#ifndef _DATA_DEFINES_H_
#define _DATA_DEFINES_H_
//------------------------------------------------------------------------------
#include "Misc/Types.h"
//------------------------------------------------------------------------------
//#define __DEBUG
#define __RELEASE
//------------------------------------------------------------------------------
// System settings
//------------------------------------------------------------------------------
#define 	LCD_ENABLE			0
#define 	FRAM_ENABLE			0
#define 	DS1337_ENABLE		0
#define 	ADC_ENABLE			1
#define 	TMP441_ENABLE		0
#define 	USE_AT45			1
#define 	USE_AT45_FS			1
#define 	WHATCHDOG          	0
#define 	LED_BOARD          	0
#define 	RS232_CONSOLE		1
#define 	INI_FILE			1
//------------------------------------------------------------------------------
// PID settings
//------------------------------------------------------------------------------
//#define __PID_ALGORITHM_ALT
#define 	__VALVE_ALGORITHM_MOVE_AT_END
#define		PID_CYCLE_TIME		500
//------------------------------------------------------------------------------
// IP settings
//------------------------------------------------------------------------------
#define 	__MODBUS_CLOSE_PORT		
//#define 	__IP_SILENCE_RESET
#define		__IP_SILENCE_RECOVER
//------------------------------------------------------------------------------
// NET Registers settings
//------------------------------------------------------------------------------
#define 	NET_PARAMETERS_MAX			50
#define 	__UDP_NET_REGS_PORT 		5555
#define 	__UDP_NET_REGS_PACKET_LEN	(NET_PARAMETERS_MAX * 2)

typedef __packed struct{
	unsigned short 	number;
	short 			value;			
}TNetReg;
//------------------------------------------------------------------------------
// ADC settings
//------------------------------------------------------------------------------
//#define 	__NO_ADC
#define 	ADC_SAMPLE_TIMEOUT		5  		// ms
#define 	ADC_FILTER_TIME_BASE	600  	// samples
#define 	ADC_DEVIATION_TIME_BASE	600  	// samples
#define 	ADC_MAX_FILTER_TIME		(ADC_FILTER_TIME_BASE * ADC_SAMPLE_TIMEOUT)  // ms
//------------------------------------------------------------------------------
// AO settings
//------------------------------------------------------------------------------
#define 	AO_STARTUP_INIT		0 		// When is set clears ao at program start
//------------------------------------------------------------------------------
// Block settings
//------------------------------------------------------------------------------
#define 	NUM_PID				1           
#define 	MAX_FANCOIL_NUMBER	2
#define 	MAX_KOTEL_NUMBER	0
#define 	MAX_VALVE_3T_NUMBER	1
#define 	MAX_PARAMS_BLOCK	1
#define 	MAX_SEASON_BLOCK	1

#define 	MAX_PARAMS_NUM		50
//------------------------------------------------------------------------------
// Kotel settings
//------------------------------------------------------------------------------
#define 	MAX_KOTEL_MODES		4
#define 	MAX_KOTEL_FUELS		1		
//------------------------------------------------------------------------------
#define 	PARAMETERS_MAX		20
//------------------------------------------------------------------------------
#define 	MAX_ERRORS_NUM		5
//------------------------------------------------------------------------------
// IO settings
//------------------------------------------------------------------------------
#ifdef __HW060
	#define NUM_DIN			8
	#define NUM_DOUT		8
	#define NUM_AIN			5
	#define NUM_AOUT		3
	#define NUM_AIN_REAL 	5
	#define NUM_AIN_THERMO 	0
#endif
//------------------------------------------------------------------------------
// Additional flash areas settings
//------------------------------------------------------------------------------
#define USING_PLM			0
#define USING_USER			1
//------------------------------------------------------------------------------
// Memory map
//   0..70K     Bootloader   70k
//   71K..236K  Main program 165k
//   237K..255k User program 20k
#define APP_FLASH_END 		0x0003ffff // end of ext flash mem
//#define APP_FLASH_START		80*1024			
#define APP_FLASH_START		0x00014000
#define HAPP_FLASH_START	APP_FLASH_START	 - 128
//#define PLM_FLASH_START		237*1024		
#define PLM_FLASH_START		0x0003B400
#define HPLM_FLASH_START	PLM_FLASH_START  - 128
//------------------------------------------------------------------------------
#ifdef __SIMULATOR
	#define NUM_DIN			6
	#define NUM_DOUT		5
	#define NUM_AIN			4
	#define NUM_AOUT		2
	#define  __farflash
#endif
//------------------------------------------------------------------------------
// Timers
//------------------------------------------------------------------------------
typedef __packed struct
{
	u8	Second;
	u8	Minute;	
	u8	Hour;	
	u8	Day;	
	u8	Date;	
	u8 	Month;	
	u8	Year;	
}TTimeFields;
typedef __packed union
{
	TTimeFields field;
	u8	data[7];
}TCTime;
#define TTime TCTime
#define TTimeFull TCTime
//------------------------------------------------------------------------------
typedef __packed union {
   u16  all;
   u8 	byte[2];
}TWord;
//------------------------------------------------------------------------------
typedef __packed struct
{
	u8	Minute;	
	u8	Hour;	
}TTimeShortFields;
typedef __packed union
{
	TTimeShortFields field;
	u8	data[2];
}TCTimeShort;
//-----------------------------------------------------------------------------------
typedef __packed struct
{
	u8	Date;	
	u8	Month;	
}TDateFieldsShort;
typedef __packed union
{
	TDateFieldsShort field;
	u8	data[2];
}TDateShort;
//------------------------------------------------------------------------------
// Season definitions
//------------------------------------------------------------------------------
// season definition
#define SEASON_SUMMER	0
#define SEASON_WINTER	1
// season mode definition
#define SEASON_AUTO		0
#define SEASON_MANUAL	1
typedef __packed struct
{
	u8 season;
	u8 mode;
	u8 switch_temperature;
	u8 switch_date;	
	TDateShort date[2];
	s16 t;
	u8 t_extern_channel;
	u8 switch_power;			
	s16 power_min_summer;
	s16 power_min_winter;	
}TSeason;
//------------------------------------------------------------------------------
// IO definitions
//------------------------------------------------------------------------------
#define MAX_IO_RECORD_LEN	48
//------------------------------------------------------------------------------
typedef __packed struct
{
	u8 num_di;
	u8 num_do;
	u8 num_ai;
	u8 num_ao;
				
	u32	din;
	u32 dout;
	s16 aoutput[NUM_AOUT];	
	s16 ainput[NUM_AIN];
	f32 ai_coff[NUM_AIN_REAL];	
	s16 ai_offset[NUM_AIN_REAL];		
}TIO;
typedef __packed union
{
	TIO field;
	u8  d[MAX_IO_RECORD_LEN];
}TIO_Fixed;	// Fixed length structure for all possible IO
//----------------------
typedef __packed struct
{
	u8 num_di;
	u8 num_do;
	u8 num_ai;
	u8 num_ao;

	u32	din;
	u32 dout;
	u16 aoutput[1];
	s16 ainput[3];
	f32 ai_coff[3];
	s16 ai_offset[3];
}TIO_CV326;
//----------------------
typedef __packed struct
{
	u8 num_di;
	u8 num_do;
	u8 num_ai;
	u8 num_ao;

	u32	din;
	u32 dout;
	u16 aoutput[1];
	s16 ainput[3];
	f32 ai_coff[3];
	s16 ai_offset[3];
}TIO_CV323;
//----------------------
typedef __packed struct
{
	u8 num_di;
	u8 num_do;
	u8 num_ai;
	u8 num_ao;

	u32	din;
	u32 dout;
	s16 aoutput[3];
	s16 ainput[5];
	f32 ai_coff[3];
	s16 ai_offset[3];
}TIO_CV050;
//------------------------------------------------------------------------------
// Menu LCD registers
//------------------------------------------------------------------------------
typedef __packed struct
{
	u8 pass_user[5];	// Password only digits
	u8 pass_admin[5];	// Password only digits	
	u8 password;		// Sign of password
	u8 lang;			// Language of menu 0 - english 1-russian
	TCTime Time;
	u8 Manual_Mode;
//	u8 reserve[2];
//	s16	params[PARAMETERS_MAX];	
	u8 Schedule_Enable;
	TCTimeShort	Schedule_Time[2];
	u8 Timer_Enable;
	TCTimeShort	Timer_Time[2];
}TMenuRegisters;

#define MANUAL_MODE 0x01
#define AUTO_MODE 	0x00
//------------------------------------------------------------------------------
// Errors record
//------------------------------------------------------------------------------
typedef __packed struct
{
	u16	code;
	TCTime time;
}TError_msg;
//------------------------------------------------------------------------------
typedef __packed struct
{
	TError_msg 	item[MAX_ERRORS_NUM];
	u8 			new_error;
}TErrors;
//------------------------------------------------------------------------------
// PID
//------------------------------------------------------------------------------
#define NUM_INT		10
#define NUM_SEC		30
#define NUM_MIN		60
//------------------------------------------------------------------------------
#define NUM_VALVE_STEP		2
//------------------------------------------------------------------------------
#define PID_MODE_STOP		0
#define PID_MODE_AUTO		1
#define PID_MODE_ERROR		2
#define PID_MODE_WARNING	3
//------------------------------------------------------------------------------
#define PID_HEATING		0
#define PID_COOLING		1
typedef __packed struct
{
	u8 channel;				// number of AI as input
	s16	p;					// proportional
	s16	i;					// integral
	s16	d;					// differential cofficient
	s16	t0;					// Desired temperature
	s16	power;				// output of pid
	s16 power_min;			// limitation of power
	s16 power_max;			// limitation of power
	u8 mode;				// 0-disable 1-enable
	s16	tin;				// input temperature	
	f32 PID_POWER_STEP[2];	// 0 - slow speed, 1 - fast speed
	u16 PID_POWER_LIMIT[2];	// 0 - zero power border, 1 - low power border
	u8 heating_cooling;
	s16	fan_in;
	s16	fan_out;	
}TPID;
//------------------------------------------------------------------------------
typedef __packed struct
{
//	s16	tm[NUM_MIN];		// memory	min
	s16	ts[NUM_SEC];		// memory	sec	
	s16	ti[NUM_INT];		// memory	smples during second
	u8	cs,cm,ch,ci;		// counters	
}TIntMem;
//------------------------------------------------------------------------------
//  Valve 3t parameters
//------------------------------------------------------------------------------
typedef __packed struct
{
	s16	power;		// Input
	u16	t3max;		// period of servoprivod full cycle in sec		
	s16	p3;			// Output
	u8 open;        // Line open
	u8 close;       // Line close
}TValve3t;
//------------------------------------------------------------------------------
//  Fancoil parameters
//------------------------------------------------------------------------------
// Day_Night definitions
#define fan_Day 	0
#define fan_Night 	1

#define FAN_AUTO	0
#define FAN_MANUAL	1
typedef __packed struct
{
	s16 T;
	u8 Fan_Mode;	
	u8 Fan_Lvl;	
	s8 Valve;
	s16 TLow;
	s16 TMedium;
	s16 THigh;		
	s16 Hysteresis;
	u16 Fan_Time;
//	u16 Valve_Time_1;	
//	u16 Valve_Time_2;
	s16 T_In;	
	s16 HC;
	s16 Valve_Hysteresis;
	u8 Day_Night;
	u8 Channel;	
//	u8 reserve;		
}TFanCoil;

typedef __packed struct
{
	u8 fan_speed;			// bits 0-low 1-med 2-high
	u8 valve_pos;		// bits 0-heat 1-cooling
}TFanLines;
//------------------------------------------------------------------------------
// Kotel records
//------------------------------------------------------------------------------
typedef __packed struct
{
	s16 		t;	
	u8			fan_speed[2];
	u8			fan_on[2];	
	u8			fan_off[2];	
	u8			smoke_speed;	
	u8			shnek_ena[2];	
	u8			shnek_on[2];
	u8			shnek_off[2];
}TKotelModeRec;

typedef __packed struct
{
	u8 				mode;
	s16 			t;
    u8              channel;
	u8				fuel;
    s16             fan_out[2];
    s16             smoke_out;
    u8              shnek_out[2];
	s16				power;		// Desired valve position
	u16				t3max;		// period of servoprivod full cycle in sec		
	s16				p3;			// Calculated valve position
	u8 				open;
	u8 				close;
	u8				smoke_speed[MAX_KOTEL_FUELS]; // At mode 5 smoke speed
	TKotelModeRec	p[MAX_KOTEL_FUELS][MAX_KOTEL_MODES];	// 3 different fuels and 4 general parameters mode
}TKotel;
//------------------------------------------------------------------------------
// Parameters record
//------------------------------------------------------------------------------
typedef __packed struct
{
	s16				pr[MAX_PARAMS_NUM];
}TParams;
//------------------------------------------------------------------------------
// Fast access records
//------------------------------------------------------------------------------
typedef __packed struct
{
	u32 serial;
	TCTime time;
}TProgramInfoRecord;

typedef __packed struct
{
	u8 identificator;
	TProgramInfoRecord prog[2];
}TProgramInfo;

#define TYPE_NOT_DEFINED	0
#define TYPE_FANCOIL_2X		1
#define TYPE_FANCOIL_4X		2
#define TYPE_PRITOCHKA		3
#define TYPE_KOTEL			4

#define TYPE_ALL_SEASON		90
#define TYPE_ALL_T			91
typedef __packed struct
{
	u8 block_num;
	u8 type;
	u8 season;
	u8 mode;
	s16 temperature[3];
	s16 speed[3];
}TWorkInfo;
//------------------------------------------------------------------------------
// IP record
//------------------------------------------------------------------------------
typedef __packed struct
{
	u8 ip[4];
	u8 mask[4];
	u8 gw[4];
	u8 mac[6];
}TIP;
//------------------------------------------------------------------------------
// Controller record
//------------------------------------------------------------------------------
typedef __packed struct
{
	TIP				_ip;
	TIO_Fixed		_io;	
	TMenuRegisters 	menu_regs;
#if MAX_SEASON_BLOCK
	TSeason			_Season;
#endif	
#if MAX_VALVE_3T_NUMBER
	TValve3t		_v3t[MAX_VALVE_3T_NUMBER];
#endif
#if NUM_PID
	TPID 			_pid[NUM_PID];
#endif
#if MAX_FANCOIL_NUMBER
	TFanCoil 		_fan[MAX_FANCOIL_NUMBER];
#endif
#if MAX_KOTEL_NUMBER
	TKotel			_kotel;
#endif
#if MAX_PARAMS_BLOCK
	TParams			_params;
#endif	
	u16	CRC;
}TControllerFields;

typedef __packed union
{
	TControllerFields field;
	u8 d[sizeof(TControllerFields)];
}TController;
//------------------------------------------------------------------------------
extern TController	CV;
extern TErrors 		_errors;
//------------------------------------------------------------------------------
//static TController CV;
//------------------------------------------------------------------------------
#define reg_data CV.d
#define MenuRegs CV.field.menu_regs
//#define errors CV.field._errors
#define errors _errors
//#define reg_season CV.field.menu_regs.Season
#define reg_ip CV.field._ip
#define ID CV.field._ip.ip
#define reg_season CV.field._Season
#define io CV.field._io.field
#define fan CV.field._fan
#define pid CV.field._pid
#define kotel CV.field._kotel
#define valve CV.field._v3t
#define misc CV.field._params


//------------------------------------------------------------------------------
// Extended Controller record
//------------------------------------------------------------------------------
typedef __packed struct
{
	char ip_str[20];
	char mask_str[20];
	char gw_str[20];
	char mac_str[24];
	char ser_id;
	char bl_pid;
	char bl_fan;
	char bl_valve;
	char bl_kotel;
	char bl_param;
	char bl_season;
	u16 adc_filter_time[NUM_AIN_REAL];//			200
}TExtController;

extern TExtController	ExtCV;

//------------------------------------------------------------------------------
#endif

