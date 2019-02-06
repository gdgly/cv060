//*****************************************************************************
//
// lmi_fs.c - File System Processing for enet_io application.
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

#if USE_AT45_FS ==0 

#include "controller_data_define.h"


#include <string.h>
#include "inc/hw_types.h"
#include "utils/lwiplib.h"
#include "utils/ustdlib.h"
#include "httpserver_raw/fs.h"
#include "httpserver_raw/fsdata.h"
#include "io.h"
#include "fatfs/src/ff.h"
#include "fatfs/src/diskio.h"

#include <stdlib.h>


//*****************************************************************************
//
// Include the file system data for this application.  This file is generated
// by the makefsfile utility, using the following command (all on one line):
//
//     makefsfile -i fs -o io_fsdata.h -r -h
//
// If any changes are made to the static content of the web pages served by the
// application, this script must be used to regenerate io_fsdata.h in order
// for those changes to be picked up by the web server.
//
//*****************************************************************************
#include "io_fsdata.h"

//*****************************************************************************
//
// Global Settings for demo page content.
//
//*****************************************************************************
static char g_cSampleTextBuffer[16] = {0};
//---------------------- Peter ------------------------------------------------
void ShowTemperature(unsigned char *out,short *val);
void ShowTemperatureShort(unsigned char *out,short *val);
void ShowShort_6sym(unsigned char *out,short *val);

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

static FATFS g_sFatFs;
static volatile tBoolean g_bFatFsEnabled = false;
FRESULT fresult;
DIR g_sDirObject;
FIL file;

//*****************************************************************************
static void
fs_enable(unsigned long ulFrequency)
{
}
//*****************************************************************************
void
fs_init(void)
{
}
//*****************************************************************************
void
fs_tick(unsigned long ulTickMS)
{}
//*****************************************************************************
//
// Open a file and return a handle to the file, if found.  Otherwise,
// return NULL.  This function also looks for special filenames used to
// provide specific status information or to control various subsystems.
// These filenames are used by the JavaScript on the "IO Control Demo 1"
// example web page.
//
//*****************************************************************************
struct fs_file *
fs_open(char *name)
{
    char *data;
    int i;
    char hour,min,sec,date,mon,year;
    char num,sign,delta;
    const struct fsdata_file *ptTree;
    struct fs_file *ptFile = NULL;

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
        char pcBuf[5][5];
		char *ptr;
		int	 digit;
		char end=0;
		char ip[4];
        data = name;
        data += 21;
        i = 0;
		
//		update_ip_address=1;
		new_ip=htonl(lwIPLocalIPAddrGet());
		new_mask=htonl(lwIPLocalNetMaskGet());
		new_gw=htonl(lwIPLocalGWAddrGet());		
		
		digit=0;
		ptr=&pcBuf[digit][0];	
		
		while((data[i]!=0)&&(end==0))
		{
			switch(data[i])
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
				*ptr=data[i];
				ptr++;
				*ptr=0;
				break;
			}
			i++;
		}
		ip[0]=atoi(&pcBuf[0][0]);
		ip[1]=atoi(&pcBuf[1][0]);
		ip[2]=atoi(&pcBuf[2][0]);
		ip[3]=atoi(&pcBuf[3][0]);
		
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

        //
        // Get the frequency of the PWM
        //
//        usprintf(pcBuf,"%d",io_get_pwmfreq());
	//	usprintf(pcBuf,"%08x",lwIPLocalIPAddrGet());	
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
        char pcBuf[5][5];
		char *ptr;
		int	 digit;
		char end=0;
		char ip[4];
        data = name;
        data += 18;
        i = 0;

		update_mask_address=1;
		new_ip=htonl(lwIPLocalIPAddrGet());
		new_mask=htonl(lwIPLocalNetMaskGet());
		new_gw=htonl(lwIPLocalGWAddrGet());		

		digit=0;
		ptr=&pcBuf[digit][0];	
		
		while((data[i]!=0)&&(end==0))
		{
			switch(data[i])
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
				*ptr=data[i];
				ptr++;
				*ptr=0;
				break;
			}
			i++;
		}
		ip[0]=atoi(&pcBuf[0][0]);
		ip[1]=atoi(&pcBuf[1][0]);
		ip[2]=atoi(&pcBuf[2][0]);
		ip[3]=atoi(&pcBuf[3][0]);
		
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
        char pcBuf[5][5];
		char *ptr;
		int	 digit;
		char end=0;
		char ip[4];
        data = name;
        data += 16;
        i = 0;

		update_gw_address=1;
		new_ip=htonl(lwIPLocalIPAddrGet());
		new_mask=htonl(lwIPLocalNetMaskGet());
		new_gw=htonl(lwIPLocalGWAddrGet());		

		digit=0;
		ptr=&pcBuf[digit][0];	
		
		while((data[i]!=0)&&(end==0))
		{
			switch(data[i])
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
				*ptr=data[i];
				ptr++;
				*ptr=0;
				break;
			}
			i++;
		}
		ip[0]=atoi(&pcBuf[0][0]);
		ip[1]=atoi(&pcBuf[1][0]);
		ip[2]=atoi(&pcBuf[2][0]);
		ip[3]=atoi(&pcBuf[3][0]);
		
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
		memset(pcBuf,'0',sizeof(pcBuf));
		pcBuf[sizeof(pcBuf)-1]=0;
		
		for(i=0;i<NUM_DOUT;i++)
			if(io.dout & (1<<i))pcBuf[i+0]='1';
			else                pcBuf[i+0]='0';
		
		for(i=0;i<NUM_DIN;i++)
			if(io.din & (1<<i)) pcBuf[i+10]='1';
			else                pcBuf[i+10]='0';			

		
		for(i=0;i<NUM_AIN;i++)
			ShowShort_6sym(&pcBuf[6*i+20],(short*)&io.ainput[i]);

		for(i=0;i<NUM_AOUT;i++)
			ShowShort_6sym(&pcBuf[6*i+50],(short*)&io.aoutput[i]);
		
//				
		Show_Time(&pcBuf[80], &MenuRegs.Time);
		
		for(i=0;i<(80);i++)
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
        static char pcBuf[40];
	memset(pcBuf,'0',sizeof(pcBuf));
	pcBuf[sizeof(pcBuf)-1]=0;
		
	usprintf(pcBuf, "Error 1\n\rError 2\n\rError 3\n\rError 4\n\r");
		
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
	if(io.aoutput[num]<0)io.aoutput[num]=0;
	if(io.aoutput[num]>999)io.aoutput[num]=999;	
        ptFile->data = NULL;
        ptFile->len = 0;
        ptFile->index = 0;
        ptFile->pextension = NULL;
        return(ptFile);
    }			
    //
    // If I can't find it there, look in the rest of the main file system
    //
//    else
    {
        //
        // Initialize the file system tree pointer to the root of the linked list.
        //
        ptTree = FS_ROOT;

        //
        // Begin processing the linked list, looking for the requested file name.
        //
        while(NULL != ptTree)
        {
            //
            // Compare the requested file "name" to the file name in the
            // current node.
            //
            if(strncmp(name, (char *)ptTree->name, ptTree->len) == 0)
            {
                //
                // Fill in the data pointer and length values from the
                // linked list node.
                //
                ptFile->data = (char *)ptTree->data;
                ptFile->len = ptTree->len;

                //
                // For now, we setup the read index to the end of the file,
                // indicating that all data has been read.
                //
                ptFile->index = ptTree->len;

                //
                // We are not using any file system extensions in this
                // application, so set the pointer to NULL.
                //
                ptFile->pextension = NULL;

                //
                // Exit the loop and return the file system pointer.
                //
                break;
            }

            //
            // If we get here, we did not find the file at this node of the linked
            // list.  Get the next element in the list.
            //
            ptTree = ptTree->next;
        }
    }

    //
    // If we didn't find the file, ptTee will be NULL.  Make sure we
    // return a NULL pointer if this happens.
    //
    if(NULL == ptTree)
    {
        mem_free(ptFile);
        ptFile = NULL;
    }

    //
    // Return the file system pointer.
    //
    return(ptFile);
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
    // Check to see if a command (pextension = 1).
    //
    if(file->pextension == (void *)1)
    {
        //
        // Nothting to do for this file type.
        //
        file->pextension = NULL;
        return(-1);
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