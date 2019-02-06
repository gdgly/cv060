/*---------------------------------------------------------------------------*/
/*
 *	Demo program of modbus example library
 *
 *	History:
 *	Date		Author			Comment
 *	08-17-2005	AceLan Kao.		Create it.
 */
/*---------------------------------------------------------------------------*/

#define DEBUG

#include <pthread.h>
#include <stdarg.h>

#include "mbserial.h"
#include "mbtcp.h"

#define		MAX_BUFFER_SIZE		256
#define		SLAVE_TCP_ADDRESS	"192.168.127.100"
#define		TCP_PORT		502

#define		MASTER_PORT		PORT1
#define		SLAVE_PORT		PORT2

typedef struct
{
	int socketfd;
	int port;
	char *adu;
	int adu_len;
} Gateway;

void *serial_master_child( void *ptr)
{
	Gateway *arg= (Gateway *)ptr;
	int port, socketfd;

	char adu[ MAX_BUFFER_SIZE], pdu[ MAX_BUFFER_SIZE];
	int adu_len, pdu_len;
	pMBAPStruct mbap= (pMBAPStruct)malloc(sizeof(MBAPStruct));
	char address;
	int times= 10;

	socketfd= arg->socketfd;
	port= arg->port;
	free( arg);

	adu_len= MBSerialBlockRead( port, adu, MAX_BUFFER_SIZE);
	if( adu_len == 0)		// it should not be happened
		goto master_exit;
	if( adu_len < 0)
	{
		printf("some error happened : %d\n", adu_len);
		goto master_exit;
	}
	address= MBSerialGetAddress( adu);
	pdu_len= MBSerialGetPDU( pdu, adu, adu_len);

	MBTCPMakeMBAP( mbap, 0, pdu_len+ 1, address);
	// TCP may timeout here...
	adu_len= MBTCPSendAndWaitResponse( socketfd, adu, pdu, pdu_len, mbap);
	if( adu_len < 0)
	{
		printf("TCP slave is not connected, trying to connecting...\n");
		MBTCPClientInit( &socketfd);
		times= 10;
		while( times > 0)
		{
			if( MBTCPClientConnect( socketfd, SLAVE_TCP_ADDRESS, TCP_PORT) == 0)
				break;
			times--;
			sleep( 1);
		}
		if( times == 0)
			goto master_exit;
		printf("TCP slave connected..\n");
		adu_len= MBTCPSendAndWaitResponse( socketfd, adu, pdu, pdu_len, mbap);
	}

	MBTCPGetMBAP( adu, mbap);
	pdu_len= MBTCPGetPDU( pdu, adu, adu_len);

	MBSerialWrite( port, pdu, pdu_len, mbap->UnitIdentifier);

master_exit:
	free( mbap);
	pthread_exit( NULL);
}

void *serial_master( void *ptr)
{
	int socketfd, serialfd;
	char adu[ MAX_BUFFER_SIZE], pdu[ MAX_BUFFER_SIZE];
	int adu_len, pdu_len, fail= 3;
	pMBAPStruct mbap= (pMBAPStruct)malloc(sizeof(MBAPStruct));
	char address;
	Gateway* gw;
	pthread_t threads;

	printf("try to open serial port%d\n", MASTER_PORT+ 1);
	if( MBSerialOpen( MASTER_PORT, MB_RTU_PROTOCOL) < 0)
	{
		perror("serial");
		exit( -1);
	}
	SerialSetSpeed( MASTER_PORT, 9600);
	printf("opened..\n");

	MBTCPClientInit( &socketfd);
	while( fail > 0)
	{
		fail--;
		printf("Master: trying to connect to slave..\n");
		if( MBTCPClientConnect( socketfd, SLAVE_TCP_ADDRESS, TCP_PORT) < 0)
		{
			perror("TCP client");
			continue;
		}
		else
		{
			printf("Master: connected..\n");
			break;
		}
	}
	if( fail == 0)
		printf("No TCP modbus slave connected..\n");

	while( 1)
	{
		if( SerialDataInInputQueue( MASTER_PORT) > 1)
		{
			gw= (Gateway *)malloc( sizeof( Gateway));
			gw->socketfd= socketfd;
			gw->port= MASTER_PORT;

			pthread_create( &threads, NULL, serial_master_child, (void *)gw);
		}
		usleep( 1000);
	}

	free( mbap);
	pthread_exit( NULL);
}

void *serial_slave_child( void *ptr)
{
	Gateway *arg= (Gateway *)ptr;
	int port, socketfd;
	char adu[ MAX_BUFFER_SIZE], pdu[ MAX_BUFFER_SIZE];
	char rsp_adu[ MAX_BUFFER_SIZE], rsp_pdu[ MAX_BUFFER_SIZE];
	int adu_len, pdu_len, rsp_adu_len, rsp_pdu_len;
	pMBAPStruct mbap= (pMBAPStruct)malloc(sizeof(MBAPStruct));
	char address;
	int times= 10;

	socketfd= arg->socketfd;
	port= arg->port;
	adu_len= arg->adu_len;
	memcpy( adu, arg->adu, adu_len);
	free( arg->adu);
	free( arg);

	MBTCPGetMBAP( adu, mbap);
	pdu_len= MBTCPGetPDU( pdu, adu, adu_len);

	address= mbap->UnitIdentifier;

	rsp_adu_len= MBSerialSendAndWaitResponse( port, rsp_adu, pdu, pdu_len, address);
	if( rsp_adu_len == 0)
	{
		printf("RTU timeout..\n");
		goto slave_exit;
	}

	if( MBSerialGetAddress( rsp_adu) != address)
	{
		printf("response address doesn't match to the request address\n");
		goto slave_exit;
	}
	rsp_pdu_len= MBSerialGetPDU( rsp_pdu, rsp_adu, rsp_adu_len);

	MBTCPMakeMBAP( mbap, mbap->TransactionIdentifier, rsp_pdu_len+ 1, address);
	MBTCPWrite( socketfd, rsp_pdu, rsp_pdu_len, mbap);

slave_exit:
	free( mbap);
	pthread_exit( NULL);
}

void *serial_slave( void *ptr)
{
	int serverfd, clientfd;
	int adu_len;
	char adu[ MAX_BUFFER_SIZE], client_addr[ MAX_BUFFER_SIZE];
	pMBAPStruct mbap= (pMBAPStruct)malloc(sizeof(MBAPStruct));
	char address;
	Gateway* gw;
	pthread_t threads;

	printf("try to open serial port2\n");
	if( MBSerialOpen( SLAVE_PORT, MB_RTU_PROTOCOL) < 0)
	{
		perror("serial");
		exit( -1);
	}
	printf("opened..\n");
	SerialSetSpeed( SLAVE_PORT, 9600);

	if( MBTCPServerInit( TCP_PORT, &serverfd) < 0)
	{
		perror("socket");
		exit( -1);
	}
	while( 1)
	{
		printf("Slave: waiting client connect..\n");
		if( MBTCPServerWaitConnection( serverfd, &clientfd, client_addr) < 0)
		{
			perror("socket");
			exit( -1);
		}
		printf("Slave: client %s connedted..\n", client_addr);

		while( 1 )
		{
			adu_len= MBTCPBlockRead( clientfd, adu, MAX_BUFFER_SIZE);
			// disconnect
			if( adu_len == 0)
			{
				printf("Slave: TCP Master disconnect\n");
				break;
			}

		gw= (Gateway *)malloc( sizeof( Gateway));
			gw->socketfd= clientfd;
			gw->port= SLAVE_PORT;
			gw->adu_len= adu_len;
			gw->adu=(char*)malloc( adu_len);
			memcpy( gw->adu, adu, adu_len);

			pthread_create( &threads, NULL, serial_slave_child, (void *)gw);
		}
	}

	free( mbap);
	pthread_exit( NULL);
}

int main()
{
	pthread_t threads[ 2];
	void* thread_result[ 2];

	MBSerialInit();

	pthread_create( &threads[ 0], NULL, serial_master, NULL);
	pthread_create( &threads[ 1], NULL, serial_slave, NULL);

	pthread_join( threads[ 0], &thread_result[ 0]);
	pthread_join( threads[ 1], &thread_result[ 1]);
	return 0;
}

