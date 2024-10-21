//#include"pid.h"
#include "arm_math.h"
#define INC_PLL_H_
#include "pll.h"
#include "process.h"

/*File description: PLL output and SOGI functions
 *Functions used:
 *Reference document:
 */

/*Function description: Function to calculate PLL output which gives us the grid angle, omega */
void SRFPllOutput(SRFPLL_Structure *pll,float Qr, float Qy, float Qb, float system_frequency, float sampling_frequency
												,float Kp, float Ki, float UpperSat, float LowerSat)
{

		pll->Qd = (float)((2*Qr*arm_sin_f32(pll->GridAngle))/3.0f + (2*Qy*arm_sin_f32(pll->GridAngle - TWO_PI_BY_THREE))/3.0f
					+ (2*Qb*arm_sin_f32(pll->GridAngle - FOUR_PI_BY_THREE))/3.0f);
		pll->Qq = (float)((2*Qr*arm_cos_f32(pll->GridAngle))/3.0f + (2*Qy*arm_cos_f32(pll->GridAngle - TWO_PI_BY_THREE))/3.0f
					+ (2*Qb*arm_cos_f32(pll->GridAngle - FOUR_PI_BY_THREE))/3.0f);
		pll->Q0 = (Qr + Qy + Qb)/3.0f;

		/*
		 * Qd_lpf[0]-> Value of Vd before Low Pass Filter
		 * Qd_lpf[1] -> Value of Vd after Low Pass Filter
		 * Qq_lpf[0]-> Value of Vq before Low Pass Filter
		 * Qq_lpf[1] -> Value of Vq after Low Pass Filter
		 *
		 */

		Qd_lpf[0] = pll->Qd;
		Qd_lpf[1] = Qd_lpf[0] + ((float)ConfigPara.lpf_factor.Vd*(Qd_lpf[1]-Qd_lpf[0]));

		Qq_lpf[0] = pll->Qq;
		Qq_lpf[1] = Qq_lpf[0] + ((float)ConfigPara.lpf_factor.Vq*(Qq_lpf[1]-Qq_lpf[0]));

		pll->Q_PID.Error[present] = Qq_lpf[1];
		Velocity_PID(&(pll->Q_PID),sampling_frequency,Kp,Ki,UpperSat,LowerSat);

		/*
		 * The output of the PI controller will be the System Frequency.
		 * +Ve value of Frequency suggest the RYB Phase Sequence
		 * -Ve Value of Frequency Suggest the RBY Phase Sequence (Reverse Phase Sequence)
		 */
		pll->F_e = pll->Q_PID.Out[present];


		pll->omega = pll->F_e * 6.28571f;
		angle_integrator += (pll->omega/sampling_frequency);

		if (angle_integrator>= 6.28571f)
				angle_integrator = 0;
		else if(angle_integrator<=0)
				angle_integrator=6.28571f;
		pll->GridAngle = angle_integrator;
}

/*Function description: Arctan function which returns the angle (SOGI function)  */
float arctan2_Su(float b_,float a_){
	static float abs_y,r,angle_;

	abs_y=b_;
	if(abs_y<0){
		abs_y=-abs_y;
	}
	if(abs_y==0){
		if(a_>0){
			angle_=0;
		}else{
			angle_= PI;
		}
	}
	if(a_>=0){
		r=((a_-abs_y)/(a_+abs_y));
		angle_=((float)0.1963f*r*r*r)-(float)0.9817f*r + PI_By_4 ; //angle_=coeff_1-(coeff_1*r);
	}else{
		r=((a_+abs_y)/(abs_y-a_));
		angle_=((float)0.1963f*r*r*r)-(float)0.9817f*r + Coeff_sogi;//angle_=coeff_2-(coeff_1*r);
	}

	if(b_<0){
		return(-angle_);
	}else{
		return(angle_);
	}
}
