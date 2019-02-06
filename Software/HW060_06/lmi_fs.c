//*****************************************************************************
//
// lmi_fs.c - File System Processing for lwIP Web Server Apps.
//
// Copyright (c) 2007-2010 Texas Instruments Incorporated.  All rights reserved.
// Software License Agreement
//
// Texas Instruments (TI) is supplying this software for use solely and
// exclusively on TI's microcontroller products. The software is owned by
// TI and/or its suppliers, and is protected under applicable copyright
// laws. You may not combine this software with "viral" open-source
// software in order to form a larger program.
//
// THIS SOFTWARE IS PROVIDED "AS IS" AND WITH ALL FAULTS.
// NO WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING, BUT
// NOT LIMITED TO, IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE. TI SHALL NOT, UNDER ANY
// CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL, OR CONSEQUENTIAL
// DAMAGES, FOR ANY REASON WHATSOEVER.
//
// This is part of revision 5961 of the EK-LM3S8962 Firmware Package.
//
//*****************************************************************************
#include "main.h"

#if USE_AT45_FS

#include <string.h>
#include "inc/hw_memmap.h"
#include "inc/hw_ssi.h"
#include "inc/hw_sysctl.h"
#include "inc/hw_types.h"
#include "driverlib/gpio.h"
#include "driverlib/ssi.h"
#include "driverlib/sysctl.h"
#include "utils/lwiplib.h"
#include "utils/ustdlib.h"
#include "httpserver_raw/httpd.h"
#include "httpserver_raw/fs.h"
#include "httpserver_raw/fsdata.h"
#include "fatfs/src/ff.h"
#include "fatfs/src/diskio.h"


#include <stdlib.h>

extern tBoolean IntMasterEnable(void);
extern tBoolean IntMasterDisable(void);

//*****************************************************************************
//
// The following are data structures used by FatFs.
//
//*****************************************************************************
static FATFS g_sFatFs;
static volatile tBoolean g_bFatFsEnabled = false;

//static char g_cSampleTextBuffer[16] = {0};

FRESULT fresult;
DIR g_sDirObject;
FIL file;

//---------------------- Peter ------------------------------------------------
void ShowTemperature(unsigned char *out,short *val);
void ShowTemperatureShort(unsigned char *out,short *val);
void ShowShort_6sym(unsigned char *out,short *val);
void Toggle_Program_Mode();

void ip_con_init();
void ip_con_handle(char *in_txt);
void con_init();
void ip_con_remove_n(u8* str);
void Show_Time_No_Shift(char *out,TCTime *time);

volatile u16 IP_Inactive_Timer=0;
volatile u16 IP_Multiply_Timer=0;
u16 IP_Multiply_Sign=0;
#define __IP_RESET			0x0001
#define __IP_STORE			0x0002
#define __IP_PROGRAMM_MODE 	0x0004

u8 last_operation=0;
#define lp_con_tx 		0x01
#define lp_con_rx 		0x02
#define lp_log_state 	0x03
#define lp_dio_state 	0x04
#define lp_ipmac_get 	0x05
#define lp_ipgw_get 	0x06
#define lp_ipmask_get 	0x07
#define lp_ipaddr_get 	0x08

char update_ip_address=0;
char update_mask_address=0;
char update_gw_address=0;

unsigned long new_ip=0;
unsigned long new_mask=0;
unsigned long new_gw=0;

#define IP4_ADDR_MAKE(ipaddr, a,b,c,d) \
                ipaddr =      (((unsigned long)((a) & 0xff) << 24) | \
                               ((unsigned long)((b) & 0xff) << 16) | \
                               ((unsigned long)((c) & 0xff) << 8) | \
                                (unsigned long)((d) & 0xff))

void Show_Time(char *out,TCTime *time);

//*****************************************************************************
//
// Set up delayed routine
//
//*****************************************************************************
void ip_multyply_command_delay(u16 command)
{
	IP_Multiply_Sign |= command;
	IP_Multiply_Timer = 3;
}

//*****************************************************************************
//
// Set up delayed routine handler
//
//*****************************************************************************
void ip_multyply_command_handle()
{
	if(IP_Multiply_Timer)return;
	if(IP_Multiply_Sign & __IP_RESET){__sprintf((u8*)outtxt,"\n\r IP command Reset");reset(); IP_Multiply_Sign&=~__IP_RESET;}
	if(IP_Multiply_Sign & __IP_STORE){
		__sprintf((u8*)outtxt,"\n\r IP command Store");
		IntMasterDisable();
		params_store();
		IntMasterEnable(); 
		IP_Multiply_Sign&=~__IP_STORE;
	}
	if(IP_Multiply_Sign & __IP_PROGRAMM_MODE){__sprintf((u8*)outtxt,"\n\r IP command Prog mode");Toggle_Program_Mode(); IP_Multiply_Sign&=~__IP_PROGRAMM_MODE;}
}

//*****************************************************************************
//
// Enable the SSI Port for FatFs usage.
//
//*****************************************************************************
static void
fs_enable(unsigned long ulFrequency)
{
}

//*****************************************************************************
//
// Initialize the file system.
//
//*****************************************************************************
void
fs_init(void)
{
    g_bFatFsEnabled = false;

    fresult = f_mount(0, &g_sFatFs);
    if(fresult != FR_OK)
    {
		//__sprintf((u8*)outtxt,"\n\r FS error");	
        return;
    }

    fresult = f_opendir(&g_sDirObject, "/");
    if(fresult == FR_OK)
    {
        g_bFatFsEnabled = true;
        //__sprintf((u8*)outtxt,"\n\r Using FLASH file system");	
    }
    else
    {
        g_bFatFsEnabled = false;
        //__sprintf((u8*)outtxt,"\n\r Filse system error");	
    }
}

//*****************************************************************************
// File System tick handler.
//*****************************************************************************
void
fs_tick(unsigned long ulTickMS)
{
    static unsigned long ulTickCounter = 0;

    //
    // Check if the file system has been enabled yet.
    //
    if(!g_bFatFsEnabled)
    {
        return;
    }

    //
    // Increment the tick counter.
    //
    ulTickCounter += ulTickMS;

    //
    // Check to see if the FAT FS tick needs to run.
    //
    if(ulTickCounter >= 10)
    {
        ulTickCounter = 0;
        disk_timerproc();
    }
}
//*****************************************************************************
//
// Convert IP string to IP numbers
// return operation status
//
//*****************************************************************************
int str_to_ip (char* str, char* ip_addr)
{
	char pcBuf[5][5];
	char *ptr;
	int	 digit;
	char end=0;
	int i = 0;

	digit=0;
	ptr=&pcBuf[digit][0];	
		
	while((str[i]!=0)&&(end==0))
	{
		switch(str[i])
		{
			case 0:
			case '&':
				end=1;
				break;
			case '.':
				digit++;
				ptr=&pcBuf[digit][0];					
				break;
			default:
				*ptr=str[i];
				ptr++;
				*ptr=0;
				break;
		}
		i++;
	}
	ip_addr[0]=atoi(&pcBuf[0][0]);
	ip_addr[1]=atoi(&pcBuf[1][0]);
	ip_addr[2]=atoi(&pcBuf[2][0]);
	ip_addr[3]=atoi(&pcBuf[3][0]);
	return 1;
}
//*****************************************************************************
//
// Open a file and return a handle to the file, if found.  Otherwise,
// return NULL.
//
//*****************************************************************************
struct fs_file *
fs_open(char *name)
{
   // const struct fsdata_file *ptTree;
    struct fs_file *ptFile = NULL;
    FIL *ptFatFile = NULL;
    fresult = FR_OK;

    char *data;
    int i;
    char hour,min,sec,date,mon,year;
    char num,sign,delta;


    //
    // Allocate memory for the file system structure.
    //
    ptFile = mem_malloc(sizeof(struct fs_file));
    if(NULL == ptFile)
    {
        return(NULL);
    }
	//---------------------------------------------------
    // Request IP address update
    //---------------------------------------------------
    if(strncmp(name, "/ipaddress_set?value", 20) == 0)
    {
		char ip[4];
        data = name;
        data += 21;
        i = 0;
		
		Time_To_Store_Full = 3;
		update_ip_address=1;
		new_ip=htonl(lwIPLocalIPAddrGet());
		new_mask=htonl(lwIPLocalNetMaskGet());
		new_gw=htonl(lwIPLocalGWAddrGet());		
		
		
		str_to_ip(data, ip);
		
		ID[0]=ip[0];
		ID[1]=ip[1];
		ID[2]=ip[2];
		ID[3]=ip[3];
		IP4_ADDR_MAKE(new_ip,ip[0],ip[1],ip[2],ip[3]);
		
        ptFile->data = NULL;
        ptFile->len = 0;
        ptFile->index = 0;
        ptFile->pextension = NULL;
        return(ptFile);
    }
	//---------------------------------------------------
    // Request IP address
    //---------------------------------------------------
    if(strncmp(name, "/ipaddress_get?id", 15) == 0)
    {
        static char pcBuf[20];
		unsigned long ipaddr=lwIPLocalIPAddrGet();
		unsigned char *pucTemp = (unsigned char *)&ipaddr;

	    usprintf(pcBuf, "%d.%d.%d.%d", pucTemp[0], pucTemp[1], pucTemp[2],
             pucTemp[3]);		

        ptFile->data = pcBuf;
        ptFile->len = strlen(pcBuf);
        ptFile->index = ptFile->len;
        ptFile->pextension = NULL;
        return(ptFile);
    }
    //---------------------------------------------------
    // Request Mask update
    //---------------------------------------------------
    if(strncmp(name, "/ipmask_set?value", 17) == 0)
    {
		char ip[4];
        data = name;
        data += 18;
        i = 0;

		Time_To_Store_Full = 3;
		update_mask_address=1;
		new_ip=htonl(lwIPLocalIPAddrGet());
		new_mask=htonl(lwIPLocalNetMaskGet());
		new_gw=htonl(lwIPLocalGWAddrGet());		

		str_to_ip(data, ip);
		
		IP4_ADDR_MAKE(new_mask,ip[0],ip[1],ip[2],ip[3]);

        ptFile->data = NULL;
        ptFile->len = 0;
        ptFile->index = 0;
        ptFile->pextension = NULL;
        return(ptFile);
    }		
    //---------------------------------------------------
    // Request MASK address
    //---------------------------------------------------
    if(strncmp(name, "/ipmask_get?id", 14) == 0)
    {
        static char pcBuf[20];
		unsigned long ipaddr=lwIPLocalNetMaskGet();
		unsigned char *pucTemp = (unsigned char *)&ipaddr;
		
	    usprintf(pcBuf, "%d.%d.%d.%d", pucTemp[0], pucTemp[1], pucTemp[2],
             pucTemp[3]);		

        ptFile->data = pcBuf;
        ptFile->len = strlen(pcBuf);
        ptFile->index = ptFile->len;
        ptFile->pextension = NULL;
        return(ptFile);
    }	
    //---------------------------------------------------
    // Request Gateway address update
    //---------------------------------------------------
    if(strncmp(name, "/ipgw_set?value", 15) == 0)
    {
		char ip[4];
        data = name;
        data += 16;
        i = 0;

		Time_To_Store_Full = 3;
		update_gw_address = 1;
		new_ip=htonl(lwIPLocalIPAddrGet());
		new_mask=htonl(lwIPLocalNetMaskGet());
		new_gw=htonl(lwIPLocalGWAddrGet());		

		str_to_ip(data, ip);
		
		IP4_ADDR_MAKE(new_gw,ip[0],ip[1],ip[2],ip[3]);

        ptFile->data = NULL;
        ptFile->len = 0;
        ptFile->index = 0;
        ptFile->pextension = NULL;
        return(ptFile);
    }	
    //---------------------------------------------------
    // Request Gateway address
    //---------------------------------------------------
    if(strncmp(name, "/ipgw_get?id", 12) == 0)
    {
        static char pcBuf[20];
		unsigned long ipaddr=lwIPLocalGWAddrGet();
		unsigned char *pucTemp = (unsigned char *)&ipaddr;
		if((IP_Inactive_Timer)&&(last_operation==lp_ipgw_get))
		{
			ptFile->data = NULL;
			ptFile->len = 0;
			ptFile->index = 0;
			ptFile->pextension = NULL;
			return(ptFile);		
		}
		last_operation=lp_ipgw_get;
		IP_Inactive_Timer=100;		
		
	    usprintf(pcBuf, "%d.%d.%d.%d", pucTemp[0], pucTemp[1], pucTemp[2],
             pucTemp[3]);		

        ptFile->data = pcBuf;
        ptFile->len = strlen(pcBuf);
        ptFile->index = ptFile->len;
        ptFile->pextension = NULL;
        return(ptFile);
    }		
	//---------------------------------------------------
    // Request MAC address
    //---------------------------------------------------
    if(strncmp(name, "/ipmac_get?id", 13) == 0)
    {
        static char pcBuf[20];

		unsigned char pucTemp[10];		
		if((IP_Inactive_Timer)&&(last_operation==lp_ipmac_get))
		{
			ptFile->data = NULL;
			ptFile->len = 0;
			ptFile->index = 0;
			ptFile->pextension = NULL;
			return(ptFile);		
		}
		last_operation=lp_ipmac_get;
		IP_Inactive_Timer=100;
		
		lwIPLocalMACGet(pucTemp);
	    usprintf(pcBuf, "%02X:%02X:%02X:%02X:%02X:%02X", pucTemp[0], pucTemp[1], pucTemp[2],
             pucTemp[3], pucTemp[4], pucTemp[5]);

        ptFile->data = pcBuf;
        ptFile->len = strlen(pcBuf);
        ptFile->index = ptFile->len;
        ptFile->pextension = NULL;
        return(ptFile);
    }			
    //---------------------------------------------------
    // Request for D IO State?
    //---------------------------------------------------
    if(strncmp(name, "/DIO_state?id=", 14) == 0)
    {
        static char pcBuf[100];
		if((IP_Inactive_Timer)&&(last_operation==lp_dio_state))
		{
			ptFile->data = NULL;
			ptFile->len = 0;
			ptFile->index = 0;
			ptFile->pextension = NULL;
			return(ptFile);		
		}
		last_operation=lp_dio_state;
		IP_Inactive_Timer=100;
		memset(pcBuf,0,sizeof(pcBuf));
		pcBuf[sizeof(pcBuf)-1]=0;
		
		for(i=0;i<NUM_DOUT;i++)
			if(io.dout & (1<<i))pcBuf[i+0]='1';
			else                pcBuf[i+0]='0';
		
		for(i=0;i<NUM_DIN;i++)
			if(io.din & (1<<i)) pcBuf[i+10]='1';
			else                pcBuf[i+10]='0';			

		
		for(i=0;i<NUM_AIN;i++)
			ShowShort_6sym((u8*)&pcBuf[6*i+20],(short*)&io.ainput[i]);

		for(i=0;i<NUM_AOUT;i++)
			ShowShort_6sym((u8*)&pcBuf[6*i+50],(short*)&io.aoutput[i]);
		
				
		Show_Time_No_Shift(&pcBuf[80], &MenuRegs.Time);
		usprintf(&pcBuf[96], " %d",MenuRegs.Manual_Mode);
				 
		for(i=0;i<(96);i++)
			if(pcBuf[i]==0)pcBuf[i]=' ';

		ptFile->data = pcBuf;
        ptFile->len = strlen(pcBuf);
        ptFile->index = ptFile->len;
        ptFile->pextension = NULL;
        return(ptFile);
    }
    //---------------------------------------------------
    // Request for Log
    //---------------------------------------------------
    if(strncmp(name, "/Log_state?id=", 14) == 0)
    {
        static char pcBuf[160];
		char buf[40];
		int j;
		u8 tmp;
		if((IP_Inactive_Timer)&&(last_operation==lp_log_state))
		{
			ptFile->data = NULL;
			ptFile->len = 0;
			ptFile->index = 0;
			ptFile->pextension = NULL;
			return(ptFile);		
		}
		last_operation=lp_log_state;
		IP_Inactive_Timer=100;
		memset(pcBuf,'0',sizeof(pcBuf));
		pcBuf[sizeof(pcBuf)-1]=0;

		strcpy(pcBuf,"");
		for(j=0;j<MAX_ERRORS_NUM;j++)
		{		
			if(errors.item[j].code!=0)
			{
				tmp=j+1;
				usprintf(buf, "%d) Error %04X %02d %s 20%02d %02d:%02d:%02d\r",tmp,errors.item[j].code, errors.item[j].time.field.Date, Monthes_Name_Short[errors.item[j].time.field.Month-1], errors.item[j].time.field.Year, errors.item[j].time.field.Hour, errors.item[j].time.field.Minute, errors.item[j].time.field.Second);
				strcat(pcBuf,buf);
			}
			else break;
		}		
		
		ptFile->data = pcBuf;
        ptFile->len = strlen(pcBuf);
        ptFile->index = ptFile->len;
        ptFile->pextension = NULL;
        return(ptFile);
    }	
    //---------------------------------------------------
    // Process request to toggle DO_X
    //---------------------------------------------------
    if(strncmp(name, "/cgi-bin/toggle_DO_", 19) == 0)
    {
//		io.aoutput[0]=name[22]-'0';
		if(name[22]=='1')
			switch(name[20])
			{
			case '0':io.dout |= 0x00000001;break;
			case '1':io.dout |= 0x00000002;break;
			case '2':io.dout |= 0x00000004;break;
			case '3':io.dout |= 0x00000008;break;
			case '4':io.dout |= 0x00000010;break;
			case '5':io.dout |= 0x00000020;break;
			case '6':io.dout |= 0x00000040;break;
			case '7':io.dout |= 0x00000080;break;
			}
		if(name[22]=='0')
			switch(name[20])
			{
			case '0':io.dout &=~ 0x00000001;break;
			case '1':io.dout &=~ 0x00000002;break;
			case '2':io.dout &=~ 0x00000004;break;
			case '3':io.dout &=~ 0x00000008;break;
			case '4':io.dout &=~ 0x00000010;break;
			case '5':io.dout &=~ 0x00000020;break;
			case '6':io.dout &=~ 0x00000040;break;
			case '7':io.dout &=~ 0x00000080;break;
			}
//		io.dout ^= 0x00000080;
        ptFile->data = NULL;
        ptFile->len = 0;
        ptFile->index = 0;
        ptFile->pextension = NULL;
        return(ptFile);
    }		
    //---------------------------------------------------
    // Process request to reinit controller
    //---------------------------------------------------
    if(strncmp(name, "/cgi-bin/reinit?id", 18) == 0)
    {		
		hour=(name[18]-'0')*10+(name[19]-'0');
		min=(name[21]-'0')*10+(name[22]-'0');
		sec=(name[24]-'0')*10+(name[25]-'0');
		date=(name[27]-'0')*10+(name[28]-'0');
		mon=(name[30]-'0')*10+(name[31]-'0');
		year=(name[35]-'0')*10+(name[36]-'0');
		fram_init();
		fram_set_time(hour,min,sec);
		fram_set_date(year,mon,date,1);
		DS1337_set_time(hour,min,sec);
		DS1337_set_date(year,mon,date,1);
        ptFile->data = NULL;
        ptFile->len = 0;
        ptFile->index = 0;
        ptFile->pextension = NULL;
        return(ptFile);
    }		
    //---------------------------------------------------
    // Process request to reinit controller
    //---------------------------------------------------
    if(strncmp(name, "/cgi-bin/store?id", 17) == 0)
    {		
		ip_multyply_command_delay(__IP_STORE);
        ptFile->data = NULL;
        ptFile->len = 0;
        ptFile->index = 0;
        ptFile->pextension = NULL;
        return(ptFile);
    }	
    //---------------------------------------------------
    // Process request to reset controller
    //---------------------------------------------------
    if(strncmp(name, "/cgi-bin/reset?id", 17) == 0)
    {		
		ip_multyply_command_delay(__IP_RESET);
        ptFile->data = NULL;
        ptFile->len = 0;
        ptFile->index = 0;
        ptFile->pextension = NULL;
        return(ptFile);
    }	
    //---------------------------------------------------
    // Process request to toggle programm mode 
    //---------------------------------------------------
    if(strncmp(name, "/cgi-bin/prog_mode?id", 21) == 0)
    {		
		ip_multyply_command_delay(__IP_PROGRAMM_MODE);
        ptFile->data = NULL;
        ptFile->len = 0;
        ptFile->index = 0;
        ptFile->pextension = NULL;
        return(ptFile);
    }	
    //---------------------------------------------------
    // Process request to change AO 
    //---------------------------------------------------
    if(strncmp(name, "/cgi-bin/change_AO_", 19) == 0)
    {		
	//	num=(name[19]-'0')*10+(name[19]-'0');
		num=name[19]-'0';
		sign=name[21]-'0';
		delta=(name[23]-'0')*10+(name[24]-'0');
		if(sign)
			io.aoutput[num]-=delta;
		else
			io.aoutput[num]+=delta;
		if(io.aoutput[num] < 0)io.aoutput[num]=0;
		if(io.aoutput[num]>999)io.aoutput[num]=999;	
        ptFile->data = NULL;
        ptFile->len = 0;
        ptFile->index = 0;
        ptFile->pextension = NULL;
        return(ptFile);
    }	
    //---------------------------------------------------
    // Process Console TX
    //---------------------------------------------------
    if(strncmp(name, "/cgi-bin/console_tx", 19) == 0)
    {		
		if((IP_Inactive_Timer)&&(last_operation==lp_con_tx))
		{
			ptFile->data = NULL;
			ptFile->len = 0;
			ptFile->index = 0;
			ptFile->pextension = NULL;
			return(ptFile);		
		}
		last_operation=lp_con_tx;
		IP_Inactive_Timer=100;
		
		ip_con_init();
		ip_con_handle(&name[19]);
		con_init();
        ptFile->data = NULL;
        ptFile->len = 0;
        ptFile->index = 0;
        ptFile->pextension = NULL;
        return(ptFile);
    }	
    //---------------------------------------------------
    // Process Console RX
    //---------------------------------------------------
    if(strncmp(name, "/console_rx", 11) == 0)
    {		
		if((IP_Inactive_Timer)&&(last_operation==lp_con_rx))
		{
			ptFile->data = NULL;
			ptFile->len = 0;
			ptFile->index = 0;
			ptFile->pextension = NULL;
			return(ptFile);		
		}
		last_operation=lp_con_rx;
		IP_Inactive_Timer=100;
	
		ip_con_remove_n(ip_txt);
		ptFile->data = (char*)ip_txt;
        ptFile->len = strlen((char*)ip_txt);
        ptFile->index = ptFile->len;
        ptFile->pextension = NULL;
        return(ptFile);
    }	
    //
    // Check to see if the Fat File System has been enabled.
    //
    if(g_bFatFsEnabled)
    {
        //
        // Ensure that the file system access to the SSI port is active.
        //
        fs_enable(400000);

        //
        // Allocate memory for the Fat File system handle.
        //
        ptFatFile = mem_malloc(sizeof(FIL));
        if(NULL == ptFatFile)
        {
            mem_free(ptFile);
            return(NULL);
        }

        //
        // Attempt to open the file on the Fat File System.
        //
		char full_name[80];
		strcpy(full_name,"/web");
		strcat(full_name,name);
        fresult = f_open(ptFatFile, full_name, FA_READ);
        if(FR_OK == fresult)
        {
            ptFile->data = NULL;
            ptFile->len = NULL;
            ptFile->index = NULL;
            ptFile->pextension = ptFatFile;
            return(ptFile);
        }

        //
        // If we get here, we failed to find the file on the Fat File System,
        // so free up the Fat File system handle/object.
        //
        mem_free(ptFatFile);
        mem_free(ptFile);
        return(NULL);
    }
	return(NULL);
}

//*****************************************************************************
//
// Close an opened file designated by the handle.
//
//*****************************************************************************
void
fs_close(struct fs_file *file)
{
    //
    // If a Fat file was opened, free its object.
    //
    if(file->pextension)
    {
        mem_free(file->pextension);
    }

    //
    // Free the main file system object.
    //
    mem_free(file);
}

//*****************************************************************************
//
// Read the next chunck of data from the file.  Return the count of data
// that was read.  Return 0 if no data is currently available.  Return
// a -1 if at the end of file.
//
//*****************************************************************************
int
fs_read(struct fs_file *file, char *buffer, int count)
{
    int iAvailable;

    //
    // Check to see if a Fat File was opened and process it.
    //
    if(file->pextension)
    {
        unsigned short usBytesRead;

        //
        // Ensure that the file system access to the SSI port is active.
        //
        fs_enable(400000);

        //
        // Read the data.
        //
        fresult = f_read(file->pextension, buffer, count, &usBytesRead);
        if((fresult != FR_OK) || (usBytesRead == 0))
        {
            return(-1);
        }
        return((int)usBytesRead);
    }

    //
    // Check to see if more data is available.
    //
    if(file->len == file->index)
    {
        //
        // There is no remaining data.  Return a -1 for EOF indication.
        //
        return(-1);
    }

    //
    // Determine how much data we can copy.  The minimum of the 'count'
    // parameter or the available data in the file system buffer.
    //
    iAvailable = file->len - file->index;
    if(iAvailable > count)
    {
        iAvailable = count;
    }

    //
    // Copy the data.
    //
    memcpy(buffer, file->data + iAvailable, iAvailable);
    file->index += iAvailable;

    //
    // Return the count of data that we copied.
    //
    return(iAvailable);
}

#endif