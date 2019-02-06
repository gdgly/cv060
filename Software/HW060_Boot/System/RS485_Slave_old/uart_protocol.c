//-----------------------------------------------------------------------------------
#include "..\main.h"
//-----------------------------------------------------------------------------------
/* Set baud rate */
#define upc_baud		17//17//5;//35;//71;//9600//35;//19200//5;//115200
//-----------------------------------------------------------------------------------
#define MAX_ANSWER_DELAY	200	// ms UPC_Time
//-----------------------------------------------------------------------------------
u8 upc_rxd;
TBuff rx,tx;
TUpcState upc;
u16 crc;
//-----------------------------------------------------------------------------------
void upc_init()
{
	upc_port_dir|=(upc_dir);
	upc_port&=~(upc_dir);
	UBRR1H = (unsigned char)(upc_baud>>8);
	UBRR1L = (unsigned char)upc_baud;
	/* Enable receiver and transmitter */
	UCSR1B =(1<<RXEN1)|(1<<TXEN1)|(1<<RXCIE1);
	/* Set frame format: 8data, 2stop bit */
	UCSR1C = (1<<USBS1)|(3<<UCSZ10);
	UDR1=' ';	
	memset((void *)&rx, 0, sizeof(rx));
	memset((void *)&tx, 0, sizeof(tx));	
	memset((void *)&upc, 0, sizeof(upc));		
	rx_mode;	
}
//-----------------------------------------------------------------------------------
u8 cs_calculate(u8* buff,u8 len)
{
	u8 i,cs=0;
	for(i=0;i<len;i++)
	{
		cs+=*buff;
		buff++;
	}
	return cs;
}
//-----------------------------------------------------------------------------------
void mem_dump(u8 *buff,u8 len)
{
	u8 i;
//	sprintf(outtxt,"\n\r");
	for(i=0;i<len;i++)
	{
		ByteToStr(outtxt,buff,1);
		buff++;
		sprintf(outtxt," ");		
	}
}
//-----------------------------------------------------------------------------------
void upc_buff_init()
{
	memset((void *)&rx, 0, sizeof(rx));
	memset((void *)&tx, 0, sizeof(tx));	
}
//-----------------------------------------------------------------------------------
#pragma vector=USART1_RXC_vect
__interrupt void upc_RXHandler()
{	
//	u8 ltmp;
//	u8 i,old_stat;
	upc_rxd=UDR1;
//	if(upc.rxnew==1)return;	// Exit if previos not handled
	switch(upc.rxcount)
	{
		case 0:
			if(upc_rxd!=PREAMBULA_LOW)
			{
				upc.rxcount=0;	
				return;
			}
		break;
		case 1:
			if(upc_rxd!=PREAMBULA_HIGH)
			{
				upc.rxcount=0;	
				return;
			}
		break;		
	}
	rx.data.d[upc.rxcount]=upc_rxd;
	upc.rxcount++;		
	if((upc.rxcount)>(rx.field.len+6))
	{

		upc.rxcount=0;	
		if(upc_crc(&rx)==rx.field.crc)
		{
			upc.rxnew=1;		
			switch(rx.field.com)
			{
				case com_none:
					sprintf(outtxt,"\n\r Empty packet received");
				break;
				case com_get_stat:
					upc_answer_sys();	
				break;
				case com_get_io:
					upc_answer_io();	
				break;
				case com_get_pid_0:
					upc_answer_pid(0);	
				break;		
				case com_get_pid_1:
					upc_answer_pid(1);	
				break;	
				case com_get_pid_2:
					upc_answer_pid(2);	
				break;	
				case com_get_pid_3:
					upc_answer_pid(3);	
				break;		
				case com_get_errors:
					upc_answer_errors();
				break;		

				case com_set_stat:
					upc_set_sys();	
				break;
				case com_set_io:
					upc_set_io();	
				break;
				case com_set_pid_0:
					upc_set_pid(0);	
				break;		
				case com_set_pid_1:
					upc_set_pid(1);	
				break;	
				case com_set_pid_2:
					upc_set_pid(2);	
				break;	
				case com_set_pid_3:
					upc_set_pid(3);	
				break;		
				case com_set_errors:
					upc_set_errors();
				break;		
				// Time			
				case com_get_time:
					upc_answer_time();	
				break;	
				case com_get_time_summ:
					upc_answer_time_summ();	
				break;		
				case com_get_time_wint:
					upc_answer_time_wint();	
				break;		
				case com_set_time:
					upc_set_time();	
				break;	
				case com_set_time_summ:
					upc_set_time_summ();	
				break;		
				case com_set_time_wint:
					upc_set_time_wint();		
				break;		
				case com_set_params:
					upc_set_parameters();		
				break;				
				default:				
				break;
			}
//			sprintf(outtxt,"\n\r Request packet received \n\r");
//			mem_dump(&rx.data.d[0],rx.field.len+7);
			//crc=upc_crc(&rx);
			//WordToStr(outtxt,&crc,1);
//			UPC_Time=3;
		}
		else
		{
			sprintf(outtxt,"\n\r Bad crc");
		}
	}
	rx_mode;						
}
//-----------------------------------------------------------------------------------
void upc_TXHandler()
{
//	if(UPC_Time!=0)return;
	// Check tx	
	if(UCSR1A & (1<<TXC1))
	{
		if(upc.done==0)
		{		
			tx_mode;	
			UCSR1A|=(1<<TXC1);			
			UDR1=tx.data.d[upc.txcount];
			upc.txcount++;
			if((upc.txcount)>(tx.field.len+6))
			{
				upc.done=1;
//					sprintf(outtxt," ch");											
			}
		}
		else
		{
			upc.txnew=0;
			rx_mode;		
		}
	}
}
//-----------------------------------------------------------------------------------
u16 upc_crc(TBuff *buff)
{
	u16 crc;
	u8 p;
	InitCRC(&crc);
	for(p=0;p<5;p++)	
	{
		CalcCRC(&(buff->data.d[p]),1,&crc);
	}
	for(p=0;p<(buff->field.len);p++)	
	{
		CalcCRC(&(buff->field.d[p]),1,&crc);
	}
	EndCRC(&crc);	
	return crc;
}
//-----------------------------------------------------------------------------------
