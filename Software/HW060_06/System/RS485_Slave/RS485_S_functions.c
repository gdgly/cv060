//-----------------------------------------------------------------------------------
#include "main.h"
//-----------------------------------------------------------------------------------
#define MAX_ANSWER_DELAY	200	// ms UPC_Time
//-----------------------------------------------------------------------------------
u8 first_start=1;
TIO *io_ptr;
TExSTATUS *Status;
extern u8 Serial_ID;
//-----------------------------------------------------------------------------------
void upc_answer_sys()
{
//	u8 *ptr;
	tx.field.pre=0x55AA;
	tx.field.com.bit.id=Serial_ID;
	tx.field.com.bit.req=0;
	tx.field.com.bit.com=rx.field.com.bit.com;
//	tx.field.len=sizeof(TExSTATUS);	
//	ptr=&tx.field.d[0];
//	*ptr=0;
//	ptr+=1;
//	*ptr=MenuRegs.Season;
//	ptr+=1;
//	memcpy(ptr,&ft,sizeof(TCTime));
	tx.field.d[0]=MAIN_CONTROLLER;	// Main programm is working
	FGet(HAPP_FLASH_START+THW_LOC,(u8*)&tx.field.d[1],4);
//	FGet(HAPP_FLASH_START+TSW_LOC,(u8*)&tx.field.d[5],4);
	FGet(HAPP_FLASH_START+TTIME_LOC,(u8*)&tx.field.d[5],7);	

	FGet(HPLM_FLASH_START+THW_LOC,(u8*)&tx.field.d[1+12],4);
//	FGet(HAPP_FLASH_START+TSW_LOC,(u8*)&tx.field.d[5+16],4);
	FGet(HPLM_FLASH_START+TTIME_LOC,(u8*)&tx.field.d[5+12],7);	
	
	//memcpy((u8*)&tx.field.d[8],&ft,sizeof(TExSTATUS));
	Status=(TExSTATUS*)&tx.field.d[30];
	Status->Manual_Mode=MenuRegs.Manual_Mode;
	Status->ft=MenuRegs.Time;
#if MAX_SEASON_BLOCK
	Status->Season=reg_season.season;
#endif
#if NUM_PID
	Status->Controller_Mode=pid[0].mode;
	Status->Preset_Temperature=pid[0].t0;	
	Status->Preset_Speed=io.aoutput[0];
	Status->Temperature=io.ainput[pid[0].channel];	
#endif
#if MAX_FANCOIL_NUMBER
	Status->Controller_Mode=fan[0].Fan_Mode;
	Status->Preset_Temperature=fan[0].T;	
	Status->Preset_Speed=fan[0].Fan_Lvl;
	Status->Temperature=io.ainput[fan[0].Channel];	
#endif	
#if MAX_KOTEL_NUMBER
	Status->Controller_Mode=kotel.mode;
	Status->Preset_Temperature=kotel.t;	
	Status->Preset_Speed=kotel.fan_out[0];
	Status->Temperature=io.ainput[kotel.channel];	
#endif	
	tx.field.len=30+sizeof(TExSTATUS);			
	tx.field.crc_data=upc_crc_data(&tx);
	tx.field.crc_head=upc_crc_head(&tx);
	upc.txnew=1;
	upc.txcount=0;	
	upc.done=0;	
	UPC_Time2=3;
}
//-----------------------------------------------------------------------------------
void upc_answer_io()
{
	tx.field.pre=0x55AA;
	tx.field.com.bit.id=Serial_ID;
	tx.field.com.bit.req=0;
	tx.field.com.bit.com=rx.field.com.bit.com;
	tx.field.len=sizeof(TIO);	
	memcpy(&tx.field.d[0],(u8 __packed*)&io,sizeof(TIO));	
	tx.field.crc_data=upc_crc_data(&tx);
	tx.field.crc_head=upc_crc_head(&tx);
	upc.txnew=1;
	upc.txcount=0;	
	upc.done=0;	
	UPC_Time2=3;
}

//-----------------------------------------------------------------------------------
void upc_answer_pid(u8 pid_num)
{
	tx.field.pre=0x55AA;
	tx.field.com.bit.id=Serial_ID;
	tx.field.com.bit.req=0;
	tx.field.com.bit.com=rx.field.com.bit.com;
	tx.field.len=sizeof(TPID);	
#if 	NUM_PID		
	if(pid_num<NUM_PID)	
		memcpy(&tx.field.d[0],(u8 __packed*)&pid[pid_num],sizeof(TPID));	
	else
		memset(&tx.field.d[0],0,sizeof(TPID));	
#else
	memset(&tx.field.d[0],0,sizeof(TPID));	
#endif	
	tx.field.crc_data=upc_crc_data(&tx);
	tx.field.crc_head=upc_crc_head(&tx);
	upc.txnew=1;
	upc.txcount=0;	
	upc.done=0;	
	UPC_Time2=3;;
}
//-----------------------------------------------------------------------------------
void upc_answer_fan(u8 fan_num)
{
	tx.field.pre=0x55AA;
	tx.field.com.bit.id=Serial_ID;
	tx.field.com.bit.req=0;
	tx.field.com.bit.com=rx.field.com.bit.com;
	tx.field.len=sizeof(TPID);	
#if 	MAX_FANCOIL_NUMBER	
	if(fan_num<MAX_FANCOIL_NUMBER)	
		memcpy(&tx.field.d[0],&fan[fan_num],sizeof(TFanCoil));	
	else
		memset(&tx.field.d[0],0,sizeof(TFanCoil));	
#else
	memset(&tx.field.d[0],0,sizeof(TFanCoil));	
#endif	
	tx.field.crc_data=upc_crc_data(&tx);
	tx.field.crc_head=upc_crc_head(&tx);
	upc.txnew=1;
	upc.txcount=0;	
	upc.done=0;	
	UPC_Time2=3;;
}
//-----------------------------------------------------------------------------------
void upc_answer_kotel(u8 kot_num)
{
	tx.field.pre=0x55AA;
	tx.field.com.bit.id=Serial_ID;
	tx.field.com.bit.req=0;
	tx.field.com.bit.com=rx.field.com.bit.com;
	tx.field.len=19;	
#if 	MAX_KOTEL_NUMBER	
	memcpy(&tx.field.d[0],&kotel,19);	
#else
	memset(&tx.field.d[0],0,19);	
#endif	
	tx.field.crc_data=upc_crc_data(&tx);
	tx.field.crc_head=upc_crc_head(&tx);
	upc.txnew=1;
	upc.txcount=0;	
	upc.done=0;	
	UPC_Time2=3;;
}
//-----------------------------------------------------------------------------------
void upc_answer_kotel_params(u8 kot_num)
{
	tx.field.pre=0x55AA;
	tx.field.com.bit.id=Serial_ID;
	tx.field.com.bit.req=0;
	tx.field.com.bit.com=rx.field.com.bit.com;
	tx.field.len=sizeof(TKotelModeRec);	
#if 	MAX_KOTEL_NUMBER	
	memcpy(&tx.field.d[0],&kotel.p[0][rx.field.d[2]],sizeof(TKotelModeRec));	
#else
	memset(&tx.field.d[0],0,sizeof(TKotelModeRec));	
#endif	
	tx.field.crc_data=upc_crc_data(&tx);
	tx.field.crc_head=upc_crc_head(&tx);
	upc.txnew=1;
	upc.txcount=0;	
	upc.done=0;	
	UPC_Time2=3;;
}
//-----------------------------------------------------------------------------------
void upc_answer_errors()
{
//	u8 *ptr;
	tx.field.pre=0x55AA;
	tx.field.com.bit.id=Serial_ID;
	tx.field.com.bit.req=0;	
	tx.field.com.bit.com=rx.field.com.bit.com;
	tx.field.len=sizeof(TErrors);	
	memcpy(&tx.field.d[0],(u8 __packed*)&errors,sizeof(TErrors));
	tx.field.crc_data=upc_crc_data(&tx);
	tx.field.crc_head=upc_crc_head(&tx);
	upc.txnew=1;
	upc.txcount=0;	
	upc.done=0;	
	UPC_Time2=3;
}//-----------------------------------------------------------------------------------
void upc_answer_clear_errors()
{
	memset((u8 __packed*)&errors,0,sizeof(TErrors));
//	Time_To_Store=3;
	
	tx.field.pre=0x55AA;
	tx.field.com.bit.id=Serial_ID;
	tx.field.com.bit.req=0;	
	tx.field.com.bit.com=rx.field.com.bit.com;
	tx.field.len=0;	
	tx.field.crc_data=upc_crc_data(&tx);
	tx.field.crc_head=upc_crc_head(&tx);
	upc.txnew=1;
	upc.txcount=0;	
	upc.done=0;	
	UPC_Time2=3;;
}
//-----------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------
void upc_set_sys()
{
//	u8 *ptr;
//	memcpy(&ft,&rx.field.d[1],sizeof(TCTime));	
	Status=(TExSTATUS*)&rx.field.d[8];
	MenuRegs.Manual_Mode=Status->Manual_Mode;
//	Status->ft=MenuRegs.Time;
#if MAX_SEASON_BLOCK
	reg_season.season=Status->Season;	
#endif
#if NUM_PID
	pid[0].mode=Status->Controller_Mode;
	pid[0].t0=Status->Preset_Temperature;	
#endif
	io.aoutput[0]=Status->Preset_Speed;	
	Time_To_Store=180;	
	tx.field.pre=0x55AA;
	tx.field.com.bit.id=Serial_ID;
	tx.field.com.bit.req=0;	
	tx.field.com.bit.com=rx.field.com.bit.com;
	tx.field.len=sizeof(TExSTATUS);	
//	ptr=&tx.field.d[0];
//	*ptr=0;
//	ptr+=1;
//	memcpy(ptr,&ft,sizeof(TCTime));
	tx.field.crc_data=upc_crc_data(&tx);
	tx.field.crc_head=upc_crc_head(&tx);
	upc.txnew=1;
	upc.txcount=0;	
	upc.done=0;	
	UPC_Time2=3;;
}
//-----------------------------------------------------------------------------------
void upc_set_io()
{
	u8 i;
//	memcpy(&io,&rx.field.d[0],sizeof(TExIO));		
//	if()
	io_ptr=(TIO*)&rx.field.d[0];
	io.dout=io_ptr->dout;
//	if(io.num_ao==io_ptr->num_ao)
	for(i=0;i<io.num_ao;i++)
		io.aoutput[i]=io_ptr->aoutput[i];
	tx.field.pre=0x55AA;
	tx.field.com.bit.id=Serial_ID;
	tx.field.com.bit.req=0;	
	tx.field.com.bit.com=rx.field.com.bit.com;
	tx.field.len=0;	
//	memcpy(&tx.field.d[0],&io,sizeof(TExIO));	
	tx.field.crc_data=upc_crc_data(&tx);
	tx.field.crc_head=upc_crc_head(&tx);
	upc.txnew=1;
	upc.txcount=0;	
	upc.done=0;	
	UPC_Time2=3;;
}

//-----------------------------------------------------------------------------------
void upc_set_pid()
{
#if NUM_PID	
	u8 pid_num=rx.field.d[0];
	if(pid_num<NUM_PID)	memcpy((u8 __packed*)&pid[pid_num],&rx.field.d[1],rx.field.len-1);	
	Time_To_Store=180;	// Sign to store parameters	
#endif	
	tx.field.pre=0x55AA;
	tx.field.com.bit.id=Serial_ID;
	tx.field.com.bit.req=0;	
	tx.field.com.bit.com=rx.field.com.bit.com;
	tx.field.len=0;	
	tx.field.crc_data=upc_crc_data(&tx);
	tx.field.crc_head=upc_crc_head(&tx);
	upc.txnew=1;
	upc.txcount=0;	
	upc.done=0;	
	UPC_Time2=3;	
}
//-----------------------------------------------------------------------------------
void upc_set_fan()
{
#if MAX_FANCOIL_NUMBER		
	u8 fan_num=rx.field.d[0];
	if(fan_num<MAX_FANCOIL_NUMBER)	memcpy(&fan[fan_num],&rx.field.d[1],rx.field.len-1);	
	Time_To_Store=180;	// Sign to store parameters
#endif
	tx.field.pre=0x55AA;
	tx.field.com.bit.id=Serial_ID;
	tx.field.com.bit.req=0;	
	tx.field.com.bit.com=rx.field.com.bit.com;
	tx.field.len=0;	
	tx.field.crc_data=upc_crc_data(&tx);
	tx.field.crc_head=upc_crc_head(&tx);
	upc.txnew=1;
	upc.txcount=0;	
	upc.done=0;	
	UPC_Time2=3;	
}
//-----------------------------------------------------------------------------------
void upc_set_kotel()
{
#if MAX_KOTEL_NUMBER	
	u8 kotel_num=rx.field.d[0];
	if(kotel_num<MAX_KOTEL_NUMBER) memcpy(&kotel,&rx.field.d[1],rx.field.len-1);	
	Time_To_Store=180;	// Sign to store parameters
#endif
	tx.field.pre=0x55AA;
	tx.field.com.bit.id=Serial_ID;
	tx.field.com.bit.req=0;	
	tx.field.com.bit.com=rx.field.com.bit.com;
	tx.field.len=0;	
	tx.field.crc_data=upc_crc_data(&tx);
	tx.field.crc_head=upc_crc_head(&tx);
	upc.txnew=1;
	upc.txcount=0;	
	upc.done=0;	
	UPC_Time2=3;	
}
//-----------------------------------------------------------------------------------
void upc_set_kotel_params()
{
#if MAX_KOTEL_NUMBER	
	u8 kotel_num=rx.field.d[0];
	if(kotel_num<MAX_KOTEL_NUMBER) memcpy(&kotel.p[0][rx.field.d[2]],&rx.field.d[3],rx.field.len-3);	
	Time_To_Store=180;	// Sign to store parameters
#endif
	tx.field.pre=0x55AA;
	tx.field.com.bit.id=Serial_ID;
	tx.field.com.bit.req=0;	
	tx.field.com.bit.com=rx.field.com.bit.com;
	tx.field.len=0;	
	tx.field.crc_data=upc_crc_data(&tx);
	tx.field.crc_head=upc_crc_head(&tx);
	upc.txnew=1;
	upc.txcount=0;	
	upc.done=0;	
	UPC_Time2=3;	
}
/*
//-----------------------------------------------------------------------------------
void upc_set_errors()
{
//	u8 *ptr;
//	memcpy(&errors,&rx.field.d[0],sizeof(TErrors));	
	memset(&errors,0,sizeof(TErrors));	
	Time_To_Store=3;		// Sign to store parameters	
	tx.field.pre=0x55AA;
	tx.field.com.bit.id=ID;
	tx.field.com.bit.req=0;	
	tx.field.com.bit.com=rx.field.com.bit.com;
	tx.field.len=0;
//	memcpy(&tx.field.d[0],&errors,sizeof(TErrors));
	tx.field.crc_data=upc_crc_data(&tx);
	tx.field.crc_head=upc_crc_head(&tx);
	upc.txnew=1;
	upc.txcount=0;	
	upc.done=0;	
	UPC_Time2=3;;
}
*/
//-----------------------------------------------------------------------------------
void upc_answer_time()
{
//	u8 *ptr;
	tx.field.pre=0x55AA;
	tx.field.com=rx.field.com;
	tx.field.com.bit.id=Serial_ID;
	tx.field.com.bit.req=0;	
	tx.field.com.bit.com=rx.field.com.bit.com;
	tx.field.len=sizeof(TCTime);	
	memcpy(&tx.field.d[0],&MenuRegs.Time,7);	
	tx.field.crc_data=upc_crc_data(&tx);
	tx.field.crc_head=upc_crc_head(&tx);
	upc.txnew=1;
	upc.txcount=0;	
	upc.done=0;	
	UPC_Time2=3;;
}
//-----------------------------------------------------------------------------------
void upc_set_time()
{	
//	u8 *ptr;
	memcpy(&MenuRegs.Time,&rx.field.d[0],7);	
	fram_set_time(MenuRegs.Time.field.Hour,MenuRegs.Time.field.Minute,0);
	fram_set_date(MenuRegs.Time.field.Year,MenuRegs.Time.field.Month,MenuRegs.Time.field.Date,MenuRegs.Time.field.Day);
	DS1337_set_time(MenuRegs.Time.field.Hour,MenuRegs.Time.field.Minute,0);
	DS1337_set_date(MenuRegs.Time.field.Year,MenuRegs.Time.field.Month,MenuRegs.Time.field.Date,MenuRegs.Time.field.Day);
	tx.field.pre=0x55AA;
	tx.field.com.bit.id=Serial_ID;
	tx.field.com.bit.req=0;	
	tx.field.com.bit.com=rx.field.com.bit.com;
	tx.field.len=0;	
	tx.field.crc_data=upc_crc_data(&tx);
	tx.field.crc_head=upc_crc_head(&tx);
	upc.txnew=1;
	upc.txcount=0;	
	upc.done=0;	
	UPC_Time2=3;;
}
//-----------------------------------------------------------------------------------
void upc_set_in_parameters()
{
//	u8 *ptr;
	u8 ptr;
	u8 len;
	ptr=rx.field.d[0];
	len=rx.field.d[1];
	if(ptr<PARAMETERS_MAX)
		memcpy((void*)&intr.in_params[ptr],&rx.field.d[2],len*2);	
	tx.field.pre=0x55AA;
	tx.field.com.bit.id=Serial_ID;
	tx.field.com.bit.req=0;	
	tx.field.com.bit.com=rx.field.com.bit.com;
	tx.field.len=0;	
	tx.field.crc_data=upc_crc_data(&tx);
	tx.field.crc_head=upc_crc_head(&tx);
	upc.txnew=1;
	upc.txcount=0;	
	upc.done=0;	
	UPC_Time2=3;
}
//-----------------------------------------------------------------------------------
void upc_answer_out_parameters()
{
	u8 ptr=rx.field.d[0];
	u8 len=rx.field.d[1];
//	BuzzerTime=50;
//	ByteToStr(outtxt,&len,0);		
	tx.field.pre=0x55AA;
	tx.field.com.bit.id=Serial_ID;
	tx.field.com.bit.req=0;
	tx.field.com.bit.com=rx.field.com.bit.com;
	tx.field.len=len*2;	
//	memcpy(&tx.field.d[0],&intr.params[0],sizeof(intr.params));	
	if(ptr<PARAMETERS_MAX)
		memcpy(&tx.field.d[0],(void*)&intr.out_params[ptr],len*2);		
	
	tx.field.crc_data=upc_crc_data(&tx);
	tx.field.crc_head=upc_crc_head(&tx);
	upc.txnew=1;
	upc.txcount=0;	
	upc.done=0;	
	UPC_Time2=3;
}
//-----------------------------------------------------------------------------------
void upc_answer_store_parameters()
{
	Time_To_Store=3;
	tx.field.pre=0x55AA;
	tx.field.com.bit.id=Serial_ID;
	tx.field.com.bit.req=0;
	tx.field.com.bit.com=rx.field.com.bit.com;
	tx.field.len=0;	
	tx.field.crc_data=upc_crc_data(&tx);
	tx.field.crc_head=upc_crc_head(&tx);
	upc.txnew=1;
	upc.txcount=0;	
	upc.done=0;	
	UPC_Time2=3;
}
//-----------------------------------------------------------------------------------
void upc_answer_set_manual()
{
	MenuRegs.Manual_Mode=rx.field.d[0];
	tx.field.d[0]=MenuRegs.Manual_Mode;
	tx.field.pre=0x55AA;
	tx.field.com.bit.id=Serial_ID;
	tx.field.com.bit.req=0;
	tx.field.com.bit.com=com_set_manual;
	tx.field.len=1;	
	tx.field.crc_data=upc_crc_data(&tx);
	tx.field.crc_head=upc_crc_head(&tx);
	upc.txnew=1;
	upc.txcount=0;	
	upc.done=0;	
	UPC_Time2=3;		
}
//-----------------------------------------------------------------------------------
void upc_answer_get_season()
{
#if MAX_SEASON_BLOCK
	memcpy(&tx.field.d[0],(u8 __packed*)&reg_season,sizeof(TSeason));
#endif
	tx.field.pre=0x55AA;
	tx.field.com.bit.id=Serial_ID;
	tx.field.com.bit.req=0;
	tx.field.com.bit.com=rx.field.com.bit.com;
	tx.field.len=sizeof(TSeason);	
	tx.field.crc_data=upc_crc_data(&tx);
	tx.field.crc_head=upc_crc_head(&tx);
	upc.txnew=1;
	upc.txcount=0;	
	upc.done=0;	
	UPC_Time2=3;		
}
//-----------------------------------------------------------------------------------
void upc_answer_set_season()
{
#if MAX_SEASON_BLOCK
	memcpy((u8 __packed*)&reg_season,&rx.field.d[0],sizeof(TSeason));
#endif
//	memcpy(&tx.field.d[0],&MenuRegs.Season,sizeof(TSeason));
	tx.field.pre=0x55AA;
	tx.field.com.bit.id=Serial_ID;
	tx.field.com.bit.req=0;
	tx.field.com.bit.com=rx.field.com.bit.com;
	tx.field.len=0;	
	tx.field.crc_data=upc_crc_data(&tx);
	tx.field.crc_head=upc_crc_head(&tx);
	upc.txnew=1;
	upc.txcount=0;	
	upc.done=0;	
	UPC_Time2=3;		
}
//-----------------------------------------------------------------------------------
void upc_answer_get_misc()
{
#if MAX_PARAMS_BLOCK != 0	
	memcpy(&tx.field.d[0],&misc,sizeof(TParams));
#else
	memset(&tx.field.d[0],0,sizeof(TParams));	
#endif
	tx.field.pre=0x55AA;
	tx.field.com.bit.id=Serial_ID;
	tx.field.com.bit.req=0;
	tx.field.com.bit.com=rx.field.com.bit.com;
	tx.field.len=sizeof(TParams);	
	tx.field.crc_data=upc_crc_data(&tx);
	tx.field.crc_head=upc_crc_head(&tx);
	upc.txnew=1;
	upc.txcount=0;	
	upc.done=0;	
	UPC_Time2=3;		
}
//-----------------------------------------------------------------------------------
void upc_answer_set_misc()
{
#if MAX_PARAMS_BLOCK != 0	
	memcpy(&misc,&rx.field.d[0],sizeof(TParams));
	Time_To_Store=180;
#endif	
	tx.field.pre=0x55AA;
	tx.field.com.bit.id=Serial_ID;
	tx.field.com.bit.req=0;
	tx.field.com.bit.com=rx.field.com.bit.com;
	tx.field.len=0;	
	tx.field.crc_data=upc_crc_data(&tx);
	tx.field.crc_head=upc_crc_head(&tx);
	upc.txnew=1;
	upc.txcount=0;	
	upc.done=0;	
	UPC_Time2=3;		
}
//-----------------------------------------------------------------------------------
void upc_answer_set_register()
{
//	rx.field.d[0] - address
//	rx.field.d[1] - number of bytes
//	rx.field.d[0] - data itself
	u16 addr;
	u8 len;
	memcpy(&addr,&rx.field.d[0],2);		
	len=rx.field.d[2];
	memcpy(&reg_data[addr],&rx.field.d[3],len);	
	Time_To_Store=180;
	
	tx.field.pre=0x55AA;
	tx.field.com.bit.id=Serial_ID;
	tx.field.com.bit.req=0;
	tx.field.com.bit.com=rx.field.com.bit.com;
	tx.field.len=0;	
	tx.field.crc_data=upc_crc_data(&tx);
	tx.field.crc_head=upc_crc_head(&tx);
	upc.txnew=1;
	upc.txcount=0;	
	upc.done=0;	
	UPC_Time2=3;		
}
//-----------------------------------------------------------------------------------
void upc_answer_get_register()
{
	u16 addr;
	u8 len;
	memcpy(&addr,&rx.field.d[0],2);		
	len=rx.field.d[2];
	memcpy(&tx.field.d[3],&reg_data[addr],len);
	memcpy(&tx.field.d[0],&addr,2);	
	tx.field.d[2]=len;
	tx.field.pre=0x55AA;
	tx.field.com.bit.id=Serial_ID;
	tx.field.com.bit.req=0;
	tx.field.com.bit.com=rx.field.com.bit.com;
	tx.field.len=len+3;	
	tx.field.crc_data=upc_crc_data(&tx);
	tx.field.crc_head=upc_crc_head(&tx);
	upc.txnew=1;
	upc.txcount=0;	
	upc.done=0;	
	UPC_Time2=3;		
}
//-----------------------------------------------------------------------------------
void upc_answer_set_id()
{
	tx.field.com.bit.id=Serial_ID;
	tx.field.com.bit.req=0;
	tx.field.com.bit.com=rx.field.com.bit.com;
	tx.field.len=0;	
	tx.field.crc_data=upc_crc_data(&tx);
	tx.field.crc_head=upc_crc_head(&tx);
	upc.txnew=1;
	upc.txcount=0;	
	upc.done=0;	
	UPC_Time2=3;	
	Serial_ID=rx.field.d[0];
	id_store();
}
//-----------------------------------------------------------------------------------
void upc_answer_info(u8 what)
{
//	u8 *ptr;
	THeadShort info;
	memset(&info,0,sizeof(TPanelInfo));
	tx.field.pre=0x55AA;
	tx.field.com.bit.id=Serial_ID;
	tx.field.com.bit.req=1;
	
	tx.field.len=0;	
	switch(what)
	{
		case 1:
			tx.field.com.bit.com=com_reqt_sys_info;
			info.present=1;
			FGet(HAPP_FLASH_START+THW_LOC,(u8*)&info.HW_Version,4);
			FGet(HAPP_FLASH_START+TSW_LOC,(u8*)&info.SW_Version,4);
			FGet(HAPP_FLASH_START+TTIME_LOC,(u8*)&info.Time,sizeof(TCTime));
			memcpy(&tx.field.d[0],&info,sizeof(info));	
			tx.field.len=sizeof(info);		
		break;
		case 2:
			tx.field.com.bit.com=com_reqt_sys_name;
			FGet(HAPP_FLASH_START+TNAME_LOC,(u8*)&tx.field.d[0],TNAME_WIDTH);
			tx.field.len=TNAME_WIDTH;
		break;		
		case 3:
			tx.field.com.bit.com=com_reqt_menu_info;
			info.present=1;
			FGet(HPLM_FLASH_START+THW_LOC,(u8*)&info.HW_Version,4);
			FGet(HPLM_FLASH_START+TSW_LOC,(u8*)&info.SW_Version,4);
			FGet(HPLM_FLASH_START+TTIME_LOC,(u8*)&info.Time,sizeof(TCTime));
			memcpy(&tx.field.d[0],&info,sizeof(info));	
			tx.field.len=sizeof(info);
		break;					
		case 4:
			tx.field.com.bit.com=com_reqt_menu_name;
			FGet(HPLM_FLASH_START+TNAME_LOC,(u8*)&tx.field.d[0],TNAME_WIDTH);
			tx.field.len=TNAME_WIDTH;
		break;		
		case 5:
			tx.field.com.bit.com=com_get_enabled_options;
			//FGet(HPLM_FLASH_START+TNAME_LOC,(u8*)&tx.field.d[0],TNAME_WIDTH);
			tx.field.d[0]=NUM_PID;
			tx.field.d[1]=MAX_FANCOIL_NUMBER;
			tx.field.d[2]=MAX_KOTEL_NUMBER;			
			tx.field.d[3]=MAX_KOTEL_MODES;			
			tx.field.d[4]=MAX_KOTEL_FUELS;			
			tx.field.d[5]=MAX_VALVE_3T_NUMBER;			
			tx.field.d[6]=0;			
			tx.field.d[7]=0;			
			tx.field.d[8]=0;			
			tx.field.d[9]=0;			
			tx.field.len=10;
		break;		
		
	}	
	tx.field.crc_data=upc_crc_data(&tx);
	tx.field.crc_head=upc_crc_head(&tx);	
	upc.txnew=1;
	upc.txcount=0;	
	upc.done=0;	
	UPC_Time2=3;
}
//-----------------------------------------------------------------------------------
void upc_answer_set_register_advanced()
{
	u8 *block_ptr;
	TRegPacketAdv	*pack_head=(TRegPacketAdv*)&rx.field.d[0];
	switch(pack_head->type)
	{
#if NUM_PID		
	case BLOCK_PID:		block_ptr=(u8*)&pid[pack_head->rec];		break;
#endif
#if MAX_FANCOIL_NUMBER		
	case BLOCK_FAN:		block_ptr=(u8*)&fan[pack_head->rec];		break;
#endif
#if MAX_KOTEL_NUMBER		
	case BLOCK_KOTEL:	block_ptr=(u8*)&kotel;		break;
#endif
#if MAX_VALVE_3T_NUMBER		
	case BLOCK_VALVE:	block_ptr=(u8*)&valve[pack_head->rec];		break;	
#endif	
#if MAX_PARAMS_BLOCK		
	case BLOCK_PARAMETERS:	block_ptr=(u8*)&misc;					break;	
#endif	
#if MAX_SEASON_BLOCK
	case BLOCK_SEASON:	block_ptr=(u8*)&reg_season;					break;	
#endif
	default: block_ptr=NULL;
	}
	memcpy(&block_ptr[pack_head->addr],&rx.field.d[5],pack_head->len);	
	Time_To_Store=180;
	
	tx.field.pre=0x55AA;
	tx.field.com.bit.id=Serial_ID;
	tx.field.com.bit.req=0;
	tx.field.com.bit.com=rx.field.com.bit.com;
	tx.field.len=0;	
	tx.field.crc_data=upc_crc_data(&tx);
	tx.field.crc_head=upc_crc_head(&tx);
	upc.txnew=1;
	upc.txcount=0;	
	upc.done=0;	
	UPC_Time2=3;		
}
//-----------------------------------------------------------------------------------
void upc_answer_get_register_advanced()
{
	u8 *block_ptr;
	TRegPacketAdv	*pack_head=(TRegPacketAdv*)&rx.field.d[0];
	switch(pack_head->type)
	{
#if NUM_PID		
	case BLOCK_PID:		block_ptr=(u8*)&pid[pack_head->rec];		break;
#endif
#if MAX_FANCOIL_NUMBER		
	case BLOCK_FAN:		block_ptr=(u8*)&fan[pack_head->rec];		break;
#endif
#if MAX_KOTEL_NUMBER		
	case BLOCK_KOTEL:	block_ptr=(u8*)&kotel;						break;
#endif
#if MAX_VALVE_3T_NUMBER		
	case BLOCK_VALVE:	block_ptr=(u8*)&valve[pack_head->rec];		break;	
#endif	
#if MAX_PARAMS_BLOCK		
	case BLOCK_PARAMETERS:	block_ptr=(u8*)&misc;					break;	
#endif	
#if MAX_SEASON_BLOCK	
	case BLOCK_SEASON:	block_ptr=(u8*)&reg_season;					break;	
#endif
	default: block_ptr=NULL;
	}
	memcpy(&tx.field.d[5],&block_ptr[pack_head->addr],pack_head->len);
	memcpy(&tx.field.d[0],pack_head,sizeof(pack_head));
	tx.field.len=pack_head->len+sizeof(pack_head);	
	Time_To_Store=180;
	
	tx.field.pre=0x55AA;
	tx.field.com.bit.id=Serial_ID;
	tx.field.com.bit.req=0;
	tx.field.com.bit.com=rx.field.com.bit.com;
	tx.field.crc_data=upc_crc_data(&tx);
	tx.field.crc_head=upc_crc_head(&tx);
	upc.txnew=1;
	upc.txcount=0;	
	upc.done=0;	
	UPC_Time2=3;		
}
//-----------------------------------------------------------------------------------
void upc_set_do()
{
	if(rx.field.d[0]<NUM_DOUT)
	{
		if(rx.field.d[1])	io.dout |= 1 << rx.field.d[0];
		else 			io.dout &= ~( 1 << rx.field.d[0]);
	}
	tx.field.pre=0x55AA;
	tx.field.com.bit.id=Serial_ID;
	tx.field.com.bit.req=0;	
	tx.field.com.bit.com=rx.field.com.bit.com;
	tx.field.len=0;	
	tx.field.crc_data=upc_crc_data(&tx);
	tx.field.crc_head=upc_crc_head(&tx);
	upc.txnew=1;
	upc.txcount=0;	
	upc.done=0;	
	UPC_Time2=3;;
}
//-----------------------------------------------------------------------------------
