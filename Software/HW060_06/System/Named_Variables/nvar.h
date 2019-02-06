#ifndef __NAMED_VARIABLES
#define	__NAMED_VARIABLES
//------------------------------------------------------------------------------
// Named variables data structure
//------------------------------------------------------------------------------
#define	MAX_NAMED_VARIABLES_LIST	100
//------------------------------------------------------------------------------
#define TYPE_S8           1
#define TYPE_U8           2
#define TYPE_S16          3
#define TYPE_U16          4
#define TYPE_S32          5
#define TYPE_U32          6
#define TYPE_F32          7
#define TYPE_STR          8
//------------------------------------------------------------------------------
typedef __packed struct
{
	char 	name[10];
	char 	*ptr;
	u8	type;	
	u8	num;		// Used for arrays
	u32	offs;		// Used for arrays
}TNamedVariable;

extern TNamedVariable	__packed NVar[MAX_NAMED_VARIABLES_LIST];
//------------------------------------------------------------------------------
void nvar_init(void);
int nvar_load(char *name);
int nvar_store(char *name);
void nvar_to_common();
void common_to_nvar();
//------------------------------------------------------------------------------
#endif