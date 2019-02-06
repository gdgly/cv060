#ifndef __AT45
#define __AT45
//-----------------------------------------------------------------------------------
#include "..\Misc\types.h"
//-----------------------------------------------------------------------------------
//#define AT45DB041	
//#define AT45DB081	
#define AT45DB161	
//#define AT45DB321	
//-----------------------------------------------------------------------------------
	// AT45 memory locations
	#define SECTOR_1_OFFSET		0
	#define _MAX_FILE_LEN	SEC	
	#define _FILE_0		_MAX_FILE_LEN*0+SECTOR_1_OFFSET
	#define _FILE_1		_MAX_FILE_LEN*1+SECTOR_1_OFFSET
//-----------------------------------------------------------------------------------
/*
#ifdef AT45DB041
#define	PAGE	256L
#define	BLOCK	8*PAGE
#define	SEC		256*PAGE
#define	SECTOR	264
#define	PAGES	2048
#endif
#ifdef AT45DB081
#define	SECTOR	264
#define	PAGES	4096
#endif
#ifdef AT45DB161
#define	SECTOR	512
#define	PAGES	4096
#define	PAGE	512L
#define	BLOCK	8*PAGE
#define	SEC		256*PAGE
#endif
#ifdef AT45DB321
#define	SECTOR	526
#define	PAGES	8192
#endif*/
//-----------------------------------------------------------------------------------
#define AT45_BUFF_SIZE	128
eu8 AT45_buff[AT45_BUFF_SIZE];
//-----------------------------------------------------------------------------------
//; Instructions for data flash SPI mode 0 or 3
//;Table 1. Read Commands
#define	Continuous_Array_Read			 	0xE8
#define	Main_Memory_Page_Read				0xD2
#define	Buffer1_Read						0xD4
#define	Buffer2_Read						0xD6
#define	Status_Register_Read			 	0xD7
//;Table 2. Program and Erase Commands
#define	Buffer1_Write_Any 				 	0x84
#define	Buffer2_Write_Any 				 	0x87
#define	Buffer1_to_MMem_with_Erase		 	0x83
#define	Buffer2_to_MMem_with_Erase		 	0x86
#define	Buffer1_to_MMem_Page_Program_without_Built_Erase	 0x88
#define	Buffer2_to_MMem_Page_Program_without_Built_Erase	 0x89
#define	Page_Erase						 	0x81
#define	Block_Erase						 	0x50
#define	MMem_through_Buff1				 	0x82
#define	MMem_through_Buff2				 	0x85
//;Table 3. Additional Commands
#define	MMem_Page_to_Buffer1_Transfer	 	0x53
#define	MMem_Page_to_Buffer2_Transfer	 	0x55
#define	MMem_Page_to_Buffer1_Compare	 	0x60
#define	MMem_Page_to_Buffer2_Compare	 	0x61
#define	Auto_Page_Rewrite_through_Buffer1	0x58
#define	Auto_Page_Rewrite_through_Buffer2	0x59
//; Memory struct for data flash IO
#define	DPage_Addr	 0x00	//; 2 bytes
#define	DByte_Addr	 0x02	//; 2 bytes
#define	DLength		 0x04	//; 1 byte
#define	DLength_All	 0x05	//; 1 byte service register
#define	DData		 0x06	//; 1 byte
#define	DStatus		 0x07	//; 1 byte
#define	DWriteStat	 0x08	//; 1 byte
	#define	Chip0	 0	//; Chip select
	#define	Chip1	 1	//; Chip select
	#define	Chip2	 2	//; Chip select
	#define	Chip3	 3	//; Chip select			
	#define	UseBuff	 4	//; 0-buff1 1-buff2

//-----------------------------------------------------------------------------------
extern u32 AT45_Addr;
//-----------------------------------------------------------------------------------
void AT45_Init();
void AT45_Start_Cycle();
void AT45_End_Cycle();
u8 AT45_Byte_Read();
void AT45_Byte_Write(u8 Byte);
u8 AT45_Status_Read();
void AT45_Read(u32 Addr,u8 *Data, u8 Len);
void AT45_Buff1_To_Mem_Write(u32 Addr);
void AT45_To_Buff1_Write(u32 Addr,u8 *Data, u8 Len);

void AT45_Start_Write(u32 Addr);
void AT45_Write(u8 *Data,u8 Size);
void AT45_End_Write();
void AT45_Read_Inc(u32 Addr,u8 *Data, u8 NewCycle);
u16 AT45_Check_CRC(u32 addr, u32 len);

void AT45_Long_Read(u32 Addr,u8 *Data, u32 len);
void AT45_Long_Write(u8 *Data,u32 len);
u8 AT45_256_Enable();
//-----------------------------------------------------------------------------------
#endif
