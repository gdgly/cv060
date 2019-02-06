#include "main.h"
//-----------------------------------------------------------------------------------
#define PID_TIME_MAX 600
//u16 time,del_time;
volatile u16 Time0=0;
volatile u16 Time1=0;
volatile u16 Time5=0;
//volatile u16 PID_Time=PID_TIME_MAX;
//volatile u16 PID_Test_Time=0;
volatile u16 FramTime=0;
volatile u16 BuzzerTime=0;
volatile u16 DelayTime=0;
volatile u16 SysSetUp=0;
volatile u16 Adc_Time=0;
volatile u16 Time6=0;
volatile u16 LCD_Time=0;
volatile u16 LED_Time=0;
volatile u16 Sec_Time=0;
volatile u16 UPC_Time=0;
volatile u16 UPC_Time2=0;

extern volatile unsigned short i2c_timer;

extern volatile u16 IP_Inactive_Timer;
extern volatile u16 IP_Multiply_Timer;
extern u8 last_operation;
u8 Time_To_Store = 0;
u8 Time_To_Store_Full = 0;
extern u8 To_Store_Full;
//vf32	iftmp;
//vs8	ictmp;
#if MAX_VALVE_3T_NUMBER
extern u16 VALVE_P3_Time[MAX_VALVE_3T_NUMBER];
extern u16 VALVE_Tail_Timer[MAX_VALVE_3T_NUMBER];
#endif
extern u8 Season_Timeout;
#if MAX_FANCOIL_NUMBER
	extern u8 Fan_Switch_Enable[MAX_FANCOIL_NUMBER];
	extern u8 Valve_Switch_Enable[MAX_FANCOIL_NUMBER];
	extern u8 Valve_Transfer_Enable[MAX_FANCOIL_NUMBER];
	extern TFanLines FanLines[MAX_FANCOIL_NUMBER];
#endif
#ifdef __PID_ALGORITHM_ALT
	extern volatile u8 pid_alt_timer[NUM_PID];
#endif
//-----------------------------------------------------------------------------------
void Timer_1ms_IRQ()
{
	u8 i;
	if(Time0!=0)Time0--;
	if (restore_ip_core_delay) restore_ip_core_delay --;
	if(intr.t32[0]!=0)intr.t32[0]--;		
	if(intr.t32[1]!=0)intr.t32[1]--;		
	if(intr.t32[2]!=0)intr.t32[2]--;		
	if(intr.t32[3]!=0)intr.t32[3]--;	

	if(Time5!=0)Time5--;
	if(Time6!=0)Time6--;	
	if(Adc_Time!=0)Adc_Time--;	
	if(FramTime!=0)FramTime--;
	if(DelayTime!=0)DelayTime--;	
	if(UPC_Time2!=0)UPC_Time2--;
	if (i2c_timer) i2c_timer --;
	if (SysSetUp) SysSetUp--;
	if(PID_Time!=0)PID_Time--;	
	
	if(IP_Inactive_Timer!=0)IP_Inactive_Timer--;	
	else last_operation=0;
	if(Time1!=0)
	{
		Time1--;	
	}
	else
	{
		Time1=1000;	
		if(intr.t32[4]!=0)intr.t32[4]--;		
		if(intr.t32[5]!=0)intr.t32[5]--;		
		if(intr.t32[6]!=0)intr.t32[6]--;		
		if(intr.t32[7]!=0)intr.t32[7]--;
		if (restore_ip_core_cycle_delay) restore_ip_core_cycle_delay --;
		if(IP_Multiply_Timer!=0)IP_Multiply_Timer--;	
		if(Time_To_Store != 0){
			Time_To_Store --;	
			To_Store = 1;
		}
		if(Time_To_Store_Full != 0){
			Time_To_Store_Full --;	
			To_Store_Full = 1;
		}
#if MAX_VALVE_3T_NUMBER
		for(i=0; i<MAX_VALVE_3T_NUMBER; i++)	
			if(VALVE_Tail_Timer[i])	VALVE_Tail_Timer[i]--;
#endif
		if(Season_Timeout!=0)Season_Timeout--;	
#if MAX_KOTEL_NUMBER
		if(Stop_Timeout!=0)Stop_Timeout--;
		if(Mode_1_timeout!=0)Mode_1_timeout--;		
		for(i=0;i<2;i++)
		{
			if(sh_on[i]!=0)sh_on[i]--;
			if(sh_off[i]!=0)sh_off[i]--;
			if(fan_on[i]!=0)fan_on[i]--;
			if(fan_off[i]!=0)fan_off[i]--;
		}			
#endif		
#if MAX_FANCOIL_NUMBER			
		for(i=0;i<MAX_FANCOIL_NUMBER;i++)
		{
			if(Fan_Switch_Enable[i]!=0)Fan_Switch_Enable[i]--;
			if(Valve_Switch_Enable[i]!=0)Valve_Switch_Enable[i]--;
			if(Valve_Transfer_Enable[i]!=0)Valve_Transfer_Enable[i]--;
		}		
#endif		
#ifdef __PID_ALGORITHM_ALT
		for(i=0;i<NUM_PID;i++)
		{
			if(pid_alt_timer[i]!=0)pid_alt_timer[i]--;
		}	
#endif
	}

#if MAX_VALVE_3T_NUMBER
	if(MenuRegs.Manual_Mode!=MANUAL_MODE)
		for(i=0;i<MAX_VALVE_3T_NUMBER;i++)			
		{
			if(VALVE_P3_Time[i]!=0)
				VALVE_P3_Time[i]--;
			else
			{
				VALVE_P3_Time[i]=valve[i].t3max;
				if(valve[i].open!=0)
				{
					if(valve[i].p3<999)
						valve[i].p3+=1;
				}
				if(valve[i].close!=0)
				{
					if(valve[i].p3>0)
						valve[i].p3-=1;
				}
			}		
		}
#endif

#if MAX_KOTEL_NUMBER
	if(MenuRegs.Manual_Mode!=MANUAL_MODE)
	{
			if(Kotel_P3_Time!=0)
				Kotel_P3_Time--;
			else
			{
				Kotel_P3_Time=kotel.t3max;
				if(kotel.open!=0)
				{
					if(kotel.p3<999)
						kotel.p3+=1;
				}
				if(kotel.close!=0)
				{
					if(kotel.p3>0)
						kotel.p3-=1;
				}
			}		
	}
#endif
	upc_TXHandler();
}
//-----------------------------------------------------------------------------------
void Delay(u16 val)// value in ms
{
	DelayTime=val;
	while(DelayTime!=0)	
	{
	}
}
//-----------------------------------------------------------------------------------
int Delay_mks(u16 val)// value in mks
{
	u16 i,j;
	int z;
	for(i=0;i<val;i++){
		watchdog_reset();
		for(j=0;j<60;j++)
			z=z^(i*j);
	}
	return z;
}
//-----------------------------------------------------------------------------------
