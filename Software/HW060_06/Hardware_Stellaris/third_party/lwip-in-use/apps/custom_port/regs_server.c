//------------------------------------------------------------------------------
#include "main.h"

#include "lwip/debug.h"
#include "lwip/stats.h"
#include "regs_port.h"
#include "lwip/tcp.h"
#include "lwip/udp.h"
#include "fs.h"
#include <string.h>
#include "utils/ustdlib.h"

#ifndef true
#define true ((u8_t)1)
#endif

#ifndef false
#define false ((u8_t)0)
#endif

//------------------------------------------------------------------------------

struct udp_pcb *rx_pcb = NULL;
struct udp_pcb *tx_pcb = NULL;

s16	net_params[NET_PARAMETERS_MAX] = {0};

//------------------------------------------------------------------------------

void regs_set(u8_t num, s16 val) {
	TNetReg nr;
	if (num < NET_PARAMETERS_MAX) {
		net_params[num] = val;
		nr.number = num;
		nr.value = val;
		regs_server_port_send ((u8_t*)&nr, sizeof(TNetReg));
	}
}

//------------------------------------------------------------------------------

void regs_server_port_send(u8_t *data, u16_t len) {
	unsigned long n_ip = 0; 
	TNetReg *nr;
	IP4_ADDR_MAKE(n_ip,reg_ip.ip[0],reg_ip.ip[1],reg_ip.ip[2],255);
	if (tx_pcb != NULL){
			struct pbuf *p = pbuf_alloc(PBUF_TRANSPORT, len, PBUF_RAM);
			memcpy(p->payload, data, len);
			udp_send(tx_pcb, p);	
			//udp_send(tx_pcb, p);
			//nr = (TNetReg*)p->payload;
			//__sprintf_P(outtxt,"\n\r");
			//WordToStr(outtxt,(u16*)&nr->number,1);
			//__sprintf_P(outtxt," ");
			//WordToStr(outtxt,(u16*)&nr->value,1);
			//udp_send(tx_pcb, p);
			//udp_send(tx_pcb, p);
			pbuf_free(p);
		}
}

//------------------------------------------------------------------------------

void 
regs_server_port_receive(void *arg, struct udp_pcb *pcb, struct pbuf *p, struct 
ip_addr *addr, u16_t port)
{
	TNetReg *nr = (TNetReg*)p->payload;
	int i;
    if (p != NULL) {
		//__sprintf_P(outtxt,"\n\r UDP packet is received ");
		//LongToStr(outtxt,(u32*)addr,1);
        //pcb->remote_ip = *addr;
        //pcb->remote_port = port;
		//udp_sendto(pcb, p, addr, port);
		//udp_send(pcb, p);
		//memcpy(p->payload, data, len);
		
		//__sprintf_P(outtxt,"\n\r");
		//WordToStr(outtxt,(u16*)nr->number,1);
		//__sprintf_P(outtxt," ");
		//WordToStr(outtxt,(u16*)nr->value,1);
		if (nr->number < NET_PARAMETERS_MAX)
			net_params[nr->number] = nr->value;
    }
   pbuf_free(p);
}

//------------------------------------------------------------------------------

void
regs_server_port_init(void)
{
	unsigned long my_ip = 0;  
	IP4_ADDR_MAKE(my_ip,reg_ip.ip[0],reg_ip.ip[1],reg_ip.ip[2],reg_ip.ip[3]);
  	rx_pcb = udp_new();
	tx_pcb = udp_new();
  	udp_bind(rx_pcb, IP_ADDR_ANY, __UDP_NET_REGS_PORT);
	udp_bind(tx_pcb, (ip_addr_t *)&my_ip, __UDP_NET_REGS_PORT);
	udp_connect(tx_pcb, IP_ADDR_BROADCAST, __UDP_NET_REGS_PORT);
	udp_recv(rx_pcb, regs_server_port_receive, NULL);
}

//------------------------------------------------------------------------------

void
regs_server_port_close(void)
{
  	udp_disconnect(rx_pcb);
	udp_disconnect(tx_pcb);
	udp_remove(rx_pcb);
	udp_remove(tx_pcb);
}

//------------------------------------------------------------------------------