
/* File description: SOGI structure and PLL definitions
 * Functions used:
 * Reference document:
*/

#include "main.h"
#include "PID_Saturation.h"

#define PI_By_4 (float)0.785398f
//#define PI (float)3.14f
#define Coeff_sogi (float)2.356194f
#define ONE_By_Root_THREE (float)0.57735f
#define TWO_PI (float)6.28

typedef struct
{
	float Qd;
	float Qq;
	float Q0;
	float GridAngle;
	float F_e;
	float omega;
	PID_Structure Q_PID;
}SRFPLL_Structure;

#ifdef INC_PLL_H_
	float angle_integrator;
	float Qd_lpf[2],Qq_lpf[2];
	void SRFPllOutput(SRFPLL_Structure *pll,float Qr, float Qy, float Qb, float system_frequency, float sampling_frequency
													,float Kp, float Ki, float UpperSat, float LowerSat);
	SRFPLL_Structure VsSRF;
	float arctan2_Su(float,float);
#else
	extern float angle_integrator;
	extern void SRFPllOutput(SRFPLL_Structure *pll,float Qr, float Qy, float Qb, float system_frequency, float sampling_frequency
														,float Kp, float Ki, float UpperSat, float LowerSat);
	extern float Qd_lpf[2],Qq_lpf[2];
	extern SRFPLL_Structure VsSRF;
	extern float arctan2_Su(float,float);
#endif /* INC_PLL_H_ */


