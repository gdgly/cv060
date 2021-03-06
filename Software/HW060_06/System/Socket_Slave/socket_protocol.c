//-----------------------------------------------------------------------------------
#include "main.h"
//-----------------------------------------------------------------------------------
extern  u32 HW;
extern  u32 HW_in;
//-----------------------------------------------------------------------------------
void upc_answer_store_parameters();
void upc_answer_set_id();
void upc_answer_fan(u8 fan_num);
void upc_answer_kotel(u8 kot_num);
void upc_answer_pid(u8 pid_num);
void upc_answer_packet_timeout();

void upc_set_pid();
void upc_set_fan();
void upc_set_kotel();
void upc_answer_kotel_params(u8 kot_num);
void upc_set_kotel_params();
void upc_answer_errors();
void upc_answer_info(u8 what);
void upc_answer_get_season();
void upc_answer_set_season();
void upc_answer_set_register_advanced();
void upc_answer_get_register_advanced();
void upc_answer_clear_errors();
void upc_set_do();
//-----------------------------------------------------------------------------------
unsigned char sock_RXHandler(u8 *data,u16 len)
{	
	u8	upc_rxd;
	upc.rxcount=0;
	while(len>0)
	{
	  	len--;
		upc_rxd=*data;
		data++;
		switch(upc.rxcount)
		{
			case 0:
				if(upc_rxd!=PREAMBULA_LOW)
				{
					upc.rxcount=0;	
					return 0;
				}
			break;
			case 1:
				if(upc_rxd!=PREAMBULA_HIGH)
				{
					upc.rxcount=0;	
					return 0;
				}
			break;		
		}
		rx.data.d[upc.rxcount]=upc_rxd;
		upc.rxcount++;		
		if((upc.rxcount)==(PACKET_HEADER_LEN))	
			if(upc_crc_head(&rx)!=rx.field.crc_head)
			{
				upc.rxcount=0;	
	//			LED_Time=50;
				return 0;
			}
		if((upc.rxcount)>(rx.field.len+PACKET_HEADER_LEN-1))	
		{
	
			upc.rxcount=0;	
			if(upc_crc_data(&rx)==rx.field.crc_data)
			{
	//			if((rx.field.com.bit.id==ID)||(rx.field.com.bit.id==0))
	//			if((rx.field.com.bit.id==ID))			
				{
					upc.rxnew=1;		
		//			mem_dump(rx.field.d,10);
					switch(rx.field.com.bit.com)
					{
						case com_reqt_status:
							if(rx.field.com.bit.id==ID[3])
								upc_answer_sys();	
						break;
						case com_get_stat:
							if(rx.field.com.bit.id==ID[3])
								upc_answer_sys();	
						break;
						case com_reqt_reset:
							if((rx.field.com.bit.id==ID[3])||(rx.field.com.bit.id==0))
								reset();
						break;					
						case com_reqt_res_hw:
							HW_in=*(u32*)&rx.field.d[0];
							if(HW==HW_in)
								reset();
						break;					
						
						case com_get_io:
							if((rx.field.com.bit.id==ID[3])||(rx.field.com.bit.id==0))
								upc_answer_io();	
						break;
	
						case com_get_pid:
							if(rx.field.com.bit.id==ID[3])						
								upc_answer_pid(rx.field.d[0]);	
						break;		
						
						case com_get_fan:
							if(rx.field.com.bit.id==ID[3])						
								upc_answer_fan(rx.field.d[0]);	
						break;		
	
						case com_get_kotel:
							if(rx.field.com.bit.id==ID[3])						
								upc_answer_kotel(rx.field.d[0]);	
						break;		
						case com_get_kotel_params:
							if(rx.field.com.bit.id==ID[3])						
								upc_answer_kotel_params(rx.field.d[0]);	
						break;		
						
						case com_get_errors:
							if(rx.field.com.bit.id==ID[3])
								upc_answer_errors();
						break;		
						case com_set_errors:
							if(rx.field.com.bit.id==ID[3])
								upc_answer_clear_errors();
						break;		
	
						case com_set_stat:
							if((rx.field.com.bit.id==ID[3])||(rx.field.com.bit.id==0))
								upc_set_sys();	
						break;
						case com_set_io:
							if((rx.field.com.bit.id==ID[3])||(rx.field.com.bit.id==0))
								upc_set_io();	
						break;
	
						case com_set_pid:
							if((rx.field.com.bit.id==ID[3])||(rx.field.com.bit.id==0))
								upc_set_pid();	
						break;		
						
						case com_set_fan:
							if((rx.field.com.bit.id==ID[3])||(rx.field.com.bit.id==0))
								upc_set_fan();	
						break;	
						
						case com_set_kotel:
							if((rx.field.com.bit.id==ID[3])||(rx.field.com.bit.id==0))
								upc_set_kotel();	
						break;	
						
						case com_set_kotel_params:
							if((rx.field.com.bit.id==ID[3])||(rx.field.com.bit.id==0))
								upc_set_kotel_params();	
						break;	
	
						// Time			
						case com_get_time:
							if(rx.field.com.bit.id==ID[3])
								upc_answer_time();	
						break;	
						case com_set_time:
							if((rx.field.com.bit.id==ID[3])||(rx.field.com.bit.id==0))
								upc_set_time();	
						break;	
						case com_set_in_params:
							if((rx.field.com.bit.id==ID[3])||(rx.field.com.bit.id==0))
								upc_set_in_parameters();		
						break;				
						case com_get_out_params:
							if(rx.field.com.bit.id==ID[3])
								upc_answer_out_parameters();		
						break;				
						case com_store_params:
							if((rx.field.com.bit.id==ID[3])||(rx.field.com.bit.id==0))
								upc_answer_store_parameters();		
						break;				
						case com_set_manual:
							if((rx.field.com.bit.id==ID[3])||(rx.field.com.bit.id==0))
								upc_answer_set_manual();	
						break;
						case com_set_season:
							if((rx.field.com.bit.id==ID[3])||(rx.field.com.bit.id==0))
								upc_answer_set_season();		
						break;
						case com_get_season:
							if((rx.field.com.bit.id==ID[3])||(rx.field.com.bit.id==0))
								upc_answer_get_season();	
						break;
						case com_set_misc_rec:
							if((rx.field.com.bit.id==ID[3])||(rx.field.com.bit.id==0))
								upc_answer_set_misc();		
						break;
						case com_get_misc_rec:
							if((rx.field.com.bit.id==ID[3])||(rx.field.com.bit.id==0))
								upc_answer_get_misc();	
						break;
						// Registers operation
						case com_set_register:
							if((rx.field.com.bit.id==ID[3])||(rx.field.com.bit.id==0))
								upc_answer_set_register();		
						break;						
						case com_get_register:
							if((rx.field.com.bit.id==ID[3])||(rx.field.com.bit.id==0))
								upc_answer_get_register();		
						break;				
						// Advanced registers operation	
						case com_set_register_adv:
							if((rx.field.com.bit.id==ID[3])||(rx.field.com.bit.id==0))
								upc_answer_set_register_advanced();		
						break;						
						case com_get_register_adv:
							if((rx.field.com.bit.id==ID[3])||(rx.field.com.bit.id==0))
								upc_answer_get_register_advanced();		
						break;				
	
						case com_set_id:
							if((rx.field.com.bit.id==ID[3]))
								upc_answer_set_id();		
						break;				
						case com_reqt_sys_info:
							if(rx.field.com.bit.id==ID[3])
								upc_answer_info(1);
						break;		
						case com_reqt_menu_info:
							if(rx.field.com.bit.id==ID[3])
								upc_answer_info(3);
						break;		
						case com_reqt_sys_name:
							if(rx.field.com.bit.id==ID[3])
								upc_answer_info(2);																																		
						break;		
						case com_reqt_menu_name:
							if(rx.field.com.bit.id==ID[3])
								upc_answer_info(4);
						break;			
						case com_get_enabled_options:
							if(rx.field.com.bit.id==ID[3])
								upc_answer_info(5);
						break;			
						
						case com_set_do:
							if((rx.field.com.bit.id==ID[3])||(rx.field.com.bit.id==0))
								upc_set_do();						
						
						default:
						break;
		
					}
					return 1;
				}
			}
			else
			{
				// BAD CRC
				__sprintf(outtxt,"\n\r Bad CRC!");
	//			LED_Time=50;
			}
		}	
	}
	return 0;
}
//-----------------------------------------------------------------------------------
void sock_TXHandler(u8 *data,u16 *len)
{	
  	*len=tx.field.len+PACKET_HEADER_LEN;
  	if(upc.txnew) memcpy(data,&tx,*len);
	upc.done=1;		
	upc.txnew=0;
}
//-----------------------------------------------------------------------------------
