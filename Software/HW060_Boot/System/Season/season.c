#include "main.h"
//-----------------------------------------------------------------------------------
#define MAX_SEASON_COUNT	5		// Timeout for choosing season
//-----------------------------------------------------------------------------------
in_flash u8	pseason[][40]=
{
	"\n\r Season parameters",			//0
	"\n\r   Season:                 ",  //1		
	"\n\r   Mode  :                 ",	//2		
	"\n\r   Temperature mode        ",	//3		
	"\n\r   Date mode               ",	//4		
	"\n\r   Preset Temperature      ",	//5		
	"\n\r   Current Temperature     ",	//6		
	"Auto",								//7
	"Manual",							//8		
	"\n\r   Summer                  ",	//9		
	"\n\r   Winter                  ",	//10	
	"Summer",							//11		
	"Winter",							//12		
};
//-----------------------------------------------------------------------------------
u8 Season_Timeout=0;
u8 Season_Count=3;
//-----------------------------------------------------------------------------------
void Season_Handle()
{
	if(reg_season.mode==SEASON_AUTO)
	{
		// Temperature part		
		if(reg_season.switch_temperature)
		{
			if(reg_season.t<io.ainput[reg_season.t_extern_channel])
			{
				if(Season_Timeout==0)
				{
					Season_Count++;
					Season_Timeout=5;
					if(Season_Count>=MAX_SEASON_COUNT)
					{
						Season_Count=MAX_SEASON_COUNT;
						reg_season.season=SEASON_SUMMER;					
//						reg_season.season=SEASON_WINTER;					
					}
				}
			}
			else
			{
				if(Season_Timeout==0)
				{
					if(Season_Count)Season_Count--;
					Season_Timeout=5;
					if(Season_Count==0)
					{
						Season_Count=MAX_SEASON_COUNT;
						reg_season.season=SEASON_WINTER;					
//						reg_season.season=SEASON_SUMMER;					
						
					}
				}
			}							
		}
		// Date part
		if(reg_season.switch_date)
		{
			reg_season.season=SEASON_WINTER;						
			if(MenuRegs.Time.field.Month > reg_season.date[0].field.Month)
				if(MenuRegs.Time.field.Month < reg_season.date[1].field.Month)
					reg_season.season=SEASON_SUMMER;

			if(MenuRegs.Time.field.Month == reg_season.date[0].field.Month)
				if(MenuRegs.Time.field.Date >= reg_season.date[0].field.Date)
					reg_season.season=SEASON_SUMMER;

			if(MenuRegs.Time.field.Month == reg_season.date[1].field.Month)
				if(MenuRegs.Time.field.Date < reg_season.date[1].field.Date)
					reg_season.season=SEASON_SUMMER;
		}		
	}
}
//-----------------------------------------------------------------------------------
void Mod_Show_Season()
{
	__sprintf_P(outtxt,pseason[0]);			

	__sprintf_P(outtxt,pseason[1]);	
	if(reg_season.season==SEASON_SUMMER)__sprintf_P(outtxt,pseason[11]);
	else __sprintf_P(outtxt,pseason[12]);	

	__sprintf_P(outtxt,pseason[2]);	
	if(reg_season.mode==SEASON_AUTO)__sprintf_P(outtxt,pseason[7]);
	else __sprintf_P(outtxt,pseason[8]);	
	
	__sprintf_P(outtxt,pseason[3]);	
	ByteToStr(outtxt,&reg_season.switch_temperature,0);

	__sprintf_P(outtxt,pseason[4]);	
	ByteToStr(outtxt,&reg_season.switch_date,0);
	
	__sprintf_P(outtxt,pseason[5]);				
	ShowTemperature(outtxt,(short *)&reg_season.t);				

	__sprintf_P(outtxt,pseason[6]);				
	ShowTemperature(outtxt,(short *)&io.ainput[reg_season.t_extern_channel]);				
	
	__sprintf_P(outtxt,pseason[9]);	
	ByteToStr(outtxt,&reg_season.date[0].field.Date,0);
	__sprintf(outtxt,"/");	
	ByteToStr(outtxt,&reg_season.date[0].field.Month,0);

	__sprintf_P(outtxt,pseason[10]);	
	ByteToStr(outtxt,&reg_season.date[1].field.Date,0);
	__sprintf(outtxt,"/");	
	ByteToStr(outtxt,&reg_season.date[1].field.Month,0);
}
//-----------------------------------------------------------------------------------
