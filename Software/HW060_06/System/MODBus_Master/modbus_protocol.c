//*****************************************************************************
#include "main.h"
#include "modbus_defs.h"
#include "modbus_utils.h"
//*****************************************************************************

MBAPStruct	MB;
u8			MB_Function;
u16			MB_Addr;
u16 		MB_Count;
u8			MB_Buff[MAX_BUFFER_SIZE];
u16			MB_Data_To_Send;

u8			mb_pid_number=0;
u8			mb_fan_number=0;
u8			mb_kot_number=0;
u8			mb_valve_number=0;

//*****************************************************************************
// MODBus Master section
//*****************************************************************************

void MODBus_Init( void )
{

}

//*****************************************************************************

u16 MB_Get_Holding_Register(u16 i)
{
	u16	tmp16 = 0;
	restore_ip_core_cycle_delay = 3*60;
	restore_ip_core_count = 0;
	
#if MAX_PARAMS_BLOCK
	if ((i >= 250) && (i < (250 + MAX_PARAMS_NUM))){
		tmp16 = misc.pr[i - 250];	
		return tmp16;
	}
#endif
	
	switch(i)
	{
	case 0:		tmp16=0xAA55; 					return tmp16;	// Just constant register showing all is OK
	case 1:		tmp16=0x0160; 					return tmp16;	// Version of software 01-controller 60-version
	case 2:		tmp16=io.num_di; 				return tmp16;	// Number of DI
	case 3:		tmp16=io.num_do; 				return tmp16;	// Number of DO
	case 4:		tmp16=io.num_ai; 				return tmp16;	// Number of AI
	case 5:		tmp16=io.num_ao; 				return tmp16;	// Number of AO

#if (NUM_AOUT > 0)
	case 10+0: tmp16 = io.aoutput[0]; return tmp16;	// AO[]
#endif
#if (NUM_AOUT > 1)
	case 10+1: tmp16 = io.aoutput[1]; return tmp16;	// AO[]
#endif
#if (NUM_AOUT > 2)
	case 10+2: tmp16 = io.aoutput[2]; return tmp16;	// AO[]
#endif
#if (NUM_AOUT > 3)
	case 10+3: tmp16 = io.aoutput[3]; return tmp16;	// AO[]
#endif
#if (NUM_AOUT > 4)
	case 10+4: tmp16 = io.aoutput[4]; return tmp16;	// AO[]
#endif
#if (NUM_AOUT > 5)
	case 10+5: tmp16 = io.aoutput[5]; return tmp16;	// AO[]
#endif
#if (NUM_AOUT > 6)
	case 10+6: tmp16 = io.aoutput[6]; return tmp16;	// AO[]
#endif
	
	
	case 20+0:	tmp16=NUM_PID; 					return tmp16;	// PID blocks number
	case 20+1:	tmp16=MAX_FANCOIL_NUMBER; 		return tmp16;	// FAN blocks number
	case 20+2:	tmp16=MAX_KOTEL_NUMBER;			return tmp16;	// KOTEL blocks number
	case 20+3:	tmp16=MAX_VALVE_3T_NUMBER;		return tmp16;	// VALVE blocks number
	case 20+4:	tmp16=MAX_PARAMS_BLOCK;			return tmp16;	// PARAMS blocks number
	
	case 20+5:	tmp16=mb_pid_number;			return tmp16;	// active pid number
	case 20+6:	tmp16=mb_fan_number;			return tmp16;	// active fan number
	case 20+7:	tmp16=mb_kot_number;			return tmp16;	// active kot number
	case 20+8:	tmp16=mb_valve_number;			return tmp16;	// active valve number

	
	// Fancoils block
#if MAX_FANCOIL_NUMBER
	case 50+0:	tmp16=0; if(mb_fan_number < MAX_FANCOIL_NUMBER) tmp16 = fan[mb_fan_number].T;					return tmp16;	//
	case 50+1:	tmp16=0; if(mb_fan_number < MAX_FANCOIL_NUMBER) tmp16 = fan[mb_fan_number].Fan_Mode;			return tmp16;	//
	case 50+2:	tmp16=0; if(mb_fan_number < MAX_FANCOIL_NUMBER) tmp16 = fan[mb_fan_number].Fan_Lvl;				return tmp16;	//
	case 50+3:	tmp16=0; if(mb_fan_number < MAX_FANCOIL_NUMBER) tmp16 = fan[mb_fan_number].Valve;				return tmp16;	//
	case 50+4:	tmp16=0; if(mb_fan_number < MAX_FANCOIL_NUMBER) tmp16 = fan[mb_fan_number].TLow;				return tmp16;	//
	case 50+5:	tmp16=0; if(mb_fan_number < MAX_FANCOIL_NUMBER) tmp16 = fan[mb_fan_number].TMedium;				return tmp16;	//
	case 50+6:	tmp16=0; if(mb_fan_number < MAX_FANCOIL_NUMBER) tmp16 = fan[mb_fan_number].THigh;				return tmp16;	//
	case 50+7:	tmp16=0; if(mb_fan_number < MAX_FANCOIL_NUMBER) tmp16 = fan[mb_fan_number].Hysteresis;			return tmp16;	//
	case 50+8:	tmp16=0; if(mb_fan_number < MAX_FANCOIL_NUMBER) tmp16 = fan[mb_fan_number].Fan_Time;			return tmp16;	//
//	case 50+9:	tmp16=0; if(mb_fan_number < MAX_FANCOIL_NUMBER) tmp16 = fan[mb_fan_number].Valve_Time_1;		return tmp16;	//
//	case 50+10:	tmp16=0; if(mb_fan_number < MAX_FANCOIL_NUMBER) tmp16 = fan[mb_fan_number].Valve_Time_2;		return tmp16;	//
	case 50+11:	tmp16=0; if(mb_fan_number < MAX_FANCOIL_NUMBER) tmp16 = fan[mb_fan_number].Valve_Hysteresis;	return tmp16;	//
	case 50+12:	tmp16=0; if(mb_fan_number < MAX_FANCOIL_NUMBER) tmp16 = fan[mb_fan_number].Day_Night;			return tmp16;	//
	case 50+13:	tmp16=0; if(mb_fan_number < MAX_FANCOIL_NUMBER) tmp16 = fan[mb_fan_number].Channel;				return tmp16;	//
	case 50+14:	tmp16=0; if(mb_fan_number < MAX_FANCOIL_NUMBER) tmp16 = fan[mb_fan_number].T_In;				return tmp16;	//
	case 50+15:	tmp16=0; if(mb_fan_number < MAX_FANCOIL_NUMBER) tmp16 = fan[mb_fan_number].HC;					return tmp16;	//	
#endif

	// Season Block
	case 100+0:		tmp16 = reg_season.season;					return tmp16;	//
	case 100+1:		tmp16 = reg_season.switch_temperature;		return tmp16;	//
	case 100+2:		tmp16 = reg_season.switch_date;				return tmp16;	//
	case 100+3:		tmp16 = 0;									return tmp16;	//
	case 100+4:		tmp16 = 0;									return tmp16;	//
	case 100+5:		tmp16 = reg_season.t;						return tmp16;	//
	case 100+6:		tmp16 = reg_season.t_extern_channel;		return tmp16;	//
	case 100+7:		tmp16 = reg_season.switch_power;			return tmp16;	//
	case 100+8:		tmp16 = reg_season.power_min_summer;		return tmp16;	//
	case 100+9:		tmp16 = reg_season.power_min_winter;		return tmp16;	//

	// Error Block
	case 150+0:		tmp16 = errors.new_error;					return tmp16;	//
	case 151+0:		tmp16 = errors.item[0].code;				return tmp16;	//
	case 151+1:		tmp16 = errors.item[1].code;				return tmp16;	//
	case 151+2:		tmp16 = errors.item[2].code;				return tmp16;	//
	case 151+3:		tmp16 = errors.item[3].code;				return tmp16;	//

	// Valve Block
#if MAX_VALVE_3T_NUMBER
	case 200+0:	tmp16=0; if(mb_valve_number < MAX_VALVE_3T_NUMBER) tmp16 = valve[mb_valve_number].power;	return tmp16;	//
	case 200+1:	tmp16=0; if(mb_valve_number < MAX_VALVE_3T_NUMBER) tmp16 = valve[mb_valve_number].t3max;	return tmp16;	//
	case 200+2:	tmp16=0; if(mb_valve_number < MAX_VALVE_3T_NUMBER) tmp16 = valve[mb_valve_number].p3;		return tmp16;	//
	case 200+3:	tmp16=0; if(mb_valve_number < MAX_VALVE_3T_NUMBER) tmp16 = valve[mb_valve_number].open;		return tmp16;	//
	case 200+4:	tmp16=0; if(mb_valve_number < MAX_VALVE_3T_NUMBER) tmp16 = valve[mb_valve_number].close;	return tmp16;	//
#endif	

	/*
	// Params Block
#if MAX_PARAMS_BLOCK
	case 250+0:	tmp16=0; tmp16 = misc.pr[0];	return tmp16;		//
	case 250+1:	tmp16=0; tmp16 = misc.pr[1];	return tmp16;		//
	case 250+2:	tmp16=0; tmp16 = misc.pr[2];	return tmp16;		//
	case 250+3:	tmp16=0; tmp16 = misc.pr[3];	return tmp16;		//
	case 250+4:	tmp16=0; tmp16 = misc.pr[4];	return tmp16;		//
	case 250+5:	tmp16=0; tmp16 = misc.pr[5];	return tmp16;		//
	case 250+6:	tmp16=0; tmp16 = misc.pr[6];	return tmp16;		//
	case 250+7:	tmp16=0; tmp16 = misc.pr[7];	return tmp16;		//
	case 250+8:	tmp16=0; tmp16 = misc.pr[8];	return tmp16;		//
	case 250+9:	tmp16=0; tmp16 = misc.pr[9];	return tmp16;		//
#endif		
	*/
	
	// PID block
#if NUM_PID
	case 300+0:	tmp16=0; if(mb_pid_number < NUM_PID) tmp16 = pid[mb_pid_number].channel;				return tmp16;	//
	case 300+1:	tmp16=0; if(mb_pid_number < NUM_PID) tmp16 = pid[mb_pid_number].p;						return tmp16;	//
	case 300+2:	tmp16=0; if(mb_pid_number < NUM_PID) tmp16 = pid[mb_pid_number].i;						return tmp16;	//
	case 300+3:	tmp16=0; if(mb_pid_number < NUM_PID) tmp16 = pid[mb_pid_number].d;						return tmp16;	//
	case 300+4:	tmp16=0; if(mb_pid_number < NUM_PID) tmp16 = pid[mb_pid_number].t0;						return tmp16;	//
	case 300+5:	tmp16=0; if(mb_pid_number < NUM_PID) tmp16 = pid[mb_pid_number].power;					return tmp16;	//
	case 300+6:	tmp16=0; if(mb_pid_number < NUM_PID) tmp16 = pid[mb_pid_number].power_min;				return tmp16;	//
	case 300+7:	tmp16=0; if(mb_pid_number < NUM_PID) tmp16 = pid[mb_pid_number].power_max;				return tmp16;	//
	case 300+8:	tmp16=0; if(mb_pid_number < NUM_PID) tmp16 = pid[mb_pid_number].mode;					return tmp16;	//
	case 300+9:	tmp16=0; if(mb_pid_number < NUM_PID) tmp16 = pid[mb_pid_number].tin;					return tmp16;	//
	case 300+10:	tmp16=0; if(mb_pid_number < NUM_PID) tmp16 = (u16)(pid[mb_pid_number].PID_POWER_STEP[0]*1000);	return tmp16;	//
	case 300+11:	tmp16=0; if(mb_pid_number < NUM_PID) tmp16 = (u16)(pid[mb_pid_number].PID_POWER_STEP[1]*1000);	return tmp16;	//
	case 300+12:	tmp16=0; if(mb_pid_number < NUM_PID) tmp16 = pid[mb_pid_number].PID_POWER_LIMIT[0];		return tmp16;	//
	case 300+13:	tmp16=0; if(mb_pid_number < NUM_PID) tmp16 = pid[mb_pid_number].PID_POWER_LIMIT[1];		return tmp16;	//
	case 300+14:	tmp16=0; if(mb_pid_number < NUM_PID) tmp16 = pid[mb_pid_number].heating_cooling;		return tmp16;	//
	case 300+15:	tmp16=0; if(mb_pid_number < NUM_PID) tmp16 = pid[mb_pid_number].fan_in;					return tmp16;	//
	case 300+16:	tmp16=0; if(mb_pid_number < NUM_PID) tmp16 = pid[mb_pid_number].fan_out;				return tmp16;	// 	
#endif
	default: return 0;
	}
}			

//*****************************************************************************

void MB_Set_Holding_Register(u16 i, u16 value)
{
	restore_ip_core_cycle_delay = 3*60;
	restore_ip_core_count = 0;
	
#if MAX_PARAMS_BLOCK
	if ((i >= 250) && (i < (250 + MAX_PARAMS_NUM))){
		misc.pr[i - 250] = value; 
		return;
	}
#endif
	
	switch(i)
	{
//	case 0:		tmp16=0xAA55; 					return;	// Just constant register showing all is OK
//	case 1:		tmp16=0x0160; 					return;	// Version of software 01-controller 60-version
//	case 2:		tmp16=NUM_PID; 					return;	// PID blocks number
//	case 3:		tmp16=MAX_FANCOIL_NUMBER; 		return;	// FAN blocks number
//	case 4:		tmp16=MAX_KOTEL_NUMBER;			return;	// KOTEL blocks number
//	case 5:		tmp16=MAX_VALVE_3T_NUMBER;		return;	// VALVE blocks number
//	case 6:		tmp16=MAX_PARAMS_BLOCK;			return;	// PARAMS blocks number
	
#if (NUM_AOUT > 0)
	case 10+0:	io.aoutput[0]=value;		return ;	// AO[]
#endif
#if (NUM_AOUT > 1)
	case 10+1:	io.aoutput[1]=value;		return ;	// AO[]
#endif
#if (NUM_AOUT > 2)
	case 10+2:	io.aoutput[2]=value;		return ;	// AO[]
#endif
#if (NUM_AOUT > 3)
	case 10+3:	io.aoutput[3]=value;		return ;	// AO[]
#endif
#if (NUM_AOUT > 4)
	case 10+4:	io.aoutput[4]=value;		return ;	// AO[]
#endif
#if (NUM_AOUT > 5)
	case 10+5:	io.aoutput[5]=value;		return ;	// AO[]
#endif
	
//	case 20+0:	tmp16=NUM_PID; 				return tmp16;	// PID blocks number
//	case 20+1:	tmp16=MAX_FANCOIL_NUMBER; 	return tmp16;	// FAN blocks number
//	case 20+2:	tmp16=MAX_KOTEL_NUMBER;		return tmp16;	// KOTEL blocks number
//	case 20+3:	tmp16=MAX_VALVE_3T_NUMBER;	return tmp16;	// VALVE blocks number
//	case 20+4:	tmp16=MAX_PARAMS_BLOCK;		return tmp16;	// PARAMS blocks number
	
	case 20+5:	mb_pid_number = value;			return;	// active pid number
	case 20+6:	mb_fan_number=value;			return;	// active fan number
	case 20+7:	mb_kot_number=value;			return;	// active kot number
	case 20+8:	mb_valve_number=value;			return;	// active valve number

	
	// Fancoils block
#if MAX_FANCOIL_NUMBER
	case 50+0:	if(mb_fan_number < MAX_FANCOIL_NUMBER) fan[mb_fan_number].T = value; Time_To_Store=3;	return;	//
	case 50+1:	if(mb_fan_number < MAX_FANCOIL_NUMBER) fan[mb_fan_number].Fan_Mode = value; Time_To_Store=3; return;	//
	case 50+2:	if(mb_fan_number < MAX_FANCOIL_NUMBER) fan[mb_fan_number].Fan_Lvl = value;				return;	//
	case 50+3:	if(mb_fan_number < MAX_FANCOIL_NUMBER) fan[mb_fan_number].Valve = value;				return;	//
	case 50+4:	if(mb_fan_number < MAX_FANCOIL_NUMBER) fan[mb_fan_number].TLow = value;					return;	//
	case 50+5:	if(mb_fan_number < MAX_FANCOIL_NUMBER) fan[mb_fan_number].TMedium = value;				return;	//
	case 50+6:	if(mb_fan_number < MAX_FANCOIL_NUMBER) fan[mb_fan_number].THigh = value;				return;	//
	case 50+7:	if(mb_fan_number < MAX_FANCOIL_NUMBER) fan[mb_fan_number].Hysteresis = value;			return;	//
	case 50+8:	if(mb_fan_number < MAX_FANCOIL_NUMBER) fan[mb_fan_number].Fan_Time = value;				return;	//
//	case 50+9:	if(mb_fan_number < MAX_FANCOIL_NUMBER) fan[mb_fan_number].Valve_Time_1 = value;			return;	//
//	case 50+10:	if(mb_fan_number < MAX_FANCOIL_NUMBER) fan[mb_fan_number].Valve_Time_2 = value;			return;	//
	case 50+11:	if(mb_fan_number < MAX_FANCOIL_NUMBER) fan[mb_fan_number].Valve_Hysteresis = value;		return;	//
	case 50+12:	if(mb_fan_number < MAX_FANCOIL_NUMBER) fan[mb_fan_number].Day_Night = value;			return;	//
	case 50+13:	if(mb_fan_number < MAX_FANCOIL_NUMBER) fan[mb_fan_number].Channel = value;				return;	//

	case 50+14:	if(mb_fan_number < MAX_FANCOIL_NUMBER) fan[mb_fan_number].T_In = value;					return;	//
	case 50+15:	if(mb_fan_number < MAX_FANCOIL_NUMBER) fan[mb_fan_number].HC = value;					return;	//
#endif

	// Season Block
	case 100+0:		reg_season.season = value;					return;	//
	case 100+1:		reg_season.switch_temperature = value;		return;	//
	case 100+2:		reg_season.switch_date = value;				return;	//
	case 100+3:													return;	//
	case 100+4:													return;	//
	case 100+5:		reg_season.t = value;						return;	//
	case 100+6:		reg_season.t_extern_channel = value;		return;	//
	case 100+7:		reg_season.switch_power = value;			return;	//
	case 100+8:		reg_season.power_min_summer = value;		return;	//
	case 100+9:		reg_season.power_min_winter = value;		return;	//

	// Error Block
	case 150+0:		errors.new_error = value;					return;	//
	case 151+0:		errors.item[0].code = value;				return;	//
	case 151+1:		errors.item[1].code = value;				return;	//
	case 151+2:		errors.item[2].code = value;				return;	//
	case 151+3:		errors.item[3].code = value;				return;	//

	// Valve Block
#if MAX_VALVE_3T_NUMBER
	case 200+0:	if(mb_valve_number < MAX_VALVE_3T_NUMBER) valve[mb_valve_number].power = value;	return;	//
	case 200+1:	if(mb_valve_number < MAX_VALVE_3T_NUMBER) valve[mb_valve_number].t3max = value;	return;	//
	case 200+2:	if(mb_valve_number < MAX_VALVE_3T_NUMBER) valve[mb_valve_number].p3 = value;		return;	//
	case 200+3:	if(mb_valve_number < MAX_VALVE_3T_NUMBER) valve[mb_valve_number].open = value;	return;	//
	case 200+4:	if(mb_valve_number < MAX_VALVE_3T_NUMBER) valve[mb_valve_number].close = value;	return;	//
#endif	

/*
	// Params Block
#if MAX_PARAMS_BLOCK
	case 250+0:	misc.pr[0] = value; return;		//
	case 250+1:	misc.pr[1] = value;	return;		//
	case 250+2:	misc.pr[2] = value;	return;		//
	case 250+3: misc.pr[3] = value;	return;		//
	case 250+4:	misc.pr[4] = value;	return;		//
	case 250+5:	misc.pr[5] = value;	return;		//
	case 250+6:	misc.pr[6] = value;	return;		//
	case 250+7:	misc.pr[7] = value;	return;		//
	case 250+8:	misc.pr[8] = value;	return;		//
	case 250+9:	misc.pr[9] = value;	return;		//
#endif	
*/	
	// PID block
#if NUM_PID
	case 300+0:	if(mb_pid_number < NUM_PID) pid[mb_pid_number].channel = value;					return;	//
	case 300+1:	if(mb_pid_number < NUM_PID) pid[mb_pid_number].p = value;						return;	//
	case 300+2:	if(mb_pid_number < NUM_PID) pid[mb_pid_number].i = value;						return;	//
	case 300+3:	if(mb_pid_number < NUM_PID) pid[mb_pid_number].d = value;						return;	//
	case 300+4:	if(mb_pid_number < NUM_PID) pid[mb_pid_number].t0 = value; Time_To_Store=3;		return;	//
	case 300+5:	if(mb_pid_number < NUM_PID) pid[mb_pid_number].power = value;					return;	//
	case 300+6:	if(mb_pid_number < NUM_PID) pid[mb_pid_number].power_min = value;				return;	//
	case 300+7:	if(mb_pid_number < NUM_PID) pid[mb_pid_number].power_max = value;				return;	//
	case 300+8:	if(mb_pid_number < NUM_PID) pid[mb_pid_number].mode = value; Time_To_Store=3;	return;	//
	case 300+9:	if(mb_pid_number < NUM_PID) pid[mb_pid_number].tin = value;						return;	//
	case 300+10:	if(mb_pid_number < NUM_PID) pid[mb_pid_number].PID_POWER_STEP[0] = value/1000;	return;	//
	case 300+11:	if(mb_pid_number < NUM_PID) pid[mb_pid_number].PID_POWER_STEP[1] = value/1000;	return;	//
	case 300+12:	if(mb_pid_number < NUM_PID) pid[mb_pid_number].PID_POWER_LIMIT[0] = value;		return;	//
	case 300+13:	if(mb_pid_number < NUM_PID) pid[mb_pid_number].PID_POWER_LIMIT[1] = value;		return;	//
	case 300+14:	if(mb_pid_number < NUM_PID) pid[mb_pid_number].heating_cooling = value;			return;	//
	case 300+15:	if(mb_pid_number < NUM_PID) pid[mb_pid_number].fan_in = value;					return;	//
	case 300+16:	if(mb_pid_number < NUM_PID) pid[mb_pid_number].fan_out = value;					return;	// 	
#endif
	default: return;
	}
}			

//*****************************************************************************

unsigned char MODBus_RXHandler(u8 *data,u16 len)
{	
	u32	tmp1;
	u8	tmp2;
	u8 	tmp3;
	int i,j;

	MB_Data_To_Send=0;
	GETU16(MB.TransactionIdentifier, 	&data[MB_TCP_TID]);
	GETU16(MB.ProtocolIdentifier, 		&data[MB_TCP_PID]);
	GETU16(MB.Length, 					&data[MB_TCP_LEN]);
	GETU8 (MB.UnitIdentifier,			&data[MB_TCP_UID]);

	GETU8 (MB_Function, 				&data[MB_TCP_FUNC]);
	GETU16(MB_Addr, 					&data[MB_TCP_ADDR]);
	GETU16(MB_Count, 					&data[MB_TCP_COUNT]);
	switch(MB_Function)
	{
	case MBF_READ_DECRETE_INPUTS:		
		tmp3=MB_Count / 8;
		if(MB_Count - tmp3*8) tmp3++;
		MB_Count = tmp3;
		MB_Buff[MB_TCP_FUNC] = MB_Function;	
		MB_Buff[MB_TCP_BCNT] = MB_Count;
		tmp1=1;
		for(i=0; i<MB_Count; i++)
		{
			tmp2=0;
			for(j=0; j<8; j++)
			{			
				tmp1 = 1<<(j+i*8);
				if(io.din & tmp1) tmp2 |= 1<<j;
			}
			MB_Buff[MB_TCP_BDAT+i] = tmp2;	
		}
		MB.Length= MB_Count + 3;
		PUTU16(&MB_Buff[MB_TCP_TID], MB.TransactionIdentifier);
		PUTU16(&MB_Buff[MB_TCP_PID], MB.ProtocolIdentifier);
		PUTU16(&MB_Buff[MB_TCP_LEN], MB.Length);
		PUTU8 (&MB_Buff[MB_TCP_UID], MB.UnitIdentifier);
		MB_Data_To_Send = sizeof(MB) + MB_Count + 2;
		return 1;
		
	case MBF_READ_COILS:		
		tmp3=MB_Count / 8;
		if(MB_Count - tmp3*8) tmp3++;
		MB_Count = tmp3;
		MB_Buff[MB_TCP_FUNC] = MB_Function;	
		MB_Buff[MB_TCP_BCNT] = MB_Count;
		tmp1=1;
		for(i=0; i<MB_Count; i++)
		{
			tmp2=0;
			for(j=0; j<8; j++)
			{			
				tmp1 = 1<<(j+i*8);
				if(io.dout & tmp1) tmp2 |= 1<<j;
			}
			MB_Buff[MB_TCP_BDAT+i] = tmp2;	
		}
		MB.Length= MB_Count + 3;
		PUTU16(&MB_Buff[MB_TCP_TID], MB.TransactionIdentifier);
		PUTU16(&MB_Buff[MB_TCP_PID], MB.ProtocolIdentifier);
		PUTU16(&MB_Buff[MB_TCP_LEN], MB.Length);
		PUTU8 (&MB_Buff[MB_TCP_UID], MB.UnitIdentifier);
		MB_Data_To_Send = sizeof(MB) + MB_Count + 2;
		return 1;
		

	case MBF_WRITE_SINGLE_COIL:		
		if(MB_Addr < io.num_do)
		{
			if(MB_Count)
				io.dout |= 1L<<MB_Addr;	
			else
				io.dout &=~ (1L<<MB_Addr);	
		}
		PUTU16(&MB_Buff[MB_TCP_TID], MB.TransactionIdentifier);
		PUTU16(&MB_Buff[MB_TCP_PID], MB.ProtocolIdentifier);
		PUTU16(&MB_Buff[MB_TCP_LEN], MB.Length);
		PUTU8 (&MB_Buff[MB_TCP_UID], MB.UnitIdentifier);

		PUTU8 (&MB_Buff[MB_TCP_FUNC], MB_Function);
		PUTU16(&MB_Buff[MB_TCP_ADDR], MB_Addr);
		PUTU16(&MB_Buff[MB_TCP_COUNT], MB_Count);
		
		MB_Data_To_Send = sizeof(MB) + 5;
		return 1;

	case MBF_WRITE_MULTIPLE_COILS:	
//		GETU32(tmp1,&data[MB_TCP_VALUE]);
		tmp1=*(u32*)&data[MB_TCP_VALUE];
		tmp1 = tmp1 << MB_Addr;
		for(i=MB_Addr; i<(MB_Addr+MB_Count); i++)
			if(i < io.num_do)
			{
				if(tmp1 & (1 << i))
					io.dout |= 1L<<i;	
				else
					io.dout &=~ (1L<<i);	
			}
		PUTU16(&MB_Buff[MB_TCP_TID], MB.TransactionIdentifier);
		PUTU16(&MB_Buff[MB_TCP_PID], MB.ProtocolIdentifier);
		PUTU16(&MB_Buff[MB_TCP_LEN], MB.Length);
		PUTU8 (&MB_Buff[MB_TCP_UID], MB.UnitIdentifier);

		PUTU8 (&MB_Buff[MB_TCP_FUNC], MB_Function);
		PUTU16(&MB_Buff[MB_TCP_ADDR], MB_Addr);
		PUTU16(&MB_Buff[MB_TCP_COUNT], MB_Count);
		
		MB_Data_To_Send = sizeof(MB) + 5;
		return 1;		


	case MBF_READ_INPUT_REGISTERS:	
		MB_Buff[MB_TCP_FUNC] = MB_Function;	
		MB_Buff[MB_TCP_BCNT] = MB_Count*2;
		for(i=MB_Addr; i<(MB_Addr + MB_Count); i++)
		{
			if(i<io.num_ai)	PUTU16(&MB_Buff[MB_TCP_BDAT+(i-MB_Addr)*2], io.ainput[i])
			else			PUTU16(&MB_Buff[MB_TCP_BDAT+(i-MB_Addr)*2], 0);
		}
		MB.Length= MB_Count*2 + 3;

		PUTU16(&MB_Buff[MB_TCP_TID], MB.TransactionIdentifier);
		PUTU16(&MB_Buff[MB_TCP_PID], MB.ProtocolIdentifier);
		PUTU16(&MB_Buff[MB_TCP_LEN], MB.Length);
		PUTU8 (&MB_Buff[MB_TCP_UID], MB.UnitIdentifier);

		PUTU8 (&MB_Buff[MB_TCP_FUNC], MB_Function);
		MB_Data_To_Send = sizeof(MB) + MB.Length - 1;
		return 1;	

	case MBF_READ_HOLDING_REGISTERS:	
		MB_Buff[MB_TCP_FUNC] = MB_Function;	
		MB_Buff[MB_TCP_BCNT] = MB_Count*2;
		for(i=MB_Addr; i<(MB_Addr + MB_Count); i++)
		{
			PUTU16(&MB_Buff[MB_TCP_BDAT+(i-MB_Addr)*2], MB_Get_Holding_Register(i));
		}
		MB.Length= MB_Count*2 + 3;

		PUTU16(&MB_Buff[MB_TCP_TID], MB.TransactionIdentifier);
		PUTU16(&MB_Buff[MB_TCP_PID], MB.ProtocolIdentifier);
		PUTU16(&MB_Buff[MB_TCP_LEN], MB.Length);
		PUTU8 (&MB_Buff[MB_TCP_UID], MB.UnitIdentifier);

		PUTU8 (&MB_Buff[MB_TCP_FUNC], MB_Function);
		MB_Data_To_Send = sizeof(MB) + MB.Length - 1;
		return 1;	

	case MBF_WRITE_SINGLE_REGISTER:	
		MB_Set_Holding_Register(MB_Addr, MB_Count);
		MB_Count = MB_Get_Holding_Register(MB_Addr);
		
		PUTU16(&MB_Buff[MB_TCP_ADDR], MB_Addr);
		PUTU16(&MB_Buff[MB_TCP_COUNT], MB_Count);

		MB.Length= 5+1;

		PUTU16(&MB_Buff[MB_TCP_TID], MB.TransactionIdentifier);
		PUTU16(&MB_Buff[MB_TCP_PID], MB.ProtocolIdentifier);
		PUTU16(&MB_Buff[MB_TCP_LEN], MB.Length);
		PUTU8 (&MB_Buff[MB_TCP_UID], MB.UnitIdentifier);

		PUTU8 (&MB_Buff[MB_TCP_FUNC], MB_Function);
		MB_Data_To_Send = sizeof(MB) + MB.Length - 1;
		return 1;	
		
	// Exeption Illegal function
	default:
		MB_Count=1;
		MB_Function = MBF_EXCEPTION;
		MB_Buff[MB_TCP_FUNC] = MB_Function;	
		MB_Buff[MB_TCP_DATA] = MB_EXEPTION_FUNCTION;
		MB.Length= MB_Count + 3;
		PUTU16(&MB_Buff[MB_TCP_TID], MB.TransactionIdentifier);
		PUTU16(&MB_Buff[MB_TCP_PID], MB.ProtocolIdentifier);
		PUTU16(&MB_Buff[MB_TCP_LEN], MB.Length);
		PUTU8 (&MB_Buff[MB_TCP_UID], MB.UnitIdentifier);
		MB_Data_To_Send = sizeof(MB) + MB_Count + 2;
		return 1;
	}
}

//*****************************************************************************

void MODBus_TXHandler(u8 *data,u16 *len)
{	
	memcpy(data,MB_Buff,MB_Data_To_Send);
	*len=MB_Data_To_Send;
}

//*****************************************************************************