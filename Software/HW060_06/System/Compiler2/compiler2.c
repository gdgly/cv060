//-----------------------------------------------------------------------------------
#ifdef __COMPILER2
//-----------------------------------------------------------------------------------
#include "main.h"
//-----------------------------------------------------------------------------------
u8 i;
u8 Program_Valid=0;
TProgLine pline;
TVarBin	in_flash *dbg_VarTable=(TVarBin	in_flash *)DATA_START_ADDR;
//-----------------------------------------------------------------------------------
void Intr_Init()
{
	memset((void *)&intr, 0, sizeof(intr));	
	intr.addr=CODE_START_ADDR;
	intr.status=program_stop;
}
//-----------------------------------------------------------------------------------
void Intr_Program_Start()
{
	Program_Valid=1;
//	if(Program_Valid==0)return;
	memset((void *)&intr, 0, sizeof(intr));		
	intr.addr=CODE_START_ADDR;
	intr.status=program_run;	// ON
}
//-----------------------------------------------------------------------------------
void Intr_Program_Stop()
{
	intr.status=program_stop;	// off
}
//-----------------------------------------------------------------------------------
void Intr_Debug_Output()
{
	u32 addr = intr.addr - CODE_START_ADDR;
	sprintf((u8*)outtxt,"\n\r Addr:%d ",addr);	
	wait_con_free();
	sprintf((u8*)outtxt,"\n\r OP:%x",pline.fields.d);	
	wait_con_free();
	sprintf((u8*)outtxt,"\n\r OP1 Type:%x Index:%x Value:%x",pline.fields.op1.type, pline.fields.op1.index, pline.fields.op1.body);	
	wait_con_free();
	sprintf((u8*)outtxt,"\n\r OP2 Type:%x Index:%x Value:%x",pline.fields.op2.type, pline.fields.op2.index, pline.fields.op2.body);	
	wait_con_free();
	sprintf((u8*)outtxt,"\n\r RES Type:%x Index:%x Value:%x",pline.fields.res.type, pline.fields.res.index, pline.fields.res.body);	
	wait_con_free();
	console_wait_rx_new_byte();
}
//-----------------------------------------------------------------------------------
void Intr_Handle()
{
	if(MenuRegs.Manual_Mode==MANUAL_MODE)return;
	if(intr.status!=program_run)return;
	FGet(intr.addr,(u8*)&pline,CODE_LINE_LEN);
	intr.addr+=CODE_LINE_LEN;
//	__sprintf(outtxt,"\n\r");
//	LongToStr(outtxt,&pline.fields.line,0);	
//	mem_dump((u8*)&pline,8);
//	Delay(2000);
//	watchdog_reset();
//	Delay(2000);
//	watchdog_reset();
	//Intr_Debug_Output();
	Intr_Program_Line_Handle();
}
//-----------------------------------------------------------------------------------
void Intr_Program_Line_Handle()
{
	Intr_Program_Line_Handle_GoTo();
	Intr_Program_Line_Handle_Math();
}
//-----------------------------------------------------------------------------------
s32 get_variable(u8 i)
{
	s32	tmp32;
    switch(dbg_VarTable[i].type[0])
    {
    	case 1:
               tmp32=*((s8*)&intr.mem[dbg_VarTable[i].offset]);
        break;
    	case 2:
               tmp32=*((u8*)&intr.mem[dbg_VarTable[i].offset]);
        break;
    	case 3:
               tmp32=*((s16*)&intr.mem[dbg_VarTable[i].offset]);
        break;
	   	case 4:
               tmp32=*((u16*)&intr.mem[dbg_VarTable[i].offset]);
        break;
    	case 5:
               tmp32=*((s32*)&intr.mem[dbg_VarTable[i].offset]);
        break;
    	case 6:
               tmp32=*((u32*)&intr.mem[dbg_VarTable[i].offset]);
        break;
    }
    return tmp32;
}
//-----------------------------------------------------------------------------------
void set_variable(u8 i,s32 value)
{
//	s32	tmp32;
    switch(dbg_VarTable[i].type[0])
    {
    	case 1:
               *((s8*)&intr.mem[dbg_VarTable[i].offset])=value;
        break;
    	case 2:
               *((u8*)&intr.mem[dbg_VarTable[i].offset])=value;
        break;
    	case 3:
               *((s16*)&intr.mem[dbg_VarTable[i].offset])=value;
        break;
    	case 4:
               *((u16*)&intr.mem[dbg_VarTable[i].offset])=value;
        break;
    	case 5:
               *((s32*)&intr.mem[dbg_VarTable[i].offset])=value;
        break;
    	case 6:
               *((u32*)&intr.mem[dbg_VarTable[i].offset])=value;
        break;
    }
}
//-----------------------------------------------------------------------------------
s32 get_operand(TOperandFields32 op)
{
	s32 tmp32 = 0;
	switch(op.type)
	{
		case TYPE_VAR+0:
        	tmp32=get_variable(op.body.u32d);
            break;
/*
#define TYPE_S8           1
#define TYPE_U8           2
#define TYPE_S16          3
#define TYPE_U16          4
#define TYPE_S32          5
#define TYPE_U32          6
#define TYPE_F32          7
*/
		case TYPE_S8:				tmp32=op.body.s8d;break;
		case TYPE_S8+1:				tmp32=op.body.u8d;break;
		case TYPE_S8+2:				tmp32=op.body.s16d;break;
		case TYPE_S8+3:				tmp32=op.body.u16d;break;
		case TYPE_S8+4:				tmp32=op.body.s32d;break;
		case TYPE_S8+5:				tmp32=op.body.u32d;break;
//		case TYPE_S8+6:				tmp32=op.body.f32d;break;
/*
RR_00="reg"
RR_01="ai"
RR_02="ao"
RR_03="di"
RR_04="do"
RR_05="timer"
RR_06="in_param"
RR_07="out_param"
RR_08="error"
RR_09="acc"

RR_10="season"
RR_11="___"
RR_12="timer"
RR_13="beep"

RR_14="pid_t"
RR_15="pid_mode"
RR_16="pid_pow"
RR_17="pid_pow_min"
RR_18="pid_pow_max"
RR_19="pid_t3max"
RR_20="pid_open"
RR_21="pid_close"
RR_22="pid_p3"
RR_23="pid_channel"
RR_24="pid_slow"
RR_25="pid_fast"
RR_26="pid_hc"
RR_27="pid_reserve"

RR_28="fan_channel"
RR_29="fan_t"
RR_30="fan_mode"
RR_31="fan_lvl"
RR_32="fan_low"
RR_33="fan_medium"
RR_34="fan_high"
RR_35="fan_hyst"
RR_36="fan_time"
RR_37="fan_day"
*/
		case TYPE_REG+0:			if(op.index<REGISTERS_MAX)tmp32=intr.reg[op.index];break;
		case TYPE_REG+1:			if(op.index<NUM_AIN)tmp32=io.ainput[op.index];break;
		case TYPE_REG+2:			if(op.index<NUM_AOUT)tmp32=io.aoutput[op.index];break;
		case TYPE_REG+3:			if(op.index<NUM_DIN)tmp32=(io.din>>op.index) & 1;break;
		case TYPE_REG+4:			if(op.index<NUM_DOUT)tmp32=(io.dout>>op.index) & 1;break;
		case TYPE_REG+38:			tmp32=io.din;break;
		case TYPE_REG+39:			tmp32=io.dout;break;
		
		case TYPE_REG+5:			if(op.index<TIMERS_MAX)tmp32=intr.t32[op.index];break;
		case TYPE_REG+6:			if(op.index<PARAMETERS_MAX)tmp32=intr.in_params[op.index];break;
		case TYPE_REG+7:			if(op.index<PARAMETERS_MAX)tmp32=intr.out_params[op.index];break;

//		case TYPE_REG+8:			if(op.index<PARAMETERS_MAX)tmp32=intr.out_params[op.index];break;
		
		case TYPE_REG+9:			tmp32=intr.acc;break;
#if MAX_SEASON_BLOCK
		case TYPE_REG+10:			tmp32=reg_season.season;break;	
#endif
		case TYPE_REG+11:			tmp32=errors.new_error;break;	
		case TYPE_REG+12:			if(op.index<TIMERS_MAX)tmp32=intr.t32[op.index];break;
		case TYPE_REG+13:			tmp32=BuzzerTime;break;
#if NUM_PID
		case TYPE_REG+23:			if(op.index<NUM_PID)tmp32=pid[op.index].channel;break;			
		case TYPE_REG+14:			if(op.index<NUM_PID)tmp32=pid[op.index].t0;break;			
		case TYPE_REG+18:			if(op.index<NUM_PID)tmp32=pid[op.index].power_max;break;			
		case TYPE_REG+17:			if(op.index<NUM_PID)tmp32=pid[op.index].power_min;break;			
		case TYPE_REG+16:			if(op.index<NUM_PID)tmp32=pid[op.index].power;break;			
		case TYPE_REG+15:			if(op.index<NUM_PID)tmp32=pid[op.index].mode;break;	
		case TYPE_REG+24:			if(op.index<NUM_PID)tmp32=pid[op.index].PID_POWER_STEP[0]*1000;break;			
		case TYPE_REG+25:			if(op.index<NUM_PID)tmp32=pid[op.index].PID_POWER_STEP[1]*1000;break;	
		case TYPE_REG+26:			if(op.index<NUM_PID)tmp32=pid[op.index].heating_cooling;break;	
		
		case TYPE_REG+73:			if(op.index<NUM_PID)tmp32=pid[op.index].fan_in;break;	
		case TYPE_REG+74:			if(op.index<NUM_PID)tmp32=pid[op.index].fan_out;break;	
#endif
#if MAX_FANCOIL_NUMBER
		case TYPE_REG+28:			if(op.index<MAX_FANCOIL_NUMBER)tmp32=fan[op.index].Channel;break;	
		case TYPE_REG+29:			if(op.index<MAX_FANCOIL_NUMBER)tmp32=fan[op.index].T;break;	
		case TYPE_REG+30:			if(op.index<MAX_FANCOIL_NUMBER)tmp32=fan[op.index].Fan_Mode;break;	
		case TYPE_REG+31:			if(op.index<MAX_FANCOIL_NUMBER)tmp32=fan[op.index].Fan_Lvl;break;	
		case TYPE_REG+32:			if(op.index<MAX_FANCOIL_NUMBER)tmp32=fan[op.index].TLow;break;	
		case TYPE_REG+33:			if(op.index<MAX_FANCOIL_NUMBER)tmp32=fan[op.index].TMedium;break;	
		case TYPE_REG+34:			if(op.index<MAX_FANCOIL_NUMBER)tmp32=fan[op.index].THigh;break;	
		case TYPE_REG+35:			if(op.index<MAX_FANCOIL_NUMBER)tmp32=fan[op.index].Hysteresis;break;	
		case TYPE_REG+36:			if(op.index<MAX_FANCOIL_NUMBER)tmp32=fan[op.index].Fan_Time;break;	
		case TYPE_REG+37:			if(op.index<MAX_FANCOIL_NUMBER)tmp32=fan[op.index].Day_Night;break;	
		case TYPE_REG+81:			if(op.index<MAX_FANCOIL_NUMBER)tmp32=fan[op.index].T_In;break;	
		case TYPE_REG+82:			if(op.index<MAX_FANCOIL_NUMBER)tmp32=fan[op.index].HC;break;			
#endif		
#if MAX_KOTEL_NUMBER
		case TYPE_REG+40:			tmp32=kotel.mode;break;	
		case TYPE_REG+41:			tmp32=kotel.t;break;	
		case TYPE_REG+42:			tmp32=kotel.channel;break;	
		case TYPE_REG+43:			tmp32=kotel.fuel;break;	
		case TYPE_REG+44:			tmp32=kotel.fan_out[0];break;	
		case TYPE_REG+45:			tmp32=kotel.fan_out[1];break;
		case TYPE_REG+46:			tmp32=kotel.smoke_out;break;
		case TYPE_REG+47:			tmp32=kotel.shnek_out[0];break;	
		case TYPE_REG+48:			tmp32=kotel.shnek_out[1];break;
		
		case TYPE_REG+49:			tmp32=kotel.t3max;break;
		case TYPE_REG+50:			tmp32=kotel.p3;break;
		case TYPE_REG+51:			tmp32=kotel.power;break;
		case TYPE_REG+52:			tmp32=kotel.open;break;
		case TYPE_REG+53:			tmp32=kotel.close;break;
#endif
#if MAX_VALVE_3T_NUMBER
		case TYPE_REG+54:			tmp32=valve[op.index].t3max;break;	
		case TYPE_REG+55:			tmp32=valve[op.index].open;break;	
		case TYPE_REG+56:			tmp32=valve[op.index].close;break;	
		case TYPE_REG+57:			tmp32=valve[op.index].power;break;	
		case TYPE_REG+27:			tmp32=valve[op.index].p3;break;			
#endif	
#if NUM_PID
		case TYPE_REG+63:			if(op.index<NUM_PID)tmp32=pid[op.index].channel;break;			
		case TYPE_REG+58:			if(op.index<NUM_PID)tmp32=pid[op.index].t0;break;			
		case TYPE_REG+62:			if(op.index<NUM_PID)tmp32=pid[op.index].power_max;break;			
		case TYPE_REG+61:			if(op.index<NUM_PID)tmp32=pid[op.index].power_min;break;			
		case TYPE_REG+60:			if(op.index<NUM_PID)tmp32=pid[op.index].power;break;			
		case TYPE_REG+59:			if(op.index<NUM_PID)tmp32=pid[op.index].mode;break;	
		case TYPE_REG+64:			if(op.index<NUM_PID)tmp32=pid[op.index].PID_POWER_STEP[0]*1000;break;			
		case TYPE_REG+65:			if(op.index<NUM_PID)tmp32=pid[op.index].PID_POWER_STEP[1]*1000;break;	
		case TYPE_REG+66:			if(op.index<NUM_PID)tmp32=pid[op.index].heating_cooling;break;	

		case TYPE_REG+67:			if(op.index<NUM_PID)tmp32=pid[op.index].fan_in;break;	
		case TYPE_REG+68:			if(op.index<NUM_PID)tmp32=pid[op.index].fan_out;break;	
		case TYPE_REG+69:			if(op.index<NUM_PID)tmp32=pid[op.index].tin;break;			
#endif
#if MAX_SEASON_BLOCK
		case TYPE_REG+75:			tmp32=reg_season.t_extern_channel;break;	
		case TYPE_REG+76:			tmp32=reg_season.mode;break;	
		case TYPE_REG+77:			tmp32=reg_season.switch_temperature;break;	
		case TYPE_REG+78:			tmp32=reg_season.switch_date;break;	
		case TYPE_REG+79:			tmp32=reg_season.t;break;	
#endif
#if MAX_PARAMS_BLOCK
		case TYPE_REG+80:			if (op.index < MAX_PARAMS_NUM) tmp32 = misc.pr[op.index]; break;	
#endif	
#if NET_PARAMETERS_MAX
		case TYPE_REG+83:			if (op.index < NET_PARAMETERS_MAX) tmp32 = net_params[op.index]; break;	
#endif			
	}
	return tmp32;
}
//-----------------------------------------------------------------------------------
void set_operand(TOperandFields32 op,s32 value)
{
	s32 tmp32 = 0;
	switch(op.type)
	{

		case TYPE_VAR+0:
			set_variable(op.body.u32d,value);
            break;
/*
RR_00="reg"
RR_01="ai"
RR_02="ao"
RR_03="di"
RR_04="do"
RR_05="timer"
RR_06="in_param"
RR_07="out_param"
*/
		case TYPE_REG+0:			if(op.index<REGISTERS_MAX)intr.reg[op.index]=value;break;
		case TYPE_REG+1:			if(op.index<NUM_AIN)io.ainput[op.index]=value;break;
		case TYPE_REG+2:			if(op.index<NUM_AOUT)io.aoutput[op.index]=(s16)value;break;
		case TYPE_REG+4:
        		if(op.index<NUM_DOUT)
                {
					tmp32=1<<op.index;
					if(value!=0)io.dout|=tmp32;
					else io.dout&=~tmp32;
                }
        	break;

		case TYPE_REG+38:			io.din=value;break;
		case TYPE_REG+39:			io.dout=value;break;
		
		case TYPE_REG+5:			if(op.index<TIMERS_MAX)intr.t32[op.index]=value; break;
		case TYPE_REG+6:			if(op.index<PARAMETERS_MAX)intr.in_params[op.index]=value;break;
		case TYPE_REG+7:			if(op.index<PARAMETERS_MAX)intr.out_params[op.index]=value;break;
		case TYPE_REG+8:			error_insert(value);break;
		case TYPE_REG+9:			intr.acc=value;break;
		
		case TYPE_REG+10:			reg_season.season=value;break;			
		case TYPE_REG+11:			errors.new_error=value;break;			
		case TYPE_REG+12:			if(op.index<TIMERS_MAX)intr.t32[op.index]=value;break;
		case TYPE_REG+13:			BuzzerTime=value;break;
#if NUM_PID		
		case TYPE_REG+23:			if(op.index<NUM_PID)pid[op.index].channel=value;break;			
		case TYPE_REG+14:			if(op.index<NUM_PID)pid[op.index].t0=value;break;			
		case TYPE_REG+18:			if(op.index<NUM_PID)pid[op.index].power_max=value;break;			
		case TYPE_REG+17:			if(op.index<NUM_PID)pid[op.index].power_min=value;break;			
		case TYPE_REG+16:			if(op.index<NUM_PID)pid[op.index].power=value;break;			
		case TYPE_REG+15:			if(op.index<NUM_PID)pid[op.index].mode=value;break;	
		case TYPE_REG+24:			if(op.index<NUM_PID)pid[op.index].PID_POWER_STEP[0]=value/1000.0;break;			
		case TYPE_REG+25:			if(op.index<NUM_PID)pid[op.index].PID_POWER_STEP[1]=value/1000.0;break;	
		case TYPE_REG+26:			if(op.index<NUM_PID)pid[op.index].heating_cooling=value;break;	
		
		case TYPE_REG+73:			if(op.index<NUM_PID)pid[op.index].fan_in=value;break;	
		case TYPE_REG+74:			if(op.index<NUM_PID)pid[op.index].fan_out=value;break;	
		
#endif
#if MAX_FANCOIL_NUMBER
		case TYPE_REG+28:			if(op.index<MAX_FANCOIL_NUMBER)fan[op.index].Channel=value;break;	
		case TYPE_REG+29:			if(op.index<MAX_FANCOIL_NUMBER)fan[op.index].T=value;break;	
		case TYPE_REG+30:			if(op.index<MAX_FANCOIL_NUMBER)fan[op.index].Fan_Mode=value;break;	
		case TYPE_REG+31:			if(op.index<MAX_FANCOIL_NUMBER)fan[op.index].Fan_Lvl=value;break;	
		case TYPE_REG+32:			if(op.index<MAX_FANCOIL_NUMBER)fan[op.index].TLow=value;break;	
		case TYPE_REG+33:			if(op.index<MAX_FANCOIL_NUMBER)fan[op.index].TMedium=value;break;	
		case TYPE_REG+34:			if(op.index<MAX_FANCOIL_NUMBER)fan[op.index].THigh=value;break;	
		case TYPE_REG+35:			if(op.index<MAX_FANCOIL_NUMBER)fan[op.index].Hysteresis=value;break;	
		case TYPE_REG+36:			if(op.index<MAX_FANCOIL_NUMBER)fan[op.index].Fan_Time=value;break;	
		case TYPE_REG+37:			if(op.index<MAX_FANCOIL_NUMBER)fan[op.index].Day_Night=value;break;		
		case TYPE_REG+81:			if(op.index<MAX_FANCOIL_NUMBER)fan[op.index].T_In=value;break;	
		case TYPE_REG+82:			if(op.index<MAX_FANCOIL_NUMBER)fan[op.index].HC=value;break;		
#endif					
#if MAX_KOTEL_NUMBER
		case TYPE_REG+40:			kotel.mode=value;break;	
		case TYPE_REG+41:			kotel.t=value;break;	
		case TYPE_REG+42:			kotel.channel=value;break;	
		case TYPE_REG+43:			kotel.fuel=value;break;	
		case TYPE_REG+44:			kotel.fan_out[0]=value;break;	
		case TYPE_REG+45:			kotel.fan_out[1]=value;break;
		case TYPE_REG+46:			kotel.smoke_out=value;break;
		case TYPE_REG+47:			kotel.shnek_out[0]=value;break;	
		case TYPE_REG+48:			kotel.shnek_out[1]=value;break;
		
		case TYPE_REG+49:			kotel.t3max=value;break;
		case TYPE_REG+50:			kotel.p3=value;break;
		case TYPE_REG+51:			kotel.power=value;break;
		case TYPE_REG+52:			kotel.open=value;break;
		case TYPE_REG+53:			kotel.close=value;break;
#endif		
#if MAX_VALVE_3T_NUMBER
		case TYPE_REG+54:			valve[op.index].t3max=value;break;	
//		case TYPE_REG+55:			v3t.open=value;break;	
//		case TYPE_REG+56:			v3t.close=value;break;	
		case TYPE_REG+57:			valve[op.index].power=value;break;	
		case TYPE_REG+27:			valve[op.index].p3=value;break;	
#endif		
#if NUM_PID		
		case TYPE_REG+63:			if(op.index<NUM_PID)pid[op.index].channel=value;break;			
		case TYPE_REG+58:			if(op.index<NUM_PID)pid[op.index].t0=value;break;			
		case TYPE_REG+62:			if(op.index<NUM_PID)pid[op.index].power_max=value;break;			
		case TYPE_REG+61:			if(op.index<NUM_PID)pid[op.index].power_min=value;break;			
		case TYPE_REG+60:			/* if(op.index<NUM_PID)pid[op.index].power=value;*/ set_pid_power(op.index, value); break;			
		case TYPE_REG+59:			if(op.index<NUM_PID)pid[op.index].mode=value;break;	
		case TYPE_REG+64:			if(op.index<NUM_PID)pid[op.index].PID_POWER_STEP[0]=value/1000.0;break;			
		case TYPE_REG+65:			if(op.index<NUM_PID)pid[op.index].PID_POWER_STEP[1]=value/1000.0;break;	
		case TYPE_REG+66:			if(op.index<NUM_PID)pid[op.index].heating_cooling=value;break;	

		case TYPE_REG+67:			if(op.index<NUM_PID)pid[op.index].fan_in=value;break;	
		case TYPE_REG+68:			if(op.index<NUM_PID)pid[op.index].fan_out=value;break;	
		case TYPE_REG+69:			if(op.index<NUM_PID)pid[op.index].tin=value;break;			
#endif
#if MAX_SEASON_BLOCK
		case TYPE_REG+75:			reg_season.t_extern_channel=value;break;	
		case TYPE_REG+76:			reg_season.mode=value;break;	
		case TYPE_REG+77:			reg_season.switch_temperature=value;break;	
		case TYPE_REG+78:			reg_season.switch_date=value;break;	
		case TYPE_REG+79:			reg_season.t=value;break;	
#endif

#if MAX_PARAMS_BLOCK
		case TYPE_REG+80:			if (op.index < MAX_PARAMS_NUM) misc.pr[op.index] = value; break;	
#endif		

#if NET_PARAMETERS_MAX
		case TYPE_REG+83:			if (op.index < NET_PARAMETERS_MAX) regs_set(op.index, value); break;	
#endif			
	}
}
//-----------------------------------------------------------------------------------
#endif
//-----------------------------------------------------------------------------------
