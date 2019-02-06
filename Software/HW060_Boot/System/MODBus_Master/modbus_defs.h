//*****************************************************************************
#ifndef MODBUS_DEFS_H
#define MODBUS_DEFS_H
//*****************************************************************************
/* ----------------------- MBAP Header --------------------------------------*/
/*
 *
 * <------------------------ MODBUS TCP/IP ADU(1) ------------------------->
 *              <----------- MODBUS PDU (1') ---------------->
 *  +-----------+---------------+------------------------------------------+
 *  | TID | PID | Length | UID  |Code | Data                               |
 *  +-----------+---------------+------------------------------------------+
 *  |     |     |        |      |
 * (2)   (3)   (4)      (5)    (6)
 *
 * (2)  ... MB_TCP_TID          = 0 (Transaction Identifier - 2 Byte)
 * (3)  ... MB_TCP_PID          = 2 (Protocol Identifier - 2 Byte)
 * (4)  ... MB_TCP_LEN          = 4 (Number of bytes - 2 Byte)
 * (5)  ... MB_TCP_UID          = 6 (Unit Identifier - 1 Byte)
 * (6)  ... MB_TCP_FUNC         = 7 (Modbus Function Code)
 *
 * (1)  ... Modbus TCP/IP Application Data Unit
 * (1') ... Modbus Protocol Data Unit
 */

//*****************************************************************************

#define MB_TCP_TID          			0
#define MB_TCP_PID          			2
#define MB_TCP_LEN          			4
#define MB_TCP_UID          			6
// Request
#define MB_TCP_FUNC         			7
#define MB_TCP_DATA         			8
#define MB_TCP_ADDR         			8
#define MB_TCP_COUNT         			10
#define MB_TCP_VALUE         			13
// Responce
#define MB_TCP_BCNT         			8
#define MB_TCP_BDAT         			9

#define MB_TCP_PROTOCOL_ID  			0   /* 0 = Modbus Protocol */

#define MODBUS_MAX_ANSWER_DELAY			200	

#define U32_MAX_VALUE					0xFFFFFFFF

#define MB_TCP_PORT						502
#define MB_RTU_ADU_MAX_LENGTH			256
#define MB_ASCII_ADU_MAX_LENGTH			512

#define MB_RTU_PROTOCOL					0
#define MB_ASCII_PROTOCOL				1
#define MB_TCP_PROTOCOL					2

#define MAX_BUFFER_SIZE					256
#define MAX_485_NUM						256

//*****************************************************************************

/// Modbus application function code define
#define MBF_READ_DECRETE_INPUTS			0x02
#define MBF_READ_COILS					0x01
#define MBF_WRITE_SINGLE_COIL			0x05
#define MBF_WRITE_MULTIPLE_COILS		0x0F
#define MBF_READ_INPUT_REGISTERS		0x04
#define MBF_READ_HOLDING_REGISTERS		0x03
#define MBF_WRITE_SINGLE_REGISTER		0x06
#define MBF_WRITE_MULTIPLE_REGISTERS		0x10
#define MBF_READ_WRITE_MULTIPLE_REGISTERS	0x17
#define MBF_MASK_WRITE_REGISTER			0x16
#define MBF_READ_FIFO_QUEUE				0x18
#define MBF_READ_FILE_RECORD			0x14
#define MBF_WRITE_FILE_RECORD			0x15
#define NBSF_FILE_RECORD				0x06
#define MBF_READ_EXCEPTION_STATUS		0x07	///< just for over serial line
#define MBF_DIAGNOSTIC					0x08	///< just for over serial line
#define MBF_GET_COMM_EVENT_COUNTER		0x0B	///< just for over serial line
#define MBF_GET_COMM_EVENT_LOG			0x0C	///< just for over serial line
#define MBF_REPORT_SLAVE_ID				0x11	///< just for over serial line
#define MBF_READ_DEVICE_IDENTIFICATION	0x2B
#define MBF_HAS_EXCEPTION				0x80
#define MBF_EXCEPTION					0x81
#define MBF_MASK						0x7F	///< mask function code

//*****************************************************************************

/// following error define
#define MB_ERROR_FREE					0	///< it is OK
#define MB_OK							0	///< operating is OK
#define MB_ERROR_FORMAT					-1
#define MB_ERROR_LENGTH					-2	///< too short, too long or boudary error
#define MB_ERROR_PARAMETER				-3	///< parameter error
#define MB_ERROR_OPEN					-4	///< open port error
#define MB_ERROR_TCP_NOT_CONNECTED		-5	///< TCP port doesn't connect
#define MB_ERROR_NOT_OPENED				-6	///< port has not opened
#define MB_ERROR_BUFFER_TOO_SHORT		-7
#define MB_ERROR_NO_FRAME				-8
#define MB_ERROR_TIMEOUT				-9
#define MB_ERROR_EXECPTION				-10
#define MB_ERROR_BAD_FD					-11
#define MB_ERROR_NET					-12
#define MB_ERROR_NO_FILE_HANDLE			-13
#define MB_ERROR_PROTOCOL				-14	///< Protocol not define
#define	MB_ERROR_FUNCTION				-15
#define	MB_ERROR_MODE					-16

#define MB_EXEPTION_FUNCTION			1
#define MB_EXEPTION_DATA_ADDR			2
#define MB_EXEPTION_DATA_VALUE			3
#define MB_EXEPTION_SLAVE_FAIL			4
#define MB_EXEPTION_ACKNOLEGE			5
#define MB_EXEPTION_SLAVE_BUSY			6
#define MB_EXEPTION_MEM_PARITY			8
#define MB_EXEPTION_GW_PATH_ERR			0x0A
#define MB_EXEPTION_GW_DEV_NO_RESPOND	0x0B
//*****************************************************************************

typedef __packed struct _MBAP_Struct {
	u16	TransactionIdentifier;		///< copy from server to client
	u16	ProtocolIdentifier;			///< 0 for Modbus protocol
	u16	Length;						///< following bytes number
	u8	UnitIdentifier;				///< copy from server to client, maybe map serial address
} MBAPStruct, *pMBAPStruct;

//*****************************************************************************

#endif

