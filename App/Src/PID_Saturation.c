#define _PID_SAT_

#include "PID_Saturation.h"
/*File description: PID Saturation functions
 *Functions used:
 *Reference document:
 */

/*Function description: Function to initialise PID structure
 * Output - Updates the PID Structure that was sent as input */

void InitPIDStruct(PID_Structure* Temp){
	Temp->Error[present]=0;
	Temp->Error[previous]=0;
	Temp->Out[present]=0;
	Temp->Out[previous]=0;
	Temp->Integrator[0]=0;
	Temp->Integrator[1]=0;
}

/*Function description: Saturation function */
float SaturationFnc(float input ,float UpperSat, float LowerSat){
	if(input>=UpperSat){
		input=UpperSat;
	}else if(input<=LowerSat){
		input=LowerSat;}
	else{
	}
	return (input);
}

/*Function description: Function that calculates PID parameters and updates the same into the calling input structure
 * Output - Updates the PID Structure that was sent as input */
void Velocity_PID(PID_Structure *PIDtemp, float SamplingFreq, float KP, float KI, float UpperSat, float LowerSat){

	PIDtemp->Out[present]= PIDtemp->Out[previous] + (float)KP*(PIDtemp->Error[present]-PIDtemp->Error[previous])+(float)(KI*PIDtemp->Error[previous]/SamplingFreq);
	PIDtemp->Out[present]=SaturationFnc(PIDtemp->Out[present],UpperSat,LowerSat);
	PIDtemp->Out[previous]=PIDtemp->Out[present];
	PIDtemp->Error[previous]=PIDtemp->Error[present];
}


/*Function description: Function that provides soft start to the variables  */
void softStartVariable(softStart_Structure *Temp, float sampleFreq, float Positive_SlwRate, float Negative_SlwRate){
	float positiveStepSize=(float)Positive_SlwRate/sampleFreq;
	float negativeStepSize=(float)Negative_SlwRate/sampleFreq;

	if(Temp->Dynamic <= (Temp->Fix - positiveStepSize*2.0f)){
	Temp->Dynamic = Temp->Dynamic + positiveStepSize;
 }else if(Temp->Dynamic >= (Temp->Fix + negativeStepSize*2.0f)){
	Temp->Dynamic = Temp->Dynamic - negativeStepSize;
 }else {
	Temp->Dynamic = Temp->Fix;
 }
}


