//------------------------------------------------------------------------------
#include "main.h"
//------------------------------------------------------------------------------
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "inc/hw_i2c.h"
#include "driverlib/i2c.h"
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"
#include "utils/uartstdio.h"
//------------------------------------------------------------------------------
volatile unsigned short i2c_timer = 0;
//-----------------------------------------------------------------------------
void I2C_Init(void)
{
	//-------------------------------------------
	// I2C init
	//-------------------------------------------
	// Port B
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOB);
	//SysCtlPeripheralReset(SYSCTL_PERIPH_GPIOB);

   // I2C1 is not configured for I2C as default
    // -> GPIOPinConfigure() is needed
	GPIOPinConfigure(GPIO_PB2_I2C0SCL);
	GPIOPinConfigure(GPIO_PB3_I2C0SDA);
    // Setup clock for 20Mhz
//    SysCtlClockSet(SYSCTL_SYSDIV_10 | SYSCTL_USE_PLL | SYSCTL_OSC_MAIN | SYSCTL_XTAL_16MHZ);
    // Turn on I2C1 and reset to a known state
	
	GPIOPinTypeI2C(GPIO_PORTB_BASE, GPIO_PIN_2 | GPIO_PIN_3);
	
    SysCtlPeripheralEnable(SYSCTL_PERIPH_I2C0);
    SysCtlPeripheralReset(SYSCTL_PERIPH_I2C0);
    // Configure the PortB pins for I2C1
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOB);
    // Set GPIO Pins for Open-Drain operation
    GPIOPadConfigSet(GPIO_PORTB_BASE, GPIO_PIN_2, GPIO_STRENGTH_2MA, GPIO_PIN_TYPE_OD_WPU);
    GPIOPadConfigSet(GPIO_PORTB_BASE, GPIO_PIN_3, GPIO_STRENGTH_2MA, GPIO_PIN_TYPE_OD_WPU);
    // Give control to the I2C Module
    GPIODirModeSet(GPIO_PORTB_BASE, GPIO_PIN_2, GPIO_DIR_MODE_HW);
    GPIODirModeSet(GPIO_PORTB_BASE, GPIO_PIN_3, GPIO_DIR_MODE_HW);
    // Enable and Initialize Master module and Master Clock using 100kbps
    I2CMasterInitExpClk(I2C0_MASTER_BASE, SysCtlClockGet(), 1);	
}
//-----------------------------------------------------------------------------
/*
sint I2C_Write(uchar adr, uchar *write_data, uchar write_data_size)
{
	sint r=Ok;
	int	i;
#if FRAM_ENABLE == 0
	return r;
#endif		
	if(write_data_size==0)return;
	if(write_data_size==1)
	{
		I2CMasterSlaveAddrSet(I2C0_MASTER_BASE, adr, false);
		I2CMasterDataPut(I2C0_MASTER_BASE, *write_data++);
		I2CMasterControl(I2C0_MASTER_BASE, I2C_MASTER_CMD_BURST_SEND_START);
		while(I2CMasterBusy(I2C0_MASTER_BASE)){ if (i2c_timer == 0) return;};
		 // send data array
		for(i=1; i < (write_data_size-1); i++){
			I2CMasterDataPut(I2C0_MASTER_BASE, *write_data++);
			I2CMasterControl(I2C0_MASTER_BASE, I2C_MASTER_CMD_BURST_SEND_CONT);
			while(I2CMasterBusy(I2C0_MASTER_BASE)){ if (i2c_timer == 0) return;}
		}
	}
}*/
//-----------------------------------------------------------------------------
sint I2C_NiMasterWrite(uchar adr,
                       uchar *write_data1, sint write_data1_size,
                       uchar *write_data2, sint write_data2_size )
{
	sint r=Ok;
	int	i;
#if FRAM_ENABLE == 0
	return r;
#endif		
	adr=adr>>1;

	i2c_timer = 10;
//	IntMasterDisable();	
//	I2CMasterSlaveAddrSet(I2C0_MASTER_BASE, adr, false);
//	for(i=0; i < (write_data1_size); i++){
//		I2CMasterDataPut(I2C0_MASTER_BASE, *write_data1++);
//		I2CMasterControl(I2C0_MASTER_BASE, I2C_MASTER_CMD_SINGLE_SEND);
//		while(I2CMasterBusy(I2C0_MASTER_BASE)){ if (i2c_timer == 0) return;}
//	}

	I2CMasterSlaveAddrSet(I2C0_MASTER_BASE, adr, false);
	I2CMasterDataPut(I2C0_MASTER_BASE, *write_data1++);
	I2CMasterControl(I2C0_MASTER_BASE, I2C_MASTER_CMD_BURST_SEND_START);
	while(I2CMasterBusy(I2C0_MASTER_BASE)){ if (i2c_timer == 0) return ERRORS_I2C;};
     // send data array 1
    for(i=1; i < (write_data1_size); i++){
        I2CMasterDataPut(I2C0_MASTER_BASE, *write_data1++);
        I2CMasterControl(I2C0_MASTER_BASE, I2C_MASTER_CMD_BURST_SEND_CONT);
        while(I2CMasterBusy(I2C0_MASTER_BASE)){ if (i2c_timer == 0) return ERRORS_I2C;}
    }


    // send data array 2
    for(i=0; i < (write_data2_size-1); i++){
        I2CMasterDataPut(I2C0_MASTER_BASE, *write_data2++);
        I2CMasterControl(I2C0_MASTER_BASE, I2C_MASTER_CMD_BURST_SEND_CONT);
        while(I2CMasterBusy(I2C0_MASTER_BASE)){ if (i2c_timer == 0) return ERRORS_I2C;}
    }
    // send last byte
    I2CMasterDataPut(I2C0_MASTER_BASE, *write_data2++);
    I2CMasterControl(I2C0_MASTER_BASE, I2C_MASTER_CMD_BURST_SEND_FINISH);
    while(I2CMasterBusy(I2C0_MASTER_BASE)){ if (i2c_timer == 0) return ERRORS_I2C;}
	
    // send data array 2
//    for(i=0; i < (write_data2_size); i++){
//        I2CMasterDataPut(I2C0_MASTER_BASE, *write_data2++);
//        I2CMasterControl(I2C0_MASTER_BASE, I2C_MASTER_CMD_SINGLE_SEND);
//        while(I2CMasterBusy(I2C0_MASTER_BASE)){ if (i2c_timer == 0) return;}
//    }
//	IntMasterEnable();	
	return r;
}
//-----------------------------------------------------------------------------
sint I2C_NiMasterRead(uchar adr,
                      uchar *write_data, sint write_data_size,
                      uchar *read_data, sint read_data_size   )
{
	sint r=Ok;
//	int rd[20];
	int	i;
//	int	k;
//	int	j=0;
#if FRAM_ENABLE == 0
	return r;
#endif
	adr=adr>>1;
    i2c_timer = 10;
//	IntMasterDisable();	
	if(write_data_size>1)	
	{
		I2CMasterSlaveAddrSet(I2C0_MASTER_BASE, adr, false);
		I2CMasterDataPut(I2C0_MASTER_BASE, *write_data++);
		I2CMasterControl(I2C0_MASTER_BASE, I2C_MASTER_CMD_BURST_SEND_START);
		while(I2CMasterBusy(I2C0_MASTER_BASE)){ if (i2c_timer == 0) return ERRORS_I2C;};
		 // send data array 1
		if(write_data_size>2)
		for(i=1; i < (write_data_size-1); i++){
			I2CMasterDataPut(I2C0_MASTER_BASE, *write_data++);
			I2CMasterControl(I2C0_MASTER_BASE, I2C_MASTER_CMD_BURST_SEND_CONT);
			while(I2CMasterBusy(I2C0_MASTER_BASE)){ if (i2c_timer == 0) return ERRORS_I2C;}
		}
		// send last byte
		I2CMasterDataPut(I2C0_MASTER_BASE, *write_data++);
		I2CMasterControl(I2C0_MASTER_BASE, I2C_MASTER_CMD_BURST_SEND_FINISH);
		while(I2CMasterBusy(I2C0_MASTER_BASE)){ if (i2c_timer == 0) return ERRORS_I2C;}
	}
	else
	{
		I2CMasterSlaveAddrSet(I2C0_MASTER_BASE, adr, false);
//		for(i=0; i < (write_data_size); i++){
			I2CMasterDataPut(I2C0_MASTER_BASE, *write_data++);
			I2CMasterControl(I2C0_MASTER_BASE, I2C_MASTER_CMD_SINGLE_SEND);
			while(I2CMasterBusy(I2C0_MASTER_BASE)){ if (i2c_timer == 0) return ERRORS_I2C;}
//		}
	}
	
	I2CMasterSlaveAddrSet(I2C0_MASTER_BASE, adr, true);
	// burst receive
	if(read_data_size>2)	
	{	
		I2CMasterControl(I2C0_MASTER_BASE, I2C_MASTER_CMD_BURST_RECEIVE_START);
		while(I2CMasterBusy(I2C0_MASTER_BASE)){ if (i2c_timer == 0) return ERRORS_I2C;}	
		*read_data++ = I2CMasterDataGet(I2C0_MASTER_BASE);
		for(i = 1; i < (read_data_size - 1); i++)
		{
			I2CMasterControl(I2C0_MASTER_BASE, I2C_MASTER_CMD_BURST_RECEIVE_CONT);
			while(I2CMasterBusy(I2C0_MASTER_BASE)){ if (i2c_timer == 0) return ERRORS_I2C;}
			*read_data++ = I2CMasterDataGet(I2C0_MASTER_BASE);
		}
		I2CMasterControl(I2C0_MASTER_BASE, I2C_MASTER_CMD_BURST_RECEIVE_FINISH);
		while(I2CMasterBusy(I2C0_MASTER_BASE)){ if (i2c_timer == 0) return ERRORS_I2C;}
		*read_data++ = I2CMasterDataGet(I2C0_MASTER_BASE);
//		IntMasterEnable();
		return r;
	}
	else
	{	
		for(i = 0; i < read_data_size; i++)
		{
			I2CMasterControl(I2C0_MASTER_BASE, I2C_MASTER_CMD_SINGLE_RECEIVE);
			while(I2CMasterBusy(I2C0_MASTER_BASE)){ if (i2c_timer == 0) return ERRORS_I2C;}	
			*read_data++ = I2CMasterDataGet(I2C0_MASTER_BASE);
		}
//		IntMasterEnable();
		return r;
	}
//	IntMasterEnable();
}
//-----------------------------------------------------------------------------
sint I2C_NiMasterRead_NoInt(uchar adr,
                      uchar *write_data, uchar write_data_size,
                      uchar *read_data, uchar read_data_size   )
{
	sint r=Ok;
//	int rd[20];
	int	i;
//	int	k;
//	int	j=0;
#if FRAM_ENABLE == 0
	return r;
#endif
	adr=adr>>1;
    i2c_timer = 10;
//	IntMasterDisable();	
	if(write_data_size>1)	
	{
		I2CMasterSlaveAddrSet(I2C0_MASTER_BASE, adr, false);
		I2CMasterDataPut(I2C0_MASTER_BASE, *write_data++);
		I2CMasterControl(I2C0_MASTER_BASE, I2C_MASTER_CMD_BURST_SEND_START);
		while(I2CMasterBusy(I2C0_MASTER_BASE)){ if (i2c_timer == 0) return ERRORS_I2C;};
		 // send data array 1
		if(write_data_size>2)
		for(i=1; i < (write_data_size-1); i++){
			I2CMasterDataPut(I2C0_MASTER_BASE, *write_data++);
			I2CMasterControl(I2C0_MASTER_BASE, I2C_MASTER_CMD_BURST_SEND_CONT);
			while(I2CMasterBusy(I2C0_MASTER_BASE)){ if (i2c_timer == 0) return ERRORS_I2C;}
		}
		// send last byte
		I2CMasterDataPut(I2C0_MASTER_BASE, *write_data++);
		I2CMasterControl(I2C0_MASTER_BASE, I2C_MASTER_CMD_BURST_SEND_FINISH);
		while(I2CMasterBusy(I2C0_MASTER_BASE)){ if (i2c_timer == 0) return ERRORS_I2C;}
	}
	else
	{
		I2CMasterSlaveAddrSet(I2C0_MASTER_BASE, adr, false);
//		for(i=0; i < (write_data_size); i++){
			I2CMasterDataPut(I2C0_MASTER_BASE, *write_data++);
			I2CMasterControl(I2C0_MASTER_BASE, I2C_MASTER_CMD_SINGLE_SEND);
			while(I2CMasterBusy(I2C0_MASTER_BASE)){ if (i2c_timer == 0) return ERRORS_I2C;}
//		}
	}
	
	I2CMasterSlaveAddrSet(I2C0_MASTER_BASE, adr, true);
	// burst receive
	if(read_data_size>2)	
	{	
		I2CMasterControl(I2C0_MASTER_BASE, I2C_MASTER_CMD_BURST_RECEIVE_START);
		while(I2CMasterBusy(I2C0_MASTER_BASE)){ if (i2c_timer == 0) return ERRORS_I2C;}	
		*read_data++ = I2CMasterDataGet(I2C0_MASTER_BASE);
		for(i = 1; i < (read_data_size - 1); i++)
		{
			I2CMasterControl(I2C0_MASTER_BASE, I2C_MASTER_CMD_BURST_RECEIVE_CONT);
			while(I2CMasterBusy(I2C0_MASTER_BASE)){ if (i2c_timer == 0) return ERRORS_I2C;}
			*read_data++ = I2CMasterDataGet(I2C0_MASTER_BASE);
		}
		I2CMasterControl(I2C0_MASTER_BASE, I2C_MASTER_CMD_BURST_RECEIVE_FINISH);
		while(I2CMasterBusy(I2C0_MASTER_BASE)){ if (i2c_timer == 0) return ERRORS_I2C;}
		*read_data++ = I2CMasterDataGet(I2C0_MASTER_BASE);
//		IntMasterEnable();
		return r;
	}
	else
	{	
		for(i = 0; i < read_data_size; i++)
		{
			I2CMasterControl(I2C0_MASTER_BASE, I2C_MASTER_CMD_SINGLE_RECEIVE);
			while(I2CMasterBusy(I2C0_MASTER_BASE)){ if (i2c_timer == 0) return ERRORS_I2C;}	
			*read_data++ = I2CMasterDataGet(I2C0_MASTER_BASE);
		}
//		IntMasterEnable();
		return r;
	}
//	IntMasterEnable();
}
//-----------------------------------------------------------------------------

