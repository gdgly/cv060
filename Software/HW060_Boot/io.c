//*****************************************************************************
//
// io.c - I/O routines for the enet_io example application.
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

#include "inc/hw_nvic.h"
#include "inc/hw_ints.h"
#include "inc/hw_memmap.h"
#include "inc/hw_pwm.h"
#include "inc/hw_types.h"
#include "driverlib/gpio.h"
#include "driverlib/pwm.h"
#include "driverlib/adc.h"
#include "driverlib/sysctl.h"
#include "utils/ustdlib.h"
#include "io.h"
#include "define.h"

//*****************************************************************************
//
// Global Variables for the Frequency and Duty cycle
//
//*****************************************************************************
unsigned long g_ulFrequency = 10000;
unsigned long g_ulDutyCycle;

//*****************************************************************************
//
// Initialize the IO used in this demo
// 1. STATUS LED on Port F pin 0
// 2. PWM on Port D Pin 1 (PWM1)
//
//*****************************************************************************
void
io_init(void)
{
    unsigned long ulPWMClock;
	//-------------------------------------------
	// GPIO init
	//-------------------------------------------
	// Port F
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
	//SysCtlPeripheralReset(SYSCTL_PERIPH_GPIOF);
    GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE,GPIO_PIN_0);
    GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_0, 0);
    GPIOPinTypeGPIOInput(GPIO_PORTF_BASE,(GPIO_PIN_1));	
	// Port D
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOD);
	//SysCtlPeripheralReset(SYSCTL_PERIPH_GPIOD);
    GPIOPinTypeGPIOOutput(GPIO_PORTD_BASE,GPIO_PIN_0);
    GPIOPinWrite(GPIO_PORTD_BASE, GPIO_PIN_0, 0);
    GPIOPinTypeGPIOInput(GPIO_PORTD_BASE,(GPIO_PIN_1));
	// Port E
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOE);
	//SysCtlPeripheralReset(SYSCTL_PERIPH_GPIOE);
    GPIOPinTypeGPIOOutput(GPIO_PORTE_BASE,GPIO_PIN_3);
    GPIOPinWrite(GPIO_PORTE_BASE, GPIO_PIN_3, 0);
	// Port B
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOB);
	//SysCtlPeripheralReset(SYSCTL_PERIPH_GPIOB);
    GPIOPinTypeGPIOOutput(GPIO_PORTB_BASE,(GPIO_PIN_4+GPIO_PIN_5+GPIO_PIN_6));
    GPIOPinWrite(GPIO_PORTB_BASE, (GPIO_PIN_4+GPIO_PIN_5+GPIO_PIN_6), 0);	
	// Port A
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);
	//SysCtlPeripheralReset(SYSCTL_PERIPH_GPIOA);
    GPIOPinTypeGPIOInput(GPIO_PORTA_BASE,(GPIO_PIN_3+GPIO_PIN_7));
	// Port C
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOC);
	//SysCtlPeripheralReset(SYSCTL_PERIPH_GPIOC);
    GPIOPinTypeGPIOInput(GPIO_PORTC_BASE,(GPIO_PIN_4+GPIO_PIN_5+GPIO_PIN_6+GPIO_PIN_7));
    //-------------------------------------------
    // PWM init
    //-------------------------------------------	
    //
    // Enable Port G1 for PWM output.
    //
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOG);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOB);
	
	GPIOPinConfigure(GPIO_PG0_PWM0);
	GPIOPinConfigure(GPIO_PF0_PWM0);
	GPIOPinConfigure(GPIO_PB0_PWM2);
	
    GPIOPinTypePWM(GPIO_PORTG_BASE,GPIO_PIN_1);
    GPIOPinTypePWM(GPIO_PORTF_BASE,GPIO_PIN_0);
	GPIOPinTypePWM(GPIO_PORTB_BASE,GPIO_PIN_0);
    //
    // Enable the PWM generator.
    //
    SysCtlPeripheralEnable(SYSCTL_PERIPH_PWM);
    //
    // Configure the PWM generator for count down mode with immediate updates
    // to the parameters.
    //
    PWMGenConfigure(PWM_BASE, PWM_GEN_0, PWM_GEN_MODE_DOWN | PWM_GEN_MODE_NO_SYNC);
	PWMGenConfigure(PWM_BASE, PWM_GEN_1, PWM_GEN_MODE_DOWN | PWM_GEN_MODE_NO_SYNC);
	//PWMGenConfigure(PWM_BASE, PWM_GEN_2, PWM_GEN_MODE_DOWN | PWM_GEN_MODE_NO_SYNC);
    //
    // Divide the PWM clock by 4.
    //
    SysCtlPWMClockSet(SYSCTL_PWMDIV_4);
    //
    // Get the PWM clock.
    //
    ulPWMClock = SysCtlClockGet()/4;
    //
    // Intialize the PWM frequency and duty cycle.
    //
//    g_ulFrequency = 10000;
//    g_ulDutyCycle = 50;
    //
    // Set the period of PWM1.
    //
    PWMGenPeriodSet(PWM_BASE, PWM_GEN_0, ulPWMClock / g_ulFrequency);
	PWMGenPeriodSet(PWM_BASE, PWM_GEN_1, ulPWMClock / g_ulFrequency);
	//PWMGenPeriodSet(PWM_BASE, PWM_GEN_2, ulPWMClock / g_ulFrequency);
    //
    // Set the pulse width of PWM1.
    //
//	PWMPulseWidthSet(PWM_BASE, PWM_OUT_0, ((ulPWMClock * 20)/100) / g_ulFrequency);
//	PWMPulseWidthSet(PWM_BASE, PWM_OUT_1, ((ulPWMClock * 50)/100) / g_ulFrequency);
//	PWMPulseWidthSet(PWM_BASE, PWM_OUT_2, ((ulPWMClock * 80)/100) / g_ulFrequency);
	PWMPulseWidthSet(PWM_BASE, PWM_OUT_0, ((ulPWMClock * 1)/100) / g_ulFrequency);
	PWMPulseWidthSet(PWM_BASE, PWM_OUT_1, ((ulPWMClock * 1)/100) / g_ulFrequency);
	PWMPulseWidthSet(PWM_BASE, PWM_OUT_2, ((ulPWMClock * 1)/100) / g_ulFrequency);

	PWMOutputState(PWM_BASE, PWM_OUT_0_BIT | PWM_OUT_1_BIT | PWM_OUT_2_BIT, true);
	//
    // Start the timers in generator 0.
    //
    PWMGenEnable(PWM_BASE, PWM_GEN_0);
	PWMGenEnable(PWM_BASE, PWM_GEN_1);
	//PWMGenEnable(PWM_BASE, PWM_GEN_2);
	
	// ADC Init
	SysCtlPeripheralEnable(SYSCTL_PERIPH_ADC0);
	ADCSequenceConfigure(ADC0_BASE, 3, ADC_TRIGGER_PROCESSOR, 0);
	ADCSequenceStepConfigure(ADC0_BASE, 3, 0, ADC_CTL_CH1 | ADC_CTL_IE | ADC_CTL_END);
	ADCSequenceEnable(ADC0_BASE, 3);
	ADCIntClear(ADC0_BASE, 3);
	ADCProcessorTrigger(ADC0_BASE, 3);
}
void
//------------------------------------------------------------------------------
// Process IO DO
//------------------------------------------------------------------------------
do_process(unsigned __packed long  *dout)
{

	unsigned char tmp=*dout;
	tmp=0;
	if(tmp & 0x01)
	    GPIOPinWrite(GPIO_PORTD_BASE, GPIO_PIN_0, GPIO_PIN_0);
	else
	    GPIOPinWrite(GPIO_PORTD_BASE, GPIO_PIN_0, 0);

	if(tmp & 0x10)
	    GPIOPinWrite(GPIO_PORTB_BASE, GPIO_PIN_4, GPIO_PIN_4);
	else
	    GPIOPinWrite(GPIO_PORTB_BASE, GPIO_PIN_4, 0);	

	if(tmp & 0x20)
	    GPIOPinWrite(GPIO_PORTB_BASE, GPIO_PIN_5, GPIO_PIN_5);
	else
	    GPIOPinWrite(GPIO_PORTB_BASE, GPIO_PIN_5, 0);	

	if(tmp & 0x40)
	    GPIOPinWrite(GPIO_PORTB_BASE, GPIO_PIN_6, GPIO_PIN_6);
	else
	    GPIOPinWrite(GPIO_PORTB_BASE, GPIO_PIN_6, 0);	
	
	if(tmp & 0x80)
		GPIOPinWrite(GPIO_PORTE_BASE, GPIO_PIN_3, GPIO_PIN_3);		
	else	
		GPIOPinWrite(GPIO_PORTE_BASE, GPIO_PIN_3, 0);
	
}
//------------------------------------------------------------------------------
// Process IO DI
//------------------------------------------------------------------------------
unsigned long di_process()
{

	unsigned long di=0;
	unsigned long adc_res=0;
	if(GPIOPinRead(GPIO_PORTF_BASE, GPIO_PIN_1)==0)di|=0x00000001;
	if(GPIOPinRead(GPIO_PORTA_BASE, GPIO_PIN_7)==0)di|=0x00000002;
	if(GPIOPinRead(GPIO_PORTA_BASE, GPIO_PIN_3)==0)di|=0x00000004;
	if(GPIOPinRead(GPIO_PORTC_BASE, GPIO_PIN_4)==0)di|=0x00000008;
	if(GPIOPinRead(GPIO_PORTC_BASE, GPIO_PIN_5)==0)di|=0x00000010;
	if(GPIOPinRead(GPIO_PORTC_BASE, GPIO_PIN_6)==0)di|=0x00000020;
	if(GPIOPinRead(GPIO_PORTC_BASE, GPIO_PIN_7)==0)di|=0x00000040;
	if(GPIOPinRead(GPIO_PORTD_BASE, GPIO_PIN_1)==0)di|=0x00000080;

	return di;
}
//------------------------------------------------------------------------------
// Process IO DI ADC
//------------------------------------------------------------------------------
unsigned long di_adc_process()
{
	unsigned long di=0;
	unsigned long adc_res=0;	

	if(ADCIntStatus(ADC0_BASE, 3, false))
	{
		ADCSequenceDataGet(ADC0_BASE, 3, &di);
		ADCProcessorTrigger(ADC0_BASE, 3);
	}

	return di;
}
//------------------------------------------------------------------------------
// Process IO AO
//------------------------------------------------------------------------------
void ao_process(unsigned __packed short *ao ,unsigned char num)
{
	unsigned long ulPWMClock;
	unsigned short AO[5];
	AO[0]=*ao++;
	AO[1]=*ao++;
	AO[2]=*ao++;
	ulPWMClock = SysCtlClockGet()/4;
	AO[0]=AO[0]/10;
	AO[1]=AO[1]/10;
	AO[2]=AO[2]/10;
	if(AO[0]>100)AO[0]=100;
	if(AO[1]>100)AO[1]=100;
	if(AO[2]>100)AO[2]=100;
	if(num>0)PWMPulseWidthSet(PWM_BASE, PWM_OUT_0, ((ulPWMClock * AO[0])/100) / g_ulFrequency);
	if(num>1)PWMPulseWidthSet(PWM_BASE, PWM_OUT_1, ((ulPWMClock * AO[1])/100) / g_ulFrequency);
	if(num>2)PWMPulseWidthSet(PWM_BASE, PWM_OUT_2, ((ulPWMClock * AO[2])/100) / g_ulFrequency);
}
//-----------------------------------------------------------------------------------
// Analog inputs define
#define CS_PORT			GPIO_PORTB_BASE
#define p_adc_cs		GPIO_PIN_1

// SPI
#define SPI_PORT		GPIO_PORTA_BASE
#define p_spi_miso		GPIO_PIN_4
#define p_spi_mosi		GPIO_PIN_5
#define p_spi_clk		GPIO_PIN_2
//#define p_spi_ss		GPIO_PIN_1
#define p_at45_cs		GPIO_PIN_6

// Signal select
#define CHANNEL_PORT	GPIO_PORTE_BASE
#define p_ch0			GPIO_PIN_0
#define p_ch1			GPIO_PIN_1
#define p_ch2			GPIO_PIN_2

void adc_hardware_init()
{

	// Port A
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);
    GPIOPinTypeGPIOOutput(SPI_PORT, p_spi_mosi | p_spi_clk | p_at45_cs);
	GPIOPinTypeGPIOInput(SPI_PORT, p_spi_miso );	
	
	// Port B
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOB);
    GPIOPinTypeGPIOOutput(CS_PORT, p_adc_cs );
	
	// Port E
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOE);
    GPIOPinTypeGPIOOutput(CHANNEL_PORT, p_ch0 | p_ch1 | p_ch2);
	
	
	GPIOPinWrite(SPI_PORT, p_at45_cs, p_at45_cs);
	GPIOPinWrite(SPI_PORT, p_spi_mosi | p_spi_clk , 0);
	
	GPIOPinWrite(SPI_PORT, p_adc_cs, p_adc_cs);

	GPIOPinWrite(CHANNEL_PORT, p_ch0 | p_ch1 | p_ch2, 0);
	
	
//	CS_PORT|=p_adc_cs;
//	CS_DIR|=p_adc_cs;
	
//	SPI_DIR|=(p_spi_mosi+p_spi_clk+p_spi_ss);
//	SPI_DIR&=~(p_spi_miso);	
//	SPI_PORT&=~(p_spi_miso+p_spi_mosi+p_spi_clk);		
//	SPI_PORT|=(p_spi_ss);	

//	CHANNEL_PORT&=~(p_ch0+p_ch1+p_ch2);		
//	CHANNEL_DIR|=(p_ch0+p_ch1+p_ch2);

//	SPCR=(0<<SPIE)+(1<<SPE)+(0<<DORD)+(1<<MSTR)+(0<<CPOL)+(0<<CPHA)+(2);
}
//------------------------------------------------------------------------------
void adc_set_channel(unsigned char ch)
{

	unsigned char tmp=0;
	switch(ch)
	{
		case 0: tmp=ch; break;
		case 1: tmp=ch; break;
		case 2: tmp=ch; break;
		case 3: tmp=5; break;
		case 4: tmp=4; break;
	}
	// Addr 0
	if(tmp & 0x01)
		GPIOPinWrite(CHANNEL_PORT, p_ch0 , p_ch0);	
	else
		GPIOPinWrite(CHANNEL_PORT, p_ch0 , 0);			

	// Addr 1
	if(tmp & 0x02)
		GPIOPinWrite(CHANNEL_PORT, p_ch1 , p_ch1);	
	else
		GPIOPinWrite(CHANNEL_PORT, p_ch1 , 0);		
	
	// Addr 2
	if(tmp & 0x04)
		GPIOPinWrite(CHANNEL_PORT, p_ch2 , p_ch2);	
	else
		GPIOPinWrite(CHANNEL_PORT, p_ch2 , 0);	
}
//------------------------------------------------------------------------------
extern short 			ad_res;
extern unsigned long	ad_tmp32;
extern unsigned short	ad_res_int;
short adc_conversion()
{

	unsigned short  tmp;
	unsigned char	tmp8[3];	
	float	ftmp=0;
	int i;
	unsigned char	bit;
//#if ADC_ENABLE	
#if 1
	//__disable_interrupt();	
	IntMasterDisable();	
	
	//CS_PORT&=~p_adc_cs;	
	GPIOPinWrite(CS_PORT, p_adc_cs, 0);
	// 1th byte
	bit=0;
	for(i=0;i<8;i++)
	{
		GPIOPinWrite(SPI_PORT, p_spi_clk , p_spi_clk);
		GPIOPinWrite(SPI_PORT, p_spi_clk , p_spi_clk);
		if(GPIOPinRead(SPI_PORT, p_spi_miso)!=0)
			bit|=0x01;
		bit<<=1;
		GPIOPinWrite(SPI_PORT, p_spi_clk , 0);
		GPIOPinWrite(SPI_PORT, p_spi_clk , 0);
	}
	tmp8[0]=bit;
	
	// 2th byte	
	bit=0;
	for(i=0;i<8;i++)
	{
		GPIOPinWrite(SPI_PORT, p_spi_clk , p_spi_clk);
		GPIOPinWrite(SPI_PORT, p_spi_clk , p_spi_clk);
		if(GPIOPinRead(SPI_PORT, p_spi_miso)!=0)
			bit|=0x01;
		bit<<=1;
		GPIOPinWrite(SPI_PORT, p_spi_clk , 0);
		GPIOPinWrite(SPI_PORT, p_spi_clk , 0);
	}
	tmp8[1]=bit;

	ad_tmp32=tmp8[0];
	ad_tmp32=ad_tmp32<<8;
	ad_tmp32|=tmp8[1];

	tmp=ad_tmp32>>2;	
	tmp&=0xfff;
	
	//CS_PORT|=p_adc_cs;	
	GPIOPinWrite(CS_PORT, p_adc_cs, p_adc_cs);
	//__enable_interrupt();		
	 IntMasterEnable();
	ad_res_int=tmp;
	ftmp=tmp;
	ftmp=ftmp/0x0fff;
	ftmp*=10000;
	
#endif	
	ad_res=(short)ftmp;		
	
	return ad_res;

}
//*****************************************************************************
// AT45 Hardware dependent part
//*****************************************************************************
#ifdef USE_AT45

#define AT45PORT			GPIO_PORTA_BASE
	#define b_at45_SCK 		GPIO_PIN_2
	#define b_at45_SO 		GPIO_PIN_4
	#define b_at45_nCS0 	GPIO_PIN_6
	#define b_at45_SI 		GPIO_PIN_5

void AT45_Init()
{	
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);
    GPIOPinTypeGPIOOutput(AT45PORT, b_at45_SCK | b_at45_nCS0 | b_at45_SI);
	GPIOPinTypeGPIOInput(AT45PORT, b_at45_SO );	
	
	GPIOPinWrite(AT45PORT, b_at45_SCK, 0);
	GPIOPinWrite(AT45PORT, b_at45_SI, 0);
	GPIOPinWrite(AT45PORT, b_at45_SI, b_at45_SI);
}
//*****************************************************************************
void AT45_Start_Cycle()
{
	GPIOPinWrite(AT45PORT, b_at45_nCS0, b_at45_nCS0);
	GPIOPinWrite(AT45PORT, b_at45_SCK, 0);
	GPIOPinWrite(AT45PORT, b_at45_nCS0, 0);
}
//*****************************************************************************
void AT45_End_Cycle()
{
	GPIOPinWrite(AT45PORT, b_at45_SCK, 0);
	GPIOPinWrite(AT45PORT, b_at45_nCS0, b_at45_nCS0);
}
//*****************************************************************************
void AT45_Enable()
{
	GPIOPinWrite(AT45PORT, b_at45_nCS0, b_at45_nCS0);
	GPIOPinWrite(AT45PORT, b_at45_nCS0, 0);
}
//*****************************************************************************
void AT45_Disable()
{
	GPIOPinWrite(AT45PORT, b_at45_nCS0, b_at45_nCS0);
}
//*****************************************************************************
u8 AT45_Byte_Read()
{
	u8 tmp=0,i;
	for(i=0;i<8;i++)
	{
		GPIOPinWrite(AT45PORT, b_at45_SCK, b_at45_SCK);
		tmp=tmp<<1;		
		if(GPIOPinRead(AT45PORT, b_at45_SO)!=0)
			tmp|=1;
		GPIOPinWrite(AT45PORT, b_at45_SCK, 0);
	}
	return tmp;
}
//*****************************************************************************
void AT45_Byte_Write(u8 Byte)
{
	u8 tmp,i;
	tmp=Byte;

	for(i=0;i<8;i++)
	{		
		if(tmp & 0x80)
			GPIOPinWrite(AT45PORT, b_at45_SI, b_at45_SI);
		else
			GPIOPinWrite(AT45PORT, b_at45_SI, 0);
		tmp=tmp<<1;
		GPIOPinWrite(AT45PORT, b_at45_SCK, b_at45_SCK);
		GPIOPinWrite(AT45PORT, b_at45_SCK, 0);
	}
}
#endif
//------------------------------------------------------------------------------
extern void StartApplication();
void __Jump_To_App(u32 ADDR)
{
	IntMasterDisable();
	StartApplication();
}
//------------------------------------------------------------------------------