//-----------------------------------------------------------------------------------
#include "main.h"
//-----------------------------------------------------------------------------------
#include "inc/hw_ints.h"
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "driverlib/debug.h"
#include "driverlib/gpio.h"
#include "driverlib/interrupt.h"
#include "driverlib/sysctl.h"
#include "driverlib/uart.h"
#include "driverlib/watchdog.h"


#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "inc/hw_timer.h"
#include "inc/hw_ints.h"
#include "driverlib/timer.h"
#include "driverlib/interrupt.h"
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"
#include "utils/uartstdio.h"
//------------------------------------------------------------------------------
// Console section
//------------------------------------------------------------------------------
//TBuffer	console_rx_buffer;
//TBuffer	console_tx_buffer;
//------------------------------------------------------------------------------
// The UART interrupt handler.
//------------------------------------------------------------------------------
void UARTIntHandler(void)
{
    u32 ulStatus;
//	u8  byte;
    ulStatus = UARTIntStatus(UART0_BASE, true);
    UARTIntClear(UART0_BASE, ulStatus);
//    while(UARTCharsAvail(UART0_BASE) && (buff_is_full(&console_rx_buffer)==0))
//    {
//		byte=UARTCharGetNonBlocking(UART0_BASE);
//		buff_put_char(&console_rx_buffer,&byte);
//		UARTCharPutNonBlocking(UART0_BASE, UARTCharGetNonBlocking(UART0_BASE));
//    }
}
//------------------------------------------------------------------------------
void con_hardware_init(u32 baund)
{
//	buff_init(&console_rx_buffer,MAX_BUFFER_LENGTH);
//	buff_init(&console_tx_buffer,MAX_BUFFER_LENGTH);
	
	// UART code start
	SysCtlPeripheralEnable(SYSCTL_PERIPH_UART0);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);
	SysCtlPeripheralReset(SYSCTL_PERIPH_UART0);

	GPIOPinTypeUART(GPIO_PORTA_BASE, GPIO_PIN_0 | GPIO_PIN_1);
    UARTConfigSetExpClk(UART0_BASE, SysCtlClockGet(), baund,
                        (UART_CONFIG_WLEN_8 | UART_CONFIG_STOP_ONE |
                         UART_CONFIG_PAR_NONE));
//    IntEnable(INT_UART0);
//    UARTIntEnable(UART0_BASE, UART_INT_RX | UART_INT_RT);
//    UARTSend((unsigned char *)" ", 1);
	// UART code finish
	
}
//-----------------------------------------------------------------------------------
u8 console_check_rx()	// if return value is 1 then something is in a buffer
{
	if(UARTCharsAvail(UART0_BASE))return 1;
	else return 0;
}
//-----------------------------------------------------------------------------------
u8 console_check_tx()
{
	if(UARTSpaceAvail(UART0_BASE))return 1;
	else return 0;
}
//-----------------------------------------------------------------------------------
void console_clear_tx_flag()
{
}
//-----------------------------------------------------------------------------------
void console_tx_byte(u8 byte)
{
	UARTCharPut(UART0_BASE, byte);
}
//-----------------------------------------------------------------------------------
u8 console_rx_byte()
{
	return UARTCharGet(UART0_BASE);
}
//-----------------------------------------------------------------------------------
void console_wait_rx_new_byte()
{
	while(console_check_rx()==0)
	{}
}
//-----------------------------------------------------------------------------------
void sendchar(u8 sym)
{
	UARTCharPut(UART0_BASE, sym);
}
//-----------------------------------------------------------------------------------
s16 recchar()
{
	if(console_check_rx())
	{
		return console_rx_byte();
	}
	else
		return -1;
}
//-----------------------------------------------------------------------------------
// Flash section
//-----------------------------------------------------------------------------------
void FGet(u32 Addr,u8 *Data,u16 Len)
{
	u8 i;
	for(i=0;i<Len;i++)
	{
		*Data=*((u8 in_flash *)Addr+i);
		Data++;
	}
}
//-----------------------------------------------------------------------------------
void GetFlashStr(u8 *word,u8* ptr)
{
	//while(*word!=0)word++;
	while((*(in_flash u8*)ptr)!=0)
	{
		*word=(*(in_flash u8*)ptr);
		ptr++;
		word++;
	}	
	*word=0;
}
//-----------------------------------------------------------------------------------
// Timer section
//-----------------------------------------------------------------------------------
void Timer_Init()
{
	SysCtlPeripheralEnable(SYSCTL_PERIPH_TIMER0);
    TimerConfigure(TIMER0_BASE, TIMER_CFG_16_BIT_PAIR | TIMER_CFG_B_PERIODIC);
    TimerLoadSet(TIMER0_BASE, TIMER_B, SysCtlClockGet() / 100000);
    TimerIntEnable(TIMER0_BASE, TIMER_TIMB_TIMEOUT);
    IntEnable(INT_TIMER0B);
    TimerEnable(TIMER0_BASE, TIMER_B);	
}
//-----------------------------------------------------------------------------------
void Timer0BIntHandler(void)
{
	TimerIntClear(TIMER0_BASE, TIMER_TIMB_TIMEOUT);
	Timer_1ms_IRQ();
}

//-----------------------------------------------------------------------------------
void reset()
{
	// Software reset
//	SysCtlReset();
	// Hardware reset
	SysCtlPeripheralEnable(SYSCTL_PERIPH_WDOG0);
    WatchdogReloadSet(WATCHDOG0_BASE, 1000);
    WatchdogResetEnable(WATCHDOG0_BASE);
    WatchdogEnable(WATCHDOG0_BASE);	
	while(1){};
}
//-----------------------------------------------------------------------------------
// Watchdog section
//-----------------------------------------------------------------------------------
void watchdog_init()
{
#ifndef	__NO_WHATCHDOG
	SysCtlPeripheralEnable(SYSCTL_PERIPH_WDOG0);
	IntEnable(INT_WATCHDOG);
	WatchdogReloadSet(WATCHDOG0_BASE, SysCtlClockGet());
	WatchdogResetEnable(WATCHDOG0_BASE);
	WatchdogEnable(WATCHDOG0_BASE);
#endif
}
//-----------------------------------------------------------------------------------
void hardware_init()
{
//	MCUCR=0X01;
//	MCUCR=0X00;
	// Watchdog disable
//	WDTCR = (1<<WDCE) | (1<<WDE);
//	WDTCR = 0x00;
//	TWCR=0;
// External interrupts
//	EICRB=0x20;	// all ints - rising adge
//	EIMSK=0x40;	
//	PORTE&=~p_buzzer;
//	DDRE|=p_buzzer;
}
/*
//-----------------------------------------------------------------------------------
// EEprom section
//-----------------------------------------------------------------------------------
void EEPut(u8 *Data,u16 Addr,u8 Len)
{
	u8 i;
	for(i=0;i<Len;i++)
	{
		__EEPUT(Addr+i,*Data);
		watchdog_reset();
		Data++;
	}
}
//-----------------------------------------------------------------------------------
void EEGet(u8 *Data,u16 Addr,u8 Len)
{
	u8 i;
	for(i=0;i<Len;i++)
	{
		__EEGET(*Data,Addr+i);
		watchdog_reset();
		Data++;
	}
}
//-----------------------------------------------------------------------------------
void reset()
{
	// Watchdog enable
	WDTCR = (1<<WDCE) | (1<<WDE);
	WDTCR = 0x08;
	while(1);
}
*/
//-----------------------------------------------------------------------------------
void watchdog_reset()
{

#ifndef	__NO_WHATCHDOG
	WatchdogReloadSet(WATCHDOG0_BASE, SysCtlClockGet());
#endif
}
/*
//-----------------------------------------------------------------------------------
void led_on()
{
#ifndef __HW030	
	led_port&=~led_out;
#endif
}
//-----------------------------------------------------------------------------------
void led_off()
{
#ifndef __HW030		
	led_port|=led_out;	
#endif
}
//-----------------------------------------------------------------------------------
void led_dir_out()
{
#ifndef __HW030	
	led_port_dir|=led_out;
#endif	
}
//-----------------------------------------------------------------------------------
u8 led_check()
{
#ifndef __HW030		
	if(led_pins & led_out)return 1;
	return 0;
#endif	
}
//-----------------------------------------------------------------------------------
void led_toggle()
{
#ifndef __HW030		
	if(led_pins & led_out)
		led_port&=~led_out;
	else
		led_port|=led_out;	
#endif	
}
//-----------------------------------------------------------------------------------
// Buzzer section
//-----------------------------------------------------------------------------------
void beep_on()
{
	PORTE|=p_buzzer;
}
//-----------------------------------------------------------------------------------
void beep_off()
{
	PORTE&=~p_buzzer;
}
//-----------------------------------------------------------------------------------
void beep_init()
{
//	beep_port&=~beep_p;beep_dir|=beep_p;
}
//-----------------------------------------------------------------------------------
void no_operation()
{}
*/
//-----------------------------------------------------------------------------------
void enable_interrupt()
{
//	__enable_interrupt();
}
//-----------------------------------------------------------------------------------
void disable_interrupt()
{
//	__disable_interrupt();
}
//------------------------------------------------------------------------------
// The UART interrupt handler.
//------------------------------------------------------------------------------
void upc_IntHandler(void)
{
    u32 ulStatus;
//	u8  byte;
    ulStatus = UARTIntStatus(UART1_BASE, true);
    UARTIntClear(UART1_BASE, ulStatus);
#ifndef __NO_SERIAL_INTERFACE
//	while(UARTCharsAvail(UART1_BASE))
//		upc_RXHandler();
	
//    while(UARTCharsAvail(UART0_BASE) && (buff_is_full(&console_rx_buffer)==0))
//    {
//		byte=UARTCharGetNonBlocking(UART0_BASE);
//		buff_put_char(&console_rx_buffer,&byte);
//		UARTCharPutNonBlocking(UART0_BASE, UARTCharGetNonBlocking(UART0_BASE));
//    }
#endif
}
//------------------------------------------------------------------------------
void upc_hardware_init(u32 baund)
{
#ifndef __NO_SERIAL_INTERFACE
	// UART code start
	SysCtlPeripheralEnable(SYSCTL_PERIPH_UART1);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOD);
	SysCtlPeripheralReset(SYSCTL_PERIPH_UART1);

	GPIOPinTypeUART(GPIO_PORTD_BASE, GPIO_PIN_2 | GPIO_PIN_3);
    UARTConfigSetExpClk(UART1_BASE, SysCtlClockGet(), baund,
                        (UART_CONFIG_WLEN_8 | UART_CONFIG_STOP_ONE |
                         UART_CONFIG_PAR_NONE));
	UARTFIFOEnable(UART1_BASE);
	UARTFIFOLevelSet(UART1_BASE, UART_FIFO_TX1_8, UART_FIFO_TX1_8);
	rx_mode();
    //IntEnable(INT_UART1);
	//UARTIntEnable(UART1_BASE, UART_INT_RX);
    UARTCharPut(UART1_BASE, ' ');
	// UART code finish
#endif	
}
//-----------------------------------------------------------------------------------
void rx_mode(void)
{
#ifndef __NO_SERIAL_INTERFACE
	// Port D
    GPIOPinTypeGPIOOutput(GPIO_PORTD_BASE,GPIO_PIN_4);
    GPIOPinWrite(GPIO_PORTD_BASE, GPIO_PIN_4, 0);
#endif
}
//-----------------------------------------------------------------------------------
void tx_mode(void)
{
	// Port D
#ifndef __NO_SERIAL_INTERFACE
    GPIOPinTypeGPIOOutput(GPIO_PORTD_BASE,GPIO_PIN_4);
    GPIOPinWrite(GPIO_PORTD_BASE, GPIO_PIN_4, GPIO_PIN_4);
#endif
}
//-----------------------------------------------------------------------------------	
void upc_tx_byte(u8 byte)
{
#ifndef __NO_SERIAL_INTERFACE
	UARTCharPut(UART1_BASE, byte);
#endif
}
//-----------------------------------------------------------------------------------
u8 upc_rx_byte()
{
#ifndef __NO_SERIAL_INTERFACE
	return UARTCharGet(UART1_BASE);
#endif
}
//-----------------------------------------------------------------------------------
u8 upc_check_tx()
{
#ifndef __NO_SERIAL_INTERFACE
	if(UARTSpaceAvail(UART1_BASE))return 1;
	else return 0;
#endif
}
//-----------------------------------------------------------------------------------
void upc_clear_tx_flag()
{
}

//-----------------------------------------------------------------------------------
u8 restore_ip_core_step = 0;
volatile u32 restore_ip_core_delay = 0;
volatile u32 restore_ip_core_cycle_delay = 3*60;
//-----------------------------------------------------------------------------------
void restore_ip_core_init()
{
	restore_ip_core_step = 1;
}
//-----------------------------------------------------------------------------------
void restore_ip_core_loop()
{
	if (restore_ip_core_cycle_delay == 0){
		restore_ip_core_step = 1;
		restore_ip_core_cycle_delay = 5*60;
	}
	switch (restore_ip_core_step){
	case 0:
		break;
	case 1:
		update_ip_address=1;
		new_ip=htonl(lwIPLocalIPAddrGet());
		new_mask=htonl(lwIPLocalNetMaskGet());
		new_gw=htonl(lwIPLocalGWAddrGet());		
		
		ID[0]=192;
		ID[1]=168;
		ID[2]=1;
		ID[3]=250;
		IP4_ADDR_MAKE(new_ip,ID[0],ID[1],ID[2],ID[3]);
		restore_ip_core_delay = 100;
		restore_ip_core_step ++;
		break;
	case 2:
		if (restore_ip_core_delay == 0)
			restore_ip_core_step ++;
		break;
	case 3:
		id_read();
		update_ip_address=1;
		IP4_ADDR_MAKE(new_ip,ID[0],ID[1],ID[2],ID[3]);
		restore_ip_core_step = 0;
		break;
	}
}
//-----------------------------------------------------------------------------------
