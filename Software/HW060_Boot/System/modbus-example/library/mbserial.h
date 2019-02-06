/*---------------------------------------------------------------------------*/
/**
  @file		mbserial.h
  @brief	Example modbus serial API header file

  This file contains higher level modbus serial utility functions.
  It supports both RTU and ASCII protocol and converts them implicity.


  History:
  Date		Author			Comment
  08-02-2005	AceLan Kao.		Create it.

  @author AceLan Kao.(acelan_kao@moxa.com.tw)
 */
/*---------------------------------------------------------------------------*/

#ifndef MBSERIAL_H
#define MBSERIAL_H

#include "serial.h"
#include "modbus_defs.h"
#include "modbus_utils.h"

#define GETCLOCKMS(x) {					\
		struct timeval tv;			\
		gettimeofday( &tv, NULL);		\
		x= tv.tv_usec>>10;			\
	}

#define GETCLOCKSECOND(x) {				\
		x= time(NULL);				\
	}

struct MB_SERIAL_INFO
{
	u8	Protocol;			///< MB_ASCII_PROTOCOL/MB_RTU_PROTOCOL
	u32	FrameTimeout;			///< frame timeout in ms
	u32	CharTimeout;			///< char timeout in ms
	u32	Timeout;			///< request timeout in ms
};

/// Modbus over serial line API
void	MBSerialInit(void);
int	MBSerialOpen(int port, int protocol);
int	MBSerialBlockRead(int port, u8 *buf, int len);		///< Read ADU
int	MBSerialNonBlockRead(int port, u8 *buf, int len);
int	MBSerialWrite(int port, u8 *pdu, int len, u8 address);	///< Make ADU and sent out
int	MBSerialClose(int port);
int	MBSerialFlowCtrl(int port, int control);
int	MBSerialSendAndWaitResponse(int port, u8 *buf, u8 *pdu, int len, u8 address);

u32	MBSerialGetFrameTimeout(int port);
void    MBSerialSetFrameTimeout(int port, u32 timeout);
u32	MBSerialGetCharTimeout(int port);
void	MBSerialSetCharTimeout(int port, u32 timeout);
u32	MBSerialGetTimeout(int port);
void	MBSerialSetTimeout(int port, u32 timeout);

int	MBSerialReadRTU( int port, u8 *buf, int len);
int	MBSerialReadASCII( int port, u8 *buf, int len);

u8	MBSerialGetAddress( const u8 *adu);
int	MBSerialGetPDU( u8 *buf, u8 *adu, int len);

int	MBSerialSetMode( int port, unsigned int mode);
int	MBSerialSetSpeed( int port, unsigned int speed);
int	MBSerialSetParam( int port, int parity, int databits, int stopbit);

/// Modbus master function
int	MBSerialReadDecreteInputs(int port,u8 address, u16 startdec, u16 no, u8 *value);
int	MBSerialReadCoils(int port, u8 address, u16 startcoils, u16 no, u8 *value);
int	MBSerialWriteSingleCoil(int port, u8 address, u16 coilreg, u16 onoff);
int	MBSerialWriteMultipleCoils(int port, u8 address, u16 startcoils, u16 no, u8 *value);

int	MBSerialReadInputRegisters(int port, u8 address, u16 startreg, u16 no, u16 *value);
int	MBSerialReadHoldingRegisters(int port, u8 address, u16 startreg, u16 no, u16 *value);
int	MBSerialWriteSingleRegister(int port, u8 address, u16 devicereg, u16 value);
int	MBSerialWriteMultipleRegisters(int port, u8 address, u16 startdevreg, u16 noreg, u8 count, u16 *value);
int	MBSerialReadWriteMultipleRegisters(int port, u8 address, u16 rsreg, u16 rno, u16 *rv, u16 wsreg, u16 wno, u8 count, u16 *wv);
int	MBSerialMaskWriteRegister(int port,u8 address, u16 reg, u16 andmask,u16 ormask);
int	MBSerialReadFIFOQueue(int port, u8 address, u16 FIFOAddr, u16 *FIFOCount, u16 *FIFOValue);

/// Modbus master function over serial only
int	MBSerialReadExceptionStatus(int port, u8 address, u8 *status);
int	MBSerialDiagnostic(int port, u8 address, u16 subfunc, u16 data);
int	MBSerialGetCommEventCounter(int port, u8 address, u16 *status, u16 *eventcount);
int	MBSerialGetCommEventLog(int port, u8 address, u16 *status, u16 *eventcount, u16 *messagecount, u8 *events);
int     MBSerialReportSlaveID(int port, u8 address, u8 *slave_id, u8 *status);

/// Modbus slave function or response to master
int	MBSerialSendReadDecreteInputs(int port, u8 address, u16 no, u8 *value);
int	MBSerialSendReadCoils(int port, u8 address, u16 no, u8 *value);
int	MBSerialSendReadInputRegisters(int port, u8 address, u16 no, u16 *value);
int	MBSerialSendReadHoldingRegisters(int port, u8 address, u16 no, u16 *value);
int	MBSerialSendWriteMultipleRegisters(int port, u8 address, u16 startdevreg, u16 noreg);
int	MBSerialSendWriteSingleCoil(int port, u8 address, u16 coilreg, u16 onoff);
int 	MBSerialSendWriteSingleRegister(int port, u8 address, u16 addr, u16 value);
int	MBSerialSendReadFIFOueue(int port, u8 address, u16 no, u16 count, u16 *value);
int	MBSerialSendReadExecptionStatus(int port, u8 address, u8 status);
int 	MBSerialSendDiagnostic(int port, u8 address, u16 subfunc, u16 data);
int	MBSerialSendGetCommEventCounter(int port, u8 address, u16 status, u16 eventcount);
int 	MBSerialSendGetCommEventLog(int port, u8 address, u8 no, u16 status, u16 eventcount, u16 messagecount, u8 *events);

#endif
