//-----------------------------------------------------------------------------------
// Sourse programmable controller
//-----------------------------------------------------------------------------------
#include "main.h"
//-----------------------------------------------------------------------------------
u16 CRC;
u8 Cycle=0;
u8 To_Store=0;	// Sign to store parameters
//------------------------------------------------------------------------------
TController CV;
u8 middle;
TInterpretatorRegisters intr;
u32 HW=0;
//-----------------------------------------------------------------------------------
void custom_handle();
void Fancoil_Temperature_Control();
void kotel_handle(void);

void stellaris_init(void);
void stellaris_run(void);
void do_process(unsigned __packed long *dout);
unsigned long di_process();
void ao_process(unsigned __packed short *AO ,unsigned char num);
void AT45_Init();
void FS_Check();
u8 FS_Check_Sys ();
u8 FS_Flash_Check_CRC(char* name);
//-----------------------------------------------------------------------------------
in_flash u8	mdic[][80]=
{
	"\n\r Configuration data is OK. Loading...",
	"\n\r Configuration record 1 is corrupted! Repairing...",
	"\n\r Configuration record 2 is corrupted! Repairing...",
	"\n\r"
	"\n\r CV060 Bootloader",
	"\n\r Configuration records are corrupted! Impossible to load",
	"\n\r Setting default values",	
	"\n\r Name: ",		
};
//-----------------------------------------------------------------------------------
extern u8 Invitation_Str[];
//-----------------------------------------------------------------------------------
void params_set_default_always()
{
}
//-----------------------------------------------------------------------------------
void params_set_default()
{
//	u8 i,j;
	memset(&reg_ip,0,sizeof(reg_ip));
	reg_ip.ip[0]=192;
	reg_ip.ip[1]=168;
	reg_ip.ip[2]=1;
	reg_ip.ip[3]=1;	
	reg_ip.mask[0]=255;
	reg_ip.mask[1]=255;
	reg_ip.mask[2]=255;
	reg_ip.mask[3]=0;	
	reg_ip.gw[0]=192;
	reg_ip.gw[1]=168;
	reg_ip.gw[2]=1;
	reg_ip.gw[3]=1;		
	
	reg_ip.mac[0]=0x00;
	reg_ip.mac[1]=0x19;
	reg_ip.mac[2]=0x4f;
	reg_ip.mac[3]=0xd2;
	reg_ip.mac[4]=0x99;
	reg_ip.mac[5]=0x78;
}
//-----------------------------------------------------------------------------------
void mem_dump(u8 *buff,u8 len);
//-----------------------------------------------------------------------------------
void params_load()
{
	id_read();
	IP4_ADDR_MAKE(new_ip,ID[0],ID[1],ID[2],ID[3]);
	update_ip_address=1;
}
//-----------------------------------------------------------------------------------
void params_store()
{
	id_store();
}
//-----------------------------------------------------------------------------------
void id_show()
{
	__sprintf((u8*)outtxt,"\n\r IP   ");ByteToStr(outtxt,&ID[0],0);
	__sprintf((u8*)outtxt,".");ByteToStr(outtxt,&ID[1],0);
	__sprintf((u8*)outtxt,".");ByteToStr(outtxt,&ID[2],0);
	__sprintf((u8*)outtxt,".");ByteToStr(outtxt,&ID[3],0);
}
//-----------------------------------------------------------------------------------
void id_read()
{
	fram_comp_read(fram_reg_Serial0,&ID[0],1);
	fram_comp_read(fram_reg_Serial1,&ID[1],1);
	fram_comp_read(fram_reg_Serial2,&ID[2],1);
	fram_comp_read(fram_reg_Serial3,&ID[3],1);
}
//-----------------------------------------------------------------------------------
void id_store()
{
	fram_comp_write(fram_reg_Serial0,&ID[0],1);
	fram_comp_write(fram_reg_Serial1,&ID[1],1);
	fram_comp_write(fram_reg_Serial2,&ID[2],1);
	fram_comp_write(fram_reg_Serial3,&ID[3],1);	
}
//-----------------------------------------------------------------------------------
void high_priority_routine_all()
{
}
//-----------------------------------------------------------------------------------
void init()
{
	watchdog_init();
	stellaris_init();	
	Timer_Init();
	I2C_Init();	
	con_init();	
	adc_init();
	AT45_Init();
}
//------------------------------------------------------------------------------
void main(void)
{
	u8 console_mode=0;
	u8 i;
	
	init();
 	__sprintf_P((u8*)outtxt,mdic[3]);	
	params_load();	
	id_read();		
	id_show();	
	watchdog_reset();
	FS_Check();
	if(FS_Check_Sys())
	{
		__sprintf((u8*)outtxt,"\n\r Device is fully operational");	
		__sprintf((u8*)outtxt,"\n\r To enter boot loader press ESC ");	
		for(i=0;i<8;i++)
		{
			watchdog_reset();
			if(console_check_rx())
				if(console_rx_byte()==13)break;
			if(console_check_rx())
				if(console_rx_byte()==27)
				{
					console_mode=1;
					break;
				}
			__sprintf((u8*)outtxt,"*");	
			Delay(500);
		}
		if(console_mode==0)
		{
			__sprintf((u8*)outtxt,"\n\r Starting Application software ");			
			IntMasterDisable();
			StartApplication();
		}
		else
		{
			__sprintf((u8*)outtxt,Invitation_Str);										
			SysSetUp=SYS_SET_UP_PERIOD;	
			while(1)
			{
				stellaris_run();	
				con_handle();
				watchdog_reset();
				if(FramTime==0)
				{
					FramTime=1000;
					LED_Time=250;
					fram_get_time(&MenuRegs.Time);
				}	
				if((To_Store)&&(Time_To_Store==0))
				{
					params_store();
					To_Store=0;
				}		
			}			
		}
	}
	else
	{
		__sprintf((u8*)outtxt,"\n\r Device operational is limited. Check file structure");	
		__sprintf((u8*)outtxt,Invitation_Str);										
		SysSetUp=SYS_SET_UP_PERIOD;	
		while(1)
		{
			stellaris_run();	
			con_handle();
			watchdog_reset();
			if(FramTime==0)
			{
				FramTime=1000;
				LED_Time=250;
				fram_get_time(&MenuRegs.Time);
			}	
			if((To_Store)&&(Time_To_Store==0))
			{
				params_store();
				To_Store=0;
			}		
		}
	}
}
//-----------------------------------------------------------------------------------
