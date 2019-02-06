#ifndef __SET
#define __SET
//-----------------------------------------------------------------------------------
#include "..\main.h"
#include "MenuItems_SERVICE.h"
//-----------------------------------------------------------------------------------
extern TCMenuItem _Set;
void Set_Pid_ZeroB();
void Set_Pid_LowB();
//-----------------------------------------------------------------------------------
TCMenuItem _Set_ID_NUMBER=
{
	&Slovar[10][0],NULL,4,
	Set_ID,		
	NULL,
	NULL,		
	NULL,
};
TCMenuItem _Set_ID=
{
	&Slovar[57][0],NULL,0,
	NULL,		
	NULL,	
	&_Set_ID_NUMBER,
	NULL,
};
//-----------------------------------------------------------------------------------
TCMenuItem _Set_PID_LowB_Value=
{
	&Slovar[10][0],NULL,4,
	Set_Pid_LowB,		
	NULL,	
	NULL,
	NULL,
};
TCMenuItem _Set_PID_LowB=
{
	&Slovar[59][0],NULL,0,
	NULL,		
	NULL,	
	&_Set_PID_LowB_Value,	
	NULL,	
};
//-----------------------------------------------------------------------------------
TCMenuItem _Set_PID_ZeroB_Value=
{
	&Slovar[10][0],NULL,4,
	Set_Pid_ZeroB,		
	NULL,	
	NULL,
	NULL,
};
TCMenuItem _Set_PID_ZeroB=
{
	&Slovar[58][0],NULL,0,
	NULL,		
	NULL,	
	&_Set_PID_ZeroB_Value,	
	&_Set_PID_LowB,	
};
//-----------------------------------------------------------------------------------
TCMenuItem _Set_PID_Fast_Value=
{
	&Slovar[10][0],NULL,4,
	Set_Pid_Fast,		
	NULL,	
	NULL,
	NULL,
};
TCMenuItem _Set_PID_Fast=
{
	&Slovar[56][0],NULL,0,
	NULL,		
	NULL,	
	&_Set_PID_Fast_Value,	
	&_Set_PID_ZeroB,	
};
//-----------------------------------------------------------------------------------
TCMenuItem _Set_PID_Slow_Value=
{
	&Slovar[10][0],NULL,4,
	Set_Pid_Slow,		
	NULL,	
	NULL,
	NULL,
};
TCMenuItem _Set_PID_Slow=
{
	&Slovar[55][0],NULL,0,
	NULL,		
	NULL,	
	&_Set_PID_Slow_Value,	
	&_Set_PID_Fast,	
};
//-----------------------------------------------------------------------------------
TCMenuItem _Set_PID_Channel_Value=
{
	&Slovar[10][0],NULL,4,
	Set_Pid_Channel,		
	NULL,	
	NULL,
	NULL,
};
TCMenuItem _Set_PID_Channel=
{
	&Slovar[42][0],NULL,0,
	NULL,		
	NULL,	
	&_Set_PID_Channel_Value,	
	&_Set_PID_Slow,	
};
//-----------------------------------------------------------------------------------
TCMenuItem _Set_PID_Power_Mode_Value=
{
	&Slovar[10][0],NULL,4,
	Set_Pid_Mode,		
	NULL,	
	NULL,
	NULL,
};
TCMenuItem _Set_PID_Power_Mode=
{
	&Slovar[48][0],NULL,0,
	NULL,		
	NULL,	
	&_Set_PID_Power_Mode_Value,	
	&_Set_PID_Channel,	
};
//-----------------------------------------------------------------------------------
TCMenuItem _Set_PID_Power_Min_Value=
{
	&Slovar[10][0],NULL,4,
	Set_Pid_Power_Min,		
	NULL,	
	NULL,
	NULL,
};
TCMenuItem _Set_PID_Power_Min=
{
	&Slovar[47][0],NULL,0,
	NULL,		
	NULL,	
	&_Set_PID_Power_Min_Value,	
	&_Set_PID_Power_Mode,	
};
//-----------------------------------------------------------------------------------
TCMenuItem _Set_PID_Power_Value=
{
	&Slovar[10][0],NULL,4,
	Set_Pid_Power,		
	NULL,	
	NULL,
	NULL,
};
TCMenuItem _Set_PID_Power=
{
	&Slovar[46][0],NULL,0,
	NULL,		
	NULL,	
	&_Set_PID_Power_Value,	
	&_Set_PID_Power_Min,	
};
//-----------------------------------------------------------------------------------
TCMenuItem _Set_PID_Diff_Value=
{
	&Slovar[10][0],NULL,4,
	Set_Pid_Diff,		
	NULL,	
	NULL,
	NULL,
};
TCMenuItem _Set_PID_Diff=
{
	&Slovar[45][0],NULL,0,
	NULL,		
	NULL,	
	&_Set_PID_Diff_Value,	
	&_Set_PID_Power,	
};
//------------------------------------
TCMenuItem _Set_PID_Int_Value=
{
	&Slovar[10][0],NULL,4,
	Set_Pid_Int,		
	NULL,	
	NULL,
	NULL,
};
TCMenuItem _Set_PID_Int=
{
	&Slovar[44][0],NULL,0,
	NULL,		
	NULL,	
	&_Set_PID_Int_Value,	
	&_Set_PID_Diff,	
};
//------------------------------------
TCMenuItem _Set_PID_Prop_Value=
{
	&Slovar[10][0],NULL,4,
	Set_Pid_Prop,		
	NULL,	
	NULL,
	NULL,
};
TCMenuItem _Set_PID_Prop=
{
	&Slovar[43][0],NULL,0,
	NULL,		
	NULL,	
	&_Set_PID_Prop_Value,	
	&_Set_PID_Int,	
};
//------------------------------------
TCMenuItem _Set_PID_Temperature_Value=
{
	&Slovar[10][0],NULL,4,
	Set_Pid_Temperature,		
	NULL,	
	NULL,
	NULL,
};
TCMenuItem _Set_PID_Temperature=
{
	&Slovar[37][0],NULL,0,
	NULL,		
	NULL,	
	&_Set_PID_Temperature_Value,	
	&_Set_PID_Prop,	
};
//------------------------------------
TCMenuItem _Set_PID_NUMBER=
{
	&Slovar[10][0],NULL,4,
	NULL,		
	NULL,
	&_Set_PID_Temperature,		
	NULL,
};
TCMenuItem _Set_PID=
{
	&Slovar[38][0],NULL,0,
	NULL,		
	NULL,	
	&_Set_PID_NUMBER,
	&_Set_ID,
};
//------------------------------------
TCMenuItem _Set_Password_Admin_Parameter=
{
	&Slovar[4][0],NULL,4,
	Set_Password_Admin,		
	NULL,	
	NULL,
	NULL,
};
TCMenuItem _Set_Password_Admin=
{
	&Slovar[53][0],NULL,0,
	NULL,		
	NULL,	
	&_Set_Password_Admin_Parameter,
	NULL,
};
TCMenuItem _Set_Password_User_Parameter=
{
	&Slovar[4][0],NULL,4,
	Set_Password_User,		
	NULL,	
	NULL,
	NULL,
};
TCMenuItem _Set_Password_User=
{
	&Slovar[52][0],NULL,0,
	NULL,		
	NULL,	
	&_Set_Password_User_Parameter,
	&_Set_Password_Admin,
};
TCMenuItem _Set_Password_Off=
{
	&Slovar[23][0],NULL,0,
	Set_Password_Off,		
	NULL,	
	NULL,
	&_Set_Password_User,
};
TCMenuItem _Set_Password_On=
{
	&Slovar[22][0],NULL,0,
	Set_Password_On,		
	NULL,	
	NULL,
	&_Set_Password_Off,
};
TCMenuItem _Set_Password=
{
	&Slovar[51][0],NULL,0,
	NULL,		
	NULL,	
	&_Set_Password_On,
	&_Set_PID,
};
//-----------------------------------------------------------------------------------
TCMenuItem _Set_AI_10V_Value=
{
	&Slovar[42][0],NULL,4,
	Set_AI_10V,		
	NULL,	
	NULL,
	NULL,
};
TCMenuItem _Set_AI_10V=
{
	&Slovar[41][0],NULL,0,
	NULL,		
	NULL,	
	&_Set_AI_10V_Value,
	&_Set_Password,
};
//-----------------------------------------------------------------------------------
TCMenuItem _Set_Temperature_Value=
{
	&Slovar[4][0],NULL,4,
	Set_Desired_Temperature,		
	NULL,	
	NULL,
	NULL,
};
TCMenuItem _Set_Temperature=
{
	&Slovar[37][0],NULL,0,
	NULL,		
	NULL,	
	&_Set_Temperature_Value,
	&_Set_AI_10V,
};
//-----------------------------------------------------------------------------------
TCMenuItem _Set_Point_Temperature=
{
	&Slovar[4][0],NULL,4,
	Set_Point,		
	NULL,	
	NULL,
	NULL,
};
TCMenuItem _Set_Point_Number=
{
	&Slovar[4][0],NULL,4,
	NULL,		
	NULL,	
	&_Set_Point_Temperature,
	NULL,
};
TCMenuItem _Set_Point=
{
	&Slovar[36][0],NULL,0,
	NULL,		
	NULL,	
	&_Set_Point_Number,
	&_Set_Temperature,
};
//-----------------------------------------------------------------------------------
TCMenuItem _Set_Date_Year=
{
	&Slovar[23][0],NULL,4,
	Set_Date,		
	NULL,	
	NULL,
	NULL,
};
TCMenuItem _Set_Date_Month=
{
	&Slovar[22][0],NULL,4,
	NULL,		
	NULL,	
	&_Set_Date_Year,
	NULL,
};
TCMenuItem _Set_Date_Date=
{
	&Slovar[4][0],NULL,4,
	NULL,		
	NULL,	
	&_Set_Date_Month,
	NULL,	
};
TCMenuItem _Set_Date_Day=
{
	&Slovar[4][0],NULL,4,
	NULL,		
	NULL,	
	&_Set_Date_Date,
	NULL,	
};
TCMenuItem _Set_Date=
{
	&Slovar[29][0],NULL,0,
	NULL,		
	NULL,	
	&_Set_Date_Day,
	&_Set_Point,	
};
//-----------------------------------------------------------------------------------
TCMenuItem _Set_Time_Second=
{
	&Slovar[23][0],NULL,4,
	Set_Time,		
	NULL,	
	NULL,
	NULL,
};
TCMenuItem _Set_Time_Minute=
{
	&Slovar[22][0],NULL,4,
	NULL,		
	NULL,	
	&_Set_Time_Second,
	NULL,
};
TCMenuItem _Set_Time_Hour=
{
	&Slovar[4][0],NULL,4,
	NULL,		
	NULL,	
	&_Set_Time_Minute,
	NULL,	
};
TCMenuItem _Set_Time=
{
	&Slovar[30][0],NULL,0,
	NULL,		
	NULL,	
	&_Set_Time_Hour,
	&_Set_Date,
};
//-------------------- Set -------------------------------
TCMenuItem _Set=
{
	&Slovar[0][0],NULL,0,
	NULL,		
	NULL,	
	&_Set_Time,
	&_Reset,
};
//-----------------------------------------------------------------------------------
#endif
