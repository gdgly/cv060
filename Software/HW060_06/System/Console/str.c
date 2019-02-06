#include "main.h"
//-----------------------------------------------------------------------------------
u8 con_txt[MAX_STR_BUFF];
u8 ip_txt[MAX_STR_BUFF];
u8 *outtxt;
u8 con_interface = 0;			// 0-Usual Console; 1-IP Console
u8 word[40],*wordptr;
u8 intxt[40],*inptr,oldtxt[40];
u8 *outptr;

u32 ltmp;
u16	wtmp;
u8	ctmp;
d64 dtmp;
//-----------------------------------------------------------------------------------
u8* shift_txt(u8* txt)
{
	if(outtxt==ip_txt)
		while((*txt!=0)&&(txt!=&ip_txt[MAX_STR_BUFF-1]))txt++;
	if(outtxt==con_txt)
		while((*txt!=0)&&(txt!=&con_txt[MAX_STR_BUFF-1]))txt++;
	ip_txt[MAX_STR_BUFF-1]=0;
	con_txt[MAX_STR_BUFF-1]=0;
	return txt;
}
//-----------------------------------------------------------------------------------
u8* put_txt(u8 *txt,u8 ch)
{
	if(outtxt==ip_txt)
		if((txt!=&ip_txt[MAX_STR_BUFF-1]))*txt=ch;
	if(outtxt==con_txt)
		if((txt!=&con_txt[MAX_STR_BUFF-1]))*txt=ch;
	ip_txt[MAX_STR_BUFF-1]=0;
	con_txt[MAX_STR_BUFF-1]=0;
	return txt;
}
//-----------------------------------------------------------------------------------
void put_str(u8 *txt,u8 *str)
{
	if(outtxt==ip_txt)
	{
		txt=shift_txt(txt);
		while((*str!=0)&&(txt!=&ip_txt[MAX_STR_BUFF-1]))
		{
			txt=put_txt(txt,*str);
			txt++;
			str++;
			*txt=0;
		}
	}
	if(outtxt==con_txt)
		while((*str!=0)&&(txt!=&con_txt[MAX_STR_BUFF-1]))
		{
			*txt=*str;
			txt++;
			str++;
			*txt=0;
		}
	ip_txt[MAX_STR_BUFF-1]=0;
	con_txt[MAX_STR_BUFF-1]=0;
}
//-----------------------------------------------------------------------------------
void __sprintf(u8 *out,u8 *in)
{
	u8 st=0;
	wait_con_free();
	out=shift_txt(out);
	while(*in!=0)
	{
		// new line or etc
		if(st==1)
		{
			switch(*in)
			{
				case 'n':
					//*out=0x0D;
					out=put_txt(out,0x0D);
					out++;
					in++;
				break;
				case 'r':
					//*out=0x0A;
					out=put_txt(out,0x0A);
					out++;	
					in++;
				break;
			}
			st=0;
		}
		switch(*in)
		{
			case 92:// '\' is detected
				in++;
				st=1;
			break;
			default:
				//*out=*in;
				out=put_txt(out,*in);
				out++;
				in++;
			break;
		}
	}
	//*out=0;
	out=put_txt(out,0);
	//outptr=&outtxt[0];
	wait_con_free();
}
//-----------------------------------------------------------------------------------
s32 __strtol(u8* txt,u8**endtxt,u8 digits)
{
	u8 d=0; // 0 - decimal 1-hex
	u8 s=0; // 0 -idle 1-stat 2-end
	u8 sign=0; // 0+ 1-
	u8 *p;
	s32 v=0;

	p=txt;
	if(*p=='-')
	{
		sign=1;
		p++;
	}
	while(*p!=0)
	{
		if(d==0)
		{
			if((s==0)&&((*p=='x')||(*p=='X')))
			{
				d=1;
				p++;
			}
			else
			{
				if((*p<'0')||(*p>'9'))return 0;
				v*=10;
				v+=*p-'0';
				if(v!=0)s=1;
				p++;
			}
		}
		if(d==1)
		{
			v*=16;
			s=2;
			if((*p>='0')&&(*p<='9'))
			{
				s=1;
				v+=*p-'0';
			}
			if((*p>='a')&&(*p<='f'))
			{
				s=1;
				v+=*p-'a'+10;
			}
			if((*p>='A')&&(*p<='F'))
			{
				s=1;
				v+=*p-'A'+10;
			}
			if(s==2)return 0;
				p++;
		}
	}
	if(sign==1)v=-v;
	return v;
}
//-----------------------------------------------------------------------------------
void WordToStr(u8 *out,u16 *val,u8 format)
{
	u8 i,p[5],pp,c,s;
	u32 v,d,t;
	u8 *r;
	while(*out!=0)out++;
	//----------- DEC ------------
	if(format==0)
	{
		v=*val;
		pp=4;
		for(i=0;i<5;i++)
		{
			t=v;
			v=v/10;
			d=v*10;
			c=t-d;
			p[pp]=c;
			pp--;
		}
		s=0;
		for(i=0;i<5;i++)
		{
			if(p[i]!=0)s=1;
			if(s!=0)
			{
				//*out='0'+p[i];
				out=put_txt(out,'0'+p[i]);
				out++;
				//*out=0;
				out=put_txt(out,0);
			}
		}
		if(s==0)
		{
			//*out='0';
			out=put_txt(out,'0');
			out++;
			//*out=0;
			out=put_txt(out,0);
		}
	}
	//----------- HEX ------------
	if(format==1)
	{
		r=(u8*)val;
		r+=1;
//		*out='0';
//		out++;
//		*out='x';
//		out++;
		for(i=0;i<2;i++)
		{
			c=*r>>4;
			if(c<10)
				*out='0'+c;
			else
				*out='A'+c-10;
			out++;
			*out=0;
			c=*r & 0x0f;
			if(c<10)
				*out='0'+c;
			else
				*out='A'+c-10;
			out++;
			*out=0;
			r--;
		}
	}
}
//-----------------------------------------------------------------------------------
void WordToStrFillZero(u8 *out,u16 *val,u8 format)
{
	u8 i,p[5],pp,c,s;
	u32 v,d,t;
	u8 *r;
	wait_con_free();
	while(*out!=0)out++;
	//----------- DEC ------------
	if(format==0)
	{
		v=*val;
		pp=4;
		for(i=0;i<5;i++)
		{
			t=v;
			v=v/10;
			d=v*10;
			c=t-d;
			p[pp]=c;
			pp--;
		}
		s=1;
		for(i=0;i<5;i++)
		{
			if(s!=0)
			{
				*out='0'+p[i];
				out++;
				*out=0;
			}
		}
	}
	//----------- HEX ------------
	if(format==1)
	{
		r=(u8*)val;
		r+=1;
//		*out='0';
//		out++;
//		*out='x';
//		out++;
		for(i=0;i<4;i++)
		{
			c=*r>>4;
			if(c<10)
				*out='0'+c;
			else
				*out='A'+c-10;
			out++;
			*out=0;
			c=*r & 0x0f;
			if(c<10)
				*out='0'+c;
			else
				*out='A'+c-10;
			out++;
			*out=0;
			r--;
		}
	}
}
//-----------------------------------------------------------------------------------
void WordToStrSigned(u8 *out,s16 *val)
{
	u8 i,p[5],pp,c,s;
	u32 d,t;
	s32 v;
//	u8 *r;
	wait_con_free();
	while(*out!=0)out++;
	//----------- DEC ------------
//	if(format==0)
	{
		v=*val;
		if(v<0)
		{
			v=-v;
			*out='-';
			out++;
			*out=0;			
		}		
		pp=4;
		for(i=0;i<5;i++)
		{
			t=v;
			v=v/10;
			d=v*10;
			c=t-d;
			p[pp]=c;
			pp--;
		}
		s=0;
		for(i=0;i<5;i++)
		{
			if(p[i]!=0)s=1;
			if(s!=0)
			{
				*out='0'+p[i];
				out++;
				*out=0;
			}
		}
		if(s==0)
		{
			*out='0';
			out++;
			*out=0;
		}
	}
}
//-----------------------------------------------------------------------------------
void ByteToStr(u8 *out,u8 *val,u8 format)
{
	u8 i,p[3],pp,c,s;
	u32 v,d,t;
	u8 *r;
	wait_con_free();
	while(*out!=0)out++;
	//----------- DEC ------------
	if(format==0)
	{
		v=*val;
		pp=2;
		for(i=0;i<3;i++)
		{
			t=v;
			v=v/10;
			d=v*10;
			c=t-d;
			p[pp]=c;
			pp--;
		}
		s=0;
		for(i=0;i<3;i++)
		{
			if(p[i]!=0)s=1;
			if(s!=0)
			{
				*out='0'+p[i];
				out++;
				*out=0;
			}
		}
		if(s==0)
		{
			*out='0';
			out++;
			*out=0;
		}
	}
	//----------- HEX ------------
	if(format==1)
	{
		r=(u8*)val;
//		*out='0';
//		out++;
//		*out='x';
//		out++;
		c=*r>>4;
		if(c<10)
			*out='0'+c;
		else
			*out='A'+c-10;
		out++;
		*out=0;
		c=*r & 0x0f;
		if(c<10)
			*out='0'+c;
		else
			*out='A'+c-10;
		out++;
		*out=0;
	}
	wait_con_free();
}
//-----------------------------------------------------------------------------------
void ByteToStrFillZero(u8 *out,u8 *val,u8 format,u8 digits,u8 fill)
{
	u8 i,p[3],pp,c,s;
	u32 v,d,t;
	u8 *r;
	wait_con_free();
	while(*out!=0)out++;
	//----------- DEC ------------
	if(format==0)
	{		
		v=*val;
		if(v<10)
		{
			*out=fill;
			out++;
			*out=0;
		}
		pp=2;
		for(i=0;i<3;i++)
		{
			t=v;
			v=v/10;
			d=v*10;
			c=t-d;
			p[pp]=c;
			pp--;
		}
		s=0;
		for(i=0;i<3;i++)
		{
			if(p[i]!=0)s=1;
			if(s!=0)
			{
				*out='0'+p[i];
				out++;
				*out=0;
			}
		}
		if(s==0)
		{
			*out='0';
			out++;
			*out=0;
		}
	}
	//----------- HEX ------------
	if(format==1)
	{
		r=(u8*)val;
//		*out='0';
//		out++;
//		*out='x';
//		out++;
		c=*r>>4;
		if(c<10)
			*out='0'+c;
		else
			*out='A'+c-10;
		out++;
		*out=0;
		c=*r & 0x0f;
		if(c<10)
			*out='0'+c;
		else
			*out='A'+c-10;
		out++;
		*out=0;
	}
	wait_con_free();
}
//-----------------------------------------------------------------------------------
void IntToStrFillZero(u8 *out,void *val,u8 format,u8 digits,u8 fill,u8 sign)
{
	u8 i,p[10];
	u32 d,t,c;
	s32 v;
//	u8 *r;
	wait_con_free();
	while(*out!=0)out++;
	switch(fill)
	{
		case 1:v=*(u8*)val;break;
		case 2:v=*(u16*)val;break;
		case 3:v=*(u32*)val;break;
		case 4:v=*(s8*)val;break;
		case 5:v=*(s16*)val;break;
		case 6:v=*(s32*)val;break;
		default:
		return;
	}	
	if(sign==1)
	{
		if(v<0)	*out='-';
		else 	*out='+';
		out++;
		*out=0;	
		if(v<0)v=-v;			
	}	
	//----------- DEC ------------
	if(format==0)
	{		
		for(i=0;i<digits;i++)
		{
			t=v;
			v=v/10;
			d=v*10;
			c=t-d;
			p[i]=c;
		}
		for(i=digits;i!=0;i--)
		{
			*out='0'+p[i-1];
			out++;
			*out=0;
		}
	}
	if(format==1)
	{
		for(i=0;i<digits;i++)
		{
//			t=v;
			c=v & 0x0000000f;
			v=v>>4;			
			p[i]=c;
		}
		for(i=digits;i!=0;i--)
		{
			if(p[i-1]<10)
				*out='0'+p[i-1];
			else
				*out='A'+p[i-1]-10;				
			out++;
			*out=0;
		}
		
	}
	wait_con_free();
}
//-----------------------------------------------------------------------------------
void ShowTemperature(unsigned char *out,short *val)
{
	u8 i,p[5],pp,c,s;
	u32 d,t;
	s16 v;
//	u8 *r;
	wait_con_free();
	while(*out!=0)out++;
	//----------- DEC ------------
//	if(format==0)
	{		
		v=*val;
		if(v<0)
		{
			v=-v;
			*out='-';
			out++;
			*out=0;			
		}
		else
		{
			*out='+';
			out++;
			*out=0;			
		}
		pp=4;
		for(i=0;i<5;i++)
		{
			t=v;
			v=v/10;
			d=v*10;
			c=t-d;
			p[pp]=c;
			pp--;
		}
		s=0;
		for(i=0;i<4;i++)
		{
			if(p[i]!=0)s=1;
			if(s!=0)
			{
				*out='0'+p[i];
				out++;
				*out=0;
			}
		}
		if(s==0)
		{
			*out='0';
			out++;
			*out=0;
		}		
		*out='.';
		out++;
		*out=0;		
		if(p[4]!=0)s=1;
		if(s!=0)
		{
			*out='0'+p[4];
			out++;
			*out=0;
		}		
		if(s==0)
		{
			*out='0';
			out++;
			*out=0;
		}
//		*out=0xdf;
//		out++;
		*out='C';
		out++;
		*out=0;				
	}
}
//-----------------------------------------------------------------------------------
void ShowTemperatureShort(unsigned char *out,short *val)
{
	u8 i,p[5],pp,c,s;
	u32 d,t;
	s16 v;
//	u8 *r;
	wait_con_free();
	while(*out!=0)out++;
	//----------- DEC ------------
//	if(format==0)
	{		
		v=*val;
		if(v<0)
		{
			v=-v;
			*out='-';
			out++;
			*out=0;			
//			*out=' ';			
		}
		else
		{
			*out='+';
			out++;
			*out=0;			
//			*out=' ';
		}
		pp=4;
		for(i=0;i<5;i++)
		{
			t=v;
			v=v/10;
			d=v*10;
			c=t-d;
			p[pp]=c;
			pp--;
		}
		s=0;
		for(i=0;i<4;i++)
		{
			if(p[i]!=0)s=1;
			if(s!=0)
			{
				*out='0'+p[i];
				out++;
				*out=0;
//				*out=' ';
			}
		}
		if(s==0)
		{
			*out='0';
			out++;
			*out=0;
//			*out=' ';
		}		
		*out='.';
		out++;
		*out=0;		
		if(p[4]!=0)s=1;
		if(s!=0)
		{
			*out='0'+p[4];
			out++;
			*out=0;
//			*out=' ';
		}		
		if(s==0)
		{
			*out='0';
			out++;
			*out=0;
//			*out=' ';
		}
	}
//	*out=0;
}
//-----------------------------------------------------------------------------------
void ShowTemperatureShort2(u8 *out,s16 *val)
{
	u8 i,p[5],pp,c,s;
	u32 d,t;
	s16 v;
//	u8 *r;
	wait_con_free();
	while(*out!=0)out++;
	//----------- DEC ------------
//	if(format==0)
	{		
		v=*val;
		if(v<0)
		{
			v=-v;
//			*out='-';
//			out++;
//			*out=0;			
		}
		else
		{
//			*out='+';
//			out++;
//			*out=0;			
		}
		pp=4;
		for(i=0;i<5;i++)
		{
			t=v;
			v=v/10;
			d=v*10;
			c=t-d;
			p[pp]=c;
			pp--;
		}
		s=0;
		for(i=0;i<4;i++)
		{
			if(p[i]!=0)s=1;
			if(s!=0)
			{
				*out='0'+p[i];
				out++;
				*out=0;
			}
		}
		if(s==0)
		{
			*out='0';
			out++;
			*out=0;
		}		
		*out='.';
		out++;
		*out=0;		
		if(p[4]!=0)s=1;
		if(s!=0)
		{
			*out='0'+p[4];
			out++;
			*out=0;
		}		
		if(s==0)
		{
			*out='0';
			out++;
			*out=0;
		}
	}
}
//-----------------------------------------------------------------------------------
void ShowPowerShort(unsigned char *out,short *val)
{
	u8 i,p[5],pp,c,s;
	u32 d,t;
	s16 v;
//	u8 *r;
	wait_con_free();
	while(*out!=0)out++;
	//----------- DEC ------------
//	if(format==0)
	{		
		v=*val;
		if(v<0)
		{
			v=-v;
//			*out='-';
//			out++;
//			*out=0;			
		}
		else
		{
//			*out='+';
//			out++;
//			*out=0;			
		}
		if(v>999)v=999;
		pp=4;
		for(i=0;i<5;i++)
		{
			t=v;
			v=v/10;
			d=v*10;
			c=t-d;
			p[pp]=c;
			pp--;
		}
		s=0;
		for(i=0;i<4;i++)
		{
			if(p[i]!=0)s=1;
			if(s!=0)
			{
				*out='0'+p[i];
				out++;
				*out=0;
			}
		}
		if(s==0)
		{
			*out='0';
			out++;
			*out=0;
		}		
		*out='.';
		out++;
		*out=0;		
		if(p[4]!=0)s=1;
		if(s!=0)
		{
			*out='0'+p[4];
			out++;
			*out=0;
		}		
		if(s==0)
		{
			*out='0';
			out++;
			*out=0;
		}
		*out='%';
		out++;
		*out=0;		
	}
}
//-----------------------------------------------------------------------------------
/*
void ShowShort_6sym(unsigned char *out,short *val)
{
	short 	v=*val;
	short	di,mo,tmp;
	signed char 	buf[7];
	char	i;	
	if(v<0)
	{	
		v=-v;
		out[0]='-';
	}
	else
	{
		out[0]='+';
	}
	
	tmp=v;	
	for(i=0;i<4;i++)
	{		
		di=tmp/10;	
		mo=tmp - di*10;	
		buf[i]=mo;
		tmp=di;				
		if((di==0)&&(mo==0))buf[i]=-1;
	}
	if(buf[3]!=-1)out[1]=buf[3]+'0';else out[1]=' ';
	if(buf[2]!=-1)out[2]=buf[2]+'0';else out[2]=' ';
	if(buf[1]!=-1)out[3]=buf[1]+'0';else out[3]='0';	
	out[4]='.';	
	if(buf[0]!=-1)out[5]=buf[0]+'0';else out[5]='0';		
	out[6]=0;	
}
*/
//-----------------------------------------------------------------------------------
void LongToStr(u8 *out,u32 *val,u8 format)
{
	u8 i,p[10],pp,c,s;
	u32 v,d,t;
	u8 *r;
	wait_con_free();
	while(*out!=0)out++;
	//----------- DEC ------------
	if(format==0)
	{
		v=*val;
		pp=9;
		for(i=0;i<10;i++)
		{
			t=v;
			v=v/10;
			d=v*10;
			c=t-d;
			p[pp]=c;
			pp--;
		}
		s=0;
		for(i=0;i<10;i++)
		{
			if(p[i]!=0)s=1;
			if(s!=0)
			{
				*out='0'+p[i];
				out++;
				*out=0;
			}
		}
		if(s==0)
		{
			*out='0';
			out++;
			*out=0;
		}
	}
	//----------- HEX ------------
	if(format==1)
	{	
		r=(u8*)val;
		r+=3;
//		*out='0';
//		out++;
//		*out='x';
//		out++;
		for(i=0;i<4;i++)
		{
			c=*r>>4;
			if(c<10)
				*out='0'+c;
			else
				*out='A'+c-10;
			out++;
			*out=0;
			c=*r & 0x0f;
			if(c<10)
				*out='0'+c;
			else
				*out='A'+c-10;
			out++;
			 *out=0;
			r--;
		}
	}
	wait_con_free();
}
//-----------------------------------------------------------------------------------
void __strlwr(char *str)
{
	while(*str!=0)
	{
		if((*str>=0x41)&&(*str<=0x5A))
		{
			*str=*str+0x20;
		}
		str++;
	}
}
//-----------------------------------------------------------------------------------
u8 strcmp2(u8* str1,u8* str2)
{
	u8 sign=0;
	while((*str1!=0)||(*str2!=0))
	{
		if(*str1!=*str2)sign=1;
		str1++;
		str2++;
	}
	return sign;
}
//-----------------------------------------------------------------------------------
u8 strcmp3(u8* str1,u8* str2)
{
	u8 sign=0;
	while((*(in_flash u8*)str1!=0)||(*str2!=0))
	{
		if(*(in_flash u8*)str1!=*str2)sign=1;
		str1++;
		str2++;
	}
	return sign;
}
//-----------------------------------------------------------------------------------
void strcat2(u8* str1,u8* str2)
{
	while(*str1!=0)
		str1++;

	while(*(in_flash u8*)str2!=0)
	{
		*str1=*(in_flash u8*)str2;
		str1++;
		str2++;
	}
	*str1=' ';
	str1++;	
	*str1=0;	
}
//-----------------------------------------------------------------------------------
void strcpy2(u8* str1,u8* str2)
{
	while(*str2!=0)
	{
		*str1=*str2;
		str1++;
		str2++;
	}
	*str1=0;	
}
//-----------------------------------------------------------------------------------
u16 strlen2(u8* str1)
{
	u16 length=0;
	while(*str1!=0)
	{
		str1++;
		length++;
	}
	return length;
}
//-----------------------------------------------------------------------------------
/*
void _strcat(u8* str1,u8* str2)
{
	while(*str1!=0)str1++;		
	while(*str2!=0)
	{
		*str1=*str2;
		str1++;
		str2++;
	}
	*str1=0;
}
*/
//-----------------------------------------------------------------------------------
void memset2(u8 *s,u8 c, u8 len)
{
	while(len!=0)
	{
		*s=c;
		s++;		
		len--;
	}
}
//-----------------------------------------------------------------------------------
void memcpy2(u8 *s,u8 *c, u8 len)
{
	while(len!=0)
	{
		*s=*c;
		s++;	
		c++;	
		len--;
	}
}
//-----------------------------------------------------------------------------------
// New functions
//-----------------------------------------------------------------------------------
void ShowShort_6sym(unsigned char *out,short *val)
{
	short 	v=*val;
	short	di,mo,tmp;
	signed char 	buf[7];
	char	i;	
	while(*out!=0)out++;
	if(v<0)
	{	
		v=-v;
		out[0]='-';
	}
	else
	{
		out[0]='+';
	}
	
	tmp=v;	
	for(i=0;i<4;i++)
	{		
		di=tmp/10;	
		mo=tmp - di*10;	
		buf[i]=mo;
		tmp=di;				
		if((di==0)&&(mo==0))buf[i]=-1;
	}
	if(buf[3]!=-1)out[1]=buf[3]+'0';else out[1]=' ';
	if(buf[2]!=-1)out[2]=buf[2]+'0';else out[2]=' ';
	if(buf[1]!=-1)out[3]=buf[1]+'0';else out[3]='0';	
	out[4]='.';	
	if(buf[0]!=-1)out[5]=buf[0]+'0';else out[5]='0';		
	out[6]=0;	
}
//-----------------------------------------------------------------------------------
void ShowShort_5sym(unsigned char *out,short *val)
{
	short 	v=*val;
	short	di,mo,tmp;
	signed char 	buf[7];
	char	i;	
	while(*out!=0)out++;
	if(v<0)
	{	
		v=-v;
		out[0]='-';
	}
	else
	{
		out[0]='+';
	}
	
	tmp=v;	
	for(i=0;i<4;i++)
	{		
		di=tmp/10;	
		mo=tmp - di*10;	
		buf[i]=mo;
		tmp=di;				
		if((di==0)&&(mo==0))buf[i]=-1;
	}
	if(buf[2]!=-1)out[1]=buf[2]+'0';else out[1]=' ';
	if(buf[1]!=-1)out[2]=buf[1]+'0';else out[2]='0';	
	out[3]='.';	
	if(buf[0]!=-1)out[4]=buf[0]+'0';else out[4]='0';		
	out[5]=0;	
}
//-----------------------------------------------------------------------------------
void ShowUChar_2sym(unsigned char *out,char *val)
{
	short 	v=*val;
	short	di,mo,tmp;
	signed char 	buf[7];
	char	i;	
	while(*out!=0)out++;
	tmp=v;	
	for(i=0;i<3;i++)
	{		
		di=tmp/10;	
		mo=tmp - di*10;	
		buf[i]=mo;
		tmp=di;				
		if((di==0)&&(mo==0))buf[i]=-1;
	}
	if(buf[0]!=-1)out[1]=buf[0]+'0';else out[1]=' ';
	if(buf[1]!=-1)out[0]=buf[1]+'0';
	out[2]=0;	
}
//-----------------------------------------------------------------------------------
void ShowUChar_2sym_fill_zero(unsigned char *out,unsigned char *val)
{
	short 	v=*val;
	short	di,mo,tmp;
	signed char 	buf[7];
	char	i;	
	while(*out!=0)out++;
	tmp=v;	
	for(i=0;i<3;i++)
	{		
		di=tmp/10;	
		mo=tmp - di*10;	
		buf[i]=mo;
		tmp=di;				
		if((di==0)&&(mo==0))buf[i]=-1;
	}
	if(buf[0]!=-1)out[1]=buf[0]+'0';else out[1]='0';
	if(buf[1]!=-1)out[0]=buf[1]+'0';else out[0]='0';
	out[2]=0;	
}
//-----------------------------------------------------------------------------------
void Show_Time(char *out,TCTime *time)
{
	char str[40];
	char str2[20];	
	//while(*out!=0)out++;
	ShowUChar_2sym_fill_zero(str,&time->field.Date);
	strcat(str,"/");
	ShowUChar_2sym_fill_zero(str2,&time->field.Month);
	strcat(str,str2);
	strcat(str,"/20");
	ShowUChar_2sym_fill_zero(str2,&time->field.Year);
	strcat(str,str2);
	strcat(str," ");

	ShowUChar_2sym_fill_zero(str2,&time->field.Hour);
//	if(time_blink & 1){
		strcat(str,str2);strcat(str,":");
//}
//	else{
//		strcat(str,str2);strcat(str," ");}
	ShowUChar_2sym_fill_zero(str2,&time->field.Minute);
	strcat(str,str2);
	strcpy(out,(char*)str);
}
//-----------------------------------------------------------------------------------
void ShowUChar_2sym_fill_zero_no_shift(unsigned char *out,unsigned char *val)
{
	short 	v=*val;
	short	di,mo,tmp;
	signed char 	buf[7];
	char	i;	
	tmp=v;	
	for(i=0;i<3;i++)
	{		
		di=tmp/10;	
		mo=tmp - di*10;	
		buf[i]=mo;
		tmp=di;				
		if((di==0)&&(mo==0))buf[i]=-1;
	}
	if(buf[0]!=-1)out[1]=buf[0]+'0';else out[1]='0';
	if(buf[1]!=-1)out[0]=buf[1]+'0';else out[0]='0';
	out[2]=0;	
}
//-----------------------------------------------------------------------------------
void Show_Time_No_Shift(char *out,TCTime *time)
{
	char str[40];
	char str2[20];	
	ShowUChar_2sym_fill_zero_no_shift(str,&time->field.Date);
	strcat(str,"/");
	ShowUChar_2sym_fill_zero_no_shift(str2,&time->field.Month);
	strcat(str,str2);
	strcat(str,"/20");
	ShowUChar_2sym_fill_zero_no_shift(str2,&time->field.Year);
	strcat(str,str2);
	strcat(str," ");

	ShowUChar_2sym_fill_zero_no_shift(str2,&time->field.Hour);
	strcat(str,str2);strcat(str,":");
	ShowUChar_2sym_fill_zero_no_shift(str2,&time->field.Minute);
	strcat(str,str2);
	strcpy(out,(char*)str);
}
//-----------------------------------------------------------------------------------
