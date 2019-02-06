#ifndef __DS1337
#define __DS1337
//-----------------------------------------------------------------------------------
#include "define.h"
#include "controller_data_define.h"
//-----------------------------------------------------------------------------------

#define DS1337_reg_Year					 		0x06
#define DS1337_reg_Month					 	0x05
#define DS1337_reg_Date					 		0x04
#define DS1337_reg_Day					 		0x03
#define DS1337_reg_Hour					 		0x02
#define DS1337_reg_Minute					 	0x01
#define DS1337_reg_Second					 	0x00

#define DS1337_reg_CR						 	0x0E

#define DS1337_reg_Control					 	0x0E
	#define bit_dsc_EOSC						0x80
	#define bit_dsc_RS2							0x10
	#define bit_dsc_RS1							0x08
	#define bit_dsc_INTC						0x04
	#define bit_dsc_A2IE						0x02
	#define bit_dsc_A1IE						0x01

#define DS1337_reg_Status					 	0x0F
	#define bit_dsc_OSF							0x80
	#define bit_dsc_A2F							0x02
	#define bit_dsc_A1F							0x01
//-----------------------------------------------------------------------------------
//u32 CheckCRC(u8 who);
void DS1337_init();
void DS1337_set_time(u8 hour,u8 minute,u8 second);
void DS1337_set_date(u8 year,u8 month, u8 date,u8 day);
void DS1337_get_time(TCTime *time);
//-----------------------------------------------------------------------------------
#endif
