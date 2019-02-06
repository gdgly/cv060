//------------------------------------------------------------------------------
#include "main.h"
//------------------------------------------------------------------------------
void Set_Valve_Power();
void Set_Valve_T3max();
void Set_Valve_P3();
void valve_3t_init();
void valve_3t_handle();
//------------------------------------------------------------------------------
in_flash u8	valve_str[][30]=
{
	"\n\r   Valve settings",				//0
	"\n\r     Power             ",			//1
	"\n\r     3 points power    ",			//2
	"\n\r     Full cycle time c ",			//3
	"\n\r     Open  line        ",			//4
	"\n\r     Close line        ",			//5		
	"\n\r No valves",						//6	
	"\n\r Wrong valve number",				//7	
};
#if MAX_VALVE_3T_NUMBER
u16 VALVE_P3_Time[MAX_VALVE_3T_NUMBER];
u16 VALVE_Tail_Timer[MAX_VALVE_3T_NUMBER]={0};
#endif
//------------------------------------------------------------------------------
void valve_3t_init(void)
{	
#if MAX_VALVE_3T_NUMBER
//	u8 i;
//	memset(&pid,0,sizeof(pid));	
//	memset(pmem,0,NUM_PID*sizeof(TIntMem));			
#endif
}
//------------------------------------------------------------------------------
void valve_3t_handle(void)
{
#if MAX_VALVE_3T_NUMBER
	u8 q;
	s16	d,ud;
//	s16 delta;
//	f32	power;
//	f32	unsigned_power;
//	f32 power_step;
	
	if(MenuRegs.Manual_Mode==MANUAL_MODE)return; // In manual mode no changes in PID
	for(q=0;q<MAX_VALVE_3T_NUMBER;q++)
	{
#ifdef   __VALVE_ALGORITHM_MOVE_AT_END
		if(valve[q].p3 > 990)valve[q].p3 = 990;
		if(valve[q].p3 < 10)valve[q].p3 = 10;
#endif
		// Calculating 3 point servoprivod values
		d=valve[q].power-valve[q].p3;
		if(d<0)ud=-d;
		else ud=d;
		if(ud<NUM_VALVE_STEP)d=0;

		if(d!=0)
		{				
			 if(d>0)
			 	valve[q].open=1;
			 else
			 	valve[q].open=0;
			 if(d<0)
			 	valve[q].close=1;				
			 else
			 	valve[q].close=0;			 
		}
		else
		{
			valve[q].open=0;				
			valve[q].close=0;				
/*
			if(valve[q].p3>=995)
			{
					if(VALVE_Tail_Timer[q])
					{
						valve[q].open=1;
						valve[q].close=0;
					}
			}
			else
			{
				if(valve[q].p3<=5)
				{
					if(VALVE_Tail_Timer[q])
					{
						valve[q].open=0;
						valve[q].close=1;
					}
				}	
				else  VALVE_Tail_Timer[q]=180;
			}
*/
		}		
	}
#endif
}
//------------------------------------------------------------------------------
void Set_Valve_Power()
{
#if MAX_VALVE_3T_NUMBER
	if(Params[0]<MAX_VALVE_3T_NUMBER)
		valve[Params[0]].power=Params[1];
#endif
}
//------------------------------------------------------------------------------
void Set_Valve_T3max()
{
#if MAX_VALVE_3T_NUMBER
	if(Params[0]<MAX_VALVE_3T_NUMBER)
		valve[Params[0]].t3max=Params[1];
#endif
}
//------------------------------------------------------------------------------
void Set_Valve_P3()
{
#if MAX_VALVE_3T_NUMBER
	if(Params[0]<MAX_VALVE_3T_NUMBER)
		valve[Params[0]].p3=Params[1];
#endif
}
//-----------------------------------------------------------------------------------
void Mod_Show_Status_Valve()
{
#if MAX_VALVE_3T_NUMBER
	if(Params[0]<MAX_VALVE_3T_NUMBER)
	{
		__sprintf_P(outtxt,valve_str[0]);			
		__sprintf_P(outtxt,valve_str[1]);			
		ShowPowerShort(outtxt,(s16*)&valve[Params[0]].power);					
		__sprintf_P(outtxt,valve_str[2]);			
		ShowPowerShort(outtxt,(s16*)&valve[Params[0]].p3);					
		
		__sprintf_P(outtxt,valve_str[3]);			
		WordToStr(outtxt,(u16*)&valve[Params[0]].t3max,0);
		__sprintf_P(outtxt,valve_str[4]);			
		ByteToStr(outtxt,&valve[Params[0]].open,0);
		__sprintf_P(outtxt,valve_str[5]);			
		ByteToStr(outtxt,&valve[Params[0]].close,0);
	}
	else
	{
		__sprintf_P(outtxt,valve_str[7]);		
	}
#else
	__sprintf_P(outtxt,valve_str[6]);				
#endif	
}
//------------------------------------------------------------------------------
