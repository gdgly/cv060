//#ifndef __SET
//#define __SET
//-----------------------------------------------------------------------------------
#include "main.h"
//-----------------------------------------------------------------------------------
extern in_flash TCMenuItem _Set;
extern in_flash TCMenuItem _File;
extern in_flash TCMenuItem _Reset;
//-----------------------------------------------------------------------------------
void Set_Pid_ZeroB();
void Set_Pid_LowB();
void Set_Pid_Heating();
void Fancoil_Set_T();
void Set_Pid_Fan_In();
void Set_Pid_Fan_Out();
//-----------------------------------------------------------------------------------
void Fancoil_Set_VHyst();
void Fancoil_Set_VTime_1();
void Fancoil_Set_VTime_2();
void Fancoil_Set_FTime();
void Fancoil_Set_TDelta();
void Fancoil_Set_THigh();
void Fancoil_Set_TMedium();
void Fancoil_Set_TLow();
void Fancoil_Set_T();
void Fancoil_Set_Mode();
void Fancoil_Set_Channel();
void Fancoil_Set_Tin();
void Fancoil_Set_HC();
//-----------------------------------------------------------------------------------
void Set_Kotel_Temperature();
void Set_Kotel_Channel();
void Set_Kotel_Fuel();
void Set_Kotel_Mode();
void Set_Kotel_P_Temperature();
void Set_Kotel_P_Fan_On_0();
void Set_Kotel_P_Fan_On_1();
void Set_Kotel_P_Fan_Off_0();
void Set_Kotel_P_Fan_Off_1();
void Set_Kotel_P_Fan_Speed_0();
void Set_Kotel_P_Fan_Speed_1();
void Set_Kotel_P_Smoke();
void Set_Kotel_P_Shnek_Ena_0();
void Set_Kotel_P_Shnek_Ena_1();
void Set_Kotel_P_Shnek_On_0();
void Set_Kotel_P_Shnek_On_1();
void Set_Kotel_P_Shnek_Off_0();
void Set_Kotel_P_Shnek_Off_1();

void Set_Kotel_P_Fan_Speed();
void Set_Kotel_P_Fan_On();
void Set_Kotel_P_Fan_Off();
void Set_Kotel_P_Shnek_Ena();
void Set_Kotel_P_Shnek_On();
void Set_Kotel_P_Shnek_Off();

void Set_Kotel_Power();
void Set_Kotel_T3Max();
void Set_Kotel_P3();

void Set_Valve_Power();
void Set_Valve_T3max();
void Set_Valve_P3();

void Set_DO();
void Set_AO();

void Set_Param();
void Set_Net_Param();
void Set_AI_Filter(); 
void set_serial_id();
//------------------------------------------------------------------------------
#if MAX_PARAMS_BLOCK
//------------------------------------------------------------------------------
//------------------------------------
in_flash TCMenuItem _Set_NetParam_Value=
{
	"value",NULL,4,
	Set_Net_Param,		
	NULL,	
	NULL,
	NULL,
};
//------------------------------------
in_flash TCMenuItem _Set_NetParam_NUMBER=
{
	"net param number",NULL,4,
	NULL,		
	NULL,
	&_Set_NetParam_Value,		
	NULL,
};
in_flash TCMenuItem _Set_NetParam=
{
	"netparam",NULL,0,
	NULL,		
	NULL,	
	&_Set_NetParam_NUMBER,
	NULL
};
//------------------------------------
in_flash TCMenuItem _Set_Param_Value=
{
	"value",NULL,4,
	Set_Param,		
	NULL,	
	NULL,
	NULL,
};
//------------------------------------
in_flash TCMenuItem _Set_Param_NUMBER=
{
	"param number",NULL,4,
	NULL,		
	NULL,
	&_Set_Param_Value,		
	NULL,
};
in_flash TCMenuItem _Set_Param=
{
	"param",NULL,0,
	NULL,		
	NULL,	
	&_Set_Param_NUMBER,
	&_Set_NetParam
};
//------------------------------------------------------------------------------
#endif
//------------------------------------------------------------------------------
#if MAX_VALVE_3T_NUMBER
//------------------------------------------------------------------------------
in_flash TCMenuItem _Set_Valve_P3_Value=
{
	"value",NULL,4,
	Set_Valve_P3,		
	NULL,	
	NULL,
	NULL,
};
in_flash TCMenuItem _Set_Valve_P3=
{
	"p3",NULL,0,
	NULL,		
	NULL,	
	&_Set_Valve_P3_Value,	
	NULL,	
};
//------------------------------------
in_flash TCMenuItem _Set_Valve_T3Max_Value=
{
	"value",NULL,4,
	Set_Valve_T3max,		
	NULL,	
	NULL,
	NULL,
};
in_flash TCMenuItem _Set_Valve_T3Max=
{
	"t3max",NULL,0,
	NULL,		
	NULL,	
	&_Set_Valve_T3Max_Value,	
	&_Set_Valve_P3,	
};
//------------------------------------
in_flash TCMenuItem _Set_Valve_Power_Value=
{
	"value",NULL,4,
	Set_Valve_Power,		
	NULL,	
	NULL,
	NULL,
};
in_flash TCMenuItem _Set_Valve_Power=
{
	"power",NULL,0,
	NULL,		
	NULL,	
	&_Set_Valve_Power_Value,	
	&_Set_Valve_T3Max,	
};
//------------------------------------
in_flash TCMenuItem _Set_Valve_NUMBER=
{
	"valve number",NULL,4,
	NULL,		
	NULL,
	&_Set_Valve_Power,		
	NULL,
};
in_flash TCMenuItem _Set_Valve=
{
	"valve",NULL,0,
	NULL,		
	NULL,	
	&_Set_Valve_NUMBER,
#if MAX_PARAMS_BLOCK
	&_Set_Param
#else
	NULL
#endif
};
//------------------------------------------------------------------------------
#endif
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
#if MAX_KOTEL_NUMBER
//------------------------------------------------------------------------------
in_flash TCMenuItem _Set_KOT_Param_Shnek_Off_Value=
{
	"value",NULL,4,
	Set_Kotel_P_Shnek_Off,		
	NULL,	
	NULL,
	NULL,
};
in_flash TCMenuItem _Set_KOT_Param_Shnek_Off=
{
	"off",NULL,0,
	NULL,		
	NULL,	
	&_Set_KOT_Param_Shnek_Off_Value,	
	NULL,	
};
//------------------------------------
in_flash TCMenuItem _Set_KOT_Param_Shnek_On_Value=
{
	"value",NULL,4,
	Set_Kotel_P_Shnek_On,		
	NULL,	
	NULL,
	NULL,
};
in_flash TCMenuItem _Set_KOT_Param_Shnek_On=
{
	"on",NULL,0,
	NULL,		
	NULL,	
	&_Set_KOT_Param_Shnek_On_Value,	
	&_Set_KOT_Param_Shnek_Off,	
};
//------------------------------------
in_flash TCMenuItem _Set_KOT_Param_Shnek_Ena_Value=
{
	"value",NULL,4,
	Set_Kotel_P_Shnek_Ena,		
	NULL,	
	NULL,
	NULL,
};
in_flash TCMenuItem _Set_KOT_Param_Shnek_Ena=
{
	"enable",NULL,0,
	NULL,		
	NULL,	
	&_Set_KOT_Param_Shnek_Ena_Value,	
	&_Set_KOT_Param_Shnek_On,	
};
//------------------------------------
in_flash TCMenuItem _Set_KOT_Param_Shnek_Number=
{
	"number",NULL,4,
	NULL,		
	NULL,	
	&_Set_KOT_Param_Shnek_Ena,
	NULL,
};
in_flash TCMenuItem _Set_KOT_Param_Shnek=
{
	"shnek",NULL,0,
	NULL,		
	NULL,	
	&_Set_KOT_Param_Shnek_Number,	
	NULL,	
};
//------------------------------------
in_flash TCMenuItem _Set_KOT_Param_Smoke_Value=
{
	"value",NULL,4,
	Set_Kotel_P_Smoke,		
	NULL,	
	NULL,
	NULL,
};
in_flash TCMenuItem _Set_KOT_Param_Smoke=
{
	"smoke",NULL,0,
	NULL,		
	NULL,	
	&_Set_KOT_Param_Smoke_Value,	
	&_Set_KOT_Param_Shnek,	
};
//------------------------------------
in_flash TCMenuItem _Set_KOT_Param_Fan_Off_Value=
{
	"value",NULL,4,
	Set_Kotel_P_Fan_Off,		
	NULL,	
	NULL,
	NULL,
};
in_flash TCMenuItem _Set_KOT_Param_Fan_Off=
{
	"off",NULL,0,
	NULL,		
	NULL,	
	&_Set_KOT_Param_Fan_Off_Value,	
	NULL,	
};
//------------------------------------
in_flash TCMenuItem _Set_KOT_Param_Fan_On_Value=
{
	"value",NULL,4,
	Set_Kotel_P_Fan_On,		
	NULL,	
	NULL,
	NULL,
};
in_flash TCMenuItem _Set_KOT_Param_Fan_On=
{
	"on",NULL,0,
	NULL,		
	NULL,	
	&_Set_KOT_Param_Fan_On_Value,	
	&_Set_KOT_Param_Fan_Off,	
};
//------------------------------------
in_flash TCMenuItem _Set_KOT_Param_Speed_Value=
{
	"value",NULL,4,
	Set_Kotel_P_Fan_Speed,		
	NULL,	
	NULL,
	NULL,
};
in_flash TCMenuItem _Set_KOT_Param_Speed=
{
	"speed",NULL,0,
	NULL,		
	NULL,	
	&_Set_KOT_Param_Speed_Value,	
	&_Set_KOT_Param_Fan_On,	
};
//------------------------------------
in_flash TCMenuItem _Set_KOT_Param_Fan_Number=
{
	"number",NULL,4,
	NULL,		
	NULL,	
	&_Set_KOT_Param_Speed,
	NULL,
};
in_flash TCMenuItem _Set_KOT_Param_Fan=
{
	"fan",NULL,0,
	NULL,		
	NULL,	
	&_Set_KOT_Param_Fan_Number,	
	&_Set_KOT_Param_Smoke,	
};
//------------------------------------
in_flash TCMenuItem _Set_KOT_Param_Temperature_Value=
{
	"value",NULL,4,
	Set_Kotel_P_Temperature,		
	NULL,	
	NULL,
	NULL,
};
in_flash TCMenuItem _Set_KOT_Param_Temperature=
{
	"temperature",NULL,0,
	NULL,		
	NULL,	
	&_Set_KOT_Param_Temperature_Value,	
	&_Set_KOT_Param_Fan,	
};
//------------------------------------
//------------------------------------
//------------------------------------
in_flash TCMenuItem _Set_KOT_Param_Rec=
{
	"record",NULL,4,
	NULL,		
	NULL,	
	&_Set_KOT_Param_Temperature,
	NULL,
};
in_flash TCMenuItem _Set_KOT_Param=
{
	"parameter",NULL,0,
	NULL,		
	NULL,	
	&_Set_KOT_Param_Rec,	
	NULL,	
};
//------------------------------------
in_flash TCMenuItem _Set_KOT_P3_Value=
{
	"value",NULL,4,
	Set_Kotel_P3,		
	NULL,	
	NULL,
	NULL,
};
in_flash TCMenuItem _Set_KOT_P3=
{
	"p3",NULL,0,
	NULL,		
	NULL,	
	&_Set_KOT_P3_Value,	
	&_Set_KOT_Param,	
};
//------------------------------------
in_flash TCMenuItem _Set_KOT_T3Max_Value=
{
	"value",NULL,4,
	Set_Kotel_T3Max,		
	NULL,	
	NULL,
	NULL,
};
in_flash TCMenuItem _Set_KOT_T3Max=
{
	"t3max",NULL,0,
	NULL,		
	NULL,	
	&_Set_KOT_T3Max_Value,	
	&_Set_KOT_P3,	
};
//------------------------------------
in_flash TCMenuItem _Set_KOT_Power_Value=
{
	"value",NULL,4,
	Set_Kotel_Power,		
	NULL,	
	NULL,
	NULL,
};
in_flash TCMenuItem _Set_KOT_Power=
{
	"power",NULL,0,
	NULL,		
	NULL,	
	&_Set_KOT_Power_Value,	
	&_Set_KOT_T3Max,	
};
//------------------------------------
in_flash TCMenuItem _Set_KOT_Channel_Value=
{
	"value",NULL,4,
	Set_Kotel_Channel,		
	NULL,	
	NULL,
	NULL,
};
in_flash TCMenuItem _Set_KOT_Channel=
{
	"channel",NULL,0,
	NULL,		
	NULL,	
	&_Set_KOT_Channel_Value,	
	&_Set_KOT_Power,	
};
//------------------------------------
in_flash TCMenuItem _Set_KOT_Fuel_Value=
{
	"value",NULL,4,
	Set_Kotel_Fuel,		
	NULL,	
	NULL,
	NULL,
};
in_flash TCMenuItem _Set_KOT_Fuel=
{
	"fuel",NULL,0,
	NULL,		
	NULL,	
	&_Set_KOT_Fuel_Value,	
	&_Set_KOT_Channel,	
};
//------------------------------------
in_flash TCMenuItem _Set_KOT_Temperature_Value=
{
	"value",NULL,4,
	Set_Kotel_Temperature,		
	NULL,	
	NULL,
	NULL,
};
in_flash TCMenuItem _Set_KOT_Temperature=
{
	"temperature",NULL,0,
	NULL,		
	NULL,	
	&_Set_KOT_Temperature_Value,	
	&_Set_KOT_Fuel,	
};
//------------------------------------
in_flash TCMenuItem _Set_KOT_Mode_Value=
{
	"value",NULL,4,
	Set_Kotel_Mode,		
	NULL,	
	NULL,
	NULL,
};
in_flash TCMenuItem _Set_KOT_Mode=
{
	"mode",NULL,0,
	NULL,		
	NULL,	
	&_Set_KOT_Mode_Value,	
	&_Set_KOT_Temperature,	
};
//------------------------------------
in_flash TCMenuItem _Set_KOT=
{
	"kotel",NULL,0,
	NULL,		
	NULL,	
	&_Set_KOT_Mode,
#if MAX_VALVE_3T_NUMBER
	&_Set_Valve
#else
	#if MAX_PARAMS_BLOCK
		&_Set_Param
	#else
		NULL,
	#endif
#endif
};
//------------------------------------------------------------------------------
#endif
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
#if MAX_FANCOIL_NUMBER
//------------------------------------------------------------------------------
void Fancoil_Set_VHyst();
void Fancoil_Set_VTime_1();
void Fancoil_Set_VTime_2();
void Fancoil_Set_FTime();
void Fancoil_Set_TDelta();
void Fancoil_Set_THigh();
void Fancoil_Set_TMedium();
void Fancoil_Set_T();
void Fancoil_Set_Mode();
void Fancoil_Set_Channel();
//------------------------------------
in_flash TCMenuItem _Set_FAN_Hyst_Value=
{
	"value",NULL,4,
	Fancoil_Set_VHyst,		
	NULL,	
	NULL,
	NULL,
};
in_flash TCMenuItem _Set_FAN_Hyst=
{
	"hysteresis",NULL,0,
	NULL,		
	NULL,	
	&_Set_FAN_Hyst_Value,	
	NULL,	
};
//------------------------------------
in_flash TCMenuItem _Set_FAN_High_Value=
{
	"value",NULL,4,
	Fancoil_Set_THigh,		
	NULL,	
	NULL,
	NULL,
};
in_flash TCMenuItem _Set_FAN_High=
{
	"high",NULL,0,
	NULL,		
	NULL,	
	&_Set_FAN_High_Value,	
	&_Set_FAN_Hyst,	
};
//------------------------------------
in_flash TCMenuItem _Set_FAN_Med_Value=
{
	"value",NULL,4,
	Fancoil_Set_TMedium,		
	NULL,	
	NULL,
	NULL,
};
in_flash TCMenuItem _Set_FAN_Med=
{
	"medium",NULL,0,
	NULL,		
	NULL,	
	&_Set_FAN_Med_Value,	
	&_Set_FAN_High,	
};
//------------------------------------
in_flash TCMenuItem _Set_FAN_Low_Value=
{
	"value",NULL,4,
	Fancoil_Set_TLow,		
	NULL,	
	NULL,
	NULL,
};
in_flash TCMenuItem _Set_FAN_Low=
{
	"low",NULL,0,
	NULL,		
	NULL,	
	&_Set_FAN_Low_Value,	
	&_Set_FAN_Med,	
};
//------------------------------------
in_flash TCMenuItem _Set_FAN_Channel_Value=
{
	"value",NULL,4,
	Fancoil_Set_Channel,		
	NULL,	
	NULL,
	NULL,
};
in_flash TCMenuItem _Set_FAN_Channel=
{
	"channel",NULL,0,
	NULL,		
	NULL,	
	&_Set_FAN_Channel_Value,	
	&_Set_FAN_Low,	
};
//------------------------------------
in_flash TCMenuItem _Set_FAN_Mode_Value=
{
	"value",NULL,4,
	Fancoil_Set_Mode,		
	NULL,	
	NULL,
	NULL,
};
in_flash TCMenuItem _Set_FAN_Mode=
{
	"mode",NULL,0,
	NULL,		
	NULL,	
	&_Set_FAN_Mode_Value,	
	&_Set_FAN_Channel,	
};
//------------------------------------
in_flash TCMenuItem _Set_FAN_HC_Value=
{
	"value",NULL,4,
	Fancoil_Set_HC,		
	NULL,	
	NULL,
	NULL,
};
in_flash TCMenuItem _Set_FAN_HC=
{
	"hc",NULL,0,
	NULL,		
	NULL,	
	&_Set_FAN_HC_Value,	
	&_Set_FAN_Mode,	
};
//------------------------------------
in_flash TCMenuItem _Set_FAN_TIN_Value=
{
	"value",NULL,4,
	Fancoil_Set_Tin,		
	NULL,	
	NULL,
	NULL,
};
in_flash TCMenuItem _Set_FAN_TIN=
{
	"tin",NULL,0,
	NULL,		
	NULL,	
	&_Set_FAN_TIN_Value,	
	&_Set_FAN_HC,	
};
//------------------------------------
in_flash TCMenuItem _Set_FAN_Temperature_Value=
{
	"value",NULL,4,
	Fancoil_Set_T,		
	NULL,	
	NULL,
	NULL,
};
in_flash TCMenuItem _Set_FAN_Temperature=
{
	"temperature",NULL,0,
	NULL,		
	NULL,	
	&_Set_FAN_Temperature_Value,	
	&_Set_FAN_TIN,	
};
//------------------------------------
in_flash TCMenuItem _Set_FAN_NUMBER=
{
	"fancoil number",NULL,4,
	NULL,		
	NULL,
	&_Set_FAN_Temperature,		
	NULL,
};
in_flash TCMenuItem _Set_FAN=
{
	"fan",NULL,0,
	NULL,		
	NULL,	
	&_Set_FAN_NUMBER,
#if MAX_KOTEL_NUMBER
	&_Set_KOT
#else
	#if MAX_VALVE_3T_NUMBER
		&_Set_Valve
	#else
		#if MAX_PARAMS_BLOCK
			&_Set_Param
		#else
			NULL,
		#endif
	#endif
#endif
};
//------------------------------------------------------------------------------
#endif
//------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------
#if NUM_PID
//-----------------------------------------------------------------------------------
in_flash TCMenuItem _Set_PID_FAN_OUT_Value=
{
	"value",NULL,4,
	Set_Pid_Fan_Out,		
	NULL,	
	NULL,
	NULL,
};
in_flash TCMenuItem _Set_PID_FAN_OUT=
{
	"fanout",NULL,0,
	NULL,		
	NULL,	
	&_Set_PID_FAN_OUT_Value,	
	NULL,	
};
//-----------------------------------------------------------------------------------
in_flash TCMenuItem _Set_PID_FAN_IN_Value=
{
	"value",NULL,4,
	Set_Pid_Fan_In,		
	NULL,	
	NULL,
	NULL,
};
in_flash TCMenuItem _Set_PID_FAN_IN=
{
	"fanin",NULL,0,
	NULL,		
	NULL,	
	&_Set_PID_FAN_IN_Value,	
	&_Set_PID_FAN_OUT,	
};
//-----------------------------------------------------------------------------------
in_flash TCMenuItem _Set_PID_HC_Value=
{
	"value",NULL,4,
	Set_Pid_Heating,		
	NULL,	
	NULL,
	NULL,
};
in_flash TCMenuItem _Set_PID_HC=
{
	"heating",NULL,0,
	NULL,		
	NULL,	
	&_Set_PID_HC_Value,	
	&_Set_PID_FAN_IN,	
};
//-----------------------------------------------------------------------------------
in_flash TCMenuItem _Set_PID_LowB_Value=
{
	"value",NULL,4,
	Set_Pid_LowB,		
	NULL,	
	NULL,
	NULL,
};
in_flash TCMenuItem _Set_PID_LowB=
{
	"lowb",NULL,0,
	NULL,		
	NULL,	
	&_Set_PID_LowB_Value,	
	&_Set_PID_HC,	
};
//-----------------------------------------------------------------------------------
in_flash TCMenuItem _Set_PID_ZeroB_Value=
{
	"value",NULL,4,
	Set_Pid_ZeroB,		
	NULL,	
	NULL,
	NULL,
};
in_flash TCMenuItem _Set_PID_ZeroB=
{
	"zerob",NULL,0,
	NULL,		
	NULL,	
	&_Set_PID_ZeroB_Value,	
	&_Set_PID_LowB,	
};
//-----------------------------------------------------------------------------------
in_flash TCMenuItem _Set_PID_Fast_Value=
{
	"value",NULL,4,
	Set_Pid_Fast,		
	NULL,	
	NULL,
	NULL,
};
in_flash TCMenuItem _Set_PID_Fast=
{
	"fast",NULL,0,
	NULL,		
	NULL,	
	&_Set_PID_Fast_Value,	
	&_Set_PID_ZeroB,	
};
//-----------------------------------------------------------------------------------
in_flash TCMenuItem _Set_PID_Slow_Value=
{
	"value",NULL,4,
	Set_Pid_Slow,		
	NULL,	
	NULL,
	NULL,
};
in_flash TCMenuItem _Set_PID_Slow=
{
	"slow",NULL,0,
	NULL,		
	NULL,	
	&_Set_PID_Slow_Value,	
	&_Set_PID_Fast,	
};
//-----------------------------------------------------------------------------------
in_flash TCMenuItem _Set_PID_Channel_Value=
{
	"value",NULL,4,
	Set_Pid_Channel,		
	NULL,	
	NULL,
	NULL,
};
in_flash TCMenuItem _Set_PID_Channel=
{
	"channel",NULL,0,
	NULL,		
	NULL,	
	&_Set_PID_Channel_Value,	
	&_Set_PID_Slow,	
};
//-----------------------------------------------------------------------------------
in_flash TCMenuItem _Set_PID_Power_Mode_Value=
{
	"value",NULL,4,
	Set_Pid_Mode,		
	NULL,	
	NULL,
	NULL,
};
in_flash TCMenuItem _Set_PID_Power_Mode=
{
	"mode",NULL,0,
	NULL,		
	NULL,	
	&_Set_PID_Power_Mode_Value,	
	&_Set_PID_Channel,	
};
//-----------------------------------------------------------------------------------
in_flash TCMenuItem _Set_PID_Power_Max_Value=
{
	"value",NULL,4,
	Set_Pid_Power_Max,		
	NULL,	
	NULL,
	NULL,
};
in_flash TCMenuItem _Set_PID_Power_Max=
{
	"pow_max",NULL,0,
	NULL,		
	NULL,	
	&_Set_PID_Power_Max_Value,	
	&_Set_PID_Power_Mode,	
};
//-----------------------------------------------------------------------------------
in_flash TCMenuItem _Set_PID_Power_Min_Value=
{
	"value",NULL,4,
	Set_Pid_Power_Min,		
	NULL,	
	NULL,
	NULL,
};
in_flash TCMenuItem _Set_PID_Power_Min=
{
	"pow_min",NULL,0,
	NULL,		
	NULL,	
	&_Set_PID_Power_Min_Value,	
	&_Set_PID_Power_Max,	
};
//-----------------------------------------------------------------------------------
in_flash TCMenuItem _Set_PID_Power_Value=
{
	"value",NULL,4,
	Set_Pid_Power,		
	NULL,	
	NULL,
	NULL,
};
in_flash TCMenuItem _Set_PID_Power=
{
	"power",NULL,0,
	NULL,		
	NULL,	
	&_Set_PID_Power_Value,	
	&_Set_PID_Power_Min,	
};
//-----------------------------------------------------------------------------------
in_flash TCMenuItem _Set_PID_Diff_Value=
{
	"value",NULL,4,
	Set_Pid_Diff,		
	NULL,	
	NULL,
	NULL,
};
in_flash TCMenuItem _Set_PID_Diff=
{
	"differencial",NULL,0,
	NULL,		
	NULL,	
	&_Set_PID_Diff_Value,	
	&_Set_PID_Power,	
};
//------------------------------------
in_flash TCMenuItem _Set_PID_Int_Value=
{
	"value",NULL,4,
	Set_Pid_Int,		
	NULL,	
	NULL,
	NULL,
};
in_flash TCMenuItem _Set_PID_Int=
{
	"integral",NULL,0,
	NULL,		
	NULL,	
	&_Set_PID_Int_Value,	
	&_Set_PID_Diff,	
};
//------------------------------------
in_flash TCMenuItem _Set_PID_Prop_Value=
{
	"value",NULL,4,
	Set_Pid_Prop,		
	NULL,	
	NULL,
	NULL,
};
in_flash TCMenuItem _Set_PID_Prop=
{
	"proportional",NULL,0,
	NULL,		
	NULL,	
	&_Set_PID_Prop_Value,	
	&_Set_PID_Int,	
};
//------------------------------------
in_flash TCMenuItem _Set_PID_Temperature_Value=
{
	"value",NULL,4,
	Set_Pid_Temperature,		
	NULL,	
	NULL,
	NULL,
};
in_flash TCMenuItem _Set_PID_Temperature=
{
	"temperature",NULL,0,
	NULL,		
	NULL,	
	&_Set_PID_Temperature_Value,	
	&_Set_PID_Prop,	
};
//------------------------------------
in_flash TCMenuItem _Set_PID_NUMBER=
{
	"pid number",NULL,4,
	NULL,		
	NULL,
	&_Set_PID_Temperature,		
	NULL,
};
in_flash TCMenuItem _Set_PID=
{
	"pid",NULL,0,
	NULL,		
	NULL,	
	&_Set_PID_NUMBER,
#if MAX_FANCOIL_NUMBER
	&_Set_FAN,
#else
	#if MAX_KOTEL_NUMBER
		&_Set_KOT,
	#else
		#if MAX_VALVE_3T_NUMBER
			&_Set_Valve,
		#else
			#if MAX_PARAMS_BLOCK
				&_Set_Param
			#else
				NULL,
			#endif
		#endif
	#endif
#endif
};
//------------------------------------------------------------------------------
#endif
//------------------------------------------------------------------------------
//------------------------------------
in_flash TCMenuItem _Set_Block_Group=
{
	"blocks",NULL,0,
	NULL,		
	NULL,	
#if NUM_PID
	&_Set_PID,
#else
	#if MAX_FANCOIL_NUMBER
		&_Set_FAN,
	#else
		#if MAX_KOTEL_NUMBER
			&_Set_KOT
		#else
			#if MAX_VALVE_3T_NUMBER
				&_Set_Valve
			#else
				#if MAX_PARAMS_BLOCK
					&_Set_Param
				#else
					NULL,
				#endif
			#endif
		#endif
	#endif
#endif
	NULL,	
};
//------------------------------------------------------------------------------
in_flash TCMenuItem _Set_ID_NUMBER_3=
{
	"IP[3]",NULL,4,
	Set_IP,		
	NULL,
	NULL,		
	NULL,
};
in_flash TCMenuItem _Set_ID_NUMBER_2=
{
	"IP[2]",NULL,4,
	NULL,		
	NULL,
	&_Set_ID_NUMBER_3,
	NULL,		
};
in_flash TCMenuItem _Set_ID_NUMBER_1=
{
	"IP[1]",NULL,4,
	NULL,		
	NULL,
	&_Set_ID_NUMBER_2,
	NULL,		
};
in_flash TCMenuItem _Set_ID_NUMBER_0=
{
	"IP[0]",NULL,4,
	NULL,		
	NULL,
	&_Set_ID_NUMBER_1,
	NULL,		
};
in_flash TCMenuItem _Set_ID=
{
	"addr",NULL,0,
	NULL,		
	NULL,	
	&_Set_ID_NUMBER_0,	
	NULL,
};
//------------------------------------------------------------------------------
in_flash TCMenuItem _Set_MASK_NUMBER_3=
{
	"MASK[3]",NULL,4,
	Set_Mask,		
	NULL,
	NULL,		
	NULL,
};
in_flash TCMenuItem _Set_MASK_NUMBER_2=
{
	"MASK[2]",NULL,4,
	NULL,		
	NULL,
	&_Set_MASK_NUMBER_3,
	NULL,		
};
in_flash TCMenuItem _Set_MASK_NUMBER_1=
{
	"MASK[1]",NULL,4,
	NULL,		
	NULL,
	&_Set_MASK_NUMBER_2,
	NULL,		
};
in_flash TCMenuItem _Set_MASK_NUMBER_0=
{
	"MASK[0]",NULL,4,
	NULL,		
	NULL,
	&_Set_MASK_NUMBER_1,
	NULL,		
};
in_flash TCMenuItem _Set_MASK=
{
	"mask",NULL,0,
	NULL,		
	NULL,	
	&_Set_MASK_NUMBER_0,	
	&_Set_ID,
};
//------------------------------------------------------------------------------
in_flash TCMenuItem _Set_GW_NUMBER_3=
{
	"GW[3]",NULL,4,
	Set_GW,		
	NULL,
	NULL,		
	NULL,
};
in_flash TCMenuItem _Set_GW_NUMBER_2=
{
	"GW[2]",NULL,4,
	NULL,		
	NULL,
	&_Set_GW_NUMBER_3,
	NULL,		
};
in_flash TCMenuItem _Set_GW_NUMBER_1=
{
	"GW[1]",NULL,4,
	NULL,		
	NULL,
	&_Set_GW_NUMBER_2,
	NULL,		
};
in_flash TCMenuItem _Set_GW_NUMBER_0=
{
	"GW[0]",NULL,4,
	NULL,		
	NULL,
	&_Set_GW_NUMBER_1,
	NULL,		
};
in_flash TCMenuItem _Set_GW=
{
	"gateway",NULL,0,
	NULL,		
	NULL,	
	&_Set_GW_NUMBER_0,	
	&_Set_MASK,
};
//------------------------------------
in_flash TCMenuItem _Set_IP_Group=
{
	"ip",NULL,0,
	NULL,		
	NULL,	
	&_Set_GW,	
	&_Set_Block_Group,
};
//------------------------------------
in_flash TCMenuItem _Set_Ser_ID=
{
	"ser_id",NULL,4,
	set_serial_id,		
	NULL,
	NULL,
	NULL,		
};
in_flash TCMenuItem _Set_Ser=
{
	"id",NULL,0,
	NULL,		
	NULL,	
	&_Set_Ser_ID,	
	NULL,
};
//------------------------------------
in_flash TCMenuItem _Set_Serial_Group=
{
	"serial",NULL,0,
	NULL,		
	NULL,	
	&_Set_Ser,	
	&_Set_IP_Group,
};
//------------------------------------
in_flash TCMenuItem _Set_Password_Admin_Parameter=
{
	"admin password",NULL,4,
	Set_Password_Admin,		
	NULL,	
	NULL,
	NULL,
};
in_flash TCMenuItem _Set_Password_Admin=
{
	"admin",NULL,0,
	NULL,		
	NULL,	
	&_Set_Password_Admin_Parameter,
	NULL,
};
in_flash TCMenuItem _Set_Password_User_Parameter=
{
	"user password",NULL,4,
	Set_Password_User,		
	NULL,	
	NULL,
	NULL,
};
in_flash TCMenuItem _Set_Password_User=
{
	"user",NULL,0,
	NULL,		
	NULL,	
	&_Set_Password_User_Parameter,
	&_Set_Password_Admin,
};
in_flash TCMenuItem _Set_Password_Off=
{
	"off",NULL,0,
	Set_Password_Off,		
	NULL,	
	NULL,
	&_Set_Password_User,
};
in_flash TCMenuItem _Set_Password_On=
{
	"on",NULL,0,
	Set_Password_On,		
	NULL,	
	NULL,
	&_Set_Password_Off,
};
in_flash TCMenuItem _Set_Password=
{
	"password",NULL,0,
	NULL,		
	NULL,	
	&_Set_Password_On,
    &_Set_Serial_Group,
};
//-----------------------------------------------------------------------------------
in_flash TCMenuItem _Set_Point_Temperature=
{
	"temperature",NULL,4,
	Set_Point,		
	NULL,	
	NULL,
	NULL,
};
in_flash TCMenuItem _Set_Point_Number=
{
	"number",NULL,4,
	NULL,		
	NULL,	
	&_Set_Point_Temperature,
	NULL,
};
in_flash TCMenuItem _Set_Point=
{
	"point",NULL,0,
	NULL,		
	NULL,	
	&_Set_Point_Number,
	&_Set_Password,
};
//-----------------------------------------------------------------------------------
in_flash TCMenuItem _Set_Date_Year=
{
	"year",NULL,4,
	Set_Date,		
	NULL,	
	NULL,
	NULL,
};
in_flash TCMenuItem _Set_Date_Month=
{
	"month",NULL,4,
	NULL,		
	NULL,	
	&_Set_Date_Year,
	NULL,
};
in_flash TCMenuItem _Set_Date_Date=
{
	"date",NULL,4,
	NULL,		
	NULL,	
	&_Set_Date_Month,
	NULL,	
};
in_flash TCMenuItem _Set_Date=
{
	"date",NULL,0,
	NULL,		
	NULL,	
	&_Set_Date_Date,
	&_Set_Point,	
};

//-----------------------------------------------------------------------------------
in_flash TCMenuItem _Set_Time_Second=
{
	"second",NULL,4,
	Set_Time,		
	NULL,	
	NULL,
	NULL,
};
in_flash TCMenuItem _Set_Time_Minute=
{
	"minute",NULL,4,
	NULL,		
	NULL,	
	&_Set_Time_Second,
	NULL,
};
in_flash TCMenuItem _Set_Time_Hour=
{
	"hour",NULL,4,
	NULL,		
	NULL,	
	&_Set_Time_Minute,
	NULL,	
};
in_flash TCMenuItem _Set_Time=
{
	"time",NULL,0,
	NULL,		
	NULL,	
	&_Set_Time_Hour,
	&_Set_Date,
};
//-----------------------------------------------------------------------------------
in_flash TCMenuItem _Set_AI_Filter_Value=
{
	"filter value",NULL,4,
	Set_AI_Filter,		
	NULL,	
	NULL,
	NULL,
};
in_flash TCMenuItem _Set_AI_Filter_PIN=
{
	"ai number",NULL,4,
	NULL,		
	NULL,	
	&_Set_AI_Filter_Value,
	NULL,
};
in_flash TCMenuItem _Set_AI_Filter=
{
	"filter",NULL,0,
	NULL,		
	NULL,	
	&_Set_AI_Filter_PIN,
	NULL,
};
//------------------
in_flash TCMenuItem _Set_AI_DC_IN_PIN=
{
	"ai number",NULL,4,
	Set_AI_10V,		
	NULL,	
	NULL,
	NULL,
};
in_flash TCMenuItem _Set_AI_DC_IN=
{
	"dc_in",NULL,0,
	NULL,		
	NULL,	
	&_Set_AI_DC_IN_PIN,
	&_Set_AI_Filter,
};
in_flash TCMenuItem _Set_AI=
{
	"ai",NULL,0,
	NULL,		
	NULL,	
	&_Set_AI_DC_IN,
	NULL,
};
//---------------------------------------
in_flash TCMenuItem _Set_AO_VALUE=
{
	"value",NULL,4,
	Set_AO,		
	NULL,	
	NULL,
	NULL,
};
in_flash TCMenuItem _Set_AO_NUM=
{
	"channel",NULL,4,
	NULL,		
	NULL,	
	&_Set_AO_VALUE,
	NULL,
};
in_flash TCMenuItem _Set_AO=
{
	"ao",NULL,0,
	NULL,		
	NULL,	
	&_Set_AO_NUM,
	&_Set_AI,
};
//---------------------------------------
in_flash TCMenuItem _Set_DO_VALUE=
{
	"value",NULL,4,
	Set_DO,		
	NULL,	
	NULL,
	NULL,
};
in_flash TCMenuItem _Set_DO_BIT=
{
	"bit",NULL,4,
	NULL,		
	NULL,	
	&_Set_DO_VALUE,
	NULL,
};
in_flash TCMenuItem _Set_DO=
{
	"do",NULL,0,
	NULL,		
	NULL,	
	&_Set_DO_BIT,
	&_Set_AO,
};
//-------------------- Set -------------------------------
in_flash TCMenuItem _Set_IO_Group=
{
	"io",NULL,0,
	NULL,		
	NULL,	
	&_Set_DO,
	&_Set_Time,
};
//-------------------- Set -------------------------------
in_flash TCMenuItem _Set=
{
	"set",NULL,0,
	NULL,		
	NULL,	
	&_Set_IO_Group,
#if USE_AT45_FS			
	&_File,
#else
	&_Reset,
#endif
};
//-----------------------------------------------------------------------------------
//#endif
