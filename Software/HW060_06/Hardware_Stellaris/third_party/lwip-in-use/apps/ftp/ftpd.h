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
 * ftpd.h - This file is part of the FTP daemon for lwIP
 *
 */

#ifndef __FTPD_H__
#define __FTPD_H__

void ftpd_init(void);


struct  FILINFO_DATE_BITS{     	// bits  description
    unsigned short  Year:7;				// 7 Year sinse 1980
    unsigned short  Month:4;				// 3  Month
    unsigned short  Date:5; 				// 5  Date
};

typedef __packed union 
{
   unsigned short	all;
   struct FILINFO_DATE_BITS bit;
}FILINFO_DATE;

struct  FILINFO_TIME_BITS{     	// bits  description
    unsigned short  Hour:5;				// 4 Hour
    unsigned short  Minute:6;				// 7  Minute
    unsigned short  Second:5; 			// 5  Second
};

typedef __packed union 
{
   unsigned short	all;
   struct FILINFO_TIME_BITS bit;
}FILINFO_TIME;

#endif				/* __FTPD_H__ */
