#include "main.h"
//#include "MenuItems_SERVICE.h"
//#include "MenuItems_FILE.h"
//#include "MenuItems_SET.h"
extern in_flash TCMenuItem _Set;
extern in_flash TCMenuItem _File;
extern in_flash TCMenuItem _Reset;
//------------------------------------------------------------------------------
eu8	itmp,itmp1,itmp2; 
eu8 b[Slovar_Word_Len];
eu8 c[Slovar_Word_Len];	
eu8 d[Slovar_Word_Len];		
//------------------------------------------------------------------------------
extern c8 StrBuff[Slovar_Word_Len];
eu8 StrLine[40];
eu8 Invitation_Str[];
//------------------------------------------------------------------------------
extern in_flash TCMenuItem _Root;
//------------------------------------------------------------------------------
extern TCMenuItem in_flash *	MenuPtr;
extern TCMenuItem in_flash *	MenuPtr2;
//------------------------------------------------------------------------------
extern TCMenuItem in_flash*	MenuList[Menu_List_Count];
extern u8 MenuList_Count;
//------------------------------------------------------------------------------
extern char in;
eu8 Params_Count;
eu32 Params[5];
eu8 Params_Str[5][30];
//------------------------------------------------------------------------------
void ip_con_parser();
void ip_word_handler();
void put_str(u8 *txt,u8 *str);
//------------------------------------------------------------------------------
void ip_con_init()
{
	ip_txt[0]=0;
	outptr=&ip_txt[0];
	ip_txt[0]=0;	
	word[0]=0;
	wordptr=&word[0];
	inptr=&intxt[0];
	intxt[0]=0;
	outtxt=&ip_txt[0];
}
//------------------------------------------------------------------------------
void ip_con_handle(char *in_txt)
{
	// Check rx
	char chr[3];
//	if(console_check_rx())	
	while(*in_txt!=0)
	{
		in=*in_txt++;
		if(ip_txt[0]==0) // If outbuff is empty, no out any text
		{
			switch(in)
			{
				case '%':
						chr[0]=*in_txt++;
						chr[1]=*in_txt++;
						chr[2]=0;
						if(strcmp(chr,"20")==0)
						{
							in=' ';
							*inptr=in;
							inptr++;					
							*inptr=0;
						}
						if(strcmp(chr,"0D")==0)
						{
							in=0x0D;
							*inptr=in;
							inptr++;					
							*inptr=0;
							ip_con_parser();
							inptr=&intxt[0];
							intxt[0]=0;
						}		
				break;
				case 0x0A:
				break;
				case 0x0D:
				case '?':
					*inptr=in;
					inptr++;					
					*inptr=0;					
					ip_con_parser();
					inptr=&intxt[0];
					intxt[0]=0;
				break;
				case 0x09:
					in=' ';		
				default:
					if(inptr<&intxt[39]){
						*inptr=in;
						inptr++;					
						*inptr=0;			
					}
				break;
			}
		}
	}
}
//------------------------------------------------------------------------------
void ip_con_parser()
{
	u16 i=0;	
	u8 *ptr;
	MenuPtr=(TCMenuItem in_flash *)_Root.SubItem;
//	MenuPtr=_Root.SubItem;
	in=intxt[0];
	Params_Count=0;
	MenuList[MenuList_Count]=MenuPtr;
	MenuList_Count=1;
	while(in!=0)
	{
			switch(in)
			{
				case 0x0d:
				case ' ':
				case ':':				
//				case '-':				
				case '?':
					ip_word_handler();
				break;
				default:
					*wordptr=in;
					wordptr++;					
					*wordptr=0;					
				break;
			}
			i++;
			in=intxt[i];			
	}
	//intxt - line to parsing
	ptr=(u8*)intxt;
	while(*ptr!=0)
	{
		if((*ptr==0x0a)||(*ptr==0x0d))
			*ptr=0;
		ptr++;
	}		
	StrLine[0]=0;
}
//------------------------------------------------------------------------------
void ip_word_handler()
{
//	char st=0;	// status 0-unrecognized command
	if(MenuPtr->Flag==0)	
	{
		__strlwr((c8*)word);
		strfull(word);
	}
	switch(in)
	{
		case ' ':
		case ':':
//		case '/':
//		case '\':
//		case '-':
		//case '.':		
			if(word[0]==0)break;
			while(MenuPtr!=NULL)
			{
				if(MenuPtr->Flag==0)				
				{
					// if match found then go to sublayer
					if(strcmp3((u8*)MenuPtr->Word,(u8*)word)==0)
					{
						strcat2(&StrLine[0],(u8*)MenuPtr->Word);
						// if sublayer exist go ...
						if(MenuPtr->SubItem!=NULL)
						{
							MenuPtr=(TCMenuItem in_flash*)MenuPtr->SubItem;
							break;
						}
						// finish of tree - make routine be course key Enter is folowing
						else
						{
							if(MenuPtr->Routine!=NULL)
							{
								MenuPtr->Routine();						
								__sprintf(ip_txt,Invitation_Str);		
							}
							MenuPtr=NULL;			
							break;			
						}
					}
					// if no match try to check other tree
					else
					{
						// if next tree exist go to
						if(MenuPtr->NextItem!=NULL)
						{
							MenuPtr=(TCMenuItem in_flash*)MenuPtr->NextItem;
//							break;
						}
						// finish of trees
						else
						{
							MenuPtr=NULL;
							__sprintf(ip_txt,"\n\r Bad command ");	
//							__sprintf(ip_txt,word);								
							__sprintf(ip_txt,Invitation_Str);
						}
					}
				}
				// Digits 1..4 
				if((MenuPtr->Flag<=4)&&(MenuPtr->Flag!=0))	
				{
//					__sprintf(ip_txt,"\n\r Got middle");
					Params[Params_Count]=__strtol(word,NULL,0);
					Params_Count++;
					// if next tree exist go to
					if(MenuPtr->SubItem!=NULL)
					{
						MenuPtr=(TCMenuItem in_flash*)MenuPtr->SubItem;
						break;
					}
					// finish of trees
					else
					{
						MenuPtr=NULL;
						__sprintf(ip_txt,"\n\r Bad command");	
//						__sprintf(ip_txt,word);	
						__sprintf(ip_txt,Invitation_Str);
					}
				}		
				// Str 5
				if(MenuPtr->Flag==5)	
				{
					strcpy((char*)Params_Str[Params_Count], (char*)word);
					Params_Count++;
					// if next tree exist go to
					if(MenuPtr->SubItem!=NULL)
					{
						MenuPtr=(TCMenuItem in_flash*)MenuPtr->SubItem;
						break;
					}
					// finish of trees
					else
					{
						MenuPtr=NULL;
						__sprintf(ip_txt,"\n\r Bad command");	
//						__sprintf(ip_txt,word);	
						__sprintf(ip_txt,Invitation_Str);
					}
				}	
			}
		break;
		case 0x0d:
			if(strcmp((c8*)word,"")==0)
				__sprintf(ip_txt,Invitation_Str);			
			else
			while(MenuPtr!=NULL)
			{
				if(MenuPtr->Flag==0)				
				{
					// if match found then go to sublayer				
					if(strcmp3((u8*)MenuPtr->Word,(u8*)word)==0)
					{
//						MenuList[MenuList_Count]=MenuPtr;
//						MenuList_Count++;					
						strcat2(&StrLine[0],(u8*)MenuPtr->Word);
						// if sublayer exist then print available trees
						if(MenuPtr->SubItem!=NULL)
						{
							__sprintf(ip_txt,"\n\r ");
							__sprintf(ip_txt,StrLine);
							__sprintf(ip_txt," : Available parameters ");
							MenuPtr2=(TCMenuItem in_flash*)MenuPtr->SubItem;
							while(MenuPtr2!=NULL)
							{
								__sprintf(ip_txt,"\n\r   ");
								//GetFlashStr(ip_txt,(u8*)MenuPtr2->Word);
								put_str(ip_txt,(u8*)MenuPtr2->Word);
								MenuPtr2=(TCMenuItem in_flash*)MenuPtr2->SubItem;
							}
							__sprintf(ip_txt,Invitation_Str);
							MenuPtr=NULL;												
						}
						// finish of tree, do final routine
						else
						{			
							MenuPtr->Routine();
							MenuPtr=NULL;	
							__sprintf(ip_txt,Invitation_Str);						
						}
					}
					// if no match try to check other tree
					else
					{
						// if next tree exist go to
						if(MenuPtr->NextItem!=NULL)
						{
							MenuPtr=(TCMenuItem in_flash*)MenuPtr->NextItem;
						}
						// finish of trees
						else
						{
							MenuPtr=NULL;
							__sprintf(ip_txt,"\n\r Bad command");
//							__sprintf(ip_txt,word);	
							__sprintf(ip_txt,Invitation_Str);
							break;
						}
					}
				}
				// Digits 1..4 
				if((MenuPtr->Flag<=4)&&(MenuPtr->Flag!=0))	
				{
					Params[Params_Count]=__strtol(word,NULL,0);
					if(MenuPtr->Routine!=NULL)
					{
						MenuPtr->Routine();					
						__sprintf(ip_txt,Invitation_Str);								
					}
					MenuPtr=NULL;
				}		
				// Str 5
				if(MenuPtr->Flag==5)	
				{
					strcpy((char*)Params_Str[Params_Count],(char*)word);
					Params_Count++;
					if(MenuPtr->Routine!=NULL)
					{
						MenuPtr->Routine();					
						__sprintf(ip_txt,Invitation_Str);								
					}
					MenuPtr=NULL;
				}	
			}
		break;
		case '?':
				__sprintf(ip_txt,"\n\r Available parameters");
				MenuPtr2=MenuPtr;
				while(MenuPtr2!=NULL)
				{
					__sprintf(ip_txt,"\n\r   ");
					//GetFlashStr(ip_txt,(u8*)MenuPtr2->Word);
					put_str(ip_txt,(u8*)MenuPtr2->Word);
					MenuPtr2=(TCMenuItem in_flash*)MenuPtr2->NextItem;
				}
				__sprintf(ip_txt,Invitation_Str);			
		break;

	}
	word[0]=0;
	wordptr=&word[0];
}
//------------------------------------------------------------------------------
void ip_con_remove_n(u8* str)
{
	while(*str!=0)
	{
		if(*str=='\n')*str=' ';
		str++;
	}
}
//------------------------------------------------------------------------------
