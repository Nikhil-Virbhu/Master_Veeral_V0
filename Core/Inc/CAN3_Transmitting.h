/*
 * CAN3_Transmitting.h
 *
 *  Created on: Nov 21, 2023
 *      Author: ujwalpatel
 */

#ifndef INC_CAN3_TRANSMITTING_H_
#define INC_CAN3_TRANSMITTING_H_

#include "main.h"

/*CANFD-3  Master send the data to Monitor as behalf of it's self as well as all slaves
 *
 * 1) Master....
 * 2) Slave 01 to Slave 39.
 *
 *  Function name description (Master will send data monitor as frame 1 (MASTER)
 *
 *  			  (Master will send data monitor as frame 1 (SLAVE01-39))
 *
 * */

void Master_To_Monitor_Frame1_Master(uint16_t R_Phase_Volt,uint16_t Y_Phase_Volt,uint16_t B_Phase_Volt,float R_Phase_Current,float Y_Phase_Current, float B_Phase_Current,uint16_t System_Active_Power, float Power_Factor,
		float System_Freq, uint16_t Output_Voltage, uint16_t Output_Current, uint16_t Output_Power, uint16_t Mfault1, uint16_t Mfault2, uint16_t Mfault3,uint16_t Mfault4,
		uint16_t Mfault5,uint16_t Mfault6,uint16_t Mfault7,uint16_t Mfault8,uint16_t Mfault9,uint16_t Mfault10,uint16_t Mstatus1,uint16_t Mstatus2,
		uint16_t Mstatus3,uint16_t Mstatus4,uint16_t Mstatus5,uint16_t Mstatus6,uint16_t Mstatus7,uint16_t Mstatus8,uint16_t Mstatus9,uint16_t Mstatus10);

void Master_To_Monitor_Frame2_Slave1(float Diode_Temperature,float Transformer_Temperature,float FEC_Temperature,float PSFB_Temperature,float DC_Busvoltage,float DC_Bus_Current,float FEC_input_Current,float PSFB_Output_Voltage,
		float PSFB_Output_Current,uint16_t SFault1_2,uint16_t SFault3_4,uint16_t SFault5_6,uint16_t SFault7_8,uint16_t SStatus1_2,uint16_t SStatus3_4,uint16_t RSVD_1,
		uint16_t RSVD_2,uint16_t RSVD_3,uint16_t RSVD_4,uint16_t RSVD_5,uint16_t RSVD_6,uint16_t RSVD_7,uint16_t RSVD_8,uint16_t RSVD_9,
		uint16_t RSVD_10,uint16_t RSVD_11,uint16_t RSVD_12,uint16_t RSVD_13,uint16_t RSVD_14,uint16_t RSVD_15,uint16_t RSVD_16,uint16_t RSVD_17);

void Master_To_Monitor_Frame3_Slave2(float Diode_Temperature,float Transformer_Temperature,float FEC_Temperature,float PSFB_Temperature,float DC_Busvoltage,float DC_Bus_Current,float FEC_input_Current,float PSFB_Output_Voltage,
		float PSFB_Output_Current,uint16_t SFault1_2,uint16_t SFault3_4,uint16_t SFault5_6,uint16_t SFault7_8,uint16_t SStatus1_2,uint16_t SStatus3_4,uint16_t RSVD_1,
		uint16_t RSVD_2,uint16_t RSVD_3,uint16_t RSVD_4,uint16_t RSVD_5,uint16_t RSVD_6,uint16_t RSVD_7,uint16_t RSVD_8,uint16_t RSVD_9,
		uint16_t RSVD_10,uint16_t RSVD_11,uint16_t RSVD_12,uint16_t RSVD_13,uint16_t RSVD_14,uint16_t RSVD_15,uint16_t RSVD_16,uint16_t RSVD_17);

void Master_To_Monitor_Frame4_Slave3(float Diode_Temperature,float Transformer_Temperature,float FEC_Temperature,float PSFB_Temperature,float DC_Busvoltage,float DC_Bus_Current,float FEC_input_Current,float PSFB_Output_Voltage,
		float PSFB_Output_Current,uint16_t SFault1_2,uint16_t SFault3_4,uint16_t SFault5_6,uint16_t SFault7_8,uint16_t SStatus1_2,uint16_t SStatus3_4,uint16_t RSVD_1,
		uint16_t RSVD_2,uint16_t RSVD_3,uint16_t RSVD_4,uint16_t RSVD_5,uint16_t RSVD_6,uint16_t RSVD_7,uint16_t RSVD_8,uint16_t RSVD_9,
		uint16_t RSVD_10,uint16_t RSVD_11,uint16_t RSVD_12,uint16_t RSVD_13,uint16_t RSVD_14,uint16_t RSVD_15,uint16_t RSVD_16,uint16_t RSVD_17);

void Master_To_Monitor_Frame5_Slave4(float Diode_Temperature,float Transformer_Temperature,float FEC_Temperature,float PSFB_Temperature,float DC_Busvoltage,float DC_Bus_Current,float FEC_input_Current,float PSFB_Output_Voltage,
		float PSFB_Output_Current,uint16_t SFault1_2,uint16_t SFault3_4,uint16_t SFault5_6,uint16_t SFault7_8,uint16_t SStatus1_2,uint16_t SStatus3_4,uint16_t RSVD_1,
		uint16_t RSVD_2,uint16_t RSVD_3,uint16_t RSVD_4,uint16_t RSVD_5,uint16_t RSVD_6,uint16_t RSVD_7,uint16_t RSVD_8,uint16_t RSVD_9,
		uint16_t RSVD_10,uint16_t RSVD_11,uint16_t RSVD_12,uint16_t RSVD_13,uint16_t RSVD_14,uint16_t RSVD_15,uint16_t RSVD_16,uint16_t RSVD_17);

void Master_To_Monitor_Frame6_Slave5(float Diode_Temperature,float Transformer_Temperature,float FEC_Temperature,float PSFB_Temperature,float DC_Busvoltage,float DC_Bus_Current,float FEC_input_Current,float PSFB_Output_Voltage,
		float PSFB_Output_Current,uint16_t SFault1_2,uint16_t SFault3_4,uint16_t SFault5_6,uint16_t SFault7_8,uint16_t SStatus1_2,uint16_t SStatus3_4,uint16_t RSVD_1,
		uint16_t RSVD_2,uint16_t RSVD_3,uint16_t RSVD_4,uint16_t RSVD_5,uint16_t RSVD_6,uint16_t RSVD_7,uint16_t RSVD_8,uint16_t RSVD_9,
		uint16_t RSVD_10,uint16_t RSVD_11,uint16_t RSVD_12,uint16_t RSVD_13,uint16_t RSVD_14,uint16_t RSVD_15,uint16_t RSVD_16,uint16_t RSVD_17);

void Master_To_Monitor_Frame7_Slave6(float Diode_Temperature,float Transformer_Temperature,float FEC_Temperature,float PSFB_Temperature,float DC_Busvoltage,float DC_Bus_Current,float FEC_input_Current,float PSFB_Output_Voltage,
		float PSFB_Output_Current,uint16_t SFault1_2,uint16_t SFault3_4,uint16_t SFault5_6,uint16_t SFault7_8,uint16_t SStatus1_2,uint16_t SStatus3_4,uint16_t RSVD_1,
		uint16_t RSVD_2,uint16_t RSVD_3,uint16_t RSVD_4,uint16_t RSVD_5,uint16_t RSVD_6,uint16_t RSVD_7,uint16_t RSVD_8,uint16_t RSVD_9,
		uint16_t RSVD_10,uint16_t RSVD_11,uint16_t RSVD_12,uint16_t RSVD_13,uint16_t RSVD_14,uint16_t RSVD_15,uint16_t RSVD_16,uint16_t RSVD_17);

void Master_To_Monitor_Frame8_Slave7(float Diode_Temperature,float Transformer_Temperature,float FEC_Temperature,float PSFB_Temperature,float DC_Busvoltage,float DC_Bus_Current,float FEC_input_Current,float PSFB_Output_Voltage,
		float PSFB_Output_Current,uint16_t SFault1_2,uint16_t SFault3_4,uint16_t SFault5_6,uint16_t SFault7_8,uint16_t SStatus1_2,uint16_t SStatus3_4,uint16_t RSVD_1,
		uint16_t RSVD_2,uint16_t RSVD_3,uint16_t RSVD_4,uint16_t RSVD_5,uint16_t RSVD_6,uint16_t RSVD_7,uint16_t RSVD_8,uint16_t RSVD_9,
		uint16_t RSVD_10,uint16_t RSVD_11,uint16_t RSVD_12,uint16_t RSVD_13,uint16_t RSVD_14,uint16_t RSVD_15,uint16_t RSVD_16,uint16_t RSVD_17);

void Master_To_Monitor_Frame9_Slave8(float Diode_Temperature,float Transformer_Temperature,float FEC_Temperature,float PSFB_Temperature,float DC_Busvoltage,float DC_Bus_Current,float FEC_input_Current,float PSFB_Output_Voltage,
		float PSFB_Output_Current,uint16_t SFault1_2,uint16_t SFault3_4,uint16_t SFault5_6,uint16_t SFault7_8,uint16_t SStatus1_2,uint16_t SStatus3_4,uint16_t RSVD_1,
		uint16_t RSVD_2,uint16_t RSVD_3,uint16_t RSVD_4,uint16_t RSVD_5,uint16_t RSVD_6,uint16_t RSVD_7,uint16_t RSVD_8,uint16_t RSVD_9,
		uint16_t RSVD_10,uint16_t RSVD_11,uint16_t RSVD_12,uint16_t RSVD_13,uint16_t RSVD_14,uint16_t RSVD_15,uint16_t RSVD_16,uint16_t RSVD_17);

void Master_To_Monitor_Frame10_Slave9(float Diode_Temperature,float Transformer_Temperature,float FEC_Temperature,float PSFB_Temperature,float DC_Busvoltage,float DC_Bus_Current,float FEC_input_Current,float PSFB_Output_Voltage,
		float PSFB_Output_Current,uint16_t SFault1_2,uint16_t SFault3_4,uint16_t SFault5_6,uint16_t SFault7_8,uint16_t SStatus1_2,uint16_t SStatus3_4,uint16_t RSVD_1,
		uint16_t RSVD_2,uint16_t RSVD_3,uint16_t RSVD_4,uint16_t RSVD_5,uint16_t RSVD_6,uint16_t RSVD_7,uint16_t RSVD_8,uint16_t RSVD_9,
		uint16_t RSVD_10,uint16_t RSVD_11,uint16_t RSVD_12,uint16_t RSVD_13,uint16_t RSVD_14,uint16_t RSVD_15,uint16_t RSVD_16,uint16_t RSVD_17);

void Master_To_Monitor_Frame11_Slave10(float Diode_Temperature,float Transformer_Temperature,float FEC_Temperature,float PSFB_Temperature,float DC_Busvoltage,float DC_Bus_Current,float FEC_input_Current,float PSFB_Output_Voltage,
		float PSFB_Output_Current,uint16_t SFault1_2,uint16_t SFault3_4,uint16_t SFault5_6,uint16_t SFault7_8,uint16_t SStatus1_2,uint16_t SStatus3_4,uint16_t RSVD_1,
		uint16_t RSVD_2,uint16_t RSVD_3,uint16_t RSVD_4,uint16_t RSVD_5,uint16_t RSVD_6,uint16_t RSVD_7,uint16_t RSVD_8,uint16_t RSVD_9,
		uint16_t RSVD_10,uint16_t RSVD_11,uint16_t RSVD_12,uint16_t RSVD_13,uint16_t RSVD_14,uint16_t RSVD_15,uint16_t RSVD_16,uint16_t RSVD_17);

void Master_To_Monitor_Frame12_Slave11(float Diode_Temperature,float Transformer_Temperature,float FEC_Temperature,float PSFB_Temperature,float DC_Busvoltage,float DC_Bus_Current,float FEC_input_Current,float PSFB_Output_Voltage,
		float PSFB_Output_Current,uint16_t SFault1_2,uint16_t SFault3_4,uint16_t SFault5_6,uint16_t SFault7_8,uint16_t SStatus1_2,uint16_t SStatus3_4,uint16_t RSVD_1,
		uint16_t RSVD_2,uint16_t RSVD_3,uint16_t RSVD_4,uint16_t RSVD_5,uint16_t RSVD_6,uint16_t RSVD_7,uint16_t RSVD_8,uint16_t RSVD_9,
		uint16_t RSVD_10,uint16_t RSVD_11,uint16_t RSVD_12,uint16_t RSVD_13,uint16_t RSVD_14,uint16_t RSVD_15,uint16_t RSVD_16,uint16_t RSVD_17);

void Master_To_Monitor_Frame13_Slave12(float Diode_Temperature,float Transformer_Temperature,float FEC_Temperature,float PSFB_Temperature,float DC_Busvoltage,float DC_Bus_Current,float FEC_input_Current,float PSFB_Output_Voltage,
		float PSFB_Output_Current,uint16_t SFault1_2,uint16_t SFault3_4,uint16_t SFault5_6,uint16_t SFault7_8,uint16_t SStatus1_2,uint16_t SStatus3_4,uint16_t RSVD_1,
		uint16_t RSVD_2,uint16_t RSVD_3,uint16_t RSVD_4,uint16_t RSVD_5,uint16_t RSVD_6,uint16_t RSVD_7,uint16_t RSVD_8,uint16_t RSVD_9,
		uint16_t RSVD_10,uint16_t RSVD_11,uint16_t RSVD_12,uint16_t RSVD_13,uint16_t RSVD_14,uint16_t RSVD_15,uint16_t RSVD_16,uint16_t RSVD_17);

void Master_To_Monitor_Frame14_Slave13(float Diode_Temperature,float Transformer_Temperature,float FEC_Temperature,float PSFB_Temperature,float DC_Busvoltage,float DC_Bus_Current,float FEC_input_Current,float PSFB_Output_Voltage,
		float PSFB_Output_Current,uint16_t SFault1_2,uint16_t SFault3_4,uint16_t SFault5_6,uint16_t SFault7_8,uint16_t SStatus1_2,uint16_t SStatus3_4,uint16_t RSVD_1,
		uint16_t RSVD_2,uint16_t RSVD_3,uint16_t RSVD_4,uint16_t RSVD_5,uint16_t RSVD_6,uint16_t RSVD_7,uint16_t RSVD_8,uint16_t RSVD_9,
		uint16_t RSVD_10,uint16_t RSVD_11,uint16_t RSVD_12,uint16_t RSVD_13,uint16_t RSVD_14,uint16_t RSVD_15,uint16_t RSVD_16,uint16_t RSVD_17);

void Master_To_Monitor_Frame15_Slave14(float Diode_Temperature,float Transformer_Temperature,float FEC_Temperature,float PSFB_Temperature,float DC_Busvoltage,float DC_Bus_Current,float FEC_input_Current,float PSFB_Output_Voltage,
		float PSFB_Output_Current,uint16_t SFault1_2,uint16_t SFault3_4,uint16_t SFault5_6,uint16_t SFault7_8,uint16_t SStatus1_2,uint16_t SStatus3_4,uint16_t RSVD_1,
		uint16_t RSVD_2,uint16_t RSVD_3,uint16_t RSVD_4,uint16_t RSVD_5,uint16_t RSVD_6,uint16_t RSVD_7,uint16_t RSVD_8,uint16_t RSVD_9,
		uint16_t RSVD_10,uint16_t RSVD_11,uint16_t RSVD_12,uint16_t RSVD_13,uint16_t RSVD_14,uint16_t RSVD_15,uint16_t RSVD_16,uint16_t RSVD_17);

void Master_To_Monitor_Frame16_Slave15(float Diode_Temperature,float Transformer_Temperature,float FEC_Temperature,float PSFB_Temperature,float DC_Busvoltage,float DC_Bus_Current,float FEC_input_Current,float PSFB_Output_Voltage,
		float PSFB_Output_Current,uint16_t SFault1_2,uint16_t SFault3_4,uint16_t SFault5_6,uint16_t SFault7_8,uint16_t SStatus1_2,uint16_t SStatus3_4,uint16_t RSVD_1,
		uint16_t RSVD_2,uint16_t RSVD_3,uint16_t RSVD_4,uint16_t RSVD_5,uint16_t RSVD_6,uint16_t RSVD_7,uint16_t RSVD_8,uint16_t RSVD_9,
		uint16_t RSVD_10,uint16_t RSVD_11,uint16_t RSVD_12,uint16_t RSVD_13,uint16_t RSVD_14,uint16_t RSVD_15,uint16_t RSVD_16,uint16_t RSVD_17);

void Master_To_Monitor_Frame17_Slave16(float Diode_Temperature,float Transformer_Temperature,float FEC_Temperature,float PSFB_Temperature,float DC_Busvoltage,float DC_Bus_Current,float FEC_input_Current,float PSFB_Output_Voltage,
		float PSFB_Output_Current,uint16_t SFault1_2,uint16_t SFault3_4,uint16_t SFault5_6,uint16_t SFault7_8,uint16_t SStatus1_2,uint16_t SStatus3_4,uint16_t RSVD_1,
		uint16_t RSVD_2,uint16_t RSVD_3,uint16_t RSVD_4,uint16_t RSVD_5,uint16_t RSVD_6,uint16_t RSVD_7,uint16_t RSVD_8,uint16_t RSVD_9,
		uint16_t RSVD_10,uint16_t RSVD_11,uint16_t RSVD_12,uint16_t RSVD_13,uint16_t RSVD_14,uint16_t RSVD_15,uint16_t RSVD_16,uint16_t RSVD_17);

void Master_To_Monitor_Frame18_Slave17(float Diode_Temperature,float Transformer_Temperature,float FEC_Temperature,float PSFB_Temperature,float DC_Busvoltage,float DC_Bus_Current,float FEC_input_Current,float PSFB_Output_Voltage,
		float PSFB_Output_Current,uint16_t SFault1_2,uint16_t SFault3_4,uint16_t SFault5_6,uint16_t SFault7_8,uint16_t SStatus1_2,uint16_t SStatus3_4,uint16_t RSVD_1,
		uint16_t RSVD_2,uint16_t RSVD_3,uint16_t RSVD_4,uint16_t RSVD_5,uint16_t RSVD_6,uint16_t RSVD_7,uint16_t RSVD_8,uint16_t RSVD_9,
		uint16_t RSVD_10,uint16_t RSVD_11,uint16_t RSVD_12,uint16_t RSVD_13,uint16_t RSVD_14,uint16_t RSVD_15,uint16_t RSVD_16,uint16_t RSVD_17);

void Master_To_Monitor_Frame19_Slave18(float Diode_Temperature,float Transformer_Temperature,float FEC_Temperature,float PSFB_Temperature,float DC_Busvoltage,float DC_Bus_Current,float FEC_input_Current,float PSFB_Output_Voltage,
		float PSFB_Output_Current,uint16_t SFault1_2,uint16_t SFault3_4,uint16_t SFault5_6,uint16_t SFault7_8,uint16_t SStatus1_2,uint16_t SStatus3_4,uint16_t RSVD_1,
		uint16_t RSVD_2,uint16_t RSVD_3,uint16_t RSVD_4,uint16_t RSVD_5,uint16_t RSVD_6,uint16_t RSVD_7,uint16_t RSVD_8,uint16_t RSVD_9,
		uint16_t RSVD_10,uint16_t RSVD_11,uint16_t RSVD_12,uint16_t RSVD_13,uint16_t RSVD_14,uint16_t RSVD_15,uint16_t RSVD_16,uint16_t RSVD_17);

void Master_To_Monitor_Frame20_Slave19(float Diode_Temperature,float Transformer_Temperature,float FEC_Temperature,float PSFB_Temperature,float DC_Busvoltage,float DC_Bus_Current,float FEC_input_Current,float PSFB_Output_Voltage,
		float PSFB_Output_Current,uint16_t SFault1_2,uint16_t SFault3_4,uint16_t SFault5_6,uint16_t SFault7_8,uint16_t SStatus1_2,uint16_t SStatus3_4,uint16_t RSVD_1,
		uint16_t RSVD_2,uint16_t RSVD_3,uint16_t RSVD_4,uint16_t RSVD_5,uint16_t RSVD_6,uint16_t RSVD_7,uint16_t RSVD_8,uint16_t RSVD_9,
		uint16_t RSVD_10,uint16_t RSVD_11,uint16_t RSVD_12,uint16_t RSVD_13,uint16_t RSVD_14,uint16_t RSVD_15,uint16_t RSVD_16,uint16_t RSVD_17);

void Master_To_Monitor_Frame21_Slave20(float Diode_Temperature,float Transformer_Temperature,float FEC_Temperature,float PSFB_Temperature,float DC_Busvoltage,float DC_Bus_Current,float FEC_input_Current,float PSFB_Output_Voltage,
		float PSFB_Output_Current,uint16_t SFault1_2,uint16_t SFault3_4,uint16_t SFault5_6,uint16_t SFault7_8,uint16_t SStatus1_2,uint16_t SStatus3_4,uint16_t RSVD_1,
		uint16_t RSVD_2,uint16_t RSVD_3,uint16_t RSVD_4,uint16_t RSVD_5,uint16_t RSVD_6,uint16_t RSVD_7,uint16_t RSVD_8,uint16_t RSVD_9,
		uint16_t RSVD_10,uint16_t RSVD_11,uint16_t RSVD_12,uint16_t RSVD_13,uint16_t RSVD_14,uint16_t RSVD_15,uint16_t RSVD_16,uint16_t RSVD_17);

void Master_To_Monitor_Frame22_Slave21(float Diode_Temperature,float Transformer_Temperature,float FEC_Temperature,float PSFB_Temperature,float DC_Busvoltage,float DC_Bus_Current,float FEC_input_Current,float PSFB_Output_Voltage,
		float PSFB_Output_Current,uint16_t SFault1_2,uint16_t SFault3_4,uint16_t SFault5_6,uint16_t SFault7_8,uint16_t SStatus1_2,uint16_t SStatus3_4,uint16_t RSVD_1,
		uint16_t RSVD_2,uint16_t RSVD_3,uint16_t RSVD_4,uint16_t RSVD_5,uint16_t RSVD_6,uint16_t RSVD_7,uint16_t RSVD_8,uint16_t RSVD_9,
		uint16_t RSVD_10,uint16_t RSVD_11,uint16_t RSVD_12,uint16_t RSVD_13,uint16_t RSVD_14,uint16_t RSVD_15,uint16_t RSVD_16,uint16_t RSVD_17);

void Master_To_Monitor_Frame23_Slave22(float Diode_Temperature,float Transformer_Temperature,float FEC_Temperature,float PSFB_Temperature,float DC_Busvoltage,float DC_Bus_Current,float FEC_input_Current,float PSFB_Output_Voltage,
		float PSFB_Output_Current,uint16_t SFault1_2,uint16_t SFault3_4,uint16_t SFault5_6,uint16_t SFault7_8,uint16_t SStatus1_2,uint16_t SStatus3_4,uint16_t RSVD_1,
		uint16_t RSVD_2,uint16_t RSVD_3,uint16_t RSVD_4,uint16_t RSVD_5,uint16_t RSVD_6,uint16_t RSVD_7,uint16_t RSVD_8,uint16_t RSVD_9,
		uint16_t RSVD_10,uint16_t RSVD_11,uint16_t RSVD_12,uint16_t RSVD_13,uint16_t RSVD_14,uint16_t RSVD_15,uint16_t RSVD_16,uint16_t RSVD_17);

void Master_To_Monitor_Frame24_Slave23(float Diode_Temperature,float Transformer_Temperature,float FEC_Temperature,float PSFB_Temperature,float DC_Busvoltage,float DC_Bus_Current,float FEC_input_Current,float PSFB_Output_Voltage,
		float PSFB_Output_Current,uint16_t SFault1_2,uint16_t SFault3_4,uint16_t SFault5_6,uint16_t SFault7_8,uint16_t SStatus1_2,uint16_t SStatus3_4,uint16_t RSVD_1,
		uint16_t RSVD_2,uint16_t RSVD_3,uint16_t RSVD_4,uint16_t RSVD_5,uint16_t RSVD_6,uint16_t RSVD_7,uint16_t RSVD_8,uint16_t RSVD_9,
		uint16_t RSVD_10,uint16_t RSVD_11,uint16_t RSVD_12,uint16_t RSVD_13,uint16_t RSVD_14,uint16_t RSVD_15,uint16_t RSVD_16,uint16_t RSVD_17);

void Master_To_Monitor_Frame25_Slave24(float Diode_Temperature,float Transformer_Temperature,float FEC_Temperature,float PSFB_Temperature,float DC_Busvoltage,float DC_Bus_Current,float FEC_input_Current,float PSFB_Output_Voltage,
		float PSFB_Output_Current,uint16_t SFault1_2,uint16_t SFault3_4,uint16_t SFault5_6,uint16_t SFault7_8,uint16_t SStatus1_2,uint16_t SStatus3_4,uint16_t RSVD_1,
		uint16_t RSVD_2,uint16_t RSVD_3,uint16_t RSVD_4,uint16_t RSVD_5,uint16_t RSVD_6,uint16_t RSVD_7,uint16_t RSVD_8,uint16_t RSVD_9,
		uint16_t RSVD_10,uint16_t RSVD_11,uint16_t RSVD_12,uint16_t RSVD_13,uint16_t RSVD_14,uint16_t RSVD_15,uint16_t RSVD_16,uint16_t RSVD_17);

void Master_To_Monitor_Frame26_Slave25(float Diode_Temperature,float Transformer_Temperature,float FEC_Temperature,float PSFB_Temperature,float DC_Busvoltage,float DC_Bus_Current,float FEC_input_Current,float PSFB_Output_Voltage,
		float PSFB_Output_Current,uint16_t SFault1_2,uint16_t SFault3_4,uint16_t SFault5_6,uint16_t SFault7_8,uint16_t SStatus1_2,uint16_t SStatus3_4,uint16_t RSVD_1,
		uint16_t RSVD_2,uint16_t RSVD_3,uint16_t RSVD_4,uint16_t RSVD_5,uint16_t RSVD_6,uint16_t RSVD_7,uint16_t RSVD_8,uint16_t RSVD_9,
		uint16_t RSVD_10,uint16_t RSVD_11,uint16_t RSVD_12,uint16_t RSVD_13,uint16_t RSVD_14,uint16_t RSVD_15,uint16_t RSVD_16,uint16_t RSVD_17);

void Master_To_Monitor_Frame27_Slave26(float Diode_Temperature,float Transformer_Temperature,float FEC_Temperature,float PSFB_Temperature,float DC_Busvoltage,float DC_Bus_Current,float FEC_input_Current,float PSFB_Output_Voltage,
		float PSFB_Output_Current,uint16_t SFault1_2,uint16_t SFault3_4,uint16_t SFault5_6,uint16_t SFault7_8,uint16_t SStatus1_2,uint16_t SStatus3_4,uint16_t RSVD_1,
		uint16_t RSVD_2,uint16_t RSVD_3,uint16_t RSVD_4,uint16_t RSVD_5,uint16_t RSVD_6,uint16_t RSVD_7,uint16_t RSVD_8,uint16_t RSVD_9,
		uint16_t RSVD_10,uint16_t RSVD_11,uint16_t RSVD_12,uint16_t RSVD_13,uint16_t RSVD_14,uint16_t RSVD_15,uint16_t RSVD_16,uint16_t RSVD_17);

void Master_To_Monitor_Frame28_Slave27(float Diode_Temperature,float Transformer_Temperature,float FEC_Temperature,float PSFB_Temperature,float DC_Busvoltage,float DC_Bus_Current,float FEC_input_Current,float PSFB_Output_Voltage,
		float PSFB_Output_Current,uint16_t SFault1_2,uint16_t SFault3_4,uint16_t SFault5_6,uint16_t SFault7_8,uint16_t SStatus1_2,uint16_t SStatus3_4,uint16_t RSVD_1,
		uint16_t RSVD_2,uint16_t RSVD_3,uint16_t RSVD_4,uint16_t RSVD_5,uint16_t RSVD_6,uint16_t RSVD_7,uint16_t RSVD_8,uint16_t RSVD_9,
		uint16_t RSVD_10,uint16_t RSVD_11,uint16_t RSVD_12,uint16_t RSVD_13,uint16_t RSVD_14,uint16_t RSVD_15,uint16_t RSVD_16,uint16_t RSVD_17);

void Master_To_Monitor_Frame29_Slave28(float Diode_Temperature,float Transformer_Temperature,float FEC_Temperature,float PSFB_Temperature,float DC_Busvoltage,float DC_Bus_Current,float FEC_input_Current,float PSFB_Output_Voltage,
		float PSFB_Output_Current,uint16_t SFault1_2,uint16_t SFault3_4,uint16_t SFault5_6,uint16_t SFault7_8,uint16_t SStatus1_2,uint16_t SStatus3_4,uint16_t RSVD_1,
		uint16_t RSVD_2,uint16_t RSVD_3,uint16_t RSVD_4,uint16_t RSVD_5,uint16_t RSVD_6,uint16_t RSVD_7,uint16_t RSVD_8,uint16_t RSVD_9,
		uint16_t RSVD_10,uint16_t RSVD_11,uint16_t RSVD_12,uint16_t RSVD_13,uint16_t RSVD_14,uint16_t RSVD_15,uint16_t RSVD_16,uint16_t RSVD_17);

void Master_To_Monitor_Frame30_Slave29(float Diode_Temperature,float Transformer_Temperature,float FEC_Temperature,float PSFB_Temperature,float DC_Busvoltage,float DC_Bus_Current,float FEC_input_Current,float PSFB_Output_Voltage,
		float PSFB_Output_Current,uint16_t SFault1_2,uint16_t SFault3_4,uint16_t SFault5_6,uint16_t SFault7_8,uint16_t SStatus1_2,uint16_t SStatus3_4,uint16_t RSVD_1,
		uint16_t RSVD_2,uint16_t RSVD_3,uint16_t RSVD_4,uint16_t RSVD_5,uint16_t RSVD_6,uint16_t RSVD_7,uint16_t RSVD_8,uint16_t RSVD_9,
		uint16_t RSVD_10,uint16_t RSVD_11,uint16_t RSVD_12,uint16_t RSVD_13,uint16_t RSVD_14,uint16_t RSVD_15,uint16_t RSVD_16,uint16_t RSVD_17);

void Master_To_Monitor_Frame31_Slave30(float Diode_Temperature,float Transformer_Temperature,float FEC_Temperature,float PSFB_Temperature,float DC_Busvoltage,float DC_Bus_Current,float FEC_input_Current,float PSFB_Output_Voltage,
		float PSFB_Output_Current,uint16_t SFault1_2,uint16_t SFault3_4,uint16_t SFault5_6,uint16_t SFault7_8,uint16_t SStatus1_2,uint16_t SStatus3_4,uint16_t RSVD_1,
		uint16_t RSVD_2,uint16_t RSVD_3,uint16_t RSVD_4,uint16_t RSVD_5,uint16_t RSVD_6,uint16_t RSVD_7,uint16_t RSVD_8,uint16_t RSVD_9,
		uint16_t RSVD_10,uint16_t RSVD_11,uint16_t RSVD_12,uint16_t RSVD_13,uint16_t RSVD_14,uint16_t RSVD_15,uint16_t RSVD_16,uint16_t RSVD_17);

void Master_To_Monitor_Frame32_Slave31(float Diode_Temperature,float Transformer_Temperature,float FEC_Temperature,float PSFB_Temperature,float DC_Busvoltage,float DC_Bus_Current,float FEC_input_Current,float PSFB_Output_Voltage,
		float PSFB_Output_Current,uint16_t SFault1_2,uint16_t SFault3_4,uint16_t SFault5_6,uint16_t SFault7_8,uint16_t SStatus1_2,uint16_t SStatus3_4,uint16_t RSVD_1,
		uint16_t RSVD_2,uint16_t RSVD_3,uint16_t RSVD_4,uint16_t RSVD_5,uint16_t RSVD_6,uint16_t RSVD_7,uint16_t RSVD_8,uint16_t RSVD_9,
		uint16_t RSVD_10,uint16_t RSVD_11,uint16_t RSVD_12,uint16_t RSVD_13,uint16_t RSVD_14,uint16_t RSVD_15,uint16_t RSVD_16,uint16_t RSVD_17);

void Master_To_Monitor_Frame33_Slave32(float Diode_Temperature,float Transformer_Temperature,float FEC_Temperature,float PSFB_Temperature,float DC_Busvoltage,float DC_Bus_Current,float FEC_input_Current,float PSFB_Output_Voltage,
		float PSFB_Output_Current,uint16_t SFault1_2,uint16_t SFault3_4,uint16_t SFault5_6,uint16_t SFault7_8,uint16_t SStatus1_2,uint16_t SStatus3_4,uint16_t RSVD_1,
		uint16_t RSVD_2,uint16_t RSVD_3,uint16_t RSVD_4,uint16_t RSVD_5,uint16_t RSVD_6,uint16_t RSVD_7,uint16_t RSVD_8,uint16_t RSVD_9,
		uint16_t RSVD_10,uint16_t RSVD_11,uint16_t RSVD_12,uint16_t RSVD_13,uint16_t RSVD_14,uint16_t RSVD_15,uint16_t RSVD_16,uint16_t RSVD_17);

void Master_To_Monitor_Frame34_Slave33(float Diode_Temperature,float Transformer_Temperature,float FEC_Temperature,float PSFB_Temperature,float DC_Busvoltage,float DC_Bus_Current,float FEC_input_Current,float PSFB_Output_Voltage,
		float PSFB_Output_Current,uint16_t SFault1_2,uint16_t SFault3_4,uint16_t SFault5_6,uint16_t SFault7_8,uint16_t SStatus1_2,uint16_t SStatus3_4,uint16_t RSVD_1,
		uint16_t RSVD_2,uint16_t RSVD_3,uint16_t RSVD_4,uint16_t RSVD_5,uint16_t RSVD_6,uint16_t RSVD_7,uint16_t RSVD_8,uint16_t RSVD_9,
		uint16_t RSVD_10,uint16_t RSVD_11,uint16_t RSVD_12,uint16_t RSVD_13,uint16_t RSVD_14,uint16_t RSVD_15,uint16_t RSVD_16,uint16_t RSVD_17);

void Master_To_Monitor_Frame35_Slave34(float Diode_Temperature,float Transformer_Temperature,float FEC_Temperature,float PSFB_Temperature,float DC_Busvoltage,float DC_Bus_Current,float FEC_input_Current,float PSFB_Output_Voltage,
		float PSFB_Output_Current,uint16_t SFault1_2,uint16_t SFault3_4,uint16_t SFault5_6,uint16_t SFault7_8,uint16_t SStatus1_2,uint16_t SStatus3_4,uint16_t RSVD_1,
		uint16_t RSVD_2,uint16_t RSVD_3,uint16_t RSVD_4,uint16_t RSVD_5,uint16_t RSVD_6,uint16_t RSVD_7,uint16_t RSVD_8,uint16_t RSVD_9,
		uint16_t RSVD_10,uint16_t RSVD_11,uint16_t RSVD_12,uint16_t RSVD_13,uint16_t RSVD_14,uint16_t RSVD_15,uint16_t RSVD_16,uint16_t RSVD_17);

void Master_To_Monitor_Frame36_Slave35(float Diode_Temperature,float Transformer_Temperature,float FEC_Temperature,float PSFB_Temperature,float DC_Busvoltage,float DC_Bus_Current,float FEC_input_Current,float PSFB_Output_Voltage,
		float PSFB_Output_Current,uint16_t SFault1_2,uint16_t SFault3_4,uint16_t SFault5_6,uint16_t SFault7_8,uint16_t SStatus1_2,uint16_t SStatus3_4,uint16_t RSVD_1,
		uint16_t RSVD_2,uint16_t RSVD_3,uint16_t RSVD_4,uint16_t RSVD_5,uint16_t RSVD_6,uint16_t RSVD_7,uint16_t RSVD_8,uint16_t RSVD_9,
		uint16_t RSVD_10,uint16_t RSVD_11,uint16_t RSVD_12,uint16_t RSVD_13,uint16_t RSVD_14,uint16_t RSVD_15,uint16_t RSVD_16,uint16_t RSVD_17);

void Master_To_Monitor_Frame37_Slave36(float Diode_Temperature,float Transformer_Temperature,float FEC_Temperature,float PSFB_Temperature,float DC_Busvoltage,float DC_Bus_Current,float FEC_input_Current,float PSFB_Output_Voltage,
		float PSFB_Output_Current,uint16_t SFault1_2,uint16_t SFault3_4,uint16_t SFault5_6,uint16_t SFault7_8,uint16_t SStatus1_2,uint16_t SStatus3_4,uint16_t RSVD_1,
		uint16_t RSVD_2,uint16_t RSVD_3,uint16_t RSVD_4,uint16_t RSVD_5,uint16_t RSVD_6,uint16_t RSVD_7,uint16_t RSVD_8,uint16_t RSVD_9,
		uint16_t RSVD_10,uint16_t RSVD_11,uint16_t RSVD_12,uint16_t RSVD_13,uint16_t RSVD_14,uint16_t RSVD_15,uint16_t RSVD_16,uint16_t RSVD_17);

void Master_To_Monitor_Frame38_Slave37(float Diode_Temperature,float Transformer_Temperature,float FEC_Temperature,float PSFB_Temperature,float DC_Busvoltage,float DC_Bus_Current,float FEC_input_Current,float PSFB_Output_Voltage,
		float PSFB_Output_Current,uint16_t SFault1_2,uint16_t SFault3_4,uint16_t SFault5_6,uint16_t SFault7_8,uint16_t SStatus1_2,uint16_t SStatus3_4,uint16_t RSVD_1,
		uint16_t RSVD_2,uint16_t RSVD_3,uint16_t RSVD_4,uint16_t RSVD_5,uint16_t RSVD_6,uint16_t RSVD_7,uint16_t RSVD_8,uint16_t RSVD_9,
		uint16_t RSVD_10,uint16_t RSVD_11,uint16_t RSVD_12,uint16_t RSVD_13,uint16_t RSVD_14,uint16_t RSVD_15,uint16_t RSVD_16,uint16_t RSVD_17);

void Master_To_Monitor_Frame39_Slave38(float Diode_Temperature,float Transformer_Temperature,float FEC_Temperature,float PSFB_Temperature,float DC_Busvoltage,float DC_Bus_Current,float FEC_input_Current,float PSFB_Output_Voltage,
		float PSFB_Output_Current,uint16_t SFault1_2,uint16_t SFault3_4,uint16_t SFault5_6,uint16_t SFault7_8,uint16_t SStatus1_2,uint16_t SStatus3_4,uint16_t RSVD_1,
		uint16_t RSVD_2,uint16_t RSVD_3,uint16_t RSVD_4,uint16_t RSVD_5,uint16_t RSVD_6,uint16_t RSVD_7,uint16_t RSVD_8,uint16_t RSVD_9,
		uint16_t RSVD_10,uint16_t RSVD_11,uint16_t RSVD_12,uint16_t RSVD_13,uint16_t RSVD_14,uint16_t RSVD_15,uint16_t RSVD_16,uint16_t RSVD_17);

void Master_To_Monitor_Frame40_Slave39(float Diode_Temperature,float Transformer_Temperature,float FEC_Temperature,float PSFB_Temperature,float DC_Busvoltage,float DC_Bus_Current,float FEC_input_Current,float PSFB_Output_Voltage,
		float PSFB_Output_Current,uint16_t SFault1_2,uint16_t SFault3_4,uint16_t SFault5_6,uint16_t SFault7_8,uint16_t SStatus1_2,uint16_t SStatus3_4,uint16_t RSVD_1,
		uint16_t RSVD_2,uint16_t RSVD_3,uint16_t RSVD_4,uint16_t RSVD_5,uint16_t RSVD_6,uint16_t RSVD_7,uint16_t RSVD_8,uint16_t RSVD_9,
		uint16_t RSVD_10,uint16_t RSVD_11,uint16_t RSVD_12,uint16_t RSVD_13,uint16_t RSVD_14,uint16_t RSVD_15,uint16_t RSVD_16,uint16_t RSVD_17);

#endif /* INC_CAN3_TRANSMITTING_H_ */
