#ifndef __SERVICE
#define __SERVICE
//-----------------------------------------------------------------------------------
#include "main.h"
//-----------------------------------------------------------------------------------
void File_Download();
void FS_File_Download();
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
	&_Init,
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

//-------------------------------------
in_flash TCMenuItem _Show_IP=
{
	"ip",NULL,0,
	id_show,	
	&_Root,	
	NULL,
	&_Config,
};
//-------------------------------------
in_flash TCMenuItem _Show_Status=
{
	"status",NULL,0,
	Mod_Show_Status,	
	&_Root,	
	NULL,
	&_Show_IP,
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
in_flash TCMenuItem _Test=
{
	"test",NULL,0,
	Mod_Test,	
	&_Root,	
	NULL,
	&_Show,
};
//-----------------------------------------------------------------------------------
in_flash TCMenuItem _Store_Parameters=
{
	"parameters",NULL,0,
	Mod_Store_Parameters,
	&_Root,	
	NULL,
	NULL,
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
#endif
