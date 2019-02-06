//------------------------------------------------------------------------------
#include "../main.h"
//------------------------------------------------------------------------------
/*
void buff_init(TBuffer *buff);
void buff_put(TBuffer *buff,u8 *data,u8 len);
void buff_get(TBuffer *buff,u8 *data,u8 len);
u8 buff_is_empty(TBuffer *buff);
u8 buff_is_full(TBuffer *buff);
u8 buff_filled(TBuffer *buff);
*/
//------------------------------------------------------------------------------
void buff_init(TBuffer *buff,u8 length)
{
	memset(buff,0,sizeof(TBuffer));
}
//------------------------------------------------------------------------------
void buff_put_char(TBuffer *buff,u8 *data)
{
	u8 stop;
	stop=buff->ptr_end + 1;
	if(stop>=MAX_BUFFER_LENGTH)stop-=MAX_BUFFER_LENGTH;
	if(stop!=buff->ptr_start)
	{
		buff->data[buff->ptr_end]=*data;
		buff->ptr_end=stop;
	}
}
//------------------------------------------------------------------------------
u8 buff_get_char(TBuffer *buff)
{
	u8 start;
	u8 data;
	start=buff->ptr_start;
	if(start!=buff->ptr_end)		
	{
		data=buff->data[start];
		start++;
		if(start>=MAX_BUFFER_LENGTH)start-=MAX_BUFFER_LENGTH;
		buff->ptr_start=start;					
	}
	return data;
}
//------------------------------------------------------------------------------
u8 buff_is_empty(TBuffer *buff)
{
	if(buff->ptr_end==buff->ptr_start)
	{
		return 1;
	}
	return 0;	
}
//------------------------------------------------------------------------------
u8 buff_is_full(TBuffer *buff)
{
	u8 stop;
	stop=buff->ptr_end + 1;
	if(stop>=MAX_BUFFER_LENGTH)stop-=MAX_BUFFER_LENGTH;
	if(stop==buff->ptr_start)
	{
		return 1;
	}
	return 0;	
}
//------------------------------------------------------------------------------
u8 buff_filled(TBuffer *buff)
{
	s16 start;
	s16 stop;
	s16 len;
	start=buff->ptr_start;
	stop=buff->ptr_end;
	len=stop-start;
	if(len<0)len+=MAX_BUFFER_LENGTH;
	return len;	
}
//-----------------------------------------------------------------------------------
