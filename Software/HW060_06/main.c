//------------------------------------------------------------------------------
//
// main.c - I/O controler with a web server
//
//------------------------------------------------------------------------------
#include <string.h>
#include "inc/hw_ints.h"
#include "inc/hw_memmap.h"
#include "inc/hw_nvic.h"
#include "inc/hw_types.h"

#include "driverlib/ethernet.h"
#include "driverlib/flash.h"
#include "driverlib/gpio.h"
#include "driverlib/interrupt.h"
#include "driverlib/sysctl.h"
#include "driverlib/systick.h"
#include "driverlib/uart.h"

#include "utils/locator.h"
#include "utils/lwiplib.h"
#include "utils/uartstdio.h"
#include "utils/ustdlib.h"
#include "httpserver_raw/httpd.h"
#include "drivers/rit128x96x4.h"
#include "io.h"
#include "cgifuncs.h"

#include "../../../../Controller/System/Misc/types.h"
#include "../../../../Controller/System/controller_data_define.h"
#include "../../../../Controller/System/define.h"
//------------------------------------------------------------------------------
// Defines for setting up the system clock.
//------------------------------------------------------------------------------
#define SYSTICKHZ               100
#define SYSTICKMS               (1000 / SYSTICKHZ)
#define SYSTICKUS               (1000000 / SYSTICKHZ)
#define SYSTICKNS               (1000000000 / SYSTICKHZ)
//------------------------------------------------------------------------------
#define FLAG_SYSTICK            0
static volatile unsigned long g_ulFlags;
//------------------------------------------------------------------------------
extern void httpd_init(void);
//------------------------------------------------------------------------------
// SSI tag indices for each entry in the g_pcSSITags array.
//------------------------------------------------------------------------------
#define SSI_INDEX_LEDSTATE  0
#define SSI_INDEX_PWMSTATE  1
#define SSI_INDEX_PWMFREQ   2
#define SSI_INDEX_PWMDUTY   3
#define SSI_INDEX_FORMVARS  4
//------------------------------------------------------------------------------
static const char *g_pcConfigSSITags[] =
{
    "LEDtxt",        // SSI_INDEX_LEDSTATE
    "PWMtxt",        // SSI_INDEX_PWMSTATE
    "PWMfreq",       // SSI_INDEX_PWMFREQ
    "PWMduty",       // SSI_INDEX_PWMDUTY
    "FormVars"       // SSI_INDEX_FORMVARS
};
//------------------------------------------------------------------------------
#define NUM_CONFIG_SSI_TAGS     (sizeof(g_pcConfigSSITags) / sizeof (char *))
//------------------------------------------------------------------------------
static char *ControlCGIHandler(int iIndex, int iNumParams, char *pcParam[],
                              char *pcValue[]);
static char *SetTextCGIHandler(int iIndex, int iNumParams, char *pcParam[],
                              char *pcValue[]);

//------------------------------------------------------------------------------
static int SSIHandler(int iIndex, char *pcInsert, int iInsertLen);
//------------------------------------------------------------------------------
#define CGI_INDEX_CONTROL       0
#define CGI_INDEX_TEXT          1
//------------------------------------------------------------------------------
static const tCGI g_psConfigCGIURIs[] =
{
    { "/iocontrol.cgi", ControlCGIHandler },      // CGI_INDEX_CONTROL
    { "/settxt.cgi", SetTextCGIHandler }          // CGI_INDEX_TEXT
};
//------------------------------------------------------------------------------
#define NUM_CONFIG_CGI_URIS     (sizeof(g_psConfigCGIURIs) / sizeof(tCGI))
//------------------------------------------------------------------------------
#define DEFAULT_CGI_RESPONSE    "/io_cgi.ssi"
//------------------------------------------------------------------------------
#define PARAM_ERROR_RESPONSE    "/perror.htm"

#define JAVASCRIPT_HEADER                                                     \
    "<script type='text/javascript' language='JavaScript'><!--\n"
#define JAVASCRIPT_FOOTER                                                     \
    "//--></script>\n"
//------------------------------------------------------------------------------
#ifndef DHCP_EXPIRE_TIMER_SECS
#define DHCP_EXPIRE_TIMER_SECS  45
#endif
//------------------------------------------------------------------------------
unsigned char pucMACArray[8];
//------------------------------------------------------------------------------
#ifdef DEBUG
void
__error__(char *pcFilename, unsigned long ulLine)
{
}
#endif
//------------------------------------------------------------------------------
//
// This CGI handler is called whenever the web browser requests iocontrol.cgi.
//
//------------------------------------------------------------------------------
static char *
ControlCGIHandler(int iIndex, int iNumParams, char *pcParam[], char *pcValue[])
{
    tBoolean bParamError;
    long lLEDState, lPWMState, lPWMDutyCycle, lPWMFrequency;

    //
    // We have not encountered any parameter errors yet.
    //
    bParamError = false;

    //
    // Get each of the 4 expected parameters.
    //
    lLEDState = FindCGIParameter("LEDOn", pcParam, iNumParams);
    lPWMState = FindCGIParameter("PWMOn", pcParam, iNumParams);
    lPWMDutyCycle = GetCGIParam("PWMDutyCycle", pcParam, pcValue, iNumParams,
                                &bParamError);
    lPWMFrequency = GetCGIParam("PWMFrequency", pcParam, pcValue, iNumParams,
                                &bParamError);

    //
    // Was there any error reported by the parameter parser?
    //
    if(bParamError || (lPWMDutyCycle < 0) || (lPWMDutyCycle > 100) ||
       (lPWMFrequency < 200) || (lPWMFrequency > 20000))
    {
        return(PARAM_ERROR_RESPONSE);
    }

    //
    // We got all the parameters and the values were within the expected ranges
    // so go ahead and make the changes.
    //
    io_set_led((lLEDState == -1) ? false : true);
    io_pwm_dutycycle((unsigned long)lPWMDutyCycle);
    io_pwm_freq((unsigned long)lPWMFrequency);
    io_set_pwm((lPWMState == -1) ? false : true);

    //
    // Send back the default response page.
    //
    return(DEFAULT_CGI_RESPONSE);
}

//------------------------------------------------------------------------------
//
// This CGI handler is called whenever the web browser requests settxt.cgi.
//
//------------------------------------------------------------------------------
static char *
SetTextCGIHandler(int iIndex, int iNumParams, char *pcParam[], char *pcValue[])
{
    long lStringParam;
    char pcDecodedString[24];

    //
    // Find the parameter that has the string we need to display.
    //
    lStringParam = FindCGIParameter("DispText", pcParam, iNumParams);

    //
    // If the parameter was not found, show the error page.
    //
    if(lStringParam == -1)
    {
        return(PARAM_ERROR_RESPONSE);
    }

    //
    // The parameter is present. We need to decode the text for display.
    //
    DecodeFormString(pcValue[lStringParam], pcDecodedString, 24);

    //
    // Claim the SSI for communication with the display.
    //
    RIT128x96x4Enable(1000000);

    //
    // Erase the previous string and overwrite it with the new one.
    //
    RIT128x96x4StringDraw("                      ", 0, 64, 12);
    RIT128x96x4StringDraw(pcDecodedString, 0, 64, 12);

    //
    // Release the SSI.
    //
    RIT128x96x4Disable();

    //
    // Tell the HTTPD server which file to send back to the client.
    //
    return(DEFAULT_CGI_RESPONSE);
}

//------------------------------------------------------------------------------
//
// This function is called by the HTTP server whenever it encounters an SSI
// tag in a web page.  The iIndex parameter provides the index of the tag in
// the g_pcConfigSSITags array. This function writes the substitution text
// into the pcInsert array, writing no more than iInsertLen characters.
//
//------------------------------------------------------------------------------
static int
SSIHandler(int iIndex, char *pcInsert, int iInsertLen)
{
    unsigned long ulVal;

    //
    // Which SSI tag have we been passed?
    //
    switch(iIndex)
    {
        case SSI_INDEX_LEDSTATE:
            io_get_ledstate(pcInsert, iInsertLen);
            break;

        case SSI_INDEX_PWMSTATE:
            io_get_pwmstate(pcInsert, iInsertLen);
            break;

        case SSI_INDEX_PWMFREQ:
            ulVal = io_get_pwmfreq();
            usnprintf(pcInsert, iInsertLen, "%d", ulVal);
            break;

        case SSI_INDEX_PWMDUTY:
            ulVal = io_get_pwmdutycycle();
            usnprintf(pcInsert, iInsertLen, "%d", ulVal);
            break;

        case SSI_INDEX_FORMVARS:
            usnprintf(pcInsert, iInsertLen,
                      "%sps=%d;\nls=%d;\npf=%d;\npd=%d;\n%s",
                      JAVASCRIPT_HEADER,
                      io_is_pwm_on(),
                      io_is_led_on(),
                      io_get_pwmfreq(),
                      io_get_pwmdutycycle(),
                      JAVASCRIPT_FOOTER);
            break;

        default:
            usnprintf(pcInsert, iInsertLen, "??");
            break;
    }

    //
    // Tell the server how many characters our insert string contains.
    //
    return(strlen(pcInsert));
}

//------------------------------------------------------------------------------
//
// Display an lwIP type IP Address.
//
//------------------------------------------------------------------------------
void
DisplayIPAddress(unsigned long ipaddr, unsigned long ulCol,
                 unsigned long ulRow)
{
    char pucBuf[16];
    unsigned char *pucTemp = (unsigned char *)&ipaddr;

    //
    // Convert the IP Address into a string.
    //
    usprintf(pucBuf, "%d.%d.%d.%d", pucTemp[0], pucTemp[1], pucTemp[2],
             pucTemp[3]);

    //
    // Display the string.
    //
    RIT128x96x4StringDraw(pucBuf, ulCol, ulRow, 15);
}

//------------------------------------------------------------------------------
//
// The interrupt handler for the SysTick interrupt.
//
//------------------------------------------------------------------------------
void
SysTickIntHandler(void)
{
    //
    // Indicate that a SysTick interrupt has occurred.
    //
    HWREGBITW(&g_ulFlags, FLAG_SYSTICK) = 1;

    //
    // Call the lwIP timer handler.
    //
    lwIPTimer(SYSTICKMS);
}

//------------------------------------------------------------------------------
//
// Required by lwIP library to support any host-related timer functions.
//
//------------------------------------------------------------------------------
void
lwIPHostTimerHandler(void)
{
    static unsigned long ulLastIPAddress = 0;
    unsigned long ulIPAddress;

    static unsigned long ulLastMASKAddress = 0;
    unsigned long ulMASKAddress;

    static unsigned long ulLastGWAddress = 0;
    unsigned long ulGWAddress;
	
    ulIPAddress   = lwIPLocalIPAddrGet();
    ulMASKAddress = lwIPLocalNetMaskGet();
    ulGWAddress   = lwIPLocalGWAddrGet();

    //
    // If IP Address has not yet been assigned, update the display accordingly
    //
    if(ulIPAddress == 0)
    {
        static int iColumn = 6;

        //
        // Update status bar on the display.
        //
        RIT128x96x4Enable(1000000);
        if(iColumn < 12)
        {
            RIT128x96x4StringDraw(" >", 114, 24, 15);
            RIT128x96x4StringDraw("< ", 0, 24, 15);
            RIT128x96x4StringDraw("*",iColumn, 24, 7);
        }
        else
        {
            RIT128x96x4StringDraw(" *",iColumn - 6, 24, 7);
        }

        iColumn += 4;
        if(iColumn > 114)
        {
            iColumn = 6;
            RIT128x96x4StringDraw(" >", 114, 24, 15);
        }
        RIT128x96x4Disable();
    }

    //
    // Check if IP address has changed, and display if it has.
    //
    else if((ulLastIPAddress != ulIPAddress)||(ulLastMASKAddress != ulMASKAddress)||(ulLastGWAddress != ulGWAddress))
    {
        ulLastIPAddress   = ulIPAddress;
        ulLastMASKAddress = ulMASKAddress;
        ulLastGWAddress   = ulGWAddress;

        RIT128x96x4Enable(1000000);
        RIT128x96x4StringDraw("                       ", 0, 16, 15);
        RIT128x96x4StringDraw("                       ", 0, 24, 15);
        RIT128x96x4StringDraw("IP:   ", 0, 16, 15);
        RIT128x96x4StringDraw("MASK: ", 0, 24, 15);
        RIT128x96x4StringDraw("GW:   ", 0, 32, 15);
        DisplayIPAddress(ulIPAddress, 36, 16);
        ulIPAddress = lwIPLocalNetMaskGet();
        DisplayIPAddress(ulIPAddress, 36, 24);
        ulIPAddress = lwIPLocalGWAddrGet();
        DisplayIPAddress(ulIPAddress, 36, 32);
        RIT128x96x4Disable();
    }
}
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//
// This example demonstrates the use of the Ethernet Controller and lwIP
// TCP/IP stack to control various peripherals on the board via a web
// browser.
//
//------------------------------------------------------------------------------
int main(void)
{
    unsigned long ulUser0, ulUser1;
    //
    // Set the clocking to run directly from the crystal.
    //
    SysCtlClockSet(SYSCTL_SYSDIV_4 | SYSCTL_USE_PLL | SYSCTL_OSC_MAIN |
                   SYSCTL_XTAL_8MHZ);

    //
    // Initialize the OLED display.
    //
    RIT128x96x4Init(1000000);
    RIT128x96x4StringDraw("Web-Based I/O Control", 0, 0, 15);
    RIT128x96x4StringDraw("Browser Message:", 0, 53, 15);

    //
    // Enable and Reset the Ethernet Controller.
    //
    SysCtlPeripheralEnable(SYSCTL_PERIPH_ETH);
    SysCtlPeripheralReset(SYSCTL_PERIPH_ETH);

    //
    // Enable Port F for Ethernet LEDs.
    //  LED0        Bit 3   Output
    //  LED1        Bit 2   Output
    //
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
    GPIOPinTypeEthernetLED(GPIO_PORTF_BASE, GPIO_PIN_2 | GPIO_PIN_3);

    //
    // Configure SysTick for a periodic interrupt.
    //
    SysTickPeriodSet(SysCtlClockGet() / SYSTICKHZ);
    SysTickEnable();
    SysTickIntEnable();

    //
    // Enable processor interrupts.
    //
    IntMasterEnable();

    //
    // Configure the hardware MAC address for Ethernet Controller filtering of
    // incoming packets.
    //
    // For the LM3S6965 Evaluation Kit, the MAC address will be stored in the
    // non-volatile USER0 and USER1 registers.  These registers can be read
    // using the FlashUserGet function, as illustrated below.
    //
    FlashUserGet(&ulUser0, &ulUser1);
    if((ulUser0 == 0xffffffff) || (ulUser1 == 0xffffffff))
    {
        //
        // We should never get here.  This is an error if the MAC address
        // has not been programmed into the device.  Exit the program.
        //
        RIT128x96x4StringDraw("MAC Address", 0, 16, 15);
        RIT128x96x4StringDraw("Not Programmed!", 0, 24, 15);
        while(1);
    }

    //
    // Convert the 24/24 split MAC address from NV ram into a 32/16 split
    // MAC address needed to program the hardware registers, then program
    // the MAC address into the Ethernet Controller registers.
    //
    pucMACArray[0] = ((ulUser0 >>  0) & 0xff);
    pucMACArray[1] = ((ulUser0 >>  8) & 0xff);
    pucMACArray[2] = ((ulUser0 >> 16) & 0xff);
    pucMACArray[3] = ((ulUser1 >>  0) & 0xff);
    pucMACArray[4] = ((ulUser1 >>  8) & 0xff);
    pucMACArray[5] = ((ulUser1 >> 16) & 0xff);

    //
    // Initialze the lwIP library, using DHCP.
    //
//    lwIPInit(pucMACArray, 0, 0, 0, IPADDR_USE_DHCP);
    lwIPInit(pucMACArray, 0xC0A8010A, 0xFFFFFF00, 0xC0A80101, IPADDR_USE_STATIC);	// Peter
	
    //
    // Setup the device locator service.
    //
    LocatorInit();
    LocatorMACAddrSet(pucMACArray);
    LocatorAppTitleSet("EK-LM3S8962 enet_io");

    //
    // Initialize a sample httpd server.
    //
    httpd_init();

    //
    // Pass our tag information to the HTTP server.
    //
    http_set_ssi_handler(SSIHandler, g_pcConfigSSITags,
                         NUM_CONFIG_SSI_TAGS);

    //
    // Pass our CGI handlers to the HTTP server.
    //
    http_set_cgi_handlers(g_psConfigCGIURIs, NUM_CONFIG_CGI_URIS);

    //
    // Initialize IO controls
    //
    io_init();

    //
    // Loop forever.  All the work is done in interrupt handlers.
    //
    while(1)
    {
		extern char update_ip_address;
		extern char update_mask_address;
		extern char update_gw_address;

		extern unsigned long new_ip;
		extern unsigned long new_mask;
		extern unsigned long new_gw;		
		
		if(update_ip_address)
		{
			update_ip_address=0;
			unsigned long ipaddr=lwIPLocalIPAddrGet();
			unsigned long ipmask=lwIPLocalNetMaskGet();
			unsigned long ipgw=lwIPLocalGWAddrGet();
			
			ipaddr=(new_ip);
			ipmask=htonl(ipmask);
			ipgw=htonl(ipgw);		
			lwIPNetworkConfigChange(ipaddr, ipmask, ipgw, IPADDR_USE_STATIC);			
		}
		if(update_mask_address)
		{
			update_mask_address=0;
			unsigned long ipaddr=lwIPLocalIPAddrGet();
			unsigned long ipmask=lwIPLocalNetMaskGet();
			unsigned long ipgw=lwIPLocalGWAddrGet();
			
			ipaddr=htonl(ipaddr);
			ipmask=(new_mask);
			ipgw=htonl(ipgw);
			lwIPNetworkConfigChange(ipaddr, ipmask, ipgw, IPADDR_USE_STATIC);			
		}		
		if(update_gw_address)
		{
			update_gw_address=0;
			unsigned long ipaddr=lwIPLocalIPAddrGet();
			unsigned long ipmask=lwIPLocalNetMaskGet();
			unsigned long ipgw=lwIPLocalGWAddrGet();
			
			ipaddr=htonl(ipaddr);
			ipmask=htonl(ipmask);
			ipgw=(new_gw);	
			lwIPNetworkConfigChange(ipaddr, ipmask, ipgw, IPADDR_USE_STATIC);				
		}				
    }
}
//------------------------------------------------------------------------------
