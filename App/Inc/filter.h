/*File description: DC blocker and  LPF variables and structures definition
 *Functions used:
 *Reference document:
 */
#include "main.h"

typedef struct
{
	float xn;
	float yn;
}DCBlocker;

typedef struct
{
	float xn;
	float yn;
}LowPassFilter;

typedef struct
{
	float Id;
	float Iq;
	float Vd;
	float Vq;
	float Vout;
	float Iout;
	float Vr;
	float Vy;
	float Vb;
	float Ir;
	float Iy;
	float Ib;
	float VdcRef;
}AbsoluteVal_t;

#ifdef _FILTER_

  	LowPassFilter VdcLPF, SupFreqLPF = { 314, 314}, IdLPF, IqLPF, ILqLPF, VdLPF, VqLPF, VrefLPF, VoutLPF, IoutLPF, Ntc1LPF, Ntc2LPF; //Low Pass Filter
  	DCBlocker Vac_R_DCBlock, Vac_Y_DCBlock, Vac_B_DCBlock, Vac_E_DCBlock, Iac_R_DCBlock, Iac_Y_DCBlock, Iac_B_DCBlock; //DC Blockers
  	LowPassFilter vrRmsLPF,vyRmsLPF, vbRmsLPF, veRmsLPF, irRmsLPF, iyRmsLPF, ibRmsLPF;
  	AbsoluteVal_t absValues;
#else

  	extern LowPassFilter VdcLPF, SupFreqLPF, IdLPF, IqLPF, ILqLPF, VdLPF, VqLPF, VrefLPF, VoutLPF, IoutLPF, Ntc1LPF, Ntc2LPF; //Low Pass Filter
  	extern DCBlocker Vac_R_DCBlock, Vac_Y_DCBlock, Vac_B_DCBlock, Vac_E_DCBlock, Iac_R_DCBlock, Iac_Y_DCBlock, Iac_B_DCBlock; //DC Blockers
  	extern LowPassFilter vrRmsLPF,vyRmsLPF, vbRmsLPF, veRmsLPF, irRmsLPF, iyRmsLPF, ibRmsLPF;
  	extern AbsoluteVal_t absValues;
#endif
