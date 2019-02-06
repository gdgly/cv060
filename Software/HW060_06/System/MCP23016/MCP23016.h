#ifndef __MCP23016
#define __MCP23016
//-----------------------------------------------------------------------------------
#include "define.h"
#include "controller_data_define.h"
//-----------------------------------------------------------------------------------

#define MCP23016_reg_GP0				 		0x00
#define MCP23016_reg_GP1				 		0x01
#define MCP23016_reg_OLAT0				 		0x02
#define MCP23016_reg_OLAT1				 		0x03
#define MCP23016_reg_IPOL0				 		0x04
#define MCP23016_reg_IPOL1				 		0x05
#define MCP23016_reg_IODIR0				 		0x06
#define MCP23016_reg_IODIR1				 		0x07
#define MCP23016_reg_INTCAP0			 		0x08
#define MCP23016_reg_INTCAP1			 		0x09
#define MCP23016_reg_IOCON0				 		0x0a
#define MCP23016_reg_IOCON1				 		0x0b

//-----------------------------------------------------------------------------------
void MCP23016_init();
void MCP23016_comp_write(u8 ic, u8 addr,u8* data, u16 len);
void MCP23016_comp_read(u8 ic, u8 addr,u8* data, u16 len);
void MCP23016_set_io(u8 ic, u16 data);
u16 MCP23016_get_io(u8 ic);
//-----------------------------------------------------------------------------------
#endif
