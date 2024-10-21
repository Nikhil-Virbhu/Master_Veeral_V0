/*
 * CAN2_Receving.c
 *
 *  Created on: Aug 8, 2023
 *      Author: ujwalpatel
 */
#define CAN_PARAMETERS_H
#include "CAN_Parameters.h"
#include "CAN2_Receving.h"
//#include "fdcan.h"
#include "protection.h"
#include "process.h"
#include "Monitor_Master_Parameters.h"
#include "Master_Monitor_Parameter.h"
#include "PID_Saturation.h"


#define Number_1 1
#define Number_2 2
#define Number_3 3
#define Number_4 4
#define Number_5 5

#define Number_6 6
#define Number_7 7
#define Number_8 8
#define Number_9 9
#define Number_10 10

#define Number_11 11
#define Number_12 12
#define Number_13 13
#define Number_14 14
#define Number_15 15

#define Number_16 16
#define Number_17 17
#define Number_18 18
#define Number_19 19
#define Number_20 20

#define Number_21 21
#define Number_22 22
#define Number_23 23
#define Number_24 24
#define Number_25 25

#define Number_26 26
#define Number_27 27
#define Number_28 28
#define Number_29 29
#define Number_30 30

#define Number_31 31
#define Number_32 32
#define Number_33 33
#define Number_34 34
#define Number_35 35

#define Number_36 36
#define Number_37 37
#define Number_38 38
#define Number_39 39

#define FACTORDEVISION 0.1
#define OFFSET 100

master_para master1, master2, master3, master4, master5, master6;

/*extern FDCAN_RxHeaderTypeDef RxHeader_CAN1,RxHeader_CAN2;

uint8_t RXdata_Handler_CAN2[8]={0},Monitor_Master_Cmd=0,
		u8Slave_1_CAN2_Live,u8Slave_2_CAN2_Live,u8Slave_3_CAN2_Live,
		u8Slave_4_CAN2_Live,u8Slave_5_CAN2_Live,u8Slave_6_CAN2_Live;

float PC_MASTER_DATA_1,PC_MASTER_DATA_2,PC_MASTER_DATA_3,PC_MASTER_DATA_4,
PC_MASTER_DATA_5,PC_MASTER_DATA_6,PC_MASTER_DATA_7,PC_MASTER_DATA_8,PC_MASTER_DATA_9,PC_MASTER_DATA_10,
PC_MASTER_DATA_11,PC_MASTER_DATA_12,PC_MASTER_DATA_13;*/


/*void HAL_FDCAN_RxFifo1Callback(FDCAN_HandleTypeDef *hfdcan, uint32_t RxFifo1ITs)
{
	if((RxFifo1ITs & FDCAN_IT_RX_FIFO1_NEW_MESSAGE) != RESET)
	{
		 Retrieve Rx messages from RX FIFO0
#if 0
		if (HAL_FDCAN_GetRxMessage(&hfdcan1, FDCAN_RX_FIFO0, &RxHeader_CAN1, RXdata_Handler_CAN1) != HAL_OK)
		{	Error_Handler();

		}
		else
		{
			Do Nothing
		}
		switch(RxHeader_CAN2.Identifier)
		{
		case 0X1E11F101:
		{
			Configpara.DutyRef_R=RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8;
			Configpara.DutyRef_Y=RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8;
			Configpara.DutyRef_B=RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8;
			Configpara.PSFBDuty =(RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8);
		}
		break;
		default:
			break;
		}
#endif

		if (HAL_FDCAN_GetRxMessage(&hfdcan2, FDCAN_RX_FIFO1, &RxHeader_CAN2, RXdata_Handler_CAN2) != HAL_OK)
		{Error_Handler();}
		else
		{Do Nothing}

		switch(RxHeader_CAN2.Identifier)
		{
		Start

		case 0X1ED10101://0X1ED10101
		{
			u8Slave_1_CAN2_Live=RXdata_Handler_CAN2[0];
		}
		break;
		case 0X1ED1010E:
		{
			u8Slave_2_CAN2_Live=RXdata_Handler_CAN2[0];
		}
		break;
		case 0X1ED1011B:
		{
			u8Slave_3_CAN2_Live=RXdata_Handler_CAN2[0];
		}
		break;
		case 0X1ED10102://0X1ED10101
		{
			u8Slave_4_CAN2_Live=RXdata_Handler_CAN2[0];
		}
		break;
		case 0X1ED1010F:
		{
			u8Slave_5_CAN2_Live=RXdata_Handler_CAN2[0];
		}
		break;
		case 0X1ED1011C:
		{
			u8Slave_6_CAN2_Live=RXdata_Handler_CAN2[0];
		}
		break;

		START debug only PC to MASTER!!!
		case 0X1EAA0101:
		{
			ConfigPara.Kp_Vdc =((RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8)*0.01);
			ConfigPara.Ki_Vdc =((RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8)*0.01);
			ConfigPara.Kp_Iq =((RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8)*0.01);
			ConfigPara.Ki_Iq =((RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8)*0.01);

			ConfigPara.Kp_Id =((RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8)*0.001);
			ConfigPara.Ki_Id =((RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8)*0.001);
			//ConfigPara.Ki_Vdc =((RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8)*0.001);
			ConfigPara.Kp_Iq =((RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8)*0.001);
			ConfigPara.Ki_Iq =((RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8)*0.001);
		}
		break;
		case 0X1EAA0102:
		{
			VoutRef.Fix =((RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8)*0.01);
			temp_vd_calc = ((RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8)*0.1);
			PC_MASTER_DATA_7 =(RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8);
			PC_MASTER_DATA_8 =(RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8);

			//VoutRef.Fix =((RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8)*0.01);
			ConfigPara.Kp_Vdc = ((RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8)*0.001);
			ConfigPara.Ki_Vdc =((RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8 )*0.001);
			//ConfigPara.lpf_factor.Vout =((RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8)*0.001);
		}
		break;
		case 0X1EAA0103:
		{
			PC_MASTER_DATA_9 =(RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8);
			PC_MASTER_DATA_10 =(RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8);
			PC_MASTER_DATA_11 =(RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8);
			PC_MASTER_DATA_12 =(RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8);
		}
		break;
		STOP debug only PC to MASTER!!!

		case 0X1E200101:
		{
			Cell[Number_1].DCBUSVOLTAGE= (RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8)*FACTORDEVISION;
			Cell[Number_1].PSFB_INPUT_DC_CURRENT= (RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8)*FACTORDEVISION;
			Cell[Number_1].FEC_INPUT_AC_CURRENT= (RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8)*FACTORDEVISION;
			Cell[Number_1].PSFB_OUTPUT_DC_CURRENT = (RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8)*FACTORDEVISION;

			master1.cell[0].dc_bus_voltage=(RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8);
			master1.cell[0].dc_bus_current=(RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8);
			master1.cell[0].fec_input_current=(RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8);
			master1.cell[0].psfb_output_current=(RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8);
		}
		break;
		case 0X1E210101:
		{
			Cell[Number_1].PSFB_OUTPUT_DC_VOLTAGE=RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8;
			Cell[Number_1].AC_VOLTAGE_OPTIONAL=RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8;
			Cell[Number_1].AC_CURRENT_OPTIONAL=(RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8)*FACTORDEVISION;
			Cell[Number_1].TRAFO_TEMPERATURE =(RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8)*FACTORDEVISION;

			master1.cell[0].psfb_output_voltage=(RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8);
			master1.cell[0].trafo_temp=(RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8);
		}
		break;
		case 0X1E220101:
		{
			Cell[Number_1].FEC_TEMPERATURE=(RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8)*FACTORDEVISION;

			Cell[Number_1].PSFB_TEMPERATURE=(RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8)*FACTORDEVISION;

			Cell[Number_1].DIODE_TEMPERATURE=(RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8)*FACTORDEVISION;

			Cell[Number_1].Rsvd2 =(RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8);

			master1.cell[0].fec_temp=(RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8);
			master1.cell[0].psfb_temp=(RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8);
			master1.cell[0].diode_temp=(RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8);
		}
		break;
		case 0X1E230101:
		{
			Cell[Number_1].PHASE_DELAY=(RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8)*FACTORDEVISION;
			Cell[Number_1].VDC_GAIN=(RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8)*FACTORDEVISION;
			Cell[Number_1].VDC_OFFSET=(((RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8)*FACTORDEVISION)-OFFSET);
			Cell[Number_1].Rsvd3 =(RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8);
		}
		break;
		case 0X1E400101:
		{
			Cell[Number_1].Fault1=RXdata_Handler_CAN2[0];
			Cell[Number_1].Fault2=RXdata_Handler_CAN2[1];

			Cell[Number_1].Fault3=RXdata_Handler_CAN2[2];
			Cell[Number_1].Fault4=RXdata_Handler_CAN2[3];

			Cell[Number_1].Fault5.byte=RXdata_Handler_CAN2[4];
			Cell[Number_1].Fault6=RXdata_Handler_CAN2[5];

			Cell[Number_1].Fault7=RXdata_Handler_CAN2[6];
			Cell[Number_1].Fault8=RXdata_Handler_CAN2[7];

			master1.cell[0].sFault1_2.byte = (RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8);
			master1.cell[0].sFault3_4.byte = (RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8);
			master1.cell[0].sFault5_6.byte = (RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8);
			master1.cell[0].sFault7_8.byte = (RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8);
		}
		break;
		case 0X1E410101:
		{
			Cell[Number_1].Status1.byte=RXdata_Handler_CAN2[0];
			Cell[Number_1].Status2=RXdata_Handler_CAN2[1];
			Cell[Number_1].Status3=RXdata_Handler_CAN2[2];

			master1.cell[0].sStatus1_2.byte = (RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8);
			master1.cell[0].sStatus3_4.byte = (RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8);
		}
		break;
		end
		Start

		case 0X1E200102:
		{
			Cell[Number_2].DCBUSVOLTAGE= (RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8)*FACTORDEVISION;
			Cell[Number_2].PSFB_INPUT_DC_CURRENT= (RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8)*FACTORDEVISION;
			Cell[Number_2].FEC_INPUT_AC_CURRENT= (RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8)*FACTORDEVISION;
			Cell[Number_2].PSFB_OUTPUT_DC_CURRENT = (RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8)*FACTORDEVISION;

			master1.cell[1].dc_bus_voltage=(RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8);
			master1.cell[1].dc_bus_current=(RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8);
			master1.cell[1].fec_input_current=(RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8);
			master1.cell[1].psfb_output_current=(RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8);
		}
		break;
		case 0X1E210102:
		{
			Cell[Number_2].PSFB_OUTPUT_DC_VOLTAGE=RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8;
			Cell[Number_2].AC_VOLTAGE_OPTIONAL=RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8;
			Cell[Number_2].AC_CURRENT_OPTIONAL=(RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8)*FACTORDEVISION;
			Cell[Number_2].TRAFO_TEMPERATURE =(RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8)*FACTORDEVISION;

			master1.cell[1].psfb_output_voltage=(RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8);
			master1.cell[1].trafo_temp=(RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8);
		}
		break;
		case 0X1E220102:
		{
			Cell[Number_2].FEC_TEMPERATURE=(RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8)*FACTORDEVISION;
			Cell[Number_2].PSFB_TEMPERATURE=(RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8)*FACTORDEVISION;
			Cell[Number_2].DIODE_TEMPERATURE=(RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8)*FACTORDEVISION;
			Cell[Number_2].Rsvd2 =(RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8);

			master1.cell[1].fec_temp=(RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8);
			master1.cell[1].psfb_temp=(RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8);
			master1.cell[1].diode_temp=(RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8);

		}
		break;
		case 0X1E230102:
		{
			Cell[Number_2].PHASE_DELAY=(RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8)*FACTORDEVISION;
			Cell[Number_2].VDC_GAIN=(RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8)*FACTORDEVISION;
			Cell[Number_2].VDC_OFFSET=(((RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8)*FACTORDEVISION)-OFFSET);
			Cell[Number_2].Rsvd3 =(RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8);
		}
		break;
		case 0X1E400102:
		{
			Cell[Number_2].Fault1=RXdata_Handler_CAN2[0];
			Cell[Number_2].Fault2=RXdata_Handler_CAN2[1];
			Cell[Number_2].Fault3=RXdata_Handler_CAN2[2];
			Cell[Number_2].Fault4=RXdata_Handler_CAN2[3];
			Cell[Number_2].Fault5.byte=RXdata_Handler_CAN2[4];
			Cell[Number_2].Fault6=RXdata_Handler_CAN2[5];
			Cell[Number_2].Fault7=RXdata_Handler_CAN2[6];
			Cell[Number_2].Fault8=RXdata_Handler_CAN2[7];

			master1.cell[1].sFault1_2.byte = (RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8);
			master1.cell[1].sFault3_4.byte = (RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8);
			master1.cell[1].sFault5_6.byte = (RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8);
			master1.cell[1].sFault7_8.byte = (RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8);

		}
		break;
		case 0X1E410102:
		{
			Cell[Number_2].Status1.byte=RXdata_Handler_CAN2[0];
			Cell[Number_2].Status2=RXdata_Handler_CAN2[1];
			Cell[Number_2].Status3=RXdata_Handler_CAN2[2];

			master1.cell[1].sStatus1_2.byte = (RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8);
			master1.cell[1].sStatus3_4.byte = (RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8);
		}
		break;
		end
		Start
		case 0X1E200103:
		{
			Cell[Number_3].DCBUSVOLTAGE= (RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8)*FACTORDEVISION;
			Cell[Number_3].PSFB_INPUT_DC_CURRENT= (RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8)*FACTORDEVISION;
			Cell[Number_3].FEC_INPUT_AC_CURRENT= (RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8)*FACTORDEVISION;
			Cell[Number_3].PSFB_OUTPUT_DC_CURRENT = (RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8)*FACTORDEVISION;

			master1.cell[2].dc_bus_voltage=(RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8);
			master1.cell[2].dc_bus_current=(RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8);
			master1.cell[2].fec_input_current=(RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8);
			master1.cell[2].psfb_output_current=(RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8);
		}
		break;
		case 0X1E210103:
		{
			Cell[Number_3].PSFB_OUTPUT_DC_VOLTAGE=RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8;
			Cell[Number_3].AC_VOLTAGE_OPTIONAL=RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8;
			Cell[Number_3].AC_CURRENT_OPTIONAL=(RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8)*FACTORDEVISION;
			Cell[Number_3].TRAFO_TEMPERATURE =(RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8)*FACTORDEVISION;

			master1.cell[2].psfb_output_voltage=(RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8);
			master1.cell[2].trafo_temp=(RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8);

		}
		break;
		case 0X1E220103:
		{
			Cell[Number_3].FEC_TEMPERATURE=(RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8)*FACTORDEVISION;
			Cell[Number_3].PSFB_TEMPERATURE=(RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8)*FACTORDEVISION;
			Cell[Number_3].DIODE_TEMPERATURE=(RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8)*FACTORDEVISION;
			Cell[Number_3].Rsvd2 =(RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8);

			master1.cell[2].fec_temp=(RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8);
			master1.cell[2].psfb_temp=(RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8);
			master1.cell[2].diode_temp=(RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8);

		}
		break;
		case 0X1E230103:
		{
			Cell[Number_3].PHASE_DELAY=(RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8)*FACTORDEVISION;
			Cell[Number_3].VDC_GAIN=(RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8)*FACTORDEVISION;
			Cell[Number_3].VDC_OFFSET=(((RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8)*FACTORDEVISION)-OFFSET);
			Cell[Number_3].Rsvd3 =(RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8);
		}
		break;
		case 0X1E400103:
		{
			Cell[Number_3].Fault1=RXdata_Handler_CAN2[0];
			Cell[Number_3].Fault2=RXdata_Handler_CAN2[1];
			Cell[Number_3].Fault3=RXdata_Handler_CAN2[2];
			Cell[Number_3].Fault4=RXdata_Handler_CAN2[3];
			Cell[Number_3].Fault5.byte=RXdata_Handler_CAN2[4];
			Cell[Number_3].Fault6=RXdata_Handler_CAN2[5];
			Cell[Number_3].Fault7=RXdata_Handler_CAN2[6];
			Cell[Number_3].Fault8=RXdata_Handler_CAN2[7];

			master1.cell[2].sFault1_2.byte = (RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8);
			master1.cell[2].sFault3_4.byte = (RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8);
			master1.cell[2].sFault5_6.byte = (RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8);
			master1.cell[2].sFault7_8.byte = (RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8);

		}
		break;
		case 0X1E410103:
		{
			Cell[Number_3].Status1.byte=RXdata_Handler_CAN2[0];
			Cell[Number_3].Status2=RXdata_Handler_CAN2[1];
			Cell[Number_3].Status3=RXdata_Handler_CAN2[2];

			master1.cell[2].sStatus1_2.byte = (RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8);
			master1.cell[2].sStatus3_4.byte = (RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8);

		}
		break;
		end
		Start

		end
		Start
		case 0X1E200104:
		{
			Cell[Number_4].DCBUSVOLTAGE= (RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8)*FACTORDEVISION;
			Cell[Number_4].PSFB_INPUT_DC_CURRENT= (RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8)*FACTORDEVISION;
			Cell[Number_4].FEC_INPUT_AC_CURRENT= (RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8)*FACTORDEVISION;
			Cell[Number_4].PSFB_OUTPUT_DC_CURRENT = (RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8)*FACTORDEVISION;

			master1.cell[3].dc_bus_voltage=(RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8);
			master1.cell[3].dc_bus_current=(RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8);
			master1.cell[3].fec_input_current=(RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8);
			master1.cell[3].psfb_output_current=(RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8);
		}
		break;
		case 0X1E210104:
		{
			Cell[Number_4].PSFB_OUTPUT_DC_VOLTAGE=RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8;
			Cell[Number_4].AC_VOLTAGE_OPTIONAL=RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8;
			Cell[Number_4].AC_CURRENT_OPTIONAL=(RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8)*FACTORDEVISION;
			Cell[Number_4].TRAFO_TEMPERATURE =(RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8)*FACTORDEVISION;

			master1.cell[3].psfb_output_voltage=(RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8);
			master1.cell[3].trafo_temp=(RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8);
		}
		break;
		case 0X1E220104:
		{
			Cell[Number_4].FEC_TEMPERATURE=(RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8)*FACTORDEVISION;
			Cell[Number_4].PSFB_TEMPERATURE=(RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8)*FACTORDEVISION;
			Cell[Number_4].DIODE_TEMPERATURE=(RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8)*FACTORDEVISION;
			Cell[Number_4].Rsvd2 =(RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8);

			master1.cell[3].fec_temp=(RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8);
			master1.cell[3].psfb_temp=(RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8);
			master1.cell[3].diode_temp=(RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8);
		}
		break;
		case 0X1E230104:
		{
			Cell[Number_4].PHASE_DELAY=(RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8)*FACTORDEVISION;
			Cell[Number_4].VDC_GAIN=(RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8)*FACTORDEVISION;
			Cell[Number_4].VDC_OFFSET=(((RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8)*FACTORDEVISION)-OFFSET);
			Cell[Number_4].Rsvd3 =(RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8);
		}
		break;
		case 0X1E400104:
		{
			Cell[Number_4].Fault1=RXdata_Handler_CAN2[0];
			Cell[Number_4].Fault2=RXdata_Handler_CAN2[1];
			Cell[Number_4].Fault3=RXdata_Handler_CAN2[2];
			Cell[Number_4].Fault4=RXdata_Handler_CAN2[3];
			Cell[Number_4].Fault5.byte=RXdata_Handler_CAN2[4];
			Cell[Number_4].Fault6=RXdata_Handler_CAN2[5];
			Cell[Number_4].Fault7=RXdata_Handler_CAN2[6];
			Cell[Number_4].Fault8=RXdata_Handler_CAN2[7];

			master1.cell[3].sFault1_2.byte = (RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8);
			master1.cell[3].sFault3_4.byte = (RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8);
			master1.cell[3].sFault5_6.byte = (RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8);
			master1.cell[3].sFault7_8.byte = (RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8);

		}
		break;
		case 0X1E410104:
		{
			Cell[Number_4].Status1.byte=RXdata_Handler_CAN2[0];
			Cell[Number_4].Status2=RXdata_Handler_CAN2[1];
			Cell[Number_4].Status3=RXdata_Handler_CAN2[2];

			master1.cell[3].sStatus1_2.byte = (RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8);
			master1.cell[3].sStatus3_4.byte = (RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8);
		}
		break;
		end
		Start
		case 0X1E200105:
		{
			Cell[Number_5].DCBUSVOLTAGE= (RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8)*FACTORDEVISION;
			Cell[Number_5].PSFB_INPUT_DC_CURRENT= (RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8)*FACTORDEVISION;
			Cell[Number_5].FEC_INPUT_AC_CURRENT= (RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8)*FACTORDEVISION;
			Cell[Number_5].PSFB_OUTPUT_DC_CURRENT = (RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8)*FACTORDEVISION;

			master1.cell[4].dc_bus_voltage=(RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8);
			master1.cell[4].dc_bus_current=(RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8);
			master1.cell[4].fec_input_current=(RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8);
			master1.cell[4].psfb_output_current=(RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8);
		}
		break;
		case 0X1E210105:
		{
			Cell[Number_5].PSFB_OUTPUT_DC_VOLTAGE=RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8;
			Cell[Number_5].AC_VOLTAGE_OPTIONAL=RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8;
			Cell[Number_5].AC_CURRENT_OPTIONAL=(RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8)*FACTORDEVISION;
			Cell[Number_5].TRAFO_TEMPERATURE =(RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8)*FACTORDEVISION;

			master1.cell[4].psfb_output_voltage=(RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8);
			master1.cell[4].trafo_temp=(RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8);
		}
		break;
		case 0X1E220105:
		{
			Cell[Number_5].FEC_TEMPERATURE=(RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8)*FACTORDEVISION;
			Cell[Number_5].PSFB_TEMPERATURE=(RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8)*FACTORDEVISION;
			Cell[Number_5].DIODE_TEMPERATURE=(RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8)*FACTORDEVISION;
			Cell[Number_5].Rsvd2 =(RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8);

			master1.cell[4].fec_temp=(RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8);
			master1.cell[4].psfb_temp=(RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8);
			master1.cell[4].diode_temp=(RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8);
		}
		break;
		case 0X1E230105:
		{
			Cell[Number_5].PHASE_DELAY=(RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8)*FACTORDEVISION;
			Cell[Number_5].VDC_GAIN=(RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8)*FACTORDEVISION;
			Cell[Number_5].VDC_OFFSET=(((RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8)*FACTORDEVISION)-OFFSET);
			Cell[Number_5].Rsvd3 =(RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8);
		}
		break;
		case 0X1E400105:
		{
			Cell[Number_5].Fault1=RXdata_Handler_CAN2[0];
			Cell[Number_5].Fault2=RXdata_Handler_CAN2[1];
			Cell[Number_5].Fault3=RXdata_Handler_CAN2[2];
			Cell[Number_5].Fault4=RXdata_Handler_CAN2[3];
			Cell[Number_5].Fault5.byte=RXdata_Handler_CAN2[4];
			Cell[Number_5].Fault6=RXdata_Handler_CAN2[5];
			Cell[Number_5].Fault7=RXdata_Handler_CAN2[6];
			Cell[Number_5].Fault8=RXdata_Handler_CAN2[7];

			master1.cell[4].sFault1_2.byte = (RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8);
			master1.cell[4].sFault3_4.byte = (RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8);
			master1.cell[4].sFault5_6.byte = (RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8);
			master1.cell[4].sFault7_8.byte = (RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8);
		}
		break;
		case 0X1E410105:
		{
			Cell[Number_5].Status1.byte=RXdata_Handler_CAN2[0];
			Cell[Number_5].Status2=RXdata_Handler_CAN2[1];
			Cell[Number_5].Status3=RXdata_Handler_CAN2[2];

			master1.cell[4].sStatus1_2.byte = (RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8);
			master1.cell[4].sStatus3_4.byte = (RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8);
		}
		break;
		end
		Start
		case 0X1E200106:
		{
			Cell[Number_6].DCBUSVOLTAGE= (RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8)*FACTORDEVISION;
			Cell[Number_6].PSFB_INPUT_DC_CURRENT= (RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8)*FACTORDEVISION;
			Cell[Number_6].FEC_INPUT_AC_CURRENT= (RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8)*FACTORDEVISION;
			Cell[Number_6].PSFB_OUTPUT_DC_CURRENT = (RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8)*FACTORDEVISION;

			master1.cell[5].dc_bus_voltage=(RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8);
			master1.cell[5].dc_bus_current=(RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8);
			master1.cell[5].fec_input_current=(RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8);
			master1.cell[5].psfb_output_current=(RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8);
		}
		break;
		case 0X1E210106:
		{
			Cell[Number_6].PSFB_OUTPUT_DC_VOLTAGE=RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8;
			Cell[Number_6].AC_VOLTAGE_OPTIONAL=RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8;
			Cell[Number_6].AC_CURRENT_OPTIONAL=(RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8)*FACTORDEVISION;
			Cell[Number_6].TRAFO_TEMPERATURE =(RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8)*FACTORDEVISION;

			master1.cell[5].psfb_output_voltage=(RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8);
			master1.cell[5].trafo_temp=(RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8);
		}
		break;
		case 0X1E220106:
		{
			Cell[Number_6].FEC_TEMPERATURE=(RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8)*FACTORDEVISION;
			Cell[Number_6].PSFB_TEMPERATURE=(RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8)*FACTORDEVISION;
			Cell[Number_6].DIODE_TEMPERATURE=(RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8)*FACTORDEVISION;
			Cell[Number_6].Rsvd2 =(RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8);

			master1.cell[5].fec_temp=(RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8);
			master1.cell[5].psfb_temp=(RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8);
			master1.cell[5].diode_temp=(RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8);
		}
		break;
		case 0X1E230106:
		{
			Cell[Number_6].PHASE_DELAY=(RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8)*FACTORDEVISION;
			Cell[Number_6].VDC_GAIN=(RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8)*FACTORDEVISION;
			Cell[Number_6].VDC_OFFSET=(((RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8)*FACTORDEVISION)-OFFSET);
			Cell[Number_6].Rsvd3 =(RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8);
		}
		break;
		case 0X1E400106:
		{
			Cell[Number_6].Fault1=RXdata_Handler_CAN2[0];
			Cell[Number_6].Fault2=RXdata_Handler_CAN2[1];
			Cell[Number_6].Fault3=RXdata_Handler_CAN2[2];
			Cell[Number_6].Fault4=RXdata_Handler_CAN2[3];
			Cell[Number_6].Fault5.byte=RXdata_Handler_CAN2[4];
			Cell[Number_6].Fault6=RXdata_Handler_CAN2[5];
			Cell[Number_6].Fault7=RXdata_Handler_CAN2[6];
			Cell[Number_6].Fault8=RXdata_Handler_CAN2[7];

			master1.cell[5].sFault1_2.byte = (RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8);
			master1.cell[5].sFault3_4.byte = (RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8);
			master1.cell[5].sFault5_6.byte = (RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8);
			master1.cell[5].sFault7_8.byte = (RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8);
		}
		break;
		case 0X1E410106:
		{
			Cell[Number_6].Status1.byte=RXdata_Handler_CAN2[0];
			Cell[Number_6].Status2=RXdata_Handler_CAN2[1];
			Cell[Number_6].Status3=RXdata_Handler_CAN2[2];

			master1.cell[5].sStatus1_2.byte = (RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8);
			master1.cell[5].sStatus3_4.byte = (RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8);
		}
		break;
		end
		Start
		case 0X1E200107:
		{
			Cell[Number_7].DCBUSVOLTAGE= (RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8)*FACTORDEVISION;
			Cell[Number_7].PSFB_INPUT_DC_CURRENT= (RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8)*FACTORDEVISION;
			Cell[Number_7].FEC_INPUT_AC_CURRENT= (RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8)*FACTORDEVISION;
			Cell[Number_7].PSFB_OUTPUT_DC_CURRENT = (RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8)*FACTORDEVISION;

			master1.cell[6].dc_bus_voltage=(RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8);
			master1.cell[6].dc_bus_current=(RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8);
			master1.cell[6].fec_input_current=(RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8);
			master1.cell[6].psfb_output_current=(RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8);
		}
		break;
		case 0X1E210107:
		{
			Cell[Number_7].PSFB_OUTPUT_DC_VOLTAGE=RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8;
			Cell[Number_7].AC_VOLTAGE_OPTIONAL=RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8;
			Cell[Number_7].AC_CURRENT_OPTIONAL=(RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8)*FACTORDEVISION;
			Cell[Number_7].TRAFO_TEMPERATURE =(RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8)*FACTORDEVISION;

			master1.cell[6].psfb_output_voltage=(RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8);
			master1.cell[6].trafo_temp=(RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8);
		}
		break;
		case 0X1E220107:
		{
			Cell[Number_7].FEC_TEMPERATURE=(RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8)*FACTORDEVISION;
			Cell[Number_7].PSFB_TEMPERATURE=(RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8)*FACTORDEVISION;
			Cell[Number_7].DIODE_TEMPERATURE=(RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8)*FACTORDEVISION;
			Cell[Number_7].Rsvd2 =(RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8);

			master1.cell[6].fec_temp=(RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8);
			master1.cell[6].psfb_temp=(RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8);
			master1.cell[6].diode_temp=(RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8);
		}
		break;
		case 0X1E230107:
		{
			Cell[Number_7].PHASE_DELAY=(RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8)*FACTORDEVISION;
			Cell[Number_7].VDC_GAIN=(RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8)*FACTORDEVISION;
			Cell[Number_7].VDC_OFFSET=(((RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8)*FACTORDEVISION)-OFFSET);
			Cell[Number_7].Rsvd3 =(RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8);
		}
		break;
		case 0X1E400107:
		{
			Cell[Number_7].Fault1=RXdata_Handler_CAN2[0];
			Cell[Number_7].Fault2=RXdata_Handler_CAN2[1];
			Cell[Number_7].Fault3=RXdata_Handler_CAN2[2];
			Cell[Number_7].Fault4=RXdata_Handler_CAN2[3];
			Cell[Number_7].Fault5.byte=RXdata_Handler_CAN2[4];
			Cell[Number_7].Fault6=RXdata_Handler_CAN2[5];
			Cell[Number_7].Fault7=RXdata_Handler_CAN2[6];
			Cell[Number_7].Fault8=RXdata_Handler_CAN2[7];

			master1.cell[6].sFault1_2.byte = (RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8);
			master1.cell[6].sFault3_4.byte = (RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8);
			master1.cell[6].sFault5_6.byte = (RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8);
			master1.cell[6].sFault7_8.byte = (RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8);
		}
		break;
		case 0X1E410107:
		{
			Cell[Number_7].Status1.byte=RXdata_Handler_CAN2[0];
			Cell[Number_7].Status2=RXdata_Handler_CAN2[1];
			Cell[Number_7].Status3=RXdata_Handler_CAN2[2];

			master1.cell[6].sStatus1_2.byte = (RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8);
			master1.cell[6].sStatus3_4.byte = (RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8);
		}
		break;
		end
		Start
		case 0X1E200108:
		{
			Cell[Number_8].DCBUSVOLTAGE= (RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8)*FACTORDEVISION;
			Cell[Number_8].PSFB_INPUT_DC_CURRENT= (RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8)*FACTORDEVISION;
			Cell[Number_8].FEC_INPUT_AC_CURRENT= (RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8)*FACTORDEVISION;
			Cell[Number_8].PSFB_OUTPUT_DC_CURRENT = (RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8)*FACTORDEVISION;

			master1.cell[7].dc_bus_voltage=(RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8);
			master1.cell[7].dc_bus_current=(RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8);
			master1.cell[7].fec_input_current=(RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8);
			master1.cell[7].psfb_output_current=(RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8);
		}
		break;
		case 0X1E210108:
		{
			Cell[Number_8].PSFB_OUTPUT_DC_VOLTAGE=RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8;
			Cell[Number_8].AC_VOLTAGE_OPTIONAL=RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8;
			Cell[Number_8].AC_CURRENT_OPTIONAL=(RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8)*FACTORDEVISION;
			Cell[Number_8].TRAFO_TEMPERATURE =(RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8)*FACTORDEVISION;

			master1.cell[7].psfb_output_voltage=(RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8);
			master1.cell[7].trafo_temp=(RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8);
		}
		break;
		case 0X1E220108:
		{
			Cell[Number_8].FEC_TEMPERATURE=(RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8)*FACTORDEVISION;
			Cell[Number_8].PSFB_TEMPERATURE=(RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8)*FACTORDEVISION;
			Cell[Number_8].DIODE_TEMPERATURE=(RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8)*FACTORDEVISION;
			Cell[Number_8].Rsvd2 =(RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8);

			master1.cell[7].fec_temp=(RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8);
			master1.cell[7].psfb_temp=(RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8);
			master1.cell[7].diode_temp=(RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8);
		}
		break;
		case 0X1E230108:
		{
			Cell[Number_8].PHASE_DELAY=(RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8)*FACTORDEVISION;
			Cell[Number_8].VDC_GAIN=(RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8)*FACTORDEVISION;
			Cell[Number_8].VDC_OFFSET=(((RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8)*FACTORDEVISION)-OFFSET);
			Cell[Number_8].Rsvd3 =(RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8);
		}
		break;
		case 0X1E400108:
		{
			Cell[Number_8].Fault1=RXdata_Handler_CAN2[0];
			Cell[Number_8].Fault2=RXdata_Handler_CAN2[1];
			Cell[Number_8].Fault3=RXdata_Handler_CAN2[2];
			Cell[Number_8].Fault4=RXdata_Handler_CAN2[3];
			Cell[Number_8].Fault5.byte=RXdata_Handler_CAN2[4];
			Cell[Number_8].Fault6=RXdata_Handler_CAN2[5];
			Cell[Number_8].Fault7=RXdata_Handler_CAN2[6];
			Cell[Number_8].Fault8=RXdata_Handler_CAN2[7];

			master1.cell[7].sFault1_2.byte = (RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8);
			master1.cell[7].sFault3_4.byte = (RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8);
			master1.cell[7].sFault5_6.byte = (RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8);
			master1.cell[7].sFault7_8.byte = (RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8);
		}
		break;
		case 0X1E410108:
		{
			Cell[Number_8].Status1.byte=RXdata_Handler_CAN2[0];
			Cell[Number_8].Status2=RXdata_Handler_CAN2[1];
			Cell[Number_8].Status3=RXdata_Handler_CAN2[2];

			master1.cell[7].sStatus1_2.byte = (RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8);
			master1.cell[7].sStatus3_4.byte = (RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8);
		}
		break;
		end
		Start
		case 0X1E200109:
		{
			Cell[Number_9].DCBUSVOLTAGE= (RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8)*FACTORDEVISION;
			Cell[Number_9].PSFB_INPUT_DC_CURRENT= (RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8)*FACTORDEVISION;
			Cell[Number_9].FEC_INPUT_AC_CURRENT= (RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8)*FACTORDEVISION;
			Cell[Number_9].PSFB_OUTPUT_DC_CURRENT = (RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8)*FACTORDEVISION;

			master1.cell[8].dc_bus_voltage=(RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8);
			master1.cell[8].dc_bus_current=(RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8);
			master1.cell[8].fec_input_current=(RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8);
			master1.cell[8].psfb_output_current=(RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8);
		}
		break;
		case 0X1E210109:
		{
			Cell[Number_9].PSFB_OUTPUT_DC_VOLTAGE=RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8;
			Cell[Number_9].AC_VOLTAGE_OPTIONAL=RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8;
			Cell[Number_9].AC_CURRENT_OPTIONAL=(RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8)*FACTORDEVISION;
			Cell[Number_9].TRAFO_TEMPERATURE =(RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8)*FACTORDEVISION;

			master1.cell[8].psfb_output_voltage=(RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8);
			master1.cell[8].trafo_temp=(RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8);
		}
		break;
		case 0X1E220109:
		{
			Cell[Number_9].FEC_TEMPERATURE=(RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8)*FACTORDEVISION;
			Cell[Number_9].PSFB_TEMPERATURE=(RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8)*FACTORDEVISION;
			Cell[Number_9].DIODE_TEMPERATURE=(RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8)*FACTORDEVISION;
			Cell[Number_9].Rsvd2 =(RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8);

			master1.cell[8].fec_temp=(RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8);
			master1.cell[8].psfb_temp=(RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8);
			master1.cell[8].diode_temp=(RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8);
		}
		break;
		case 0X1E230109:
		{
			Cell[Number_9].PHASE_DELAY=(RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8)*FACTORDEVISION;
			Cell[Number_9].VDC_GAIN=(RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8)*FACTORDEVISION;
			Cell[Number_9].VDC_OFFSET=(((RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8)*FACTORDEVISION)-OFFSET);
			Cell[Number_9].Rsvd3 =(RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8);
		}
		break;
		case 0X1E400109:
		{
			Cell[Number_9].Fault1=RXdata_Handler_CAN2[0];
			Cell[Number_9].Fault2=RXdata_Handler_CAN2[1];
			Cell[Number_9].Fault3=RXdata_Handler_CAN2[2];
			Cell[Number_9].Fault4=RXdata_Handler_CAN2[3];
			Cell[Number_9].Fault5.byte=RXdata_Handler_CAN2[4];
			Cell[Number_9].Fault6=RXdata_Handler_CAN2[5];
			Cell[Number_9].Fault7=RXdata_Handler_CAN2[6];
			Cell[Number_9].Fault8=RXdata_Handler_CAN2[7];

			master1.cell[8].sFault1_2.byte = (RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8);
			master1.cell[8].sFault3_4.byte = (RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8);
			master1.cell[8].sFault5_6.byte = (RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8);
			master1.cell[8].sFault7_8.byte = (RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8);
		}
		break;
		case 0X1E410109:
		{
			Cell[Number_9].Status1.byte=RXdata_Handler_CAN2[0];
			Cell[Number_9].Status2=RXdata_Handler_CAN2[1];
			Cell[Number_9].Status3=RXdata_Handler_CAN2[2];

			master1.cell[8].sStatus1_2.byte = (RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8);
			master1.cell[8].sStatus3_4.byte = (RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8);
		}
		break;
		end

		Start

		case 0X1E20010A:
		{
			Cell[Number_10].DCBUSVOLTAGE= (RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8)*FACTORDEVISION;
			Cell[Number_10].PSFB_INPUT_DC_CURRENT= (RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8)*FACTORDEVISION;
			Cell[Number_10].FEC_INPUT_AC_CURRENT= (RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8)*FACTORDEVISION;
			Cell[Number_10].PSFB_OUTPUT_DC_CURRENT = (RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8)*FACTORDEVISION;

			master1.cell[9].dc_bus_voltage=(RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8);
			master1.cell[9].dc_bus_current=(RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8);
			master1.cell[9].fec_input_current=(RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8);
			master1.cell[9].psfb_output_current=(RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8);
		}
		break;
		case 0X1E21010A:
		{
			Cell[Number_10].PSFB_OUTPUT_DC_VOLTAGE=RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8;
			Cell[Number_10].AC_VOLTAGE_OPTIONAL=RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8;
			Cell[Number_10].AC_CURRENT_OPTIONAL=(RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8)*FACTORDEVISION;
			Cell[Number_10].TRAFO_TEMPERATURE =(RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8)*FACTORDEVISION;

			master1.cell[9].psfb_output_voltage=(RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8);
			master1.cell[9].trafo_temp=(RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8);
		}
		break;
		case 0X1E22010A:
		{
			Cell[Number_10].FEC_TEMPERATURE=(RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8)*FACTORDEVISION;
			Cell[Number_10].PSFB_TEMPERATURE=(RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8)*FACTORDEVISION;
			Cell[Number_10].DIODE_TEMPERATURE=(RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8)*FACTORDEVISION;
			Cell[Number_10].Rsvd2 =(RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8);

			master1.cell[9].fec_temp=(RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8);
			master1.cell[9].psfb_temp=(RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8);
			master1.cell[9].diode_temp=(RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8);
		}
		break;
		case 0X1E23010A:
		{
			Cell[Number_10].PHASE_DELAY=(RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8)*FACTORDEVISION;
			Cell[Number_10].VDC_GAIN=(RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8)*FACTORDEVISION;
			Cell[Number_10].VDC_OFFSET=(((RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8)*FACTORDEVISION)-OFFSET);
			Cell[Number_10].Rsvd3 =(RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8);
		}
		break;
		case 0X1E40010A:
		{
			Cell[Number_10].Fault1=RXdata_Handler_CAN2[0];
			Cell[Number_10].Fault2=RXdata_Handler_CAN2[1];
			Cell[Number_10].Fault3=RXdata_Handler_CAN2[2];
			Cell[Number_10].Fault4=RXdata_Handler_CAN2[3];
			Cell[Number_10].Fault5.byte=RXdata_Handler_CAN2[4];
			Cell[Number_10].Fault6=RXdata_Handler_CAN2[5];
			Cell[Number_10].Fault7=RXdata_Handler_CAN2[6];
			Cell[Number_10].Fault8=RXdata_Handler_CAN2[7];

			master1.cell[9].sFault1_2.byte = (RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8);
			master1.cell[9].sFault3_4.byte = (RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8);
			master1.cell[9].sFault5_6.byte = (RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8);
			master1.cell[9].sFault7_8.byte = (RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8);
		}
		break;
		case 0X1E41010A:
		{
			Cell[Number_10].Status1.byte=RXdata_Handler_CAN2[0];
			Cell[Number_10].Status2=RXdata_Handler_CAN2[1];
			Cell[Number_10].Status3=RXdata_Handler_CAN2[2];

			master1.cell[9].sStatus1_2.byte = (RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8);
			master1.cell[9].sStatus3_4.byte = (RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8);
		}
		break;
		end 10
		Start
		case 0X1E20010B:
		{
			Cell[Number_11].DCBUSVOLTAGE= (RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8)*FACTORDEVISION;
			Cell[Number_11].PSFB_INPUT_DC_CURRENT= (RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8)*FACTORDEVISION;
			Cell[Number_11].FEC_INPUT_AC_CURRENT= (RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8)*FACTORDEVISION;
			Cell[Number_11].PSFB_OUTPUT_DC_CURRENT = (RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8)*FACTORDEVISION;

			master1.cell[10].dc_bus_voltage=(RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8);
			master1.cell[10].dc_bus_current=(RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8);
			master1.cell[10].fec_input_current=(RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8);
			master1.cell[10].psfb_output_current=(RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8);
		}
		break;
		case 0X1E21010B:
		{
			Cell[Number_11].PSFB_OUTPUT_DC_VOLTAGE=RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8;
			Cell[Number_11].AC_VOLTAGE_OPTIONAL=RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8;
			Cell[Number_11].AC_CURRENT_OPTIONAL=(RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8)*FACTORDEVISION;
			Cell[Number_11].TRAFO_TEMPERATURE =(RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8)*FACTORDEVISION;

			master1.cell[10].psfb_output_voltage=(RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8);
			master1.cell[10].trafo_temp=(RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8);
		}
		break;
		case 0X1E22010B:
		{
			Cell[Number_11].FEC_TEMPERATURE=(RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8)*FACTORDEVISION;
			Cell[Number_11].PSFB_TEMPERATURE=(RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8)*FACTORDEVISION;
			Cell[Number_11].DIODE_TEMPERATURE=(RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8)*FACTORDEVISION;
			Cell[Number_11].Rsvd2 =(RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8);

			master1.cell[10].fec_temp=(RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8);
			master1.cell[10].psfb_temp=(RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8);
			master1.cell[10].diode_temp=(RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8);
		}
		break;
		case 0X1E23010B:
		{
			Cell[Number_11].PHASE_DELAY=(RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8)*FACTORDEVISION;
			Cell[Number_11].VDC_GAIN=(RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8)*FACTORDEVISION;
			Cell[Number_11].VDC_OFFSET=(((RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8)*FACTORDEVISION)-OFFSET);
			Cell[Number_11].Rsvd3 =(RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8);
		}
		break;
		case 0X1E40010B:
		{
			Cell[Number_11].Fault1=RXdata_Handler_CAN2[0];
			Cell[Number_11].Fault2=RXdata_Handler_CAN2[1];
			Cell[Number_11].Fault3=RXdata_Handler_CAN2[2];
			Cell[Number_11].Fault4=RXdata_Handler_CAN2[3];
			Cell[Number_11].Fault5.byte=RXdata_Handler_CAN2[4];
			Cell[Number_11].Fault6=RXdata_Handler_CAN2[5];
			Cell[Number_11].Fault7=RXdata_Handler_CAN2[6];
			Cell[Number_11].Fault8=RXdata_Handler_CAN2[7];

			master1.cell[10].sFault1_2.byte = (RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8);
			master1.cell[10].sFault3_4.byte = (RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8);
			master1.cell[10].sFault5_6.byte = (RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8);
			master1.cell[10].sFault7_8.byte = (RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8);
		}
		break;
		case 0X1E41010B:
		{
			Cell[Number_11].Status1.byte=RXdata_Handler_CAN2[0];
			Cell[Number_11].Status2=RXdata_Handler_CAN2[1];
			Cell[Number_11].Status3=RXdata_Handler_CAN2[2];

			master1.cell[10].sStatus1_2.byte = (RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8);
			master1.cell[10].sStatus3_4.byte = (RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8);
		}
		break;
		end
		Start
		case 0X1E20010C:
		{
			Cell[Number_12].DCBUSVOLTAGE= (RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8)*FACTORDEVISION;
			Cell[Number_12].PSFB_INPUT_DC_CURRENT= (RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8)*FACTORDEVISION;
			Cell[Number_12].FEC_INPUT_AC_CURRENT= (RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8)*FACTORDEVISION;
			Cell[Number_12].PSFB_OUTPUT_DC_CURRENT = (RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8)*FACTORDEVISION;

			master1.cell[11].dc_bus_voltage=(RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8);
			master1.cell[11].dc_bus_current=(RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8);
			master1.cell[11].fec_input_current=(RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8);
			master1.cell[11].psfb_output_current=(RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8);
		}
		break;
		case 0X1E21010C:
		{
			Cell[Number_12].PSFB_OUTPUT_DC_VOLTAGE=RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8;
			Cell[Number_12].AC_VOLTAGE_OPTIONAL=RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8;
			Cell[Number_12].AC_CURRENT_OPTIONAL=(RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8)*FACTORDEVISION;
			Cell[Number_12].TRAFO_TEMPERATURE =(RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8)*FACTORDEVISION;

			master1.cell[11].psfb_output_voltage=(RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8);
			master1.cell[11].trafo_temp=(RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8);
		}
		break;
		case 0X1E22010C:
		{
			Cell[Number_12].FEC_TEMPERATURE=(RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8)*FACTORDEVISION;
			Cell[Number_12].PSFB_TEMPERATURE=(RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8)*FACTORDEVISION;
			Cell[Number_12].DIODE_TEMPERATURE=(RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8)*FACTORDEVISION;
			Cell[Number_12].Rsvd2 =(RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8);

			master1.cell[11].fec_temp=(RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8);
			master1.cell[11].psfb_temp=(RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8);
			master1.cell[11].diode_temp=(RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8);
		}
		break;
		case 0X1E23010C:
		{
			Cell[Number_12].PHASE_DELAY=(RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8)*FACTORDEVISION;
			Cell[Number_12].VDC_GAIN=(RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8)*FACTORDEVISION;
			Cell[Number_12].VDC_OFFSET=(((RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8)*FACTORDEVISION)-OFFSET);
			Cell[Number_12].Rsvd3 =(RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8);
		}
		break;
		case 0X1E40010C:
		{
			Cell[Number_12].Fault1=RXdata_Handler_CAN2[0];
			Cell[Number_12].Fault2=RXdata_Handler_CAN2[1];
			Cell[Number_12].Fault3=RXdata_Handler_CAN2[2];
			Cell[Number_12].Fault4=RXdata_Handler_CAN2[3];
			Cell[Number_12].Fault5.byte=RXdata_Handler_CAN2[4];
			Cell[Number_12].Fault6=RXdata_Handler_CAN2[5];
			Cell[Number_12].Fault7=RXdata_Handler_CAN2[6];
			Cell[Number_12].Fault8=RXdata_Handler_CAN2[7];

			master1.cell[11].sFault1_2.byte = (RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8);
			master1.cell[11].sFault3_4.byte = (RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8);
			master1.cell[11].sFault5_6.byte = (RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8);
			master1.cell[11].sFault7_8.byte = (RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8);
		}
		break;
		case 0X1E41010C:
		{
			Cell[Number_12].Status1.byte=RXdata_Handler_CAN2[0];
			Cell[Number_12].Status2=RXdata_Handler_CAN2[1];
			Cell[Number_12].Status3=RXdata_Handler_CAN2[2];

			master1.cell[11].sStatus1_2.byte = (RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8);
			master1.cell[11].sStatus3_4.byte = (RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8);
		}
		break;
		end
		Start
		case 0X1E20010D:
		{
			Cell[Number_13].DCBUSVOLTAGE= (RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8)*FACTORDEVISION;
			Cell[Number_13].PSFB_INPUT_DC_CURRENT= (RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8)*FACTORDEVISION;
			Cell[Number_13].FEC_INPUT_AC_CURRENT= (RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8)*FACTORDEVISION;
			Cell[Number_13].PSFB_OUTPUT_DC_CURRENT = (RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8)*FACTORDEVISION;

			master1.cell[12].dc_bus_voltage=(RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8);
			master1.cell[12].dc_bus_current=(RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8);
			master1.cell[12].fec_input_current=(RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8);
			master1.cell[12].psfb_output_current=(RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8);
		}
		break;
		case 0X1E21010D:
		{
			Cell[Number_13].PSFB_OUTPUT_DC_VOLTAGE=RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8;
			Cell[Number_13].AC_VOLTAGE_OPTIONAL=RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8;
			Cell[Number_13].AC_CURRENT_OPTIONAL=(RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8)*FACTORDEVISION;
			Cell[Number_13].TRAFO_TEMPERATURE =(RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8)*FACTORDEVISION;

			master1.cell[12].psfb_output_voltage=(RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8);
			master1.cell[12].trafo_temp=(RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8);
		}
		break;
		case 0X1E22010D:
		{
			Cell[Number_13].FEC_TEMPERATURE=(RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8)*FACTORDEVISION;
			Cell[Number_13].PSFB_TEMPERATURE=(RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8)*FACTORDEVISION;
			Cell[Number_13].DIODE_TEMPERATURE=(RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8)*FACTORDEVISION;
			Cell[Number_13].Rsvd2 =(RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8);

			master1.cell[12].fec_temp=(RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8);
			master1.cell[12].psfb_temp=(RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8);
			master1.cell[12].diode_temp=(RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8);
		}
		break;
		case 0X1E23010D:
		{
			Cell[Number_13].PHASE_DELAY=(RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8)*FACTORDEVISION;
			Cell[Number_13].VDC_GAIN=(RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8)*FACTORDEVISION;
			Cell[Number_13].VDC_OFFSET=(((RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8)*FACTORDEVISION)-OFFSET);
			Cell[Number_13].Rsvd3 =(RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8);
		}
		break;
		case 0X1E40010D:
		{
			Cell[Number_13].Fault1=RXdata_Handler_CAN2[0];
			Cell[Number_13].Fault2=RXdata_Handler_CAN2[1];
			Cell[Number_13].Fault3=RXdata_Handler_CAN2[2];
			Cell[Number_13].Fault4=RXdata_Handler_CAN2[3];
			Cell[Number_13].Fault5.byte=RXdata_Handler_CAN2[4];
			Cell[Number_13].Fault6=RXdata_Handler_CAN2[5];
			Cell[Number_13].Fault7=RXdata_Handler_CAN2[6];
			Cell[Number_13].Fault8=RXdata_Handler_CAN2[7];

			master1.cell[12].sFault1_2.byte = (RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8);
			master1.cell[12].sFault3_4.byte = (RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8);
			master1.cell[12].sFault5_6.byte = (RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8);
			master1.cell[12].sFault7_8.byte = (RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8);
		}
		break;
		case 0X1E41010D:
		{
			Cell[Number_13].Status1.byte=RXdata_Handler_CAN2[0];
			Cell[Number_13].Status2=RXdata_Handler_CAN2[1];
			Cell[Number_13].Status3=RXdata_Handler_CAN2[2];

			master1.cell[12].sStatus1_2.byte = (RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8);
			master1.cell[12].sStatus3_4.byte = (RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8);
		}
		break;
		end
		Start
		case 0X1E20010E:
		{
			Cell[Number_14].DCBUSVOLTAGE= (RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8)*FACTORDEVISION;
			Cell[Number_14].PSFB_INPUT_DC_CURRENT= (RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8)*FACTORDEVISION;
			Cell[Number_14].FEC_INPUT_AC_CURRENT= (RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8)*FACTORDEVISION;
			Cell[Number_14].PSFB_OUTPUT_DC_CURRENT = (RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8)*FACTORDEVISION;

			master1.cell[13].dc_bus_voltage=(RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8);
			master1.cell[13].dc_bus_current=(RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8);
			master1.cell[13].fec_input_current=(RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8);
			master1.cell[13].psfb_output_current=(RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8);
		}
		break;
		case 0X1E21010E:
		{
			Cell[Number_14].PSFB_OUTPUT_DC_VOLTAGE=RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8;
			Cell[Number_14].AC_VOLTAGE_OPTIONAL=RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8;
			Cell[Number_14].AC_CURRENT_OPTIONAL=(RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8)*FACTORDEVISION;
			Cell[Number_14].TRAFO_TEMPERATURE =(RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8)*FACTORDEVISION;

			master1.cell[13].psfb_output_voltage=(RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8);
			master1.cell[13].trafo_temp=(RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8);
		}
		break;
		case 0X1E22010E:
		{
			Cell[Number_14].FEC_TEMPERATURE=(RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8)*FACTORDEVISION;
			Cell[Number_14].PSFB_TEMPERATURE=(RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8)*FACTORDEVISION;
			Cell[Number_14].DIODE_TEMPERATURE=(RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8)*FACTORDEVISION;
			Cell[Number_14].Rsvd2 =(RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8);

			master1.cell[13].fec_temp=(RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8);
			master1.cell[13].psfb_temp=(RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8);
			master1.cell[13].diode_temp=(RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8);
		}
		break;
		case 0X1E23010E:
		{
			Cell[Number_14].PHASE_DELAY=(RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8)*FACTORDEVISION;
			Cell[Number_14].VDC_GAIN=(RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8)*FACTORDEVISION;
			Cell[Number_14].VDC_OFFSET=(((RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8)*FACTORDEVISION)-OFFSET);
			Cell[Number_14].Rsvd3 =(RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8);
		}
		break;
		case 0X1E40010E:
		{
			Cell[Number_14].Fault1=RXdata_Handler_CAN2[0];
			Cell[Number_14].Fault2=RXdata_Handler_CAN2[1];
			Cell[Number_14].Fault3=RXdata_Handler_CAN2[2];
			Cell[Number_14].Fault4=RXdata_Handler_CAN2[3];
			Cell[Number_14].Fault5.byte=RXdata_Handler_CAN2[4];
			Cell[Number_14].Fault6=RXdata_Handler_CAN2[5];
			Cell[Number_14].Fault7=RXdata_Handler_CAN2[6];
			Cell[Number_14].Fault8=RXdata_Handler_CAN2[7];

			master1.cell[13].sFault1_2.byte = (RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8);
			master1.cell[13].sFault3_4.byte = (RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8);
			master1.cell[13].sFault5_6.byte = (RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8);
			master1.cell[13].sFault7_8.byte = (RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8);
		}
		break;
		case 0X1E41010E:
		{
			Cell[Number_14].Status1.byte=RXdata_Handler_CAN2[0];
			Cell[Number_14].Status2=RXdata_Handler_CAN2[1];
			Cell[Number_14].Status3=RXdata_Handler_CAN2[2];

			master1.cell[13].sStatus1_2.byte = (RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8);
			master1.cell[13].sStatus3_4.byte = (RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8);
		}
		break;
		end
		Start
		case 0X1E20010F:
		{
			Cell[Number_15].DCBUSVOLTAGE= (RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8)*FACTORDEVISION;
			Cell[Number_15].PSFB_INPUT_DC_CURRENT= (RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8)*FACTORDEVISION;
			Cell[Number_15].FEC_INPUT_AC_CURRENT= (RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8)*FACTORDEVISION;
			Cell[Number_15].PSFB_OUTPUT_DC_CURRENT = (RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8)*FACTORDEVISION;

			master1.cell[14].dc_bus_voltage=(RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8);
			master1.cell[14].dc_bus_current=(RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8);
			master1.cell[14].fec_input_current=(RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8);
			master1.cell[14].psfb_output_current=(RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8);
		}
		break;
		case 0X1E21010F:
		{
			Cell[Number_15].PSFB_OUTPUT_DC_VOLTAGE=RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8;
			Cell[Number_15].AC_VOLTAGE_OPTIONAL=RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8;
			Cell[Number_15].AC_CURRENT_OPTIONAL=(RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8)*FACTORDEVISION;
			Cell[Number_15].TRAFO_TEMPERATURE =(RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8)*FACTORDEVISION;

			master1.cell[14].psfb_output_voltage=(RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8);
			master1.cell[14].trafo_temp=(RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8);
		}
		break;
		case 0X1E22010F:
		{
			Cell[Number_15].FEC_TEMPERATURE=(RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8)*FACTORDEVISION;
			Cell[Number_15].PSFB_TEMPERATURE=(RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8)*FACTORDEVISION;
			Cell[Number_15].DIODE_TEMPERATURE=(RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8)*FACTORDEVISION;
			Cell[Number_15].Rsvd2 =(RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8);

			master1.cell[14].fec_temp=(RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8);
			master1.cell[14].psfb_temp=(RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8);
			master1.cell[14].diode_temp=(RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8);
		}
		break;
		case 0X1E23010F:
		{
			Cell[Number_15].PHASE_DELAY=(RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8)*FACTORDEVISION;
			Cell[Number_15].VDC_GAIN=(RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8)*FACTORDEVISION;
			Cell[Number_15].VDC_OFFSET=(((RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8)*FACTORDEVISION)-OFFSET);
			Cell[Number_15].Rsvd3 =(RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8);
		}
		break;
		case 0X1E40010F:
		{
			Cell[Number_15].Fault1=RXdata_Handler_CAN2[0];
			Cell[Number_15].Fault2=RXdata_Handler_CAN2[1];
			Cell[Number_15].Fault3=RXdata_Handler_CAN2[2];
			Cell[Number_15].Fault4=RXdata_Handler_CAN2[3];
			Cell[Number_15].Fault5.byte=RXdata_Handler_CAN2[4];
			Cell[Number_15].Fault6=RXdata_Handler_CAN2[5];
			Cell[Number_15].Fault7=RXdata_Handler_CAN2[6];
			Cell[Number_15].Fault8=RXdata_Handler_CAN2[7];

			master1.cell[14].sFault1_2.byte = (RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8);
			master1.cell[14].sFault3_4.byte = (RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8);
			master1.cell[14].sFault5_6.byte = (RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8);
			master1.cell[14].sFault7_8.byte = (RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8);
		}
		break;
		case 0X1E41010F:
		{
			Cell[Number_15].Status1.byte=RXdata_Handler_CAN2[0];
			Cell[Number_15].Status2=RXdata_Handler_CAN2[1];
			Cell[Number_15].Status3=RXdata_Handler_CAN2[2];

			master1.cell[14].sStatus1_2.byte = (RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8);
			master1.cell[14].sStatus3_4.byte = (RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8);
		}
		break;
		end
		Start
		case 0X1E200110:
		{
			Cell[Number_16].DCBUSVOLTAGE= (RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8)*FACTORDEVISION;
			Cell[Number_16].PSFB_INPUT_DC_CURRENT= (RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8)*FACTORDEVISION;
			Cell[Number_16].FEC_INPUT_AC_CURRENT= (RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8)*FACTORDEVISION;
			Cell[Number_16].PSFB_OUTPUT_DC_CURRENT = (RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8)*FACTORDEVISION;

			master1.cell[15].dc_bus_voltage=(RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8);
			master1.cell[15].dc_bus_current=(RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8);
			master1.cell[15].fec_input_current=(RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8);
			master1.cell[15].psfb_output_current=(RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8);
		}
		break;
		case 0X1E210110:
		{
			Cell[Number_16].PSFB_OUTPUT_DC_VOLTAGE=RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8;
			Cell[Number_16].AC_VOLTAGE_OPTIONAL=RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8;
			Cell[Number_16].AC_CURRENT_OPTIONAL=(RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8)*FACTORDEVISION;
			Cell[Number_16].TRAFO_TEMPERATURE =(RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8)*FACTORDEVISION;

			master1.cell[15].psfb_output_voltage=(RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8);
			master1.cell[15].trafo_temp=(RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8);
		}
		break;
		case 0X1E220110:
		{
			Cell[Number_16].FEC_TEMPERATURE=(RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8)*FACTORDEVISION;
			Cell[Number_16].PSFB_TEMPERATURE=(RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8)*FACTORDEVISION;
			Cell[Number_16].DIODE_TEMPERATURE=(RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8)*FACTORDEVISION;
			Cell[Number_16].Rsvd2 =(RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8);

			master1.cell[15].fec_temp=(RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8);
			master1.cell[15].psfb_temp=(RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8);
			master1.cell[15].diode_temp=(RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8);
		}
		break;
		case 0X1E230110:
		{
			Cell[Number_16].PHASE_DELAY=(RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8)*FACTORDEVISION;
			Cell[Number_16].VDC_GAIN=(RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8)*FACTORDEVISION;
			Cell[Number_16].VDC_OFFSET=(((RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8)*FACTORDEVISION)-OFFSET);
			Cell[Number_16].Rsvd3 =(RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8);
		}
		break;
		case 0X1E400110:
		{
			Cell[Number_16].Fault1=RXdata_Handler_CAN2[0];
			Cell[Number_16].Fault2=RXdata_Handler_CAN2[1];
			Cell[Number_16].Fault3=RXdata_Handler_CAN2[2];
			Cell[Number_16].Fault4=RXdata_Handler_CAN2[3];
			Cell[Number_16].Fault5.byte=RXdata_Handler_CAN2[4];
			Cell[Number_16].Fault6=RXdata_Handler_CAN2[5];
			Cell[Number_16].Fault7=RXdata_Handler_CAN2[6];
			Cell[Number_16].Fault8=RXdata_Handler_CAN2[7];

			master1.cell[15].sFault1_2.byte = (RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8);
			master1.cell[15].sFault3_4.byte = (RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8);
			master1.cell[15].sFault5_6.byte = (RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8);
			master1.cell[15].sFault7_8.byte = (RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8);
		}
		break;
		case 0X1E410110:
		{
			Cell[Number_16].Status1.byte=RXdata_Handler_CAN2[0];
			Cell[Number_16].Status2=RXdata_Handler_CAN2[1];
			Cell[Number_16].Status3=RXdata_Handler_CAN2[2];

			master1.cell[15].sStatus1_2.byte = (RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8);
			master1.cell[15].sStatus3_4.byte = (RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8);
		}
		break;
		end
		Start
		case 0X1E200111:
		{
			Cell[Number_17].DCBUSVOLTAGE= (RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8)*FACTORDEVISION;
			Cell[Number_17].PSFB_INPUT_DC_CURRENT= (RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8)*FACTORDEVISION;
			Cell[Number_17].FEC_INPUT_AC_CURRENT= (RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8)*FACTORDEVISION;
			Cell[Number_17].PSFB_OUTPUT_DC_CURRENT = (RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8)*FACTORDEVISION;

			master1.cell[16].dc_bus_voltage=(RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8);
			master1.cell[16].dc_bus_current=(RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8);
			master1.cell[16].fec_input_current=(RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8);
			master1.cell[16].psfb_output_current=(RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8);
		}
		break;
		case 0X1E210111:
		{
			Cell[Number_17].PSFB_OUTPUT_DC_VOLTAGE=RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8;
			Cell[Number_17].AC_VOLTAGE_OPTIONAL=RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8;
			Cell[Number_17].AC_CURRENT_OPTIONAL=(RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8)*FACTORDEVISION;
			Cell[Number_17].TRAFO_TEMPERATURE =(RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8)*FACTORDEVISION;

			master1.cell[16].psfb_output_voltage=(RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8);
			master1.cell[16].trafo_temp=(RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8);
		}
		break;
		case 0X1E220111:
		{
			Cell[Number_17].FEC_TEMPERATURE=(RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8)*FACTORDEVISION;
			Cell[Number_17].PSFB_TEMPERATURE=(RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8)*FACTORDEVISION;
			Cell[Number_17].DIODE_TEMPERATURE=(RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8)*FACTORDEVISION;
			Cell[Number_17].Rsvd2 =(RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8);

			master1.cell[16].fec_temp=(RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8);
			master1.cell[16].psfb_temp=(RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8);
			master1.cell[16].diode_temp=(RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8);
		}
		break;
		case 0X1E230111:
		{
			Cell[Number_17].PHASE_DELAY=(RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8)*FACTORDEVISION;
			Cell[Number_17].VDC_GAIN=(RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8)*FACTORDEVISION;
			Cell[Number_17].VDC_OFFSET=(((RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8)*FACTORDEVISION)-OFFSET);
			Cell[Number_17].Rsvd3 =(RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8);

		}
		break;
		case 0X1E400111:
		{
			Cell[Number_17].Fault1=RXdata_Handler_CAN2[0];
			Cell[Number_17].Fault2=RXdata_Handler_CAN2[1];
			Cell[Number_17].Fault3=RXdata_Handler_CAN2[2];
			Cell[Number_17].Fault4=RXdata_Handler_CAN2[3];
			Cell[Number_17].Fault5.byte=RXdata_Handler_CAN2[4];
			Cell[Number_17].Fault6=RXdata_Handler_CAN2[5];
			Cell[Number_17].Fault7=RXdata_Handler_CAN2[6];
			Cell[Number_17].Fault8=RXdata_Handler_CAN2[7];

			master1.cell[16].sFault1_2.byte = (RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8);
			master1.cell[16].sFault3_4.byte = (RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8);
			master1.cell[16].sFault5_6.byte = (RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8);
			master1.cell[16].sFault7_8.byte = (RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8);
		}
		break;
		case 0X1E410111:
		{
			Cell[Number_17].Status1.byte=RXdata_Handler_CAN2[0];
			Cell[Number_17].Status2=RXdata_Handler_CAN2[1];
			Cell[Number_17].Status3=RXdata_Handler_CAN2[2];

			master1.cell[16].sStatus1_2.byte = (RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8);
			master1.cell[16].sStatus3_4.byte = (RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8);
		}
		break;
		end
		Start
		case 0X1E200112:
		{
			Cell[Number_18].DCBUSVOLTAGE= (RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8)*FACTORDEVISION;
			Cell[Number_18].PSFB_INPUT_DC_CURRENT= (RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8)*FACTORDEVISION;
			Cell[Number_18].FEC_INPUT_AC_CURRENT= (RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8)*FACTORDEVISION;
			Cell[Number_18].PSFB_OUTPUT_DC_CURRENT = (RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8)*FACTORDEVISION;

			master1.cell[17].dc_bus_voltage=(RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8);
			master1.cell[17].dc_bus_current=(RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8);
			master1.cell[17].fec_input_current=(RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8);
			master1.cell[17].psfb_output_current=(RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8);
		}
		break;
		case 0X1E210112:
		{
			Cell[Number_18].PSFB_OUTPUT_DC_VOLTAGE=RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8;
			Cell[Number_18].AC_VOLTAGE_OPTIONAL=RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8;
			Cell[Number_18].AC_CURRENT_OPTIONAL=(RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8)*FACTORDEVISION;
			Cell[Number_18].TRAFO_TEMPERATURE =(RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8)*FACTORDEVISION;

			master1.cell[17].psfb_output_voltage=(RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8);
			master1.cell[17].trafo_temp=(RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8);
		}
		break;
		case 0X1E220112:
		{
			Cell[Number_18].FEC_TEMPERATURE=(RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8)*FACTORDEVISION;
			Cell[Number_18].PSFB_TEMPERATURE=(RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8)*FACTORDEVISION;
			Cell[Number_18].DIODE_TEMPERATURE=(RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8)*FACTORDEVISION;
			Cell[Number_18].Rsvd2 =(RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8);

			master1.cell[17].fec_temp=(RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8);
			master1.cell[17].psfb_temp=(RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8);
			master1.cell[17].diode_temp=(RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8);
		}
		break;
		case 0X1E230112:
		{
			Cell[Number_18].PHASE_DELAY=(RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8)*FACTORDEVISION;
			Cell[Number_18].VDC_GAIN=(RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8)*FACTORDEVISION;
			Cell[Number_18].VDC_OFFSET=(((RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8)*FACTORDEVISION)-OFFSET);
			Cell[Number_18].Rsvd3 =(RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8);
		}
		break;
		case 0X1E400112:
		{
			Cell[Number_18].Fault1=RXdata_Handler_CAN2[0];
			Cell[Number_18].Fault2=RXdata_Handler_CAN2[1];
			Cell[Number_18].Fault3=RXdata_Handler_CAN2[2];
			Cell[Number_18].Fault4=RXdata_Handler_CAN2[3];
			Cell[Number_18].Fault5.byte=RXdata_Handler_CAN2[4];
			Cell[Number_18].Fault6=RXdata_Handler_CAN2[5];
			Cell[Number_18].Fault7=RXdata_Handler_CAN2[6];
			Cell[Number_18].Fault8=RXdata_Handler_CAN2[7];

			master1.cell[17].sFault1_2.byte = (RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8);
			master1.cell[17].sFault3_4.byte = (RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8);
			master1.cell[17].sFault5_6.byte = (RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8);
			master1.cell[17].sFault7_8.byte = (RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8);
		}
		break;
		case 0X1E410112:
		{
			Cell[Number_18].Status1.byte=RXdata_Handler_CAN2[0];
			Cell[Number_18].Status2=RXdata_Handler_CAN2[1];
			Cell[Number_18].Status3=RXdata_Handler_CAN2[2];

			master1.cell[17].sStatus1_2.byte = (RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8);
			master1.cell[17].sStatus3_4.byte = (RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8);
		}
		break;
		end
		Start
		case 0X1E200113:
		{
			Cell[Number_19].DCBUSVOLTAGE= (RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8)*FACTORDEVISION;
			Cell[Number_19].PSFB_INPUT_DC_CURRENT= (RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8)*FACTORDEVISION;
			Cell[Number_19].FEC_INPUT_AC_CURRENT= (RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8)*FACTORDEVISION;
			Cell[Number_19].PSFB_OUTPUT_DC_CURRENT = (RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8)*FACTORDEVISION;

			master1.cell[18].dc_bus_voltage=(RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8);
			master1.cell[18].dc_bus_current=(RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8);
			master1.cell[18].fec_input_current=(RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8);
			master1.cell[18].psfb_output_current=(RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8);
		}
		break;
		case 0X1E210113:
		{
			Cell[Number_19].PSFB_OUTPUT_DC_VOLTAGE=RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8;
			Cell[Number_19].AC_VOLTAGE_OPTIONAL=RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8;
			Cell[Number_19].AC_CURRENT_OPTIONAL=(RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8)*FACTORDEVISION;
			Cell[Number_19].TRAFO_TEMPERATURE =(RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8)*FACTORDEVISION;

			master1.cell[18].psfb_output_voltage=(RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8);
			master1.cell[18].trafo_temp=(RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8);
		}
		break;
		case 0X1E220113:
		{
			Cell[Number_19].FEC_TEMPERATURE=(RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8)*FACTORDEVISION;
			Cell[Number_19].PSFB_TEMPERATURE=(RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8)*FACTORDEVISION;
			Cell[Number_19].DIODE_TEMPERATURE=(RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8)*FACTORDEVISION;
			Cell[Number_19].Rsvd2 =(RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8);

			master1.cell[18].fec_temp=(RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8);
			master1.cell[18].psfb_temp=(RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8);
			master1.cell[18].diode_temp=(RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8);
		}
		break;
		case 0X1E230113:
		{
			Cell[Number_19].PHASE_DELAY=(RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8)*FACTORDEVISION;
			Cell[Number_19].VDC_GAIN=(RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8)*FACTORDEVISION;
			Cell[Number_19].VDC_OFFSET=(((RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8)*FACTORDEVISION)-OFFSET);
			Cell[Number_19].Rsvd3 =(RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8);

		}
		break;
		case 0X1E400113:
		{
			Cell[Number_19].Fault1=RXdata_Handler_CAN2[0];
			Cell[Number_19].Fault2=RXdata_Handler_CAN2[1];
			Cell[Number_19].Fault3=RXdata_Handler_CAN2[2];
			Cell[Number_19].Fault4=RXdata_Handler_CAN2[3];
			Cell[Number_19].Fault5.byte=RXdata_Handler_CAN2[4];
			Cell[Number_19].Fault6=RXdata_Handler_CAN2[5];
			Cell[Number_19].Fault7=RXdata_Handler_CAN2[6];
			Cell[Number_19].Fault8=RXdata_Handler_CAN2[7];

			master1.cell[18].sFault1_2.byte = (RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8);
			master1.cell[18].sFault3_4.byte = (RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8);
			master1.cell[18].sFault5_6.byte = (RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8);
			master1.cell[18].sFault7_8.byte = (RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8);
		}
		break;
		case 0X1E410113:
		{
			Cell[Number_19].Status1.byte=RXdata_Handler_CAN2[0];
			Cell[Number_19].Status2=RXdata_Handler_CAN2[1];
			Cell[Number_19].Status3=RXdata_Handler_CAN2[2];

			master1.cell[18].sStatus1_2.byte = (RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8);
			master1.cell[18].sStatus3_4.byte = (RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8);
		}
		break;
		end
		Start
		case 0X1E200114:
		{
			Cell[Number_20].DCBUSVOLTAGE= (RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8)*FACTORDEVISION;
			Cell[Number_20].PSFB_INPUT_DC_CURRENT= (RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8)*FACTORDEVISION;
			Cell[Number_20].FEC_INPUT_AC_CURRENT= (RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8)*FACTORDEVISION;
			Cell[Number_20].PSFB_OUTPUT_DC_CURRENT = (RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8)*FACTORDEVISION;

			master1.cell[19].dc_bus_voltage=(RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8);
			master1.cell[19].dc_bus_current=(RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8);
			master1.cell[19].fec_input_current=(RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8);
			master1.cell[19].psfb_output_current=(RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8);
		}
		break;
		case 0X1E210114:
		{
			Cell[Number_20].PSFB_OUTPUT_DC_VOLTAGE=RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8;
			Cell[Number_20].AC_VOLTAGE_OPTIONAL=RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8;
			Cell[Number_20].AC_CURRENT_OPTIONAL=(RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8)*FACTORDEVISION;
			Cell[Number_20].TRAFO_TEMPERATURE =(RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8)*FACTORDEVISION;

			master1.cell[19].psfb_output_voltage=(RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8);
			master1.cell[19].trafo_temp=(RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8);
		}
		break;
		case 0X1E220114:
		{
			Cell[Number_20].FEC_TEMPERATURE=(RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8)*FACTORDEVISION;
			Cell[Number_20].PSFB_TEMPERATURE=(RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8)*FACTORDEVISION;
			Cell[Number_20].DIODE_TEMPERATURE=(RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8)*FACTORDEVISION;
			Cell[Number_20].Rsvd2 =(RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8);

			master1.cell[19].fec_temp=(RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8);
			master1.cell[19].psfb_temp=(RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8);
			master1.cell[19].diode_temp=(RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8);
		}
		break;
		case 0X1E230114:
		{
			Cell[Number_20].PHASE_DELAY=(RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8)*FACTORDEVISION;
			Cell[Number_20].VDC_GAIN=(RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8)*FACTORDEVISION;
			Cell[Number_20].VDC_OFFSET=(((RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8)*FACTORDEVISION)-OFFSET);
			Cell[Number_20].Rsvd3 =(RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8);
		}
		break;
		case 0X1E400114:
		{
			Cell[Number_20].Fault1=RXdata_Handler_CAN2[0];
			Cell[Number_20].Fault2=RXdata_Handler_CAN2[1];
			Cell[Number_20].Fault3=RXdata_Handler_CAN2[2];
			Cell[Number_20].Fault4=RXdata_Handler_CAN2[3];
			Cell[Number_20].Fault5.byte=RXdata_Handler_CAN2[4];
			Cell[Number_20].Fault6=RXdata_Handler_CAN2[5];
			Cell[Number_20].Fault7=RXdata_Handler_CAN2[6];
			Cell[Number_20].Fault8=RXdata_Handler_CAN2[7];

			master1.cell[19].sFault1_2.byte = (RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8);
			master1.cell[19].sFault3_4.byte = (RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8);
			master1.cell[19].sFault5_6.byte = (RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8);
			master1.cell[19].sFault7_8.byte = (RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8);
		}
		break;
		case 0X1E410114:
		{
			Cell[Number_20].Status1.byte=RXdata_Handler_CAN2[0];
			Cell[Number_20].Status2=RXdata_Handler_CAN2[1];
			Cell[Number_20].Status3=RXdata_Handler_CAN2[2];

			master1.cell[19].sStatus1_2.byte = (RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8);
			master1.cell[19].sStatus3_4.byte = (RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8);
		}
		break;
		end 20
		Start
		case 0X1E200115:
		{
			Cell[Number_21].DCBUSVOLTAGE= (RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8)*FACTORDEVISION;
			Cell[Number_21].PSFB_INPUT_DC_CURRENT= (RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8)*FACTORDEVISION;
			Cell[Number_21].FEC_INPUT_AC_CURRENT= (RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8)*FACTORDEVISION;
			Cell[Number_21].PSFB_OUTPUT_DC_CURRENT = (RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8)*FACTORDEVISION;

			master1.cell[20].dc_bus_voltage=(RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8);
			master1.cell[20].dc_bus_current=(RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8);
			master1.cell[20].fec_input_current=(RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8);
			master1.cell[20].psfb_output_current=(RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8);
		}
		break;
		case 0X1E210115:
		{
			Cell[Number_21].PSFB_OUTPUT_DC_VOLTAGE=RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8;
			Cell[Number_21].AC_VOLTAGE_OPTIONAL=RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8;
			Cell[Number_21].AC_CURRENT_OPTIONAL=(RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8)*FACTORDEVISION;
			Cell[Number_21].TRAFO_TEMPERATURE =(RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8)*FACTORDEVISION;

			master1.cell[20].psfb_output_voltage=(RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8);
			master1.cell[20].trafo_temp=(RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8);
		}
		break;
		case 0X1E220115:
		{
			Cell[Number_21].FEC_TEMPERATURE=(RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8)*FACTORDEVISION;
			Cell[Number_21].PSFB_TEMPERATURE=(RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8)*FACTORDEVISION;
			Cell[Number_21].DIODE_TEMPERATURE=(RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8)*FACTORDEVISION;
			Cell[Number_21].Rsvd2 =(RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8);

			master1.cell[20].fec_temp=(RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8);
			master1.cell[20].psfb_temp=(RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8);
			master1.cell[20].diode_temp=(RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8);
		}
		break;
		case 0X1E230115:
		{
			Cell[Number_21].PHASE_DELAY=(RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8)*FACTORDEVISION;
			Cell[Number_21].VDC_GAIN=(RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8)*FACTORDEVISION;
			Cell[Number_21].VDC_OFFSET=(((RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8)*FACTORDEVISION)-OFFSET);
			Cell[Number_21].Rsvd3 =(RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8);
		}
		break;
		case 0X1E400115:
		{
			Cell[Number_21].Fault1=RXdata_Handler_CAN2[0];
			Cell[Number_21].Fault2=RXdata_Handler_CAN2[1];
			Cell[Number_21].Fault3=RXdata_Handler_CAN2[2];
			Cell[Number_21].Fault4=RXdata_Handler_CAN2[3];
			Cell[Number_21].Fault5.byte=RXdata_Handler_CAN2[4];
			Cell[Number_21].Fault6=RXdata_Handler_CAN2[5];
			Cell[Number_21].Fault7=RXdata_Handler_CAN2[6];
			Cell[Number_21].Fault8=RXdata_Handler_CAN2[7];

			master1.cell[20].sFault1_2.byte = (RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8);
			master1.cell[20].sFault3_4.byte = (RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8);
			master1.cell[20].sFault5_6.byte = (RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8);
			master1.cell[20].sFault7_8.byte = (RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8);
		}
		break;
		case 0X1E410115:
		{
			Cell[Number_21].Status1.byte=RXdata_Handler_CAN2[0];
			Cell[Number_21].Status2=RXdata_Handler_CAN2[1];
			Cell[Number_21].Status3=RXdata_Handler_CAN2[2];

			master1.cell[20].sStatus1_2.byte = (RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8);
			master1.cell[20].sStatus3_4.byte = (RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8);
		}
		break;
		end
		Start
		case 0X1E200116:
		{
			Cell[Number_22].DCBUSVOLTAGE= (RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8)*FACTORDEVISION;
			Cell[Number_22].PSFB_INPUT_DC_CURRENT= (RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8)*FACTORDEVISION;
			Cell[Number_22].FEC_INPUT_AC_CURRENT= (RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8)*FACTORDEVISION;
			Cell[Number_22].PSFB_OUTPUT_DC_CURRENT = (RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8)*FACTORDEVISION;

			master1.cell[21].dc_bus_voltage=(RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8);
			master1.cell[21].dc_bus_current=(RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8);
			master1.cell[21].fec_input_current=(RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8);
			master1.cell[21].psfb_output_current=(RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8);
		}
		break;
		case 0X1E210116:
		{
			Cell[Number_22].PSFB_OUTPUT_DC_VOLTAGE=RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8;
			Cell[Number_22].AC_VOLTAGE_OPTIONAL=RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8;
			Cell[Number_22].AC_CURRENT_OPTIONAL=(RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8)*FACTORDEVISION;
			Cell[Number_22].TRAFO_TEMPERATURE =(RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8)*FACTORDEVISION;

			master1.cell[21].psfb_output_voltage=(RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8);
			master1.cell[21].trafo_temp=(RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8);
		}
		break;
		case 0X1E220116:
		{
			Cell[Number_22].FEC_TEMPERATURE=(RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8)*FACTORDEVISION;
			Cell[Number_22].PSFB_TEMPERATURE=(RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8)*FACTORDEVISION;
			Cell[Number_22].DIODE_TEMPERATURE=(RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8)*FACTORDEVISION;
			Cell[Number_22].Rsvd2 =(RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8);

			master1.cell[21].fec_temp=(RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8);
			master1.cell[21].psfb_temp=(RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8);
			master1.cell[21].diode_temp=(RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8);
		}
		break;
		case 0X1E230116:
		{
			Cell[Number_22].PHASE_DELAY=(RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8)*FACTORDEVISION;
			Cell[Number_22].VDC_GAIN=(RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8)*FACTORDEVISION;
			Cell[Number_22].VDC_OFFSET=(((RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8)*FACTORDEVISION)-OFFSET);
			Cell[Number_22].Rsvd3 =(RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8);
		}
		break;
		case 0X1E400116:
		{
			Cell[Number_22].Fault1=RXdata_Handler_CAN2[0];
			Cell[Number_22].Fault2=RXdata_Handler_CAN2[1];
			Cell[Number_22].Fault3=RXdata_Handler_CAN2[2];
			Cell[Number_22].Fault4=RXdata_Handler_CAN2[3];
			Cell[Number_22].Fault5.byte=RXdata_Handler_CAN2[4];
			Cell[Number_22].Fault6=RXdata_Handler_CAN2[5];
			Cell[Number_22].Fault7=RXdata_Handler_CAN2[6];
			Cell[Number_22].Fault8=RXdata_Handler_CAN2[7];

			master1.cell[21].sFault1_2.byte = (RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8);
			master1.cell[21].sFault3_4.byte = (RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8);
			master1.cell[21].sFault5_6.byte = (RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8);
			master1.cell[21].sFault7_8.byte = (RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8);
		}
		break;
		case 0X1E410116:
		{
			Cell[Number_22].Status1.byte=RXdata_Handler_CAN2[0];
			Cell[Number_22].Status2=RXdata_Handler_CAN2[1];
			Cell[Number_22].Status3=RXdata_Handler_CAN2[2];

			master1.cell[21].sStatus1_2.byte = (RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8);
			master1.cell[21].sStatus3_4.byte = (RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8);
		}
		break;
		end
		Start
		case 0X1E200117:
		{
			Cell[Number_23].DCBUSVOLTAGE= (RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8)*FACTORDEVISION;
			Cell[Number_23].PSFB_INPUT_DC_CURRENT= (RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8)*FACTORDEVISION;
			Cell[Number_23].FEC_INPUT_AC_CURRENT= (RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8)*FACTORDEVISION;
			Cell[Number_23].PSFB_OUTPUT_DC_CURRENT = (RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8)*FACTORDEVISION;

			master1.cell[22].dc_bus_voltage=(RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8);
			master1.cell[22].dc_bus_current=(RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8);
			master1.cell[22].fec_input_current=(RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8);
			master1.cell[22].psfb_output_current=(RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8);
		}
		break;
		case 0X1E210117:
		{
			Cell[Number_23].PSFB_OUTPUT_DC_VOLTAGE=RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8;
			Cell[Number_23].AC_VOLTAGE_OPTIONAL=RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8;
			Cell[Number_23].AC_CURRENT_OPTIONAL=(RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8)*FACTORDEVISION;
			Cell[Number_23].TRAFO_TEMPERATURE =(RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8)*FACTORDEVISION;

			master1.cell[22].psfb_output_voltage=(RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8);
			master1.cell[22].trafo_temp=(RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8);
		}
		break;
		case 0X1E220117:
		{
			Cell[Number_23].FEC_TEMPERATURE=(RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8)*FACTORDEVISION;
			Cell[Number_23].PSFB_TEMPERATURE=(RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8)*FACTORDEVISION;
			Cell[Number_23].DIODE_TEMPERATURE=(RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8)*FACTORDEVISION;
			Cell[Number_23].Rsvd2 =(RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8);

			master1.cell[22].fec_temp=(RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8);
			master1.cell[22].psfb_temp=(RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8);
			master1.cell[22].diode_temp=(RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8);
		}
		break;
		case 0X1E230117:
		{
			Cell[Number_23].PHASE_DELAY=(RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8)*FACTORDEVISION;
			Cell[Number_23].VDC_GAIN=(RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8)*FACTORDEVISION;
			Cell[Number_23].VDC_OFFSET=(((RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8)*FACTORDEVISION)-OFFSET);
			Cell[Number_23].Rsvd3 =(RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8);
		}
		break;
		case 0X1E400117:
		{
			Cell[Number_23].Fault1=RXdata_Handler_CAN2[0];
			Cell[Number_23].Fault2=RXdata_Handler_CAN2[1];
			Cell[Number_23].Fault3=RXdata_Handler_CAN2[2];
			Cell[Number_23].Fault4=RXdata_Handler_CAN2[3];
			Cell[Number_23].Fault5.byte=RXdata_Handler_CAN2[4];
			Cell[Number_23].Fault6=RXdata_Handler_CAN2[5];
			Cell[Number_23].Fault7=RXdata_Handler_CAN2[6];
			Cell[Number_23].Fault8=RXdata_Handler_CAN2[7];

			master1.cell[22].sFault1_2.byte = (RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8);
			master1.cell[22].sFault3_4.byte = (RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8);
			master1.cell[22].sFault5_6.byte = (RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8);
			master1.cell[22].sFault7_8.byte = (RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8);
		}
		break;
		case 0X1E410117:
		{
			Cell[Number_23].Status1.byte=RXdata_Handler_CAN2[0];
			Cell[Number_23].Status2=RXdata_Handler_CAN2[1];
			Cell[Number_23].Status3=RXdata_Handler_CAN2[2];

			master1.cell[22].sStatus1_2.byte = (RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8);
			master1.cell[22].sStatus3_4.byte = (RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8);
		}
		break;
		end
		Start
		case 0X1E200118:
		{
			Cell[Number_24].DCBUSVOLTAGE= (RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8)*FACTORDEVISION;
			Cell[Number_24].PSFB_INPUT_DC_CURRENT= (RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8)*FACTORDEVISION;
			Cell[Number_24].FEC_INPUT_AC_CURRENT= (RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8)*FACTORDEVISION;
			Cell[Number_24].PSFB_OUTPUT_DC_CURRENT = (RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8)*FACTORDEVISION;

			master1.cell[23].dc_bus_voltage=(RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8);
			master1.cell[23].dc_bus_current=(RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8);
			master1.cell[23].fec_input_current=(RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8);
			master1.cell[23].psfb_output_current=(RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8);
		}
		break;
		case 0X1E210118:
		{
			Cell[Number_24].PSFB_OUTPUT_DC_VOLTAGE=RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8;
			Cell[Number_24].AC_VOLTAGE_OPTIONAL=RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8;
			Cell[Number_24].AC_CURRENT_OPTIONAL=(RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8)*FACTORDEVISION;
			Cell[Number_24].TRAFO_TEMPERATURE =(RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8)*FACTORDEVISION;

			master1.cell[23].psfb_output_voltage=(RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8);
			master1.cell[23].trafo_temp=(RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8);
		}
		break;
		case 0X1E220118:
		{
			Cell[Number_24].FEC_TEMPERATURE=(RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8)*FACTORDEVISION;
			Cell[Number_24].PSFB_TEMPERATURE=(RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8)*FACTORDEVISION;
			Cell[Number_24].DIODE_TEMPERATURE=(RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8)*FACTORDEVISION;
			Cell[Number_24].Rsvd2 =(RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8);

			master1.cell[23].fec_temp=(RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8);
			master1.cell[23].psfb_temp=(RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8);
			master1.cell[23].diode_temp=(RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8);
		}
		break;
		case 0X1E230118:
		{
			Cell[Number_24].PHASE_DELAY=(RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8)*FACTORDEVISION;
			Cell[Number_24].VDC_GAIN=(RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8)*FACTORDEVISION;
			Cell[Number_24].VDC_OFFSET=(((RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8)*FACTORDEVISION)-OFFSET);
			Cell[Number_24].Rsvd3 =(RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8);
		}
		break;
		case 0X1E400118:
		{
			Cell[Number_24].Fault1=RXdata_Handler_CAN2[0];
			Cell[Number_24].Fault2=RXdata_Handler_CAN2[1];
			Cell[Number_24].Fault3=RXdata_Handler_CAN2[2];
			Cell[Number_24].Fault4=RXdata_Handler_CAN2[3];
			Cell[Number_24].Fault5.byte=RXdata_Handler_CAN2[4];
			Cell[Number_24].Fault6=RXdata_Handler_CAN2[5];
			Cell[Number_24].Fault7=RXdata_Handler_CAN2[6];
			Cell[Number_24].Fault8=RXdata_Handler_CAN2[7];

			master1.cell[23].sFault1_2.byte = (RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8);
			master1.cell[23].sFault3_4.byte = (RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8);
			master1.cell[23].sFault5_6.byte = (RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8);
			master1.cell[23].sFault7_8.byte = (RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8);
		}
		break;
		case 0X1E410118:
		{
			Cell[Number_24].Status1.byte=RXdata_Handler_CAN2[0];
			Cell[Number_24].Status2=RXdata_Handler_CAN2[1];
			Cell[Number_24].Status3=RXdata_Handler_CAN2[2];

			master1.cell[23].sStatus1_2.byte = (RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8);
			master1.cell[23].sStatus3_4.byte = (RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8);
		}
		break;
		end
		Start
		case 0X1E200119:
		{
			Cell[Number_25].DCBUSVOLTAGE= (RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8)*FACTORDEVISION;
			Cell[Number_25].PSFB_INPUT_DC_CURRENT= (RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8)*FACTORDEVISION;
			Cell[Number_25].FEC_INPUT_AC_CURRENT= (RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8)*FACTORDEVISION;
			Cell[Number_25].PSFB_OUTPUT_DC_CURRENT = (RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8)*FACTORDEVISION;

			master1.cell[24].dc_bus_voltage=(RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8);
			master1.cell[24].dc_bus_current=(RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8);
			master1.cell[24].fec_input_current=(RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8);
			master1.cell[24].psfb_output_current=(RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8);
		}
		break;
		case 0X1E210119:
		{
			Cell[Number_25].PSFB_OUTPUT_DC_VOLTAGE=RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8;
			Cell[Number_25].AC_VOLTAGE_OPTIONAL=RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8;
			Cell[Number_25].AC_CURRENT_OPTIONAL=(RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8)*FACTORDEVISION;
			Cell[Number_25].TRAFO_TEMPERATURE =(RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8)*FACTORDEVISION;

			master1.cell[24].psfb_output_voltage=(RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8);
			master1.cell[24].trafo_temp=(RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8);
		}
		break;
		case 0X1E220119:
		{
			Cell[Number_25].FEC_TEMPERATURE=(RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8)*FACTORDEVISION;
			Cell[Number_25].PSFB_TEMPERATURE=(RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8)*FACTORDEVISION;
			Cell[Number_25].DIODE_TEMPERATURE=(RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8)*FACTORDEVISION;
			Cell[Number_25].Rsvd2 =(RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8);

			master1.cell[24].fec_temp=(RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8);
			master1.cell[24].psfb_temp=(RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8);
			master1.cell[24].diode_temp=(RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8);
		}
		break;
		case 0X1E230119:
		{
			Cell[Number_25].PHASE_DELAY=(RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8)*FACTORDEVISION;
			Cell[Number_25].VDC_GAIN=(RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8)*FACTORDEVISION;
			Cell[Number_25].VDC_OFFSET=(((RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8)*FACTORDEVISION)-OFFSET);
			Cell[Number_25].Rsvd3 =(RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8);
		}
		break;
		case 0X1E400119:
		{
			Cell[Number_25].Fault1=RXdata_Handler_CAN2[0];
			Cell[Number_25].Fault2=RXdata_Handler_CAN2[1];
			Cell[Number_25].Fault3=RXdata_Handler_CAN2[2];
			Cell[Number_25].Fault4=RXdata_Handler_CAN2[3];
			Cell[Number_25].Fault5.byte=RXdata_Handler_CAN2[4];
			Cell[Number_25].Fault6=RXdata_Handler_CAN2[5];
			Cell[Number_25].Fault7=RXdata_Handler_CAN2[6];
			Cell[Number_25].Fault8=RXdata_Handler_CAN2[7];

			master1.cell[24].sFault1_2.byte = (RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8);
			master1.cell[24].sFault3_4.byte = (RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8);
			master1.cell[24].sFault5_6.byte = (RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8);
			master1.cell[24].sFault7_8.byte = (RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8);
		}
		break;
		case 0X1E410119:
		{
			Cell[Number_25].Status1.byte=RXdata_Handler_CAN2[0];
			Cell[Number_25].Status2=RXdata_Handler_CAN2[1];
			Cell[Number_25].Status3=RXdata_Handler_CAN2[2];

			master1.cell[24].sStatus1_2.byte = (RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8);
			master1.cell[24].sStatus3_4.byte = (RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8);
		}
		break;
		end
		Start
		case 0X1E20011A:
		{
			Cell[Number_26].DCBUSVOLTAGE= (RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8)*FACTORDEVISION;
			Cell[Number_26].PSFB_INPUT_DC_CURRENT= (RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8)*FACTORDEVISION;
			Cell[Number_26].FEC_INPUT_AC_CURRENT= (RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8)*FACTORDEVISION;
			Cell[Number_26].PSFB_OUTPUT_DC_CURRENT = (RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8)*FACTORDEVISION;

			master1.cell[25].dc_bus_voltage=(RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8);
			master1.cell[25].dc_bus_current=(RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8);
			master1.cell[25].fec_input_current=(RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8);
			master1.cell[25].psfb_output_current=(RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8);
		}
		break;
		case 0X1E21011A:
		{
			Cell[Number_26].PSFB_OUTPUT_DC_VOLTAGE=RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8;
			Cell[Number_26].AC_VOLTAGE_OPTIONAL=RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8;
			Cell[Number_26].AC_CURRENT_OPTIONAL=(RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8)*FACTORDEVISION;
			Cell[Number_26].TRAFO_TEMPERATURE =(RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8)*FACTORDEVISION;

			master1.cell[25].psfb_output_voltage=(RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8);
			master1.cell[25].trafo_temp=(RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8);
		}
		break;
		case 0X1E22011A:
		{
			Cell[Number_26].FEC_TEMPERATURE=(RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8)*FACTORDEVISION;
			Cell[Number_26].PSFB_TEMPERATURE=(RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8)*FACTORDEVISION;
			Cell[Number_26].DIODE_TEMPERATURE=(RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8)*FACTORDEVISION;
			Cell[Number_26].Rsvd2 =(RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8);

			master1.cell[25].fec_temp=(RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8);
			master1.cell[25].psfb_temp=(RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8);
			master1.cell[25].diode_temp=(RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8);
		}
		break;
		case 0X1E23011A:
		{
			Cell[Number_26].PHASE_DELAY=(RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8)*FACTORDEVISION;
			Cell[Number_26].VDC_GAIN=(RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8)*FACTORDEVISION;
			Cell[Number_26].VDC_OFFSET=(((RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8)*FACTORDEVISION)-OFFSET);
			Cell[Number_26].Rsvd3 =(RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8);
		}
		break;
		case 0X1E40011A:
		{
			Cell[Number_26].Fault1=RXdata_Handler_CAN2[0];
			Cell[Number_26].Fault2=RXdata_Handler_CAN2[1];
			Cell[Number_26].Fault3=RXdata_Handler_CAN2[2];
			Cell[Number_26].Fault4=RXdata_Handler_CAN2[3];
			Cell[Number_26].Fault5.byte=RXdata_Handler_CAN2[4];
			Cell[Number_26].Fault6=RXdata_Handler_CAN2[5];
			Cell[Number_26].Fault7=RXdata_Handler_CAN2[6];
			Cell[Number_26].Fault8=RXdata_Handler_CAN2[7];

			master1.cell[25].sFault1_2.byte = (RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8);
			master1.cell[25].sFault3_4.byte = (RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8);
			master1.cell[25].sFault5_6.byte = (RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8);
			master1.cell[25].sFault7_8.byte = (RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8);
		}
		break;
		case 0X1E41011A:
		{
			Cell[Number_26].Status1.byte=RXdata_Handler_CAN2[0];
			Cell[Number_26].Status2=RXdata_Handler_CAN2[1];
			Cell[Number_26].Status3=RXdata_Handler_CAN2[2];

			master1.cell[25].sStatus1_2.byte = (RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8);
			master1.cell[25].sStatus3_4.byte = (RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8);
		}
		break;
		end
		Start
		case 0X1E20011B:
		{
			Cell[Number_27].DCBUSVOLTAGE= (RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8)*FACTORDEVISION;
			Cell[Number_27].PSFB_INPUT_DC_CURRENT= (RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8)*FACTORDEVISION;
			Cell[Number_27].FEC_INPUT_AC_CURRENT= (RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8)*FACTORDEVISION;
			Cell[Number_27].PSFB_OUTPUT_DC_CURRENT = (RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8)*FACTORDEVISION;

			master1.cell[26].dc_bus_voltage=(RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8);
			master1.cell[26].dc_bus_current=(RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8);
			master1.cell[26].fec_input_current=(RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8);
			master1.cell[26].psfb_output_current=(RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8);
		}
		break;
		case 0X1E21011B:
		{
			Cell[Number_27].PSFB_OUTPUT_DC_VOLTAGE=RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8;
			Cell[Number_27].AC_VOLTAGE_OPTIONAL=RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8;
			Cell[Number_27].AC_CURRENT_OPTIONAL=(RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8)*FACTORDEVISION;
			Cell[Number_27].TRAFO_TEMPERATURE =(RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8)*FACTORDEVISION;

			master1.cell[26].psfb_output_voltage=(RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8);
			master1.cell[26].trafo_temp=(RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8);
		}
		break;
		case 0X1E22011B:
		{
			Cell[Number_27].FEC_TEMPERATURE=(RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8)*FACTORDEVISION;
			Cell[Number_27].PSFB_TEMPERATURE=(RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8)*FACTORDEVISION;
			Cell[Number_27].DIODE_TEMPERATURE=(RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8)*FACTORDEVISION;
			Cell[Number_27].Rsvd2 =(RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8);

			master1.cell[26].fec_temp=(RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8);
			master1.cell[26].psfb_temp=(RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8);
			master1.cell[26].diode_temp=(RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8);
		}
		break;
		case 0X1E23011B:
		{
			Cell[Number_27].PHASE_DELAY=(RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8)*FACTORDEVISION;
			Cell[Number_27].VDC_GAIN=(RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8)*FACTORDEVISION;
			Cell[Number_27].VDC_OFFSET=(((RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8)*FACTORDEVISION)-OFFSET);
			Cell[Number_27].Rsvd3 =(RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8);
		}
		break;
		case 0X1E40011B:
		{
			Cell[Number_27].Fault1=RXdata_Handler_CAN2[0];
			Cell[Number_27].Fault2=RXdata_Handler_CAN2[1];
			Cell[Number_27].Fault3=RXdata_Handler_CAN2[2];
			Cell[Number_27].Fault4=RXdata_Handler_CAN2[3];
			Cell[Number_27].Fault5.byte=RXdata_Handler_CAN2[4];
			Cell[Number_27].Fault6=RXdata_Handler_CAN2[5];
			Cell[Number_27].Fault7=RXdata_Handler_CAN2[6];
			Cell[Number_27].Fault8=RXdata_Handler_CAN2[7];

			master1.cell[26].sFault1_2.byte = (RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8);
			master1.cell[26].sFault3_4.byte = (RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8);
			master1.cell[26].sFault5_6.byte = (RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8);
			master1.cell[26].sFault7_8.byte = (RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8);
		}
		break;
		case 0X1E41011B:
		{
			Cell[Number_27].Status1.byte=RXdata_Handler_CAN2[0];
			Cell[Number_27].Status2=RXdata_Handler_CAN2[1];
			Cell[Number_27].Status3=RXdata_Handler_CAN2[2];

			master1.cell[26].sStatus1_2.byte = (RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8);
			master1.cell[26].sStatus3_4.byte = (RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8);
		}
		break;
		end
		Start
		case 0X1E20011C:
		{
			Cell[Number_28].DCBUSVOLTAGE= (RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8)*FACTORDEVISION;
			Cell[Number_28].PSFB_INPUT_DC_CURRENT= (RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8)*FACTORDEVISION;
			Cell[Number_28].FEC_INPUT_AC_CURRENT= (RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8)*FACTORDEVISION;
			Cell[Number_28].PSFB_OUTPUT_DC_CURRENT = (RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8)*FACTORDEVISION;

			master1.cell[27].dc_bus_voltage=(RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8);
			master1.cell[27].dc_bus_current=(RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8);
			master1.cell[27].fec_input_current=(RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8);
			master1.cell[27].psfb_output_current=(RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8);
		}
		break;
		case 0X1E21011C:
		{
			Cell[Number_28].PSFB_OUTPUT_DC_VOLTAGE=RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8;
			Cell[Number_28].AC_VOLTAGE_OPTIONAL=RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8;
			Cell[Number_28].AC_CURRENT_OPTIONAL=(RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8)*FACTORDEVISION;
			Cell[Number_28].TRAFO_TEMPERATURE =(RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8)*FACTORDEVISION;

			master1.cell[27].psfb_output_voltage=(RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8);
			master1.cell[27].trafo_temp=(RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8);
		}
		break;
		case 0X1E22011C:
		{
			Cell[Number_28].FEC_TEMPERATURE=(RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8)*FACTORDEVISION;
			Cell[Number_28].PSFB_TEMPERATURE=(RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8)*FACTORDEVISION;
			Cell[Number_28].DIODE_TEMPERATURE=(RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8)*FACTORDEVISION;
			Cell[Number_28].Rsvd2 =(RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8);

			master1.cell[27].fec_temp=(RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8);
			master1.cell[27].psfb_temp=(RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8);
			master1.cell[27].diode_temp=(RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8);
		}
		break;
		case 0X1E23011C:
		{
			Cell[Number_28].PHASE_DELAY=(RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8)*FACTORDEVISION;
			Cell[Number_28].VDC_GAIN=(RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8)*FACTORDEVISION;
			Cell[Number_28].VDC_OFFSET=(((RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8)*FACTORDEVISION)-OFFSET);
			Cell[Number_28].Rsvd3 =(RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8);
		}
		break;
		case 0X1E40011C:
		{
			Cell[Number_28].Fault1=RXdata_Handler_CAN2[0];
			Cell[Number_28].Fault2=RXdata_Handler_CAN2[1];
			Cell[Number_28].Fault3=RXdata_Handler_CAN2[2];
			Cell[Number_28].Fault4=RXdata_Handler_CAN2[3];
			Cell[Number_28].Fault5.byte=RXdata_Handler_CAN2[4];
			Cell[Number_28].Fault6=RXdata_Handler_CAN2[5];
			Cell[Number_28].Fault7=RXdata_Handler_CAN2[6];
			Cell[Number_28].Fault8=RXdata_Handler_CAN2[7];

			master1.cell[27].sFault1_2.byte = (RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8);
			master1.cell[27].sFault3_4.byte = (RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8);
			master1.cell[27].sFault5_6.byte = (RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8);
			master1.cell[27].sFault7_8.byte = (RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8);
		}
		break;
		case 0X1E41011C:
		{
			Cell[Number_28].Status1.byte=RXdata_Handler_CAN2[0];
			Cell[Number_28].Status2=RXdata_Handler_CAN2[1];
			Cell[Number_28].Status3=RXdata_Handler_CAN2[2];

			master1.cell[27].sStatus1_2.byte = (RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8);
			master1.cell[27].sStatus3_4.byte = (RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8);
		}
		break;
		end
		Start
		case 0X1E20011D:
		{
			Cell[Number_29].DCBUSVOLTAGE= (RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8)*FACTORDEVISION;
			Cell[Number_29].PSFB_INPUT_DC_CURRENT= (RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8)*FACTORDEVISION;
			Cell[Number_29].FEC_INPUT_AC_CURRENT= (RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8)*FACTORDEVISION;
			Cell[Number_29].PSFB_OUTPUT_DC_CURRENT = (RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8)*FACTORDEVISION;

			master1.cell[28].dc_bus_voltage=(RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8);
			master1.cell[28].dc_bus_current=(RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8);
			master1.cell[28].fec_input_current=(RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8);
			master1.cell[28].psfb_output_current=(RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8);
		}
		break;
		case 0X1E21011D:
		{
			Cell[Number_29].PSFB_OUTPUT_DC_VOLTAGE=RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8;
			Cell[Number_29].AC_VOLTAGE_OPTIONAL=RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8;
			Cell[Number_29].AC_CURRENT_OPTIONAL=(RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8)*FACTORDEVISION;
			Cell[Number_29].TRAFO_TEMPERATURE =(RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8)*FACTORDEVISION;

			master1.cell[28].psfb_output_voltage=(RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8);
			master1.cell[28].trafo_temp=(RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8);
		}
		break;
		case 0X1E22011D:
		{
			Cell[Number_29].FEC_TEMPERATURE=(RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8)*FACTORDEVISION;
			Cell[Number_29].PSFB_TEMPERATURE=(RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8)*FACTORDEVISION;
			Cell[Number_29].DIODE_TEMPERATURE=(RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8)*FACTORDEVISION;
			Cell[Number_29].Rsvd2 =(RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8);

			master1.cell[28].fec_temp=(RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8);
			master1.cell[28].psfb_temp=(RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8);
			master1.cell[28].diode_temp=(RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8);
		}
		break;
		case 0X1E23011D:
		{
			Cell[Number_29].PHASE_DELAY=(RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8)*FACTORDEVISION;
			Cell[Number_29].VDC_GAIN=(RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8)*FACTORDEVISION;
			Cell[Number_29].VDC_OFFSET=(((RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8)*FACTORDEVISION)-OFFSET);
			Cell[Number_29].Rsvd3 =(RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8);
		}
		break;
		case 0X1E40011D:
		{
			Cell[Number_29].Fault1=RXdata_Handler_CAN2[0];
			Cell[Number_29].Fault2=RXdata_Handler_CAN2[1];
			Cell[Number_29].Fault3=RXdata_Handler_CAN2[2];
			Cell[Number_29].Fault4=RXdata_Handler_CAN2[3];
			Cell[Number_29].Fault5.byte=RXdata_Handler_CAN2[4];
			Cell[Number_29].Fault6=RXdata_Handler_CAN2[5];
			Cell[Number_29].Fault7=RXdata_Handler_CAN2[6];
			Cell[Number_29].Fault8=RXdata_Handler_CAN2[7];

			master1.cell[28].sFault1_2.byte = (RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8);
			master1.cell[28].sFault3_4.byte = (RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8);
			master1.cell[28].sFault5_6.byte = (RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8);
			master1.cell[28].sFault7_8.byte = (RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8);
		}
		break;
		case 0X1E41011D:
		{
			Cell[Number_29].Status1.byte=RXdata_Handler_CAN2[0];
			Cell[Number_29].Status2=RXdata_Handler_CAN2[1];
			Cell[Number_29].Status3=RXdata_Handler_CAN2[2];

			master1.cell[28].sStatus1_2.byte = (RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8);
			master1.cell[28].sStatus3_4.byte = (RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8);
		}
		break;
		end
		Start
		case 0X1E20011E:
		{
			Cell[Number_30].DCBUSVOLTAGE= (RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8)*FACTORDEVISION;
			Cell[Number_30].PSFB_INPUT_DC_CURRENT= (RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8)*FACTORDEVISION;
			Cell[Number_30].FEC_INPUT_AC_CURRENT= (RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8)*FACTORDEVISION;
			Cell[Number_30].PSFB_OUTPUT_DC_CURRENT = (RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8)*FACTORDEVISION;

			master1.cell[29].dc_bus_voltage=(RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8);
			master1.cell[29].dc_bus_current=(RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8);
			master1.cell[29].fec_input_current=(RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8);
			master1.cell[29].psfb_output_current=(RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8);
		}
		break;
		case 0X1E21011E:
		{
			Cell[Number_30].PSFB_OUTPUT_DC_VOLTAGE=RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8;
			Cell[Number_30].AC_VOLTAGE_OPTIONAL=RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8;
			Cell[Number_30].AC_CURRENT_OPTIONAL=(RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8)*FACTORDEVISION;
			Cell[Number_30].TRAFO_TEMPERATURE =(RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8)*FACTORDEVISION;

			master1.cell[29].psfb_output_voltage=(RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8);
			master1.cell[29].trafo_temp=(RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8);
		}
		break;
		case 0X1E22011E:
		{
			Cell[Number_30].FEC_TEMPERATURE=(RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8)*FACTORDEVISION;
			Cell[Number_30].PSFB_TEMPERATURE=(RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8)*FACTORDEVISION;
			Cell[Number_30].DIODE_TEMPERATURE=(RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8)*FACTORDEVISION;
			Cell[Number_30].Rsvd2 =(RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8);

			master1.cell[29].fec_temp=(RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8);
			master1.cell[29].psfb_temp=(RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8);
			master1.cell[29].diode_temp=(RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8);
		}
		break;
		case 0X1E23011E:
		{
			Cell[Number_30].PHASE_DELAY=(RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8)*FACTORDEVISION;
			Cell[Number_30].VDC_GAIN=(RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8)*FACTORDEVISION;
			Cell[Number_30].VDC_OFFSET=(((RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8)*FACTORDEVISION)-OFFSET);
			Cell[Number_30].Rsvd3 =(RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8);
		}
		break;
		case 0X1E40011E:
		{
			Cell[Number_30].Fault1=RXdata_Handler_CAN2[0];
			Cell[Number_30].Fault2=RXdata_Handler_CAN2[1];
			Cell[Number_30].Fault3=RXdata_Handler_CAN2[2];
			Cell[Number_30].Fault4=RXdata_Handler_CAN2[3];
			Cell[Number_30].Fault5.byte=RXdata_Handler_CAN2[4];
			Cell[Number_30].Fault6=RXdata_Handler_CAN2[5];
			Cell[Number_30].Fault7=RXdata_Handler_CAN2[6];
			Cell[Number_30].Fault8=RXdata_Handler_CAN2[7];

			master1.cell[29].sFault1_2.byte = (RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8);
			master1.cell[29].sFault3_4.byte = (RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8);
			master1.cell[29].sFault5_6.byte = (RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8);
			master1.cell[29].sFault7_8.byte = (RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8);
		}
		break;
		case 0X1E41011E:
		{
			Cell[Number_30].Status1.byte=RXdata_Handler_CAN2[0];
			Cell[Number_30].Status2=RXdata_Handler_CAN2[1];
			Cell[Number_30].Status3=RXdata_Handler_CAN2[2];

			master1.cell[29].sStatus1_2.byte = (RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8);
			master1.cell[29].sStatus3_4.byte = (RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8);
		}
		break;
		end
		Start
		case 0X1E20011F:
		{
			Cell[Number_31].DCBUSVOLTAGE= (RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8)*FACTORDEVISION;
			Cell[Number_31].PSFB_INPUT_DC_CURRENT= (RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8)*FACTORDEVISION;
			Cell[Number_31].FEC_INPUT_AC_CURRENT= (RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8)*FACTORDEVISION;
			Cell[Number_31].PSFB_OUTPUT_DC_CURRENT = (RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8)*FACTORDEVISION;

			master1.cell[30].dc_bus_voltage=(RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8);
			master1.cell[30].dc_bus_current=(RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8);
			master1.cell[30].fec_input_current=(RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8);
			master1.cell[30].psfb_output_current=(RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8);
		}
		break;
		case 0X1E21011F:
		{
			Cell[Number_31].PSFB_OUTPUT_DC_VOLTAGE=RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8;
			Cell[Number_31].AC_VOLTAGE_OPTIONAL=RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8;
			Cell[Number_31].AC_CURRENT_OPTIONAL=(RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8)*FACTORDEVISION;
			Cell[Number_31].TRAFO_TEMPERATURE =(RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8)*FACTORDEVISION;

			master1.cell[30].psfb_output_voltage=(RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8);
			master1.cell[30].trafo_temp=(RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8);
		}
		break;
		case 0X1E22011F:
		{
			Cell[Number_31].FEC_TEMPERATURE=(RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8)*FACTORDEVISION;
			Cell[Number_31].PSFB_TEMPERATURE=(RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8)*FACTORDEVISION;
			Cell[Number_31].DIODE_TEMPERATURE=(RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8)*FACTORDEVISION;
			Cell[Number_31].Rsvd2 =(RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8);

			master1.cell[30].fec_temp=(RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8);
			master1.cell[30].psfb_temp=(RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8);
			master1.cell[30].diode_temp=(RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8);
		}
		break;
		case 0X1E23011F:
		{
			Cell[Number_31].PHASE_DELAY=(RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8)*FACTORDEVISION;
			Cell[Number_31].VDC_GAIN=(RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8)*FACTORDEVISION;
			Cell[Number_31].VDC_OFFSET=(((RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8)*FACTORDEVISION)-OFFSET);
			Cell[Number_31].Rsvd3 =(RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8);
		}
		break;
		case 0X1E40011F:
		{
			Cell[Number_31].Fault1=RXdata_Handler_CAN2[0];
			Cell[Number_31].Fault2=RXdata_Handler_CAN2[1];
			Cell[Number_31].Fault3=RXdata_Handler_CAN2[2];
			Cell[Number_31].Fault4=RXdata_Handler_CAN2[3];
			Cell[Number_31].Fault5.byte=RXdata_Handler_CAN2[4];
			Cell[Number_31].Fault6=RXdata_Handler_CAN2[5];
			Cell[Number_31].Fault7=RXdata_Handler_CAN2[6];
			Cell[Number_31].Fault8=RXdata_Handler_CAN2[7];

			master1.cell[30].sFault1_2.byte = (RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8);
			master1.cell[30].sFault3_4.byte = (RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8);
			master1.cell[30].sFault5_6.byte = (RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8);
			master1.cell[30].sFault7_8.byte = (RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8);
		}
		break;
		case 0X1E41011F:
		{
			Cell[Number_31].Status1.byte=RXdata_Handler_CAN2[0];
			Cell[Number_31].Status2=RXdata_Handler_CAN2[1];
			Cell[Number_31].Status3=RXdata_Handler_CAN2[2];

			master1.cell[30].sStatus1_2.byte = (RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8);
			master1.cell[30].sStatus3_4.byte = (RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8);
		}
		break;
		end
		Start
		case 0X1E200120:
		{
			Cell[Number_32].DCBUSVOLTAGE= (RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8)*FACTORDEVISION;
			Cell[Number_32].PSFB_INPUT_DC_CURRENT= (RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8)*FACTORDEVISION;
			Cell[Number_32].FEC_INPUT_AC_CURRENT= (RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8)*FACTORDEVISION;
			Cell[Number_32].PSFB_OUTPUT_DC_CURRENT = (RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8)*FACTORDEVISION;

			master1.cell[31].dc_bus_voltage=(RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8);
			master1.cell[31].dc_bus_current=(RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8);
			master1.cell[31].fec_input_current=(RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8);
			master1.cell[31].psfb_output_current=(RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8);
		}
		break;
		case 0X1E210120:
		{
			Cell[Number_32].PSFB_OUTPUT_DC_VOLTAGE=RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8;
			Cell[Number_32].AC_VOLTAGE_OPTIONAL=RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8;
			Cell[Number_32].AC_CURRENT_OPTIONAL=(RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8)*FACTORDEVISION;
			Cell[Number_32].TRAFO_TEMPERATURE =(RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8)*FACTORDEVISION;

			master1.cell[31].psfb_output_voltage=(RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8);
			master1.cell[31].trafo_temp=(RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8);
		}
		break;
		case 0X1E220120:
		{
			Cell[Number_32].FEC_TEMPERATURE=(RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8)*FACTORDEVISION;
			Cell[Number_32].PSFB_TEMPERATURE=(RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8)*FACTORDEVISION;
			Cell[Number_32].DIODE_TEMPERATURE=(RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8)*FACTORDEVISION;
			Cell[Number_32].Rsvd2 =(RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8);

			master1.cell[31].fec_temp=(RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8);
			master1.cell[31].psfb_temp=(RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8);
			master1.cell[31].diode_temp=(RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8);
		}
		break;
		case 0X1E230120:
		{
			Cell[Number_32].PHASE_DELAY=(RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8)*FACTORDEVISION;
			Cell[Number_32].VDC_GAIN=(RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8)*FACTORDEVISION;
			Cell[Number_32].VDC_OFFSET=(((RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8)*FACTORDEVISION)-OFFSET);
			Cell[Number_10].Rsvd3 =(RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8);
		}
		break;
		case 0X1E400120:
		{
			Cell[Number_32].Fault1=RXdata_Handler_CAN2[0];
			Cell[Number_32].Fault2=RXdata_Handler_CAN2[1];
			Cell[Number_32].Fault3=RXdata_Handler_CAN2[2];
			Cell[Number_32].Fault4=RXdata_Handler_CAN2[3];
			Cell[Number_32].Fault5.byte=RXdata_Handler_CAN2[4];
			Cell[Number_32].Fault6=RXdata_Handler_CAN2[5];
			Cell[Number_32].Fault7=RXdata_Handler_CAN2[6];
			Cell[Number_32].Fault8=RXdata_Handler_CAN2[7];

			master1.cell[31].sFault1_2.byte = (RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8);
			master1.cell[31].sFault3_4.byte = (RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8);
			master1.cell[31].sFault5_6.byte = (RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8);
			master1.cell[31].sFault7_8.byte = (RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8);
		}
		break;
		case 0X1E410120:
		{
			Cell[Number_32].Status1.byte=RXdata_Handler_CAN2[0];
			Cell[Number_32].Status2=RXdata_Handler_CAN2[1];
			Cell[Number_32].Status3=RXdata_Handler_CAN2[2];

			master1.cell[31].sStatus1_2.byte = (RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8);
			master1.cell[31].sStatus3_4.byte = (RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8);
		}
		break;
		end
		Start
		case 0X1E200121:
		{
			Cell[Number_33].DCBUSVOLTAGE= (RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8)*FACTORDEVISION;
			Cell[Number_33].PSFB_INPUT_DC_CURRENT= (RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8)*FACTORDEVISION;
			Cell[Number_33].FEC_INPUT_AC_CURRENT= (RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8)*FACTORDEVISION;
			Cell[Number_33].PSFB_OUTPUT_DC_CURRENT = (RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8)*FACTORDEVISION;

			master1.cell[32].dc_bus_voltage=(RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8);
			master1.cell[32].dc_bus_current=(RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8);
			master1.cell[32].fec_input_current=(RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8);
			master1.cell[32].psfb_output_current=(RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8);
		}
		break;
		case 0X1E210121:
		{
			Cell[Number_33].PSFB_OUTPUT_DC_VOLTAGE=RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8;
			Cell[Number_33].AC_VOLTAGE_OPTIONAL=RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8;
			Cell[Number_33].AC_CURRENT_OPTIONAL=(RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8)*FACTORDEVISION;
			Cell[Number_33].TRAFO_TEMPERATURE =(RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8)*FACTORDEVISION;

			master1.cell[32].psfb_output_voltage=(RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8);
			master1.cell[32].trafo_temp=(RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8);
		}
		break;
		case 0X1E220121:
		{
			Cell[Number_33].FEC_TEMPERATURE=(RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8)*FACTORDEVISION;
			Cell[Number_33].PSFB_TEMPERATURE=(RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8)*FACTORDEVISION;
			Cell[Number_33].DIODE_TEMPERATURE=(RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8)*FACTORDEVISION;
			Cell[Number_33].Rsvd2 =(RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8);

			master1.cell[32].fec_temp=(RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8);
			master1.cell[32].psfb_temp=(RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8);
			master1.cell[32].diode_temp=(RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8);
		}
		break;
		case 0X1E230121:
		{
			Cell[Number_33].PHASE_DELAY=(RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8)*FACTORDEVISION;
			Cell[Number_33].VDC_GAIN=(RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8)*FACTORDEVISION;
			Cell[Number_33].VDC_OFFSET=(((RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8)*FACTORDEVISION)-OFFSET);
			Cell[Number_33].Rsvd3 =(RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8);
		}
		break;
		case 0X1E400121:
		{
			Cell[Number_33].Fault1=RXdata_Handler_CAN2[0];
			Cell[Number_33].Fault2=RXdata_Handler_CAN2[1];
			Cell[Number_33].Fault3=RXdata_Handler_CAN2[2];
			Cell[Number_33].Fault4=RXdata_Handler_CAN2[3];
			Cell[Number_33].Fault5.byte=RXdata_Handler_CAN2[4];
			Cell[Number_33].Fault6=RXdata_Handler_CAN2[5];
			Cell[Number_33].Fault7=RXdata_Handler_CAN2[6];
			Cell[Number_33].Fault8=RXdata_Handler_CAN2[7];

			master1.cell[32].sFault1_2.byte = (RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8);
			master1.cell[32].sFault3_4.byte = (RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8);
			master1.cell[32].sFault5_6.byte = (RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8);
			master1.cell[32].sFault7_8.byte = (RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8);
		}
		break;
		case 0X1E410121:
		{
			Cell[Number_33].Status1.byte=RXdata_Handler_CAN2[0];
			Cell[Number_33].Status2=RXdata_Handler_CAN2[1];
			Cell[Number_33].Status3=RXdata_Handler_CAN2[2];

			master1.cell[32].sStatus1_2.byte = (RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8);
			master1.cell[32].sStatus3_4.byte = (RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8);
		}
		break;
		end
		Start
		case 0X1E200122:
		{
			Cell[Number_34].DCBUSVOLTAGE= (RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8)*FACTORDEVISION;
			Cell[Number_34].PSFB_INPUT_DC_CURRENT= (RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8)*FACTORDEVISION;
			Cell[Number_34].FEC_INPUT_AC_CURRENT= (RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8)*FACTORDEVISION;
			Cell[Number_34].PSFB_OUTPUT_DC_CURRENT = (RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8)*FACTORDEVISION;

			master1.cell[33].dc_bus_voltage=(RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8);
			master1.cell[33].dc_bus_current=(RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8);
			master1.cell[33].fec_input_current=(RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8);
			master1.cell[33].psfb_output_current=(RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8);
		}
		break;
		case 0X1E210122:
		{
			Cell[Number_34].PSFB_OUTPUT_DC_VOLTAGE=RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8;
			Cell[Number_34].AC_VOLTAGE_OPTIONAL=RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8;
			Cell[Number_34].AC_CURRENT_OPTIONAL=(RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8)*FACTORDEVISION;
			Cell[Number_34].TRAFO_TEMPERATURE =(RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8)*FACTORDEVISION;

			master1.cell[33].psfb_output_voltage=(RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8);
			master1.cell[33].trafo_temp=(RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8);
		}
		break;
		case 0X1E220122:
		{
			Cell[Number_34].FEC_TEMPERATURE=(RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8)*FACTORDEVISION;
			Cell[Number_34].PSFB_TEMPERATURE=(RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8)*FACTORDEVISION;
			Cell[Number_34].DIODE_TEMPERATURE=(RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8)*FACTORDEVISION;
			Cell[Number_34].Rsvd2 =(RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8);

			master1.cell[33].fec_temp=(RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8);
			master1.cell[33].psfb_temp=(RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8);
			master1.cell[33].diode_temp=(RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8);
		}
		break;
		case 0X1E230122:
		{
			Cell[Number_34].PHASE_DELAY=(RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8)*FACTORDEVISION;
			Cell[Number_34].VDC_GAIN=(RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8)*FACTORDEVISION;
			Cell[Number_34].VDC_OFFSET=(((RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8)*FACTORDEVISION)-OFFSET);
			Cell[Number_34].Rsvd3 =(RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8);
		}
		break;
		case 0X1E400122:
		{
			Cell[Number_34].Fault1=RXdata_Handler_CAN2[0];
			Cell[Number_34].Fault2=RXdata_Handler_CAN2[1];
			Cell[Number_34].Fault3=RXdata_Handler_CAN2[2];
			Cell[Number_34].Fault4=RXdata_Handler_CAN2[3];
			Cell[Number_34].Fault5.byte=RXdata_Handler_CAN2[4];
			Cell[Number_34].Fault6=RXdata_Handler_CAN2[5];
			Cell[Number_34].Fault7=RXdata_Handler_CAN2[6];
			Cell[Number_34].Fault8=RXdata_Handler_CAN2[7];

			master1.cell[33].sFault1_2.byte = (RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8);
			master1.cell[33].sFault3_4.byte = (RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8);
			master1.cell[33].sFault5_6.byte = (RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8);
			master1.cell[33].sFault7_8.byte = (RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8);
		}
		break;
		case 0X1E410122:
		{
			Cell[Number_34].Status1.byte=RXdata_Handler_CAN2[0];
			Cell[Number_34].Status2=RXdata_Handler_CAN2[1];
			Cell[Number_34].Status3=RXdata_Handler_CAN2[2];

			master1.cell[33].sStatus1_2.byte = (RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8);
			master1.cell[33].sStatus3_4.byte = (RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8);
		}
		break;
		end
		Start
		case 0X1E200123:
		{
			Cell[Number_35].DCBUSVOLTAGE= (RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8)*FACTORDEVISION;
			Cell[Number_35].PSFB_INPUT_DC_CURRENT= (RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8)*FACTORDEVISION;
			Cell[Number_35].FEC_INPUT_AC_CURRENT= (RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8)*FACTORDEVISION;
			Cell[Number_35].PSFB_OUTPUT_DC_CURRENT = (RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8)*FACTORDEVISION;

			master1.cell[34].dc_bus_voltage=(RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8);
			master1.cell[34].dc_bus_current=(RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8);
			master1.cell[34].fec_input_current=(RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8);
			master1.cell[34].psfb_output_current=(RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8);
		}
		break;
		case 0X1E210123:
		{
			Cell[Number_35].PSFB_OUTPUT_DC_VOLTAGE=RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8;
			Cell[Number_35].AC_VOLTAGE_OPTIONAL=RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8;
			Cell[Number_35].AC_CURRENT_OPTIONAL=(RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8)*FACTORDEVISION;
			Cell[Number_35].TRAFO_TEMPERATURE =(RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8)*FACTORDEVISION;

			master1.cell[34].psfb_output_voltage=(RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8);
			master1.cell[34].trafo_temp=(RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8);
		}
		break;
		case 0X1E220123:
		{
			Cell[Number_35].FEC_TEMPERATURE=(RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8)*FACTORDEVISION;
			Cell[Number_35].PSFB_TEMPERATURE=(RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8)*FACTORDEVISION;
			Cell[Number_35].DIODE_TEMPERATURE=(RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8)*FACTORDEVISION;
			Cell[Number_35].Rsvd2 =(RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8);

			master1.cell[34].fec_temp=(RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8);
			master1.cell[34].psfb_temp=(RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8);
			master1.cell[34].diode_temp=(RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8);
		}
		break;
		case 0X1E230123:
		{
			Cell[Number_35].PHASE_DELAY=(RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8)*FACTORDEVISION;
			Cell[Number_35].VDC_GAIN=(RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8)*FACTORDEVISION;
			Cell[Number_35].VDC_OFFSET=(((RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8)*FACTORDEVISION)-OFFSET);
			Cell[Number_35].Rsvd3 =(RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8);
		}
		break;
		case 0X1E400123:
		{
			Cell[Number_35].Fault1=RXdata_Handler_CAN2[0];
			Cell[Number_35].Fault2=RXdata_Handler_CAN2[1];
			Cell[Number_35].Fault3=RXdata_Handler_CAN2[2];
			Cell[Number_35].Fault4=RXdata_Handler_CAN2[3];
			Cell[Number_35].Fault5.byte=RXdata_Handler_CAN2[4];
			Cell[Number_35].Fault6=RXdata_Handler_CAN2[5];
			Cell[Number_35].Fault7=RXdata_Handler_CAN2[6];
			Cell[Number_35].Fault8=RXdata_Handler_CAN2[7];

			master1.cell[34].sFault1_2.byte = (RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8);
			master1.cell[34].sFault3_4.byte = (RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8);
			master1.cell[34].sFault5_6.byte = (RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8);
			master1.cell[34].sFault7_8.byte = (RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8);
		}
		break;
		case 0X1E410123:
		{
			Cell[Number_35].Status1.byte=RXdata_Handler_CAN2[0];
			Cell[Number_35].Status2=RXdata_Handler_CAN2[1];
			Cell[Number_35].Status3=RXdata_Handler_CAN2[2];

			master1.cell[34].sStatus1_2.byte = (RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8);
			master1.cell[34].sStatus3_4.byte = (RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8);
		}
		break;
		end
		Start
		case 0X1E200124:
		{
			Cell[Number_36].DCBUSVOLTAGE= (RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8)*FACTORDEVISION;
			Cell[Number_36].PSFB_INPUT_DC_CURRENT= (RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8)*FACTORDEVISION;
			Cell[Number_36].FEC_INPUT_AC_CURRENT= (RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8)*FACTORDEVISION;
			Cell[Number_36].PSFB_OUTPUT_DC_CURRENT = (RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8)*FACTORDEVISION;

			master1.cell[35].dc_bus_voltage=(RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8);
			master1.cell[35].dc_bus_current=(RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8);
			master1.cell[35].fec_input_current=(RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8);
			master1.cell[35].psfb_output_current=(RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8);
		}
		break;
		case 0X1E210124:
		{
			Cell[Number_36].PSFB_OUTPUT_DC_VOLTAGE=RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8;
			Cell[Number_36].AC_VOLTAGE_OPTIONAL=RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8;
			Cell[Number_36].AC_CURRENT_OPTIONAL=(RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8)*FACTORDEVISION;
			Cell[Number_36].TRAFO_TEMPERATURE =(RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8)*FACTORDEVISION;

			master1.cell[35].psfb_output_voltage=(RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8);
			master1.cell[35].trafo_temp=(RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8);
		}
		break;
		case 0X1E220124:
		{
			Cell[Number_36].FEC_TEMPERATURE=(RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8)*FACTORDEVISION;
			Cell[Number_36].PSFB_TEMPERATURE=(RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8)*FACTORDEVISION;
			Cell[Number_36].DIODE_TEMPERATURE=(RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8)*FACTORDEVISION;
			Cell[Number_36].Rsvd2 =(RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8);

			master1.cell[35].fec_temp=(RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8);
			master1.cell[35].psfb_temp=(RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8);
			master1.cell[35].diode_temp=(RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8);
		}
		break;
		case 0X1E230124:
		{
			Cell[Number_36].PHASE_DELAY=(RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8)*FACTORDEVISION;
			Cell[Number_36].VDC_GAIN=(RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8)*FACTORDEVISION;
			Cell[Number_36].VDC_OFFSET=(((RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8)*FACTORDEVISION)-OFFSET);
			Cell[Number_36].Rsvd3 =(RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8);
		}
		break;
		case 0X1E400124:
		{
			Cell[Number_36].Fault1=RXdata_Handler_CAN2[0];
			Cell[Number_36].Fault2=RXdata_Handler_CAN2[1];
			Cell[Number_36].Fault3=RXdata_Handler_CAN2[2];
			Cell[Number_36].Fault4=RXdata_Handler_CAN2[3];
			Cell[Number_36].Fault5.byte=RXdata_Handler_CAN2[4];
			Cell[Number_36].Fault6=RXdata_Handler_CAN2[5];
			Cell[Number_36].Fault7=RXdata_Handler_CAN2[6];
			Cell[Number_36].Fault8=RXdata_Handler_CAN2[7];

			master1.cell[35].sFault1_2.byte = (RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8);
			master1.cell[35].sFault3_4.byte = (RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8);
			master1.cell[35].sFault5_6.byte = (RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8);
			master1.cell[35].sFault7_8.byte = (RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8);
		}
		break;
		case 0X1E410124:
		{
			Cell[Number_36].Status1.byte=RXdata_Handler_CAN2[0];
			Cell[Number_36].Status2=RXdata_Handler_CAN2[1];
			Cell[Number_36].Status3=RXdata_Handler_CAN2[2];

			master1.cell[35].sStatus1_2.byte = (RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8);
			master1.cell[35].sStatus3_4.byte = (RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8);
		}
		break;
		end
		Start
		case 0X1E200125:
		{
			Cell[Number_37].DCBUSVOLTAGE= (RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8)*FACTORDEVISION;
			Cell[Number_37].PSFB_INPUT_DC_CURRENT= (RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8)*FACTORDEVISION;
			Cell[Number_37].FEC_INPUT_AC_CURRENT= (RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8)*FACTORDEVISION;
			Cell[Number_37].PSFB_OUTPUT_DC_CURRENT = (RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8)*FACTORDEVISION;

			master1.cell[36].dc_bus_voltage=(RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8);
			master1.cell[36].dc_bus_current=(RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8);
			master1.cell[36].fec_input_current=(RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8);
			master1.cell[36].psfb_output_current=(RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8);
		}
		break;
		case 0X1E210125:
		{
			Cell[Number_37].PSFB_OUTPUT_DC_VOLTAGE=RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8;
			Cell[Number_37].AC_VOLTAGE_OPTIONAL=RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8;
			Cell[Number_37].AC_CURRENT_OPTIONAL=(RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8)*FACTORDEVISION;
			Cell[Number_37].TRAFO_TEMPERATURE =(RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8)*FACTORDEVISION;

			master1.cell[36].psfb_output_voltage=(RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8);
			master1.cell[36].trafo_temp=(RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8);
		}
		break;
		case 0X1E220125:
		{
			Cell[Number_37].FEC_TEMPERATURE=(RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8)*FACTORDEVISION;
			Cell[Number_37].PSFB_TEMPERATURE=(RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8)*FACTORDEVISION;
			Cell[Number_37].DIODE_TEMPERATURE=(RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8)*FACTORDEVISION;
			Cell[Number_37].Rsvd2 =(RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8);

			master1.cell[36].fec_temp=(RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8);
			master1.cell[36].psfb_temp=(RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8);
			master1.cell[36].diode_temp=(RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8);
		}
		break;
		case 0X1E230125:
		{
			Cell[Number_37].PHASE_DELAY=(RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8)*FACTORDEVISION;
			Cell[Number_37].VDC_GAIN=(RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8)*FACTORDEVISION;
			Cell[Number_37].VDC_OFFSET=(((RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8)*FACTORDEVISION)-OFFSET);
			Cell[Number_37].Rsvd3 =(RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8);
		}
		break;
		case 0X1E400125:
		{
			Cell[Number_37].Fault1=RXdata_Handler_CAN2[0];
			Cell[Number_37].Fault2=RXdata_Handler_CAN2[1];
			Cell[Number_37].Fault3=RXdata_Handler_CAN2[2];
			Cell[Number_37].Fault4=RXdata_Handler_CAN2[3];
			Cell[Number_37].Fault5.byte=RXdata_Handler_CAN2[4];
			Cell[Number_37].Fault6=RXdata_Handler_CAN2[5];
			Cell[Number_37].Fault7=RXdata_Handler_CAN2[6];
			Cell[Number_37].Fault8=RXdata_Handler_CAN2[7];

			master1.cell[36].sFault1_2.byte = (RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8);
			master1.cell[36].sFault3_4.byte = (RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8);
			master1.cell[36].sFault5_6.byte = (RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8);
			master1.cell[36].sFault7_8.byte = (RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8);
		}
		break;
		case 0X1E410125:
		{
			Cell[Number_37].Status1.byte=RXdata_Handler_CAN2[0];
			Cell[Number_37].Status2=RXdata_Handler_CAN2[1];
			Cell[Number_37].Status3=RXdata_Handler_CAN2[2];

			master1.cell[36].sStatus1_2.byte = (RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8);
			master1.cell[36].sStatus3_4.byte = (RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8);
		}
		break;
		end
		Start
		case 0X1E200126:
		{
			Cell[Number_38].DCBUSVOLTAGE= (RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8)*FACTORDEVISION;
			Cell[Number_38].PSFB_INPUT_DC_CURRENT= (RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8)*FACTORDEVISION;
			Cell[Number_38].FEC_INPUT_AC_CURRENT= (RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8)*FACTORDEVISION;
			Cell[Number_38].PSFB_OUTPUT_DC_CURRENT = (RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8)*FACTORDEVISION;

			master1.cell[37].dc_bus_voltage=(RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8);
			master1.cell[37].dc_bus_current=(RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8);
			master1.cell[37].fec_input_current=(RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8);
			master1.cell[37].psfb_output_current=(RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8);
		}
		break;
		case 0X1E210126:
		{
			Cell[Number_38].PSFB_OUTPUT_DC_VOLTAGE=RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8;
			Cell[Number_38].AC_VOLTAGE_OPTIONAL=RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8;
			Cell[Number_38].AC_CURRENT_OPTIONAL=(RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8)*FACTORDEVISION;
			Cell[Number_38].TRAFO_TEMPERATURE =(RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8)*FACTORDEVISION;

			master1.cell[37].psfb_output_voltage=(RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8);
			master1.cell[37].trafo_temp=(RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8);
		}
		break;
		case 0X1E220126:
		{
			Cell[Number_38].FEC_TEMPERATURE=(RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8)*FACTORDEVISION;
			Cell[Number_38].PSFB_TEMPERATURE=(RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8)*FACTORDEVISION;
			Cell[Number_38].DIODE_TEMPERATURE=(RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8)*FACTORDEVISION;
			Cell[Number_38].Rsvd2 =(RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8);

			master1.cell[37].fec_temp=(RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8);
			master1.cell[37].psfb_temp=(RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8);
			master1.cell[37].diode_temp=(RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8);
		}
		break;
		case 0X1E230126:
		{
			Cell[Number_38].PHASE_DELAY=(RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8)*FACTORDEVISION;
			Cell[Number_38].VDC_GAIN=(RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8)*FACTORDEVISION;
			Cell[Number_38].VDC_OFFSET=(((RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8)*FACTORDEVISION)-OFFSET);
			Cell[Number_38].Rsvd3 =(RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8);
		}
		break;
		case 0X1E400126:
		{
			Cell[Number_38].Fault1=RXdata_Handler_CAN2[0];
			Cell[Number_38].Fault2=RXdata_Handler_CAN2[1];
			Cell[Number_38].Fault3=RXdata_Handler_CAN2[2];
			Cell[Number_38].Fault4=RXdata_Handler_CAN2[3];
			Cell[Number_38].Fault5.byte=RXdata_Handler_CAN2[4];
			Cell[Number_38].Fault6=RXdata_Handler_CAN2[5];
			Cell[Number_38].Fault7=RXdata_Handler_CAN2[6];
			Cell[Number_38].Fault8=RXdata_Handler_CAN2[7];

			master1.cell[37].sFault1_2.byte = (RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8);
			master1.cell[37].sFault3_4.byte = (RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8);
			master1.cell[37].sFault5_6.byte = (RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8);
			master1.cell[37].sFault7_8.byte = (RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8);
		}
		break;
		case 0X1E410126:
		{
			Cell[Number_38].Status1.byte=RXdata_Handler_CAN2[0];
			Cell[Number_38].Status2=RXdata_Handler_CAN2[1];
			Cell[Number_38].Status3=RXdata_Handler_CAN2[2];

			master1.cell[37].sStatus1_2.byte = (RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8);
			master1.cell[37].sStatus3_4.byte = (RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8);
		}
		break;
		end
		Start
		case 0X1E200127:
		{
			Cell[Number_39].DCBUSVOLTAGE= (RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8)*FACTORDEVISION;
			Cell[Number_39].PSFB_INPUT_DC_CURRENT= (RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8)*FACTORDEVISION;
			Cell[Number_39].FEC_INPUT_AC_CURRENT= (RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8)*FACTORDEVISION;
			Cell[Number_39].PSFB_OUTPUT_DC_CURRENT = (RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8)*FACTORDEVISION;

			master1.cell[38].dc_bus_voltage=(RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8);
			master1.cell[38].dc_bus_current=(RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8);
			master1.cell[38].fec_input_current=(RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8);
			master1.cell[38].psfb_output_current=(RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8);
		}
		break;
		case 0X1E210127:
		{
			Cell[Number_39].PSFB_OUTPUT_DC_VOLTAGE=RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8;
			Cell[Number_39].AC_VOLTAGE_OPTIONAL=RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8;
			Cell[Number_39].AC_CURRENT_OPTIONAL=(RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8)*FACTORDEVISION;
			Cell[Number_39].TRAFO_TEMPERATURE =(RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8)*FACTORDEVISION;

			master1.cell[38].psfb_output_voltage=(RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8);
			master1.cell[38].trafo_temp=(RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8);
		}
		break;
		case 0X1E220127:
		{
			Cell[Number_39].FEC_TEMPERATURE=(RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8)*FACTORDEVISION;
			Cell[Number_39].PSFB_TEMPERATURE=(RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8)*FACTORDEVISION;
			Cell[Number_39].DIODE_TEMPERATURE=(RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8)*FACTORDEVISION;
			Cell[Number_39].Rsvd2 =(RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8);

			master1.cell[38].fec_temp=(RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8);
			master1.cell[38].psfb_temp=(RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8);
			master1.cell[38].diode_temp=(RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8);
		}
		break;
		case 0X1E230127:
		{
			Cell[Number_39].PHASE_DELAY=(RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8)*FACTORDEVISION;
			Cell[Number_39].VDC_GAIN=(RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8)*FACTORDEVISION;
			Cell[Number_39].VDC_OFFSET=(((RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8)*FACTORDEVISION)-OFFSET);
			Cell[Number_39].Rsvd3 =(RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8);
		}
		break;
		case 0X1E400127:
		{
			Cell[Number_39].Fault1=RXdata_Handler_CAN2[0];
			Cell[Number_39].Fault2=RXdata_Handler_CAN2[1];
			Cell[Number_39].Fault3=RXdata_Handler_CAN2[2];
			Cell[Number_39].Fault4=RXdata_Handler_CAN2[3];
			Cell[Number_39].Fault5.byte=RXdata_Handler_CAN2[4];
			Cell[Number_39].Fault6=RXdata_Handler_CAN2[5];
			Cell[Number_39].Fault7=RXdata_Handler_CAN2[6];
			Cell[Number_39].Fault8=RXdata_Handler_CAN2[7];

			master1.cell[38].sFault1_2.byte = (RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8);
			master1.cell[38].sFault3_4.byte = (RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8);
			master1.cell[38].sFault5_6.byte = (RXdata_Handler_CAN2[4] | RXdata_Handler_CAN2[5] << 8);
			master1.cell[38].sFault7_8.byte = (RXdata_Handler_CAN2[6] | RXdata_Handler_CAN2[7] << 8);
		}
		break;
		case 0X1E410127:
		{
			Cell[Number_39].Status1.byte=RXdata_Handler_CAN2[0];
			Cell[Number_39].Status2=RXdata_Handler_CAN2[1];
			Cell[Number_39].Status3=RXdata_Handler_CAN2[2];

			master1.cell[38].sStatus1_2.byte = (RXdata_Handler_CAN2[0] | RXdata_Handler_CAN2[1] << 8);
			master1.cell[38].sStatus3_4.byte = (RXdata_Handler_CAN2[2] | RXdata_Handler_CAN2[3] << 8);
		}
		break;
		//#endif
		end
		default:
			break;
		}
	}
}

void checkCAN2Status()
{
	if((u8Slave_2_CAN2_Live!=5))//||(u8Slave_2_CAN2_Live!=5)||(u8Slave_3_CAN2_Live!=5))
		//	||			(u8Slave_4_CAN2_Live!=5)||(u8Slave_5_CAN2_Live!=5)||(u8Slave_6_CAN2_Live!=5))
	{
		criticalFault.bits.can_2_fail=1;
	}
	else
	{
		criticalFault.bits.can_2_fail=0;
	}
}
void counterReset_CAN2()
{
	u8Slave_1_CAN2_Live=0;
	u8Slave_2_CAN2_Live=0;
	u8Slave_3_CAN2_Live=0;
	u8Slave_4_CAN2_Live=0;
	u8Slave_5_CAN2_Live=0;
	u8Slave_6_CAN2_Live=0;
}*/


