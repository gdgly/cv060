//------------------------------------------------------------------------------
#include "main.h"
//------------------------------------------------------------------------------
u8 	ad_res_l,ad_res_h;
s16	ad_res;
u16	ad_res_int=0;
s16 point_reference_temperature[2];
s16 point_real_temperature[2][NUM_AIN_REAL];
s32 filter[NUM_AIN_REAL+1+NUM_AIN_THERMO];
s16	input_voltage=0;
u8 channel=0;
u8 tmp;
u16	ad_tmp;
u32	ad_tmp32;
double	ftmp;
//u8	tmp8[3];
s16 ai_tst[NUM_AIN_REAL+NUM_AIN_THERMO];
s16 adc_real_result[NUM_AIN_REAL+NUM_AIN_THERMO];
#define MEDIAN_FILTER_SAMPLES_MAX 4
s16 med_filter[NUM_AIN_REAL+NUM_AIN_THERMO][MEDIAN_FILTER_SAMPLES_MAX];
s16 med_filter_average[NUM_AIN_REAL+NUM_AIN_THERMO];
s16 med_filter_average_diff[NUM_AIN_REAL+NUM_AIN_THERMO];
s16 med_filter_diff[NUM_AIN_REAL+NUM_AIN_THERMO][MEDIAN_FILTER_SAMPLES_MAX];
s32 ai_filter[NUM_AIN_REAL+NUM_AIN_THERMO]={0};

s16 ai_hyst[NUM_AIN_REAL][ADC_FILTER_TIME_BASE] = {0};
s32 ai_hyst_summ[NUM_AIN_REAL] = {0};
int	ai_hyst_ptr[NUM_AIN_REAL] = {0};
//------------------------------------------------------------------------------
s16 adc_conversion();
void adc_set_channel(u8 ch);
void adc_hardware_init();
//------------------------------------------------------------------------------
void adc_init()
{
	adc_hardware_init();
	channel=0;	
	adc_set_channel(channel);	
	memset(&filter[0],0,sizeof(filter));
}
//------------------------------------------------------------------------------
s16 Median_Filter(s16 temp)
{
//	u8 i;
	s16 diff;
	s16 diff2;
	med_filter[channel][3]=med_filter[channel][2];	
	med_filter[channel][2]=med_filter[channel][1];	
	med_filter[channel][1]=med_filter[channel][0];	
	med_filter[channel][0]=temp;
	med_filter_average[channel]=med_filter[channel][0]+med_filter[channel][1]+med_filter[channel][2]+med_filter[channel][3];
	med_filter_average[channel]/=4;
		
	diff=temp-med_filter_average[channel];
	if(diff<0)diff=-diff;
	med_filter_diff[channel][3]=med_filter_diff[channel][2];	
	med_filter_diff[channel][2]=med_filter_diff[channel][1];	
	med_filter_diff[channel][1]=med_filter_diff[channel][0];	
	med_filter_diff[channel][0]=diff;

	med_filter_average_diff[channel]=med_filter_diff[channel][0]+med_filter_diff[channel][1]+med_filter_diff[channel][2]+med_filter_diff[channel][3];
	med_filter_average_diff[channel]/=4;
		
	diff2=med_filter_average_diff[channel]*3;
	if(diff2>diff)return temp;
	else return med_filter[channel][1];	
}
//------------------------------------------------------------------------------
s16 adc_simple_flter(s16 temp)
{
	ai_filter[channel] *= 7;
	ai_filter[channel] += temp;
	ai_filter[channel] /= 8;
	return ai_filter[channel];
}
//------------------------------------------------------------------------------
s16 adc_extended_filter(s16 temp)
{
	s32 tmp;
	if (ExtCV.adc_filter_time[channel] > ADC_FILTER_TIME_BASE) 	ExtCV.adc_filter_time[channel] = ADC_FILTER_TIME_BASE;
	if (ExtCV.adc_filter_time[channel] == 0 ) 					ExtCV.adc_filter_time[channel] = 1;
	ai_hyst_summ[channel] -= ai_hyst[channel][ai_hyst_ptr[channel]];
	ai_hyst[channel][ai_hyst_ptr[channel]] = temp;
	ai_hyst_summ[channel] += ai_hyst[channel][ai_hyst_ptr[channel]];
	ai_hyst_ptr[channel] ++;
	if (ai_hyst_ptr[channel] >= ExtCV.adc_filter_time[channel]) ai_hyst_ptr[channel] = 0;
	tmp = ai_hyst_summ[channel] /  ExtCV.adc_filter_time[channel];
	return tmp;
}
//------------------------------------------------------------------------------
s16 adc_get_deviation(u8 ch)
{
	s32 tmp;
	s32 summ = 0;
	s32 diff;
	int i;
	if ( ch < NUM_AIN_REAL ){
		tmp = ai_hyst_summ[ch] / ExtCV.adc_filter_time[ch];
		for (i = 0; i < ExtCV.adc_filter_time[ch]; i ++){
			diff = 	tmp - ai_hyst[ch][i];
			if (diff < 0 ) diff = -diff;
			summ += diff;
		}
		tmp = summ / ExtCV.adc_filter_time[ch];
		return tmp;
	}
	return 0;
}
//------------------------------------------------------------------------------
void adc_handle()
{
	f32 ftmp;
	s16 temp;
	ftmp=adc_conversion();
//	ai_tst[channel]=ftmp;
	if(channel<NUM_AIN_REAL)
	{
		ftmp=ftmp*io.ai_coff[channel];
		ftmp=ftmp+io.ai_offset[channel];
		adc_real_result[channel]=(s16)ftmp;
		temp=(s16)ftmp;
		switch(channel)
		{
		case 0:
			io.ainput[channel]=adc_extended_filter(temp);
			break;
		case 1:
			io.ainput[channel]=adc_extended_filter(temp);
			break;
		case 2:
			io.ainput[channel]=adc_extended_filter(temp);
			break;
		case 3:
			io.ainput[channel]=adc_extended_filter(temp);
			break;
		case 4:
			io.ainput[channel]=adc_extended_filter(temp);
//			io.ainput[channel]=Median_Filter(temp);
			break;
		}
//		io.ainput[channel]=temp;
	}
/*
#if NUM_AIN_THERMO	
	if(channel==NUM_AIN_REAL)
	{
//		ftmp=ftmp*2;
		ftmp=ftmp/10;		
		adc_real_result[channel]=(s16)ftmp;
		temp=(s16)ftmp;
		io.ainput[channel]=Median_Filter(temp);		
		temp=0;
	}	
#endif
*/
	channel++;
	if(channel>=(NUM_AIN_REAL+NUM_AIN_THERMO))
	{
		channel=0;
//		pid_handle();
/*
#if TMP441_ENABLE		
		// TMP441 get temperature
		TMP441_read(TMP441_reg_Remote0_T_H,(u8*)&stmp,1);
		temp=stmp;
		temp*=10;
		TMP441_read(TMP441_reg_Remote0_T_L,&utmp,1);			
		utmp>>=4;
		ftmp=utmp*0.0625*10;
		temp+=ftmp;
#ifdef __HW050			
		io.ainput[4]=temp;
#endif					
#endif
*/
	}	
	//channel=3;
	adc_set_channel(channel);
	//adc_set_channel(4);
}
//------------------------------------------------------------------------------
