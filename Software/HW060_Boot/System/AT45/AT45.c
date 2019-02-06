#include "..\main.h"
//-----------------------------------------------------------------------------------
//u8 i;
//u16 j;
//u8 *ptr;
//u8 c;	
u8 AT45_buff[AT45_BUFF_SIZE];
//u16 bs=0;
u32 AT45_Addr;	
u32 AT45_Addr_Int;	
u32 test;
//-----------------------------------------------------------------------------------
void AT45_Init()
{	
	// Port 1
	AT45PORT 	&= ~b_at45_SCK;
	AT45PORT 	&= ~b_at45_SI;
	AT45DDR  	|=  b_at45_SCK + b_at45_SI;
	AT45DDR  	&= ~b_at45_SO;	
	// Port 2
	AT45_2_PORT	|=	 b_at45_nCS0;	
	AT45_2_PORT	|=	 b_at45_nWP;
	AT45_2_PORT	|=	 b_at45_RES;	
	AT45_2_DDR	|=	 b_at45_nCS0;	
	AT45_2_DDR	|=	 b_at45_nWP;
	AT45_2_DDR	|=	 b_at45_RES;			
}
//-----------------------------------------------------------------------------------
void AT45_Start_Cycle()
{
	AT45_2_PORT	|=	 b_at45_nCS0;	
	AT45PORT	&=	~b_at45_SCK;
	AT45_2_PORT	&=	~b_at45_nCS0;
}
//-----------------------------------------------------------------------------------
void AT45_End_Cycle()
{
	AT45PORT	&=	~b_at45_SCK;
	AT45_2_PORT	|=	 b_at45_nCS0;	
}
//-----------------------------------------------------------------------------------
u8 AT45_Byte_Read()
{
	u8 tmp=0,i;
	for(i=0;i<8;i++)
	{
		AT45PORT	|=	b_at45_SCK;
		tmp=tmp<<1;		
		if(AT45PINS & b_at45_SO)
			tmp|=1;
		AT45PORT	&=	~b_at45_SCK;		
	}
	return tmp;
}
//-----------------------------------------------------------------------------------
void AT45_Byte_Write(u8 Byte)
{
	u8 tmp,i;
	tmp=Byte;

	for(i=0;i<8;i++)
	{		
		if(tmp & 0x80)
			AT45PORT	|=	b_at45_SI;
		else
			AT45PORT	&=	~b_at45_SI;
		tmp=tmp<<1;
		AT45PORT	|=	b_at45_SCK;	
		AT45PORT	&=	~b_at45_SCK;		
	}
}
//-----------------------------------------------------------------------------------
void AT45_Read_Inc(u32 Addr,u8 *Data, u8 NewCycle)
{
	u8 tmp;
	tmp=Addr-AT45_Addr_Int;
	if((NewCycle!=0)||(tmp>=AT45_BUFF_SIZE))
	{
		AT45_Addr_Int=Addr;
		AT45_Read(AT45_Addr_Int,&AT45_buff[0],AT45_BUFF_SIZE);
		tmp=0;
	}
	*Data=AT45_buff[tmp];		
}
//-----------------------------------------------------------------------------------
void AT45_Read(u32 Addr,u8 *Data, u8 Len)
{
	u8 i,*ptr,tmp;
	u16 PageAddr,ByteAddr;
	
	PageAddr=Addr/SECTOR;
	ByteAddr=Addr-PageAddr*SECTOR;

	AT45_Start_Cycle();
	AT45_Byte_Write(Continuous_Array_Read);
	AT45_Byte_Write(PageAddr>>7);
	tmp=PageAddr<<1;
	if(ByteAddr & 0x0100)
		tmp|=1;
	AT45_Byte_Write(tmp);		
	AT45_Byte_Write(ByteAddr);
	AT45_Byte_Write(0);
	AT45_Byte_Write(0);
	AT45_Byte_Write(0);		
	AT45_Byte_Write(0);
	ptr=Data;
	for(i=0;i<Len;i++)	
	{
		*ptr=AT45_Byte_Read();
		ptr++;
	}
	AT45_End_Cycle();	
}
//-----------------------------------------------------------------------------------
void AT45_Start_Write(u32 Addr)
{
	AT45_Addr=Addr;
}
//-----------------------------------------------------------------------------------
void AT45_Write(u8 *Data,u8 Size)
{
	u16 len;
	u16 PageAddr,ByteAddr;	
	PageAddr=AT45_Addr/SECTOR;	
	ByteAddr=AT45_Addr-PageAddr*SECTOR;

	if((Size+ByteAddr)<SECTOR)	
	{
		AT45_To_Buff1_Write(AT45_Addr,Data,Size);
		AT45_Addr+=Size;
	}
	else
	{
		len=SECTOR-ByteAddr;
		AT45_To_Buff1_Write(AT45_Addr,Data,(u8)len);
		AT45_Buff1_To_Mem_Write(AT45_Addr);
		AT45_Addr+=len;
		Data+=len;		
		len=Size-len;
		AT45_To_Buff1_Write(AT45_Addr,Data,(u8)len);
		AT45_Addr+=len;		
	}
}
//-----------------------------------------------------------------------------------
void AT45_End_Write()
{
	u32 PageAddr,ByteAddr;	
	PageAddr=AT45_Addr/SECTOR;	
	ByteAddr=AT45_Addr-PageAddr*SECTOR;
	if(ByteAddr!=0)
		AT45_Buff1_To_Mem_Write(AT45_Addr);

}
//-----------------------------------------------------------------------------------
void AT45_Buff1_To_Mem_Write(u32 Addr)
{
	u8 tmp;
	u16 PageAddr,ByteAddr;
	
	PageAddr=Addr/SECTOR;	
	ByteAddr=Addr-PageAddr*SECTOR;
	
	while((AT45_Status_Read() & 0x80)==0){}			
	AT45_Start_Cycle();
	AT45_Byte_Write(Buffer1_to_MMem_with_Erase);
	AT45_Byte_Write(PageAddr>>7);
	tmp=PageAddr<<1;
	AT45_Byte_Write(tmp);		
	AT45_Byte_Write(ByteAddr);
	AT45_End_Cycle();		
	while((AT45_Status_Read() & 0x80)==0){}			
}
//-----------------------------------------------------------------------------------
void AT45_To_Buff1_Write(u32 Addr,u8 *Data, u8 Len)
{
	u8 i,*ptr,tmp;
	u16 PageAddr,ByteAddr;

	PageAddr=Addr/SECTOR;
	ByteAddr=Addr-PageAddr*SECTOR;
	AT45_Start_Cycle();
	AT45_Byte_Write(Buffer1_Write_Any); 	
	AT45_Byte_Write(PageAddr>>7);
	tmp=PageAddr<<1;
	if(ByteAddr & 0x0100)
		tmp|=1;
	AT45_Byte_Write(tmp);		
	AT45_Byte_Write(ByteAddr);

	ptr=Data;
	for(i=0;i<Len;i++)
	{	
		AT45_Byte_Write(*ptr);
		ptr++;
	}
	AT45_End_Cycle();	
}
//-----------------------------------------------------------------------------------
u8 AT45_Status_Read()
{
	u8 tmp=0;
	AT45_Start_Cycle();
	AT45_Byte_Write(Status_Register_Read);
	tmp=AT45_Byte_Read();
	AT45_End_Cycle();
	return tmp;
}
//-----------------------------------------------------------------------------------
