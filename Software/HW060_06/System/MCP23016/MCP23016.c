//-----------------------------------------------------------------------------------
#include "main.h"
//-----------------------------------------------------------------------------------

void MCP23016_init()	// Must be done once
{	
	u8 d[3]={0,0,0};
	MCP23016_comp_write(0, MCP23016_reg_IODIR0, &d[0], 2);
	MCP23016_comp_write(0, MCP23016_reg_GP0, &d[0], 2);
	MCP23016_comp_write(1, MCP23016_reg_IODIR0, &d[0], 2);
	MCP23016_comp_write(1, MCP23016_reg_GP0, &d[0], 2);
}

//-----------------------------------------------------------------------------------

void MCP23016_comp_write(u8 ic, u8 addr,u8* data, u16 len)
{
	u8	Addr[2];
	Addr[0]=addr;
	Addr[1]=0;	
	switch(ic){
	case 0 : 	I2C_NiMasterWrite(0x40,Addr,1,data,len); break;
	case 1 : 	I2C_NiMasterWrite(0x42,Addr,1,data,len); break;
	}
}

//-----------------------------------------------------------------------------------

void MCP23016_comp_read(u8 ic, u8 addr,u8* data, u16 len)
{
	u8	Addr[2];
	Addr[0]=addr;
	Addr[1]=0;	
	switch(ic){
	case 0 : 	I2C_NiMasterRead(0x40,Addr,1,data,len); break;
	case 1 : 	I2C_NiMasterRead(0x42,Addr,1,data,len); break;
	}
}

//-----------------------------------------------------------------------------------

void MCP23016_set_io(u8 ic, u16 data)
{
	switch(ic){
	case 0 : 	MCP23016_comp_write(0,MCP23016_reg_GP0,(u8*)&data,2); break;
	case 1 : 	MCP23016_comp_write(1,MCP23016_reg_GP0,(u8*)&data,2); break;
	}
}

//-----------------------------------------------------------------------------------

u16 MCP23016_get_io(u8 ic)
{
	u16 data = 0;
	switch(ic){
	case 0 : 	MCP23016_comp_read(0,MCP23016_reg_GP0,(u8*)&data,2); break;
	case 1 : 	MCP23016_comp_read(1,MCP23016_reg_GP0,(u8*)&data,2); break;
	}
    return data;
}
//-----------------------------------------------------------------------------------
