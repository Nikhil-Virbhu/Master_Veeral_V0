#define _PROCESS_
//#define _SOGI_
//#define InverterTest
#define PLLreadyProtection

#define PU_SYSTEM
#define DynamicVdcwithVac
#define _FILTER_
#include "main.h"
#include "process.h"
#include "filter.h"
#include "Pll.h"
#include "measurement.h"
#include "arm_math.h"
#include "dac.h"
#include "debug.h"
#include "hrtim.h"
#include "ntc_measurement.h"
#include "protection.h"
#include"io.h"
#include"CAN1_Transmitting.h"
#include "Slave_Monitoring.h"
#include "interface.h"
#include "sequence.h"

#include "Kalman.h"
/*
 * Function description: Low priority timer for Round robin algorithm (1 kHz)
 * Input : none
 * Output : none
*/
uint8_t DC_con_flag=0;

float Vout_temp=0;
uint8_t test_mode_count=0;
float mod_index = 0.8;
uint32_t timer_period;

float R_sine_wave[100] = {
		0,							0.06279052,		0.125333234,		0.187381315,		0.248689887,		0.309016994,		0.368124553,		0.425779292,		0.481753674,		0.535826795,
		0.587785252,		0.63742399,		0.684547106,		0.728968627,		0.770513243,		0.809016994,		0.844327926,		0.87630668,		0.904827052,		0.929776486,
		0.951056516,		0.968583161,		0.982287251,		0.992114701,		0.998026728,		1,							0.998026728,		0.992114701,		0.982287251,		0.968583161,
		0.951056516,		0.929776486,		0.904827052,		0.87630668,		0.844327926,		0.809016994,		0.770513243,		0.728968627,		0.684547106,		0.63742399,
		0.587785252,		0.535826795,		0.481753674,		0.425779292,		0.368124553,		0.309016994,		0.248689887,		0.187381315,		0.125333234,		0.06279052,
		0,							-0.06279052,		-0.125333234,		-0.187381315,		-0.248689887,		-0.309016994,		-0.368124553,		-0.425779292,		-0.481753674,		-0.535826795,
		-0.587785252,		-0.63742399,		-0.684547106,		-0.728968627,		-0.770513243,		-0.809016994,		-0.844327926,		-0.87630668,		-0.904827052,		-0.929776486,
		-0.951056516,		-0.968583161,		-0.982287251,		-0.992114701,		-0.998026728,		-1,						-0.998026728,		-0.992114701,		-0.982287251,		-0.968583161,
		-0.951056516,		-0.929776486,		-0.904827052,		-0.87630668,		-0.844327926,		-0.809016994,		-0.770513243,		-0.728968627,		-0.684547106,		-0.63742399,
		-0.587785252,		-0.535826795,		-0.481753674,		-0.425779292,		-0.368124553,		-0.309016994,		-0.248689887,		-0.187381315,		-0.125333234,		-0.06279052

		};

void TIM6_Execution(void){
	//HAL_GPIO_TogglePin(LED1_GPIO_Port,LED1_Pin);

	CNT_TIM6++; // Increment at every 1 mSec
	mSec1_Flag=1; // Every 1 mSec

	if (CNT_TIM6%40==0){
		mSec40_Flag=1; // Every 40 mSec
	}
	if (CNT_TIM6%100==0){
		mSec100_Flag=1; // Every 100 mSec
	}
	if(CNT_TIM6%250 == 0){
		mSec250_Flag = 1;
	}
	if(CNT_TIM6%500 == 0){
		mSec500_Flag = 1;
	}
	if (CNT_TIM6%1000==0){
		Sec1_Flag=1; // Every 1 Sec
		CNT_TIM6 = 0;
		/*
		 * This function is temparary arrangement for Testing. It serves the purpose that in change of Vg the value of Vdcref INcreases.
		 */
		#ifdef DynamicVdcwithVac
			// This line is written to increase the DC-Out Reference Dynamically with Change in Grid-SUpply (It is just for testing Purpose only)
		//	if (Turn_ONOFF_Flag==1){
//			VoutRef.Fix=((float)Vd[procValue]/1.41f)*1.17f*1.08f*boost_factor* VphBase / VoutBase;
		//	}
		#endif
	}
}

/*
 * Function description: High priority function for control algorithm and parameter calculations (5000 Hz)
 * Input : none
 * Output : none
*/
void TIM7_Execution(void){
	//HAL_GPIO_TogglePin(U_DB2_GPIO_Port, U_DB2_Pin);

	//TODO: change the contactor operation to a slower speed function
	// no need to operate contactor in 200us routine
	/* DC contactor manual test */

	DC_con_flag = DC_CONTACTOR_TEST;
	if (DC_CONTACTOR_TEST ==0){
		DC_CONTACTOR_TEST_CLOSE_IND;
		if (DC_CONTACTOR_TEST_CLOSE ==0){
		dc_contactor_close_flag =1;

	}
		else{
			dc_contactor_open_flag = 1;
		}
		DC_CONTACTOR_TEST_OPEN_IND;
	}

	// All the parameters are calculated in this function. It execute all Irrespective of Fault conditions
	Parameter_Calculations();

	VdFeedForward= Vd[procValue]+2.0f;
	VqFeedForward=Vq[procValue];

	/*
	 * Turn_ONFF_Flag=1-> Control System in Master is active
	 * Turn_ONFF_Flag=1 -> Control System in Master is inactive
	 * This is set when all PSFB starts Successfully and Status is received from all the Slave.
	 * It is set in checkPsfbStatus() function in SlaveMonitoring.C file
	*/
	Turn_ONOFF_Flag=1;
	if (Turn_ONOFF_Flag==1){


		softStartVariable(&IDSat,ConfigPara.Freq_inner,ConfigPara.Id_rate,ConfigPara.Id_rate);
		softStartVariable(&VdSat,ConfigPara.Freq_inner,(float)ConfigPara.Vd_rate,(float)ConfigPara.Vd_rate);
		softStartVariable(&VqSat,ConfigPara.Freq_inner,(float)ConfigPara.Vq_rate,(float)ConfigPara.Vq_rate);
		/* IQRef.Fix should be varied to vary Reactive Current. */
		//softStartVariable(&IQRef,ConfigPara.Freq_inner,ConfigPara.Iq_rate,ConfigPara.Iq_rate);

		OuterLoopCNT++; // Outer PI Controllers. To make outer loop slow by "OuterLoopSlowBy(=10 is set)" Value
		if(OuterLoopCNT>=ConfigPara.OuterLoopSlowBy){
			softStartVariable(&VoutRef,(float)ConfigPara.Freq_inner/ConfigPara.OuterLoopSlowBy,(float)ConfigPara.Vdc_rate,(float)ConfigPara.Vdc_rate);
			OuterLoopCNT=1;

			//DC voltage control loop
			IDref.Error[present]=(float)(VoutRef.Dynamic-V_OUT[procValue]);
			//Velocity_PID(&IDref,(float)ConfigPara.Freq_inner/ConfigPara.OuterLoopSlowBy,ConfigPara.Kp_Vdc,ConfigPara.Ki_Vdc, IDSat.Dynamic,-IDSat.Dynamic);


			if(IDref.Error[present] > 0.01 || IDref.Error[present] <-0.01){
			IDref.k_term 	= (float)ConfigPara.Kp_Vdc*(IDref.Error[present]);
						IDref.i_term  	= 	(float)(ConfigPara.Ki_Vdc*IDref.Error[present]*0.0002f);
						IDref.Integrator[present] = IDref.Integrator[present] + IDref.i_term;
						IDref.Integrator[present] = SaturationFnc(IDref.Integrator[present],IDSat.Dynamic,-IDSat.Dynamic);
						IDref.d_term = 	ConfigPara.Kd_Vd * ((IDref.Error[present]-IDref.Error[previous])/0.0002f);
						IDref.d_term = SaturationFnc(IDref.Out[present],IDSat.Dynamic,-IDSat.Dynamic);

						IDref.Out[present] =  IDref.k_term + IDref.Integrator[present];//+IDref.d_term ;
						IDref.Out[present]=SaturationFnc(IDref.Out[present],IDSat.Dynamic,-IDSat.Dynamic);
						IDref.Out[previous]=IDref.Out[present];
						IDref.Error[previous]=IDref.Error[present];
			}

			else{
				IDref.Error[present] = 0;
			}

			//check if the pid output is saturated
			if((IDref.Out[present] >= IDSat.Dynamic) || (IDref.Out[present] <= -IDSat.Dynamic))
			{
				vout_pid_saturated = 1;
			}
			else{
				vout_pid_saturated = 0;
			}
		}
		//IDref.Out[present] = 3.0f;
		//ID control loop
		VDref.Error[present]=(float)(IDref.Out[present]-Id[procValue]);
		//Velocity_PID(&VDref,(float)ConfigPara.Freq_inner,ConfigPara.Kp_Id,ConfigPara.Ki_Id, VdSat.Dynamic,-VdSat.Dynamic);

		if(VDref.Error[present]> 0.01 || VDref.Error[present]<-0.01)
		{
				VDref.k_term 	= ConfigPara.Kp_Id * VDref.Error[present];
				VDref.i_term  	= 	ConfigPara.Ki_Id * VDref.Error[present]*0.0002f;
				VDref.Integrator[present] = VDref.Integrator[present] + VDref.i_term;
				VDref.Integrator[present] = SaturationFnc(VDref.Integrator[present],VdSat.Dynamic,-VdSat.Dynamic);
				VDref.d_term		= ConfigPara.Kd_Id * ((VDref.Error[present]-VDref.Error[previous])/0.0002f) ;
				VDref.d_term		= SaturationFnc(VDref.d_term,VdSat.Dynamic,-VdSat.Dynamic);

				VDref.Out[present] =  VDref.k_term + VDref.Integrator[present] + VDref.d_term;
				VDref.Out[present]=SaturationFnc(VDref.Out[present],VdSat.Dynamic,-VdSat.Dynamic);
				VDref.Out[previous]=VDref.Out[present];
				VDref.Error[previous]=VDref.Error[present];
	}
				else{
					VDref.Error[present] = 0;
				}

		//check if the pid output is saturated
		if((VDref.Out[present] >= VdSat.Dynamic) || (VDref.Out[present] <= -VdSat.Dynamic))
		{
			id_pid_saturated = 1;
		}
		else{
			id_pid_saturated = 0;
		}

		//IQ control Innerloop
		VQref.Error[present]=(float)(IQRef.Dynamic-Iq[procValue]);
		//Velocity_PID(&VQref,(float)ConfigPara.Freq_inner,ConfigPara.Kp_Iq ,ConfigPara.Ki_Iq,VqSat.Dynamic,-VqSat.Dynamic);
		if(VQref.Error[present]> 0.01 || VQref.Error[present]<-0.01)
				{

				VQref.k_term 	= ConfigPara.Kp_Iq * VQref.Error[present];
				VQref.i_term  	= 	ConfigPara.Ki_Iq * VQref.Error[present]*0.0002f;
				VQref.Integrator[present] = VQref.Integrator[present] + VQref.i_term;
				VQref.Integrator[present] = SaturationFnc(VQref.Integrator[present],VqSat.Dynamic,-VqSat.Dynamic);
				VQref.d_term = 	ConfigPara.Kd_Iq * ((VQref.Error[present]-VQref.Error[previous])/0.0002f);
				VQref.d_term = SaturationFnc(VQref.d_term,VqSat.Dynamic,-VqSat.Dynamic);

				VQref.Out[present] =  VQref.k_term + VQref.Integrator[present]+VQref.d_term ;
				VQref.Out[present]=SaturationFnc(VQref.Out[present],VqSat.Dynamic,-VqSat.Dynamic);
				VQref.Out[previous]=VQref.Out[present];
				VQref.Error[previous]=VQref.Error[present];
				}
					else{
							VQref.Error[present] = 0;
						}


		//check if the pid output is saturated
		if((VQref.Out[present] >= VqSat.Dynamic) || (VQref.Out[present] <= -VqSat.Dynamic))
		{
			iq_pid_saturated = 1;
		}
		else{
			iq_pid_saturated = 0;
		}

		/*VoutRef.Fix is in PU Value.
		 * First it converted in the Absolute value.
		 * And then it is converter in Vphase Base for division with Vd PU
		 * */

		TempVdc_Bus_Divide=VoutRef.Fix*VoutBase/VphBase;

		// 100 is multiplied in the below equation to convert it in Percentage
		Vd_cmd=(float) ((VdFeedForward)-VDref.Out[present])*100/TempVdc_Bus_Divide; // it should be change when used at time of PU system or other voltage run
		Vq_cmd=(float) ((VqFeedForward)-VQref.Out[present])*100/TempVdc_Bus_Divide;

		Vd_cmd=SaturationFnc(Vd_cmd,200, -200);
		Vq_cmd=SaturationFnc(Vq_cmd,200, -200);

		//inverse transformation from Clarke and Park
		Vr_cmd=(float)((Vd_cmd*arm_sin_f32(GridAngle)+ Vq_cmd*arm_cos_f32(GridAngle))*10.0f + 2000.0f);
		Vy_cmd=(float)((Vd_cmd*arm_sin_f32(GridAngle-TWO_PI_BY_THREE) + Vq_cmd*arm_cos_f32(GridAngle-TWO_PI_BY_THREE))*10.0f + 2000.0f);
		Vb_cmd=(float)((Vd_cmd*arm_sin_f32(GridAngle-FOUR_PI_BY_THREE) + Vq_cmd*arm_cos_f32(GridAngle-FOUR_PI_BY_THREE))*10.0f + 2000.0f);

			#ifdef InverterTest
				Vr_cmd= ((float) Ma*arm_sin_f32((float)314.159f*n_spwm/(float)ConfigPara.Freq_inner)) ; // 0.5 + ma* 0.5 sin (2*pi*f*n*Ts)
				Vy_cmd=  ((float)Ma*arm_sin_f32((float)(314.159f*n_spwm/(float)ConfigPara.Freq_inner)-2.0943f));
				Vb_cmd= ((float)Ma*arm_sin_f32((float)(314.159f*n_spwm/(float)ConfigPara.Freq_inner)-4.1887f)) ;
				Vr_cmd = (Vr_cmd * 1000) + 2000 ;
				Vy_cmd = (Vy_cmd * 1000) + 2000;
				Vb_cmd = (Vb_cmd * 1000) + 2000;
				n_spwm=n_spwm+1;
				if(n_spwm > ((float)ConfigPara.Freq_inner/50.0f - 1))
				   n_spwm=0;
			#endif
			Vr_cmd = SaturationFnc(Vr_cmd, 4000, 0);
			Vy_cmd = SaturationFnc(Vy_cmd, 4000, 0);
			Vb_cmd = SaturationFnc(Vb_cmd, 4000, 0);
			//HAL_HRTIM_Init(&hhrtim1);

			                    test_mode_count++;
								if(test_mode_count>=100)
								{
									test_mode_count =0;
								}
								timer_period = HRTIM1->sTimerxRegs[HRTIM_TIMERINDEX_TIMER_B].PERxR;

								V_cmd = (R_sine_wave[test_mode_count]* mod_index+1) * (timer_period/2) ;
								//HAL_DAC_SetValue(&hdac1, DAC_CHANNEL_1, DAC_ALIGN_12B_R, V_cmd*0.1);

								HRTIM1->sTimerxRegs[HRTIM_TIMERINDEX_TIMER_A].CMP3xR = V_cmd;
								HRTIM1->sTimerxRegs[HRTIM_TIMERINDEX_TIMER_B].CMP3xR = V_cmd;
								//HRTIM1->sTimerxRegs[HRTIM_TIMERINDEX_TIMER_A].CMP3xR = (uint16_t)(((float) V_cmd * HRTIM1->sTimerxRegs[HRTIM_TIMERINDEX_TIMER_A].PERxR  + (float) HRTIM1->sTimerxRegs[HRTIM_TIMERINDEX_TIMER_A].PERxR) * 0.5f) ;
										//HRTIM1->sTimerxRegs[HRTIM_TIMERINDEX_TIMER_B].CMP3xR = (uint16_t)(((float)(- V_cmd) * HRTIM1->sTimerxRegs[HRTIM_TIMERINDEX_TIMER_B].PERxR + (float) HRTIM1->sTimerxRegs[HRTIM_TIMERINDEX_TIMER_B].PERxR) * 0.5f);

			/*HAL_HRTIM_WaveformCounterStart(&hhrtim1, HRTIM_TIMERID_MASTER + HRTIM_TIMERID_TIMER_A + HRTIM_TIMERID_TIMER_B );*/
			//HRTIM1->sTimerxRegs[HRTIM_TIMERINDEX_TIMER_A].CMP3xR = (uint16_t)V_cmd*HRTIM1->sTimerxRegs[HRTIM_TIMERINDEX_TIMER_A].PERxR+(float) (HRTIM1->sTimerxRegs[HRTIM_TIMERINDEX_TIMER_B].PERxR* 0.5f);
		   //HRTIM1->sTimerxRegs[HRTIM_TIMERINDEX_TIMER_B].CMP3xR = (uint16_t)(V_cmd)*HRTIM1->sTimerxRegs[HRTIM_TIMERINDEX_TIMER_A].PERxR+(float) (HRTIM1->sTimerxRegs[HRTIM_TIMERINDEX_TIMER_B].PERxR* 0.5f);

		   /* HAL_HRTIM_WaveformOutputStart(&hhrtim1, HRTIM_OUTPUT_TA1 | HRTIM_OUTPUT_TB1);
			API_CAN_Duty_RYB((uint16_t)Vr_cmd,(uint16_t)Vy_cmd,(uint16_t)Vb_cmd,cmd.byte);*/
	}
	else {
		API_CAN_Duty_RYB(Vr_cmd,Vy_cmd,Vb_cmd,cmd.byte);
	}
}

/*
 * Function description: Initializes the code with factory parameters of ratings, limits, gains and factors
 * Input : none
 * Output : none
*/
void paraInit(void)
{
	ConfigPara.Vdc_rate = 300.0f/5.0f;
	// We must change the rated to the nominal notation for future use
	ConfigPara.Vrated=415*1.73; // Line to Line RMS
	ConfigPara.Prated=50000;
	ConfigPara.Irated=ConfigPara.Prated/(1.73f*ConfigPara.Vrated); //system rated Current (RMS)
	ConfigPara.Fsystem = 50;
	ConfigPara.Voutrated=1000;
	ConfigPara.Ioutrated=ConfigPara.Prated/ConfigPara.Voutrated;

	// PI Values for PLL
	ConfigPara.Kp_pll=10; //PID Kp constant for PLL
	ConfigPara.Ki_pll=20; //PID Ki constant for PLL

	ConfigPara.pllLockRange = 4; //This shows the Different value of frequency from the System Frequnecy. Check PLL Function

	ConfigPara.pll_uppersat = ConfigPara.Fsystem + 10; // Upper and lower saturation values of pll
	ConfigPara.pll_lowersat = -(ConfigPara.Fsystem + 10);

	// InnerLoop Sampling Frequency and Outer Loop Slowing Rate
	ConfigPara.Freq_inner=5000.0f; //inner loop rate
	ConfigPara.OuterLoopSlowBy=1.0f;

	ConfigPara.CascadedCELL=1; //number of cascaded stages per phase
	ConfigPara.totalPhases=3; //single phase or three phase system

	ConfigPara.lineL=20.0f/1000.0f;//line inductor value

 	// Gain settings for AC quantities
	ConfigPara.calibration[eVAC_R].sensorGain = PT_RATIO ;
	ConfigPara.calibration[eVAC_R].boardGain = 0.5; //this factor was decided during calibration
	ConfigPara.calibration[eVAC_R].Gain = ConfigPara.calibration[eVAC_R].sensorGain * ConfigPara.calibration[eVAC_R].boardGain * ADC_RESOLUTION;
	ConfigPara.calibration[eVAC_R].corFac = 6.1939;
	ConfigPara.calibration[eVAC_R].Offset = 0.009862;
	ConfigPara.calibration[eVAC_Y].sensorGain = PT_RATIO ;
	ConfigPara.calibration[eVAC_Y].boardGain = 0.5;//16.11*0.85; //this factor was decided during calibration
	ConfigPara.calibration[eVAC_Y].Gain = ConfigPara.calibration[eVAC_Y].sensorGain * ConfigPara.calibration[eVAC_Y].boardGain * ADC_RESOLUTION;
	ConfigPara.calibration[eVAC_Y].corFac = 5.9039;
	ConfigPara.calibration[eVAC_Y].Offset = 0.009862;
	ConfigPara.calibration[eVAC_B].sensorGain = PT_RATIO;
	ConfigPara.calibration[eVAC_B].boardGain = 0.5;//16.11*0.85; //this factor was decided during calibration
	ConfigPara.calibration[eVAC_B].Gain = ConfigPara.calibration[eVAC_B].sensorGain * ConfigPara.calibration[eVAC_B].boardGain * ADC_RESOLUTION;
	ConfigPara.calibration[eVAC_B].corFac =6.0639;
	ConfigPara.calibration[eVAC_B].Offset =0.009862;

	ConfigPara.calibration[eVAC_E].sensorGain = PT_RATIO;
	ConfigPara.calibration[eVAC_E].boardGain = 16.1;//8.44f;// 14.06
	ConfigPara.calibration[eVAC_E].Gain = ConfigPara.calibration[eVAC_E].sensorGain * ConfigPara.calibration[eVAC_E].boardGain * ADC_RESOLUTION;
	ConfigPara.calibration[eVAC_E].corFac = 1;
	ConfigPara.calibration[eIAC_R].sensorGain = CT_RATIO ;
	ConfigPara.calibration[eIAC_R].boardGain = (float)(0.5f/R_BURDEN)*4.2;//this factor was decided during calibration
	ConfigPara.calibration[eIAC_R].Gain = ConfigPara.calibration[eIAC_R].sensorGain * ConfigPara.calibration[eIAC_R].boardGain * ADC_RESOLUTION;
	ConfigPara.calibration[eIAC_R].corFac = 1;//0.87f;
	ConfigPara.calibration[eIAC_Y].sensorGain = CT_RATIO;
	ConfigPara.calibration[eIAC_Y].boardGain = (float)(0.5f/R_BURDEN)*4.2;//this factor was decided during calibration
	ConfigPara.calibration[eIAC_Y].Gain = ConfigPara.calibration[eIAC_Y].sensorGain * ConfigPara.calibration[eIAC_Y].boardGain * ADC_RESOLUTION;
	ConfigPara.calibration[eIAC_Y].corFac = 1;//0.87f;
	ConfigPara.calibration[eIAC_B].sensorGain = CT_RATIO;
	ConfigPara.calibration[eIAC_B].boardGain = (float)(0.5f/R_BURDEN)*4.2;//this factor was decided during calibration
	ConfigPara.calibration[eIAC_B].Gain = ConfigPara.calibration[eIAC_B].sensorGain * ConfigPara.calibration[eIAC_B].boardGain * ADC_RESOLUTION;
	ConfigPara.calibration[eIAC_B].corFac = 1;//0.94f;


	// Gain settings for DC quantities
	ConfigPara.calibration[eV_OUT].Slope = 369.36f;
	ConfigPara.calibration[eV_OUT].Offset = 19.224f;
	ConfigPara.calibration[eV_OUT].boardGain = 1.0f;
	ConfigPara.calibration[eV_OUT].sensorGain = 1.0f;
	ConfigPara.calibration[eV_OUT].Gain = ConfigPara.calibration[eV_OUT].boardGain * ConfigPara.calibration[eV_OUT].sensorGain * ADC_RESOLUTION;
	ConfigPara.calibration[eV_OUT].corFac = 1;

	ConfigPara.calibration[eI_OUT].Slope = 30.0f/3.3f;
	ConfigPara.calibration[eI_OUT].Offset = 0;
	ConfigPara.calibration[eI_OUT].boardGain = 4.65148f;
	ConfigPara.calibration[eI_OUT].sensorGain = 1;
	ConfigPara.calibration[eI_OUT].Gain = ConfigPara.calibration[eI_OUT].boardGain * ConfigPara.calibration[eI_OUT].sensorGain * ADC_RESOLUTION;
	ConfigPara.calibration[eI_OUT].corFac = 1;

	ConfigPara.calibration[eTmpr1].Slope = 3066.0361f;
	ConfigPara.calibration[eTmpr1].Offset = 77.7927f;
	ConfigPara.calibration[eTmpr1].corFac = 1;
	ConfigPara.calibration[eTmpr2].Slope = 3066.0361f;
	ConfigPara.calibration[eTmpr2].Offset = 77.7927f;
	ConfigPara.calibration[eTmpr2].corFac = 1;

	ConfigPara.DcBlocker_factor.Iac_R=0.998f;
	ConfigPara.DcBlocker_factor.Iac_Y=0.998f;
	ConfigPara.DcBlocker_factor.Iac_B=0.998f;
	ConfigPara.DcBlocker_factor.Vac_R=0.998f;
	ConfigPara.DcBlocker_factor.Vac_Y=0.998f;
	ConfigPara.DcBlocker_factor.Vac_B=0.998f;
	ConfigPara.DcBlocker_factor.Vac_E=0.998f;

	ConfigPara.lpf_factor.Iout=0.995f;
	ConfigPara.lpf_factor.Vout=0.998f;//0.920f;
	ConfigPara.lpf_factor.Ntc1=0.995f;
	ConfigPara.lpf_factor.Ntc2=0.995f;


	ConfigPara.lpf_factor.Vd=0.998f;//0.820f;
	ConfigPara.lpf_factor.rmsCal = 0.8f;

	StartTime_ParameterInit();

}

/*
 * Function description: Samples the PLL function (SRF or SOGI) at the Sampling frequency
 * Input : Sampling Frequency
 * Output : Updates global variables of Grid Angle, DQ parameters and also highlights if the PLL is stable and changes gains on that basis
*/
void pllSample(float sampling_freq)
{
		SRFPllOutput(&VsSRF, VAC_R[procValue], VAC_Y[procValue], VAC_B[procValue], ConfigPara.Fsystem, sampling_freq, ConfigPara.Kp_pll, ConfigPara.Ki_pll, ConfigPara.pll_uppersat, ConfigPara.pll_lowersat);
		GridAngle = VsSRF.GridAngle;
		//GridAngle=341.0f;
		if(VsSRF.F_e<0)
			SupFreqLPF.xn=-VsSRF.F_e;
		else
			SupFreqLPF.xn = (VsSRF.F_e);
		/*
	 *To reduce the indipendancy of the code with respect to the number of cell cascaded
	 */
		Vd[rawValue] = VsSRF.Qd / ConfigPara.CascadedCELL;
		Vq[rawValue] = VsSRF.Qq / ConfigPara.CascadedCELL;
		V0 = VsSRF.Q0/ConfigPara.CascadedCELL;

		SupFreqLPF.yn= SupFreqLPF.xn +(0.998f*(SupFreqLPF.yn-SupFreqLPF.xn));

	if ((SupFreqLPF.yn > (ConfigPara.Fsystem - ConfigPara.pllLockRange)) && (SupFreqLPF.yn < (ConfigPara.Fsystem + ConfigPara.pllLockRange)))
	{
		pllReady = 1;
		ConfigPara.Kp_pll=2; //PID Kp constant for PLL 1
		ConfigPara.Ki_pll=3; //PID Ki constant for PLL 2
		ConfigPara.lpf_factor.Vq=0.998f; // Stiff Filtering for better performance in Steady-State.
	}
	else
	{
		pllReady = 0;
		ConfigPara.Kp_pll=5; //PID Kp constant for PLL 10
		ConfigPara.Ki_pll=7; //PID Ki constant for PLL 20
		ConfigPara.lpf_factor.Vq=0.92f; // Low value of Filtering is required to have faster settling when power ON.
	}

}

/*
 * Function description: Updates the value of parameters before System is ON and after system is OFF
 * Input : None
 * Output : None
*/
void StartTime_ParameterInit(void)
{

	/* PU Saturation values of Id and Iq */
	ConfigPara.Id_limit=500;
	ConfigPara.Iq_limit=500;

	/* PU Ramping rates of IDSat and IQRef soft start variables which updates in inner loop */
	ConfigPara.Id_rate=100.0f/10.0f;
	ConfigPara.Iq_rate=100.0f/10.0f;

	/* PU Ramping rates of VdSat and VqSat soft start variables which updates in inner loop */
	ConfigPara.Vd_rate=Vd[procValue]/0.05f;
	ConfigPara.Vq_rate=Vq[procValue]/0.05f;//Vd[procValue]/0.1f;

	/* PU Ramping rate of VoutRef soft start variable which updates in outer loop */
	ConfigPara.Vdc_rate=100.0f/10.0f;

	/* PU limits for soft start VdSat and VqSat soft start structures */
	ConfigPara.VdLimit = 500;//Vd[procValue];
	ConfigPara.VqLimit = 500; // Vd[procValue];

/*
****************************** Note about the factors *****************************
*	1.17f is factor showing conversion from AC RMS Voltage Value-> DC bus Voltage *
*	1.08f is factor showing conversion from DC-Bus voltage value -> DC-bus Output *
*	1.31f is boosting factor consider after running system                        *
***********************************************************************************
*/
	/*** Outer Control loop gains ***/
/*	ConfigPara.Kp_Vdc=0.15f;//0.35f;//0.58f;// 0.05f;
	ConfigPara.Ki_Vdc=0.50f;//0.29f; //0.2f;

	ConfigPara.Kd_Vd = 0.02f;*/
	ConfigPara.Kp_Vdc=0.75f;//0.35f;//0.58f;// 0.05f;
	ConfigPara.Ki_Vdc=0.18f;//0.29f; //0.2f;

	ConfigPara.Kd_Vd = 0.002f;

	/*** Inner Control loop gains ***/

	/*ConfigPara.Kp_Id=0.32f;//0.32f;
	ConfigPara.Ki_Id=0.62f;
	ConfigPara.Kd_Id = 0.02f;

	ConfigPara.Kp_Iq=0.29f;//0.34f;//0.05f;
	ConfigPara.Ki_Iq=0.20f;//0.8f;//0.03f;
	ConfigPara.Kd_Iq =0.05f;*/
		ConfigPara.Kp_Id=0.32f;//0.32f;
		ConfigPara.Ki_Id=0.62f;
		ConfigPara.Kd_Id = 0.04f;

		ConfigPara.Kp_Iq=0.39f;//0.34f;//0.05f;
		ConfigPara.Ki_Iq=0.62f;//0.8f;//0.03f;
		ConfigPara.Kd_Iq =0.06f;
	/*** LPF factors ***/
	ConfigPara.lpf_factor.Id=0.998;//0.92f;
	ConfigPara.lpf_factor.Iq=0.998;//0.92f;//0.995f;

	/*** Initialization of soft start structures ***/
	IDSat.Dynamic=Id[procValue];
	IDSat.Fix=ConfigPara.Id_limit;

	IQRef.Dynamic=0;
	IQRef.Fix=0;

	VdSat.Dynamic=ConfigPara.VdLimit; // Keep ConfigPara.VdLimit for Direct limit, and Keep 0 for Increment from small to high value
	VdSat.Fix=ConfigPara.VdLimit;

	VqSat.Dynamic=ConfigPara.VqLimit;
	VqSat.Fix=ConfigPara.VqLimit;

	/* Calculation of DC reference voltage */
	ConfigPara.VdcRef = VoutRef.Fix;
	VoutRef.Dynamic = V_OUT[procValue]; //when the system starts the DC building will start from present value

	if (absValues.Vr<500)
	{
		VoutRef.Fix= (Vrms[R_PHASE]*1.75*VphBase)/VoutBase;
	}
	else{
		VoutRef.Fix = 98.0;
	}


	VdFeedForward= Vd[procValue]+2.0f;
	VqFeedForward=Vq[procValue];

	/*** Initialization of PID Structures ***/
	InitPIDStruct(&IDref);
	InitPIDStruct(&VDref);
	InitPIDStruct(&VQref);

}

/*
 * Function description: Starts and stops the system on the event of button press
 * CALLS FROM: 100msecTask->getDigiIn()->Push-button Press
 * Execution Frequency: Calls once when Push-button key is pressed.
 * Input : None
 * Output : None
*/
void systemOnOff(void)
{
	if(psfb_OnOff_Flag == 0 && masterFaultFlag == 0 && slaveFaultFlag == 0)
	{
		dc_contactor_close_flag =1;
	//	if (DC_contactor_close ==1)
		psfb_OnOff_Flag = 1; //PSFB pulses start indicating the psfb start(local flag)
		cmd.bits.psfb_on = 1; //CAN variable indicating the psfb start
		psfbCounter = 0;
		PSFBFeedbackWaitFlag=1; // This flag shows the waiting period for completion of PSFB start and its start feedback command.


	}else if (Turn_ONOFF_Flag == 1 || psfb_OnOff_Flag == 1)
	{
		turnOff();
	}
}

/*
 * Function description: Wrapper function for resetting flags and bits in case of System is turned  OFF
 * Input : None
 * Output : None
*/
void turnOff(void)
{
	Turn_ONOFF_Flag = 0; //System off
	AFEOnFlag = 0;
	psfb_OnOff_Flag = 0;
	psfbFeedback = 0;
	PSFBFeedbackWaitFlag = 0;
	cmd.bits.system_on = 0;
	cmd.bits.psfb_on = 0;
	StartTime_ParameterInit();
	setDigiOut(LED1, GPIO_PIN_RESET);
	dc_contactor_open_flag = 1;					// output DC contactor OPEN
	Vout_temp=0;
}

/*
 * Function description: Checks the health of master, slave and PLL stability and turns OFF the system
 * Input : None
 * Output : None
 * Function Calls from the TIM7Execution()->ParameterCalculation() Function
*/
void systemEmrgAction(void)
{
	slave_health(ConfigPara.CascadedCELL * ConfigPara.totalPhases); // Change number of slaves in the argument
	if((masterFaultFlag != 0 || slaveFaultFlag != 0 || pllReady == 0) && (Turn_ONOFF_Flag == 1 || psfb_OnOff_Flag == 1))
		{
			turnOff();
		}
}

/*
 * Function description: Calculates the AC and DC parameters by multiplying ADC values with respective gains. Also performs necessary filtering
 * Input : None
 * Output : Updates global variables and sets master fault flag
 * Functions Call from TIM7execution Function at rate of 5 KHz
*/
void Parameter_Calculations(void)
{

	parameterCalculations_ADC1();
	parameterCalculations_ADC2();
	parameterCalculations_ADC3();
	parameterCalculations_ADC4();

	VrefLPF.xn = Adc_Avg_Buffer[ev1_65] ; //	Low pass filter for Vref
	VrefLPF.yn= VrefLPF.xn + ((float)0.998f*(VrefLPF.yn-VrefLPF.xn));

	//	Calculation of Grid Voltage angle, VAC_R,VAC_Y,VAC_B filtering and DC Blocking Starts*/
	VAC_R[rawValue] = ((((float)Adc_Avg_Buffer[eVAC_R]- VrefLPF.xn) * ConfigPara.calibration[eVAC_R].Gain * ConfigPara.calibration[eVAC_R].corFac)+ConfigPara.calibration[eVAC_R].Offset)/(VphBase);
	Vac_R_DCBlock.yn=ConfigPara.DcBlocker_factor.Vac_R*Vac_R_DCBlock.yn+(VAC_R[rawValue]-Vac_R_DCBlock.xn);  // DC Blockers
	Vac_R_DCBlock.xn=VAC_R[rawValue];
	VAC_R[procValue]=Vac_R_DCBlock.yn;


	VAC_Y[rawValue] =((((float)Adc_Avg_Buffer[eVAC_Y]- VrefLPF.xn) * ConfigPara.calibration[eVAC_Y].Gain * ConfigPara.calibration[eVAC_Y].corFac)+ConfigPara.calibration[eVAC_Y].Offset)/(VphBase);//3.39
	Vac_Y_DCBlock.yn=ConfigPara.DcBlocker_factor.Vac_Y*Vac_Y_DCBlock.yn+(VAC_Y[rawValue]-Vac_Y_DCBlock.xn); // DC Blockers
	Vac_Y_DCBlock.xn=VAC_Y[rawValue];
	VAC_Y[procValue]=Vac_Y_DCBlock.yn;


	VAC_B[rawValue] =((((float)Adc_Avg_Buffer[eVAC_B]- VrefLPF.xn) * ConfigPara.calibration[eVAC_B].Gain * ConfigPara.calibration[eVAC_B].corFac)+ConfigPara.calibration[eVAC_B].Offset)/(VphBase);//3.39
	Vac_B_DCBlock.yn=ConfigPara.DcBlocker_factor.Vac_B*Vac_B_DCBlock.yn+(VAC_B[rawValue]-Vac_B_DCBlock.xn); // DC Blockers
	Vac_B_DCBlock.xn=VAC_B[rawValue];
	VAC_B[procValue]=Vac_B_DCBlock.yn;


	VAC_E[rawValue] = (((float)Adc_Avg_Buffer[eVAC_E]- VrefLPF.yn) * ConfigPara.calibration[eVAC_E].Gain * ConfigPara.calibration[eVAC_E].corFac)/VphBase;//3.39
	Vac_E_DCBlock.yn=ConfigPara.DcBlocker_factor.Vac_E*Vac_E_DCBlock.yn+(VAC_E[rawValue]-Vac_E_DCBlock.xn); //DC Blockers
    Vac_E_DCBlock.yn=ConfigPara.DcBlocker_factor.Vac_E*Vac_E_DCBlock.yn+(VAC_E[rawValue]-Vac_E_DCBlock.xn);
	VAC_E[procValue]=Vac_E_DCBlock.yn;
	pllSample(5000);

	/*  IAC_R,IAC_Y,IAC_B filtering and DC Blocking Starts*/
	IAC_R[rawValue] = (((float)Adc_Avg_Buffer[eIAC_R]-VrefLPF.xn) *ConfigPara.calibration[eIAC_R].Gain * ConfigPara.calibration[eIAC_R].corFac)/IphBase;
	Iac_R_DCBlock.yn=ConfigPara.DcBlocker_factor.Iac_R*Iac_R_DCBlock.yn+(IAC_R[rawValue]-Iac_R_DCBlock.xn);
	Iac_R_DCBlock.xn=IAC_R[rawValue];
	IAC_R[procValue]=Iac_R_DCBlock.yn;



	IAC_Y[rawValue] = (((float)Adc_Avg_Buffer[eIAC_Y]-VrefLPF.xn) * ConfigPara.calibration[eIAC_Y].Gain * ConfigPara.calibration[eIAC_Y].corFac)/IphBase;
	Iac_Y_DCBlock.yn=ConfigPara.DcBlocker_factor.Iac_Y*Iac_Y_DCBlock.yn+(IAC_Y[rawValue]-Iac_Y_DCBlock.xn);
	Iac_Y_DCBlock.xn=IAC_Y[rawValue];
	IAC_Y[procValue]=Iac_Y_DCBlock.yn;

	IAC_B[rawValue] = (((float)Adc_Avg_Buffer[eIAC_B]-VrefLPF.xn) *ConfigPara.calibration[eIAC_B].Gain * ConfigPara.calibration[eIAC_B].corFac)/IphBase;
	Iac_B_DCBlock.yn=ConfigPara.DcBlocker_factor.Iac_B*Iac_B_DCBlock.yn+(IAC_B[rawValue]-Iac_B_DCBlock.xn);
	Iac_B_DCBlock.xn=IAC_B[rawValue];
	IAC_B[procValue]=Iac_B_DCBlock.yn;


	VdLPF.xn = Vd[rawValue];
	VdLPF.yn = VdLPF.xn + (ConfigPara.lpf_factor.Vd*(VdLPF.yn-VdLPF.xn));
	Vd[procValue] = VdLPF.yn;

	VqLPF.xn = Vq[rawValue];
	VqLPF.yn = VqLPF.xn + (ConfigPara.lpf_factor.Vq*(VqLPF.yn-VqLPF.xn));
	Vq[procValue] = VqLPF.yn;

	Id[rawValue]=(float)((2*IAC_R[procValue]*arm_sin_f32(GridAngle))/3.0f + (2*IAC_Y[procValue]*arm_sin_f32(GridAngle - 2.0944))/3.0f
			+ (2*IAC_B[procValue]*arm_sin_f32(GridAngle + 2.0944))/3.0f); // ABC to DQ for current
	IdLPF.xn =Id[rawValue];
	IdLPF.yn=IdLPF.xn+(ConfigPara.lpf_factor.Id*(IdLPF.yn-IdLPF.xn));
	Id[procValue]=IdLPF.yn; // Filtered Value

	Iq[rawValue]=(float)((2*IAC_R[procValue]*arm_cos_f32(GridAngle))/3.0f + (2*IAC_Y[procValue]*arm_cos_f32(GridAngle - 2.0944))/3.0f
			+ (2*IAC_B[procValue]*arm_cos_f32(GridAngle + 2.0944))/3.0f); // ABC to DQ for current

	IqLPF.xn =Iq[rawValue];
	IqLPF.yn=IqLPF.xn+(ConfigPara.lpf_factor.Iq*(IqLPF.yn-IqLPF.xn));
	Iq[procValue]=IqLPF.yn; // Filtered Value

	V_OUT[rawValue]=((((float)Adc_Avg_Buffer[eV_OUT])* ConfigPara.calibration[eV_OUT].Gain * ConfigPara.calibration[eV_OUT].Slope) + ConfigPara.calibration[eV_OUT].Offset) * ConfigPara.calibration[eV_OUT].corFac; // Low pass filter for Vout
	V_OUT[rawValue] = V_OUT[rawValue]/VoutBase;
	VoutLPF.xn =V_OUT[rawValue];
	VoutLPF.yn= VoutLPF.xn + ((float)ConfigPara.lpf_factor.Vout*(VoutLPF.yn-VoutLPF.xn));
	V_OUT[procValue]=	VoutLPF.yn;


	I_OUT[rawValue]=((((float)Adc_Avg_Buffer[eI_OUT])* ADC_RESOLUTION * ConfigPara.calibration[eI_OUT].Slope) +  ConfigPara.calibration[eI_OUT].Offset) * ConfigPara.calibration[eI_OUT].corFac; //Low pass filter for Iout
	I_OUT[rawValue] = I_OUT[rawValue]/IoutBase;
	IoutLPF.xn =I_OUT[rawValue];
	IoutLPF.yn= IoutLPF.xn + ((float)ConfigPara.lpf_factor.Iout*(IoutLPF.yn-IoutLPF.xn));
	I_OUT[procValue] =	IoutLPF.yn;

	protectionMonitoring_DC();

	// Calculating the RMS and Protection function at every 1 mSec
	calculateRMS(ConfigPara.Freq_inner, ConfigPara.Fsystem);

//	masterFaultFlag = acVoltFault.byte | acCurrFault.byte | dcFault.byte | tempFault.byte;
	masterFaultFlag = 0;

	powerOutput = V_OUT[procValue] * I_OUT[procValue];

	puToAbsolute(); // This function convert the PU value to Absolute Value
	systemEmrgAction();
	DAC_Out();
}

/*
 * Function description: Calculates absolute values from Per Unit values
 * Input : None
 * Output :
*/
void puToAbsolute()
{
	absValues.Id = Id[procValue] * IphBase;
	absValues.Iq = Iq[procValue] * IphBase;
	absValues.Vd = Vd[procValue] * VphBase;
	absValues.Vq = Vq[procValue] * VphBase;
	absValues.Vout =  V_OUT[procValue] * VoutBase;
	absValues.Iout = I_OUT[procValue] * IoutBase;
	absValues.Vr = Vrms[R_PHASE] * VphBase;
	absValues.Vy = Vrms[Y_PHASE] * VphBase;
	absValues.Vb = Vrms[B_PHASE] * VphBase;
	//VrmsAbs[E_PHASE] = Vrms[E_PHASE] * VphBase;
	absValues.Ir = Irms[R_PHASE] * IphBase;
	absValues.Iy = Irms[Y_PHASE] * IphBase;
	absValues.Ib = Irms[B_PHASE] * IphBase;
	absValues.VdcRef = VoutRef.Fix * VoutBase;
	//absValues.VdcRef = ConfigPara.VdcRef * VoutBase;
}

/*
 * Function description: Initializes and starts the peripherals such as Timers, ADC and DAC and also initializes the fault structure
 * Input : None
 * Output : None
*/
void Control_Init(void){

	// for converting the actual value in PU system
	VphBase=(ConfigPara.Vrated*1.41f/(100.0f*1.73f));
	IphBase=(ConfigPara.Irated*1.41f/100.0f); //User Defined PerUnit
	VoutBase=(ConfigPara.Voutrated/100.0f);
	IoutBase=(ConfigPara.Ioutrated/100.0f);

	// ADC 1, 2 and 3 Sampling
	TIM3->PSC=0; //Timer 1 at 4*5000 = 20 KHz
	TIM3->ARR = (uint16_t)(((float)SystemCoreClock/2)/((1+TIM3->PSC)*(ConfigPara.Freq_inner*ADC_SAMPLE_SIZE))) - 1;

	// ADC 4 and 5 with SLow Quantity Sensing
	TIM4->PSC=249; //Timer 4 at 10*4 = 40 Hz
    TIM4->ARR = (uint16_t)(SystemCoreClock/((1+TIM4->PSC)*(10.0f*ADC_SAMPLE_SIZE))) - 1;

    // System Interrupt for Low priotiy task based on RoundRobin
    TIM6->PSC=4; //Timer 6 (1 KHz= 1000us)
	TIM6->ARR = (uint16_t)(SystemCoreClock/((1+TIM6->PSC)*(1000))) - 1;

	// High Priority System INterrupt for Control System
	TIM7->PSC=0; //Timer 7
	TIM7->ARR = (uint16_t)(SystemCoreClock/((1+TIM7->PSC)*(ConfigPara.Freq_inner))) - 1;

	// Sync Pulse generation
	TIM1->PSC = 0;
	TIM1->ARR = (uint16_t)(SystemCoreClock/((1+TIM1->PSC)*(5000))) - 1;
	TIM1->CCR3 = (uint16_t)(0.5f * (float)TIM1->ARR);

    HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_3); // Start timer 1 to enable sync pulse

	HAL_TIM_Base_Start(&htim3); // Start Timer To enable ADC1, ADC2, ADC3  High Rate
	HAL_TIM_Base_Start_IT(&htim4); // Start Timer To enable ADC5 at Low rate
    HAL_TIM_Base_Start_IT(&htim6); //Start Timers for interrupts
    HAL_TIM_Base_Start_IT(&htim7); //Start Timers for interrupts To enable for calculations


    HAL_ADC_Start_DMA(&hadc1,(uint32_t*)Adc1_Buffer,ADC1_BUFFER_SIZE); //Start ADC1
	HAL_ADC_Start_DMA(&hadc2,(uint32_t*)Adc2_Buffer,ADC2_BUFFER_SIZE); //Start ADC2
	HAL_ADC_Start_DMA(&hadc3,(uint32_t*)Adc3_Buffer,ADC3_BUFFER_SIZE); //Start ADC3
	HAL_ADC_Start_DMA(&hadc4,(uint32_t*)Adc4_Buffer,ADC4_BUFFER_SIZE); //Start ADC4
	HAL_ADC_Start_DMA(&hadc5,(uint32_t*)Adc5_Buffer,ADC5_BUFFER_SIZE); //Start ADC5
	HAL_DAC_Start(&hdac1, DAC_CHANNEL_1); // Start DAC
	HAL_DAC_Start(&hdac1, DAC_CHANNEL_2); // Start DAC

	HAL_HRTIM_WaveformCounterStart(&hhrtim1, HRTIM_TIMERID_MASTER + HRTIM_TIMERID_TIMER_A + HRTIM_TIMERID_TIMER_B );
	HAL_HRTIM_WaveformOutputStart(&hhrtim1, HRTIM_OUTPUT_TA1 | HRTIM_OUTPUT_TB1);


	faultInit(); // Initializing all the fault structures
	HAL_GPIO_WritePin(SYNC1_GPIO_Port, SYNC1_Pin, GPIO_PIN_RESET); // For Slave AFE PWM on indication. Check in io.c getDigiIn()
	HAL_GPIO_WritePin(TO_SG1_GPIO_Port, TO_SG1_Pin, GPIO_PIN_SET);
	Turn_ONOFF_Flag = 0; //Initialised as zero as it was taking garbage value '155'
	psfb_OnOff_Flag = 0; //Initialised as zero as it was taking garbage value '66'
	dc_contactor_close_flag = 0;
	dc_contactor_open_flag = 0;

}

/*
 * Function description: Calculates RMS value of AC quantities
 * Input : None
 * Output : None
*/
void calculateRMS(unsigned int SamplingFreq, unsigned int Fsystem)
{
	//HAL_GPIO_TogglePin(STRB3_GPIO_Port, STRB3_Pin);
	static uint16_t smplCnt=0;
	uint16_t Temp_Sample= SamplingFreq/Fsystem;

	Temp_Sample = 1000; // 200us *1000 interrupts = 10 cycle time

	vr_rms_buffer = (float)vr_rms_buffer + (float)(VAC_R[procValue] * VAC_R[procValue]);
	vy_rms_buffer = (float)vy_rms_buffer + (float)(VAC_Y[procValue] * VAC_Y[procValue]);
	vb_rms_buffer = (float)vb_rms_buffer + (float)(VAC_B[procValue] * VAC_B[procValue]);
	ve_rms_buffer = (float)ve_rms_buffer + (float)(VAC_E[procValue] * VAC_E[procValue]);
	ir_rms_buffer = (float)ir_rms_buffer + (float)(IAC_R[procValue] * IAC_R[procValue]);
	iy_rms_buffer = (float)iy_rms_buffer + (float)(IAC_Y[procValue] * IAC_Y[procValue]);
	ib_rms_buffer = (float)ib_rms_buffer + (float)(IAC_B[procValue] * IAC_B[procValue]);
	smplCnt++;
	if(smplCnt >= Temp_Sample){
		smplCnt = 0;
		vrRmsLPF.xn = (float)sqrt(vr_rms_buffer/Temp_Sample);
		vyRmsLPF.xn = (float)sqrt(vy_rms_buffer/Temp_Sample);
		vbRmsLPF.xn = (float)sqrt(vb_rms_buffer/Temp_Sample);
		veRmsLPF.xn = (float)sqrt(ve_rms_buffer/Temp_Sample);
		irRmsLPF.xn = (float)sqrt(ir_rms_buffer/Temp_Sample);
		iyRmsLPF.xn = (float)sqrt(iy_rms_buffer/Temp_Sample);
		ibRmsLPF.xn = (float)sqrt( ib_rms_buffer/Temp_Sample);

		vrRmsLPF.yn = vrRmsLPF.xn + ((float)ConfigPara.lpf_factor.rmsCal*(vrRmsLPF.yn-vrRmsLPF.xn));
		vyRmsLPF.yn = vyRmsLPF.xn + ((float)ConfigPara.lpf_factor.rmsCal*(vyRmsLPF.yn-vyRmsLPF.xn));
		vbRmsLPF.yn = vbRmsLPF.xn + ((float)ConfigPara.lpf_factor.rmsCal*(vbRmsLPF.yn-vbRmsLPF.xn));
		veRmsLPF.yn = veRmsLPF.xn + ((float)ConfigPara.lpf_factor.rmsCal*(veRmsLPF.yn-veRmsLPF.xn));
		irRmsLPF.yn = irRmsLPF.xn + ((float)ConfigPara.lpf_factor.rmsCal*(irRmsLPF.yn-irRmsLPF.xn));
		iyRmsLPF.yn = iyRmsLPF.xn + ((float)ConfigPara.lpf_factor.rmsCal*(iyRmsLPF.yn-iyRmsLPF.xn));
		ibRmsLPF.yn = ibRmsLPF.xn + ((float)ConfigPara.lpf_factor.rmsCal*(ibRmsLPF.yn-ibRmsLPF.xn));

		Vrms[R_PHASE] = (vrRmsLPF.yn);
		Vrms[Y_PHASE] = (vyRmsLPF.yn);
		Vrms[B_PHASE] = (vbRmsLPF.yn);
		Vrms[E_PHASE] = veRmsLPF.yn;
		Irms[R_PHASE] = irRmsLPF.yn;
		Irms[Y_PHASE] = iyRmsLPF.yn;
		Irms[B_PHASE] = ibRmsLPF.yn;

		vr_rms_buffer = 0.0f;
		vy_rms_buffer = 0.0f;
		vb_rms_buffer = 0.0f;
		ve_rms_buffer = 0.0f;
		ir_rms_buffer = 0.0f;
		iy_rms_buffer = 0.0f;
		ib_rms_buffer = 0.0f;
		protectionMonitoring_AC();
		if (absValues.Vr<500)
		{
			VoutRef.Fix= (Vrms[R_PHASE]*1.75*VphBase)/VoutBase;
		}
		else{
			VoutRef.Fix = 98.0;
		}
	}

	//power calculation
	rPower = Vrms[R_PHASE] * Irms[R_PHASE];
	yPower = Vrms[Y_PHASE] * Irms[Y_PHASE];
	bPower = Vrms[B_PHASE] * Irms[B_PHASE];
	power_kva = (rPower + yPower + bPower)/1000;

	//power factor calculation
	//TODO theta = atan(iq/id);
	//theta = arctan2_Su(Iq[procValue], Id[procValue]);
	//power_factor = arm_cos_f32(theta);


}

/*
 * Function description: Calculates Temperature from ADC values at 40Hz
 * Input : None
 * Output : None
*/
void tempCalculations()
{
	parameterCalculations_ADC5();
	NTC1[rawValue]=(((float)Adc_Avg_Buffer[eTmpr1])*ADC_RESOLUTION); //Low pass filter for ntc1
	Ntc1LPF.xn =NTC1[rawValue];
	Ntc1LPF.yn= Ntc1LPF.xn + ((float)ConfigPara.lpf_factor.Ntc1*(Ntc1LPF.yn-Ntc1LPF.xn));
	NTC1[procValue]=	Ntc1LPF.yn;
	NTC1[procValue] = ((NTC1[procValue] * ConfigPara.calibration[eTmpr1].Slope) + ConfigPara.calibration[eTmpr1].Offset)*ConfigPara.calibration[eTmpr1].corFac;
	ntc1_temp = calculateTemperature(NTC1[procValue]);


	NTC2[rawValue]=(((float)Adc_Avg_Buffer[eTmpr2])*ADC_RESOLUTION); //Low pass filter for ntc2
	Ntc2LPF.xn =NTC2[rawValue];
	Ntc2LPF.yn= Ntc2LPF.xn + ((float)ConfigPara.lpf_factor.Ntc2*(Ntc2LPF.yn-Ntc2LPF.xn));
	NTC2[procValue] = Ntc2LPF.yn;
	NTC2[procValue] = ((NTC2[procValue] * ConfigPara.calibration[eTmpr2].Slope) + ConfigPara.calibration[eTmpr2].Offset)*ConfigPara.calibration[eTmpr2].corFac;
	ntc2_temp = calculateTemperature(NTC2[procValue]);

	protectionMonitoring_Temp();
}
