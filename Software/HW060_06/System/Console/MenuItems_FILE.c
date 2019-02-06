//#ifndef __FILE
//#define __FILE
#include "main.h"
//-----------------------------------------------------------------------------------
extern in_flash TCMenuItem _Set;
extern in_flash TCMenuItem _File;
extern in_flash TCMenuItem _Reset;
//-----------------------------------------------------------------------------------
void FS_Check();
void FS_Format();
void FS_Write_Buff(u8* data,u8 len);
void FS_Scan_Files (char* path);
void FS_Make_Dir (char* path);
void FS_Delete (char* name);
void FS_Rename (char* old, char* new);
void FS_Show_Files ();
void FS_Change_Dir (char* path);

void _FS()
{
	FS_Scan_Files ("");
}
void _FR()
{
	FS_Rename (Params_Str[0],Params_Str[1]);
}
void _CD()
{
	FS_Change_Dir (Params_Str[0]);
}
void _DF()
{
	FS_Delete (Params_Str[0]);
}
void _FMKD()
{
	FS_Make_Dir (Params_Str[0]);
}
//-----------------------------------------------------------------------------------
extern in_flash TCMenuItem _Reset;
//-----------------------------------------------------------------------------------
in_flash TCMenuItem _File_Make_Rename_File_New=
{
	"new name",NULL,5,
	_FR,	
	&_Root,	
	NULL,
	NULL,
};
//-----------------------------
in_flash TCMenuItem _File_Make_Rename_File_Old=
{
	"old name",NULL,5,
	NULL,	
	&_Root,	
	&_File_Make_Rename_File_New,
	NULL,
};
//-----------------------------
in_flash TCMenuItem _File_Rename=
{
	"rename",NULL,0,
	NULL,	
	&_Root,	
	&_File_Make_Rename_File_Old,
	NULL,
};
//-----------------------------------------------------------------------------------
in_flash TCMenuItem _File_DC_Name=
{
	"name",NULL,5,
	_CD,	
	&_Root,	
	NULL,
	NULL,
};
//-----------------------------
in_flash TCMenuItem _File_CD=
{
	"cd",NULL,0,
	NULL,	
	&_Root,	
	&_File_DC_Name,
	&_File_Rename,
};
//-----------------------------------------------------------------------------------
in_flash TCMenuItem _File_Make_Del_File=
{
	"name",NULL,5,
	_DF,	
	&_Root,	
	NULL,
	NULL,
};
//-----------------------------
in_flash TCMenuItem _File_Del=
{
	"del",NULL,0,
	NULL,	
	&_Root,	
	&_File_Make_Del_File,
	&_File_CD,
};
//-----------------------------------------------------------------------------------
in_flash TCMenuItem _File_Make_Dir_Name=
{
	"name",NULL,5,
	_FMKD,	
	&_Root,	
	NULL,
	NULL,
};
//-----------------------------
in_flash TCMenuItem _File_Make_Dir=
{
	"makedir",NULL,0,
	NULL,	
	&_Root,	
	&_File_Make_Dir_Name,
	&_File_Del,
};
//-----------------------------------------------------------------------------------
in_flash TCMenuItem _File_Dir=
{
	"dir",NULL,0,
	FS_Show_Files,	
	&_Root,	
	NULL,
	&_File_Make_Dir,
};
//-----------------------------------------------------------------------------------
in_flash TCMenuItem _File_Format=
{
	"format",NULL,0,
	FS_Format,	
	&_Root,	
	NULL,
	&_File_Dir,
};
//-----------------------------------------------------------------------------------
in_flash TCMenuItem _File_Check=
{
	"check",NULL,0,
	FS_Check,	
	&_Root,	
	NULL,
	&_File_Format,
};
//-----------------------------------------------------------------------------------
in_flash TCMenuItem _File=
{
	"file",NULL,0,
	NULL,	
	&_Root,	
	&_File_Check,
	&_Reset,
};
//-----------------------------------------------------------------------------------
//#endif
