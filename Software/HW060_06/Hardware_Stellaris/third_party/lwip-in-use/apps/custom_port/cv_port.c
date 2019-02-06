/*
 * Copyright (c) 2001-2003 Swedish Institute of Computer Science.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 * 3. The name of the author may not be used to endorse or promote products
 *    derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT
 * SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT
 * OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
 * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY
 * OF SUCH DAMAGE.
 *
 * This file is part of the lwIP TCP/IP stack.
 *
 * Author: Adam Dunkels <adam@sics.se>
 *
 */

/* This file is modified from the original version (httpd.c) as shipped with
 * lwIP version 1.3.1. Changes have been made to allow support for a
 * rudimentary server-side-include facility which will replace tags of the form
 * <!--#tag--> in any file whose extension is .shtml, .shtm or .ssi with
 * strings provided by an include handler whose pointer is provided to the
 * module via function http_set_ssi_handler(). Additionally, a simple common
 * gateway interface (CGI) handling mechanism has been added to allow clients
 * to hook functions to particular request URIs.
 *
 * To enable SSI support, define label INCLUDE_HTTPD_SSI in lwipopts.h.
 * To enable CGI support, define label INCLUDE_HTTPD_CGI in lwipopts.h.
 *
 * By default, the server assumes that HTTP headers are already present in
 * each file stored in the file system.  By defining DYNAMIC_HTTP_HEADERS in
 * lwipopts.h, this behavior can be changed such that the server inserts the
 * headers automatically based on the extension of the file being served.  If
 * this mode is used, be careful to ensure that the file system image used
 * does not already contain the header information.
 *
 * File system images without headers can be created using the makefsfile
 * tool with the -h command line option.
 */

/*
 * Notes about valid SSI tags
 * --------------------------
 *
 * The following assumptions are made about tags used in SSI markers:
 *
 * 1. No tag may contain '-' or whitespace characters within the tag name.
 * 2. Whitespace is allowed between the tag leadin "<!--#" and the start of
 *    the tag name and between the tag name and the leadout string "-->".
 * 3. The maximum tag name length is MAX_TAG_NAME_LEN, currently 8 characters.
 *
 * Notes on CGI usage
 * ------------------
 *
 * The simple CGI support offered here works with GET method requests only
 * and can handle up to 16 parameters encoded into the URI. The handler
 * function may not write directly to the HTTP output but must return a
 * filename that the HTTP server will send to the browser as a response to
 * the incoming CGI request.
 *
 */
#include "lwip/debug.h"
#include "lwip/stats.h"
#include "cv_port.h"
#include "lwip/tcp.h"
#include "fs.h"

#include <string.h>

#ifndef HTTPD_DEBUG
#define HTTPD_DEBUG         LWIP_DBG_OFF
#endif

#ifndef true
#define true ((u8_t)1)
#endif

#ifndef false
#define false ((u8_t)0)
#endif

typedef struct
{
    const char *name;
    u8_t shtml;
} default_filename;

extern const default_filename g_psDefaultFilenames[];

#define NUM_DEFAULT_FILENAMES (sizeof(g_psDefaultFilenames) /                 \
                               sizeof(default_filename))

#ifdef DYNAMIC_HTTP_HEADERS
/* The number of individual strings that comprise the headers sent before each
 * requested file.
 */
#define NUM_FILE_HDR_STRINGS 3
#endif

#ifdef INCLUDE_HTTPD_SSI

/* Include the (TI-specific) micro-standard-library.  This is needed for the
 * function usnprintf which is a cut down version of the C standard snprintf.
 * Some of the toolchains we support don't support snprintf without pulling in
 * a large amount of extra (and usually extraneous) code.  If your C runtime
 * does support snprintf, this header can be removed and the call to usnprintf
 * replaced.
 */
#include "utils/ustdlib.h"

extern const char *g_pcSSIExtensions;

#define NUM_SHTML_EXTENSIONS (sizeof(g_pcSSIExtensions) / sizeof(const char *))

enum tag_check_state {
    TAG_NONE,       /* Not processing an SSI tag */
    TAG_LEADIN,     /* Tag lead in "<!--#" being processed */
    TAG_FOUND,      /* Tag name being read, looking for lead-out start */
    TAG_LEADOUT,    /* Tag lead out "-->" being processed */
    TAG_SENDING     /* Sending tag replacement string */
};
#endif /* INCLUDE_HTTPD_SSI */

struct http_state {
  struct fs_file *handle;
  char *file;       /* Pointer to first unsent byte in buf. */
  char *buf;        /* File read buffer. */
#ifdef INCLUDE_HTTPD_SSI
  char *parsed;     /* Pointer to the first unparsed byte in buf. */
  char *tag_end;    /* Pointer to char after the closing '>' of the tag. */
  u32_t parse_left; /* Number of unparsed bytes in buf. */
#endif
  u32_t left;       /* Number of unsent bytes in buf. */
  int buf_len;      /* Size of file read buffer, buf. */
  u8_t retries;
#ifdef INCLUDE_HTTPD_SSI
  u8_t tag_check;   /* true if we are processing a .shtml file else false */
  u8_t tag_index;   /* Counter used by tag parsing state machine */
  u8_t tag_insert_len; /* Length of insert in string tag_insert */
  u8_t tag_name_len; /* Length of the tag name in string tag_name */
  char tag_name[MAX_TAG_NAME_LEN + 1]; /* Last tag name extracted */
  char tag_insert[MAX_TAG_INSERT_LEN + 1]; /* Insert string for tag_name */
  enum tag_check_state tag_state; /* State of the tag processor */
#endif
#ifdef INCLUDE_HTTPD_CGI
  char *params[MAX_CGI_PARAMETERS]; /* Params extracted from the request URI */
  char *param_vals[MAX_CGI_PARAMETERS]; /* Values for each extracted param */
#endif
#ifdef DYNAMIC_HTTP_HEADERS
  const char *hdrs[NUM_FILE_HDR_STRINGS]; /* HTTP headers to be sent. */
  u16_t hdr_pos;     /* The position of the first unsent header byte in the
                        current string */
  u16_t hdr_index;   /* The index of the hdr string currently being sent. */
#endif
};

#ifdef INCLUDE_HTTPD_SSI
/* SSI insert handler function pointer. */
//tSSIHandler g_pfnSSIHandler = NULL;
//int g_iNumTags = 0;
//const char **g_ppcTags = NULL;

#define LEN_TAG_LEAD_IN 5
extern const char * const g_pcTagLeadIn;

#define LEN_TAG_LEAD_OUT 3
extern const char * const g_pcTagLeadOut;
#endif /* INCLUDE_HTTPD_SSI */

#ifdef INCLUDE_HTTPD_CGI
/* CGI handler information */
//const tCGI *g_pCGIs = NULL;
//int g_iNumCGIs = 0;
#endif /* INCLUDE_HTTPD_CGI */

#ifdef DYNAMIC_HTTP_HEADERS
//*****************************************************************************
//
// HTTP header strings for various filename extensions.
//
//*****************************************************************************


#define HTTP_HDR_HTML           0
#define HTTP_HDR_SSI            1
#define HTTP_HDR_GIF            2
#define HTTP_HDR_PNG            3
#define HTTP_HDR_JPG            4
#define HTTP_HDR_BMP            5
#define HTTP_HDR_ICO            6
#define HTTP_HDR_APP            7
#define HTTP_HDR_JS             8
#define HTTP_HDR_RA             9
#define HTTP_HDR_CSS            10
#define HTTP_HDR_SWF            11
#define HTTP_HDR_XML            12
#define HTTP_HDR_DEFAULT_TYPE   13
#define HTTP_HDR_OK             14
#define HTTP_HDR_NOT_FOUND      15
#define HTTP_HDR_SERVER         16
#define DEFAULT_404_HTML        17


#define NUM_HTTP_HEADERS (sizeof(g_psHTTPHeaders) / sizeof(tHTTPHeader))

#endif

/*-----------------------------------------------------------------------------------*/
static void
cv_port_conn_err(void *arg, err_t err)
{
  struct http_state *hs;

  LWIP_UNUSED_ARG(err);

  if(arg)
  {
      hs = arg;
      if(hs->handle) {
        fs_close(hs->handle);
        hs->handle = NULL;
      }
      if(hs->buf)
      {
          mem_free(hs->buf);
      }
      mem_free(hs);
  }
}
/*-----------------------------------------------------------------------------------*/
static void
cv_port_close_conn(struct tcp_pcb *pcb, struct http_state *hs)
{
  err_t err;
  LWIP_DEBUGF(HTTPD_DEBUG, ("Closing connection 0x%08x\n", pcb));

  tcp_arg(pcb, NULL);
  tcp_sent(pcb, NULL);
  tcp_recv(pcb, NULL);
  if(hs) {
    if(hs->handle) {
      fs_close(hs->handle);
      hs->handle = NULL;
    }
    if(hs->buf)
    {
      mem_free(hs->buf);
    }
    mem_free(hs);
  }
  err = tcp_close(pcb);
  if(err != ERR_OK)
  {
      LWIP_DEBUGF(HTTPD_DEBUG, ("Error %d closing 0x%08x\n", err, pcb));
  }
}
/*-----------------------------------------------------------------------------------*/
static void
cv_port_send_data(struct tcp_pcb *pcb, struct http_state *hs)
{
  err_t err;
  u16_t len;
  u8_t data_to_send = false;
  u16_t hdrlen, sendlen;
  u8_t buff[10]={'A','B','B','D','E','F','G','H','A','A'};

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
cv_port_poll(void *arg, struct tcp_pcb *pcb)
{
  struct http_state *hs;

  hs = arg;

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
      cv_port_send_data(pcb, hs);
    }
    }
  */
  return ERR_OK;
}
/*-----------------------------------------------------------------------------------*/
static err_t
cv_port_sent(void *arg, struct tcp_pcb *pcb, u16_t len)
{
  struct http_state *hs;

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

  cv_port_send_data(pcb, hs);

  // Reenable notifications.
  tcp_sent(pcb, cv_port_sent);
*/
  return ERR_OK;
}

unsigned char sock_RXHandler(u8_t *data,u16_t len);
void sock_TXHandler(u8_t *data,u16_t *len);
/*-----------------------------------------------------------------------------------*/
static err_t
cv_port_recv(void *arg, struct tcp_pcb *pcb, struct pbuf *p, err_t err)
{
  int i;
  int loop;
  char *data;
  char *uri;
  struct fs_file *file;
  struct http_state *hs;
  char buff[128];
  u16_t len,*len_ptr;
  LWIP_DEBUGF(HTTPD_DEBUG, ("http_recv 0x%08x\n", pcb));

  hs = arg;

  if ((err == ERR_OK) && (p != NULL) && hs) {

    /* Inform TCP that we have taken the data. */
    tcp_recved(pcb, p->tot_len);

    if (hs->handle == NULL) {
      data = p->payload;
//      LWIP_DEBUGF(HTTPD_DEBUG, ("Request:\n%s\n", data));
//      if (strncmp(data, "GET ", 4) == 0)
      {
/*        for(i = 4; i < (p->len - 5); i++) {
          if ((data[i] == ' ') && (data[i + 1] == 'H') &&
              (data[i + 2] == 'T') && (data[i + 3] == 'T') &&
              (data[i + 4] == 'P')) {
            data[i] = 0;
            break;
          }
        }
*/
        // Tell TCP that we wish be to informed of data that has been
        // successfully sent by a call to the http_sent() function.
        tcp_sent(pcb, cv_port_sent);

	  if(sock_RXHandler((u8_t*)data,p->len))
	  {
		//cv_port_send_data(pcb, hs);
			sock_TXHandler(buff,&len);
			tcp_write(pcb, buff, len, 1);
	  }
	  else
	  {
			tcp_write(pcb, data, p->tot_len, 1);		
	  }

		
		tcp_output(pcb);
        pbuf_free(p);
//        cv_port_close_conn(pcb, hs);
      }
    } else {
      pbuf_free(p);
    }
  }

  if ((err == ERR_OK) && (p == NULL)) {
    cv_port_close_conn(pcb, hs);
  }
  return ERR_OK;
}
/*-----------------------------------------------------------------------------------*/
static err_t
cv_port_accept(void *arg, struct tcp_pcb *pcb, err_t err)
{
  struct http_state *hs;

  LWIP_UNUSED_ARG(arg);
  LWIP_UNUSED_ARG(err);

  hs = (struct http_state *)mem_malloc(sizeof(struct http_state));

  if (hs == NULL) {
    LWIP_DEBUGF(HTTPD_DEBUG, ("http_accept: Out of memory\n"));
    return ERR_MEM;
  }

  hs->handle = NULL;
  hs->file = NULL;
  hs->buf = NULL;
  hs->buf_len = 0;
  hs->left = 0;
  hs->retries = 0;
  hs->hdr_index = NUM_FILE_HDR_STRINGS;

  // Tell TCP that this is the structure we wish to be passed for our callbacks.
  tcp_arg(pcb, hs);

  // Tell TCP that we wish to be informed of incoming data by a call  to the http_recv() function.
  tcp_recv(pcb, cv_port_recv);

  tcp_err(pcb, cv_port_conn_err);

  tcp_poll(pcb, cv_port_poll, 4);
  return ERR_OK;
}
/*-----------------------------------------------------------------------------------*/
void
cv_port_init(void)
{
  struct tcp_pcb *pcb;

  pcb = tcp_new();
  tcp_bind(pcb, IP_ADDR_ANY, 2020);
  pcb = tcp_listen(pcb);
  tcp_accept(pcb, cv_port_accept);
}

/*-----------------------------------------------------------------------------------*/
