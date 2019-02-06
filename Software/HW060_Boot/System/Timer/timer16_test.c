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

u8 Time_To_Store=0;
//vf32	iftmp;
//vs8	ictmp;
//-----------------------------------------------------------------------------------
void Timer_1ms_IRQ()
{
//	u8 i;
	if(Time0!=0)Time0--;

	if(Time1!=0)
	{
		Time1--;	
	}
	else
	{
		Time1=1000;	
	}
	if(Time5!=0)Time5--;
	if(Time6!=0)Time6--;	
	if(Adc_Time!=0)Adc_Time--;	
	if(FramTime!=0)FramTime--;
	if(DelayTime!=0)DelayTime--;	
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
	for(i=0;i<val;i++)
		for(j=0;j<60;j++)
			z=z^(i*j);
	return z;
}
//-----------------------------------------------------------------------------------
