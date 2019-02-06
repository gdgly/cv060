//------------------------------------------------------------------------------
#include "main.h"
//------------------------------------------------------------------------------
unsigned short indication_data[2] = {0};
unsigned short indication_step = 0;

#define bit_ind_sys_00		0x0100
#define bit_ind_sys_01		0x0200
#define bit_ind_sys_02		0x0400

#define bit_ind_ai_00		0x0001
#define bit_ind_ai_01		0x0002
#define bit_ind_ai_02		0x0004
#define bit_ind_ai_03		0x0008
#define bit_ind_ai_04		0x0010
#define bit_ind_ai_05		0x0020
#define bit_ind_ai_06		0x0040
#define bit_ind_ai_07		0x0080

#define bit_ind_ao_00		0x0800
#define bit_ind_ao_01		0x1000
#define bit_ind_ao_02		0x2000
#define bit_ind_ao_03		0x4000
#define bit_ind_ao_04		0x8000

#define bit_ind_di_00		0x0100
#define bit_ind_di_01		0x0200
#define bit_ind_di_02		0x0400
#define bit_ind_di_03		0x0800
#define bit_ind_di_04		0x1000
#define bit_ind_di_05		0x2000
#define bit_ind_di_06		0x4000
#define bit_ind_di_07		0x8000

#define bit_ind_d0_00		0x0001
#define bit_ind_d0_01		0x0002
#define bit_ind_d0_02		0x0004
#define bit_ind_d0_03		0x0008
#define bit_ind_d0_04		0x0010
#define bit_ind_d0_05		0x0020
#define bit_ind_d0_06		0x0040
#define bit_ind_d0_07		0x0080
//------------------------------------------------------------------------------

void indication_init(void)	// Must be done once
{	
#if LED_BOARD	
	MCP23016_init();
#endif	
}

//------------------------------------------------------------------------------

void indication_handle(void)
{
#if LED_BOARD		
	unsigned short tmp;	
	unsigned short i;

	indication_step ++;
	if (indication_step > 9) indication_step = 0;
	
	// System
	if (indication_step & 1) indication_data[0] |= bit_ind_sys_00;
	else   indication_data[0] &= ~bit_ind_sys_00;
	
	if (indication_step & 2) indication_data[0] |= bit_ind_sys_01;
	else   indication_data[0] &= ~bit_ind_sys_01;
	
	if (indication_step & 4) indication_data[0] |= bit_ind_sys_02;
	else   indication_data[0] &= ~bit_ind_sys_02;
	
	for (i=0; i<NUM_AIN ; i++){
		if (io.ainput[i] < 800) indication_data[0] |=  (bit_ind_ai_00 << i);
		else  					indication_data[0] &= ~(bit_ind_ai_00 << i);
	}
	for (i=0; i<NUM_AOUT ; i++){
		tmp = io.aoutput[i] / 100;
		if (tmp >= indication_step) indication_data[0] |=  (bit_ind_ao_00 << i);
		else  						indication_data[0] &= ~(bit_ind_ao_00 << i);
	}

	indication_data[1] = io.din;
	indication_data[1] <<= 8;
	indication_data[1] |= io.dout;
	
	MCP23016_set_io(0, indication_data[0]);
	MCP23016_set_io(1, indication_data[1]);
#endif		
}

//------------------------------------------------------------------------------
