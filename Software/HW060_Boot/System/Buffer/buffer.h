#ifndef __BUFFER
#define __BUFFER
//---------------------------------------------------------------------------
#include "main.h"
//---------------------------------------------------------------------------
#define MAX_BUFFER_LENGTH  100
//---------------------------------------------------------------------------
typedef struct
{
	u8 max_length;
	u8 data[MAX_BUFFER_LENGTH];
	u8 ptr;
	u8 ptr_end;
	u8 ptr_start;
}TBuffer;
//---------------------------------------------------------------------------
void buff_init(TBuffer *buff,u8 length);
//void buff_put(TBuffer *buff,u8 *data,u8 len);
//void buff_get(TBuffer *buff,u8 *data,u8 len);
void buff_put_char(TBuffer *buff, u8 *data);
u8 buff_get_char(TBuffer *buff);

u8 buff_is_empty(TBuffer *buff);
u8 buff_is_full(TBuffer *buff);
u8 buff_filled(TBuffer *buff);

void buff_delete(TBuffer *buff);
//---------------------------------------------------------------------------
#endif
