//------------------------------------------------------------------------------
// Sourse programmable controller
//------------------------------------------------------------------------------
#include "main.h"
//------------------------------------------------------------------------------
u16 CRC;
u8 Cycle = 0;
u8 To_Store = 0;			// Sign to store parameters
u8 To_Store_Full = 0;		// Sign to store all parameters
//------------------------------------------------------------------------------
TController 				CV;
TController 				CV_Buff;
TInterpretatorRegisters 	intr;
u32 HW=0;
TErrors 					_errors;
//------------------------------------------------------------------------------
TExtController				ExtCV;
//------------------------------------------------------------------------------
void custom_handle();
void Fancoil_Temperature_Control();
void kotel_handle(void);

void stellaris_init(void);
void stellaris_IP_init(void);
void stellaris_run(void);
void do_process(unsigned __packed long *dout);
unsigned long di_process(unsigned long old_di);
void ao_process(short __packed  *AO ,unsigned char num);
void AT45_Init();              
void FS_Check();
void ip_multyply_command_handle();
unsigned long di_adc_process();
extern tBoolean IntMasterEnable(void);
extern tBoolean IntMasterDisable(void);
void indication_init();
void stellaris_IP_init(void);
void I2C_Init(void);
void Season_Handle(void);
void valve_3t_handle(void);
u8 get_day_of_week(TCTime *time);
void indication_handle(void);
//------------------------------------------------------------------------------
in_flash u8	mdic[][80]=
{
	"\n\r Configuration data is OK. Loading...",
	"\n\r Configuration record 1 is corrupted! Repairing...",
	"\n\r Configuration record 2 is corrupted! Repairing...",
	"\n\r"
	"\n\r Climate Commander"
	"\n\r Programmable controller",
	"\n\r Configuration records are corrupted! Impossible to load",
	"\n\r Setting default values",	
	"\n\r Name: ",		
};
//------------------------------------------------------------------------------
void params_set_default_always()
{
	u8 i;
	// IO init	
	io.dout=0;
#if AO_STARTUP_INIT
	for(i=0;i<NUM_AOUT;i++)
		io.aoutput[i]=0;
#endif	
#if NUM_PID!=0
	// PID init
	for(i=0;i<NUM_PID;i++)
	{		
		pid[i].power=0;			
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
	if((reg_season.t>300)||(reg_season.t<-300))reg_season.t=0;	
	MenuRegs.Manual_Mode=AUTO_MODE;	
}
//-----------------------------------------------------------------------------------
void params_set_default()
{
	u8 i;
	// Defaults
	memset(&MenuRegs,0,sizeof(TMenuRegisters));				
	memset((u8 __packed*)&errors,0,sizeof(TErrors));						
	// Default
	io.num_di=NUM_DIN;
	io.num_do=NUM_DOUT;
	io.num_ai=NUM_AIN;
	io.num_ao=NUM_AOUT;			

	reg_ip.mask[0]=255;
	reg_ip.mask[1]=255;
	reg_ip.mask[2]=255;
	reg_ip.mask[3]=0;	
	reg_ip.gw[0]=192;
	reg_ip.gw[1]=168;
	reg_ip.gw[2]=1;
	reg_ip.gw[3]=1;		
	
	reg_ip.mac[0]=0x00;
	reg_ip.mac[1]=0x19;
	reg_ip.mac[2]=0x4f;
	reg_ip.mac[3]=0xd2;
	reg_ip.mac[4]=0x99;
	reg_ip.mac[5]=0x78;
	
#if NUM_PID
	memset((u8 __packed*)&pid,0,NUM_PID*sizeof(TPID));		
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
		pid[i].tin=30;		
		pid[i].PID_POWER_STEP[0]=0.01;		// Slow
		pid[i].PID_POWER_STEP[1]=0.08;		// Fast
		pid[i].PID_POWER_LIMIT[0]=35;		// Zero power border
		pid[i].PID_POWER_LIMIT[1]=350;		// Low power border	
		pid[i].heating_cooling=PID_HEATING;		
	}
#endif

	MenuRegs.password=1;
	memset(&MenuRegs.pass_user[0],0,sizeof(5));		
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
		fan[i].Fan_Mode=0;
		fan[i].Fan_Lvl=1;
		fan[i].Valve=0;
		fan[i].TLow=5;
		fan[i].TMedium=10;
		fan[i].THigh=20;
		fan[i].Hysteresis=2;
		fan[i].Fan_Time=1;
		fan[i].Valve_Hysteresis=5;
		fan[i].Day_Night=fan_Day;		
		fan[i].Channel=1;		
		fan[i].T_In=0;
		fan[i].HC=0;
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
}

//-----------------------------------------------------------------------------------
void ext_params_set_default()
{
#if INI_FILE
	u8 i;
	// Defaults			
	memset((u8 __packed*)&ExtCV,0,sizeof(ExtCV));						
	// Default
	if (((ID[0] == 0) || (ID[0] == 0xff)) & \
		((ID[1] == 0) || (ID[1] == 0xff)) & \
		((ID[2] == 0) || (ID[2] == 0xff)) & \
		((ID[3] == 0) || (ID[3] == 0xff)))
		strcpy(ExtCV.ip_str, 	"192.168.1.100");
	strcpy(ExtCV.mask_str, 	"255.255.255.0");
	strcpy(ExtCV.gw_str, 	"192.168.1.1");
	ExtCV.ser_id 	= 1;
	ExtCV.bl_pid 	= NUM_PID;
	ExtCV.bl_fan 	= MAX_FANCOIL_NUMBER;
    ExtCV.bl_valve 	= MAX_VALVE_3T_NUMBER;
	ExtCV.bl_kotel 	= MAX_KOTEL_NUMBER;
	ExtCV.bl_param 	= MAX_PARAMS_BLOCK;
	ExtCV.bl_season = MAX_SEASON_BLOCK;
	for (i=0; i < NUM_AIN_REAL; i++)
		ExtCV.adc_filter_time[i] = 200;
#endif
}
//-----------------------------------------------------------------------------------
void mem_dump(u8 *buff,u8 len);
u16 get_crc(u8 *buff, u16 len);

void fram_params_store(u16 PARAM_LOCATION)
{
	fram_mem_enable();	
	fram_mem_write(PARAM_LOCATION,(u8*)&CV,sizeof(CV));
	fram_mem_disable();
}
//-----------------------------------------------------------------------------------
void params_load()
{
	u8 valid[2]={0};
	//u16 i;
	u16 wtmp;

	// *** Load dynamical variables
	
	// Checking old style record 
	if ( file_load((u8*)&CV_Buff, sizeof(CV_Buff), "config.cfg")) {
		CV.field._io = CV_Buff.field._io;
		CV.field._ip = CV_Buff.field._ip;
		//__sprintf_P(outtxt,"\n\r1 Native CRC=");  WordToStr(outtxt,(u16*)&CV_Buff.field.CRC,1);
		//__sprintf_P(outtxt,"\n\r1 Calcul CRC=");  WordToStr(outtxt,&wtmp,1);
	}
	// Checking record 2
	if ( file_load((u8*)&CV_Buff, sizeof(CV_Buff), "config2.cfg")){
		CV.field._io = CV_Buff.field._io;
		CV.field._ip = CV_Buff.field._ip;
		wtmp=CheckCRC(3,(u32)&CV_Buff);	
		//__sprintf_P(outtxt,"\n\r0 Native CRC=");  WordToStr(outtxt,(u16*)&CV_Buff.field.CRC,1);
		//__sprintf_P(outtxt,"\n\r0 Calcul CRC=");  WordToStr(outtxt,&wtmp,1);
		if(CV_Buff.field.CRC == wtmp)valid[1]=1;
	}
	// Checking record 1
	if ( file_load((u8*)&CV_Buff, sizeof(CV_Buff), "config1.cfg")) {
		CV.field._io = CV_Buff.field._io;
		CV.field._ip = CV_Buff.field._ip;
		wtmp=CheckCRC(3,(u32)&CV_Buff);	
		//__sprintf_P(outtxt,"\n\r1 Native CRC=");  WordToStr(outtxt,(u16*)&CV_Buff.field.CRC,1);
		//__sprintf_P(outtxt,"\n\r1 Calcul CRC=");  WordToStr(outtxt,&wtmp,1);
		if(CV_Buff.field.CRC == wtmp)valid[0]=1;
	}

	// Choosing actions
	if(valid[0]==1)
	{
		__sprintf_P(outtxt,mdic[0]);
		file_load((u8*)&CV, sizeof(CV), "config1.cfg");
		if(valid[1]==0)
		{
			full_params_store();
			__sprintf_P(outtxt,mdic[2]);
		}
	}
	else
	{
		if(valid[1]==1)
		{
			__sprintf_P(outtxt,mdic[0]);			
			file_load((u8*)&CV, sizeof(CV), "config2.cfg");
			__sprintf_P(outtxt,mdic[1]);			
			full_params_store();
		}
		else
		{
			__sprintf_P(outtxt,mdic[4]);			
			__sprintf_P(outtxt,mdic[5]);	
			// All records are demaged
			CV.field._io = CV_Buff.field._io;
			CV.field._ip = CV_Buff.field._ip;
			params_set_default();	
			params_store();
		}
	}
	
	// *** Load static parameters which will stay unchanged
	if (FS_File_Check("conf_str.cfg"))
		nvar_load("conf_str.cfg");
	else{
		ext_params_set_default();
		nvar_store("conf_str.cfg");
	}
	
	// *** Init variables
	params_set_default_always(); 
	
	// *** Stellaris lwip IP reinit
	IP4_ADDR_MAKE(new_ip,ID[0],ID[1],ID[2],ID[3]);
	IP4_ADDR_MAKE(new_mask,reg_ip.mask[0],reg_ip.mask[1],reg_ip.mask[2],reg_ip.mask[3]);
	IP4_ADDR_MAKE(new_gw,reg_ip.gw[0],reg_ip.gw[1],reg_ip.gw[2],reg_ip.gw[3]);
	update_ip_address=1;
	update_mask_address=1;
	update_gw_address=1;
}
//-----------------------------------------------------------------------------------
void params_store()
{
	CV.field.CRC=CheckCRC(3,(u32)&CV);
	file_store(&CV,sizeof(CV),"config1.cfg");
	file_store(&CV,sizeof(CV),"config2.cfg");
	__sprintf((u8*)outtxt,"\n\r Saving parameters...");
	//__sprintf_P(outtxt,"\n\rNative CRC=");  WordToStr(outtxt,(u16*)&CV.field.CRC,1);
}
//-----------------------------------------------------------------------------------
void full_params_store()
{
	params_store();
	if (FS_File_Check("conf_str.cfg"))
		nvar_store("conf_str.cfg");
	else{
		ext_params_set_default();
		nvar_store("conf_str.cfg");
	}
			
}
//-----------------------------------------------------------------------------------
void id_show()
{
	__sprintf((u8*)outtxt,"\n\r IP   ");ByteToStr(outtxt,&ID[0],0);
	__sprintf((u8*)outtxt,".");ByteToStr(outtxt,&ID[1],0);
	__sprintf((u8*)outtxt,".");ByteToStr(outtxt,&ID[2],0);
	__sprintf((u8*)outtxt,".");ByteToStr(outtxt,&ID[3],0);
	__sprintf((u8*)outtxt,"\n\r Mask ");ByteToStr(outtxt,&reg_ip.mask[0],0);
	__sprintf((u8*)outtxt,".");ByteToStr(outtxt,&reg_ip.mask[1],0);
	__sprintf((u8*)outtxt,".");ByteToStr(outtxt,&reg_ip.mask[2],0);
	__sprintf((u8*)outtxt,".");ByteToStr(outtxt,&reg_ip.mask[3],0);
	__sprintf((u8*)outtxt,"\n\r GW   ");ByteToStr(outtxt,&reg_ip.gw[0],0);
	__sprintf((u8*)outtxt,".");ByteToStr(outtxt,&reg_ip.gw[1],0);
	__sprintf((u8*)outtxt,".");ByteToStr(outtxt,&reg_ip.gw[2],0);
	__sprintf((u8*)outtxt,".");ByteToStr(outtxt,&reg_ip.gw[3],0);
}
//-----------------------------------------------------------------------------------
#define USE_FIXED_IP
void id_read()
{
	params_load();
#ifdef USE_FIXED_IP
	ID[0] = 192;
	ID[1] = 168;
	ID[2] = 1;
	ID[3] = 101;
#endif
}
//-----------------------------------------------------------------------------------
void id_store()
{
}
//-----------------------------------------------------------------------------------
void init()
{
	watchdog_init();	
	stellaris_init();
	Timer_Init();	
	con_init();	
	adc_init();
	AT45_Init();
	upc_init();
	I2C_Init();
	DS1337_init();	
	indication_init();
}
//------------------------------------------------------------------------------
void full_main(void)
{
	init();
    watchdog_reset();
 	__sprintf_P((u8*)outtxt,mdic[3]);	
	__sprintf_P(outtxt,mdic[6]);
	strcpy((char*)outtxt, (char*)(HAPP_FLASH_START));
	__sprintf(outtxt,"");
	params_load();	
	id_show();	
	watchdog_reset();
	FS_Check();
	__sprintf((u8*)outtxt,"\n\r>");											
	Intr_Program_Start();
	stellaris_IP_init();
	IntMasterEnable();
	SysSetUp = SYS_SET_UP_PERIOD;
	while(1)
	{
		watchdog_reset();
		stellaris_run();		
		
		IntMasterDisable();
			do_process(&io.dout);
			io.din=di_process(io.din);
		IntMasterEnable();
		
		ao_process(io.aoutput, 3);
		con_handle();
		if (SysSetUp == 0)
			Intr_Handle();
		ip_multyply_command_handle();
		Season_Handle();
		Fancoil_Temperature_Control();
		valve_3t_handle();
		kotel_handle();
		restore_ip_core_loop();
		if(PID_Time == 0)	{
			PID_Time = PID_CYCLE_TIME;
			pid_handle();
		}
		if(FramTime == 0)	{
			FramTime = 1000;
			LED_Time = 250;
			IntMasterDisable();
				fram_get_time(&MenuRegs.Time);
				DS1337_get_time(&MenuRegs.Time);
				MenuRegs.Time.field.Day = get_day_of_week(&MenuRegs.Time);
			IntMasterEnable();
		}	
		if(Adc_Time == 0){
			Adc_Time = ADC_SAMPLE_TIMEOUT;
			adc_handle();
			//indication_handle();
		}
		if((To_Store) && (Time_To_Store == 0))
		{
			IntMasterDisable();
			params_store();
			To_Store = 0;
			IntMasterEnable();
		}		
		if((To_Store_Full) && (Time_To_Store_Full == 0))
		{
			IntMasterDisable();
			full_params_store();
			To_Store_Full = 0;
			IntMasterEnable();
		}	
	}
}
//-----------------------------------------------------------------------------------
