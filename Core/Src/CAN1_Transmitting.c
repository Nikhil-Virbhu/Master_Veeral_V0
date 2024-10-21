/*
 * CAN1_Transmitting.c
 *
 *  Created on: Jul 21, 2023
 *      Author: ujwalpatel
 */
#include "CAN1_Transmitting.h"
//#include "fdcan.h"

#define MULTIFACTOR_10 10
#define OFFSETFACTOR_100 100
extern uint8_t can_debug1, can_debug2, can_debug_flag;

//extern FDCAN_TxHeaderTypeDef TxHeader_CAN1,TxHeader1_CAN1,TxHeader2_CAN1,
							 TxHeader_CAN2;
//extern FDCAN_RxHeaderTypeDef RxHeader_CAN1,
							 RxHeader_CAN2;
extern uint8_t u8MASTER_CAN1_Status;

uint8_t TxDataHandler_CAN1[8],TxDataHandler2_CAN1[8];

uint8_t u8connectorcounter;

void API_CAN_Duty_RYB(uint16_t DUTY_RATIO_FEC_R,uint16_t DUTY_RATIO_FEC_Y,uint16_t DUTY_RATIO_FEC_B,uint16_t CMNDS)
{
	/*Converting Required Data type*/
	//uint16_t u16Gate_Command_Pulse=(Gate_Command_Pulse);

	TxDataHandler_CAN1[0]=DUTY_RATIO_FEC_R;
	TxDataHandler_CAN1[1]=DUTY_RATIO_FEC_R>>8;
	TxDataHandler_CAN1[2]=DUTY_RATIO_FEC_Y;
	TxDataHandler_CAN1[3]=DUTY_RATIO_FEC_Y>>8;
	TxDataHandler_CAN1[4]=DUTY_RATIO_FEC_B;
	TxDataHandler_CAN1[5]=DUTY_RATIO_FEC_B>>8;
	TxDataHandler_CAN1[6]=CMNDS;
	TxDataHandler_CAN1[7]=CMNDS>>8;

//if (HAL_FDCAN_AddMessageToTxFifoQ(&hfdcan2, &TxHeader_CAN2, TxDataHandler_CAN1) != HAL_OK) // For testing CAN 2
	/*if (HAL_FDCAN_AddMessageToTxFifoQ(&hfdcan1, &TxHeader_CAN1, TxDataHandler_CAN1) != HAL_OK)
	{
//		can_debug1++;
		can_debug_flag = 1;

	}
	else
	{
		can_debug_flag = 0;
//		can_debug2++;
	}*/
//}

//void API_CAN1_HEARTBEAT_MASTER01_CELL0139()
//{
	/*if (HAL_FDCAN_AddMessageToTxFifoQ(&hfdcan1, &TxHeader2_CAN1, TxDataHandler2_CAN1) != HAL_OK)
	{
		u8MASTER_CAN1_Status=0;
	}
	else
	{
		TxDataHandler2_CAN1[0]=u8connectorcounter++;
		u8MASTER_CAN1_Status=1;
	}
	HAL_Delay(10);//10*/
}
