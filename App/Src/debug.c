#define _DEBUG_H_
#include "debug.h"
#include "process.h"
#include "measurement.h"
#include "pll.h"
#include "usart.h"
#include "string.h"
#include "filter.h"


extern float lowpass_out;
extern float y_nld;
float multi = 1;

/*
 Debug parameters:
 		case(12):
				offset = 2048.0f;
				gain = 4096.0f / 100;
				out = IsSOGI.Alpha[0] * gain + offset;
		break;
		case(13):
				offset = 2048.0f;
				gain = 4096.0f / 100;
				out = IsSOGI.Beta[0] * gain + offset;
		break;
		case(14):
				offset = 50;
				gain = 4096.0f/(offset * 2);
				out = (Vd[1] + offset) * gain;
		break;
		case(15):
				offset = 50;
				gain = 4096.0f/(offset * 2);
				out = (Vq[1] + offset) * gain;
		break;
		case(16):
				offset = 20;
				gain = 4096.0f/(offset * 2);
				out = (Id[1] + offset) * gain;
		break;
		case(17):
				offset = 20;
				gain = 4096.0f/(offset * 2);
				out = (Iq[1] + offset) * gain;
		break;
		case(18):
				offset = 100;
				gain = 4096.0f/(offset * 2);
				out = (Vd_cmd + offset) * gain;
		break;
		case(19):
				offset = 100;
				gain = 4096.0f/(offset * 2);
				out = (Vq_cmd + offset) * gain;
		break;
		case(20):
				offset = 5;
				gain = 4096.0f/(offset * 2);
				out = (VsSRF.F_e - 50 + offset) * gain;
		break;
 */


uint32_t DAC_update(uint8_t signal)
{
	float out,gain,offset;
	switch(signal)
	{
		case(1):
			offset = 2048.0f;
			gain = multi * VphBase/(ConfigPara.calibration[eVAC_R].Gain * ConfigPara.calibration[eVAC_R].corFac);
			//gain =0.2;
			out = VAC_R[rawValue]  * gain + offset;
		break;
		case(2):
			offset = 2048.0f;
			gain = multi * VphBase/(ConfigPara.calibration[eVAC_Y].Gain * ConfigPara.calibration[eVAC_Y].corFac);
			out = VAC_Y[procValue] * gain + offset;
		break;

		case(3):
			offset = 2048.0f;
			gain = multi * VphBase/(ConfigPara.calibration[eVAC_B].Gain * ConfigPara.calibration[eVAC_B].corFac);
			out = VAC_B[procValue] * gain + offset;
		break;

		case(4):
			offset = 0;
			gain = 4096.0f/6.28f;
			out = GridAngle * gain + offset;
		break;

		case(5):
			offset = 2048.0f;
			gain = multi * IphBase/(ConfigPara.calibration[eIAC_R].Gain * ConfigPara.calibration[eIAC_R].corFac);
			out = IAC_R[procValue] * gain + offset;
		break;

		case(6):
			offset = 2048.0f;
			gain = multi * IphBase/(ConfigPara.calibration[eIAC_Y].Gain * ConfigPara.calibration[eIAC_Y].corFac);
			out = IAC_Y[procValue] * gain + offset;
		break;

		case(7):
			offset = 2048.0f;
			gain = multi * IphBase/(ConfigPara.calibration[eIAC_B].Gain * ConfigPara.calibration[eIAC_B].corFac);
			out = IAC_B[procValue] * gain + offset;
		break;

		case(8):
			offset = 0;
			gain = 4096.0f / SlaveARR;
			out = Vr_cmd * 1;
		break;

		case(9):
			offset = 0;
			gain= 4096.0f / SlaveARR;
			out = Vy_cmd * 1;
		break;
		case(10):
			offset = 0;
			gain= 4096.0f / SlaveARR;
			out = Vb_cmd * 1;
		break;
		case (11):
				offset =0;
				gain = 20;
				out =Vr_cmd;
		break;
		case (12):
				offset =0;
				gain = 20;
				out =Vq[procValue]*gain;
		break;
		case(13):
				out = (float)(V_OUT[procValue]*VoutBase)*4096.0f/1000.0f;//Adc_Avg_Buffer[eV_OUT] * 0.2;
				break;
		case(14):
			offset = 2048.0f;
			gain = multi * VphBase/(ConfigPara.calibration[eVAC_Y].Gain * ConfigPara.calibration[eVAC_Y].corFac);
			out = lowpass_out * gain + offset;
		break;
		case(15):
				offset = 2048.0f;
		gain = multi * VphBase/(ConfigPara.calibration[eVAC_Y].Gain * ConfigPara.calibration[eVAC_Y].corFac);
		out = y_nld * gain + offset;
		break;

		case (16):
			out = (uint16_t)V_cmd*0.1;

		default:
			offset = 0;
			gain = 4096.0f;
			out = 0;
		break;

	}
	return (uint32_t) out;
}

/*Function description: DAC_Out to see the Analog output of DAC (waveform) on DSO. */
void DAC_Out(void)
{
	dac1=8;
	dac2=8;

	dac1_data = DAC_update(dac1);
	dac2_data = DAC_update(dac2);

	HAL_DAC_SetValue(&hdac1, DAC_CHANNEL_1, DAC_ALIGN_12B_R,  dac1_data);
	HAL_DAC_SetValue(&hdac1, DAC_CHANNEL_2, DAC_ALIGN_12B_R,  dac2_data);
//	HAL_DAC_SetValue(&hdac1, DAC_CHANNEL_1, DAC_ALIGN_12B_R, (uint32_t) 2048);
//	HAL_DAC_SetValue(&hdac1, DAC_CHANNEL_2, DAC_ALIGN_12B_R, (uint32_t) 4000);
}

