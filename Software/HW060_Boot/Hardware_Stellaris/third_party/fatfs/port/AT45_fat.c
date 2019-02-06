#include "main.h"

#if USE_AT45_FS

#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "driverlib/gpio.h"
#include "driverlib/ssi.h"
#include "driverlib/sysctl.h"
#include "fatfs/src/diskio.h"


void AT45_Init();
void AT45_Start_Cycle();
void AT45_End_Cycle();
u8 AT45_Byte_Read();
void AT45_Byte_Write(u8 Byte);
void AT45_Enable();
void AT45_Disable();

// asserts the CS pin to the card
static
void SELECT(void)
{
}

// de-asserts the CS pin to the card
static
void DESELECT(void)
{
}

/*--------------------------------------------------------------------------

   Module Private Functions

---------------------------------------------------------------------------*/

static volatile
DSTATUS Stat = STA_NOINIT;    /* Disk status */

static volatile
BYTE Timer1, Timer2;    /* 100Hz decrement timer */

static
BYTE CardType;            /* b0:MMC, b1:SDC, b2:Block addressing */

static
BYTE PowerFlag = 0;     /* indicates if "power" is on */

/*-----------------------------------------------------------------------*/
/* Transmit a byte to MMC via SPI  (Platform dependent)                  */
/*-----------------------------------------------------------------------*/

//static
//void xmit_spi(BYTE dat)
//{
//	AT45_Byte_Write(dat);
//}


/*-----------------------------------------------------------------------*/
/* Receive a byte from MMC via SPI  (Platform dependent)                 */
/*-----------------------------------------------------------------------*/

static
BYTE rcvr_spi (void)
{
    DWORD rcvdat;
	rcvdat=AT45_Byte_Read();
    return (BYTE)rcvdat;
}


//static
//void rcvr_spi_m (BYTE *dst)
//{
//    *dst = rcvr_spi();
//}

/*-----------------------------------------------------------------------*/
/* Wait for card ready                                                   */
/*-----------------------------------------------------------------------*/

static
BYTE wait_ready (void)
{
    BYTE res=0xff;
	while((AT45_Status_Read() & 0x80)==0){watchdog_reset();}	
    return res;
}


/*-----------------------------------------------------------------------*/
/* Send 80 or so clock transitions with CS and DI held high. This is     */
/* required after card power up to get it into SPI mode                  */
/*-----------------------------------------------------------------------*/
static
void send_initial_clock_train(void)
{

}

/*-----------------------------------------------------------------------*/
/* Power Control  (Platform dependent)                                   */
/*-----------------------------------------------------------------------*/
/* When the target system does not support socket power control, there   */
/* is nothing to do in these functions and chk_power always returns 1.   */

static
void power_on (void)
{
    send_initial_clock_train();
    PowerFlag = 1;
}

// set the SSI speed to the max setting
//static
//void set_max_speed(void)
//{
//}

static
void power_off (void)
{
    PowerFlag = 0;
}

static
int chk_power(void)        /* Socket power state: 0=off, 1=on */
{
    return PowerFlag;
}

/*--------------------------------------------------------------------------

   Public Functions

---------------------------------------------------------------------------*/


/*-----------------------------------------------------------------------*/
/* Initialize Disk Drive                                                 */
/*-----------------------------------------------------------------------*/
long sector_number = 0; 

DSTATUS disk_initialize (
    BYTE drv        /* Physical drive nmuber (0) */
)
{
    BYTE n, ty;//, ocr[4];


    if (drv) return STA_NOINIT;            /* Supports only single drive */
    if (Stat & STA_NODISK) return Stat;    /* No card in the socket */
    watchdog_reset();
	AT45_Init();
    power_on();                            /* Force socket power on */
	n=AT45_Status_Read() & 0x3c;
	switch(n) {
	case 0x1c:
		sector_number = 1024;
		break;
	case 0x2c:
		sector_number = 4096;
		break;
	default:
		Stat |= STA_NODISK;
		return Stat;
		break;
	}
	
    ty = 0xb2; // Block addressing

    CardType = ty;
	
    DESELECT();            /* CS = H */

    if (ty)
	{
		/* Initialization succeded */
        Stat &= ~STA_NOINIT;        /* Clear STA_NOINIT */

    } else
	{
		/* Initialization failed */
        power_off();
    }

    return Stat;
}



/*-----------------------------------------------------------------------*/
/* Get Disk Status                                                       */
/*-----------------------------------------------------------------------*/

DSTATUS disk_status (
    BYTE drv        /* Physical drive nmuber (0) */
)
{
    if (drv) return STA_NOINIT;        /* Supports only single drive */
    return Stat;
}



/*-----------------------------------------------------------------------*/
/* Read Sector(s)                                                        */
/*-----------------------------------------------------------------------*/

DRESULT disk_read (
    BYTE drv,            /* Physical drive nmuber (0) */
    BYTE *buff,            /* Pointer to the data buffer to store read data */
    DWORD sector,        /* Start sector number (LBA) */
    BYTE count            /* Sector count (1..255) */
)
{
    if (drv || !count) return RES_PARERR;
    if (Stat & STA_NOINIT) return RES_NOTRDY;

    if (!(CardType & 4)) sector *= 512;    /* Convert to byte address if needed */

    AT45_Init();

    if (count == 1) {    /* Single block read */
			AT45_Long_Read(sector,buff,512);
            count = 0;
    }
    else
	{                /* Multiple block read */
           do
		   {
			    watchdog_reset();
                AT45_Long_Read(sector,buff,512);
                buff   += 512;
				sector += 512;
           } while (--count);
    }

    return count ? RES_ERROR : RES_OK;
}



/*-----------------------------------------------------------------------*/
/* Write Sector(s)                                                       */
/*-----------------------------------------------------------------------*/

#if _READONLY == 0
DRESULT disk_write (
    BYTE drv,            /* Physical drive nmuber (0) */
    const BYTE *buff,    /* Pointer to the data to be written */
    DWORD sector,        /* Start sector number (LBA) */
    BYTE count            /* Sector count (1..255) */
)
{
    if (drv || !count) return RES_PARERR;
    if (Stat & STA_NOINIT) return RES_NOTRDY;
    if (Stat & STA_PROTECT) return RES_WRPRT;

    if (!(CardType & 4)) sector *= 512;    /* Convert to byte address if needed */

   	AT45_Init();
	AT45_Addr=sector;
    if (count == 1)
	{    /* Single block write */
//            && xmit_datablock(buff, 0xFE))
		watchdog_reset();
		AT45_Long_Write((u8*)buff,512);
        count = 0;
    }
    else {                /* Multiple block write */
            do {               
				watchdog_reset();
				AT45_Long_Write((u8*)buff,512);
                buff += 512;
            } while (--count);
    }
    return count ? RES_ERROR : RES_OK;
}
#endif /* _READONLY */



/*-----------------------------------------------------------------------*/
/* Miscellaneous Functions                                               */
/*-----------------------------------------------------------------------*/

DRESULT disk_ioctl (
    BYTE drv,        /* Physical drive nmuber (0) */
    BYTE ctrl,        /* Control code */
    void *buff        /* Buffer to send/receive control data */
)
{
    DRESULT res;
    BYTE  *ptr = buff;
//    WORD csize;


    if (drv) return RES_PARERR;
    watchdog_reset();
    res = RES_ERROR;

    if (ctrl == CTRL_POWER) {
        switch (*ptr) {
        case 0:        /* Sub control code == 0 (POWER_OFF) */
            if (chk_power())
                power_off();        /* Power off */
            res = RES_OK;
            break;
        case 1:        /* Sub control code == 1 (POWER_ON) */
            power_on();                /* Power on */
            res = RES_OK;
            break;
        case 2:        /* Sub control code == 2 (POWER_GET) */
            *(ptr+1) = (BYTE)chk_power();
            res = RES_OK;
            break;
        default :
            res = RES_PARERR;
        }
    }
    else {
        if (Stat & STA_NOINIT) return RES_NOTRDY;

        SELECT();        /* CS = L */

        switch (ctrl) {
        case GET_SECTOR_COUNT :    /* Get number of sectors on the disk (DWORD) */
               *(DWORD*)buff = sector_number;
                res = RES_OK;
            break;

        case GET_SECTOR_SIZE :    /* Get sectors on the disk (WORD) */
            *(WORD*)buff = 512;
            res = RES_OK;
            break;

        case CTRL_SYNC :    /* Make sure that data has been written */
            if (wait_ready() == 0xFF)
                res = RES_OK;
            break;

        case MMC_GET_CSD :    /* Receive CSD as a data block (16 bytes) */
                res = RES_OK;
            break;

        case MMC_GET_CID :    /* Receive CID as a data block (16 bytes) */
                res = RES_OK;
            break;

        case MMC_GET_OCR :    /* Receive OCR as an R3 resp (4 bytes) */
                res = RES_OK;

        default:
            res = RES_PARERR;
        }

        DESELECT();            /* CS = H */
        rcvr_spi();            /* Idle (Release DO) */
    }

    return res;
}



/*-----------------------------------------------------------------------*/
/* Device Timer Interrupt Procedure  (Platform dependent)                */
/*-----------------------------------------------------------------------*/
/* This function must be called in period of 10ms                        */

void disk_timerproc (void)
{
//    BYTE n, s;
    BYTE n;


    n = Timer1;                        /* 100Hz decrement timer */
    if (n) Timer1 = --n;
    n = Timer2;
    if (n) Timer2 = --n;

}

/*---------------------------------------------------------*/
/* User Provided Timer Function for FatFs module           */
/*---------------------------------------------------------*/
/* This is a real time clock service to be called from     */
/* FatFs module. Any valid time must be returned even if   */
/* the system does not support a real time clock.          */

DWORD get_fattime (void)
{

    return    ((2007UL-1980) << 25)    // Year = 2007
            | (6UL << 21)            // Month = June
            | (5UL << 16)            // Day = 5
            | (11U << 11)            // Hour = 11
            | (38U << 5)            // Min = 38
            | (0U >> 1)                // Sec = 0
            ;

}
#endif