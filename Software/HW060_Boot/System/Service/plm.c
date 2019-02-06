#include "main.h"
#include "ff.h"            /* FatFs declarations */
#include "bl_flash.h"
//-----------------------------------------------------------------------------------
u8 ReProgramm(char* name);
//-----------------------------------------------------------------------------------
//u8 UControl0=0;
u8 			UControl1=0;
extern s16 	adc_real_result[NUM_AIN_REAL];
//extern TFanLines FanLines[MAX_FANCOIL_NUMBER];
u8			Program_File=0;

static FATFS g_sFatFs;
extern FRESULT fresult;
extern DIR g_sDirObject;
extern FIL file;
char path[80]={0};
//-----------------------------------------------------------------------------------
in_flash u8	Monthes_Name[12][10]=
{
	"January",
	"February",
	"March",
	"April",
	"May",
	"June",
	"July",
	"August",
	"September",
	"October",
	"November",
	"December",												
};
in_flash u8	Monthes_Name_Short[12][5]=
{
	"Jan",
	"Feb",
	"Mar",
	"Apr",
	"May",
	"Jun",
	"Jul",
	"Aug",
	"Sep",
	"Oct",
	"Nov",
	"Dec",												
};
in_flash u8	DaysOfWeek[7][10]=
{
	"Monday",
	"Tuesday",
	"Wednesday",
	"Thursday",
	"Friday",
	"Saturday",
	"Sunday",
};
in_flash u8	DaysOfWeek_Short[7][5]=
{
	"Mond",
	"Tues",
	"Wedn",
	"Thur",
	"Frid",
	"Satu",
	"Sund",
};
//------------------------------------------------------------------------------
// Russian language
in_flash u8	Monthes_Name_rus[12][10]=
{
	"Январь",
	"Февраль",
	"Март",
	"Апрель",
	"Май",
	"Июнь",
	"Июль",
	"Август",
	"Сентябрь",
	"Октябрь",
	"Ноябрь",
	"Декабрь",												
};
in_flash u8	Monthes_Name_Short_rus[12][5]=
{
	"Янв",
	"Фев",
	"Мар",
	"Апр",
	"Май",
	"Июн",
	"Июл",
	"Авг",
	"Сен",
	"Окт",
	"Ноб",
	"Дек",												
};
in_flash u8	DaysOfWeek_rus[7][13]=
{
	"Понедельник",
	"Вторник",
	"Среда",
	"Четверг",
	"Пятница",
	"Суббота",
	"Воскресенье",
};
in_flash u8	DaysOfWeek_Short_rus[7][5]=
{
	"Пон",
	"Втор",
	"Сред",
	"Четв",
	"Пятн",
	"Субб",
	"Воск",
};
//-----------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------
in_flash u8	pdic[][80]=
{
	"\n\r Resetting...",					//0
	"\n\r Parameters stored ",				//1
	"\n\r Test...\n\r",						//2
	"\n\r Current state ",					//3
	"\n\r   Controller configuration",		//4	
	"\n\r     Digital inputs  \n\r       ",	//5		
	"\n\r     Digital outputs  \n\r       ",//6		
	"\n\r     Analog inputs  \n\r       ",	//7		
	"\n\r     Analog outputs  \n\r       ",	//8		
	"\n\r   Temperature settings",			//9		
	"\n\r     Desired temperature ",		//10		
	"\n\r     Mode of operation ",			//11		
	"\n\r   Program  ",		  				//12		
	"RUN",									//13
	"STOPED",								//14
	"\n\r   Pid settings",					//15
	"\n\r     Desired temperature ",		//16
	"\n\r     Mode of operation ",			//17
	"\n\r     Temperature channel AI[",		//18
	"\n\r     Prop cofficient     ",		//19
	"\n\r     Diff cofficient     ",		//20
	"\n\r     Integral cofficient ",		//21
	"\n\r     Input temperature   ",		//22						
	"\n\r Ready for downloading program image...",	//23						
	"\n\r Download is successful complete...",		//24						
	"\n\r Download error!",							//25						
	"\n\r No valid user program found\n\r Download new bin please ...",		//26						
	"\n\r User program image corrupted\n\r Download new bin please...",		//27						
	"\n\r User program CRC OK. Loading...\n\r Name:  ",		//28						
	"\n\r     Min power ",						//29
	"\n\r     Max power ",						//30
	"\n\r     Power     ",						//31
	"\n\r Power supply voltage ",				//32
	"\n\r     Servoprivod full cycle time c ",	//33
	"\n\r     3 points server power ",			//34
	"\n\r     Open  line ",					//35
	"\n\r     Close line ",					//36		
	"\n\r     Current temperature ",		//37
	"\n\r Bad command",						//38	
	"\n\r     Slow speed ",					//39
	"\n\r     Fast speed ",					//40			
	"\n\r",									//41		
	"\n\r Season ",							//42		
	"Summer",								//43		
	"Winter",								//44	
	"\n\r Controller IP ",					//45	
	"\n\r     Zero power border ",			//46
	"\n\r     Low  power border ",			//47		
	"\n\r   In_Params",						//48
	"\n\r    ",								//49
	"\n\r   Regs ",							//50
	"\n\r   Timers ",						//51
	"\n\r   Out_Params ",					//52	
	"\n\r     Heat/Cooling ",				//53				
	"Heating",								//54
	"Cooling",								//55
	"\n\r     FAN IN  speed ",				//56
	"\n\r     FAN OUT speed ",				//57
	"\n\r Present blocks ",					//58
	"\n\r   Pritochka ",		//59
	"\n\r   Fancoil",	//60		
	"\n\r     Digital outputs  \n\r       ",//61		
	"\n\r     Analog inputs  \n\r       ",	//62		
	"\n\r   Params block ",					//63	

	"\n\r Ready for downloading program image...",							//64						
	"\n\r Download is successful complete...",								//65						
	"\n\r Download error!",													//66						
	"\n\r No valid CPU program found\n\r Download new bin please ...",		//67
	"\n\r CPU program image corrupted\n\r Download new bin please...",		//68						
	"\n\r CPU program CRC OK \n\r Name:  ",									//69						
	"\n\r Ready for downloading FILE 1...",									//70
	"\n\r Ready for downloading FILE 2...",									//71	
	"\n\r No valid PLM program found\n\r Download new bin please ...",		//72
	"\n\r PLM program image corrupted\n\r Download new bin please...",		//73						
	"\n\r PLM program CRC OK \n\r Name:  ",									//74	
//	txt,		//33
};
//-----------------------------------------------------------------------------------
void mem_dump(u8 *buff,u8 len);
void File_Check();
void FS_Scan_Files (char* path);
//-----------------------------------------------------------------------------------
void Mod_Store_Parameters()
{
	params_store();
	__sprintf_P(outtxt,pdic[1]);	
}
//-----------------------------------------------------------------------------------
static volatile u8 g_bFatFsEnabled = false;	
void Jump_To_App(u32 ADDR);
void __Jump_To_App(u32 ADDR);
void Jump_To_App_2();
u8 Tx[1260];
u8 Rx[1260];
unsigned char	te[] = {
0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81,
0x40, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0,
0x80, 0x41, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x00, 0xC1, 0x81, 0x40, 0x01,
0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0, 0x80, 0x41,
0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x00, 0xC1, 0x81,
0x40, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0,
0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x01,
0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40,
0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81,
0x40, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0,
0x80, 0x41, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x00, 0xC1, 0x81, 0x40, 0x01,
0xC0, 0x80, 0x41, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41,
0x00, 0xC1, 0x81, 0x40, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81,
0x40, 0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0,
0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x01,
0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41,
0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81,
0x40
};
void Mod_Test()
{
//	u8	tmp;
//	pid_handle();
//	__sprintf_P(outtxt,pdic[2]);		
//	Production_Test();
	extern u32 HW_in;
	extern u32 HW;
	BuzzerTime=100;
//	LongToStr(outtxt,&HW,1);	
//	__sprintf(outtxt," ");
//	LongToStr(outtxt,&HW_in,1);
//	__sprintf(outtxt,"\n\r");
	
//	fram_mem_enable();
//	fram_mem_write(0,&buff[0],1);
//	__sprintf(outtxt,"\n\r R:");
//	mem_dump(buff,1);	
	
//	fram_mem_read(0,buff,10);
//	__sprintf(outtxt,"\n\r S:");
//	mem_dump(buff,10);	
//	mem_dump((u8*)&CV,20);	
//	fram_mem_disable();


	AT45_Init();
	if(AT45_256_Enable())
	{
		__sprintf(outtxt,"\n\r AT45 256 bytes configured");
	}
	else
	{
		__sprintf(outtxt,"\n\r AT45 264 bytes configured");
	}
//	return;
	u16 i;
	for(i=0;i<1260;i++)
	{
		Tx[i]=i ^ ~te[i & 0x00ff];
	}
	AT45_Init();
	AT45_Addr=0;

	AT45_Long_Write(Tx,1260);
	AT45_End_Write();
	AT45_Long_Read(0,Rx,1260);	
	for(i=0;i<1260;i++)
	{
		if(Tx[i]!=Rx[i])
		{
			__sprintf(outtxt,"\n\r AT45 write error");
			return;
		}
	}
	__sprintf(outtxt,"\n\r AT45 OK");
	return;

//	f_mkfs();
//	path[0]=0;
//	FS_Scan_Files (path);
//	io_init();
//	ReProgramm("sys_cpu.bin");
//	IntMasterDisable();
//	StartApplication();
}
//-----------------------------------------------------------------------------------
u8 Monthes[12]={31,28,31,30,31,30,31,31,30,31,30,31};
//2008.01.01 - 2 (вторник)
u8 get_day_of_week(TCTime *time)
{
	u8 year_rem;
	u32 date=0,tmp;
	u16 j;
	year_rem=time->field.Year & 0x03;
	for(j=1;j<13;j++)
	{
		if(time->field.Month!=j)
		{
			date+=Monthes[j-1];			
			if(year_rem==0)		
				if(j==1)		
					date++;	
		}
		else
		{
			date+=time->field.Date;
			break;
		}
	}
		for(j=8;j<time->field.Year;j++)
		{
			date+=365;
			year_rem=j & 0x03;
			if(year_rem==0)
				date++;
		}
	tmp=date/7;
	tmp=date-(tmp*7);
	tmp+=1;
	if(tmp>7)tmp-=7;	
	time->field.Day=tmp;
	return tmp;
}
//-----------------------------------------------------------------------------------
void Mod_Show_Full_Time(TCTime *time)
{
	TCTime ft;
	ft=*time;
//	u8 tmp;
//	fram_get_time();
/*	
	__sprintf(outtxt,"\n\r Date ");
	ByteToStr(outtxt,&ft.field.Date,0);__sprintf(outtxt,".");
	ByteToStr(outtxt,&ft.field.Month,0);__sprintf(outtxt,".");
	ByteToStr(outtxt,&ft.field.Year,0);
*/	
	__sprintf(outtxt,"\n\r ");
	ByteToStrFillZero(outtxt,&ft.field.Date,0,2,'0');
	__sprintf(outtxt," ");
	__sprintf_P(outtxt,Monthes_Name[ft.field.Month-1]);
	__sprintf(outtxt," 20");
	ByteToStrFillZero(outtxt,&ft.field.Year,0,2,'0');
	__sprintf(outtxt,", ");
	__sprintf_P(outtxt,DaysOfWeek	[get_day_of_week(&ft)-1]);	
				
	__sprintf(outtxt," Time ");
	ByteToStrFillZero(outtxt,&ft.field.Hour,0,2,'0');__sprintf(outtxt,".");
	ByteToStrFillZero(outtxt,&ft.field.Minute,0,2,'0');__sprintf(outtxt,".");
	ByteToStrFillZero(outtxt,&ft.field.Second,0,2,'0');
}
//-----------------------------------------------------------------------------------
void Mod_Show_Status_IO()
{
	s16 wtmp;
	u8 j;
	u16 t;	
	// IO state
	__sprintf_P(outtxt,pdic[4]);	
	__sprintf_P(outtxt,pdic[5]);		
	for(j=0;j<NUM_DIN;j++)
	{
		t=1<<j;			
		if(io.din & t) __sprintf(outtxt,"1 ");
		else __sprintf(outtxt,"0 ");
	}
	__sprintf_P(outtxt,pdic[6]);
	for(j=0;j<NUM_DOUT;j++)
	{
		t=1<<j;			
		if(io.dout & t) __sprintf(outtxt,"1 ");
		else __sprintf(outtxt,"0 ");
	}
	__sprintf_P(outtxt,pdic[7]);	
	for(j=0;j<NUM_AIN;j++)
	{
		wtmp=io.ainput[j];
		ShowTemperature(outtxt,&wtmp);				
		__sprintf(outtxt," "); 			
	}
	// Real AI
/*
	__sprintf_P(outtxt,pdic[7]);	
	for(j=0;j<NUM_AIN;j++)
	{
		wtmp=adc_real_result[j];
		ShowTemperature(outtxt,&wtmp);				
		__sprintf(outtxt," "); 			
	}
*/	
	__sprintf_P(outtxt,pdic[8]);	
	for(j=0;j<NUM_AOUT;j++)
	{
		ShowPowerShort(outtxt,(s16*)&io.aoutput[j]);
		__sprintf(outtxt," "); 			
	}
}
//-----------------------------------------------------------------------------------
void Mod_Show_Status_Prog()
{
//	u16 wtmp;
	u8 j;
//	u16 t;
	// Program state
	__sprintf_P(outtxt,pdic[12]);		
	if(intr.status==int_Run)
		__sprintf_P(outtxt,pdic[13]);		
	if(intr.status==int_Stop)
		__sprintf_P(outtxt,pdic[14]);	
	
//	intr.in_params[0]=0x1234;
//	intr.in_params[1]=0xffff;
//	intr.in_params[2]=0x9876;	
	__sprintf_P(outtxt,pdic[48]);		
	for(j=0;j<PARAMETERS_MAX;j++)
	{
		if((j & 0x07)==0x00)__sprintf_P(outtxt,pdic[49]);		
		IntToStrFillZero(outtxt,(u32*)&intr.in_params[j],0,5,5,1);		
		__sprintf(outtxt," ");
	}	

	__sprintf_P(outtxt,pdic[52]);		
	for(j=0;j<PARAMETERS_MAX;j++)
	{
		if((j & 0x07)==0x00)__sprintf_P(outtxt,pdic[49]);		
		IntToStrFillZero(outtxt,(u32*)&intr.out_params[j],0,5,5,1);		
		__sprintf(outtxt," ");
	}	

	__sprintf_P(outtxt,pdic[50]);
	for(j=0;j<REGISTERS_MAX;j++)
	{
		if((j & 0x07)==0x00)__sprintf_P(outtxt,pdic[49]);				
		IntToStrFillZero(outtxt,(u32*)&intr.reg[j],1,8,3,0);	
		__sprintf(outtxt," "); 			
	}	
	__sprintf_P(outtxt,pdic[51]);
	for(j=0;j<TIMERS_MAX;j++)
	{
		if((j & 0x07)==0x00)__sprintf_P(outtxt,pdic[49]);						
		IntToStrFillZero(outtxt,(u32*)&intr.t32[j],1,8,3,0);			
		__sprintf(outtxt," "); 			
	}		
#if MAX_PARAMS_BLOCK	
	__sprintf_P(outtxt,pdic[63]);	
	__sprintf_P(outtxt,pdic[49]);	
	for(j=0;j<10;j++)
	{
//		if((j & 0x07)==0x00)__sprintf_P(outtxt,pdic[49]);		
		IntToStrFillZero(outtxt,(u32*)&misc.pr[j],0,5,5,1);		
		__sprintf(outtxt," ");
	}	
#endif	
}
//-----------------------------------------------------------------------------------
void Mod_Show_Errors()
{
//	u16 wtmp;
	u8 j,tmp;
//	u16 t;
	// Preset state
//	__sprintf_P(outtxt,pdic[9]);		
//	__sprintf_P(outtxt,pdic[10]);		
//	ShowTemperature(outtxt,&MenuRegs.t0);
//	__sprintf_P(outtxt,pdic[11]);		
//	switch(MenuRegs.mode_of_controller)
//	{
//		case 0:__sprintf(outtxt,"Auto");break;
//		case 1:__sprintf(outtxt,"Summer");break;
//		case 2:__sprintf(outtxt,"Winter");break;				
//	}	
	__sprintf(outtxt,"\n\r  Errors");
	__sprintf(outtxt,"\n\r    New ");ByteToStr(outtxt,&errors.new_error,0);
	for(j=0;j<MAX_ERRORS_NUM;j++)
	{		
		if(errors.item[j].code!=0)
		{
			__sprintf(outtxt,"\n\r    ");ByteToStr(outtxt,&j,0);__sprintf(outtxt,". ");
			__sprintf(outtxt,"Code=");
			tmp=errors.item[j].code>>8;ByteToStrFillZero(outtxt,&tmp,1,2,'0');
			tmp=errors.item[j].code;ByteToStrFillZero(outtxt,&tmp,1,2,'0');
			__sprintf(outtxt," ");
			ByteToStrFillZero(outtxt,&errors.item[j].time.field.Date,0,2,'0');__sprintf(outtxt,"th ");
			__sprintf_P(outtxt,Monthes_Name_Short[errors.item[j].time.field.Month-1]);
			__sprintf(outtxt," 20");
			ByteToStrFillZero(outtxt,&errors.item[j].time.field.Year,0,2,'0');
			__sprintf(outtxt," ");
			ByteToStrFillZero(outtxt,&errors.item[j].time.field.Hour,0,2,'0');__sprintf(outtxt,":");
			ByteToStrFillZero(outtxt,&errors.item[j].time.field.Minute,0,2,'0');__sprintf(outtxt,":");
			ByteToStrFillZero(outtxt,&errors.item[j].time.field.Second,0,2,'0');
		}
	}
}
//-----------------------------------------------------------------------------------
void Mod_Show_Status()
{
	Mod_Show_Full_Time(&MenuRegs.Time);
	__sprintf_P(outtxt,pdic[45]);ByteToStr(outtxt,&ID[0],0);
	__sprintf((u8*)outtxt,".");ByteToStr(outtxt,&ID[1],0);
	__sprintf((u8*)outtxt,".");ByteToStr(outtxt,&ID[2],0);
	__sprintf((u8*)outtxt,".");ByteToStr(outtxt,&ID[3],0);	
	
//	Mod_Show_Status_IO();
//	Mod_Show_Status_Prog();
//	Mod_Show_Status_PID(0);
}
//-----------------------------------------------------------------------------------
void Mod_Show_Block()
{
	u8 tmp;
	__sprintf(outtxt,"\n\r Software has options : ");
#ifdef __HW060
	__sprintf(outtxt,"\n\r  Board CV060  AI:4 AO:3 DI:8 DO:8");
#endif
	tmp=NUM_PID;
	__sprintf(outtxt,"\n\r  PID    blocks ");ByteToStr(outtxt,&tmp,0);
	tmp=MAX_FANCOIL_NUMBER;
	__sprintf(outtxt,"\n\r  FAN    blocks ");ByteToStr(outtxt,&tmp,0);
	tmp=MAX_KOTEL_NUMBER;
	__sprintf(outtxt,"\n\r  Boiler blocks ");ByteToStr(outtxt,&tmp,0);
	tmp=MAX_VALVE_3T_NUMBER;
	__sprintf(outtxt,"\n\r  Valve  blocks ");ByteToStr(outtxt,&tmp,0);
	tmp=MAX_PARAMS_BLOCK;
	__sprintf(outtxt,"\n\r  Params blocks ");ByteToStr(outtxt,&tmp,0);
}
//-----------------------------------------------------------------------------------
void Set_Point()
{	
	f32 ftmp0;
	f32 ftmp1;	
	f32 ftmp2;	
//	s16 tmp;	
	u8 i;	
	// Make point 1 calculations
	if((Params[0]==0)||(Params[0]==1))
	{
		point_reference_temperature[(u8)Params[0]]=(s16)Params[1];
		__sprintf(outtxt,"\n\r Reference temperature");ShowTemperature(outtxt,&point_reference_temperature[(u8)Params[0]]);			
		__sprintf(outtxt,"\n\r Real temperatures");
		__sprintf(outtxt,"\n\r   ");	
		adc_set_channel(0);
		for(i=0;i<NUM_AIN_REAL;i++)	
		{
			Delay(100);
			adc_conversion();
			point_real_temperature[(u8)Params[0]][i]=ad_res;
			adc_set_channel(i+1);	
			ShowTemperature(outtxt,&point_real_temperature[(u8)Params[0]][i]);__sprintf(outtxt,"  ");			
		}
	}
	// Make point 2 calculations >  cofficients + offsets
	if((Params[0]==1))
	{
//		__sprintf(outtxt,"\n\r Coffs and offsets");
//		__sprintf(outtxt,"\n\r   ");		
		ftmp1=point_reference_temperature[1]-point_reference_temperature[0];
		for(i=0;i<NUM_AIN_REAL;i++)	
		{
			ftmp0=point_real_temperature[1][i]-point_real_temperature[0][i];
			if(ftmp0<1)ftmp0=1;
			ftmp2=ftmp1/ftmp0;
			io.ai_coff[i]=ftmp2;
			
//			point_real_temperature[0][i]=(f32)ad_res*io.ai_coff[i];			
//			point_real_temperature[0][i]=point_real_temperature[0][i]*io.ai_coff[i];			
//			io.ai_offset[i]=point_reference_temperature[0]-point_real_temperature[0][i];
//			io.ai_offset[i]=0;
//			io.ai_offset[i]=point_reference_temperature[0]-point_real_temperature[0][i];			
//			ShowTemperature(outtxt,&io.ai_offset[i]);					
		}
	}
	// Make point 2 calculations >  offsets (optional)
	if((Params[0]==2))
	{
		point_reference_temperature[0]=(s16)Params[1];
		__sprintf(outtxt,"\n\r Reference temperature");ShowTemperature(outtxt,&point_reference_temperature[0]);			
		__sprintf(outtxt,"\n\r Real temperatures");
		__sprintf(outtxt,"\n\r   ");			
		adc_set_channel(0);		
		for(i=0;i<NUM_AIN_REAL;i++)	
		{
			Delay(100);
			adc_conversion();
			point_real_temperature[0][i]=(f32)ad_res*io.ai_coff[i];
			adc_set_channel(i+1);	
			ShowTemperature(outtxt,&point_real_temperature[0][i]);__sprintf(outtxt,"  ");		
		}
		for(i=0;i<NUM_AIN_REAL;i++)	
		{
			io.ai_offset[i]=point_reference_temperature[0]-point_real_temperature[0][i];			
		}
		__sprintf(outtxt,"\n\r Offsets");
		__sprintf(outtxt,"\n\r   ");	
		for(i=0;i<NUM_AIN_REAL;i++)	
		{
			ShowTemperature(outtxt,(short *)&io.ai_offset[i]);__sprintf(outtxt,"  ");	
		}			
	}
}
//-----------------------------------------------------------------------------------
void Relay_Off()
{
//	Other.relay[Params[0]]=0;
//	io_relay_set();
}
//-----------------------------------------------------------------------------------
void IO_On()
{	
//	Vacuum.io=1;
	io_io_set();
}
//-----------------------------------------------------------------------------------
void IO_Off()
{
//	Vacuum.io=0;
	io_io_set();
}
//-----------------------------------------------------------------------------------
void Set_AI_10V()
{
//	Vacuum.analog=Params[0];
//	io_analog_set();
	if(Params[0]>=NUM_AIN_REAL)
	{
		__sprintf_P(outtxt,pdic[38]);	
		return;
	}
	io.ai_coff[Params[0]]=1;
	io.ai_offset[Params[0]]=0;	
}
//-----------------------------------------------------------------------------------
void Set_Date()
{
//	fram_set_time(u8 hour,u8 minute,u8 second)
//	fram_set_date(u8 year,u8 month, u8 date,u8 day)	
	fram_set_date((u8)Params[2],(u8)Params[1],(u8)Params[0],1);
}
//-----------------------------------------------------------------------------------
void Set_Time()
{
//	Vacuum.analog=Params[0];
	fram_set_time((u8)Params[0],(u8)Params[1],(u8)Params[2]);
}
//-----------------------------------------------------------------------------------
void Set_Password_On()
{
	MenuRegs.password=1;
	Time_To_Store=3;
}
//-----------------------------------------------------------------------------------
void Set_Password_Off()
{
	MenuRegs.password=0;
	Time_To_Store=3;
}
//-----------------------------------------------------------------------------------
void Set_Password_User()
{
	u32 tmp1,tmp2;
	u8 res;
	u8 i;
	tmp1=tmp2=Params[0];
	for(i=0;i<5;i++)
	{
		tmp1/=10;
		tmp1*=10;
		res=tmp2-tmp1;
		MenuRegs.pass_user[4-i]=res;
		tmp1/=10;
		tmp2=tmp1;
	}
	Time_To_Store=3;
}
//-----------------------------------------------------------------------------------
void Set_Password_Admin()
{
	u32 tmp1,tmp2;
	u8 res;
	u8 i;
	tmp1=tmp2=Params[0];
	for(i=0;i<5;i++)
	{
		tmp1/=10;
		tmp1*=10;
		res=tmp2-tmp1;
		MenuRegs.pass_admin[4-i]=res;
		tmp1/=10;
		tmp2=tmp1;
	}
	Time_To_Store=3;
}
//-----------------------------------------------------------------------------------
void Mod_Console_Toggle()
{
	console_mode=0;
}
//-----------------------------------------------------------------------------------
void Prog_Download()
{
/*
//	u16 CRC;
	Program_Valid=0;
	__sprintf_P(outtxt,pdic[23]);			
	Fram_Addr=CODE_ADDR;
	Xmodem_Start();
	ctmp=XMOD_None;
	while(ctmp==XMOD_None)
	{
		ctmp=Xmodem_Processor();
	}
	if(ctmp==XMOD_Ok)
	{
		__sprintf_P(outtxt,pdic[24]);
		// Check program CRC
		Prog_Check();
		Intr_IRQ0_Start();// Make IO initialisation
	}
	else
		__sprintf_P(outtxt,pdic[25]);
*/	
}
//-----------------------------------------------------------------------------------
void Set_IP()
{
	reg_ip.ip[0]=Params[0];
	reg_ip.ip[1]=Params[1];
	reg_ip.ip[2]=Params[2];
	reg_ip.ip[3]=Params[3];
	id_store();
	IP4_ADDR_MAKE(new_ip,reg_ip.ip[0],reg_ip.ip[1],reg_ip.ip[2],reg_ip.ip[3]);
	update_ip_address=1;
}
//-----------------------------------------------------------------------------------
void Set_Mask()
{
	reg_ip.mask[0]=Params[0];
	reg_ip.mask[1]=Params[1];
	reg_ip.mask[2]=Params[2];
	reg_ip.mask[3]=Params[3];
	id_store();
	IP4_ADDR_MAKE(new_mask,reg_ip.mask[0],reg_ip.mask[1],reg_ip.mask[2],reg_ip.mask[3]);
	update_mask_address=1;
}
//-----------------------------------------------------------------------------------
void Set_GW()
{
	reg_ip.gw[0]=Params[0];
	reg_ip.gw[1]=Params[1];
	reg_ip.gw[2]=Params[2];
	reg_ip.gw[3]=Params[3];
	id_store();
	IP4_ADDR_MAKE(new_gw,reg_ip.gw[0],reg_ip.gw[1],reg_ip.gw[2],reg_ip.gw[3]);
	update_gw_address=1;
}
//-----------------------------------------------------------------------------------
void Prog_Check()
{
	u16 CRC;
	Program_Valid=0;
	// Check program CRC
	wtmp=CheckCRC(1,0);
	FGet(HPLM_FLASH_START+CRC_H_LOC,(u8*)&CRC,2);		
	if(CRC!=wtmp)
		__sprintf_P(outtxt,pdic[26]);		
	else
	{
		wtmp=CheckCRC(2,0);
		FGet(HPLM_FLASH_START+CRC_D_LOC,(u8*)&CRC,2);	
		if(CRC!=wtmp)
			__sprintf_P(outtxt,pdic[27]);			
		else
		{
			__sprintf_P(outtxt,pdic[28]);
			FGet(HPLM_FLASH_START,outtxt,TNAME_WIDTH);
			Program_Valid=1;
		}
		
	}
}
//-----------------------------------------------------------------------------------
void params_set_default();
//-----------------------------------------------------------------------------------
void Params_Init()
{
	params_set_default();
	params_store();
}
//-----------------------------------------------------------------------------------
void mem_dump(u8 *buff,u8 len)
{
	u8 i;
//	_sprintf(outtxt,"\n\r");
	for(i=0;i<len;i++)
	{
		ByteToStr(outtxt,buff,1);
		buff++;
		__sprintf(outtxt," ");		
	}
}
//*****************************************************************************
void File_Download()
{
//	u16 CRC;	
	Program_File=Params[0];
	switch(Params[0])
	{
	case 0:
/*
		Program_Valid=0;
//		__sprintf(outtxt,pdic[3]);			
		__sprintf(outtxt,pdic[9+63]);
	//	Flash_Addr=CODE_ADDR;
		Flash_Program_Start(Flash_Addr,8*1024);
		
		Xmodem_Start();
		ctmp=XMOD_None;
		while(ctmp==XMOD_None)
		{
			ctmp=Xmodem_Processor();
		}
		Flash_Program_End();
		if(ctmp==XMOD_Ok)
		{
			__sprintf(outtxt,pdic[4+63]);
			// Check program CRC
			File_Check();
	//		Intr_IRQ0_Start();// Make IO initialisation
		}
		else
			__sprintf(outtxt,pdic[5+63]);
		break;
	
	case 1:
			AT45_Start_Write(_FILE_0);
			__sprintf(outtxt,pdic[71]);
			Xmodem_Start();
			ctmp=XMOD_None;
			while(ctmp==XMOD_None)
			{
				ctmp=Xmodem_Processor( AT45_Write);
				watchdog_reset();
			}
			switch(ctmp)
			{
				case XMOD_Ok: AT45_End_Write();__sprintf(outtxt,pdic[65]);File_Check();break;
				case XMOD_Error:while(recchar()==-1){watchdog_reset();}; __sprintf(outtxt,pdic[66]);break;
		//		case XMOD_Wrong_HW_Ver: while(recchar()==-1){watchdog_reset();};sprintf(outtxt,"\n\r Wrong HW Version! Download correct file\n\r");break;
			}						
			break;
*/	
	case 2:
#if USE_AT45_FS
//			AT45_Start_Write(_FILE_0);
			fresult = f_opendir(&g_sDirObject, "/");	
			if(fresult != FR_OK)
			{
				__sprintf(outtxt,"\n\r FS Error");
				return;
			}			
			fresult=f_open(&file,"index.htm",FA_CREATE_ALWAYS | FA_WRITE);	
			if(fresult != FR_OK)
			{
				__sprintf(outtxt,"\n\r FS open file error");
				return;
			}				
			__sprintf(outtxt,pdic[71]);
			Xmodem_Start();
			ctmp=XMOD_None;
			while(ctmp==XMOD_None)
			{
				ctmp=Xmodem_Processor(FS_Write_Buff);
				watchdog_reset();
			}
			fresult=f_close(&file);
			if(fresult != FR_OK)
			{
				__sprintf(outtxt,"\n\r FS close file error");
				return;
			}	
			switch(ctmp)
			{
				case XMOD_Ok: __sprintf(outtxt,pdic[65]);;break;
				case XMOD_Error:while(recchar()==-1){watchdog_reset();}; __sprintf(outtxt,pdic[66]);break;
			}		
#endif
			break;
		}
}
//*****************************************************************************
void FS_File_Download()
{
#if USE_AT45_FS
//	AT45_Start_Write(_FILE_0);
	fresult = f_opendir(&g_sDirObject, path);	
	if(fresult != FR_OK)
	{
		__sprintf(outtxt,"\n\r FS Error");
		return;
	}			
	fresult=f_open(&file,Params_Str[0],FA_CREATE_ALWAYS | FA_WRITE);	
	if(fresult != FR_OK)
	{
		__sprintf(outtxt,"\n\r FS open file error");
		return;
	}				
	__sprintf(outtxt,pdic[71]);
	Xmodem_Start();
	ctmp=XMOD_None;
	while(ctmp==XMOD_None)
	{
		ctmp=Xmodem_Processor(FS_Write_Buff);
		watchdog_reset();
	}
	fresult=f_close(&file);
	if(fresult != FR_OK)
	{
		__sprintf(outtxt,"\n\r FS close file error");
		return;
	}	
	switch(ctmp)
	{
		case XMOD_Ok: __sprintf(outtxt,pdic[65]);;break;
		case XMOD_Error:while(recchar()==-1){watchdog_reset();}; __sprintf(outtxt,pdic[66]);break;
	}		
#endif
}
//-----------------------------------------------------------------------------------
void FS_Check()
{
#if USE_AT45_FS
    g_bFatFsEnabled = false;
    fresult = f_mount(0, &g_sFatFs);
    if(fresult != FR_OK)
    {		
		__sprintf(outtxt,"\n\r File system Error");
        return;
    }

    fresult = f_opendir(&g_sDirObject, "/");	
    if(fresult != FR_OK)
    {
		__sprintf(outtxt,"\n\r File system Error");
        return;
    }	
	else __sprintf(outtxt,"\n\r File system Ok");
#endif
}
//-----------------------------------------------------------------------------------
void FS_Format()
{
#if USE_AT45_FS
    FRESULT fresult;
	AT45_256_Enable();
    fresult = f_mount(0, &g_sFatFs);
    if(fresult != FR_OK)
    {		
		__sprintf(outtxt,"\n\r FS format error");
        return;
    }
	fresult = f_mkfs(0,0,4);
    if(fresult != FR_OK)
    {
		__sprintf(outtxt,"\n\r FS format error");
        return;
    }	
	f_mount(0, NULL);
	__sprintf(outtxt,"\n\r FS formatted OK");
#endif
}
//-----------------------------------------------------------------------------------
void FS_Write_Buff(u8* data,u8 len)
{
#if USE_AT45_FS
	WORD wl;
	fresult=f_write(&file,data,len,&wl);
    if(fresult != FR_OK)
    {
		__sprintf(outtxt,"\n\r FS write error");
        return;
    }		
#endif
}
//-----------------------------------------------------------------------------------
void FS_Scan_Files (char* path)
{
#if USE_AT45_FS
    FILINFO finfo;
    DIR dirs;
    int i;

    if (f_opendir(&dirs, path) == FR_OK)
	{
        i = strlen(path);
        while ((f_readdir(&dirs, &finfo) == FR_OK) && finfo.fname[0])
		{
            if (finfo.fattrib & AM_DIR)
			{
                sprintf(path+i, "/%s", &finfo.fname[0]);
                FS_Scan_Files(path);
                *(path+i) = '\0';
            }
			else
			{
				__sprintf(outtxt,"\n\r");
                __sprintf(outtxt,path);
                __sprintf(outtxt,&finfo.fname[0]);
            }
        }
    }
#endif
}
//-----------------------------------------------------------------------------------
void FS_Make_Dir (char* newpath)
{
#if USE_AT45_FS
	char full[80];
	strcpy(full,&path[1]);
	stradd(full,"/");
	stradd(full,newpath);
    if(f_mkdir(full) == FR_OK)
		__sprintf(outtxt,"\n\r FS OK");
	else
		__sprintf(outtxt,"\n\r FS Error");

#endif
}
//-----------------------------------------------------------------------------------
void FS_Delete (char* name)
{
#if USE_AT45_FS
	char fullname[80];
	strcpy(fullname,path);
	stradd(fullname,"/");
	stradd(fullname,name);
	if(f_unlink(fullname) == FR_OK)
		__sprintf(outtxt,"\n\r FS OK");
	else
		__sprintf(outtxt,"\n\r FS Error");
#endif
}
//-----------------------------------------------------------------------------------
void FS_Rename (char* old, char* new)
{
#if USE_AT45_FS
	char fullname_1[80];
	char fullname_2[80];
	
	strcpy(fullname_1,path);
	stradd(fullname_1,"/");
	stradd(fullname_1,old);
	
	strcpy(fullname_2,path);
	stradd(fullname_2,"/");
	stradd(fullname_2,new);
	if (f_opendir(&g_sDirObject, path) == FR_OK)
	{
		if(f_rename(fullname_1,fullname_2) == FR_OK)
			__sprintf(outtxt,"\n\r FS OK");
		else
			__sprintf(outtxt,"\n\r FS Error");
	}
#endif
}
//-----------------------------------------------------------------------------------
void FS_Change_Dir (char* newpath)
{
#if USE_AT45_FS
	int i;
	char* ptr;
	char* ptr2;
	if(strcmp(newpath,"..")==0)
	{
		//strcpy(path,"");
		ptr2=path;
		ptr=strchr(path, '/');
		while(ptr!=NULL)
		{
			ptr2=ptr;
			ptr2++;
			ptr=strchr(ptr2, '/');
		}
		*ptr2--=0;
		*ptr2=0;
		if(f_opendir(&g_sDirObject, path) == FR_OK)
			__sprintf(outtxt,"\n\r FS OK");
		else
			__sprintf(outtxt,"\n\r FS Error");
	}
	else
	{
		if(f_opendir(&g_sDirObject, path) == FR_OK)
		{
			i = strlen(path);
			stradd(path,"/");
			stradd(path,newpath);
			__sprintf(outtxt,"\n\r FS OK");
		}
		else
		{
			__sprintf(outtxt,"\n\r FS Error");
			strcpy(path,"");
			f_opendir(&g_sDirObject, path);		
		}
	}
#endif
}
//-----------------------------------------------------------------------------------
void FS_Show_Files ()
{
#if USE_AT45_FS
	int i;
    FILINFO finfo;
	if (f_opendir(&g_sDirObject, path) == FR_OK)
	{
		__sprintf(outtxt,"\n\r");
        __sprintf(outtxt,"..");		
        __sprintf(outtxt,path);
        __sprintf(outtxt,"/");		
		
	    while ((f_readdir(&g_sDirObject, &finfo) == FR_OK) && finfo.fname[0])
		{			
            if (finfo.fattrib & AM_DIR)
			{
				__sprintf(outtxt,"\n\r");
                __sprintf(outtxt,"<DIR> ");
                __sprintf(outtxt, &finfo.fname[0]);				
            }
		}
    }
	if (f_opendir(&g_sDirObject, path) == FR_OK)
	{
	    while ((f_readdir(&g_sDirObject, &finfo) == FR_OK) && finfo.fname[0])
		{			
			if (!(finfo.fattrib & AM_DIR))
			{
				__sprintf(outtxt,"\n\r");
                __sprintf(outtxt,&finfo.fname[0]);
            }
		}
    }
#endif
}
//-----------------------------------------------------------------------------------
u8 Internal_Flash_Check_CRC(u32 ADDR)
{
	u32 len,p,Addr;
	u16 crc;
	u16 native_crc;
	u8 ctmp;

	// Header
	Addr=ADDR;
	len=CRC_H_LOC;
	InitCRC(&crc);
	for(p=0;p<len;p++)	
	{
		FGet((Addr+p),&ctmp,1);
		CalcCRC(&ctmp,1,&crc);
	}
	EndCRC(&crc);
	FGet(ADDR+CRC_H_LOC,(u8*)&native_crc,2);
	if(native_crc==crc)
	{
		// Body
		Addr=ADDR + THEAD_WIDTH;
		FGet((ADDR+LENGTH_LOC),(u8*)&len,4);
		InitCRC(&crc);
		for(p=0;p<len;p++)	
		{
			FGet((Addr+p),&ctmp,1);
			CalcCRC(&ctmp,1,&crc);
		}
		EndCRC(&crc);
		FGet(ADDR+CRC_D_LOC,(u8*)&native_crc,2);
		if(native_crc==crc)return 1; 				// All is OK
	}
	return 0;
}
//-----------------------------------------------------------------------------------
u8 FS_Flash_Check_CRC(char* name)
{
	u32 len,p,Addr;
	u16 crc;
	u16 native_crc;
	u8 ctmp;
	u32 ADDR;
	u16	rl;
	
	fresult = f_opendir(&g_sDirObject, "");	if(fresult != FR_OK) {f_close(&file);return 0;}
	fresult=f_open(&file,name,FA_OPEN_EXISTING | FA_READ);	if(fresult != FR_OK) {f_close(&file);return 0;}
	// Header
	Addr=0;
	len=CRC_H_LOC;
	InitCRC(&crc);
	for(p=0;p<len;p++)	
	{
		fresult=f_read(&file,&ctmp,1,&rl); if(fresult != FR_OK) {f_close(&file);return 0;}
		CalcCRC(&ctmp,1,&crc);
	}
	EndCRC(&crc);
	fresult=f_lseek (&file,CRC_H_LOC); if(fresult != FR_OK) {f_close(&file);return 0;}
	fresult=f_read(&file,&native_crc,2,&rl); if(fresult != FR_OK) {f_close(&file);return 0;}
	if(native_crc==crc)
	{
		// Body
		Addr=CODE_ADDR;
		fresult=f_lseek (&file,LENGTH_LOC);if(fresult != FR_OK) {f_close(&file);return 0;} 		
		fresult=f_read(&file,&len,4,&rl); if(fresult != FR_OK) {f_close(&file);return 0;}	
		fresult=f_lseek (&file,THEAD_WIDTH); if(fresult != FR_OK) {f_close(&file);return 0;}
		InitCRC(&crc);
		for(p=0;p<len;p++)	
		{
			fresult=f_read(&file,&ctmp,1,&rl);if(fresult != FR_OK) {f_close(&file);return 0;}
			CalcCRC(&ctmp,1,&crc);
		}
		EndCRC(&crc);
		fresult=f_lseek (&file,CRC_D_LOC); if(fresult != FR_OK) {f_close(&file);return 0;}
		fresult=f_read(&file,&native_crc,2,&rl); if(fresult != FR_OK) {f_close(&file);return 0;}	
		if(native_crc==crc){f_close(&file);return 1;}			
	}
	return 0;
}
//-----------------------------------------------------------------------------------
TTimeFull Get_File_Date_FS (char* name)
{
#if USE_AT45_FS
	TTimeFull Time={0,0,0,0,0,0,0};
	unsigned short rl;
	fresult = f_opendir(&g_sDirObject, "");	if(fresult != FR_OK) {f_close(&file);return Time;}
	fresult=f_open(&file,name,FA_OPEN_EXISTING | FA_READ);	if(fresult != FR_OK) {f_close(&file);return Time;}
	fresult=f_lseek (&file,TTIME_LOC); if(fresult != FR_OK) {f_close(&file);return Time;}
	fresult=f_read(&file,&Time,sizeof(Time),&rl); if(fresult != FR_OK) {f_close(&file);return Time;}
	return Time;
#endif
}
//-----------------------------------------------------------------------------------
TTimeFull Get_File_Date_FLASH (u32 ADDR)
{
	TTimeFull Time;
//	unsigned short rl;
	FGet((ADDR+TTIME_LOC),(u8*)&Time,sizeof(Time));
	return Time;
}
//-----------------------------------------------------------------------------------
u8 _Compare_Time (TTimeFull *Time_Old, TTimeFull *Time_New)
{
	u8 update_flash=0;
	if(Time_New->field.Year != Time_Old->field.Year)
	{
		if(Time_New->field.Year > Time_Old->field.Year) update_flash=1;
	}
	else
	{
		if(Time_New->field.Month != Time_Old->field.Month)
		{
			if(Time_New->field.Month > Time_Old->field.Month) update_flash=1;
		}
		else
		{
			if(Time_New->field.Date != Time_Old->field.Date)
			{
				if(Time_New->field.Date > Time_Old->field.Date) update_flash=1;
			}
			else
			{
				if(Time_New->field.Hour != Time_Old->field.Hour)
				{
					if(Time_New->field.Hour > Time_Old->field.Hour) update_flash=1;
				}
				else
				{
					if(Time_New->field.Minute != Time_Old->field.Minute)
					{
						if(Time_New->field.Minute > Time_Old->field.Minute) update_flash=1;
					}
					else
					{
						if(Time_New->field.Second != Time_Old->field.Second)
						{
							if(Time_New->field.Second > Time_Old->field.Second) update_flash=1;
						}
						
					}						
				}					
			}				
		}
	}		
	return update_flash;
}
//-----------------------------------------------------------------------------------
u8 Is_Time_Equal (TTimeFull *Time_Old, TTimeFull *Time_New)
{
	u8 update_flash=0;
	if(Time_New->field.Year != Time_Old->field.Year)
	{
		update_flash=1;
	}
	else
	{
		if(Time_New->field.Month != Time_Old->field.Month)
		{
			update_flash=1;
		}
		else
		{
			if(Time_New->field.Date != Time_Old->field.Date)
			{
				update_flash=1;
			}
			else
			{
				if(Time_New->field.Hour != Time_Old->field.Hour)
				{
					update_flash=1;
				}
				else
				{
					if(Time_New->field.Minute != Time_Old->field.Minute)
					{
						update_flash=1;
					}
					else
					{
						if(Time_New->field.Second != Time_Old->field.Second)
						{
							update_flash=1;
						}
						
					}						
				}					
			}				
		}
	}		
	return update_flash;
}
//-----------------------------------------------------------------------------------
u8 FS_Check_Sys ()
{
#if USE_AT45_FS
    int i=0;
//	int int_flash=1;
	int sys_cpu=1;
	int sys_user=1;	
	int sys_plm=1;	
	TTimeFull Time_Old={0,0,0,0,0,0,0};
	TTimeFull Time_New={0,0,0,0,0,0,0};
	// Checking internal flash memory
	__sprintf(outtxt,"\n\r Checking internal flash memory");
	if(Internal_Flash_Check_CRC(HAPP_FLASH_START))
	{
		__sprintf(outtxt,"\n\r   CPU software CRC OK");
	}
	else
	{
		__sprintf(outtxt,"\n\r   CPU software CRC BAD");
		sys_cpu=0;
//		int_flash=0;
	}
#if USING_USER	
	if(Internal_Flash_Check_CRC(HPLM_FLASH_START))
	{
		__sprintf(outtxt,"\n\r   USER software CRC OK");
	}
	else
	{
		__sprintf(outtxt,"\n\r   USER software CRC BAD");
		sys_user=0;
//		int_flash=0;
	}
#endif	
	
	// Checking external flash memory
	__sprintf(outtxt,"\n\r Checking external flash memory");
	fresult = f_opendir(&g_sDirObject, "/");	
	if(fresult != FR_OK)
	{
		__sprintf(outtxt,"\n\r   FS Error");
		return 0;
	}			
	i=0;
	
	// CPU File	
	fresult=f_open(&file,"sys_cpu.bin",FA_OPEN_EXISTING | FA_READ);	
	if(fresult != FR_OK)
	{
		__sprintf(outtxt,"\n\r   FLASH CPU image missing");
		f_close(&file);
//		if (sys_cpu == 0)
//			return 0;  															// Critical issue
	}
	else
	{
		//*** Checking CRC ***
		if(FS_Flash_Check_CRC("sys_cpu.bin"))
		{
			__sprintf((u8*)outtxt,"\n\r   CPU Image OK");	
			// Is update is necessarry
//			__sprintf(outtxt,"\n\r Checking update need");
			Time_New = Get_File_Date_FS ("sys_cpu.bin");
			Time_Old = Get_File_Date_FLASH (HAPP_FLASH_START);
			if((Is_Time_Equal (&Time_Old, &Time_New))||(sys_cpu==0))
			{
				__sprintf(outtxt,"\n\r   Newer CPU software present, updating");
				ReProgramm("sys_cpu.bin");
				sys_cpu=1;
			}
		}
		else
		{
			__sprintf((u8*)outtxt,"\n\r   CPU Image ERROR");		
//			return 0;
		}
	}
	i |= 0x01;
	
	// PLM File	
#if USING_PLM	
	fresult=f_open(&file,"sys_plm.bin",FA_OPEN_EXISTING | FA_READ);	
	if(fresult != FR_OK)
	{
		__sprintf(outtxt,"\n\r   FLASH PLM image missing");
		f_close(&file);
		return 0;	// Critical issue
	}
	else
	{
		// Checking CRC
		if(FS_Flash_Check_CRC("sys_plm.bin"))
			__sprintf((u8*)outtxt,"\n\r   PLM Image OK");			
		else
		{
			__sprintf((u8*)outtxt,"\n\r   PLM Image ERROR");		
			return 0;
		}	
	}
	i |= 0x02;
#endif
	
	
	// USER File
#if USING_USER	
	fresult=f_open(&file,"sys_user.bin",FA_OPEN_EXISTING | FA_READ);	
	if(fresult != FR_OK)
	{
		__sprintf(outtxt,"\n\r   USER image missing");
		f_close(&file);
//		if (sys_user == 0)
//			return 0;  															// Critical issue
	}	
	else
	{
		if(FS_Flash_Check_CRC("sys_user.bin"))
		{
			__sprintf((u8*)outtxt,"\n\r   USER Image OK");	
			// Checking update necessary
			Time_New = Get_File_Date_FS ("sys_user.bin");
			Time_Old = Get_File_Date_FLASH (HPLM_FLASH_START);
			if((Is_Time_Equal (&Time_Old, &Time_New))||(sys_user==0))
			{
				__sprintf(outtxt,"\n\r   Newer USER software present, updating");
				ReProgramm("sys_user.bin");
				sys_user=1;
			}
		}
		else
		{
			__sprintf((u8*)outtxt,"\n\r   USER Image ERROR");		
//			return 0;
		}	
	}
	i |= 0x04;	
#endif
	if (sys_cpu == 0)  return 0;
#if USING_USER	
     if (sys_user == 0)  return 0;
#endif	
	return 1;
#endif	
}
//-----------------------------------------------------------------------------------
u8 ReProgramm(char* name)
{
	u32 Start_Addr;
	u32 End_Addr;	
	u32 len;	
	u32 i;	
	u32 p;
	u16	rl;
	FILINFO st;
	u8 buff[128];

//	BLInternalFlashInit();
	fresult = f_opendir(&g_sDirObject, "");	if(fresult != FR_OK) {f_close(&file);return 0;}
	fresult=f_stat(name,&st);if(fresult != FR_OK) {f_close(&file);return 0;}
	len=st.fsize;

	Start_Addr=0;
	if(strcmp(name,"sys_cpu.bin")==0) {Start_Addr=HAPP_FLASH_START; End_Addr=HPLM_FLASH_START;}
	if(strcmp(name,"sys_plm.bin")==0)return 0; // No actions
	if(strcmp(name,"sys_user.bin")==0){Start_Addr=HPLM_FLASH_START; End_Addr=APP_FLASH_END;}
	if(Start_Addr==0)return 0; // Wrong name
	// Erase    FLASH
	for(i=Start_Addr;i<End_Addr;i+=1024)
		BLInternalFlashErase(i);
	// Programm FLASH
	fresult=f_open(&file,name,FA_OPEN_EXISTING | FA_READ);	if(fresult != FR_OK) {f_close(&file);return 0;}
	for(p=0;p<len;p+=128)	
	{
		fresult=f_read(&file,buff,128,&rl);if(fresult != FR_OK) {f_close(&file);return 0;}
		BLInternalFlashProgram(p+Start_Addr, buff,128);
		
	}
	f_close(&file);
	return 0;
}
//-----------------------------------------------------------------------------------
