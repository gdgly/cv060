#include "main.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
//------------------------------------------------------------------------------
extern FRESULT fresult;
extern DIR g_sDirObject;
extern FIL file;

int str_to_ip (char* str, char* ip_addr);

//------------------------------------------------------------------------------
TNamedVariable __packed	NVar[MAX_NAMED_VARIABLES_LIST]={
	{" ", 			NULL, 							TYPE_NOTKNOWN, 	1, 	0},
	{"IP",			&ExtCV.ip_str[0], 				TYPE_STR, 	1, 	sizeof(ExtCV.ip_str)},
	{"MASK",		&ExtCV.mask_str[0],				TYPE_STR, 	1, 	sizeof(ExtCV.mask_str)},
	{"GW",			&ExtCV.gw_str[0], 				TYPE_STR, 	1, 	sizeof(ExtCV.gw_str)},
	{"MAC",			&ExtCV.mac_str[0],				TYPE_STR, 	1, 	sizeof(ExtCV.mac_str)},
	{"SER_ID",		&ExtCV.ser_id,	 				TYPE_U8, 	1, 	sizeof(ExtCV.ser_id)},
	
	{" ", 			NULL, 							TYPE_NOTKNOWN, 	1, 	0},
	{"BL_PID",		&ExtCV.bl_pid, 					TYPE_U8, 	1, 	sizeof(ExtCV.bl_pid)},
	{"BL_FAN",		&ExtCV.bl_fan, 					TYPE_U8, 	1, 	sizeof(ExtCV.bl_fan)},
	{"BL_VAL",		&ExtCV.bl_valve, 				TYPE_U8, 	1, 	sizeof(ExtCV.bl_valve)},
	{"BL_KOT",		&ExtCV.bl_kotel, 				TYPE_U8, 	1, 	sizeof(ExtCV.bl_kotel)},
	{"BL_PAR",		&ExtCV.bl_param, 				TYPE_U8, 	1, 	sizeof(ExtCV.bl_param)},
	{"BL_SES",		&ExtCV.bl_season, 				TYPE_U8, 	1, 	sizeof(ExtCV.bl_season)},
	{" ", 			NULL, 							TYPE_NOTKNOWN, 	1, 	0},
	{"AI_COF",		(char*)&io.ai_coff[0], 			TYPE_F32, 	NUM_AIN_REAL, 	sizeof(io.ai_coff[0])},
	{" ", 			NULL, 							TYPE_NOTKNOWN, 	1, 	0},
	{"AI_OFF",		(char*)&io.ai_offset[0], 			TYPE_S16, 	NUM_AIN_REAL, 	sizeof(io.ai_offset[0])},
	{" ", 			NULL, 							TYPE_NOTKNOWN, 	1, 	0},
	{"AI_FIL",		(char*)&ExtCV.adc_filter_time[0],	TYPE_U16, 	NUM_AIN_REAL, 	sizeof(io.ai_offset[0])},
	{" ", 			NULL, 							TYPE_NOTKNOWN, 	1, 	0},
	//{"iA.rc", 		(u8*) &Static.iA_Params.rc, 	TYPE_U8, 	1, 	sizeof(TiA_Param)},
	{"", 			NULL, 							TYPE_U8, 	1, 	0},
};
//------------------------------------------------------------------------------
// Initialisation of structure
//------------------------------------------------------------------------------
void nvar_init(void)
{
}
//------------------------------------------------------------------------------
int nvar_load(char *name)
{
#if INI_FILE
	c8 str[40];
	c8 reg[40];
	c8 val[40];
	c8 index[10];
	c8 chr;
	c8 *cptr;
	c8 *eptr;
	int	ptr=0;
	WORD rl=1;
	int i;
	long	lv,li;
	
	// Init variables structure
	nvar_init();
	
	fresult = f_opendir(&g_sDirObject, "");	if(fresult != FR_OK) {f_close(&file);return 0;}
	fresult=f_open(&file,name,FA_OPEN_EXISTING | FA_READ);	if(fresult != FR_OK) {f_close(&file);return 0;}
	
	ptr=0;
	str[0]=0;
	reg[0]=0;
	val[0]=0;
	while(rl !=0 )
	{
		fresult=f_read(&file,&chr,1,&rl);
		if(chr != '\n')
		{
			str[ptr] = chr;
			ptr++;
			str[ptr] = 0;
		}
		else
		{	
			if(str[0] != 0)
			{
				// Get register name
				cptr = strstr(str,"[");						
				if(cptr == NULL)	cptr = strstr(str,"=");
				if(cptr != NULL)
				{
					eptr = cptr;
					cptr = str;
					ptr=0;
					while((cptr != eptr)&&(ptr < 20))
					{
						reg[ptr++]=*cptr++;
						reg[ptr]=0;
					}						
				}
					
				ptr=0;
				// Look for registers
				for(i=0;i<MAX_NAMED_VARIABLES_LIST;i++)
				{
					if(NVar[i].name[0]!=0)
					{
						//if(strstr(NVar[i].name,str) != NULL)
						if(strcmp(NVar[i].name,reg) == 0)
						{
							index[0]=0;
							val[0]=0;
							// Get index
							cptr = strstr(str,"[");
							if(cptr != NULL)
							{							
								cptr++;
								eptr = strstr(str,"]");
								if(eptr != NULL)
								{
									ptr=0;
									while((cptr!=eptr)&&(ptr<9))
									{
										index[ptr++]=*cptr++;
										index[ptr]=0;
									}
								}						
								else break;							
							}
							// Get value
							cptr = strstr(str,"=");
							if(cptr != NULL)
							{
								cptr++;
								strcpy(val,cptr);
							}
							else break;
							
							// Transfer values into memory
							li=strtol(index,NULL,0);
							lv=strtol(val,NULL,0);
							if(li < NVar[i].num)
								switch(NVar[i].type)
								{
								case TYPE_S8:  *(s8*) (NVar[i].ptr + NVar[i].offs*li) = lv;break;
								case TYPE_U8:  *(u8*) (NVar[i].ptr + NVar[i].offs*li) = lv;break;
								case TYPE_S16: *(s16*)(NVar[i].ptr + NVar[i].offs*li) = lv;break;
								case TYPE_U16: *(u16*)(NVar[i].ptr + NVar[i].offs*li) = lv;break;
								case TYPE_S32: *(s32*)(NVar[i].ptr + NVar[i].offs*li) = lv;break;
								case TYPE_U32: *(u32*)(NVar[i].ptr + NVar[i].offs*li) = lv;break;
								case TYPE_F32: *(f32*)(NVar[i].ptr + NVar[i].offs*li) = strtof(val,NULL); break;
								case TYPE_STR: strcpy((char*)(NVar[i].ptr + NVar[i].offs*li), val); break;
								}
							break;
						}
					}
				}
			}
			str[0]=0;
			ptr=0;
		}
	}
	f_close(&file);	
	nvar_to_common();
#endif
	return 1;
}
//------------------------------------------------------------------------------
int nvar_store(char *name)
{
#if INI_FILE
	u8 i,j;
	WORD rl;
	c8 str[4];
	c8 val[40];
	//u8 old=0;
	s32 hl,ll;
	float ftmp;
	
	common_to_nvar();
	// Init variables structure
	nvar_init();
	
	strcpy(str,"=\n");
	fresult = f_opendir(&g_sDirObject, "");	if(fresult != FR_OK) {f_close(&file);return 0;}
	fresult=f_open(&file,name,FA_CREATE_ALWAYS | FA_WRITE);	if(fresult != FR_OK) {f_close(&file);return 0;}
	
	sprintf(val,"//--------------------------------\n");	
	fresult=f_write(&file,val,strlen(val),&rl);if(fresult != FR_OK) {f_close(&file);return 0;}
	sprintf(val,"//  %s\n\r",__DATE__);
	fresult=f_write(&file,val,strlen(val),&rl);if(fresult != FR_OK) {f_close(&file);return 0;}	
	sprintf(val,"//  %s\n\r",__TIME__);
	fresult=f_write(&file,val,strlen(val),&rl);if(fresult != FR_OK) {f_close(&file);return 0;}
	sprintf(val,"//  %s\n\r",PRJ_NAME);
	fresult=f_write(&file,val,strlen(val),&rl);if(fresult != FR_OK) {f_close(&file);return 0;}		
	sprintf(val,"//--------------------------------\n");
	fresult=f_write(&file,val,strlen(val),&rl);if(fresult != FR_OK) {f_close(&file);return 0;}		
	
	for(i=0; i<MAX_NAMED_VARIABLES_LIST; i++)
	{
		if(NVar[i].name[0] != 0)
		{
			if(NVar[i].num <= 1)
			{
				fresult=f_write(&file,(u8*)NVar[i].name,strlen(NVar[i].name),&rl);if(fresult != FR_OK) {f_close(&file);return 0;}
				switch(NVar[i].type)
				{
				case TYPE_S8:  sprintf(val,"=%d\n", *(s8*)NVar[i].ptr);break;
				case TYPE_U8:  sprintf(val,"=%d\n", *(u8*)NVar[i].ptr);break;
				case TYPE_S16: sprintf(val,"=%d\n", *(s16*)NVar[i].ptr);break;
				case TYPE_U16: sprintf(val,"=%d\n", *(u16*)NVar[i].ptr);break;
				case TYPE_S32: sprintf(val,"=%li\n",*(s32*)NVar[i].ptr);break;
				case TYPE_U32: sprintf(val,"=%li\n",*(u32*)NVar[i].ptr);break;
				case TYPE_F32: 
					ftmp =  *(f32*)(NVar[i].ptr); 
					hl = (s32)ftmp; 
					ll = (s32)((ftmp - hl) * 100000);
					sprintf(val,"=%d.%d\n", hl, ll);
					break;
				case TYPE_STR: sprintf(val,"=%s\n", NVar[i].ptr);break;
				default:
						sprintf(val,"\n");
					break;
				}
				fresult=f_write(&file,val,strlen(val),&rl); if(fresult != FR_OK) {f_close(&file);return 0;}
			}
			else
			{
				for(j=0;j<NVar[i].num;j++)
				{
					fresult=f_write(&file,(u8*)NVar[i].name,strlen(NVar[i].name),&rl);if(fresult != FR_OK) {f_close(&file);return 0;}
					sprintf(val,"[%d]",j);
					fresult=f_write(&file,val,strlen(val),&rl);if(fresult != FR_OK) {f_close(&file);return 0;}
					switch(NVar[i].type)
					{
					case TYPE_S8:  sprintf(val,"=%d\n",  *(s8*)(NVar[i].ptr + NVar[i].offs*j));break;
					case TYPE_U8:  sprintf(val,"=%d\n",  *(u8*)(NVar[i].ptr + NVar[i].offs*j));break;
					case TYPE_S16: sprintf(val,"=%d\n", *(s16*)(NVar[i].ptr + NVar[i].offs*j));break;
					case TYPE_U16: sprintf(val,"=%d\n", *(u16*)(NVar[i].ptr + NVar[i].offs*j));break;
					case TYPE_S32: sprintf(val,"=%li\n",*(s32*)(NVar[i].ptr + NVar[i].offs*j));break;
					case TYPE_U32: sprintf(val,"=%li\n",*(u32*)(NVar[i].ptr + NVar[i].offs*j));break;
					case TYPE_F32: 
						ftmp =  *(f32*)(NVar[i].ptr + NVar[i].offs*j); 
						hl = (s32)ftmp; 
						ll = (s32)((ftmp - hl) * 100000);
						sprintf(val,"=%d.%d\n", hl, ll);
						break;
					case TYPE_STR: sprintf(val,"=%s\n", NVar[i].ptr); break;
					default:
						sprintf(val,"\n");
						break;
					}
					fresult=f_write(&file,val,strlen(val),&rl); if(fresult != FR_OK) {f_close(&file);return 0;}	
				}
				sprintf(val,"\n");	
				fresult=f_write(&file,val,strlen(val),&rl); if(fresult != FR_OK) {f_close(&file);return 0;}											
			}
			//old = NVar[i].num;
		}
	}
	f_close(&file);	
#endif
	return 1;	// All is ok
}

//------------------------------------------------------------------------------

void nvar_to_common()
{
	str_to_ip (ExtCV.ip_str, (char*)ID);
	str_to_ip (ExtCV.mask_str, (char*)reg_ip.mask);
	str_to_ip (ExtCV.gw_str, (char*)reg_ip.gw);                                   
}

//------------------------------------------------------------------------------

void common_to_nvar()
{
	sprintf(ExtCV.ip_str,	"%d.%d.%d.%d", ID[0], ID[1], ID[2], ID[3]);
	sprintf(ExtCV.mask_str,	"%d.%d.%d.%d", reg_ip.mask[0], reg_ip.mask[1], reg_ip.mask[2], reg_ip.mask[3]);
	sprintf(ExtCV.gw_str,	"%d.%d.%d.%d", reg_ip.gw[0], reg_ip.gw[1], reg_ip.gw[2], reg_ip.gw[3]);
//	sprintf(ExtCV.mac_str,	"%02X.%02X.%02X.%02X.%02X", reg_ip.mac[0], reg_ip.mac[1], reg_ip.mac[2], reg_ip.mac[3], reg_ip.mac[4], reg_ip.mac[5]);
}

//------------------------------------------------------------------------------
