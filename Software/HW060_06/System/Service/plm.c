#include "main.h"
#include "ff.h"            /* FatFs declarations */
#include <stdio.h>
//-----------------------------------------------------------------------------------
extern tBoolean IntMasterEnable(void);
extern tBoolean IntMasterDisable(void);

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
	"\n\r     Analog noise  \n\r       ",	//75
	"\n\r   Net params block ",				//76
	"\n\r Serial ID ",					//77	
	//	txt,		//33
};
//-----------------------------------------------------------------------------------
void mem_dump(u8 *buff,u8 len);
void File_Check();
void FS_Scan_Files (char* path);
void io_io_set();
//-----------------------------------------------------------------------------------
void Mod_Store_Parameters()
{
	IntMasterDisable();
	params_store();
	IntMasterEnable();
	__sprintf_P(outtxt,pdic[1]);	
}
//-----------------------------------------------------------------------------------
void Mod_Store_Full_Parameters()
{
	IntMasterDisable();
	full_params_store();
	IntMasterEnable();
	__sprintf_P(outtxt,pdic[1]);	
}
//-----------------------------------------------------------------------------------
static volatile u8 g_bFatFsEnabled = false;	
#include "lwip/def.h"
#include "lwip/mem.h"
#include "lwip/sys.h"
#include "lwip/stats.h"

eu8 Params_Count;
eu32 Params[5];
void Mod_Test()
{
//	u8	tmp;
//	pid_handle();
//	__sprintf_P(outtxt,pdic[2]);		
//	Production_Test();
	extern u32 HW_in;
	extern u32 HW;
	
	//restore_ip_core_init();
//	strcpy (ExtCV.ip_str, "192.168.1.100");
//	strcpy (ExtCV.mask_str, "255.255.255.0");
//	strcpy (ExtCV.gw_str, "192.168.1.1");
//	strcpy (ExtCV.mac_str, "4f.19.00.78.99.d2");
//	nvar_store("conf_str.cfg");
//	ByteToStr(outtxt,&Params_Count,0);
//	__sprintf(outtxt,"\n\r");
//	LongToStr(outtxt,&Params[0],0);
//	return;
	u8	*ptr;
	u32 i;
	u32 res;
//	BuzzerTime=100;
//	CV.d[0]=0x55;
//	fram_params_store(PARAM_LOCATION_0);
//	tx_mode();
//	upc_tx_byte('*');
//	while(1){};
	for(i=1;i<100;i++)
	{
		ptr = (u8*)mem_malloc(1024*i);
		if(ptr==NULL)
		{
			__sprintf(outtxt,"\n\r Free mem size is ");
			res=i;
			LongToStr(outtxt,&res,0);	
			return;			
		}
		mem_free(ptr);
			
	}
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

/*
	AT45_Init();
	if(AT45_256_Enable())
	{
		__sprintf(outtxt,"\n\r AT45 256 bytes configured");
	}
	else
	{
		__sprintf(outtxt,"\n\r AT45 264 bytes configured");
	}
	return;
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
	return;
*/
//	f_mkfs();
//	path[0]=0;
//	FS_Scan_Files (path);
	//io_init();
//	Delay(1000);
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
				if(j==2)		
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
	
	__sprintf(outtxt,"\n\r ");
	ByteToStrFillZero(outtxt,&ft.field.Date,0,2,'0');
	__sprintf(outtxt," ");
	__sprintf_P(outtxt,Monthes_Name[ft.field.Month-1]);
	__sprintf(outtxt," 20");
	ByteToStrFillZero(outtxt,&ft.field.Year,0,2,'0');
	__sprintf(outtxt,", ");
	__sprintf_P(outtxt,DaysOfWeek[ft.field.Day-1]);	
				
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
	Mod_Show_Full_Time(&MenuRegs.Time);
	__sprintf_P(outtxt,pdic[45]);ByteToStr(outtxt,&ID[0],0);
	__sprintf((u8*)outtxt,".");ByteToStr(outtxt,&ID[1],0);
	__sprintf((u8*)outtxt,".");ByteToStr(outtxt,&ID[2],0);
	__sprintf((u8*)outtxt,".");ByteToStr(outtxt,&ID[3],0);	
	__sprintf_P((u8*)outtxt,pdic[77]);ByteToStr(outtxt,&ExtCV.ser_id,0);	
//	Mod_Show_Full_Time(&MenuRegs.Time_Summ);
//	Mod_Show_Full_Time(&MenuRegs.Time_Wint);
//	__sprintf_P(outtxt,pdic[32]);ShowTemperatureShort(outtxt,&input_voltage);__sprintf(outtxt,"V");
	__sprintf_P(outtxt,pdic[42]);
	if(reg_season.season==SEASON_SUMMER)__sprintf_P(outtxt,pdic[43]);
	else __sprintf_P(outtxt,pdic[44]);	
	__sprintf_P(outtxt,pdic[3]);
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
	
	__sprintf_P(outtxt,pdic[8]);	
	for(j=0;j<NUM_AOUT;j++)
	{
		ShowPowerShort(outtxt,(s16*)&io.aoutput[j]);
		__sprintf(outtxt," "); 			
	}
	
	// AI Noise
	__sprintf_P(outtxt,pdic[75]);	
	for(j=0;j<NUM_AIN;j++)
	{
		wtmp = adc_get_deviation(j);
		ShowTemperature(outtxt,&wtmp);				
		__sprintf(outtxt," "); 			
	}
}
//-----------------------------------------------------------------------------------
void Mod_Show_Param()
{
	u8 j, i;
#if MAX_PARAMS_BLOCK	
	__sprintf_P(outtxt,pdic[63]);	
	__sprintf_P(outtxt,pdic[49]);	
	__sprintf(outtxt, "\n\r Max parameters number ");
	i = MAX_PARAMS_NUM;
	ByteToStr(outtxt, (u8*)&i, 0);
	__sprintf(outtxt,"\n\r");
	
	for (i=0;i<5;i++){
		for (j=0;j<10;j++){	
			if ((i*10 + j) > MAX_PARAMS_NUM) return;
			IntToStrFillZero(outtxt,(u32*)&misc.pr[j + i*10],0,5,5,1);		
			__sprintf(outtxt," ");
		}	
		__sprintf(outtxt,"\n\r");
	}
#endif	
}
//-----------------------------------------------------------------------------------
void Mod_Show_Net_Param()
{
	u8 j, i;
#if NET_PARAMETERS_MAX	
	__sprintf_P(outtxt,pdic[76]);	
	__sprintf_P(outtxt,pdic[49]);	
	__sprintf(outtxt, "\n\r Max net parameters number ");
	i = NET_PARAMETERS_MAX;
	ByteToStr(outtxt, (u8*)&i, 0);
	__sprintf(outtxt,"\n\r");
	
	for (i=0;i<5;i++){
		for (j=0;j<10;j++){	
			if ((i*10 + j) > NET_PARAMETERS_MAX) return;
			IntToStrFillZero(outtxt,(u32*)&net_params[j + i*10],0,5,5,1);		
			__sprintf(outtxt," ");
		}	
		__sprintf(outtxt,"\n\r");
	}
#endif	
}
//-----------------------------------------------------------------------------------
void Mod_Show_Timers()
{
	u8 j;
	__sprintf_P(outtxt,pdic[51]);
	for(j=0;j<TIMERS_MAX;j++)
	{
		if((j & 0x07)==0x00)__sprintf_P(outtxt,pdic[49]);						
		IntToStrFillZero(outtxt,(u32*)&intr.t32[j],1,8,3,0);			
		__sprintf(outtxt," "); 			
	}		
}
//-----------------------------------------------------------------------------------
void Mod_Show_Registers()
{
	u8 j;
	__sprintf_P(outtxt,pdic[50]);
	for(j=0;j<REGISTERS_MAX;j++)
	{
		if((j & 0x07)==0x00)__sprintf_P(outtxt,pdic[49]);				
		IntToStrFillZero(outtxt,(u32*)&intr.reg[j],1,8,3,0);	
		__sprintf(outtxt," "); 			
	}	
}
//-----------------------------------------------------------------------------------
void Mod_Show_Status_Prog()
{
	u8 j;
//	u16 t;
	// Program state
	__sprintf_P(outtxt,pdic[12]);		
	if(intr.status==program_run)
		__sprintf_P(outtxt,pdic[13]);		
	if(intr.status==program_stop)
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
	Mod_Show_Status_IO();
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
		Delay(100);
		adc_conversion();
		for(i=0;i<NUM_AIN_REAL;i++)	
		{
			//Delay(100);
//			Adc_Time=100;
//			while(Adc_Time!=0){};
			Delay_mks(0x8fff);
			adc_conversion();
			point_real_temperature[(u8)Params[0]][i]=ad_res;
			adc_set_channel(i+1);	
			ShowTemperature(outtxt,&point_real_temperature[(u8)Params[0]][i]);__sprintf(outtxt,"  ");			
		}
	}
	// Make point 2 calculations >  cofficients + offsets
	if((Params[0]==1))
	{	
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
//			Delay(100);
//			Adc_Time=100;
//			while(Adc_Time!=0){};
			Delay_mks(0x8fff);
			adc_conversion();
			point_real_temperature[0][i] = (s16) ((f32)ad_res * io.ai_coff[i]);
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
void Calibrate_Single()
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
			point_real_temperature[0][i]=(s16) ((f32)ad_res * io.ai_coff[i]);
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
//	if(Params[0]>=NUM_AIN_REAL)
//	{
//		__sprintf_P(outtxt,pdic[38]);	
//		return;
//	}
	io.ai_coff[Params[0]]=0.1;
	io.ai_offset[Params[0]]=0;	
}
//-----------------------------------------------------------------------------------
void Set_AI_Filter()
{
	if (Params[0] < NUM_AIN_REAL){
		ExtCV.adc_filter_time[Params[0]] = Params[1]; 	
	}
}
//-----------------------------------------------------------------------------------
void Set_Date()
{
//	fram_set_time(u8 hour,u8 minute,u8 second)
//	fram_set_date(u8 year,u8 month, u8 date,u8 day)	
	fram_set_date((u8)Params[2],(u8)Params[1],(u8)Params[0],1);
	DS1337_set_date((u8)Params[2],(u8)Params[1],(u8)Params[0],1);
}
//-----------------------------------------------------------------------------------
void Set_Time()
{
//	Vacuum.analog=Params[0];
	fram_set_time((u8)Params[0],(u8)Params[1],(u8)Params[2]);
	DS1337_set_time((u8)Params[0],(u8)Params[1],(u8)Params[2]);
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
void set_serial_id()
{
	ExtCV.ser_id = Params[0];
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
	IntMasterDisable();
	params_set_default();
	params_store();
	IntMasterEnable();
}
//-----------------------------------------------------------------------------------
void Set_DO()
{
	if((Params[0]<NUM_DOUT))
	{
		if(Params[1])	io.dout |= 1 << Params[0];
		else 			io.dout &= ~( 1 << Params[0]);
	}
	else
		__sprintf(outtxt,"\n\r Wrong DO number");
}
//-----------------------------------------------------------------------------------
void Set_AO()
{
	if((Params[0]<NUM_AOUT))
	{
		io.aoutput[Params[0]]=Params[1];
	}
	else
		__sprintf(outtxt,"\n\r Wrong AO number");
}
//-----------------------------------------------------------------------------------
void Set_Param()
{
	if((Params[0] < MAX_PARAMS_NUM))
	{
		 misc.pr[Params[0]] = Params[1];
	}
	else
		__sprintf(outtxt,"\n\r Wrong Param number");
}
//-----------------------------------------------------------------------------------
void Set_Net_Param()
{
	if((Params[0] < NET_PARAMETERS_MAX))
	{
		//net_params[Params[0]] = Params[1];
		regs_set(Params[0], Params[1]);
	}
	else
		__sprintf(outtxt,"\n\r Wrong Param number");
}
//-----------------------------------------------------------------------------------
void Toggle_Program_Mode()
{
	if(MenuRegs.Manual_Mode == MANUAL_MODE)
		MenuRegs.Manual_Mode = AUTO_MODE;
	else
		MenuRegs.Manual_Mode = MANUAL_MODE;
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
	fresult=f_open(&file, (char*)Params_Str[0],FA_CREATE_ALWAYS | FA_WRITE);	
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
//*****************************************************************************
// who-5 Params fields in eep
u32 _CheckCRC(u8 who,u16 PARAM_LOCATION)
{
	u32 len,p,Addr,d;
	u16 crc;
	u8 ctmp;
	u8 buff[64];
	switch(who)
	{
		// Main program header
		case 1:
			Addr=HAPP_FLASH_START;
			len=CRC_H_LOC;
			InitCRC(&crc);
			for(p=0;p<len;p++)	
			{
				ctmp=*(u8*)(Addr+p);
				CalcCRC(&ctmp,1,&crc);
			}
			EndCRC(&crc);
		break;
		// Main program body
		case 2:		
			Addr=APP_FLASH_START;
			len=*(u32*)(HAPP_FLASH_START+LENGTH_LOC);
			InitCRC(&crc);
			for(p=0;p<len;p++)	
			{
				ctmp=*(u8*)(Addr+p);
				CalcCRC(&ctmp,1,&crc);
			}
			EndCRC(&crc);
		break; 		
		// PLM program header
		case 3:
			Addr=_FILE_0;
			len=CRC_H_LOC;
			InitCRC(&crc);
			for(p=0;p<len;p++)	
			{
				watchdog_reset();
				AT45_Read((Addr+p),(u8*)&ctmp,1);
				CalcCRC(&ctmp,1,&crc);
			}
			EndCRC(&crc);
		break;
		// PLM program body
		case 4:		
//			Addr=_FILE_0;
			AT45_Read((_FILE_0+LENGTH_LOC),(u8*)&len,4);
			InitCRC(&crc);
			for(p=0;p<len;p=p+64)	
			{
//				watchdog_reset();
				AT45_Read((_FILE_0+THEAD_WIDTH+p),(u8*)&buff[0],64);
				d=len-p;
				if(d>=64)
				{
					CalcCRC(&buff[0],64,&crc);
				}
				else
				{
					CalcCRC(&buff[0],d,&crc);
				}
			}
			
			EndCRC(&crc);
		break; 		
	 }
	return crc;
}
//*****************************************************************************
void File_Check()
{
	u16 CRC;
	u16 wtmp;
	Program_Valid=0;
/*
	// Check program CRC
	wtmp=_CheckCRC(1,0);
	CRC=*(u16*)(HAPP_FLASH_START+CRC_H_LOC);
	if(CRC!=wtmp)
		__sprintf(outtxt,pdic[6]);		
	else
	{
		wtmp=_CheckCRC(2,0);
		CRC=*(u16*)(HAPP_FLASH_START+CRC_D_LOC);
//		WordToStr(outtxt,&wtmp,1);__sprintf(outtxt," ");		
//		WordToStr(outtxt,&CRC,1);__sprintf(outtxt," ");	
		if(CRC!=wtmp)
			__sprintf(outtxt,pdic[7]);			
		else
		{
			__sprintf(outtxt,pdic[8]);
			strcpy2(outtxt,(u8*)HAPP_FLASH_START);
			Program_Valid=1;
		}
		
	}
*/	
//wait_con_free();
//	AT45_Read((_FILE_0),outtxt,60);		
//	wait_con_free();
	// Check PLM program CRC
	wtmp=_CheckCRC(3,0);
//	CRC=*(u16*)(HAPP_FLASH_START+CRC_H_LOC);
	AT45_Read((_FILE_0+CRC_H_LOC),(u8*)&CRC,2);
	if(CRC!=wtmp)
		__sprintf(outtxt,pdic[73]);		
	else
	{
		wtmp=_CheckCRC(4,0);
//		CRC=*(u16*)(HAPP_FLASH_START+CRC_D_LOC);
		AT45_Read((_FILE_0+CRC_D_LOC),(u8*)&CRC,2);
//		WordToStr(outtxt,&wtmp,1);__sprintf(outtxt," ");		
//		WordToStr(outtxt,&CRC,1);__sprintf(outtxt," ");	
		if(CRC!=wtmp)
			__sprintf(outtxt,pdic[73]);			
		else
		{
			__sprintf(outtxt,pdic[74]);
			//strcpy2(outtxt,(u8*)HAPP_FLASH_START);
			AT45_Read((_FILE_0),outtxt,60);
			Program_Valid=1;
		}
		
	}
}
//-----------------------------------------------------------------------------------
bool FS_File_Check(char* name)
{
	FILINFO finfo;
	fresult = f_opendir(&g_sDirObject, "");						if(fresult != FR_OK) {f_close(&file);return false;}
	fresult = f_open(&file,name,FA_OPEN_EXISTING | FA_READ);	if(fresult != FR_OK) {f_close(&file);return false;}
	fresult = f_stat(name,&finfo);  							if(fresult != FR_OK) {f_close(&file);return false;}
	if (finfo.fsize == 0) 										{f_close(&file);return false;}
	f_close(&file);
	return true;
}
//-----------------------------------------------------------------------------------
void FS_Check()
{
#if USE_AT45_FS
    g_bFatFsEnabled = false;
    fresult = f_mount(0, &g_sFatFs);
    if(fresult != FR_OK)
    {		
		__sprintf(outtxt,"\n\r FS Error");
        return;
    }

    fresult = f_opendir(&g_sDirObject, "/");	
    if(fresult != FR_OK)
    {
		__sprintf(outtxt,"\n\r FS Error");
        return;
    }	
	else __sprintf(outtxt,"\n\r FS Ok");
#endif
}
//-----------------------------------------------------------------------------------
void FS_Format()
{
#if USE_AT45_FS
    FRESULT fresult;
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
                sprintf(path+i, "/%s", (char*)&finfo.fname[0]);
                FS_Scan_Files(path);
                *(path+i) = '\0';
            }
			else
			{
				__sprintf(outtxt,"\n\r");
                __sprintf(outtxt,(u8*)path);
                __sprintf(outtxt,(u8*)&finfo.fname[0]);
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
	strcpy((char*)full,&path[1]);
	strcat(full,"/");
	strcat(full,newpath);
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
	strcat(fullname,"/");
	strcat(fullname, name);
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
	strcat(fullname_1,"/");
	strcat(fullname_1,old);
	
	strcpy(fullname_2,path);
	strcat(fullname_2,"/");
	strcat(fullname_2,new);
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
	//int i;
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
			//i = strlen(path);
			strcat(path,"/");
			strcat(path,newpath);
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
	//int i;
    FILINFO finfo;
	if (f_opendir(&g_sDirObject, path) == FR_OK)
	{
		__sprintf(outtxt,"\n\r");
        __sprintf(outtxt,"..");		
        __sprintf(outtxt,(u8*)path);
        __sprintf(outtxt,"/");		
		
	    while ((f_readdir(&g_sDirObject, &finfo) == FR_OK) && finfo.fname[0])
		{			
            if (finfo.fattrib & AM_DIR)
			{
				__sprintf(outtxt,"\n\r");
                __sprintf(outtxt,"<DIR> ");
                __sprintf(outtxt, (u8*)&finfo.fname[0]);				
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
                __sprintf(outtxt,(u8*)&finfo.fname[0]);
            }
		}
    }
//	__sprintf(outtxt,"\n\r");
#endif
}
/*
void LWIP_DEBUGF(u8 type,const char * __format, ...)
{
	va_list 	argList;

    va_startva_start(argList, __format);
	size_t stackSize = 2000;
	int *newstack = (int*)alloca(stackSize);
	memcpy(newstack, argList, stackSize);
	sprinf(outtxt,__format);
	va_end(argList);
	wait_con_free();	
}
*/
//-----------------------------------------------------------------------------------

//char* fgets(char* line, int n, FILE* file)
//{
//}

//-----------------------------------------------------------------------------------
