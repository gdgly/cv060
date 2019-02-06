/*
 *
 */
#include "main.h"

#include "lwip/debug.h"
#include "lwip/stats.h"
#include "modbus_port.h"
#include "lwip/tcp.h"
#include "fs.h"

#include <string.h>

#ifndef true
#define true ((u8_t)1)
#endif

#ifndef false
#define false ((u8_t)0)
#endif


#include "utils/ustdlib.h"

/*-----------------------------------------------------------------------------------*/
static void
mb_port_conn_err(void *arg, err_t err)
{
  LWIP_UNUSED_ARG(err);
}
/*-----------------------------------------------------------------------------------*/
static void
mb_port_close_conn(struct tcp_pcb *pcb)
{
  err_t err;
  LWIP_DEBUGF(HTTPD_DEBUG, ("Closing connection 0x%08x\n", pcb));
 // IntMasterEnable();
  tcp_arg(pcb, NULL);
  tcp_sent(pcb, NULL);
  tcp_recv(pcb, NULL);
  err = tcp_close(pcb);
  if(err != ERR_OK)
  {
      LWIP_DEBUGF(HTTPD_DEBUG, ("Error %d closing 0x%08x\n", err, pcb));
  }
}
/*-----------------------------------------------------------------------------------*/
static void
mb_port_send_data(struct tcp_pcb *pcb, struct http_state *hs)
{
  err_t err;
  u16_t len;
  u8_t data_to_send = false;
  u16_t hdrlen, sendlen;
  u8_t buff[10]={'A','B','B','D','E','F','G','H','A','A'};

 // IntMasterEnable();
  // If we were passed a NULL state structure pointer, ignore the call.
  if(!hs) {
      return;
  }

  err = ERR_OK;
  // How much data can we send?
  len = tcp_sndbuf(pcb);
  sendlen = len;
  err = tcp_write(pcb, buff, 5, 1);
  data_to_send=true;

  // If we wrote anything to be sent, go ahead and send it now.
  if(data_to_send) {
    LWIP_DEBUGF(HTTPD_DEBUG, ("tcp_output\n"));
    tcp_output(pcb);
  }

  LWIP_DEBUGF(HTTPD_DEBUG, ("send_data end.\n"));
}

/*-----------------------------------------------------------------------------------*/
static err_t
mb_port_poll(void *arg, struct tcp_pcb *pcb)
{
//  struct http_state *hs;

//  hs = arg;

  LWIP_DEBUGF(HTTPD_DEBUG, ("http_poll 0x%08x\n", pcb));
/*
  //  printf("Polll\n");
  if ((hs == NULL) && (pcb->state == ESTABLISHED)) {
    //    printf("Null, close\n");
    tcp_abort(pcb);
    return ERR_ABRT;
  } else {
    ++hs->retries;
    if (hs->retries == 4) {
      tcp_abort(pcb);
      return ERR_ABRT;
    }

    // If this connection has a file open, try to send some more data. If
    // it has not yet received a GET request, don't do this since it will
    // cause the connection to close immediately.
    if(hs && (hs->handle)) {
      mb_port_send_data(pcb, hs);
    }
    }
  */
  return ERR_OK;
}
/*-----------------------------------------------------------------------------------*/
static err_t
mb_port_sent(void *arg, struct tcp_pcb *pcb, u16_t len)
{
//  struct http_state *hs;

//	IntMasterEnable();
  LWIP_DEBUGF(HTTPD_DEBUG, ("http_sent 0x%08x\n", pcb));

  LWIP_UNUSED_ARG(len);
/*
  if(!arg) {
    return ERR_OK;
  }

  hs = arg;

  hs->retries = 0;

  // Temporarily disable send notifications
  tcp_sent(pcb, NULL);

  mb_port_send_data(pcb, hs);

  // Reenable notifications.
  tcp_sent(pcb, mb_port_sent);
*/
  return ERR_OK;
}

//unsigned char sock_RXHandler(u8_t *data,u16_t len);
void MODBus_Init( void );
unsigned char MODBus_RXHandler(u8_t *data,u16_t len);
void MODBus_TXHandler(u8_t *data,u16_t *len);
/*-----------------------------------------------------------------------------------*/
static err_t
mb_port_recv(void *arg, struct tcp_pcb *pcb, struct pbuf *p, err_t err)
{
//  int i;
//  int loop;
  char *data;
//  char *uri;
  char buff[128];
  u16_t len,*len_ptr;

//  	IntMasterEnable();
	if ((err == ERR_OK) && (p != NULL))
	{

		/* Inform TCP that we have taken the data. */
		tcp_recved(pcb, p->tot_len);
	
		data = p->payload;
		// Tell TCP that we wish be to informed of data that has been
		// successfully sent by a call to the http_sent() function.
		tcp_sent(pcb, mb_port_sent);
	
		len=p->len;
		memcpy(buff,data,len);
		if(MODBus_RXHandler((u8_t*)data,p->len))
		{
			MODBus_TXHandler(buff,&len);
			if(len)	tcp_write(pcb, buff, len, 1);
		}
		else
		{
			tcp_write(pcb, data, p->tot_len, 1);		
		}
		tcp_output(pcb);
		pbuf_free(p);
#ifdef __MODBUS_CLOSE_PORT
	    mb_port_close_conn(pcb);
#endif
	}

//	if ((err == ERR_OK) && (p == NULL))
//	{
//		mb_port_close_conn(pcb, NULL);
//	}
	return ERR_OK;
}
/*-----------------------------------------------------------------------------------*/
static err_t
mb_port_accept(void *arg, struct tcp_pcb *pcb, err_t err)
{
//	IntMasterEnable();
  LWIP_UNUSED_ARG(arg);
  LWIP_UNUSED_ARG(err);

  tcp_arg(pcb, NULL);
  // Tell TCP that we wish to be informed of incoming data by a call  to the mb_port_recv() function.
  tcp_recv(pcb, mb_port_recv);
  tcp_err(pcb, mb_port_conn_err);

  tcp_poll(pcb, mb_port_poll, 4);
  return ERR_OK;
}
/*-----------------------------------------------------------------------------------*/
void
mb_port_init(void)
{
  	struct tcp_pcb *pcb;
	
	MODBus_Init();
  	pcb = tcp_new();
  	tcp_bind(pcb, IP_ADDR_ANY, 502);
  	pcb = tcp_listen(pcb);
 	tcp_accept(pcb, mb_port_accept);
}
/*-----------------------------------------------------------------------------------*/
