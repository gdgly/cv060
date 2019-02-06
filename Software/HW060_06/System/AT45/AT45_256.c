//*****************************************************************************
#include "main.h"
//*****************************************************************************
#ifdef USE_AT45
//*****************************************************************************
//u8 i;
//u16 j;
//u8 *ptr;
//u8 c;	
u8 AT45_buff[AT45_BUFF_SIZE];
//u16 bs=0;
u32 AT45_Addr;	
u32 AT45_Addr_Int;	
u32 test;
//*****************************************************************************
// AT45 Hardware dependent part
//*****************************************************************************
void AT45_Init();
void AT45_Start_Cycle();
void AT45_End_Cycle();
u8 AT45_Byte_Read();
void AT45_Byte_Write(u8 Byte);
void AT45_Enable();
void AT45_Disable();
//*****************************************************************************
// AT45 Hardware independent part
//*****************************************************************************
u8 AT45_256_Enable()
{
	while((AT45_Status_Read() & 0x80)==0){}			
	AT45_Start_Cycle();
	AT45_Byte_Write(0x3d);
	AT45_Byte_Write(0x2a);
	AT45_Byte_Write(0x80);
	AT45_Byte_Write(0xa6);
	AT45_End_Cycle();		
	while((AT45_Status_Read() & 0x80)==0){}		
	if(AT45_Status_Read() & 0x01)
		return 1;	// Device in 256 bytes mode
	return 0;	
}
//*****************************************************************************
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
//*****************************************************************************
void AT45_Read(u32 Addr,u8 *Data, u8 Len)
{
	u8 i,*ptr;

	AT45_Start_Cycle();
	AT45_Byte_Write(Continuous_Array_Read);
	AT45_Byte_Write(Addr>>16);
	AT45_Byte_Write(Addr>>8);		
	AT45_Byte_Write(Addr);
	AT45_Byte_Write(0);
	AT45_Byte_Write(0);
	AT45_Byte_Write(0);		
	AT45_Byte_Write(0);
	ptr=Data;
	for(i=0;i<Len;i++)	
	{
		watchdog_reset();
		*ptr=AT45_Byte_Read();
		ptr++;
	}
	AT45_End_Cycle();	
}
//*****************************************************************************
void AT45_Long_Read(u32 Addr,u8 *Data, u32 len)
{
	u32	i=0;
	u32	tmp;

	for(i=0;i<(len/128);i++)
	{
		tmp=len-i*128;
		AT45_Read(Addr,Data,128);
		Data+=128;
		Addr+=128;
	}
	tmp=len-i*128;
	if(tmp!=0)
	{
		AT45_Read(Addr,Data,tmp);
		Data+=tmp;
		Addr+=tmp;			
	}
}
//*****************************************************************************
void AT45_Start_Write(u32 Addr)
{
	AT45_Addr=Addr;
}
//*****************************************************************************
void AT45_Write(u8 *Data,u8 Size)
{
	u32 len;
	u32 PageAddr,ByteAddr;	
	
	PageAddr=AT45_Addr/PAGE;	
	ByteAddr=AT45_Addr-PageAddr*PAGE;

	if((Size+ByteAddr)<PAGE)	
	{
		AT45_To_Buff1_Write(AT45_Addr,Data,Size);
		AT45_Addr+=Size;
	}
	else
	{
		len=PAGE-ByteAddr;
		AT45_To_Buff1_Write(AT45_Addr,Data,(u8)len);
		AT45_Buff1_To_Mem_Write(AT45_Addr);
		AT45_Addr+=len;
		Data+=len;		
		len=Size-len;
		AT45_To_Buff1_Write(AT45_Addr,Data,(u8)len);
		AT45_Addr+=len;		
	}
}
//*****************************************************************************
void AT45_Long_Write(u8 *Data,u32 len)
{
	u32	i=0;
	u32	tmp;
	for(i=0;i<(len/128);i++)
	{
		tmp=len-i*128;
		//__sprintf((u8*)outtxt,"\n\r\WR ");	LongToStr(outtxt,&i,0);
		AT45_Write(Data,128);
		Data+=128;
	}
	tmp=len-i*128;
	if(tmp!=0)
	{
		AT45_Write(Data,tmp);
		Data+=tmp;			
	}	
}
//*****************************************************************************
void AT45_End_Write()
{
	u32 PageAddr,ByteAddr;	
	PageAddr=AT45_Addr/PAGE;	
	ByteAddr=AT45_Addr-PageAddr*PAGE;
	if(ByteAddr!=0)
		AT45_Buff1_To_Mem_Write(AT45_Addr);

}
//*****************************************************************************
void AT45_Buff1_To_Mem_Write(u32 Addr)
{
//	u8 tmp;

	while((AT45_Status_Read() & 0x80)==0){}			
	AT45_Start_Cycle();
	AT45_Byte_Write(Buffer1_to_MMem_with_Erase);
	AT45_Byte_Write(Addr>>16);
	AT45_Byte_Write(Addr>>8);
	AT45_Byte_Write(Addr);
	AT45_End_Cycle();		
	while((AT45_Status_Read() & 0x80)==0){}			
}
//*****************************************************************************
void AT45_To_Buff1_Write(u32 Addr,u8 *Data, u8 Len)
{
	u8 i,*ptr;
//	u32 PageAddr,ByteAddr;

	AT45_Start_Cycle();
	AT45_Byte_Write(Buffer1_Write_Any); 	
	AT45_Byte_Write(Addr>>16);
	AT45_Byte_Write(Addr>>8);
	AT45_Byte_Write(Addr);
	ptr=Data;
	for(i=0;i<Len;i++)
	{	
		AT45_Byte_Write(*ptr);
		ptr++;
	}
	AT45_End_Cycle();	
}
//*****************************************************************************
u8 AT45_Status_Read()
{
	u8 tmp=0;
	AT45_Start_Cycle();
	AT45_Byte_Write(Status_Register_Read);
	tmp=AT45_Byte_Read();
	AT45_End_Cycle();
	return tmp;
}
///*****************************************************************************
// who-5 Params fields in eep
u16 AT45_Check_CRC(u32 addr, u32 len)
{
	u32 p,d;
	u16 crc;
//	u8 ctmp;
	u8 buff[64];
	
	InitCRC(&crc);
	for(p=0;p<len;p=p+64)	
	{
		AT45_Read((addr+p),(u8*)&buff[0],64);
		d=len-p;
		if(d>=64)
		{
			CalcCRC(&buff[0],64,&crc);
		}
		else
		{
			CalcCRC(&buff[0],d,&crc);
		}
	}
	EndCRC(&crc);
	return crc;
}
//*****************************************************************************
#endif
//*****************************************************************************
