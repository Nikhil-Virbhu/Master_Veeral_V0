/*
 * io.c
 *
 *  Created on: 25-Apr-2023
 *      Author: hp
 */
#define _IO_
#include "io.h"
#include "main.h"
#include "debug.h"
#include "protection.h"
#include "process.h"
#include "Slave_Monitoring.h"
#include"PID_Saturation.h"

uint32_t switch_stable;
uint8_t switch_change_flag;
uint16_t switch_state[5];
uint32_t new_stable;

void checkDebounce(void)
{
	uint16_t temp1,temp2,temp3,temp4,temp5,temp6,temp7,temp8,temp9;
	static uint8_t sw_state_ptr;
	static uint32_t stayed_high;
	static uint32_t stayed_low;
	static uint32_t switch_changes;


	temp1 = (uint8_t)(HAL_GPIO_ReadPin(DI0_GPIO_Port,DI0_Pin));
	temp2 = ((uint8_t)(HAL_GPIO_ReadPin(DI1_GPIO_Port,DI1_Pin)))<<1;
	temp3 = ((uint8_t)(HAL_GPIO_ReadPin(DI2_GPIO_Port,DI2_Pin)))<<2;
	temp4 = ((uint8_t)(HAL_GPIO_ReadPin(DI3_GPIO_Port,DI3_Pin)))<<3;
	temp5 = ((uint8_t)(HAL_GPIO_ReadPin(DI4_GPIO_Port,DI4_Pin)))<<4;
	temp6 = ((uint8_t)(HAL_GPIO_ReadPin(DI5_GPIO_Port,DI5_Pin)))<<5;
	temp7 = ((uint8_t)(HAL_GPIO_ReadPin(DI6_GPIO_Port,DI6_Pin)))<<6;
	temp8 = ((uint8_t)(HAL_GPIO_ReadPin(DI7_GPIO_Port,DI7_Pin)))<<7;
	temp9 = ((uint8_t)(HAL_GPIO_ReadPin(DI8_GPIO_Port,DI8_Pin)))<<8;


    //debounce inputs
    switch_state[sw_state_ptr] = temp1 | temp2 |temp3 | temp4| temp5 | temp6 | temp7 | temp8 | temp9;
    sw_state_ptr++;
    if (sw_state_ptr == 5)
    	sw_state_ptr = 0;

    stayed_high = switch_state[0] & switch_state[1] & switch_state[2] & switch_state[3] & switch_state[4];
    stayed_low = !switch_state[0] & !switch_state[1] & !switch_state[2] & !switch_state[3] & !switch_state[4];

    new_stable = (stayed_high | stayed_low);
    switch_changes = (new_stable ^ switch_stable); //switch changes, switch_stable are globals

    if(switch_changes > 0){
      switch_change_flag = 1; //set a flag to allow processing outside the interrupt (global scope)
      switch_stable = new_stable; //save new stable sta&te
    }

}

/* Function description: Function to get pin state of digital input
 *
 *
 */


void getDigiIn(void)
{

	checkDebounce();
	if (switch_change_flag == 1){
		switch_change_flag = 0;

		// Start push button
		if((switch_stable & 0x1) == 0){
			//systemOnOff();						//switch spared for DC contactor
		}

		// Reset push button
		if (((switch_stable & 0x2)>>1) == 0){
			cmd.bits.fault_reset = 1;
		}

		// Emergency stop push button
		if(((switch_stable & 0x4)>>2)==0){
			turnOff();
		}

		// AFE key
		if (((switch_stable & 0x8)>>3)==0){
			if(AFEOnFlag == 0)
				AFEOnFlag = 1;
		}

		// AFE pwm mask key
		if (((switch_stable & 0x10)>>4)==0){
			if(cmd.bits.afe_pwm_mask == 0){
				cmd.bits.afe_pwm_mask = 1;
				HAL_GPIO_WritePin(U_DB1_GPIO_Port, U_DB1_Pin, GPIO_PIN_SET);
			}
			else if(cmd.bits.afe_pwm_mask == 1){
				cmd.bits.afe_pwm_mask = 0;
				HAL_GPIO_WritePin(U_DB1_GPIO_Port, U_DB1_Pin, GPIO_PIN_RESET);
			}
		}

		// DAC2 Increment
		if (((switch_stable & 0x20)>>5)==0){
			dac2++;
			if(dac2 >= 11)
				dac2 = 1;
		}

		if (((switch_stable & 0x40)>>6)==0){ // Fuse Feedback 1
			//status1.bits.fuse_1 = 1;
			systemOnOff();
		}
		if (((switch_stable & 0x80)>>7)==0){ // Fuse Feedback 2
			status1.bits.door_feedback = 1;
		}else{
			status1.bits.door_feedback = 0;
		}
		if (((switch_stable & 0x100)>>8)==0){ // Fuse Feedback 3
			status1.bits.fuse_3 = 1;
		}
	}
}


/* Function description: Function to set pin state of the digital output
 *
 *
 */

void setDigiOut(digiOut relayNo, GPIO_PinState state)
{
	switch(relayNo){
		case OUT1:
			//HAL_GPIO_WritePin(AUX_DO1_GPIO_Port,AUX_DO1_Pin,state);  //Write digital Output
			break;
		case OUT2:
			//HAL_GPIO_WritePin(AUX_DO2_GPIO_Port,AUX_DO2_Pin,state);
			break;
		case OUT3:
			//HAL_GPIO_WritePin(AUX_DO3_GPIO_Port,AUX_DO3_Pin,state);
			break;
		case LED1:
			HAL_GPIO_WritePin(U_DB0_GPIO_Port, U_DB0_Pin, state);
			break;
		default:
		 {/*Action to be added*/}

	}
}


void generateAddress()
{
	uint8_t dswitch_states[4];
	//dswitch_states[0] = HAL_GPIO_ReadPin(SW0_GPIO_Port, SW0_Pin);
	dswitch_states[1] = HAL_GPIO_ReadPin(SW1_GPIO_Port, SW1_Pin);
	dswitch_states[2] = HAL_GPIO_ReadPin(SW2_GPIO_Port, SW2_Pin);
	dswitch_states[3] = HAL_GPIO_ReadPin(SW3_GPIO_Port, SW3_Pin);
	masterAddress = (uint16_t)((uint16_t)dswitch_states[3]<<3 | (uint16_t)dswitch_states[2]<<2 | (uint16_t)dswitch_states[1]<<1 | (uint16_t)dswitch_states[0]);
}
