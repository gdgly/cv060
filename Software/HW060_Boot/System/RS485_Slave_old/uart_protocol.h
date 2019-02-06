//------------------------------------------------------------------------------
#ifndef __UARTPROTOCOL
#define __UARTPROTOCOL
//------------------------------------------------------------------------------
#include "..\Misc\types.h"
//------------------------------------------------------------------------------
#define upc_port		PORTD
#define upc_port_dir	DDRD
#define upc_dir		0x10
//#define upc_out		upc_port|=upc_dir
//#define upc_in		upc_port&=~upc_dir
#define tx_mode		upc_port|=upc_dir
#define rx_mode		upc_port&=~upc_dir
//------------------------------------------------------------------------------
extern TBuff rx,tx;
extern TUpcState upc;
///extern TExchange exch;
//extern TExchange own_state;
eu8 received;
//------------------------------------------------------------------------------
void upc_init();
void upc_TXHandler();
u16 upc_crc(TBuff *buff);
void upc_answer_sys();
void upc_answer_io();
void upc_answer_pid(u8 pid_num);
void upc_answer_errors();

void upc_set_sys();
void upc_set_io();
void upc_set_pid(u8 pid_num);
void upc_set_errors();

void upc_answer_time();
void upc_answer_time_summ();
void upc_answer_time_wint();
void upc_set_time();
void upc_set_time_summ();
void upc_set_time_wint();
void upc_set_parameters();
//------------------------------------------------------------------------------
#endif
