/*
 * CAN1_Receving.c
 *
 *  Created on: Aug 4, 2023
 *      Author: ujwalpatel
 */

#include "CAN_Parameters.h"
#include "CAN1_Receving.h"
//#include "fdcan.h"
#include "process.h"
#include "protection.h"
#include "Monitor_Master_Parameters.h"

#define FACTORDEVISION 0.1
#define MASTER_CAN3_RECEVED_ID 0X1E0001B

//extern FDCAN_RxHeaderTypeDef RxHeader_CAN1,RxHeader_CAN2,RxHeader_CAN3;
extern configParameters ConfigPara;
extern uint16_t masterAddress;


cell_limits cellLimit;
Enable_and_rated_params enableRated;
commands command;
HMI_Params Params;
Output_Set outputSetParams;

uint8_t u8CANFDtempvalue,RXdata_Handler_CAN1[8],u8Slave_1_CAN1_Live,u8Slave_2_CAN1_Live,u8Slave_3_CAN1_Live,/**/u8Slave_4_CAN1_Live,u8Slave_5_CAN1_Live,u8Slave_6_CAN1_Live/**/,RXdata_Handler_CAN3[64]/*,RXdata_Handler_CAN2[8]*/;

static uint16_t Master_RSVD;

/*
void HAL_FDCAN_RxFifo0Callback(FDCAN_HandleTypeDef *hfdcan, uint32_t RxFifo0ITs)
{
	if((RxFifo0ITs & FDCAN_IT_RX_FIFO0_NEW_MESSAGE) != RESET)
	{
		 Retrieve Rx messages from RX FIFO0
		if (HAL_FDCAN_GetRxMessage(&hfdcan1, FDCAN_RX_FIFO0, &RxHeader_CAN1, RXdata_Handler_CAN1) != HAL_OK)
		{Error_Handler();}
		else
		{Do Nothing}

		switch(RxHeader_CAN1.Identifier)
		{
		case 0X1EC10101:
		{
			u8Slave_1_CAN1_Live=RXdata_Handler_CAN1[0];
			Cell[1].Major_Firmware = RXdata_Handler_CAN1[6];
		}
		break;
		case 0X1EC1010E:
		{
			u8Slave_2_CAN1_Live=RXdata_Handler_CAN1[0];
			Cell[14].Major_Firmware = RXdata_Handler_CAN1[6];
		}
		break;
		case 0X1EC1011B:
		{
			u8Slave_3_CAN1_Live=RXdata_Handler_CAN1[0];
			Cell[27].Major_Firmware = RXdata_Handler_CAN1[6];
		}
		break;
		case 0X1EC10102:
		{
			u8Slave_4_CAN1_Live=RXdata_Handler_CAN1[0];
			Cell[2].Major_Firmware = RXdata_Handler_CAN1[6];
		}
		break;
		case 0X1EC1010F:
		{
			u8Slave_5_CAN1_Live=RXdata_Handler_CAN1[0];
			Cell[15].Major_Firmware = RXdata_Handler_CAN1[6];
		}
		break;
		case 0X1EC1011C:
		{
			u8Slave_6_CAN1_Live=RXdata_Handler_CAN1[0];
			Cell[28].Major_Firmware = RXdata_Handler_CAN1[6];
		}
		break;
		default:
			break;
		}

		CANFD3
		if (HAL_FDCAN_GetRxMessage(&hfdcan3, FDCAN_RX_FIFO0, &RxHeader_CAN3, RXdata_Handler_CAN3) != HAL_OK)
		{Error_Handler();}
		else
		{Do Nothing}

		if (RxHeader_CAN3.Identifier == (MASTER_CAN3_RECEVED_ID << 4| masterAddress))
		{
			Master_CANFD3_Received();
		}
		else {}
	}
}

void Master_CANFD3_Received(void)
{
	if(((RXdata_Handler_CAN3[0] | RXdata_Handler_CAN3[1] << 8) & (1 << 0)))
	{
		Params.control.bits.converteron_off=1;
	}
	else
	{
		Params.control.bits.converteron_off=0;
	}

	if(((RXdata_Handler_CAN3[0] | RXdata_Handler_CAN3[1] << 8) & (1 << 1)))
	{
		Params.control.bits.upstream_breaker=1;
	}
	else
	{
		Params.control.bits.upstream_breaker=0;
	}


	Params.calibration_PT = ((RXdata_Handler_CAN3[3] | RXdata_Handler_CAN3[2] << 8) * FACTORDEVISION);
	Params.calibration_CT = ((RXdata_Handler_CAN3[5] | RXdata_Handler_CAN3[4] << 8) * FACTORDEVISION);
	Params.acGridOVL_limit = ((RXdata_Handler_CAN3[7] | RXdata_Handler_CAN3[6] << 8) * FACTORDEVISION);

	Params.acGridUVL_limit = ((RXdata_Handler_CAN3[9] | RXdata_Handler_CAN3[8] << 8) * FACTORDEVISION);
	Params.dcOutOVL_limit = ((RXdata_Handler_CAN3[11] | RXdata_Handler_CAN3[10] << 8) * FACTORDEVISION);
	Params.dcOutOCL_limit = ((RXdata_Handler_CAN3[13] | RXdata_Handler_CAN3[12] << 8) * FACTORDEVISION);

	if(((RXdata_Handler_CAN3[15] | RXdata_Handler_CAN3[14] << 8) & (1 << masterAddress)))
	{
		if(((RXdata_Handler_CAN3[15] | RXdata_Handler_CAN3[14] << 8) & (1 << 0)))
		{
			enableRated.moduleEnable.bits.module_Enable=1;
		}
		else
		{
			enableRated.moduleEnable.bits.module_Enable=0;
		}
	}
	else{}

	Master_RSVD = (RXdata_Handler_CAN3[17] | RXdata_Handler_CAN3[16] << 8);
	Master_RSVD = (RXdata_Handler_CAN3[19] | RXdata_Handler_CAN3[18] << 8);
	Master_RSVD = (RXdata_Handler_CAN3[21] | RXdata_Handler_CAN3[20] << 8);
	Master_RSVD = (RXdata_Handler_CAN3[23] | RXdata_Handler_CAN3[22] << 8);
	Master_RSVD = (RXdata_Handler_CAN3[25] | RXdata_Handler_CAN3[24] << 8);


	if(((RXdata_Handler_CAN3[27] | RXdata_Handler_CAN3[26] << 8) & (1 << masterAddress)))
	{
		if(((RXdata_Handler_CAN3[27] | RXdata_Handler_CAN3[26] << 8) & (1 << 0)))
		{
			command.bits.DC_contactor=1;
		}
		else
		{
			command.bits.DC_contactor=0;
		}
	}
	else{}

	if(((RXdata_Handler_CAN3[29] | RXdata_Handler_CAN3[28] << 8) & (1 << masterAddress)))
	{
		if(((RXdata_Handler_CAN3[29] | RXdata_Handler_CAN3[28] << 8) & (1 << 0)))
		{
			command.bits.LBS_command=1;
		}
		else
		{
			command.bits.LBS_command=0;
		}
	}
	else{}

	if(((RXdata_Handler_CAN3[31] | RXdata_Handler_CAN3[30] << 8) & (1 << masterAddress)))
	{
		if(((RXdata_Handler_CAN3[31] | RXdata_Handler_CAN3[30] << 8) & (1 << 0)))
		{
			command.bits.main_breaker_command=1;
		}
		else
		{
			command.bits.main_breaker_command=0;
		}
	}
	else{}

	if(((RXdata_Handler_CAN3[33] | RXdata_Handler_CAN3[32] << 8) & (1 << masterAddress)))
	{
		if(((RXdata_Handler_CAN3[33] | RXdata_Handler_CAN3[32] << 8) & (1 << 0)))
		{
			command.bits.space_heater_command=1;
		}
		else
		{
			command.bits.space_heater_command=0;
		}
	}
	else{}

	Master_RSVD = (RXdata_Handler_CAN3[35] | RXdata_Handler_CAN3[34] << 8);
	Master_RSVD = (RXdata_Handler_CAN3[37] | RXdata_Handler_CAN3[36] << 8);
	Master_RSVD = (RXdata_Handler_CAN3[39] | RXdata_Handler_CAN3[38] << 8);

	outputSetParams.totalOutPower_set = ((RXdata_Handler_CAN3[41] | RXdata_Handler_CAN3[40] << 8) * FACTORDEVISION);
	outputSetParams.OutVol_set = ((RXdata_Handler_CAN3[43] | RXdata_Handler_CAN3[42] << 8) * FACTORDEVISION);
	outputSetParams.OutCur_set = ((RXdata_Handler_CAN3[45] | RXdata_Handler_CAN3[44] << 8) * FACTORDEVISION);
	enableRated.ratedPower = ((RXdata_Handler_CAN3[47] | RXdata_Handler_CAN3[46] << 8));
	enableRated.ratedCurrent = ((RXdata_Handler_CAN3[49] | RXdata_Handler_CAN3[48] << 8));
	cellLimit.trafo_temp_limit = ((RXdata_Handler_CAN3[51] | RXdata_Handler_CAN3[50] << 8) * FACTORDEVISION);
	cellLimit.diode_temp_limit = ((RXdata_Handler_CAN3[53] | RXdata_Handler_CAN3[52] << 8) * FACTORDEVISION);
	cellLimit.psfb_temp_limit = ((RXdata_Handler_CAN3[55] | RXdata_Handler_CAN3[54] << 8) * FACTORDEVISION);
	cellLimit.afe_temp_limit = ((RXdata_Handler_CAN3[57] | RXdata_Handler_CAN3[56] << 8) * FACTORDEVISION);
	cellLimit.Over_cur_limit = ((RXdata_Handler_CAN3[59] | RXdata_Handler_CAN3[58] << 8) * FACTORDEVISION);
	cellLimit.Under_volt_limit = ((RXdata_Handler_CAN3[61] | RXdata_Handler_CAN3[60] << 8) * FACTORDEVISION);
	cellLimit.Over_volt_limit = ((RXdata_Handler_CAN3[63] | RXdata_Handler_CAN3[62] << 8) * FACTORDEVISION);
}

void checkCAN1Status()
{
	if((u8Slave_2_CAN1_Live!=5))//||(u8Slave_2_CAN1_Live!=5)||(u8Slave_3_CAN1_Live!=5))
			//||(u8Slave_4_CAN1_Live!=5)||(u8Slave_5_CAN1_Live!=5)||(u8Slave_6_CAN1_Live!=5))
	{
		criticalFault.bits.can_1_fail=1;
	}
	else
	{
		criticalFault.bits.can_1_fail=0;
	}
}

void counterReset_CAN1()
{
	u8Slave_1_CAN1_Live=0;
	u8Slave_2_CAN1_Live=0;
	u8Slave_3_CAN1_Live=0;
	u8Slave_4_CAN1_Live=0;
	u8Slave_5_CAN1_Live=0;
	u8Slave_6_CAN1_Live=0;
}
*/
