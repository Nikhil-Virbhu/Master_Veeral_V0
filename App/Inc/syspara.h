/* File description: System parameters/ variables structure definition
 * Functions used:
 * Reference document:
*/
#include "main.h"

#define MAX_CELL 13

#ifndef _syspara_
enum Phase{R_PHASE,Y_PHASE,B_PHASE,E_PHASE};  //3 phase
enum NTC_ch{FEC,PSFB,TRAFO,DIODE};    //Temp channels

typedef struct
{
	float Vac_R;
	float Vac_Y;
	float Vac_B;
	float Vac_E;
	float Iac_R;
	float Iac_Y;
	float Iac_B;
}dcBlockerFactor;

typedef struct
{
	float Vout;
	float Iout;
	float Ntc1;
	float Ntc2;
	float Id;
	float Iq;
	float Vd;
	float Vq;
	float rmsCal;
}lpfFactor;

typedef struct
{
	float Gain;
	float Offset;
	float Slope;
	float corFac;
	float sensorGain;
	float boardGain;
}calFactor;

typedef struct
{
	float Vrated; //system rated voltage
	float Prated; //system rated Power
	float Irated; //system rated Current
	float Fsystem; //system frequency
	float Voutrated; // Rated output voltage
	float Ioutrated; // Rated output current

	float Kp_pll; //PID Kp constant for PLL
	float Ki_pll; //PID Ki constant for PLL
	float Kp_Vdc;  //PID Kp constant for Vdc
	float Ki_Vdc;  //PID Ki constant for Vdc
	float Kp_Id; //PID Kp constant for direct component of current
	float Ki_Id; //PID Ki constant for direct component of current
	float Kp_Iq; //PID Kp constant for quadrature component of current
	float Ki_Iq; //PID Ki constant for quadrature component of current
	float Kd_Id;// PID Kd constant
	float Kd_Iq; // PID Kq constant
	float Kd_Vd; // PID Vd constant

	float Freq_inner; //inner loop rate
	float OuterLoopSlowBy;

	float VdcRef;
	float Freq_FEC; //Front-End-Converter switching frequency
	float FECdeadband; //deadband value in uSecond for FEC
	float Freq_PSFB; //Phase-Shifted-Full-Bridge switching frequency
	float PSFBdeadband; //deadband value in uSecond for PSFB

	uint8_t CascadedCELL; //number of cascaded stages per phase
	uint8_t totalPhases; //single phase or three phase system
	float Vdc_rated; //Rated output voltage of converter
	float lineL;//line inductor value
	float Id_limit; //Saturation limit for Id
	float Iq_limit; //Saturation limit for Iq
	float Id_rate; //Id ramping rate
	float Iq_rate; //Iq ramping rate
	float Vd_rate; //Vd voltage ramping rate
	float Vq_rate; // Vq Voltage Rise Rate
	float Vdc_rate; // Vdc ramping rate
	float VMF_Vac; // AC voltage Sensor Gain
	float CMF_Iac; // AC current Sensor Gain
	float VMF_Vout; // Converter Output Voltage Sensor Gain
	float VMF_Vorec; // Rectifier Output Voltage Sensor Gain
	float CMF_Iout; // Converter Outuput CUrrent Sensor Gain

	float pll_uppersat;
	float pll_lowersat;
	float pllLockRange;
	float VdLimit;
	float VqLimit;
	float Vd_low_limit;
	float Vd_high_limit;
	float Vq_low_limit;
	float Vq_high_limit;
	dcBlockerFactor DcBlocker_factor;
	lpfFactor lpf_factor;
	calFactor calibration[12];
}configParameters;

typedef struct
{
	uint8_t f_dsat[8];
	uint8_t f_FEC_Vout;
	uint8_t f_FEC_Iout;
	uint8_t f_PSFB_Iout;
	uint8_t f_PSFB_Vout;
	uint8_t f_eeprom;
	uint8_t f_digiIN[2];
	uint8_t f_ucTemp;
}cellFaults;

typedef struct
{
	float FEC_Iin;
	float FEC_Iout;//Front-end converter DC Voltage
	float FEC_Vout;//MF Trafo AC Current
	float PSFB_Vout;//Converter Output DC Voltage
	float PSFB_Iout;//Converter Output DC Current
	float HsinkTemp[4];
}cellSignals;

typedef struct
{
	float Grid_V;//Grid AC Voltage
	float Grid_I;//Grid AC Current
	cellSignals cellSig[MAX_CELL];
	uint8_t slaveHealth[MAX_CELL];
}sysParameters;

#endif



