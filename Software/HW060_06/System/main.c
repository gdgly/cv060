//-----------------------------------------------------------------------------------
// Sourse programmable controller
//-----------------------------------------------------------------------------------
#include "main.h"
//-----------------------------------------------------------------------------------
u16 CRC;
u8 Cycle=0;
u8 To_Store=0;	// Sign to store parameters
//------------------------------------------------------------------------------
TController CV;
u8 middle;
u8 ID=0;
TInterpretatorRegisters intr;
u32 HW=0;
//-----------------------------------------------------------------------------------
void custom_handle();
void Fancoil_Temperature_Control();
void kotel_handle(void);
void valve_3t_handle();
void Season_Handle();
int stellaris_init(void);
int stellaris_run(void);
//-----------------------------------------------------------------------------------
in_flash u8	mdic[][80]=
{
	"\n\r Configuration data is OK. Loading... ",
	"\n\r Configuration record 1 is corrupted! Repairing...",
	"\n\r Configuration record 2 is corrupted! Repairing...",
	"\n\r"
	"\n\r Climate Commander"
	"\n\r Programmable controller",
	"\n\r Configuration records are corrupted! Impossible to load",
	"\n\r Setting default values",	
	"\n\r Name: ",
	" Bytes loaded",	
	"\n\r Configuration data single record mode",
	"\n\r Configuration data dual records mode",
};
//-----------------------------------------------------------------------------------
void params_set_default_always()
{
	u8 i;
	// IO init	
	io.dout=0;
	for(i=0;i<NUM_AOUT;i++)
		io.aoutput[i]=0;	
#if NUM_PID!=0
	// PID init
	for(i=0;i<NUM_PID;i++)
	{		
		pid[i].power=0;		
		pid[i].tin=pid[i].t0;
	}
#endif
#if MAX_KOTEL_NUMBER!=0
	kotel.mode=0;
    kotel.fan_out[0]=0;
    kotel.fan_out[1]=0;
    kotel.smoke_out=0;
    kotel.shnek_out[0]=0;
    kotel.shnek_out[1]=0;

    kotel.power=0;
    kotel.p3=0;
    kotel.open=0;
    kotel.close=0;
#endif	
//	if((MenuRegs.Season.t>300)||(MenuRegs.Season.t<-300))MenuRegs.Season.t=0;	
	MenuRegs.Manual_Mode=0;	
}
//-----------------------------------------------------------------------------------
void params_set_default()
{
	u8 i;
	// Defaults
	memset(&MenuRegs,0,sizeof(TMenuRegisters));				
	memset(&reg_season,0,sizeof(reg_season));				
	memset(&errors,0,sizeof(TErrors));						
	// Default
	io.num_di=NUM_DIN;
	io.num_do=NUM_DOUT;
	io.num_ai=NUM_AIN;
	io.num_ao=NUM_AOUT;			
	for(i=NUM_AIN_REAL-1;i<NUM_AIN;i++)
		io.ainput[i]=5000;

#if NUM_PID
	memset(&pid,0,NUM_PID*sizeof(TPID));		
	for(i=0;i<NUM_PID;i++)
	{		
		pid[i].channel=0;
		pid[i].p=100;
		pid[i].d=500;
		pid[i].i=50;
		pid[i].t0=200;
		pid[i].power_min=0;
		pid[i].power=0;			
		pid[i].power_max=1000;
		pid[i].mode=1;
		pid[i].tin=0;		
//		pid[i].t3max=155;
//		pid[i].open=0;
//		pid[i].close=0;					
//		pid[i].p3=0;	
		pid[i].PID_POWER_STEP[0]=0.01;		// Slow
		pid[i].PID_POWER_STEP[1]=0.08;		// Fast
		pid[i].PID_POWER_LIMIT[0]=35;		// Zero power border
		pid[i].PID_POWER_LIMIT[1]=350;		// Low power border	
		pid[i].heating_cooling=PID_HEATING;		
	}
#endif

	MenuRegs.password=1;
	memset(&MenuRegs.pass_user[0],0,sizeof(5));	
//		memset(&MenuRegs.pass_admin[0],0,sizeof(5));	
	MenuRegs.pass_admin[0]=9;
	MenuRegs.pass_admin[1]=8;
	MenuRegs.pass_admin[2]=1;
	MenuRegs.pass_admin[3]=2;
	MenuRegs.pass_admin[4]=5;		
	MenuRegs.lang=1; // Language=RUS
	MenuRegs.Manual_Mode=AUTO_MODE;
//		memset(&MenuRegs.params,0,sizeof(MenuRegs.params));				
	memset(&MenuRegs.Schedule_Enable,0,1);	
	memset(&MenuRegs.Schedule_Time,0,4);	
	memset(&MenuRegs.Timer_Enable,0,1);	
	memset(&MenuRegs.Timer_Time,0,4);	
	// Fancoil values
#if MAX_FANCOIL_NUMBER!=0	
	for(i=0;i<MAX_FANCOIL_NUMBER;i++)
	{
		fan[i].T=220;
		fan[i].Fan_Mode=FAN_AUTO;
		fan[i].Fan_Lvl=1;
		fan[i].Valve=0;
		fan[i].TLow=5;
		fan[i].TMedium=10;
		fan[i].THigh=20;
		fan[i].Hysteresis=2;
		fan[i].Fan_Time=1;
		fan[i].Valve_Time_1=150;
		fan[i].Valve_Time_2=150;
		fan[i].Valve_Hysteresis=5;
		fan[i].Day_Night=fan_Day;		
		fan[i].Channel=1;		
	}
#endif
#if MAX_KOTEL_NUMBER
	kotel.mode=0;
	kotel.fuel=0;
	kotel.t=600;
    kotel.channel=0;
	kotel.t3max=150;
	for(i=0;i<MAX_KOTEL_FUELS;i++)
	{
		kotel.smoke_speed[i]=50;
		for(j=0;j<MAX_KOTEL_MODES;j++)
		{
			kotel.p[i][j].t=0;
			kotel.p[i][j].fan_speed[0]=50;		
			kotel.p[i][j].fan_speed[1]=20;		
			kotel.p[i][j].fan_on[0]=1;		
			kotel.p[i][j].fan_on[1]=0;		
			kotel.p[i][j].fan_off[0]=0;		
			kotel.p[i][j].fan_off[1]=0;		
	
			kotel.p[i][j].shnek_ena[0]=1;		
			kotel.p[i][j].shnek_ena[1]=0;		
			kotel.p[i][j].shnek_on[0]=3;		
			kotel.p[i][j].shnek_on[1]=0;		
			kotel.p[i][j].shnek_off[0]=10;		
			kotel.p[i][j].shnek_off[1]=0;
			
			kotel.p[i][j].smoke_speed=50;
		}
	}
#endif	
#if MAX_VALVE_3T_NUMBER
	memset(&valve,0,MAX_VALVE_3T_NUMBER*sizeof(TValve3t));	
	for(i=0;i<MAX_VALVE_3T_NUMBER;i++)
	{
		valve[i].t3max=150;
	}
#endif		
#if MAX_PARAMS_BLOCK
	memset(&misc,0,sizeof(TParams));	
#endif		
}
//-----------------------------------------------------------------------------------
void params_store_new(u16 PARAM_LOCATION)
{
	fram_mem_enable();
	fram_mem_write(PARAM_LOCATION,(u8*)&CV,sizeof(CV));
	CRC=CheckCRC(0,PARAM_LOCATION);	
	fram_mem_write(PARAM_LOCATION+TPARAM_WIDTH-2,(u8*)&CRC,2);
	fram_mem_disable();	
}
//-----------------------------------------------------------------------------------
void params_load()
{
	u16 PARAM_LOCATION=PARAM_LOCATION_0;
	u16 tmp;
	u8 valid[2]={0};
#if PARAM_RECORDS == 1
	__sprintf_P(outtxt,mdic[8]);	
#endif
#if PARAM_RECORDS == 2
	__sprintf_P(outtxt,mdic[9]);	
#endif
	
	// Checking record 1
	wtmp=CheckCRC(0,PARAM_LOCATION);	
	fram_mem_read(PARAM_LOCATION+TPARAM_WIDTH-2,(u8*)&CRC,2);
	if(CRC==wtmp)valid[0]=1;
#if PARAM_RECORDS == 1
	if(valid[0]==0)
	{
		__sprintf_P(outtxt,mdic[1]);
		params_set_default();			
		params_store();	
	}
	else
	{
		__sprintf_P(outtxt,mdic[0]);
		tmp=sizeof(CV);
		WordToStr(outtxt,&tmp,0);
		__sprintf_P(outtxt,mdic[7]);
	}
	fram_mem_read(PARAM_LOCATION_0,(u8*)&CV,sizeof(CV));	
	return;
#endif	
#if PARAM_RECORDS >1
	// Checking record 2
	PARAM_LOCATION=PARAM_LOCATION_1;
	wtmp=CheckCRC(0,PARAM_LOCATION);	
	fram_mem_read(PARAM_LOCATION+TPARAM_WIDTH-2,(u8*)&CRC,2);
	if(CRC==wtmp)valid[1]=1;
	
	// Choosing actions
	if(valid[0]==1)
	{
		__sprintf_P(outtxt,mdic[0]);
		fram_mem_read(PARAM_LOCATION_0,(u8*)&CV,sizeof(CV));
		if(valid[1]==0)
		{
			params_store_new(PARAM_LOCATION_1);
			__sprintf_P(outtxt,mdic[2]);
		}
	}
	else
	{
		if(valid[1]==1)
		{
			__sprintf_P(outtxt,mdic[0]);			
			fram_mem_read(PARAM_LOCATION_1,(u8*)&CV,sizeof(CV));
			__sprintf_P(outtxt,mdic[1]);			
			params_store_new(PARAM_LOCATION_0);
		}
		else
		{
			fram_mem_read(PARAM_LOCATION_1,(u8*)&CV,sizeof(CV));
			__sprintf_P(outtxt,mdic[4]);			
			__sprintf_P(outtxt,mdic[5]);	
			// Loading corrupted structure
			fram_mem_read(PARAM_LOCATION_0,(u8*)&CV,sizeof(CV));
			params_set_default();			
			params_store();
		}
	}
#endif	
	params_set_default_always(); // Part of necessary inited parameters
}
//-----------------------------------------------------------------------------------
void params_store()
{	
	params_store_new(PARAM_LOCATION_0);
#if PARAM_RECORDS > 1	
	params_store_new(PARAM_LOCATION_1);
#endif
}
//-----------------------------------------------------------------------------------
void id_read()
{
	FGet(HAPP_FLASH_START+THW_LOC,(u8*)&HW,4); // Hardware number
	fram_comp_read(fram_reg_Serial0,&ID,1);
	__sprintf((u8*)outtxt,"\n\r ID-");ByteToStr(outtxt,&ID,0);
	if(ID>MAX_ID)ID=0;
}
//-----------------------------------------------------------------------------------
void id_store()
{
	fram_comp_write(fram_reg_Serial0,&ID,1);
}
//-----------------------------------------------------------------------------------
void init()
{
	hardware_init();
	Timer_Init();	
	con_init();
	upc_init();
	adc_init();
    menu_init();
	io_init();	
	lcd_io_init();
	I2C_Init();
	watchdog_reset();
#if	TMP441_ENABLE		
	TMP441_init();
#endif	
	Intr_Init();
	pid_init();
	error_init();
	enable_interrupt();		
}
//-----------------------------------------------------------------------------------
void main(void)
{
	init();
 	__sprintf_P((u8*)outtxt,mdic[3]);	
	id_read();		
	__sprintf_P(outtxt,mdic[6]);
	FGet(HAPP_FLASH_START,outtxt,TNAME_WIDTH);
	params_load();	
	lcd_init();	
	Prog_Check();
	Intr_Program_Start();
	middle=1;
	__sprintf((u8*)outtxt,"\n\r>");										
	SysSetUp=SYS_SET_UP_PERIOD;
	while(1)
	{
		watchdog_reset();
		if(FramTime==0)
		{
			FramTime=1000;
			LED_Time=250;
			fram_get_time(&MenuRegs.Time);		
			ft=MenuRegs.Time;			
		}		
 		if(Adc_Time==0)
		{
			Adc_Time=100;
			adc_handle();
		}
		con_handle();		
		keys_menu();		
		
		io_handle();				
		Intr_Handle();		
		custom_handle();
		Season_Handle();
		Fancoil_Temperature_Control();
		valve_3t_handle();
		kotel_handle();

		if((To_Store)&&(Time_To_Store==0))
		{
			params_store();
			To_Store=0;
		}
	}
}
//-----------------------------------------------------------------------------------
