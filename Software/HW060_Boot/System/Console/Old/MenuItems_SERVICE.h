#ifndef __SERVICE
#define __SERVICE
//-----------------------------------------------------------------------------------
#include "..\main.h"
//-----------------------------------------------------------------------------------
extern TCMenuItem _Set;
//-----------------------------------------------------------------------------------
TCMenuItem _Init=
{
	&Slovar[39][0],NULL,0,
	Params_Init,	
	&_Root,	
	NULL,
	NULL,
};
//-----------------------------------------------------------------------------------
TCMenuItem _Program_Stop=
{
	&Slovar[35][0],NULL,0,
	Intr_Program_Stop,	
	&_Root,	
	NULL,
	NULL,
};
TCMenuItem _Program_Start=
{
	&Slovar[34][0],NULL,0,
	Intr_Program_Start,	
	&_Root,	
	NULL,
	&_Program_Stop,
};
TCMenuItem _Program=
{
	&Slovar[33][0],NULL,0,
	NULL,	
	&_Root,	
	&_Program_Start,
	&_Init,
};
//-----------------------------------------------------------------------------------
TCMenuItem _Download_Program=
{
	&Slovar[33][0],NULL,0,
	Prog_Download,	
	&_Root,	
	NULL,
	NULL,
};
TCMenuItem _Download=
{
	&Slovar[32][0],NULL,0,
	NULL,	
	&_Root,	
//	&_Download_Program,
	NULL,	
	&_Program,
};
//-----------------------------------------------------------------------------------
TCMenuItem _Config=
{
	&Slovar[31][0],NULL,0,
	fram_init,	
	&_Root,	
	NULL,
	&_Download,
};
//-----------------------------------------------------------------------------------
TCMenuItem _Show_Prog=
{
	&Slovar[54][0],NULL,0,
	Mod_Show_Status_Prog,	
	&_Root,	
	NULL,
	NULL,
};
TCMenuItem _Show_Errors=
{
	&Slovar[40][0],NULL,0,
	Mod_Show_Errors,	
	&_Root,	
	NULL,
	&_Show_Prog,
};
TCMenuItem _Show_PID_Number=
{
	&Slovar[38][0],NULL,4,
	Mod_Show_PID,	
	&_Root,	
	NULL,
	NULL,
};
TCMenuItem _Show_PID=
{
	&Slovar[38][0],NULL,0,
	NULL,	
	&_Root,	
	&_Show_PID_Number,
	&_Show_Errors,
};

TCMenuItem _Show_Status=
{
	&Slovar[13][0],NULL,0,
	Mod_Show_Status,	
	&_Root,	
	NULL,
	&_Show_PID,
};
TCMenuItem _Show=
{
	&Slovar[12][0],NULL,0,
	NULL,	
	&_Root,	
	&_Show_Status,
	&_Config,
};
//-----------------------------------------------------------------------------------
TCMenuItem _Console_Toggle=
{
	&Slovar[28][0],NULL,0,
	Mod_Console_Toggle,	
	&_Root,	
	NULL,
	&_Show,
};
//-----------------------------------------------------------------------------------
TCMenuItem _Test=
{
	&Slovar[11][0],NULL,0,
	Mod_Test,	
	&_Root,	
	NULL,
	&_Console_Toggle,
};
//-----------------------------------------------------------------------------------
TCMenuItem _Store_Parameters=
{
	&Slovar[4][0],NULL,0,
	Mod_Store_Parameters,
	&_Root,	
	NULL,
	NULL,
};
//-------------------------
TCMenuItem _Store=
{
	&Slovar[2][0],NULL,0,
	NULL,		
	&_Root,	
	&_Store_Parameters,
	&_Test,
};
//-----------------------------------------------------------------------------------
TCMenuItem _Reset=
{
	&Slovar[7][0],NULL,0,
	reset,		
	&_Root,	
	NULL,
	&_Store,
};
//-----------------------------------------------------------------------------------
#endif
