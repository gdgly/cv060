/*
 * Copyright (c) 2002 Florian Schulze.
 * All rights reserved.
 * 
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Neither the name of the authors nor the names of the contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE AUTHORS AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHORS OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 * ftpd.c - This file is part of the FTP daemon for lwIP
 *
 */

#include "lwip/debug.h"

#include "lwip/stats.h"

#include "ftpd.h"

#include "lwip/tcp.h"

#include <stdarg.h>
#include <malloc.h>
#include <string.h>
#include <ctype.h>

#include "vfs.h"
#ifdef _MSC_VER
#include "vfs_msvc.h"
#endif
#ifdef __DJGPP
#include "vfs_djgpp.h"
#endif
#include "vfs_null.h"

#define msg110 "110 MARK %s = %s."
/*
         110 Restart marker reply.
             In this case, the text is exact and not left to the
             particular implementation; it must read:
                  MARK yyyy = mmmm
             Where yyyy is User-process data stream marker, and mmmm
             server's equivalent marker (note the spaces between markers
             and "=").
*/
#define msg120 "120 Service ready in nnn minutes."
#define msg125 "125 Data connection already open; transfer starting."
#define msg150 "150 File status okay; about to open data connection."
#define msg200 "200 Command okay."
#define msg202 "202 Command not implemented, superfluous at this site."
#define msg211 "211 System status, or system help reply."
#define msg212 "212 Directory status."
#define msg213 "213 File status."
#define msg214 "214 %s."
/*
             214 Help message.
             On how to use the server or the meaning of a particular
             non-standard command.  This reply is useful only to the
             human user.
*/
#define msg214SYST "214 %s system type."
/*
         215 NAME system type.
             Where NAME is an official system name from the list in the
             Assigned Numbers document.
*/
#define msg220 "220 lwIP FTP Server ready."
/*
         220 Service ready for new user.
*/
#define msg221 "221 Goodbye."
/*
         221 Service closing control connection.
             Logged out if appropriate.
*/
#define msg225 "225 Data connection open; no transfer in progress."
#define msg226 "226 Closing data connection."
/*
             Requested file action successful (for example, file
             transfer or file abort).
*/
#define msg227 "227 Entering Passive Mode (%i,%i,%i,%i,%i,%i)."
/*
         227 Entering Passive Mode (h1,h2,h3,h4,p1,p2).
*/
#define msg230 "230 User logged in, proceed."
#define msg250 "250 Requested file action okay, completed."
#define msg257PWD "257 \"%s\" is current directory."
#define msg257 "257 \"%s\" created."
/*
         257 "PATHNAME" created.
*/
#define msg331 "331 User name okay, need password."
#define msg332 "332 Need account for login."
#define msg350 "350 Requested file action pending further information."
#define msg421 "421 Service not available, closing control connection."
/*
             This may be a reply to any command if the service knows it
             must shut down.
*/
#define msg425 "425 Can't open data connection."
#define msg426 "426 Connection closed; transfer aborted."
#define msg450 "450 Requested file action not taken."
/*
             File unavailable (e.g., file busy).
*/
#define msg451 "451 Requested action aborted: local error in processing."
#define msg452 "452 Requested action not taken."
/*
             Insufficient storage space in system.
*/          
#define msg500 "500 Syntax error, command unrecognized."
/*
             This may include errors such as command line too long.
*/
#define msg501 "501 Syntax error in parameters or arguments."
#define msg502 "502 Command not implemented."
#define msg503 "503 Bad sequence of commands."
#define msg504 "504 Command not implemented for that parameter."
#define msg530 "530 Not logged in."
#define msg532 "532 Need account for storing files."
#define msg550 "550 Requested action not taken."
/*
             File unavailable (e.g., file not found, no access).
*/
#define msg551 "551 Requested action aborted: page type unknown."
#define msg552 "552 Requested file action aborted."
/*
             Exceeded storage allocation (for current directory or
             dataset).
*/
#define msg553 "553 Requested action not taken."
/*
             File name not allowed.
*/

enum ftpd_state_e {
  FTPD_USER,
  FTPD_PASS,
  FTPD_IDLE,
  FTPD_NLST,
  FTPD_LIST,
  FTPD_LISTEND,
  FTPD_QUIT
};

struct ftpd_datastate {
  vfs_dir_t *vfs_dir;
  u8_t *curpos;
  char text[1024];
  u32_t left;
  struct tcp_pcb *msgpcb;
  struct ftpd_msgstate *msgfs;
};

struct ftpd_msgstate {
  enum ftpd_state_e state;
  char *curpos;
  u32_t left;
  char text[1024];
	vfs_t *vfs;
	struct ip_addr dataip;
  u16_t dataport;
  struct tcp_pcb *datapcb;
  struct ftpd_datastate *datafs;
  u8_t passive;
  u8_t dataok;
};

static void conn_msgerr(void *arg, err_t err)
{
  struct ftpd_msgstate *fsm;

  fsm = arg;
  mem_free(fsm);
}

static void close_msgconn(struct tcp_pcb *pcb, struct ftpd_msgstate *fsm)
{
  tcp_arg(pcb, NULL);
  tcp_sent(pcb, NULL);
  tcp_recv(pcb, NULL);
  mem_free(fsm);
  tcp_close(pcb);
}

static void send_msgdata(struct tcp_pcb *pcb, struct ftpd_msgstate *fsm)
{
  err_t err;
  u16_t len;

  if (fsm->left>0) {
    /* We cannot send more data than space available in the send
       buffer. */     
    if(tcp_sndbuf(pcb) < fsm->left) {
      len = tcp_sndbuf(pcb);
    } else {
      len = (u16_t)fsm->left;
    }

    err = tcp_write(pcb, fsm->curpos, len, 1);
  
    if(err == ERR_OK) {
      fsm->curpos += len;
      fsm->left -= len;
    }
  }
}

static void send_msg(struct tcp_pcb *pcb, struct ftpd_msgstate *fsm, char *msg, ...)
{
	va_list arg;

	va_start(arg,msg);
	vsprintf(fsm->text, msg, arg);
	va_end(arg);
  strcat(fsm->text,"\r\n");
  printf("response: %s",fsm->text);
  fsm->curpos=fsm->text;
  fsm->left=strlen(fsm->text);
  send_msgdata(pcb, fsm);
}

static void conn_dataerr(void *arg, err_t err)
{
  struct ftpd_datastate *fs;

  fs = arg;
  mem_free(fs);
}

static void close_dataconn(struct tcp_pcb *pcb, struct ftpd_datastate *fsd)
{
  tcp_arg(pcb, NULL);
  tcp_sent(pcb, NULL);
  tcp_recv(pcb, NULL);
  mem_free(fsd);
  tcp_close(pcb);
}

static void send_data(struct tcp_pcb *pcb, struct ftpd_datastate *fsd)
{
  err_t err;
  u16_t len;

  if (fsd->left>0) {

    /* We cannot send more data than space available in the send
       buffer. */     
    if(tcp_sndbuf(pcb) < fsd->left) {
      len = tcp_sndbuf(pcb);
    } else {
      len = (u16_t)fsd->left;
    }

    err = tcp_write(pcb, fsd->curpos, len, 1);
  
    if(err == ERR_OK) {
      fsd->curpos += len;
      fsd->left -= len;
    }
  }
}

static void send_next_directory(struct ftpd_datastate *fsd, struct tcp_pcb *pcb, int shortlist)
{
  vfs_dirent_t *vfs_dirent;

  if (vfs_dirent=vfs_readdir(fsd->vfs_dir))
	{
    if (shortlist)
    {
      fsd->curpos=fsd->text;
      fsd->left=sprintf(fsd->text,"%s\r\n",vfs_dirent->name);
      send_data(pcb, fsd);
    }
    else
    {
      vfs_stat_t st;

      vfs_stat(fsd->msgfs->vfs,vfs_dirent->name,&st);
      fsd->curpos=fsd->text;
		  fsd->left=sprintf(fsd->text,"-rw-rw-rw-   1 user     ftp  %11ld %s\r\n",
        st.st_size,vfs_dirent->name);
      if (VFS_ISDIR(st.st_mode))
        fsd->text[0]='d';
      send_data(pcb, fsd);
    }
  }
  else
  {
    struct ftpd_msgstate *fsm;
    struct tcp_pcb *msgpcb;

    fsm=fsd->msgfs;
    msgpcb=fsd->msgpcb;

    vfs_closedir(fsd->vfs_dir);
    close_dataconn(pcb, fsd);
    fsm->datapcb=NULL;
    fsm->datafs=NULL;
    //fsd->msgfs->state=FTPD_LISTEND;
    fsm->state=FTPD_IDLE;
    send_msg(msgpcb, fsm, msg226);
  }
}

static err_t ftpd_datasent(void *arg, struct tcp_pcb *pcb, u16_t len)
{
  struct ftpd_datastate *fsd;

  fsd = arg;

  if(fsd->left > 0)
  {
    send_data(pcb, fsd);
  }
  else
  {
    if (fsd->msgfs->state==FTPD_LIST)
      send_next_directory(fsd, pcb, 0);
    if (fsd->msgfs->state==FTPD_NLST)
      send_next_directory(fsd, pcb, 1);
  }

  return ERR_OK;
}

static err_t ftpd_datarecv(void *arg, struct tcp_pcb *pcb, struct pbuf *p, err_t err)
{
  struct ftpd_datastate *fs;

  fs = arg;

  if(err == ERR_OK && p != NULL) {

    /* Inform TCP that we have taken the data. */
    tcp_recved(pcb, p->tot_len);
    
	  pbuf_free(p);
  }

  return ERR_OK;
}

static err_t ftpd_dataconnected(void *arg, struct tcp_pcb *pcb, err_t err)
{
  struct ftpd_datastate *fsd;

  fsd = arg;

  /* Tell TCP that we wish to be informed of incoming data by a call
     to the http_recv() function. */
  tcp_recv(pcb, ftpd_datarecv);

	/* Tell TCP that we wish be to informed of data that has been
	   successfully sent by a call to the ftpd_sent() function. */
  tcp_sent(pcb, ftpd_datasent);

  tcp_err(pcb, conn_dataerr);

  return ERR_OK;
}

static err_t ftpd_dataaccept(void *arg, struct tcp_pcb *pcb, err_t err)
{
  struct ftpd_datastate *fsd;

  fsd = arg;

  fsd->msgfs->datapcb=pcb;
  fsd->msgfs->dataok = 1;

  /* Tell TCP that we wish to be informed of incoming data by a call
     to the http_recv() function. */
  tcp_recv(pcb, ftpd_datarecv);

	/* Tell TCP that we wish be to informed of data that has been
	   successfully sent by a call to the ftpd_sent() function. */
  tcp_sent(pcb, ftpd_datasent);

  tcp_err(pcb, conn_dataerr);

  return ERR_OK;
}

static void cmd_user(const char *arg, struct tcp_pcb *pcb, struct ftpd_msgstate *fsm)
{
  send_msg(pcb, fsm, msg331);
	fsm->state = FTPD_PASS;
  /*
  send_msg(pcb, fs, msgLoginFailed);
	fs->state = FTPD_QUIT;
  */
}

static void cmd_pass(const char *arg, struct tcp_pcb *pcb, struct ftpd_msgstate *fsm)
{
  send_msg(pcb, fsm, msg230);
	fsm->state = FTPD_IDLE;
  /*
  send_msg(pcb, fs, msgLoginFailed);
	fs->state = FTPD_QUIT;
  */
}

static void cmd_port(const char *arg, struct tcp_pcb *pcb, struct ftpd_msgstate *fsm)
{
	int nr;
	unsigned pHi, pLo;
	unsigned ip[4];

	nr = sscanf(arg,"%u,%u,%u,%u,%u,%u", &(ip[0]), &(ip[1]),
			&(ip[2]), &(ip[3]), &pHi, &pLo);
	if (nr != 6) {
		send_msg(pcb, fsm, msg501);
  } else {
  	IP4_ADDR(&fsm->dataip, (u8_t)ip[0], (u8_t)ip[1], (u8_t)ip[2], (u8_t)ip[3]);
	  fsm->dataport = ((u16_t) pHi << 8) | (u16_t)pLo;
	  send_msg(pcb, fsm, msg200);
  }
}

static void cmd_quit(const char *arg, struct tcp_pcb *pcb, struct ftpd_msgstate *fsm)
{
  send_msg(pcb, fsm, msg221);
	fsm->state = FTPD_QUIT;
}

static void cmd_cwd(const char *arg, struct tcp_pcb *pcb, struct ftpd_msgstate *fsm)
{
  if (!vfs_chdir(fsm->vfs,arg)) {
    send_msg(pcb, fsm, msg250);
  } else {
    send_msg(pcb, fsm, msg550);
  }
}

static void cmd_pwd(const char *arg, struct tcp_pcb *pcb, struct ftpd_msgstate *fsm)
{
  char *path;

  if (path=vfs_getcwd(fsm->vfs,NULL,0)) {
    send_msg(pcb, fsm, msg257PWD, path);
    free(path);
  }
}

static void cmd_list_common(const char *arg, struct tcp_pcb *pcb, struct ftpd_msgstate *fsm, int shortlist)
{
  vfs_dir_t *vfs_dir;
  char *cwd;

  cwd=vfs_getcwd(fsm->vfs,NULL,0);
  if ( (!cwd) )
  {
    send_msg(pcb, fsm, msg451);
    return;
  }
	vfs_dir=vfs_opendir(fsm->vfs,cwd);
  free(cwd);
  if (!vfs_dir)
  {
    send_msg(pcb, fsm, msg451);
    return;
  }
  if (!fsm->passive)
  {
    /* Allocate memory for the structure that holds the state of the
       connection. */
    fsm->datafs = mem_malloc(sizeof(struct ftpd_datastate));

    if(fsm->datafs == NULL)
    {
      send_msg(pcb, fsm, msg451);
      return;
    }
    fsm->datafs->msgfs=fsm;
    fsm->datafs->msgpcb=pcb;

    fsm->datapcb = tcp_new();
    tcp_bind(fsm->datapcb, &pcb->local_ip, 20);
    /* Tell TCP that this is the structure we wish to be passed for our
       callbacks. */
    tcp_arg(fsm->datapcb, fsm->datafs);
    tcp_connect(fsm->datapcb, &fsm->dataip, fsm->dataport, ftpd_dataconnected);
  }

  fsm->datafs->vfs_dir=vfs_dir;
  if (shortlist)
    fsm->state=FTPD_NLST;
  else
    fsm->state=FTPD_LIST;

  send_msg(pcb, fsm, msg150);
}

static void cmd_nlst(const char *arg, struct tcp_pcb *pcb, struct ftpd_msgstate *fsm)
{
  cmd_list_common(arg, pcb, fsm, 1);
}

static void cmd_list(const char *arg, struct tcp_pcb *pcb, struct ftpd_msgstate *fsm)
{
  cmd_list_common(arg, pcb, fsm, 0);
}

static void cmd_noop(const char *arg, struct tcp_pcb *pcb, struct ftpd_msgstate *fsm)
{
  send_msg(pcb, fsm, msg200);
}

static void cmd_syst(const char *arg, struct tcp_pcb *pcb, struct ftpd_msgstate *fsm)
{
  send_msg(pcb, fsm, msg214SYST, "UNIX");
}

static void cmd_pasv(const char *arg, struct tcp_pcb *pcb, struct ftpd_msgstate *fsm)
{
  struct tcp_pcb *temppcb;

  /* Allocate memory for the structure that holds the state of the
     connection. */
  fsm->datafs = mem_malloc(sizeof(struct ftpd_datastate));

  if(fsm->datafs == NULL)
  {
    send_msg(pcb, fsm, msg451);
    return;
  }
  
  fsm->datapcb = tcp_new();
  if (!fsm->datapcb)
  {
    mem_free(fsm->datafs);
    send_msg(pcb, fsm, msg451);
    return;
  }
  
  fsm->dataport = 4096;
  if (tcp_bind(fsm->datapcb, &pcb->local_ip, fsm->dataport)!=ERR_OK)
  {
    close_dataconn(fsm->datapcb,fsm->datafs);
    fsm->datapcb=NULL;
    fsm->datafs=NULL;
    return;
  }
  
  temppcb = tcp_listen(fsm->datapcb);
  if (!temppcb)
  {
    close_dataconn(fsm->datapcb,fsm->datafs);
    fsm->datapcb=NULL;
    fsm->datafs=NULL;
    return;
  }
  fsm->datapcb=temppcb;

  fsm->passive = 1;
  fsm->dataok = 0;
  fsm->datafs->msgfs=fsm;
  fsm->datafs->msgpcb=pcb;

  /* Tell TCP that this is the structure we wish to be passed for our
     callbacks. */
  tcp_arg(fsm->datapcb, fsm->datafs);

  tcp_accept(fsm->datapcb, ftpd_dataaccept);
  send_msg(pcb, fsm, msg227,
           ip4_addr1(&pcb->local_ip),
           ip4_addr2(&pcb->local_ip),
           ip4_addr3(&pcb->local_ip),
           ip4_addr4(&pcb->local_ip),
           (fsm->dataport >> 8) & 0xff,
           (fsm->dataport) & 0xff);
}

struct ftpd_command {
  char *cmd;
  void (*func)(const char *arg, struct tcp_pcb *pcb, struct ftpd_msgstate *fsm);
};

static struct ftpd_command ftpd_commands[] = {
  "USER", cmd_user,
  "PASS", cmd_pass,
  "PORT", cmd_port,
  "QUIT", cmd_quit,
  "CWD", cmd_cwd,
  "PWD", cmd_pwd,
  "XPWD", cmd_pwd,
  "NLST", cmd_list,
  "LIST", cmd_list,
  "NOOP", cmd_noop,
  "SYST", cmd_syst,
  "PASV", cmd_pasv,
  NULL
};

static err_t ftpd_msgsent(void *arg, struct tcp_pcb *pcb, u16_t len)
{
  struct ftpd_msgstate *fsm;

  fsm = arg;

  if(fsm->left > 0)
    send_msgdata(pcb, fsm);

  if ( (fsm->left==0) && (fsm->state==FTPD_QUIT) )
    close_msgconn(pcb, fsm);

/*
  if ( (fsm->datapcb) && (fsm->datafs) && (fsm->state!=FTPD_LIST) )
  {
    close_dataconn(fsm->datapcb, fsm->datafs);
    fsm->datapcb=NULL;
    fsm->datafs=NULL;
  }
*/

  return ERR_OK;
}

static err_t ftpd_msgrecv(void *arg, struct tcp_pcb *pcb, struct pbuf *p, err_t err)
{
  char *text;
  struct ftpd_msgstate *fsm;

  fsm = arg;

  if(err == ERR_OK && p != NULL) {

    /* Inform TCP that we have taken the data. */
    tcp_recved(pcb, p->tot_len);
    
	  text=malloc(p->tot_len+1);
	  if (text) {
      char cmd[5];
		  struct pbuf *q;
      char *pt=text;
      struct ftpd_command *ftpd_cmd;

		  for(q = p; q != NULL; q = q->next) {
        bcopy(q->payload,pt,q->len);
        pt+=q->len;
      }
      *pt='\0';

      pt=&text[strlen(text)-1];
      while ( ((*pt=='\r') || (*pt=='\n')) && pt>=text)
        *pt--='\0';

      printf("query: %s\n",text);

      strncpy(cmd,text,4);
      for (pt=cmd; isalpha(*pt) && pt<&cmd[4]; pt++)
        *pt=toupper(*pt);
      *pt='\0';

      for(ftpd_cmd=ftpd_commands; ftpd_cmd->cmd!=NULL; ftpd_cmd++)
      {
        if (!strcmp(ftpd_cmd->cmd,cmd))
          break;
      }

      if (strlen(text)<(strlen(cmd)+1))
        pt="";
      else
        pt=&text[strlen(cmd)+1];

      if (ftpd_cmd->func)
        ftpd_cmd->func(pt,pcb,fsm);
      else
        send_msg(pcb, fsm, msg502);

      free(text);
	  }
	  pbuf_free(p);
  }

  return ERR_OK;
}

static err_t ftpd_msgpoll(void *arg, struct tcp_pcb *pcb)
{
  struct ftpd_msgstate *fsm;

  fsm = arg;

  if (fsm->passive == fsm->dataok)
  {
    if (fsm->state==FTPD_LIST)
      send_next_directory(fsm->datafs, fsm->datapcb, 0);
    if (fsm->state==FTPD_NLST)
      send_next_directory(fsm->datafs, fsm->datapcb, 1);
  }

/*
  if (fsm->state==FTPD_LISTEND)
  {
    send_msg(pcb, fsm, msg226);
    fsm->state=FTPD_IDLE;
  }
*/

  return ERR_OK;
}

static err_t ftpd_msgaccept(void *arg, struct tcp_pcb *pcb, err_t err)
{
  struct ftpd_msgstate *fsm;

  /* Allocate memory for the structure that holds the state of the
     connection. */
  fsm = mem_malloc(sizeof(struct ftpd_msgstate));

  if(fsm == NULL)
  {
    printf("ftpd_accept: Out of memory\n");
    return ERR_MEM;
  }
  
  /* Initialize the structure. */
  fsm->curpos = NULL;
  fsm->left = 0;
	fsm->state = FTPD_IDLE;
	IP4_ADDR(&fsm->dataip, 0,0,0,0);
  fsm->dataport = 2000;
  fsm->datapcb = NULL;
  fsm->passive = 0;
	fsm->vfs=vfs_openfs();
	if (!fsm->vfs)
		return ERR_CLSD;

  /* Tell TCP that this is the structure we wish to be passed for our
     callbacks. */
  tcp_arg(pcb, fsm);

  /* Tell TCP that we wish to be informed of incoming data by a call
     to the http_recv() function. */
  tcp_recv(pcb, ftpd_msgrecv);

	/* Tell TCP that we wish be to informed of data that has been
	   successfully sent by a call to the ftpd_sent() function. */
  tcp_sent(pcb, ftpd_msgsent);

  tcp_err(pcb, conn_msgerr);

  tcp_poll(pcb, ftpd_msgpoll, 1);

  send_msg(pcb, fsm, msg220);

  return ERR_OK;
}

void ftpd_init(void)
{
  struct tcp_pcb *pcb;

	vfs_load_plugin(vfs_null_fs);
#ifdef _MSC_VER
	vfs_load_plugin(vfs_msvc_fs);
#endif
#ifdef __DJGPP
	vfs_load_plugin(vfs_djgpp_fs);
#endif

  pcb = tcp_new();
  tcp_bind(pcb, IP_ADDR_ANY, 21);
  pcb = tcp_listen(pcb);
  tcp_accept(pcb, ftpd_msgaccept);
}
