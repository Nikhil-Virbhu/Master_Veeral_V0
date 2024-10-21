/*
 * Implementation file for: bandpass filter
 * Generated with         : PLECS 4.7.5
 * Generated on           : 31 Jan 2024 14:21:35
 */
#include "bandpass_filter.h"
#include "main.h"
#include"process.h"


//coefficients for 50Hz notch filter with Q factor 10
float b0  = 0.98453371f;
float b1  = -1.8726944f;
float b2  = 0.98453371f;
float a1  = -1.8726944f;
float a2  =   0.96906742f;




float xn;
float xn_prev;
float xn_prev_prev;
float xn_prev_prev_prev;

float Yn;
float Yn_prev;
float Yn_prev_prev;
float Yn_prev_prev_prev;

 float lowpass_out;




void lowpass_filter(void){
	xn= VAC_R[rawValue];
	xn_prev =xn;
	xn_prev_prev = xn_prev;
	xn_prev_prev_prev = xn_prev_prev;

	Yn = (xn*b0) + (xn_prev*b1) + (xn_prev_prev*b2) - (Yn_prev*a1) - (Yn_prev_prev*a2);

	Yn_prev = Yn;
	Yn_prev_prev = Yn_prev;
	lowpass_out = Yn;
}

