#ifndef __SET
#define __SET
//-----------------------------------------------------------------------------------
#include "main.h"
//-----------------------------------------------------------------------------------
extern in_flash TCMenuItem _Set;
extern in_flash TCMenuItem _File;
extern in_flash TCMenuItem _Reset;
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
//------------------------------------
in_flash TCMenuItem _Set_IP_Group=
{
	"ip",NULL,0,
	NULL,		
	NULL,	
	&_Set_ID,	
	NULL,
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
	&_Set_IP_Group,	
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
//-------------------- Set -------------------------------
in_flash TCMenuItem _Set=
{
	"set",NULL,0,
	NULL,		
	NULL,	
	&_Set_Time,
#if USE_AT45_FS			
	&_File,
#else
	&_Reset,
#endif
};
//-----------------------------------------------------------------------------------
#endif
