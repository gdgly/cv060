/*---------------------------------------------------------------------------*/
/**
  @file		modbus_utils.h
  @brief	Example modbus utilities header file

  This file contains much modbus utility functions.
  It helps to merge modbus function code and data to a PDU and split PDU
  to modbus function code and data.
  We split one request and response into four functions, for example if modbus
  master sends Read Coils request to slave and gets slave's response, we might
  have to use these four functions.

  Modbus Master					Modbus Slave
  1. MBReadCoils()		---->		2. MBGetReadCoils()
  4. MBGetResponseReadCoils()	<----		3. MBResponseReadCoils


  History:
  Date		Author			Comment
  08-01-2005	AceLan Kao.		Create it.

  @author AceLan Kao.(acelan_kao@moxa.com.tw)
 */
/*---------------------------------------------------------------------------*/

#ifndef MODBUS_UTILS_H
#define MODBUS_UTILS_H

/*---------------------------------------------------------------------------*/
/**
  @brief	get 16 bits data from buf
  @param	var	a 16 bits variable
  @param	buf	a pointer to data buffer
  @return	none
 */
/*---------------------------------------------------------------------------*/
#define GETU16( var, buf) {				\
		(var) = (*(buf) << 8) & 0xFF00;		\
		(var) |= (*((buf)+1) & 0xFF);		\
	}
/*---------------------------------------------------------------------------*/
/**
  @brief	put 16 bits data to buf
  @param	buf	a pointer to data buffer
  @param	var	a 16 bits variable
  @return	none
 */
/*---------------------------------------------------------------------------*/
#define PUTU16( buf, var) {				\
		(*(buf)) = ((var) >> 8);		\
		*((buf)+1) = ((var) & 0xFF);		\
	}

/// API pothotype define
/// Modbus protocol utility API
u16	CRC16( const u8 *buf, int len);
u8	LRC( const u8 *buf, int len);
int	MBASCIIToData(u8 *buf, const u8 *data, int len);
int	MBDataToASCII(u8 *buf, const u8 *data, int len);

/// Modbus utilities functions
int	MBMakeADU( u8 *buf, int protocol, u8 address, const u8 *pdu, int len, u16 tid);
int	MBGetPDU( u8 *buf, u8 *adu, int len);
int	MBMakePDU( u8 *buf, u8 function, u8 *data, int len);
u8	MBGetAddress( const u8 *adu);
u8	MBGetFunctionCode( const u8 *pdu);

/// Master function
int	MBReadDecreteInputs(u8 *buf, u16 startdec, u16 no);		///< 0x02
int	MBReadCoils(u8 *buf, u16 startcoils, u16 no);			///< 0x01
int	MBWriteSingleCoil(u8 *buf, u16 coilreg, u16 onoff);		///< 0x05
int	MBWriteMultipleCoils(u8 *buf, u16 startcoils, u16 no, u8 count, u8 *data);///< 0x0F
int	MBReadInputRegisters(u8 *buf, u16 startreg, u16 no);		///< 0x04
int	MBReadHoldingRegisters(u8 *buf, u16 startreg, u16 no);		///< 0x03
int	MBWriteSingleRegister(u8 *buf, u16 devicereg, u16 value);	///< 0x06
int	MBWriteMultipleRegisters(u8 *buf, u16 startreg, u16 noreg, u8 count, u16 *no);///< 0x10
int	MBReadWriteMultipleRegisters(u8 *buf, u16 rsreg, u16 rno, u16 wsreg, u16 wno, u8 count, u16 *wv);///< 0x17
int	MBMaskWriteRegister(u8 *buf, u16 reg, u16 andmask,u16 ormask);	///< 0x16
int	MBReadFIFOQueue(u8 *buf, u16 FIFOAddr);				///< 0x18
// MBF_READ_FILE_RECORD			0x14
// MBF_WRITE_FILE_RECORD		0x15
int	MBReadExceptionStatus(u8 *buf);					///< 0x07
int	MBDiagnostic(u8 *buf, u16 subfunc, u16 data);			///< 0x08
int	MBGetCommEventCounter(u8 *buf);					///< 0x0B
int	MBGetCommEventLog(u8 *buf);					///< 0x0C
int	MBReportSlaveID(u8 *buf);					///< 0x11

/// Response function
int	MBResponseReadDecreteInputs(u8 *buf, u8 no, u8 *value);
int	MBResponseReadCoils(u8 *buf, u8 no, u8 *value);
int	MBResponseReadInputRegisters(u8 *buf, u8 no, u16 *value);
int	MBResponseReadHoldingRegisters(u8 *buf, u8 no, u16 *value);
int	MBResponseWriteMultipleRegisters(u8 *buf, u16 startdevreg, u16 no);
int	MBResponseWriteSingleCoil(u8 *buf, u16 coilreg, u16 onoff);
int	MBResponseWriteSingleRegister(u8 *buf, u16 reg, u16 value);
int	MBResponseReadFIFOueue(u8 *buf, u16 count, u16 *value);
int	MBResponseReadExecptionStatus(u8 *buf, u8 status);
int	MBResponseDiagnostic(u8 *buf, u16 subfunc, u16 data);
int	MBResponseGetCommEventCounter(u8 *buf, u16 status, u16 eventcount);
int     MBResponseGetCommEventLog(u8 *buf, u8 no, u16 status, u16 eventcount, u16 messagecount, u8 *events);
//int	MBResponseReportSlaveID(u8 *buf, u8 *buf, int len);

/// Modbus get request value from PDU
int	MBGetReadDecreteInputs(u8 *pdu, u16 *startdec, u16 *no);
int	MBGetReadCoils(u8 *pdu, u16 *startcoils, u16 *no);
int	MBGetWriteSingleCoil(u8 *pdu, u16 *coilreg, u16 *onoff);
int	MBGetWriteMultipleCoils(u8 *pdu, u16 *startcoils, u16 *no);
int	MBGetReadInputRegisters(u8 *pdu, u16 *startreg, u16 *no);
int	MBGetReadHoldingRegisters(u8 *pdu, u16 *startreg, u16 *no);
int	MBGetWriteSingleRegister(u8 *pdu, u16 *devicereg, u16 *value);
int	MBGetWriteMultipleRegisters(u8 *pdu, u16 *startreg, u16 *no, u8 *count, u16 *value);
int     MBGetReadWriteMultipleRegisters(u8 *pdu, u16 *rsreg, u16 *rno, u16 *wsreg, u16 *wno, u8 *count, u16 *wv);
int	MBGetMaskWriteRegister(u8 *pdu, u16 *reg, u16 *andmask, u16 *ormask);
int	MBGetReadFIFOQueue(u8 *pdu, u16 *FIFOAddr);
int	MBGetDiagnostic(u8 *pdu, u16 *subfunc, u16 *data);	// just for serial port

/// Modbus get response value from PDU
int     MBGetResponseReadDecreteInputs(u8 *pdu, u8 *no, u8 *value);
int     MBGetResponseReadCoils(u8 *pdu, u8 *no, u8 *value);
int     MBGetResponseReadInputRegisters(u8 *pdu, u8 *no, u16 *value);
int     MBGetResponseReadHoldingRegisters(u8 *pdu, u8 *no, u16 *value);
int     MBGetResponseWriteMultipleRegisters(u8 *pdu, u16 *address, u16 *no);
int     MBGetResponseWriteSingleCoil(u8 *pdu, u16 *address, u16 *value);
int	MBGetResponseWriteMultipleCoils(u8 *pdu, u16 *address, u16 *value);
int     MBGetResponseWriteSingleRegister(u8 *pdu, u16 *address, u16 *value);
int	MBGetResponseReadFIFOueue(u8 *buf, u16 count, u16 *value);
int	MBGetResponseReadExecptionStatus(u8 *buf, u8 status);
int     MBGetResponseDiagnostic(u8 *pdu, u16 *subfunc, u16 *data);
int     MBGetResponseGetCommEventCounter(u8 *pdu, u16 *status, u16 *eventcount);
int	MBGetResponseGetCommEventLog(u8 *buf, u16 *status, u16 *eventcount, u16 *messagecount, u8 *events);
int	MBGetResponseReadWriteMultipleRegisters(u8 *pdu, u8 *no, u16 *value);
int     MBGetResponseMaskWriteRegister(u8 *pdu, u16 *reg, u16 *andmask, u16 *ormask);
int	MBGetResponseReportSlaveID(u8 *pdu, u8 *slave_id, u8 *status);

#endif

