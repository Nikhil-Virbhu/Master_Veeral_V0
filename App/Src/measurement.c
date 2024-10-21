/* Buffer locations and respective quantities
	Adc_Avg_Buffer[0];   PA0 -> VAC_R (AC) 1
	Adc_Avg_Buffer[1];   PA1 -> VAC_Y (AC) 1
	Adc_Avg_Buffer[2];   PA2 -> VAC_B (AC) 1
	Adc_Avg_Buffer[3];   PA3 -> V_OUT (DC) 1
	Adc_Avg_Buffer[4];   PA6 -> VAC_E (AC) 2
	Adc_Avg_Buffer[5];   PA7 -> I_OUT (DC) 2
	Adc_Avg_Buffer[6];   PD12 -> IAC_R (AC) 3
	Adc_Avg_Buffer[7];   PD11 -> IAC_Y (AC) 3
	Adc_Avg_Buffer[8];   PD10 -> IAC_B (AC) 3
	Adc_Avg_Buffer[9];   PE14 -> V1.65  4
	Adc_Avg_Buffer[10];  PA9 -> I_REF (DC) 5
	Adc_Avg_Buffer[11];  PD13 -> Tmpr2 (DC) 5
	Adc_Avg_Buffer[12];  PD14 -> Tmpr1 (DC) 5
*/

#define _MEASUREMENT_
#include "main.h"
#include "measurement.h"
#include "debug.h"

/*Function description: Function to calculate Sum and Average of ADC1 Parameters*/
void parameterCalculations_ADC1(void){
	Adc_Sum_Buffer[eVAC_R]=0,Adc_Sum_Buffer[eVAC_Y]=0,Adc_Sum_Buffer[eVAC_B]=0,Adc_Sum_Buffer[eV_OUT]=0;
	for(int i=0;i<ADC_SAMPLE_SIZE;i++){
		Adc_Sum_Buffer[eVAC_R] += Adc1_Buffer[i*ADC1_CHN + 0];  //PA0 -> VAC_R
		Adc_Sum_Buffer[eVAC_Y] += Adc1_Buffer[i*ADC1_CHN + 1];  //PA1 -> VAC_Y
		Adc_Sum_Buffer[eVAC_B] += Adc1_Buffer[i*ADC1_CHN + 2];  //PA2 -> VAC_B
		Adc_Sum_Buffer[eV_OUT] += Adc1_Buffer[i*ADC1_CHN + 3];  //PA3 -> V_OUT
	}
    Adc_Avg_Buffer[eVAC_R] = Adc_Sum_Buffer[eVAC_R]/ADC_SAMPLE_SIZE;  //PA0 -> VAC_R
    Adc_Avg_Buffer[eVAC_Y] = Adc_Sum_Buffer[eVAC_Y]/ADC_SAMPLE_SIZE;  //PA1 -> VAC_Y
    Adc_Avg_Buffer[eVAC_B] = Adc_Sum_Buffer[eVAC_B]/ADC_SAMPLE_SIZE;  //PA2 -> VAC_B
    Adc_Avg_Buffer[eV_OUT] = Adc_Sum_Buffer[eV_OUT]/ADC_SAMPLE_SIZE;  //PA3 -> V_OUT
}

/*Function description: Function to calculate Sum and  Average of ADC2 Parameters*/
void parameterCalculations_ADC2(void){//Function to calculate Average of ADC2 Parameters
	Adc_Sum_Buffer[eVAC_E]=0,Adc_Sum_Buffer[eI_OUT]=0;
	for(int i=0;i<ADC_SAMPLE_SIZE;i++){
		Adc_Sum_Buffer[eVAC_E] += Adc2_Buffer[i*ADC2_CHN + 0];  //PA6 -> VAC_E
		Adc_Sum_Buffer[eI_OUT] += Adc2_Buffer[i*ADC2_CHN + 1];  //PA7 -> I_OUT
	}
	Adc_Avg_Buffer[eVAC_E] = Adc_Sum_Buffer[eVAC_E]/ADC_SAMPLE_SIZE;  //PA6 -> VAC_E
	Adc_Avg_Buffer[eI_OUT] = Adc_Sum_Buffer[eI_OUT]/ADC_SAMPLE_SIZE;  //PA7 -> I_OUT
}

/*Function description: Function to calculate Sum and  Average of ADC3 Parameters*/
void parameterCalculations_ADC3(void){
	Adc_Sum_Buffer[eIAC_B]=0,Adc_Sum_Buffer[eIAC_Y]=0,Adc_Sum_Buffer[eIAC_R]=0;
	for(int i=0;i<ADC_SAMPLE_SIZE;i++){
		Adc_Sum_Buffer[eIAC_R] += Adc3_Buffer[i*ADC3_CHN + 0];  //PD12 -> IAC_R
		Adc_Sum_Buffer[eIAC_Y] += Adc3_Buffer[i*ADC3_CHN + 1];  //PD10 -> IAC_Y
		Adc_Sum_Buffer[eIAC_B] += Adc3_Buffer[i*ADC3_CHN + 2];  //PD11 -> IAC_B
	}
	Adc_Avg_Buffer[eIAC_R] = Adc_Sum_Buffer[eIAC_R]/ADC_SAMPLE_SIZE;  //PD12 -> IAC_R
	Adc_Avg_Buffer[eIAC_Y] = Adc_Sum_Buffer[eIAC_Y]/ADC_SAMPLE_SIZE;  //PD10 -> IAC_Y
	Adc_Avg_Buffer[eIAC_B] = Adc_Sum_Buffer[eIAC_B]/ADC_SAMPLE_SIZE;  //PD11 -> IAC_B
}

void parameterCalculations_ADC4(void){
	Adc_Sum_Buffer[ev1_65]=0;
	for(int i=0;i<ADC_SAMPLE_SIZE;i++){
		Adc_Sum_Buffer[ev1_65] += Adc4_Buffer[i*ADC4_CHN + 0];  //PE14 -> V1.65
	}
	Adc_Avg_Buffer[ev1_65] = Adc_Sum_Buffer[ev1_65]/ADC_SAMPLE_SIZE;  //PE14 -> V1.65
}

/*Function description: Function to calculate Sum and  Average of ADC5 Parameters*/
void parameterCalculations_ADC5(void){
	Adc_Sum_Buffer[eIref]=0, Adc_Sum_Buffer[eTmpr2]=0, Adc_Sum_Buffer[eTmpr1]=0;
	for(int i=0;i<ADC_SAMPLE_SIZE;i++){
		Adc_Sum_Buffer[eIref] += Adc5_Buffer[i*ADC5_CHN + 0];  //PA9 -> I_REF
		Adc_Sum_Buffer[eTmpr2] += Adc5_Buffer[i*ADC5_CHN + 1];  //PD13 -> Tmpr2
		Adc_Sum_Buffer[eTmpr1] += Adc5_Buffer[i*ADC5_CHN + 2];  //PD14 -> Tmpr1
	}
	Adc_Avg_Buffer[eIref] = Adc_Sum_Buffer[eIref]/ADC_SAMPLE_SIZE;  //PA9 -> I_REF
	Adc_Avg_Buffer[eTmpr2] = Adc_Sum_Buffer[eTmpr2]/ADC_SAMPLE_SIZE;  //PD13 -> Tmpr2
	Adc_Avg_Buffer[eTmpr1] = Adc_Sum_Buffer[eTmpr1]/ADC_SAMPLE_SIZE;  //PD14 -> Tmpr1
}
