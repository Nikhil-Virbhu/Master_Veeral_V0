/* File description: PID Saturation variables and structures
 * Functions used:
 * Reference document:
*/
#include "main.h"
enum State_PID {present,previous};
typedef struct
{
	float Out[2];
	float Error[2];
	float Integrator[2];
	float saturation_error;
	float signal_error;
	float k_term;
	float i_term;
	float d_term;
}PID_Structure;

typedef struct{
	float Dynamic;
	float Fix;
}softStart_Structure;



#ifdef _PID_SAT_
	float ID_sat;
	float VD_sat, VQ_sat;
	softStart_Structure IDSat, IQRef, VdSat, VqSat, VoutRef, virtualResistorss;
	PID_Structure *PtrPID;
	float KP_Vdc=0.3, KI_Vdc=0.6;
	float KP_Vd=1.2, KI_Vd=1.2;
	float KP_Vq=2.3, KI_Vq=3;
	PID_Structure IDref,VDref,VQref;
	float SaturationFnc(float,float,float);
	void Velocity_PID(PID_Structure *PIDtemp, float SamplingFreq, float KP, float KI, float UpperSat, float LowerSat);
	void InitPIDStruct(PID_Structure*);
	void softStartVariable(softStart_Structure *Temp, float sampleFreq, float Positive_SlwRate, float Negative_SlwRate);
	float SaturationFunc(float value, float UpperSat, float LowerSat);

#else
	extern float ID_sat;
	extern float VD_sat, VQ_sat;
	extern float KP_Vdc, KI_Vdc;
	extern float KP_Vd, KI_Vd;
	extern float KP_Vq, KI_Vq;
	extern PID_Structure IDref,VDref,VQref;
	extern PID_Structure *PtrPID;
	extern softStart_Structure IDSat, IQRef, VdSat, VqSat, VoutRef, virtualResistorss;
	extern float SaturationFnc(float,float,float);
	extern void Velocity_PID(PID_Structure *PIDtemp, float SamplingFreq, float KP, float KI, float UpperSat, float LowerSat);
	extern void InitPIDStruct(PID_Structure*);
	extern void softStartVariable(softStart_Structure *Temp, float sampleFreq, float Positive_SlwRate, float Negative_SlwRate);
	extern float SaturationFunc(float value, float UpperSat, float LowerSat);

#endif
