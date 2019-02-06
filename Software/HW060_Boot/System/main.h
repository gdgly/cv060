//------------------------------------------------------------------------------
// Sourse EL programmable controller V031
//------------------------------------------------------------------------------
#ifndef __MAIN_H
#define __MAIN_H
//------------------------------------------------------------------------------
#include <string.h>
//------------------------------------------------------------------------------
#include "Misc/types.h"
#include "define.h"
#include "controller_data_define.h"
#include "Buffer/buffer.h"
//------------------------------------------------------------------------------
#ifdef __HW060
	#include "Hardware_Stellaris\EL\functions.h"
	#include "Hardware_Stellaris\EL\lcd.h"
//	#include "Hardware_Stellaris\EL\I2C\i2c.h"
//	#include "..\Custom\HW060\Hardware\pinout.h"
//	#include "..\Custom\HW060\Hardware\io.h"
//	#include "..\Custom\HW060\LCD_Menu\menu.h"
#endif

#include "Console\console.h"
#include "Console\str.h"
#include "Timer\timer16.h"
#include "Memory\fram31xx.h"
#include "Memory\eep.h"
#include "Pid\pid.h"

#ifdef __COMPILER2
	#include "Compiler2\Compiler2.h"
#else
	#include "Compiler\Compiler.h"
#endif

#include "IO\adc.h"
#include "TMP441\TMP441.h"

#include "Xmodem\xmodem.h"
#include "Service\plm.h"
#include "Misc\header.h"

#include "Misc\crc.h"
#include "AT45\AT45_256.h"
//#include "math.h"
//#include "can.h"
//#include <ctype.h>
#include "Service\errors.h"
#include "RS485_Slave\uart_misc.h"
#include "RS485_Slave\uart_protocol.h"

//#include "Buffer/buffer.h"
//#include "protection.h"
//------------------------------------------------------------------------------
//#define _SEASON_DATE
//------------------------------------------------------------------------------
// Parameters record
//------------------------------------------------------------------------------
#define PARAM_RECORDS  		1

#define PARAM_LOCATION_0 	0x0000
#define PARAM_LOCATION_1 	0x0100
#define TPARAM_WIDTH 		sizeof(TParam)
//------------------------------------------------------------------------------
typedef __packed struct
{
	TController	CV;
	u16 CRC;
}TParam;
//------------------------------------------------------------------------------
extern TController CV;
//------------------------------------------------------------------------------
//static TController CV;
//------------------------------------------------------------------------------
extern in_flash u8	mdic[][80];
//------------------------------------------------------------------------------
eu8 Cycle;
eu16 Error_Code;
//extern TParam DevParams;
eu8 Flag;
eu8 Test_Mode;
eu8 To_Store;
//-----------------------------------------------------------------------------------
//extern TIO io;
//extern TPID pid[NUM_PID];
extern TInterpretatorRegisters intr;
//extern TErrors errors;

extern char update_ip_address;
extern char update_mask_address;
extern char update_gw_address;

extern unsigned long new_ip;
extern unsigned long new_mask;
extern unsigned long new_gw;	

#define IP4_ADDR_MAKE(ipaddr, a,b,c,d) \
                ipaddr =      (((unsigned long)((a) & 0xff) << 24) | \
                               ((unsigned long)((b) & 0xff) << 16) | \
                               ((unsigned long)((c) & 0xff) << 8) | \
                                (unsigned long)((d) & 0xff))
//------------------------------------------------------------------------------
void params_store();
void params_load();
void cycle_handler();
void task_handler(u8 Command, u16 Parameter);
void Immediately_DO();
void idle();
void init();
void id_store();
void id_read();
void id_show();
//------------------------------------------------------------------------------
#endif
