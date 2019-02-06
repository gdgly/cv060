//#ifndef __SERVICE
//#define __SERVICE
//-----------------------------------------------------------------------------------
#include "main.h"
//-----------------------------------------------------------------------------------
void Mod_Show_FAN();
void Mod_Show_Season();
void Mod_Show_Kotel();
void Mod_Show_Kotel_Params();
void Mod_Show_Block();
void Mod_Show_Param();
void Mod_Show_Status_Valve();
void Mod_Show_Status_IO();
void File_Download();
void FS_File_Download();
void Mod_Store_Full_Parameters();
void Mod_Show_Timers();
void Mod_Show_Registers();
void Mod_Show_Net_Param();
//-----------------------------------------------------------------------------------
extern in_flash TCMenuItem _Set;
extern in_flash TCMenuItem _File;
extern in_flash TCMenuItem _Reset;
//-----------------------------------------------------------------------------------
in_flash TCMenuItem _Echo_Off=
{
	"off",NULL,0,
	Echo_Off,	
	&_Root,	
	NULL,
	NULL,
};
in_flash TCMenuItem _Echo_On=
{
	"on",NULL,0,
	Echo_On,	
	&_Root,	
	NULL,
	&_Echo_Off,
};
in_flash TCMenuItem _Echo=
{
	"echo",NULL,0,
	NULL,	
	&_Root,	
	&_Echo_On,
	NULL,
};
//-----------------------------------------------------------------------------------
in_flash TCMenuItem _Init=
{
	"init",NULL,0,
	Params_Init,	
	&_Root,	
	NULL,
	&_Echo,
};
//-----------------------------------------------------------------------------------
in_flash TCMenuItem _Program_Stop=
{
	"stop",NULL,0,
	Intr_Program_Stop,	
	&_Root,	
	NULL,
	NULL,
};
in_flash TCMenuItem _Program_Start=
{
	"start",NULL,0,
	Intr_Program_Start,	
	&_Root,	
	NULL,
	&_Program_Stop,
};
in_flash TCMenuItem _Program=
{
	"program",NULL,0,
	NULL,	
	&_Root,	
	&_Program_Start,
	&_Init,
};
//*****************************************************************************
in_flash TCMenuItem _Download_File_Num=
{
	"name",NULL,5,
	FS_File_Download,	
	&_Root,	
	NULL,
	NULL,
};
in_flash TCMenuItem _Download_File=
{
	"file",NULL,0,
	NULL,	
	&_Root,	
	&_Download_File_Num,
	NULL,
};
in_flash TCMenuItem _Download=
{
	"download",NULL,0,
	NULL,	
	&_Root,	
	&_Download_File,
	&_Program,
};
//-----------------------------------------------------------------------------------
in_flash TCMenuItem _Config=
{
	"config",NULL,0,
	fram_init,	
	&_Root,	
	NULL,
	&_Download,
};

//-----------------------------------------------------------------------------------
#if MAX_KOTEL_NUMBER
//-----------------------------------------------------------------------------------
in_flash TCMenuItem _Show_KOT_Params_Number=
{
	"number",NULL,4,
	Mod_Show_Kotel_Params,	
	&_Root,	
	NULL,
	NULL,
};
in_flash TCMenuItem _Show_KOT_Params=
{
	"parameters",NULL,0,
	NULL,	
	&_Root,	
	&_Show_KOT_Params_Number,
	NULL,
};
//-------------------------------------
in_flash TCMenuItem _Show_KOT_Stat=
{
	"status",NULL,0,
	Mod_Show_Kotel,	
	&_Root,	
	NULL,
	&_Show_KOT_Params,
};
//-------------------------------------
in_flash TCMenuItem _Show_KOT=
{
	"kotel",NULL,0,
	NULL,	
	&_Root,	
	&_Show_KOT_Stat,
	NULL,
};
//-------------------------------------
#endif
//-------------------------------------
in_flash TCMenuItem _Show_Season=
{
	"season",NULL,0,
	Mod_Show_Season,	
	&_Root,	
	NULL,
#if MAX_KOTEL_NUMBER
	&_Show_KOT,
#else
	NULL,
#endif
};
//-------------------------------------
in_flash TCMenuItem _Show_Valve_Number=
{
	"number",NULL,4,
	Mod_Show_Status_Valve,	
	&_Root,	
	NULL,
	NULL,
};
in_flash TCMenuItem _Show_Valve=
{
	"valve",NULL,0,
	NULL,	
	&_Root,	
	&_Show_Valve_Number,
	&_Show_Season,
};
//-------------------------------------
in_flash TCMenuItem _Show_FAN_Number=
{
	"number",NULL,4,
	Mod_Show_FAN,	
	&_Root,	
	NULL,
	NULL,
};
in_flash TCMenuItem _Show_FAN=
{
	"fan",NULL,0,
	NULL,	
	&_Root,	
	&_Show_FAN_Number,
	&_Show_Valve,
};
//-------------------------------------
in_flash TCMenuItem _Show_Prog=
{
	"program",NULL,0,
	Mod_Show_Status_Prog,	
	&_Root,	
	NULL,
	&_Show_FAN,
};
//-------------------------------------
in_flash TCMenuItem _Show_Errors=
{
	"errors",NULL,0,
	Mod_Show_Errors,	
	&_Root,	
	NULL,
	&_Show_Prog,
};
//-------------------------------------
in_flash TCMenuItem _Show_PID_Number=
{
	"number",NULL,4,
	Mod_Show_PID,	
	&_Root,	
	NULL,
	NULL,
};
in_flash TCMenuItem _Show_PID=
{
	"pid",NULL,0,
	NULL,	
	&_Root,	
	&_Show_PID_Number,
	&_Show_Errors,
};
//-------------------------------------
in_flash TCMenuItem _Show_Block=
{
	"block",NULL,0,
	Mod_Show_Block,	
	&_Root,	
	NULL,
	&_Show_PID,
};

//-------------------------------------
in_flash TCMenuItem _Show_IO=
{
	"io",NULL,0,
	Mod_Show_Status_IO,	
	&_Root,	
	NULL,
	&_Show_Block,
};
//-------------------------------------
in_flash TCMenuItem _Show_IP=
{
	"ip",NULL,0,
	id_show,	
	&_Root,	
	NULL,
	&_Show_IO,
};
//-------------------------------------
in_flash TCMenuItem _Show_Net_Params=
{
	"netparams",NULL,0,
	Mod_Show_Net_Param,	
	&_Root,	
	NULL,
	&_Show_IP,
};
//-------------------------------------
in_flash TCMenuItem _Show_Params=
{
	"params",NULL,0,
	Mod_Show_Param,	
	&_Root,	
	NULL,
	&_Show_Net_Params,
};
//-------------------------------------
in_flash TCMenuItem _Show_Timers=
{
	"timers",NULL,0,
	Mod_Show_Timers,	
	&_Root,	
	NULL,
	&_Show_Params,
};
//-------------------------------------
in_flash TCMenuItem _Show_Registers=
{
	"registers",NULL,0,
	Mod_Show_Registers,	
	&_Root,	
	NULL,
	&_Show_Timers,
};
//-------------------------------------
in_flash TCMenuItem _Show_Status=
{
	"status",NULL,0,
	Mod_Show_Status,	
	&_Root,	
	NULL,
	&_Show_Registers,
};
//-------------------------------------
in_flash TCMenuItem _Show=
{
	"show",NULL,0,
	NULL,	
	&_Root,	
	&_Show_Status,
	&_Config,
};
//-----------------------------------------------------------------------------------
in_flash TCMenuItem _Console_Toggle=
{
	"toggle",NULL,0,
	Mod_Console_Toggle,	
	&_Root,	
	NULL,
	&_Show,
};
//-----------------------------------------------------------------------------------
in_flash TCMenuItem _Test=
{
	"test",NULL,0,
	Mod_Test,	
	&_Root,	
	NULL,
	&_Console_Toggle,
};
//-----------------------------------------------------------------------------------
in_flash TCMenuItem _Store_Full=
{
	"full",NULL,0,
	Mod_Store_Full_Parameters,
	&_Root,	
	NULL,
	NULL,
};
//-----------------------------------------------------------------------------------
in_flash TCMenuItem _Store_Parameters=
{
	"parameters",NULL,0,
	Mod_Store_Parameters,
	&_Root,	
	NULL,
	&_Store_Full,
};
//-------------------------
in_flash TCMenuItem _Store=
{
	"store",NULL,0,
	NULL,		
	&_Root,	
	&_Store_Parameters,
	&_Test,
};
//-----------------------------------------------------------------------------------
in_flash TCMenuItem _Reset=
{
	"reset",NULL,0,
	reset,		
	&_Root,	
	NULL,
	&_Store,
};
//-----------------------------------------------------------------------------------
//#endif
