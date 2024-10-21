#define _PROTECTION_
#include"protection.h"
#include "Slave_Monitoring.h"
#include "process.h"
#include "interface.h"
/*
* Function Description: To check under limit of quantities
* Input:
* Return:
*/
void faultInit(void)
{

	/* R phase over voltage initialization */
	RphOverVol.ovlCount = 0; //always initialized as 0
	RphOverVol.ovlFault = 0; //always initialized as 0
	RphOverVol.ovlResetCount = 0; //always initialized as 0
	RphOverVol.ovlNoOfReset = 3;
	RphOverVol.ovlFaultLatched = 0;
	RphOverVol.ovlCoolDownCount = 0; //always initialized as 0
	RphOverVol.threshold = 13000;
	RphOverVol.threshold_time = 100.0f/1000.0f;
	RphOverVol.reset_threshold = 12000;
	RphOverVol.reset_threshold_time = 100.0f/1000.0f;
	RphOverVol.no_of_reset = 0;
	RphOverVol.autoreset = 0;
	RphOverVol.cooldown_enable = 1;
	RphOverVol.cooldown_time = 86400;
	RphOverVol.sampleFreq = 50.0f;

	/* R phase under voltage initialization */
	RphUnVol.underLCount = 0; // Dynamic parameters will change during the course of execution
	RphUnVol.underLFault = 0;
	RphUnVol.underLResetCount = 0;
	RphUnVol.underLNoOfReset = 3;
	RphUnVol.underLFaultLatched = 0;
	RphUnVol.underLCoolDownCount = 0;
	RphUnVol.threshold = 11000; // Static parameters can be configured using ConfigPara
	RphUnVol.threshold_time = 100.0f/1000.0f;
	RphUnVol.reset_threshold = 12000;
	RphUnVol.reset_threshold_time = 100.0f/1000.0f;
	RphUnVol.no_of_reset = 0;
	RphUnVol.autoreset = 0;
	RphUnVol.cooldown_enable = 1;
	RphUnVol.cooldown_time = 86400;
	RphUnVol.sampleFreq = 50.0f;

	/* Y phase over voltage initialization */
	YphOverVol.ovlCount = 0; //always initialized as 0
	YphOverVol.ovlFault = 0; //always initialized as 0
	YphOverVol.ovlResetCount = 0; //always initialized as 0
	YphOverVol.ovlNoOfReset = 3;
	YphOverVol.ovlFaultLatched = 0;
	YphOverVol.ovlCoolDownCount = 0; //always initialized as 0
	YphOverVol.threshold = 13000;
	YphOverVol.threshold_time = 100.0f/1000.0f;
	YphOverVol.reset_threshold = 12000;
	YphOverVol.reset_threshold_time = 100.0f/1000.0f;
	YphOverVol.no_of_reset = 0;
	YphOverVol.autoreset = 0;
	YphOverVol.cooldown_enable = 1;
	YphOverVol.cooldown_time = 86400;
	YphOverVol.sampleFreq = 50.0f;

	/* Y phase under voltage initialization */
	YphUnVol.underLCount = 0; // Dynamic parameters will change during the course of execution
	YphUnVol.underLFault = 0;
	YphUnVol.underLResetCount = 0;
	YphUnVol.underLNoOfReset = 3;
	YphUnVol.underLFaultLatched = 0;
	YphUnVol.underLCoolDownCount = 0;
	YphUnVol.threshold = 11000; // Static parameters can be configured using ConfigPara
	YphUnVol.threshold_time = 100.0f/1000.0f;
	YphUnVol.reset_threshold = 12000;
	YphUnVol.reset_threshold_time = 100.0f/1000.0f;
	YphUnVol.no_of_reset = 0;
	YphUnVol.autoreset = 0;
	YphUnVol.cooldown_enable = 1;
	YphUnVol.cooldown_time = 86400;
	YphUnVol.sampleFreq = 50.0f;

	/* B phase over voltage initialization */
	BphOverVol.ovlCount = 0; //always initialized as 0
	BphOverVol.ovlFault = 0; //always initialized as 0
	BphOverVol.ovlResetCount = 0; //always initialized as 0
	BphOverVol.ovlNoOfReset = 3;
	BphOverVol.ovlFaultLatched = 0;
	BphOverVol.ovlCoolDownCount = 0; //always initialized as 0
	BphOverVol.threshold = 13000;
	BphOverVol.threshold_time = 100.0f/1000.0f;
	BphOverVol.reset_threshold = 12000;
	BphOverVol.reset_threshold_time = 100.0f/1000.0f;
	BphOverVol.no_of_reset = 0;
	BphOverVol.autoreset = 0;
	BphOverVol.cooldown_enable = 1;
	BphOverVol.cooldown_time = 86400;
	BphOverVol.sampleFreq = 50.0f;

	/* B phase under voltage initialization */
	BphUnVol.underLCount = 0; // Dynamic parameters will change during the course of execution
	BphUnVol.underLFault = 0;
	BphUnVol.underLResetCount = 0;
	BphUnVol.underLNoOfReset = 3;
	BphUnVol.underLFaultLatched = 0;
	BphUnVol.underLCoolDownCount = 0;
	BphUnVol.threshold = 11000; // Static parameters can be configured using ConfigPara
	BphUnVol.threshold_time = 100.0f/1000.0f;
	BphUnVol.reset_threshold = 12000;
	BphUnVol.reset_threshold_time = 100.0f/1000.0f;
	BphUnVol.no_of_reset = 0;
	BphUnVol.autoreset = 0;
	BphUnVol.cooldown_enable = 1;
	BphUnVol.cooldown_time = 86400;
	BphUnVol.sampleFreq = 50.0f;

	/* Earth phase over voltage initialization */
	EphOverVol.ovlCount = 0; //always initialized as 0
	EphOverVol.ovlFault = 0; //always initialized as 0
	EphOverVol.ovlResetCount = 0; //always initialized as 0
	EphOverVol.ovlNoOfReset = 3;
	EphOverVol.ovlFaultLatched = 0;
	EphOverVol.ovlCoolDownCount = 0; //always initialized as 0
	EphOverVol.threshold = 13000;
	EphOverVol.threshold_time = 100.0f/1000.0f;
	EphOverVol.reset_threshold = 12000;
	EphOverVol.reset_threshold_time = 100.0f/1000.0f;
	EphOverVol.no_of_reset = 0;
	EphOverVol.autoreset = 0;
	EphOverVol.cooldown_enable = 1;
	EphOverVol.cooldown_time = 86400;
	EphOverVol.sampleFreq = 50.0f;

	/* R phase Over Current */
	RphOverCur.ovlCount = 0; //always initialized as 0
	RphOverCur.ovlFault = 0; //always initialized as 0
	RphOverCur.ovlResetCount = 0; //always initialized as 0
	RphOverCur.ovlNoOfReset = 3;
	RphOverCur.ovlFaultLatched = 0;
	RphOverCur.ovlCoolDownCount = 0; //always initialized as 0
	RphOverCur.threshold = 50;
	RphOverCur.threshold_time = 100.0f/1000.0f;
	RphOverCur.reset_threshold = 0;
	RphOverCur.reset_threshold_time = 0;
	RphOverCur.no_of_reset = 0;
	RphOverCur.autoreset = 0;
	RphOverCur.cooldown_enable = 1;
	RphOverCur.cooldown_time = 86400;
	RphOverCur.sampleFreq = 50.0f;

	/* Y phase Over Current */
	YphOverCur.ovlCount = 0; //always initialized as 0
	YphOverCur.ovlFault = 0; //always initialized as 0
	YphOverCur.ovlResetCount = 0; //always initialized as 0
	YphOverCur.ovlNoOfReset = 3;
	YphOverCur.ovlFaultLatched = 0;
	YphOverCur.ovlCoolDownCount = 0; //always initialized as 0
	YphOverCur.threshold = 50;
	YphOverCur.threshold_time = 100.0f/1000.0f;
	YphOverCur.reset_threshold = 0;
	YphOverCur.reset_threshold_time = 0;
	YphOverCur.no_of_reset = 0;
	YphOverCur.autoreset = 0;
	YphOverCur.cooldown_enable = 1;
	YphOverCur.cooldown_time = 86400;
	YphOverCur.sampleFreq = 50.0f;

	/* B phase Over Current */
	BphOverCur.ovlCount = 0; //always initialized as 0
	BphOverCur.ovlFault = 0; //always initialized as 0
	BphOverCur.ovlResetCount = 0; //always initialized as 0
	BphOverCur.ovlNoOfReset = 3;
	BphOverCur.ovlFaultLatched = 0;
	BphOverCur.ovlCoolDownCount = 0; //always initialized as 0
	BphOverCur.threshold = 50;
	BphOverCur.threshold_time = 100.0f/1000.0f;
	BphOverCur.reset_threshold = 0;
	BphOverCur.reset_threshold_time = 0;
	BphOverCur.no_of_reset = 0;
	BphOverCur.autoreset = 0;
	BphOverCur.cooldown_enable = 1;
	BphOverCur.cooldown_time = 86400;
	BphOverCur.sampleFreq = 50.0f;

	/* Vout Over Voltage */
	VoutOverVol.ovlCount = 0;  //always initialized as 0
	VoutOverVol.ovlFault = 0; //always initialized as 0
	VoutOverVol.ovlResetCount = 0;
	VoutOverVol.ovlNoOfReset = 3;
	VoutOverVol.ovlFaultLatched = 0;
	VoutOverVol.ovlCoolDownCount = 0; //always initialized as 0
	VoutOverVol.threshold = 1200;
	VoutOverVol.threshold_time = 5.0f/1000.0f;
	VoutOverVol.reset_threshold = 1000; //TBD
	VoutOverVol.reset_threshold_time =5.0f/1000.0f;
	VoutOverVol.no_of_reset = 0;
	VoutOverVol.autoreset = 0;
	VoutOverVol.cooldown_enable = 1;
	VoutOverVol.cooldown_time = 86400;
	VoutOverVol.sampleFreq = 5000.0f;

	/* Vout Under Voltage */
	VoutUnVol.underLCount = 0; //always initialized as 0
	VoutUnVol.underLFault = 0; //always initialized as 0
	VoutUnVol.underLResetCount = 0; //always initialized as 0
	VoutUnVol.underLNoOfReset = 3;
	VoutUnVol.underLFaultLatched = 0;
	VoutUnVol.underLCoolDownCount = 0;
	VoutUnVol.threshold = 900; //TBD
	VoutUnVol.threshold_time = 5.0f/1000.0f;
	VoutUnVol.reset_threshold = 950; //TBD
	VoutUnVol.reset_threshold_time = 5.0f/1000.0f;
	VoutUnVol.no_of_reset = 0;
	VoutUnVol.autoreset = 0;
	VoutUnVol.cooldown_enable = 1;
	VoutUnVol.cooldown_time = 86400;
	VoutUnVol.sampleFreq = 5000.0f;

	/* Iout Over Current */
	IoutOverCur.ovlCount = 0; //always initialized as 0
	IoutOverCur.ovlFault = 0; //always initialized as 0
	IoutOverCur.ovlResetCount = 0; //always initialized as 0
	IoutOverCur.ovlNoOfReset = 3;
	IoutOverCur.ovlFaultLatched = 0;
	IoutOverCur.ovlCoolDownCount = 0; //always initialized as 0
	IoutOverCur.threshold = 50;
	IoutOverCur.threshold_time = 5.0f/1000.0f;
	IoutOverCur.reset_threshold = 0; //Not applicable for current
	IoutOverCur.reset_threshold_time = 0; //Not applicable for current
	IoutOverCur.no_of_reset = 0; //Not applicable for current
	IoutOverCur.autoreset = 0;  //Not applicable for current
	IoutOverCur.cooldown_enable = 1;
	IoutOverCur.cooldown_time = 86400;
	IoutOverCur.sampleFreq = 5000.0f;

	/* NTC1 Over temperature */
	ntc1OverTemp.ovlCount = 0; // Dynamic parameters will change during the course of execution
	ntc1OverTemp.ovlFault = 0;
	ntc1OverTemp.ovlResetCount = 0;
	ntc1OverTemp.ovlNoOfReset = 3;
	ntc1OverTemp.ovlFaultLatched = 0;
	ntc1OverTemp.ovlCoolDownCount = 0;
	ntc1OverTemp.threshold = 90; // Static parameters can be configured using ConfigPara
	ntc1OverTemp.threshold_time = 0.125f; // 1/40 *5
	ntc1OverTemp.reset_threshold = 80;
	ntc1OverTemp.reset_threshold_time = 0.125; //  // 1/40 *5
	ntc1OverTemp.no_of_reset = 0;
	ntc1OverTemp.autoreset = 0;
	ntc1OverTemp.cooldown_enable = 1;
	ntc1OverTemp.cooldown_time = 86400;
	ntc1OverTemp.sampleFreq = 40.0f;

	/* NTC2 Over temperature */
	ntc2OverTemp.ovlCount = 0; // Dynamic parameters will change during the course of execution
	ntc2OverTemp.ovlFault = 0;
	ntc2OverTemp.ovlResetCount = 0;
	ntc2OverTemp.ovlNoOfReset = 3;
	ntc2OverTemp.ovlFaultLatched = 0;
	ntc2OverTemp.ovlCoolDownCount = 0;
	ntc2OverTemp.threshold = 90; // Static parameters can be configured using ConfigPara
	ntc2OverTemp.threshold_time = 0.125f; // 1/40 *5
	ntc2OverTemp.reset_threshold = 80;
	ntc2OverTemp.reset_threshold_time = 0.125; //  // 1/40 *5
	ntc2OverTemp.no_of_reset = 0;
	ntc2OverTemp.autoreset = 0;
	ntc2OverTemp.cooldown_enable = 1;
	ntc2OverTemp.cooldown_time = 86400;
	ntc2OverTemp.sampleFreq = 40.0f;
}

/*
* Function Description: To check under limit of quantities
* Input:
* Return:
*/
void check_over_limit(ovLFault_t *fhand, float value)
{
	if(fhand->ovlFault!=1){
	//check if the quantity is above the threshold
		if(value > (float)fhand->threshold){
			fhand->ovlCount = fhand->ovlCount + 1;
		}else{
			fhand->ovlCount = 0;
		}

		//check if the quantity is above the threshold for given time
		// This function is called every 1 sec. So the below expression will be evaluated as 50 * 100/1000 = 5. Which means we have a
		// threshold time of 5 counts or simply 5 seconds. By changing the value of fhand->threshold_time we are changing the final counts
		// They are integral values of 1 seconds. Bu the minimum resolution will be 1sec since the function is called every 1 sec
		if(fhand->ovlCount > (fhand->sampleFreq*fhand->threshold_time)){
			fhand->ovlCount = 0;
			fhand->ovlFault = 1;
		}
	}else{
		//try auto reset if the fault is not latched
		if(fhand->autoreset && (!fhand->ovlFaultLatched)){
		 //check if the voltage is below the reset threshold
			if(value < (float)fhand->reset_threshold){
				fhand->ovlResetCount = fhand->ovlResetCount + 1;
			}else{
				fhand->ovlResetCount =0;
			}
			//check if the quantity is below the reset threshold for given time
			if(fhand->ovlResetCount > (fhand->sampleFreq*fhand->reset_threshold_time)){
				fhand->ovlResetCount = 0;
				fhand->ovlFault = 0;
				fhand->ovlNoOfReset = fhand->ovlNoOfReset + 1;
			}
		}
	}
	//cool down time means that "no_of_reset" will be reduced by one for every given time
	//this is to prevent the fault accumulation.
	//example: if one over voltage fault occurred today and next one occurred previous week
	//with COOLDOWN_ENABLE "no_of_reset" will be 1
	//without COOLDOWN_ENABLE "no_of_reset" will be 2
	if(fhand->cooldown_enable){
		if(fhand->ovlNoOfReset > 0){
			fhand->ovlCoolDownCount = fhand->ovlCoolDownCount + 1;
			if(fhand->ovlCoolDownCount > (fhand->sampleFreq*fhand->cooldown_time)){
				fhand->ovlCoolDownCount = 0;
				fhand->ovlNoOfReset = fhand->ovlNoOfReset - 1;
			}
		}
	}
	//if the fault is reset for given number of times, latch the fault
	if(fhand->ovlNoOfReset > fhand->no_of_reset){
		fhand->ovlNoOfReset = 0;
		fhand->ovlFaultLatched = 1;
	}
}

/*
* Function Description: To check under limit of quantities
* Input:
* Return:
*/
void check_under_limit(underLFault_t *fhand, float value){
	if(fhand->underLFault!=1){
		//check if the quantity is below the threshold
			if(value < (float)fhand->threshold){
				fhand->underLCount = fhand->underLCount + 1;
			}else{
				fhand->underLCount = 0;
			}

			//check if the quantity is below the threshold for given time
			if(fhand->underLCount < (fhand->sampleFreq*fhand->threshold_time)){
				fhand->underLCount = 0;
				fhand->underLFault = 1;
			}
		}else{
			//try auto reset if the fault is not latched
			if(fhand->autoreset && (!fhand->underLFaultLatched)){
			 //check if the voltage is above the reset threshold
				if(value > (float)fhand->reset_threshold){
					fhand->underLResetCount = fhand->underLResetCount + 1;
				}else{
					fhand->underLResetCount =0;
				}
				//check if the quantity is above the reset threshold for given time
				if(fhand->underLResetCount < (fhand->sampleFreq*fhand->reset_threshold_time)){
					fhand->underLResetCount = 0;
					fhand->underLFault = 0;
					fhand->underLNoOfReset = fhand->underLNoOfReset + 1;
				}
			}
		}
	//cool down time means that "no_of_reset" will be reduced by one for every given time
	//this is to prevent the fault accumulation.
	//example: if one over voltage fault occurred today and next one occurred previous week
	//with COOLDOWN_ENABLE "no_of_reset" will be 1
	//without COOLDOWN_ENABLE "no_of_reset" will be 2
	if(fhand->cooldown_enable){
		if(fhand->underLNoOfReset > 0){
			fhand->underLCoolDownCount = fhand->underLCoolDownCount + 1;
			if(fhand->underLCoolDownCount > (fhand->sampleFreq*fhand->cooldown_time)){
				fhand->underLCoolDownCount = 0;
				fhand->underLNoOfReset = fhand->underLNoOfReset - 1;
			}
		}
	}

		//if the fault is reset for given number of times, latch the fault
		if(fhand->underLNoOfReset > fhand->no_of_reset){
			fhand->underLNoOfReset = 0;
			fhand->underLFaultLatched = 1;
		}
}

/*
 * This function checks the fuse failure
 * Check the status of fuse(digital input) and generate the fault
 * As of now fuse failure is considered a critical fault so it will not reset automatically,
 * User has to manually press a fault reset button after checking the status of fuse
 */
void check_fuse_fault(void){
	/*if (status1.bits.fuse_1 == 0){
		criticalFault2.bits.fuse1_fail = 1; //set the fuse failure fault
	}

	if(status1.bits.door_feedback ==0){
		criticalFault2.bits.door_feedback = 1;
	}

	if(status1.bits.fuse_3 ==0){
		criticalFault2.bits.fuse3_fail = 1;
	}*/
}

/*
 * This function checks the emergency fault
 * Check the status of emergency stop (digital input) and generate the fault
 */
void check_emergency_fault(void){
	if(cmd.bits.emergency_stop == 1){
		criticalFault.bits.emergency_stop =1;
	}
}

/*
 * This function checks the emergency fault
 * Check the status of emergency stop (digital input) and generate the fault
 */
void protectionMonitoring_AC()
{
	// Check for R phase over voltage setting
	check_over_limit(&RphOverVol, Vrms[R_PHASE]);
	if(RphOverVol.ovlFault)
		acVoltFault.bits.rOverVol = 1;
	else
		acVoltFault.bits.rOverVol = 0;

	// Check for R phase under voltage setting
	check_under_limit(&RphUnVol, Vrms[R_PHASE]);
	if(RphUnVol.underLFault)
		acVoltFault.bits.rUnderVol = 1;
	else
		acVoltFault.bits.rUnderVol = 0;

	// Check for Y phase over voltage setting
	check_over_limit(&YphOverVol, Vrms[Y_PHASE]);
	if(YphOverVol.ovlFault)
		acVoltFault.bits.yOverVol = 1;
	else
		acVoltFault.bits.yOverVol = 0;

	// Check for Y phase under voltage setting
	check_under_limit(&YphUnVol, Vrms[Y_PHASE]);
	if(YphUnVol.underLFault)
		acVoltFault.bits.yUnderVol = 1;
	else
		acVoltFault.bits.yUnderVol = 0;

	// Check for B phase over voltage setting
	check_over_limit(&BphOverVol, Vrms[B_PHASE]);
	if(BphOverVol.ovlFault)
		acVoltFault.bits.bOverVol = 1;
	else
		acVoltFault.bits.bOverVol = 0;

	// Check for B phase under voltage setting
	check_under_limit(&BphUnVol, Vrms[B_PHASE]);
	if(BphUnVol.underLFault)
		acVoltFault.bits.bUnderVol = 1;
	else
		acVoltFault.bits.bUnderVol = 0;

	// Check for Earth phase over voltage setting
	check_over_limit(&EphOverVol, Vrms[E_PHASE]);
	if(EphOverVol.ovlFault)
		acVoltFault.bits.eOverVol = 1;
	else
		acVoltFault.bits.eOverVol = 0;

	// Check for R phase over current setting
	check_over_limit(&RphOverCur, Irms[R_PHASE]);
	if(RphOverCur.ovlFault)
		acCurrFault.bits.rOverCur = 1;
	else
		acCurrFault.bits.rOverCur = 0;

	// Check for Y phase over current setting
	check_over_limit(&YphOverCur, Irms[Y_PHASE]);
	if(YphOverCur.ovlFault)
		acCurrFault.bits.yOverCur = 1;
	else
		acCurrFault.bits.yOverCur = 0;

	// Check for B phase over current setting
	check_over_limit(&BphOverCur, Irms[B_PHASE]);
	if(BphOverCur.ovlFault)
		acCurrFault.bits.bOverCur = 1;
	else
		acCurrFault.bits.bOverCur = 0;

	acCurrFault.bits.rUnderCur = 0;
	acCurrFault.bits.yUnderCur = 0;
	acCurrFault.bits.bUnderCur = 0;
}

/*
 * This function checks the emergency fault
 * Check the status of emergency stop (digital input) and generate the fault
 */
void protectionMonitoring_DC()
{
//	check_over_limit(&VoutOverVol, V_OUT[procValue]);
//	if(VoutOverVol.ovlFault)
//		dcFault.bits.vOutOver = 1;
//	else
		dcFault.bits.vOutOver = 0;
//
//	check_under_limit(&VoutUnVol, V_OUT[procValue]);
//	if(VoutUnVol.underLFault)
//		dcFault.bits.vOutUnder = 1;
//	else
		dcFault.bits.vOutUnder = 0;

//	check_over_limit(&IoutOverCur, I_OUT[procValue]);
//	if(IoutOverCur.ovlFault)
//		dcFault.bits.iOutOver = 1;
//	else
		dcFault.bits.iOutOver = 0;
}

/*
 * This function checks the emergency fault
 * Check the status of emergency stop (digital input) and generate the fault
 */
void protectionMonitoring_Temp(void)
{
	check_over_limit(&ntc1OverTemp, ntc1_temp);
	if(ntc1OverTemp.ovlFault)
		tempFault.bits.ntc1OverTemp = 1;
	else
		tempFault.bits.ntc1OverTemp = 0;

	check_over_limit(&ntc1OverTemp, ntc2_temp);
	if(ntc2OverTemp.ovlFault)
		tempFault.bits.ntc2OverTemp = 1;
	else
		tempFault.bits.ntc2OverTemp = 0;
}

/*
 * This function will try to reset the fault if the faults are no longer present.
 * whenever cmd.bits.fault_reset = 1; this function will be executed once
 */
void manual_fault_reset(void){
//	cmd.bits.fault_reset = 0;

//	if(/*slaveFaultFlag == 0 && */cmd.bits.fault_reset == 1)
	if(slaveFaultFlag == 0 && cmd.bits.fault_reset == 1)
	{
		//check if the fault is there and the fault condition is no longer present then reset the fault.
		//Fuse1 failure
		if(criticalFault2.bits.fuse1_fail == 1){
			if(status1.bits.fuse_1 == 1){
				criticalFault2.bits.fuse1_fail = 0;
			}
		}

		//Fuse2 failure
		if(criticalFault2.bits.door_feedback == 1){
			if(status1.bits.door_feedback == 1){
				criticalFault2.bits.door_feedback = 0;
			}
		}

		//Fuse3 failure
		if(criticalFault2.bits.fuse3_fail == 1){
			if(status1.bits.fuse_3 == 1){
				criticalFault2.bits.fuse3_fail = 0;
			}
		}

		//emergency stop reset
		if(criticalFault.bits.eeprom_fault == 1){
			if (cmd.bits.emergency_stop == 0){
				criticalFault.bits.emergency_stop = 0;
			}
		}

		if(acVoltFault.bits.rOverVol == 1)
			RphOverVol.ovlFault = 0;

		if(acVoltFault.bits.rUnderVol == 1)
			RphUnVol.underLFault = 0;

		if(acVoltFault.bits.yOverVol == 1)
			YphOverVol.ovlFault = 0;

		if(acVoltFault.bits.yUnderVol == 1)
			YphUnVol.underLFault = 0;

		if(acVoltFault.bits.bOverVol == 1)
			BphOverVol.ovlFault = 0;

		if(acVoltFault.bits.bUnderVol == 1)
			BphUnVol.underLFault = 0;

		if(acVoltFault.bits.eOverVol == 1)
			EphOverVol.ovlFault = 0;

		if(acCurrFault.bits.rOverCur == 1)
			RphOverCur.ovlFault = 0;

		if(acCurrFault.bits.yOverCur == 1)
			YphOverCur.ovlFault = 0;

		if(acCurrFault.bits.bOverCur == 1)
			BphOverCur.ovlFault = 0;

		if(dcFault.bits.vOutOver == 1)
			VoutOverVol.ovlFault = 0;

		if(dcFault.bits.vOutUnder == 1)
			VoutUnVol.underLFault = 0;

		if(dcFault.bits.iOutOver == 1)
			IoutOverCur.ovlFault = 0;

		if(tempFault.bits.ntc1OverTemp == 1)
			ntc1OverTemp.ovlFault = 0;

		if(tempFault.bits.ntc2OverTemp == 1)
			ntc2OverTemp.ovlFault = 0;

		PSFBFeedbackWaitFlag = 0;
		masterFaultFlag = 0;
		cmd.bits.fault_reset = 0;
	}

}
