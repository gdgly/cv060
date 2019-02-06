//------------------------------------------------------------------------------
#ifndef __STR
#define __STR
//------------------------------------------------------------------------------
#include "Misc\types.h"
//------------------------------------------------------------------------------
#define MAX_STR_BUFF 1024
eu8 con_txt[MAX_STR_BUFF];
eu8 ip_txt[MAX_STR_BUFF];
eu8 *outtxt;
eu8	con_interface;
eu8 word[40],*wordptr;
eu8 intxt[40],*inptr;
eu8 *outptr;
eu8 oldtxt[40];

eu32 ltmp;
eu16 wtmp;
eu8  ctmp;
ed64   dtmp;
//------------------------------------------------------------------------------
#define __sprintf_P __sprintf

void __sprintf(u8 *out,u8 *in);
s32 __strtol(u8* txt,u8**endtxt,u8 digits);
void WordToStr(u8 *out,u16 *val,u8 format);
void ByteToStr2(u8 **out,u8 *val,u8 format);
void ByteToStr(u8 *out,u8 *val,u8 format);
void ByteToStrFillZero(u8 *out,u8 *val,u8 format,u8 digits,u8 fill);
void LongToStr(u8 *out,u32 *val,u8 format);
//void strlwr(char *str);
u8 strcmp2(u8* str1,u8* str2);
u8 strcmp3(u8* str1,u8* str2);
void strcat2(u8* str1,u8* str2);
void strcpy2(u8* str1,u8* str2);
void memset2(u8 *s,u8 c, u8 len);
void memcpy2(u8 *s,u8 *c, u8 len);
u16 strlen2(u8* str1);
void _stradd(u8* str1,u8* str2);
void __strlwr(char *str);
//void WordToStrFillZero(u8 *out,u16 *val,u8 format,u8 digits,u8 fill,u8 sign);
void ShowTemperature(u8 *out,s16 *val);
void ShowTemperatureShort(u8 *out,s16 *val);
void ShowTemperatureShort2(u8 *out,s16 *val);
void ShowPowerShort(u8 *out,s16 *val);
void WordToStrSigned(u8 *out,s16 *val);
void IntToStrFillZero(u8 *out,void *val,u8 format,u8 digits,u8 fill,u8 sign);
//------------------------------------------------------------------------------
#endif
