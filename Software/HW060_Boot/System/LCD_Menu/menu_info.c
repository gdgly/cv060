//-----------------------------------------------------------------------------------
#include "..\main.h"
//-----------------------------------------------------------------------------------
#define MAX_INFO_LINES 5
//-----------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------
TMenuRecodr in_flash* menu_str;
in_flash TMenuRecodr	eng_info_str[7]=
{
	"EastLabs",			0,		//0
	"controller",		0,		//1
	"model:",			0,		//2	
	"HW    ",			0,		//3
	"SW    ",			0,		//4	
	"Issue date ",		0,		//5
	"                ",	0,		//6	
};
in_flash TMenuRecodr	ru_info_str[7]=
{
	"�������",			0,		//0
	"����������",		0,		//1
	"������:",			0,		//2
	"����� ",			0,		//3
	"����  ",			0,		//4
	"���� ������� ",	0,		//5
	"                ",	0,		//6	
};
//-----------------------------------------------------------------------------------

in_flash u8	eng_info_dic[2][20]=
{
	"Information",		//0
	"about controller",				//0	
};
in_flash u8	ru_info_dic[2][20]=
{
	"���������� o",			//0
	"�����������",					//0	
};	
//-----------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------
void lcd_title_info()
{
	if(newmenuitem)
	{
		lcd_clear();		
		lcd_set_pos(0,0);
		if(MenuRegs.lang==0)
		{
			lcd_printf_P(eng_info_dic[0]);			
			lcd_set_pos(1,0);			
			lcd_printf_P(eng_info_dic[1]);			
		}
		if(MenuRegs.lang==1)
		{
			lcd_printf_P(ru_info_dic[0]);	
			lcd_set_pos(1,0);			
			lcd_printf_P(ru_info_dic[1]);
		}
		pos=0;
	}
	newmenuitem=0;	
}
//-----------------------------------------------------------------------------------
void lcd_show_info()
{
//	s16 tmp;
	u8 i,j;
	u8 pos_old;
//	u8 edit_pos;
//	u8 show_pos_tmp;	
	if(newmenuitem)
	{
		if(MenuRegs.lang==0)
			menu_str=&eng_info_str[0];
		if(MenuRegs.lang==1)
			menu_str=&ru_info_str[0];		
		for(i=pos;i<(MAX_INFO_LINES-2);i++)
			if(menu_str[i].lvl<=password_lvl)
			{
				pos=i;
				break;
			}	
			
		lcd_clear();
		memset(lcd_txt, 0, sizeof(lcd_txt));				
		for(i=pos;i<pos+2;i++)					
		{
			lcd_set_pos(i-pos,0);
			if(i<MAX_INFO_LINES)	
			{						
				if(menu_str[i].lvl>password_lvl)
				{
					pos_old=i;
					for(j=i+1;j<(MAX_INFO_LINES);j++)
						if(menu_str[j].lvl<=password_lvl)
						{
							i=j;
							break;
						}
				}	
				if(menu_str[i].lvl<=password_lvl)
				{				
					__sprintf_P(lcd_txt,menu_str[i].str);					
					lcd_printf(lcd_txt);	
					switch(i)
					{
						case 3:
							FGet(HAPP_FLASH_START+THW_LOC,(u8*)&ltmp,4);	
							LongToStr(lcd_txt,&ltmp,0);
							lcd_set_pos(i-pos,8);
							lcd_printf(lcd_txt);
						break;
						case 4:
							FGet(HAPP_FLASH_START+TSW_LOC,(u8*)&ltmp,4);	
							LongToStr(lcd_txt,&ltmp,0);
							lcd_set_pos(i-pos,8);
							lcd_printf(lcd_txt);
						break;				
					}
				}
				else
				{
					__sprintf_P(lcd_txt,menu_str[MAX_INFO_LINES+1].str);				
					lcd_printf(lcd_txt);			
				}	
			}
			else
			{
				__sprintf_P(lcd_txt,menu_str[MAX_INFO_LINES+1].str);				
				lcd_printf(lcd_txt);			
			}			
		}
	}
	newmenuitem=0;	
		// -------- Keys --------------//
		// Up arrow
		if(key0==1)
		{
			pos_old=pos;
			if(pos!=0)pos--;
			for(i=pos;i!=0;i--)
				if(menu_str[i].lvl<=password_lvl)
				{
					pos=i;
					break;
				}
			if(menu_str[pos].lvl>password_lvl)pos=pos_old;
			newmenuitem=1;
			key0=2;			
		}
		// Down arrow		
		if(key1==1)
		{
			pos_old=pos;
			if(pos<(MAX_INFO_LINES-2))pos++;
			for(i=pos;i<(MAX_INFO_LINES-2);i++)
				if(menu_str[i].lvl<=password_lvl)
				{
					pos=i;
					break;
				}
			if(menu_str[pos].lvl>password_lvl)pos=pos_old;
			
			newmenuitem=1;
			key1=2;
		}
		// Esc
		if(key2==1)
		{
			if(LCDMenuPtr->UpItem!=NULL)
			{
				LCDMenuPtr=(TLCDMenuItem*)LCDMenuPtr->UpItem;
				newmenuitem=1;
				pos=0;										
			}	
			newmenuitem=1;				
			key2=2;			
		}
		// Enter		
		if(key3==1)
		{
			if(LCDMenuPtr->UpItem!=NULL)
			{
				LCDMenuPtr=(TLCDMenuItem*)LCDMenuPtr->UpItem;						
				newmenuitem=1;				
			}	
			key3=2;			
		}	
}

//-----------------------------------------------------------------------------------
