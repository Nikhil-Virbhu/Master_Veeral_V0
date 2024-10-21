/*
 * sequence.c
 *	This file will contain all the operating sequence related code.
 *  Created on: 05-Oct-2023
 *      Author: KeyurAcharya
 */

#define INC_SEQUENCE_H_
#include "sequence.h"
#include "Can_Data_Xchange.h"
#include "process.h"
#include "main.h"
#include "Slave_Monitoring.h"
#include "CAN1_Receving.h"
#include "CAN2_Receving.h"
#include "CAN3_Transmitting.h"
#include "io.h"
#include"protection.h"
#include "i2cEeprom.h"
#include "interface.h"



void task_1ms(){
	MASTER_CAN_DATA_XCHANGE();
	mSec1_Flag=0;
}


void task_40ms(){
	mSec40_Flag=0;
	checkPsfbStatus(ConfigPara.CascadedCELL * ConfigPara.totalPhases);
}

void task_100ms(){
	mSec100_Flag =0;
	//checkCAN1Status(); // CAN 1 Health/Connection Check
	//checkCAN2Status(); // CAN2 Health/Connection Check
	getDigiIn(); // Key press check
	check_fuse_fault();
	check_emergency_fault();
	if (cmd.bits.fault_reset == 1){
		manual_fault_reset();
	}

	//DC contactor CLOSE logic
	if(dc_contactor_close_flag ==1){
		DC_CONTACTOR_CLOSE;
		dc_contactor_close_wait++;
	}
	if(dc_contactor_close_wait>10){
		dc_contactor_close_wait=0;
		dc_contactor_close_flag =0;
		if(GET_DC_CONTACTOR_FB == DC_CONTACTOR_OPEN_FB)	//DC contactor did not close after the elapsed time
		{
			criticalFault2.bits. DC_contactor_fail =1;		//generate contactor fail fault
			DC_CONTACTOR_TEST_FB_FAIL;
		}
		else{
			criticalFault2.bits. DC_contactor_fail =0;
			DC_contactor_close = 1;
			DC_CONTACTOR_TEST_FB_REC;
		}
	}

	//dc contactor OPEN logic
	if(dc_contactor_open_flag ==1){
		DC_CONTACTOR_OPEN;
		dc_contactor_open_wait++;
	}
	if (dc_contactor_open_wait>10){
		dc_contactor_open_wait =0;
		dc_contactor_open_flag = 0;
		if(GET_DC_CONTACTOR_FB == DC_CONTACTOR_CLOSE_FB)	//DC contactor did not open after the elapsed time
		{
			criticalFault2.bits. DC_contactor_fail =1;		//generate contactor fail fault

		}
		else{
			criticalFault2.bits. DC_contactor_fail =0;
			dc_contactor_open_flag = 0;
		}
	}
}



void task_250ms(){
	mSec250_Flag = 0;
	if(psfbFeedback == 1 && AFEOnFlag == 0 && criticalFault.bits.can_1_fail == 0 && criticalFault.bits.can_2_fail == 0){
		HAL_GPIO_TogglePin(U_DB0_GPIO_Port, U_DB0_Pin);
	}
	if(psfbFeedback == 1 && AFEOnFlag == 1 && criticalFault.bits.can_1_fail == 0 && criticalFault.bits.can_2_fail == 0){
		setDigiOut(LED1, GPIO_PIN_SET);
	}
	//MASTER_CANFD_3_DATA_XCHNAGE();
}

void task_1s(){
	Sec1_Flag=0;
	psfbTimeout();
	//counterReset_CAN1();
	//counterReset_CAN2();
	//Serial_Out();//value debugging purpose only. comment out if not required
	tempCalculations();
	if(criticalFault.bits.can_1_fail == 1 || criticalFault.bits.can_2_fail == 1){
		HAL_GPIO_TogglePin(U_DB0_GPIO_Port, U_DB0_Pin);
	}
	if(criticalFault.bits.can_1_fail == 0 && criticalFault.bits.can_2_fail == 0 && Turn_ONOFF_Flag == 1){
		setDigiOut(LED1, GPIO_PIN_SET);
	}
	if(criticalFault.bits.can_1_fail == 0 && criticalFault.bits.can_2_fail == 0 && Turn_ONOFF_Flag == 0){
		setDigiOut(LED1, GPIO_PIN_RESET);
	}

	//TO store or load predefined values or New Values
	if(set_default_para_cmd == 1){
		set_default_para_cmd = 0;
		default_para_load();
	}
	if(para_save_cmd == 1){
		para_save_cmd = 0;
		para_save();
	}

	//To check Firmware version in each slave
	check_slave_firmware(4);
}

