//------------------------------------------------------------------------------
#ifndef __UARTMISC
#define __UARTMISC
//------------------------------------------------------------------------------
#include "..\Misc\types.h"
//------------------------------------------------------------------------------
#define PREAMBULA_LOW	0xAA
#define PREAMBULA_HIGH	0x55
//------------------------------------------------------------------------------
// commands list
#define com_none		0
#define com_get_stat	1
#define com_get_io		2
#define com_get_errors	3
#define com_get_pid_0	4
#define com_get_pid_1	5
#define com_get_pid_2	6
#define com_get_pid_3	7


#define com_set_stat	8
#define com_set_io		9
#define com_set_errors	10
#define com_set_pid_0	11
#define com_set_pid_1	12
#define com_set_pid_2	13
#define com_set_pid_3	14

#define com_get_time		15
#define com_set_time		16
#define com_get_time_summ	17
#define com_set_time_summ	18
#define com_get_time_wint	19
#define com_set_time_wint	20
#define com_set_params		21
#define com_get_params		22

//#define com_get_pid		6
//#define com_get_status	1
//------------------------------------------------------------------------------
#define st_none				0
#define st_sending			1
#define st_wait_answer		2
#define st_answer_process	3
#define st_complete			4
//------------------------------------------------------------------------------
#define er_none				0
#define er_no_answer		1
#define er_bad_crc			2
//------------------------------------------------------------------------------
typedef struct
{
	u16 pre;
	u8 com;
	u8 id;
	u8 len;
	u16 crc;
	u8 d[121];
}TBuffFields;
//------------------------------------------------------------------------------
typedef struct
{
	u8 d[128];
}TBuffData;
//------------------------------------------------------------------------------
typedef union
{
	TBuffFields field;
	TBuffData data;	
}TBuff;
//------------------------------------------------------------------------------
typedef struct
{
	u8 txnew;
	u8 rxnew;
	u8 rxcount;
	u8 txcount;	
	u8 status;
	u8 error;	
	u8 done;
	u8 channel;
}TUpcState;
//------------------------------------------------------------------------------
typedef struct
{
	u8 status;
	u8 Season;
	TTime	ft;
}TExSTATUS;//44 bytes
//------------------------------------------------------------------------------
typedef struct
{
	u8 num_di;
	u8 num_do;
	u8 num_ai;
	u8 num_ao;			
	u32	din;
	u32 dout;
//	u16 aoutput[NUM_AOUT];	
//	s16 ainput[NUM_AIN];
	u16 analog[NUM_AOUT+NUM_AIN];	
}TExIO;//44 bytes
//------------------------------------------------------------------------------
#define NUM_ExPID	2
typedef struct
{
	u8 channel;		// number of AI as input
	s16	p;			// proportional
	s16	i;			// integral
	s16	d;			// differential cofficient
	s16	t0;			// Desired temperature
	s16	power;		// output of pid
	s16 power_min;	// limitation of power
	s16 power_max;	// limitation of power
	u8 mode;		//0-disable 1-enable
	u16	ti;			// period of integration in sec	
	u16	t3max;		// period of servoprivod full cycle in sec		
	s16	p3;			// output of pid
	u8 open;
	u8 close;
}TExPID; //24 bytes
//------------------------------------------------------------------------------
#define rx_none		0x00
#define rx_stat		0x01
#define rx_io		0x02
#define rx_pid0		0x04
#define rx_pid1		0x08
#define rx_pid2		0x10
#define rx_pid3		0x20
#define rx_errors	0x40

#define tx_none		0x00
#define tx_stat		0x01
#define tx_io		0x02
#define tx_pid0		0x04
#define tx_pid1		0x08
#define tx_pid2		0x10
#define tx_pid3		0x20
#define tx_errors	0x40
//------------------------------------------------------------------------------
typedef struct
{
	u8 channel_state;	// present or not controllers on 0..4 channels
	u8 update_stat;	
	u8 rx_list;			// 0-nothing,1-stat,2-io,3-pid0,...,6-pid3
	u8 tx_list;			// 0-nothing,1-stat,2-io,3-pid0,...,6-pid3	
	TExSTATUS st;
	TTime Time;
	TTime Time_Summ;
	TTime Time_Wint;	
	TExIO io;
	TExPID pid[NUM_ExPID];
	TErrors errors;
}TExController;
//------------------------------------------------------------------------------
#endif
