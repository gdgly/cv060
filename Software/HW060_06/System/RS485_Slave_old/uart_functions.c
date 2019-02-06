//-----------------------------------------------------------------------------------
#include "..\main.h"
//-----------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------
void upc_answer_sys()
{
	u8 *ptr;
	tx.field.pre=0x55AA;
	tx.field.com=rx.field.com;
	tx.field.id=3;
	tx.field.len=sizeof(TExSTATUS);	
	ptr=&tx.field.d[0];
	*ptr=0;
	ptr+=1;
	*ptr=MenuRegs.Season;
	ptr+=1;
	memcpy(ptr,&ft,sizeof(TTime));
	tx.field.crc=upc_crc(&tx);
	upc.txnew=1;
	upc.txcount=0;	
	upc.done=0;	
	tx_mode;
}
//-----------------------------------------------------------------------------------
void upc_answer_io()
{
	tx.field.pre=0x55AA;
	tx.field.com=rx.field.com;
	tx.field.id=3;
	tx.field.len=sizeof(TExIO);	
	memcpy(&tx.field.d[0],&io,sizeof(TExIO));	
	tx.field.crc=upc_crc(&tx);
	upc.txnew=1;
	upc.txcount=0;	
	upc.done=0;	
	tx_mode;
}
//-----------------------------------------------------------------------------------
void upc_answer_pid(u8 pid_num)
{
	tx.field.pre=0x55AA;
	tx.field.com=rx.field.com;
	tx.field.id=3;
	tx.field.len=sizeof(TExPID);	
	memcpy(&tx.field.d[0],&pid[pid_num],sizeof(TExPID));	
	tx.field.crc=upc_crc(&tx);
	upc.txnew=1;
	upc.txcount=0;	
	upc.done=0;	
	tx_mode;
}
//-----------------------------------------------------------------------------------
void upc_answer_errors()
{
//	u8 *ptr;
	tx.field.pre=0x55AA;
	tx.field.com=rx.field.com;
	tx.field.id=3;
	tx.field.len=sizeof(TErrors);	
	memcpy(&tx.field.d[0],&errors,sizeof(TErrors));
	tx.field.crc=upc_crc(&tx);
	upc.txnew=1;
	upc.txcount=0;	
	upc.done=0;	
	tx_mode;
}
//-----------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------
void upc_set_sys()
{

	u8 *ptr;
	memcpy(&ft,&rx.field.d[1],sizeof(TTime));	
	tx.field.pre=0x55AA;
	tx.field.com=rx.field.com;
	tx.field.id=3;
	tx.field.len=sizeof(TExSTATUS);	
	ptr=&tx.field.d[0];
	*ptr=0;
	ptr+=1;
	memcpy(ptr,&ft,sizeof(TTime));
	tx.field.crc=upc_crc(&tx);
	upc.txnew=1;
	upc.txcount=0;	
	upc.done=0;	
	tx_mode;
}
//-----------------------------------------------------------------------------------
void upc_set_io()
{
	memcpy(&io,&rx.field.d[0],sizeof(TExIO));		
	tx.field.pre=0x55AA;
	tx.field.com=rx.field.com;
	tx.field.id=3;
	tx.field.len=sizeof(TExIO);	
	memcpy(&tx.field.d[0],&io,sizeof(TExIO));	
	tx.field.crc=upc_crc(&tx);
	upc.txnew=1;
	upc.txcount=0;	
	upc.done=0;	
	tx_mode;
}
//-----------------------------------------------------------------------------------
void upc_set_pid(u8 pid_num)
{
	if(pid_num<NUM_PID)
		memcpy(&pid[pid_num],&rx.field.d[0],sizeof(TExPID));	
	params_store();
	tx.field.pre=0x55AA;
	tx.field.com=rx.field.com;
	tx.field.id=3;
	tx.field.len=sizeof(TExPID);	
	memcpy(&tx.field.d[0],&pid[pid_num],sizeof(TExPID));	
	tx.field.crc=upc_crc(&tx);
	upc.txnew=1;
	upc.txcount=0;	
	upc.done=0;	
	tx_mode;	
}
//-----------------------------------------------------------------------------------
void upc_set_errors()
{
//	u8 *ptr;
	memcpy(&errors,&rx.field.d[0],sizeof(TErrors));	
	params_store();
	tx.field.pre=0x55AA;
	tx.field.com=rx.field.com;
	tx.field.id=3;
	tx.field.len=sizeof(TErrors);	
	memcpy(&tx.field.d[0],&errors,sizeof(TErrors));
	tx.field.crc=upc_crc(&tx);
	upc.txnew=1;
	upc.txcount=0;	
	upc.done=0;	
	tx_mode;
}
//-----------------------------------------------------------------------------------
void upc_answer_time()
{
//	u8 *ptr;
	tx.field.pre=0x55AA;
	tx.field.com=rx.field.com;
	tx.field.id=3;
	tx.field.len=sizeof(TTime);	
	memcpy(&tx.field.d[0],&MenuRegs.Time,sizeof(TTime));	
	tx.field.crc=upc_crc(&tx);
	upc.txnew=1;
	upc.txcount=0;	
	upc.done=0;	
	tx_mode;
}
//-----------------------------------------------------------------------------------
void upc_answer_time_summ()
{
//	u8 *ptr;
	tx.field.pre=0x55AA;
	tx.field.com=rx.field.com;
	tx.field.id=3;
	tx.field.len=sizeof(TTime);	
	memcpy(&tx.field.d[0],&MenuRegs.Time_Summ,sizeof(TTime));	
	tx.field.crc=upc_crc(&tx);
	upc.txnew=1;
	upc.txcount=0;	
	upc.done=0;	
	tx_mode;
}
//-----------------------------------------------------------------------------------
void upc_answer_time_wint()
{
//	u8 *ptr;
	tx.field.pre=0x55AA;
	tx.field.com=rx.field.com;
	tx.field.id=3;
	tx.field.len=sizeof(TTime);	
	memcpy(&tx.field.d[0],&MenuRegs.Time_Wint,sizeof(TTime));	
	tx.field.crc=upc_crc(&tx);
	upc.txnew=1;
	upc.txcount=0;	
	upc.done=0;	
	tx_mode;
}
//-----------------------------------------------------------------------------------
void upc_set_time()
{	
//	u8 *ptr;
	memcpy(&MenuRegs.Time,&rx.field.d[0],sizeof(TTime));	
	fram_set_time(MenuRegs.Time.field.Hour,MenuRegs.Time.field.Minute,0);
	fram_set_date(MenuRegs.Time.field.Year,MenuRegs.Time.field.Month,MenuRegs.Time.field.Date,MenuRegs.Time.field.Day);
	tx.field.pre=0x55AA;
	tx.field.com=rx.field.com;
	tx.field.id=3;
	tx.field.len=0;	
	tx.field.crc=upc_crc(&tx);
	upc.txnew=1;
	upc.txcount=0;	
	upc.done=0;	
	tx_mode;
}
//-----------------------------------------------------------------------------------
void upc_set_time_summ()
{
//	u8 *ptr;
	memcpy(&MenuRegs.Time_Summ,&rx.field.d[0],sizeof(TTime));	
	params_store();	
	tx.field.pre=0x55AA;
	tx.field.com=rx.field.com;
	tx.field.id=3;
	tx.field.len=0;	
	tx.field.crc=upc_crc(&tx);
	upc.txnew=1;
	upc.txcount=0;	
	upc.done=0;	
	tx_mode;
}
//-----------------------------------------------------------------------------------
void upc_set_time_wint()
{
//	u8 *ptr;
	memcpy(&MenuRegs.Time_Wint,&rx.field.d[0],sizeof(TTime));	
	params_store();	
	tx.field.pre=0x55AA;
	tx.field.com=rx.field.com;
	tx.field.id=3;
	tx.field.len=0;	
	tx.field.crc=upc_crc(&tx);
	upc.txnew=1;
	upc.txcount=0;	
	upc.done=0;	
	tx_mode;
}
//-----------------------------------------------------------------------------------
void upc_set_parameters()
{
//	u8 *ptr;
	memcpy(&intr.in_params[0],&rx.field.d[0],sizeof(intr.in_params));	
	tx.field.pre=0x55AA;
	tx.field.com=rx.field.com;
	tx.field.id=3;
	tx.field.len=0;	
	tx.field.crc=upc_crc(&tx);
	upc.txnew=1;
	upc.txcount=0;	
	upc.done=0;	
	tx_mode;
}
//-----------------------------------------------------------------------------------
