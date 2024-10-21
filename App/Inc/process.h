/* File description: Process variables
 * Functions used:
 * Reference document:
*/
#include "main.h"
#include "stdio.h"
#include "main.h"
#include "adc.h"
#include "dac.h"
#include "dma.h"
#include "tim.h"
#include "gpio.h"
#include "syspara.h"

/*** Mathematical constants ***/
#define pi (float)3.141592f
#define ONE_By_Root_THREE (float)0.57735f
#define TWO_PI_BY_THREE (float)2.09523809f
#define FOUR_PI_BY_THREE (float)4.19047619f

/*** Sensor gains ***/
#define ADC_RESOLUTION (float)0.00080566 //(3.3f/4096.0f)
#define PT_RATIO (float)1200.0f/6.0f // For debugging 1000.0f/10.0f
#define CT_RATIO (float) 20.0f/1.0f
#define R_BURDEN 0.5f
#define OUTPUT_VOLTAGE_GAIN 1500.0f
#define OUTPUT_CURRENT_GAIN 600.0f

enum arrayValue{rawValue, procValue,absoluteValue};

#ifdef _PROCESS_
	configParameters ConfigPara;

	/* Declaration of flags */
    unsigned char mSec1_Flag, mSec40_Flag, mSec100_Flag,mSec500_Flag,mSec250_Flag,Sec1_Flag;
    unsigned char TurnON_DemandFlag,TurnOFF_DemandFlag,Turn_ONOFF_Flag = 0,psfb_OnOff_Flag = 0,psfbFeedback,StartStopFlag; // Turn ON/OFF Demand Flag
    uint8_t dc_contactor_close_flag =0;
    float V_cmd = 4250.0;
    uint8_t dc_contactor_open_flag =0;
    uint8_t slope_flag=1;
    float V_OUT_Error=0;
    float V_OUT_Constant=15.0f;
    float V_OUT_Requirement=0;
    float V_OUT_Error_present=0;
    float V_OUT_add=0;
    uint32_t V_OUT_count=0;
    float virtual_add=0.0f;

    /* Declaration of counters */
    unsigned int CNT_TIM6;
    unsigned char OuterLoopCNT;

    /* Process variables */
    float vr_rms_buffer, vy_rms_buffer, vb_rms_buffer,ve_rms_buffer,ir_rms_buffer,iy_rms_buffer,ib_rms_buffer;
    float VAC_R[3], VAC_Y[3], VAC_B[3], VAC_E[2];                   // Input AC voltages
    float IAC_R[3], IAC_Y[3], IAC_B[3];                             //Input AC current
    float V_OUT[2], I_OUT[2], NTC1[2], NTC2[2]; //DC quantities
    float ntc1_temp, ntc2_temp;
    float Vrms[4], Irms[3]; // RMS values of AC components
    float Id[2],Iq[2], Vd[2], Vq[2], V0; //DQ components
    float VphBase,IphBase,VoutBase,IoutBase; // Per Unit conversion factors
    float GridAngle; // Grid Angle output of PLL
	float Vd_cmd, Vq_cmd; // DQ outputs of inner loop
	float Vr_cmd, Vy_cmd, Vb_cmd; // ABC duty as converted from DQ
	float powerOutput,power_kva,rPower,yPower,bPower;
	float theta;
	float power_factor;
	uint16_t TIM1_CCR1, TIM1_CCR2;
	uint32_t rms_sample=0;
	float Vrms_R=0;
	float Vrms_r_avg=0;

	/* Inverter test variables uncomment to use*/
    uint16_t n_spwm;
    float Ma=0.8;
//    float V_cmd;

	/* Process parameters. Might have to replace them with configPara */
    float SlaveARR = 14999.0f;
    float angle_compensation = 6;
    uint8_t pllReady = 0;
    float VdcRefAbs;
    float InputPower, OutputPower;
    float TempVdc_Bus_Divide;
    float boost_factor=1.5f;
    float VdFeedForward, VqFeedForward;
	float temp_vd_calc=14;
	unsigned char TempCNT_TIM7;

	uint16_t vout_pid_saturated;
	uint16_t id_pid_saturated;
	uint16_t iq_pid_saturated;

    void TIM6_Execution(void); // for LED, lCD, Protection, Soft-Start and Key Scan
    void TIM7_Execution(void); // for Inner and Outer Loop Calculations
    void Converter_Start(void);
    void Converter_Stop(void);
    void Control_Init(void);
    void Parameter_Calculations(void);
    void SoftStart(void);
    void StartTime_ParameterInit(void);
    void parameterCalculations_ADC1(void);
    void parameterCalculations_ADC2(void);
    void parameterCalculations_ADC3(void);
    void parameterCalculations_ADC4(void);
    void parameterCalculations_ADC5(void);
    void paraInit(void);
    void systemOnOff(void);
    void turnOff(void);
    void tempCalculations(void);
    void calculateRMS(unsigned int SamplingFreq, unsigned int Fsystem);
    void pllSample(float sampling_freq);
    void puToAbsolute();
#else
    extern configParameters ConfigPara;
    extern unsigned char mSec1_Flag, mSec40_Flag, mSec100_Flag,mSec500_Flag, mSec250_Flag,Sec1_Flag;
    extern unsigned char TurnON_DemandFlag,TurnOFF_DemandFlag,Turn_ONOFF_Flag,psfb_OnOff_Flag,psfbFeedback; // Turn ON/OFF Demand Flag
    extern uint8_t StartStopFlag;
    extern  uint8_t dc_contactor_close_flag;
    extern uint8_t dc_contactor_open_flag;
    extern float VAC_R[3], VAC_Y[3], VAC_B[3], VAC_E[2]; // Receiving end voltage
    extern float IAC_R[3], IAC_Y[3], IAC_B[3]; //Compansator current
    extern float V_OUT[3], I_OUT[3], NTC1[2], NTC2[2]; //DC quantities
    extern float Vrms[3], Irms[3];

    extern float Id[3],Iq[3], Vd[3], Vq[3],V0; //DQ Components
    extern uint8_t rms_counter;
    extern float vr_rms_buffer, vy_rms_buffer, vb_rms_buffer,ve_rms_buffer,ir_rms_buffer,iy_rms_buffer,ib_rms_buffer;
    extern float virtual_add;
    extern float VphBase,IphBase,VoutBase,IoutBase;
    extern float VrefADC, IQref;
    extern float Vdc[1];
    extern unsigned char OuterLoopCNT;
    extern float GridAngle;
    extern float Vd_cmd, Vq_cmd; // Keep Vd as Peak Value of Grid Phase Voltage
    extern float Vr_cmd, Vy_cmd, Vb_cmd; // Keep Vd as Peak Value of Grid Phase Voltage
    extern uint16_t n_spwm;
    extern float Ma;
    extern float V_cmd;
    extern uint16_t TIM1_CCR1, TIM1_CCR2;
    extern float ntc1_temp, ntc2_temp;
    extern float SlaveARR;
    extern float angle_compensation;
    extern uint8_t pllReady;
    extern  float InputPower, OutputPower;
    extern void TIM6_Execution(void); // for LED, lCD, Protection, Soft-Start and Key Scan
    extern void TIM7_Execution(void); // for Inner and Outer Loop Calculations
    extern void Converter_Start(void);
    extern void Converter_Stop(void);
    extern void Control_Init(void);
    extern void Parameter_Calculations(void);
    extern void SoftStart(void);
    extern void StartTime_ParameterInit(void);
    extern void parameterCalculations_ADC1(void);
    extern void parameterCalculations_ADC2(void);
    extern void parameterCalculations_ADC3(void);
    extern void parameterCalculations_ADC4(void);
    extern void parameterCalculations_ADC5(void);
    extern void paraInit(void);
    extern void systemOnOff(void);
    extern void turnOff(void);
    extern void tempCalculations(void);
    extern void pllSample(float sampling_freq);
    extern float InputPower, OutputPower;
    extern float TempVdc_Bus_Divide;
    extern float VdFeedForward, VqFeedForward;
	extern float temp_vd_calc;
    extern  uint8_t slope_flag;
    extern uint32_t rms_sample;
    extern float Vrms_R;
    extern float Vrms_r_avg;

	extern uint16_t vout_pid_saturated;
	extern uint16_t id_pid_saturated;
	extern uint16_t iq_pid_saturated;
#endif
