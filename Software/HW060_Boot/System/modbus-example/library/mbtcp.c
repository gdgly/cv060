/*---------------------------------------------------------------------------*/
/**
  @file		mbtcp.c
  @brief	Example modbus TCP API define file

  This file contains higher level modbus TCP utility functions.


  History:
  Date		Author			Comment
  08-17-2005	AceLan Kao.		Create it.

  @author AceLan Kao.(acelan_kao@moxa.com.tw)
 */
/*---------------------------------------------------------------------------*/

#include <string.h>

#include "mbtcp.h"

// Modbus over TCP/IP API
#define bcopy	memcpy
/*---------------------------------------------------------------------------*/
/**
  @brief	initial TCP socket for modbus protocol
  @param	port		port number
  @param	serverfd	server socket fd
  @return	return server socked fd for success, on error return error code
 */
/*---------------------------------------------------------------------------*/
int	MBTCPServerInit( int port, int *serverfd)
{
//	TCPServerInit( port, serverfd);
}

/*---------------------------------------------------------------------------*/
/**
  @brief	wait modbus master device connect
  @param	serverfd	server socket fd
  @param	clientfd	client socket fd
  @param	client_addr	used for store client ip address
  @return	return client address for success, on error return error code
 */
/*---------------------------------------------------------------------------*/
int	MBTCPServerWaitConnection( const int serverfd, int *clientfd, char *client_addr)
{
	*clientfd= TCPServerWaitConnection( serverfd, clientfd, client_addr);
	if( *clientfd < 0 )
		return MB_ERROR_TCP_NOT_CONNECTED;

	return *clientfd;
}

/*---------------------------------------------------------------------------*/
/**
  @brief	initialize modbus TCP client
  @param	clientfd	client socket fd
  @return	return client socked fd for success, on error return error code
 */
/*---------------------------------------------------------------------------*/
int	MBTCPClientInit( int *clientfd)
{
	return TCPClientInit( clientfd);
}

/*---------------------------------------------------------------------------*/
/**
  @brief	connect to TCP server
  @param	clientfd	client socket fd
  @param	addr		server address
  @param	port		server port number
  @return	return zero for success, on error -1 is returned
 */
/*---------------------------------------------------------------------------*/
int	MBTCPClientConnect( const int clientfd, const char *addr, int port)
{
	return TCPClientConnect( clientfd, addr, port);
}

/*---------------------------------------------------------------------------*/
/**
  @brief	non-block read from TCP socket
  @param	fd		socket fd
  @param	buf		input buffer
  @param	len		buffer size
  @return	the length of read data
 */
/*---------------------------------------------------------------------------*/
int	MBTCPNonBlockRead( int fd, u8 *buf, int len)
{
	return TCPNonBlockRead( fd, buf, len);
}

/*---------------------------------------------------------------------------*/
/**
  @brief	block read from TCP socket
  @param	fd		socket fd
  @param	buf		input buffer
  @param	len		buffer size
  @return	the length of read data
 */
/*---------------------------------------------------------------------------*/
int	MBTCPBlockRead( int fd, u8 *buf, int len)
{
	return TCPBlockRead( fd, buf, len);
}

/*---------------------------------------------------------------------------*/
/**
  @brief	write to TCP socket
  @param	fd		socket fd
  @param	pdu		output buffer
  @param	len		output string length
  @param	mbap		MBAP struct
  @return	the length of the actual written data
 */
/*---------------------------------------------------------------------------*/
int	MBTCPWrite(int fd, u8 *pdu, int len, pMBAPStruct mbap)
{
	u8 adu[ MB_RTU_ADU_MAX_LENGTH];
	int adu_len= 0;

	adu_len= MBTCPWriteMBAP( adu, mbap);
	bcopy( (char *)pdu, (char *)(adu+ adu_len), len);
	adu_len+= len;

	return TCPWrite( fd, adu, adu_len);
}

int	MBTCPServerClose(int fd)
{
//	close( fd);
}

int	MBTCPClientClose(int fd)
{
//	close( fd);
}

/*---------------------------------------------------------------------------*/
/**
  @brief	get MBAP struct from adu
  @param	adu		adu data
  @param	mbap		output buffer
  @return	MB_OK
 */
/*---------------------------------------------------------------------------*/
int	MBTCPGetMBAP(u8 *adu, pMBAPStruct mbap)
{
	GETU16( mbap->TransactionIdentifier, adu);
	GETU16( mbap->ProtocolIdentifier, adu+ 2);
	GETU16( mbap->Length, adu+ 4);
	mbap->UnitIdentifier= adu[ 6];

	return MB_OK;
}

/*---------------------------------------------------------------------------*/
/**
  @brief	make MBAP struct
  @param	mbap		output buffer
  @param	tid		transaction identifier
  @param	len		lenght of the following data
  @param	uid		unit identifier
  @return	MB_OK
 */
/*---------------------------------------------------------------------------*/
int	MBTCPMakeMBAP( pMBAPStruct mbap, u16 tid, u16 len, u8 uid)
{
	mbap->TransactionIdentifier= tid;
	mbap->ProtocolIdentifier= 0;
	mbap->Length= len;
	mbap->UnitIdentifier= uid;

	return MB_OK;
}

/*---------------------------------------------------------------------------*/
/**
  @brief	write MBAP struct to buffer
  @param	buf		buffer to contain MBAP
  @param	mbap		output buffer
  @return	length of data actually wrote
 */
/*---------------------------------------------------------------------------*/
int	MBTCPWriteMBAP( char *buf, pMBAPStruct mbap)
{
	PUTU16( buf, mbap->TransactionIdentifier);
	PUTU16( buf+ 2, mbap->ProtocolIdentifier);
	PUTU16( buf+ 4, mbap->Length);
	buf[ 6]= mbap->UnitIdentifier;

	return 7;				// MBAP length
}

/*---------------------------------------------------------------------------*/
/**
  @brief	get PDU from adu
  @param	buf		buffer to contain PDU
  @param	adu		adu data
  @param	len		length of the adu data
  @return	length of data actually wrote
 */
/*---------------------------------------------------------------------------*/
int	MBTCPGetPDU(u8 *buf, u8 *adu, int len)
{
	bcopy( (char *)(adu+ 7), (char *)buf, len- 7);

	return len- 7;
}

/*---------------------------------------------------------------------------*/
/**
  @brief	send adu packet through TCP socket
  		and wait response adu from slave
  @param	fd		TCP socket
  @param	buf		input buffer for receive adu from slave
  @param	pdu		pdu data prepare to send to slave
  @param	len		pdu length
  @param	mbap		mbap structure
  @return	MB_OK for success, on error return error code
 */
/*---------------------------------------------------------------------------*/
int	MBTCPSendAndWaitResponse(int fd, u8 *buf, u8 *pdu, int len, pMBAPStruct mbap)
{
	int ret_len= 0;
	int tid= 0;
	pMBAPStruct ret_mbap= (pMBAPStruct)malloc(sizeof(MBAPStruct));

	tid= mbap->TransactionIdentifier;
	MBTCPWrite( fd, pdu, len, mbap);

	ret_len= MBTCPBlockRead( fd, buf, MB_RTU_ADU_MAX_LENGTH);

	MBTCPGetMBAP( buf, ret_mbap);

	// TODO: reply for another transaction, drop it now, but may correct one day
	if( ret_mbap->TransactionIdentifier != tid)
		return MB_ERROR_EXECPTION;

	return ret_len;
}

/* Modbus over TCP/IP master function */

/*---------------------------------------------------------------------------*/
/**
  @brief	send Read Decrete Inputs request and get response(0x02)
  @param	fd		socket fd
  @param	startdec	starting decrete inputs register number
  @param	no		number of registers, between 1 ~ 2000
  @param	value		registers status slave returned
  @param	mbap		mbap structure
  @return	return 0 for success, on error return error code
 */
/*---------------------------------------------------------------------------*/
int	MBTCPReadDecreteInputs(int fd, u16 startdec, u16 no, u8 *value, pMBAPStruct mbap)
{
	u8 adu[ MB_ASCII_ADU_MAX_LENGTH], pdu[ MAX_BUFFER_SIZE];
	int pdu_len= 0, adu_len= 0, ret= 0;
	u8 ret_no;

	pdu_len= MBReadDecreteInputs( pdu, startdec, no);	// make PDU
	mbap->Length= pdu_len+ 1;				// plus 1 for address

	adu_len= MBTCPSendAndWaitResponse( fd, adu, pdu, pdu_len, mbap);

	if( adu_len < 0)
		return adu_len;

	pdu_len= MBTCPGetPDU( pdu, adu, adu_len);
	ret= MBGetResponseReadDecreteInputs( pdu, &ret_no, value);
	if( ret < 0)
		return ret;
	return ret_no;
}

/*---------------------------------------------------------------------------*/
/**
  @brief	send Read Coils request and get response(0x01)
  @param	fd		socket fd
  @param	startcoils	starting coil register numbere
  @param	no		number of registers, between 1 ~ 2000
  @param	value		coils status slave returned
  @param	mbap		mbap structure
  @return	return 0 for success, on error return error code
 */
/*---------------------------------------------------------------------------*/
int	MBTCPReadCoils(int fd, u16 startcoils, u16 no, u8 *value, pMBAPStruct mbap)
{
	u8 adu[ MB_ASCII_ADU_MAX_LENGTH], pdu[ MAX_BUFFER_SIZE];
	int pdu_len= 0, adu_len= 0, ret= 0;
	u8 ret_no;

	pdu_len= MBReadCoils( pdu, startcoils, no);		// make PDU
	mbap->Length= pdu_len+ 1;				// plus 1 for address

	adu_len= MBTCPSendAndWaitResponse( fd, adu, pdu, pdu_len, mbap);

	if( adu_len < 0)
		return adu_len;

	pdu_len= MBTCPGetPDU( pdu, adu, adu_len);
	ret= MBGetResponseReadCoils( pdu, &ret_no, value);
	if( ret < 0)
		return ret;
	return ret_no;
}

/*---------------------------------------------------------------------------*/
/**
  @brief	send Write Single Coil request and get response(0x05)
  @param	fd		socket fd
  @param	coilreg		coil register number
  @param	onoff		0xFF00 for on,0x0000 for off
  @param	mbap		mbap structure
  @return	return 0 for success, on error return error code
 */
/*---------------------------------------------------------------------------*/
int	MBTCPWriteSingleCoil(int fd, u16 coilreg, u16 onoff, pMBAPStruct mbap)
{
	u8 adu[ MB_ASCII_ADU_MAX_LENGTH], pdu[ MAX_BUFFER_SIZE];
	int pdu_len= 0, adu_len= 0, ret= 0;
	u16 ret_addr, ret_value;

	pdu_len= MBWriteSingleCoil( pdu, coilreg, onoff);	// make PDU
	mbap->Length= pdu_len+ 1;				// plus 1 for address

	adu_len= MBTCPSendAndWaitResponse( fd, adu, pdu, pdu_len, mbap);

	if( adu_len < 0)
		return adu_len;

	pdu_len= MBTCPGetPDU( pdu, adu, adu_len);
	ret= MBGetResponseWriteSingleCoil( pdu, &ret_addr, &ret_value);
	if( ret < 0)
		return ret;
	if( ( ret_addr != coilreg) || ( ret_value != onoff))
		return MB_ERROR_EXECPTION;
	return MB_OK;
}

/*---------------------------------------------------------------------------*/
/**
  @brief	send Write Multiple Coils request and get response(0x0F)
  @param	fd		socket fd
  @param	startcoils	starting coil register number
  @param	no		number of registers, between 1 ~ 2000
  @param	value		coils status slave returned
  @param	mbap		mbap structure
  @return	return 0 for success, on error return error code
 */
/*---------------------------------------------------------------------------*/
int	MBTCPWriteMultipleCoils(int fd, u16 startcoils, u16 no, u8 *value, pMBAPStruct mbap)
{
	u8 adu[ MB_ASCII_ADU_MAX_LENGTH], pdu[ MAX_BUFFER_SIZE];
	int pdu_len= 0, adu_len= 0, ret= 0;
	u16 count;
	u16 ret_addr, ret_value;

	count= (u8)no/8;
	if( count*8 < no)
		count++;

	pdu_len= MBWriteMultipleCoils( pdu, startcoils, no, count, value);	// make PDU
	mbap->Length= pdu_len+ 1;				// plus 1 for address

	adu_len= MBTCPSendAndWaitResponse( fd, adu, pdu, pdu_len, mbap);

	if( adu_len < 0)
		return adu_len;

	pdu_len= MBTCPGetPDU( pdu, adu, adu_len);
	ret= MBGetResponseWriteMultipleCoils( pdu, &ret_addr, &ret_value);
	if( ret < 0)
		return ret;
	if( ( ret_addr != startcoils) || ( ret_value != no))
		return MB_ERROR_EXECPTION;
	return MB_OK;
}

/*---------------------------------------------------------------------------*/
/**
  @brief	send Read Input Registers request and get response(0x04)
  @param	fd		socket fd
  @param	startreg	starting coil register number
  @param	no		number of registers, between 1 ~ 125
  @param	value		register status slave returned
  @param	mbap		mbap structure
  @return	return 0 for success, on error return error code
 */
/*---------------------------------------------------------------------------*/
int	MBTCPReadInputRegisters(int fd, u16 startreg, u16 no, u16 *value, pMBAPStruct mbap)
{
	u8 adu[ MB_ASCII_ADU_MAX_LENGTH], pdu[ MAX_BUFFER_SIZE];
	int pdu_len= 0, adu_len= 0, ret= 0;
	u8 ret_no;

	pdu_len= MBReadInputRegisters( pdu, startreg, no);	// make PDU
	mbap->Length= pdu_len+ 1;				// plus 1 for address

	adu_len= MBTCPSendAndWaitResponse( fd, adu, pdu, pdu_len, mbap);

	if( adu_len < 0)
		return adu_len;

	pdu_len= MBTCPGetPDU( pdu, adu, adu_len);
	ret= MBGetResponseReadInputRegisters( pdu, &ret_no, value);
	if( ret < 0)
		return ret;
	return ret_no;
}

/*---------------------------------------------------------------------------*/
/**
  @brief	send Read Holding Registers request and get response(0x03)
  @param	fd		socket fd
  @param	startreg	starting coil register number
  @param	no		number of registers, between 1 ~ 125
  @param	value		register status slave returned
  @param	mbap		mbap structure
  @return	return 0 for success, on error return error code
 */
/*---------------------------------------------------------------------------*/
int	MBTCPReadHoldingRegisters(int fd, u16 startreg, u16 no, u16 *value, pMBAPStruct mbap)
{
	u8 adu[ MB_ASCII_ADU_MAX_LENGTH], pdu[ MAX_BUFFER_SIZE];
	int pdu_len= 0, adu_len= 0, ret= 0;
	u8 ret_no;

	pdu_len= MBReadHoldingRegisters( pdu, startreg, no);	// make PDU
	mbap->Length= pdu_len+ 1;				// plus 1 for address

	adu_len= MBTCPSendAndWaitResponse( fd, adu, pdu, pdu_len, mbap);

	if( adu_len < 0)
		return adu_len;

	pdu_len= MBTCPGetPDU( pdu, adu, adu_len);
	ret= MBGetResponseReadHoldingRegisters( pdu, &ret_no, value);
	if( ret < 0)
		return ret;
	return ret_no;
}

/*---------------------------------------------------------------------------*/
/**
  @brief	send Write Single Register request and get response(0x06)
  @param	fd		socket fd
  @param	devicereg	register number
  @param	value		register status slave returned
  @param	mbap		mbap structure
  @return	return 0 for success, on error return error code
 */
/*---------------------------------------------------------------------------*/
int	MBTCPWriteSingleRegister(int fd, u16 devicereg, u16 value, pMBAPStruct mbap)
{
	u8 adu[ MB_ASCII_ADU_MAX_LENGTH], pdu[ MAX_BUFFER_SIZE];
	int pdu_len= 0, adu_len= 0, ret= 0;
	u16 ret_addr, ret_value;

	pdu_len= MBWriteSingleRegister( pdu, devicereg, value);	// make PDU
	mbap->Length= pdu_len+ 1;				// plus 1 for address

	adu_len= MBTCPSendAndWaitResponse( fd, adu, pdu, pdu_len, mbap);

	if( adu_len < 0)
		return adu_len;

	pdu_len= MBTCPGetPDU( pdu, adu, adu_len);
	ret= MBGetResponseWriteSingleRegister( pdu, &ret_addr, &ret_value);
	if( ret < 0)
		return ret;
	if( ( ret_addr != devicereg) || ( ret_value != value))
		return MB_ERROR_EXECPTION;
	return MB_OK;
}

/*---------------------------------------------------------------------------*/
/**
  @brief	send Write Multiple Registers request and get response(0x10)
  @param	fd		socket fd
  @param	startreg	starting register number
  @param	noreg		number of registers, between 1 ~ 120
  @param	count		value counter
  @param	value		register status slave returned
  @param	mbap		mbap structure
  @return	return 0 for success, on error return error code
 */
/*---------------------------------------------------------------------------*/
int	MBTCPWriteMultipleRegisters(int fd, u16 startreg, u16 noreg, u8 count, u16 *value, pMBAPStruct mbap)
{
	u8 adu[ MB_ASCII_ADU_MAX_LENGTH], pdu[ MAX_BUFFER_SIZE];
	int pdu_len= 0, adu_len= 0, ret= 0;
	u16 ret_addr, ret_value;

	pdu_len= MBWriteMultipleRegisters( pdu, startreg, noreg, count, value);
	mbap->Length= pdu_len+ 1;				// plus 1 for address		// make PDU

	adu_len= MBTCPSendAndWaitResponse( fd, adu, pdu, pdu_len, mbap);

	if( adu_len < 0)
		return adu_len;

	pdu_len= MBTCPGetPDU( pdu, adu, adu_len);
	ret= MBGetResponseWriteMultipleRegisters( pdu, &ret_addr, &ret_value);
	if( ret < 0)
		return ret;
	if( ( ret_addr != startreg) || ( ret_value != noreg))
		return MB_ERROR_EXECPTION;
	return MB_OK;
}

/*---------------------------------------------------------------------------*/
/**
  @brief	send Read Write Multiple Registers request and get response(0x17)
  @param	fd		socket fd
  @param	rsreg		starting register number to read
  @param	rno		number of registers ro read, between 1 ~ 120
  @param	rv		registers value slave returned
  @param	wsreg		starting register number to write
  @param	wno		number of registers ro write, between 1 ~ 120
  @param	count		value counter
  @param	wv		value to write
  @param	mbap		mbap structure
  @return	return 0 for success, on error return error code
 */
/*---------------------------------------------------------------------------*/
int	MBTCPReadWriteMultipleRegisters(int fd, u16 rsreg, u16 rno, u16 *rv, u16 wsreg, u16 wno, u8 count, u16 *wv, pMBAPStruct mbap)
{
	u8 adu[ MB_ASCII_ADU_MAX_LENGTH], pdu[ MAX_BUFFER_SIZE];
	int pdu_len= 0, adu_len= 0, ret= 0;
	u8 ret_no;

	pdu_len= MBReadWriteMultipleRegisters( pdu, rsreg, rno, wsreg, wno, count, wv);
	mbap->Length= pdu_len+ 1;				// plus 1 for address		// make PDU

	adu_len= MBTCPSendAndWaitResponse( fd, adu, pdu, pdu_len, mbap);

	if( adu_len < 0)
		return adu_len;

	pdu_len= MBTCPGetPDU( pdu, adu, adu_len);
	ret= MBGetResponseReadWriteMultipleRegisters( pdu, (u8 *)&ret_no, wv);

	if( ret < 0)
		return ret;
	if( ret_no != rno*2)
		return MB_ERROR_EXECPTION;
	return MB_OK;
}

/*---------------------------------------------------------------------------*/
/**
  @brief	send Mask Write Register request and get response(0x16)
  @param	fd		socket fd
  @param	reg		register number
  @param	andmask		and mask
  @param	ormask		or mask
  @param	mbap		mbap structure
  @return	return 0 for success, on error return error code
 */
/*---------------------------------------------------------------------------*/
int	MBTCPMaskwWriteRegister(int fd, u16 reg, u16 andmask, u16 ormask, pMBAPStruct mbap)
{
	u8 adu[ MB_ASCII_ADU_MAX_LENGTH], pdu[ MAX_BUFFER_SIZE];
	int pdu_len= 0, adu_len= 0, ret= 0;
	u16 ret_reg, ret_and, ret_or;

	pdu_len= MBMaskWriteRegister( pdu, reg, andmask, ormask);	// make PDU
	mbap->Length= pdu_len+ 1;				// plus 1 for address

	adu_len= MBTCPSendAndWaitResponse( fd, adu, pdu, pdu_len, mbap);

	if( adu_len < 0)
		return adu_len;

	pdu_len= MBTCPGetPDU( pdu, adu, adu_len);
	ret= MBGetResponseMaskWriteRegister( pdu, &ret_reg, &ret_and, &ret_or);

	if( ret < 0)
		return ret;
	if( ( ret_reg != reg) || ( ret_and != andmask) || ( ret_or != ormask))
		return MB_ERROR_EXECPTION;
	return MB_OK;
}

/*---------------------------------------------------------------------------*/
/**
  @brief	send Read FIFO Queue request and get response(0x18)
  @param	fd		socket fd
  @param	FIFOAddr	FIFO address
  @param	FIFOCount	FIFO value buffer size(<=31)
  @param	FIFOValue	values of FIFO register
  @param	mbap		mbap structure
  @return	return 0 for success, on error return error code
 */
/*---------------------------------------------------------------------------*/
int	MBTCPReadFIFOQueue(int fd, u16 FIFOAddr, u16 *FIFOCount, u16 *FIFOValue, pMBAPStruct mbap)
{
	u8 adu[ MB_ASCII_ADU_MAX_LENGTH], pdu[ MAX_BUFFER_SIZE];
	int pdu_len= 0, adu_len= 0, ret= 0;

	pdu_len= MBReadFIFOQueue( pdu, FIFOAddr);		// make PDU
	mbap->Length= pdu_len+ 1;				// plus 1 for address

	adu_len= MBTCPSendAndWaitResponse( fd, adu, pdu, pdu_len, mbap);

	if( adu_len < 0)
		return adu_len;

	pdu_len= MBTCPGetPDU( pdu, adu, adu_len);
	ret= MBGetResponseReadFIFOQueue( pdu, FIFOCount, FIFOValue);

	if( ret < 0)
		return ret;

	return MB_OK;
}

/* Modbus over TCP/IP slave function */
/*---------------------------------------------------------------------------*/
/**
  @brief	send Read Decrete Inputs response(0x02)
  @param	fd		socket fd
  @param	no		number of registers
  @param	value		registers status
  @param	mbap		mbap structure
  @return	return 0 for success, on error return error code
 */
/*---------------------------------------------------------------------------*/
int	MBTCPSendReadDecreteInputs(int fd, u16 no, u8 *value, pMBAPStruct mbap)
{
	u8 pdu[ MAX_BUFFER_SIZE];
	int pdu_len= 0, adu_len= 0;

	pdu_len= MBResponseReadDecreteInputs( pdu, no, value);	// make PDU
	mbap->Length= pdu_len+ 1;				// plus 1 for address

	adu_len= MBTCPWrite( fd, pdu, pdu_len, mbap);

	if( adu_len < 0)
		return adu_len;

	return MB_OK;
}

/*---------------------------------------------------------------------------*/
/**
  @brief	send Read Coils response(0x01)
  @param	fd		socket fd
  @param	no		number of registers
  @param	value		registers status
  @param	mbap		mbap structure
  @return	return 0 for success, on error return error code
 */
/*---------------------------------------------------------------------------*/
int	MBTCPSendReadCoils(int fd, u16 no, u8 *value, pMBAPStruct mbap)
{
	u8 pdu[ MAX_BUFFER_SIZE];
	int pdu_len= 0, adu_len= 0;

	pdu_len= MBResponseReadCoils( pdu, no, value);		// make PDU
	mbap->Length= pdu_len+ 1;				// plus 1 for address

	adu_len= MBTCPWrite( fd, pdu, pdu_len, mbap);

	if( adu_len < 0)
		return adu_len;

	return MB_OK;
}

/*---------------------------------------------------------------------------*/
/**
  @brief	send Read Input Registers response(0x04)
  @param	fd		socket fd
  @param	no		number of registers
  @param	value		registers status
  @param	mbap		mbap structure
  @return	return 0 for success, on error return error code
 */
/*---------------------------------------------------------------------------*/
int	MBTCPSendReadInputRegisters(int fd, u16 no, u16 *value, pMBAPStruct mbap)
{
	u8 pdu[ MAX_BUFFER_SIZE];
	int pdu_len= 0, adu_len= 0;

	pdu_len= MBResponseReadInputRegisters( pdu, no, value);	// make PDU
	mbap->Length= pdu_len+ 1;				// plus 1 for address

	adu_len= MBTCPWrite( fd, pdu, pdu_len, mbap);

	if( adu_len < 0)
		return adu_len;

	return MB_OK;
}

/*---------------------------------------------------------------------------*/
/**
  @brief	send Read Holding Registers response(0x03)
  @param	fd		socket fd
  @param	no		number of registers
  @param	value		registers status
  @param	mbap		mbap structure
  @return	return 0 for success, on error return error code
 */
/*---------------------------------------------------------------------------*/
int	MBTCPSendReadHoldingRegisters(int fd, u16 no, u16 *value, pMBAPStruct mbap)
{
	u8 pdu[ MAX_BUFFER_SIZE];
	int pdu_len= 0, adu_len= 0;

	pdu_len= MBResponseReadHoldingRegisters( pdu, no, value);	// make PDU
	mbap->Length= pdu_len+ 1;				// plus 1 for address

	adu_len= MBTCPWrite( fd, pdu, pdu_len, mbap);

	if( adu_len < 0)
		return adu_len;

	return MB_OK;
}

/*---------------------------------------------------------------------------*/
/**
  @brief	send Write Multiple Registers response(0x10)
  @param	fd		socket fd
  @param	startdevreg	starting register number
  @param	noreg		number of registers, between 1 ~ 120
  @param	count		value counter
  @param	value		value to write
  @param	mbap		mbap structure
  @return	return 0 for success, on error return error code
 */
/*---------------------------------------------------------------------------*/
int	MBTCPSendWriteMultipleRegisters(int fd, u16 startdevreg, u16 noreg, u8 count, u16 *value, pMBAPStruct mbap)
{
	u8 pdu[ MAX_BUFFER_SIZE];
	int pdu_len= 0, adu_len= 0;

	pdu_len= MBResponseWriteMultipleRegisters( pdu, startdevreg, noreg);	// make PDU
	mbap->Length= pdu_len+ 1;				// plus 1 for address

	adu_len= MBTCPWrite( fd, pdu, pdu_len, mbap);

	if( adu_len < 0)
		return adu_len;

	return MB_OK;
}

/*---------------------------------------------------------------------------*/
/**
  @brief	send Write Single Coil response(0x05)
  @param	fd		socket fd
  @param	coilreg		coil register number
  @param	onoff		0xFF00 for on,0x0000 for off
  @param	mbap		mbap structure
  @return	return 0 for success, on error return error code
 */
/*---------------------------------------------------------------------------*/
int	MBTCPSendWriteSingleCoil(int fd, u16 coilreg, u16 onoff, pMBAPStruct mbap)
{
	u8 pdu[ MAX_BUFFER_SIZE];
	int pdu_len= 0, adu_len= 0;

	pdu_len= MBResponseWriteSingleCoil( pdu, coilreg, onoff);	// make PDU
	mbap->Length= pdu_len+ 1;				// plus 1 for address

	adu_len= MBTCPWrite( fd, pdu, pdu_len, mbap);

	if( adu_len < 0)
		return adu_len;

	return MB_OK;
}

/*---------------------------------------------------------------------------*/
/**
  @brief	send Write Single Register response(0x06)
  @param	fd		socket fd
  @param	reg		register number
  @param	value		value to write
  @param	mbap		mbap structure
  @return	return 0 for success, on error return error code
 */
/*---------------------------------------------------------------------------*/
int	MBTCPSendWriteSingleRegister(int fd, u16 reg, u16 value, pMBAPStruct mbap)
{
	u8 pdu[ MAX_BUFFER_SIZE];
	int pdu_len= 0, adu_len= 0;

	pdu_len= MBResponseWriteSingleRegister( pdu, reg, value);	// make PDU
	mbap->Length= pdu_len+ 1;				// plus 1 for address

	adu_len= MBTCPWrite( fd, pdu, pdu_len, mbap);

	if( adu_len < 0)
		return adu_len;

	return MB_OK;
}

/*---------------------------------------------------------------------------*/
/**
  @brief	send Read FIFO Queue response(0x18)
  @param	fd		socket fd
  @param	no		number of bytes
  @param	count		FIFO value buffer size(<=31)
  @param	value		values of FIFO register
  @param	mbap		mbap structure
  @return	return 0 for success, on error return error code
 */
/*---------------------------------------------------------------------------*/
int	MBTCPSendReadFIFOQueue(int fd, u16 no, u16 count, u16 *value, pMBAPStruct mbap)
{
	u8 pdu[ MAX_BUFFER_SIZE];
	int pdu_len= 0, adu_len= 0;

	pdu_len= MBResponseReadFIFOQueue( pdu, no, count, value);	// make PDU
	mbap->Length= pdu_len+ 1;				// plus 1 for address

	adu_len= MBTCPWrite( fd, pdu, pdu_len, mbap);

	if( adu_len < 0)
		return adu_len;

	return MB_OK;
}

