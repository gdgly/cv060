//-----------------------------------------------------------------------------------
#include "main.h"
//-----------------------------------------------------------------------------------

void DS1337_init()	// Must be done once
{	
#if DS1337_ENABLE	

#endif	
}

//-----------------------------------------------------------------------------------

void DS1337_comp_write(u8 addr,u8* data, u16 len)
{
#if DS1337_ENABLE	
	u8	Addr[2];
	Addr[0]=addr;
	Addr[1]=0;	
	I2C_NiMasterWrite(0xd0,Addr,1,data,len);
#endif		
}

//-----------------------------------------------------------------------------------

void DS1337_comp_read(u8 addr,u8* data, u16 len)
{
#if DS1337_ENABLE	
	u8	Addr[2];
	Addr[0]=addr;
	Addr[1]=0;	
	I2C_NiMasterRead(0xd0,Addr,1,data,len);	
#endif		
}

//-----------------------------------------------------------------------------------

void DS1337_comp_read_no_int(u8 addr,u8* data, u16 len)
{
#if DS1337_ENABLE		
	u8	Addr[2];	
	Addr[0]=addr;
	Addr[1]=0;	
	I2C_NiMasterRead_NoInt(0xd0,Addr,1,data,len);	
#endif		
}

//-----------------------------------------------------------------------------------

void DS1337_set_time(u8 hour,u8 minute,u8 second)
{
#if DS1337_ENABLE	
	u8 tmp,bcbh,bcbl,d[3];
	bcbh=hour/10;
	bcbl=hour-bcbh*10;
	hour=bcbh;
	hour=hour<<4;
	hour|=bcbl;	

	bcbh=minute/10;
	bcbl=minute-bcbh*10;
	minute=bcbh;
	minute=minute<<4;
	minute|=bcbl;	

	bcbh=second/10;
	bcbl=second-bcbh*10;
	second=bcbh;
	second=second<<4;
	second|=bcbl;	

	d[0]=second;
	d[1]=minute;
	d[2]=hour;

//	tmp=fram_W;	// Write enable
//	DS1337_comp_write(fram_reg_RTC_Control,&tmp,1);	
	
	DS1337_comp_write(DS1337_reg_Second,d,3);
	
	d[0] = 0x18;
	DS1337_comp_write(DS1337_reg_CR,d,1);
//	tmp=0;	// Write disable
//	DS1337_comp_write(fram_reg_RTC_Control,&tmp,1);	
#endif		
}

//-----------------------------------------------------------------------------------

void DS1337_set_date(u8 year,u8 month, u8 date,u8 day)
{
#if DS1337_ENABLE	
	u8 tmp,bcbh,bcbl,d[4];
	
	if(year>99)year=0;
	if(month>12)month=0;
	if(date>31)date=0;
	if(day>7)day=0;
				
	bcbh=year/10;
	bcbl=year-bcbh*10;
	year=bcbh;
	year=year<<4;
	year|=bcbl;	

	bcbh=month/10;
	bcbl=month-bcbh*10;
	month=bcbh;
	month=month<<4;
	month|=bcbl;	

	bcbh=date/10;
	bcbl=date-bcbh*10;
	date=bcbh;
	date=date<<4;
	date|=bcbl;	

	d[0]=day;
	d[1]=date;
	d[2]=month;
	d[3]=year;
				
//	tmp=fram_W;	// Write enable
//	fram_comp_write(fram_reg_RTC_Control,&tmp,1);	
	DS1337_comp_write(DS1337_reg_Day,d,4);		
	d[0] = 0x18;
	DS1337_comp_write(DS1337_reg_CR,d,1);	
//	tmp=0;	// Write disable
//	fram_comp_write(fram_reg_RTC_Control,&tmp,1);
#endif	
}


//-----------------------------------------------------------------------------------

void DS1337_get_time(TCTime *time)
{
#if DS1337_ENABLE	
	TCTime	ft;
	u8 tmp;//,bcbh,bcbl;
	u8 buff[5]={0xf0,0xff,0x0f,0x55,0x01};
	//I2C_NiMasterWrite(0xD2,buff,5,NULL,0);
	//return;
//	tmp=fram_R;	// Read enable
//	fram_comp_write(fram_reg_RTC_Control,&tmp,1);	
	DS1337_comp_read(DS1337_reg_Second,&ft.field.Second,7);
//	tmp=0;		// Read disable
//	fram_comp_write(fram_reg_RTC_Control,&tmp,1);		
	
	tmp=ft.field.Second>>4;tmp*=10;tmp+=ft.field.Second&0x0f;ft.field.Second=tmp;
	tmp=ft.field.Minute>>4;tmp*=10;tmp+=ft.field.Minute&0x0f;ft.field.Minute=tmp;
	tmp=ft.field.Hour>>4;tmp*=10;tmp+=ft.field.Hour&0x0f;ft.field.Hour=tmp;
	tmp=ft.field.Day>>4;tmp*=10;tmp+=ft.field.Day&0x0f;ft.field.Day=tmp;
	tmp=ft.field.Date>>4;tmp*=10;tmp+=ft.field.Date&0x0f;ft.field.Date=tmp;
	tmp=ft.field.Month>>4;tmp*=10;tmp+=ft.field.Month&0x0f;ft.field.Month=tmp;
	tmp=ft.field.Year>>4;tmp*=10;tmp+=ft.field.Year&0x0f;ft.field.Year=tmp;		
	*time=ft;
#endif	
}
//-----------------------------------------------------------------------------------
