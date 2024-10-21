/*
 * CAN2_Transmitting.c
 *
 *  Created on: Aug 8, 2023
 *      Author: ujwalpatel
 */

#include "CAN2_Transmitting.h"
//#include "fdcan.h"

#define DELAY 5
#define MULTIFACTOR_10 10
#define OFFSETFACTOR_100 100

/*extern FDCAN_TxHeaderTypeDef TxHeader_CAN2,TxHeader1_CAN2,TxHeader2_CAN2,TxHeader3_CAN2,TxHeader4_CAN2,TxHeader5_CAN2,TxHeader6_CAN2,TxHeader7_CAN2,TxHeader8_CAN2,TxHeader9_CAN2,TxHeader10_CAN2,TxHeader11_CAN2;
extern uint8_t u8MASTER_CAN2_Status;

uint8_t TxDataHandler_CAN2[8],TxDataHandler1_CAN2[8],TxDataHandler2_CAN2[8],TxDataHandler3_CAN2[8],TxDataHandler4_CAN2[8],TxDataHandler5_CAN2[8],
TxDataHandler6_CAN2[8],TxDataHandler7_CAN2[8],TxDataHandler8_CAN2[8],TxDataHandler9_CAN2[8],TxDataHandler10_CAN2[8],TxDataHandler11_CAN2[8];
uint8_t u8connectorcounter_CAN2;



void API_CAN_IDC_IAC_GAIN_OFFSET(float RSVD1,float RSVD2,float RSVD3,float RSVD4)
{
	Converting Required Data type
	uint16_t u16RSVD1=(RSVD1*MULTIFACTOR_10);

	uint16_t u16RSVD2=((RSVD2+OFFSETFACTOR_100)*MULTIFACTOR_10);

	uint16_t u16RSVD3=(RSVD3*MULTIFACTOR_10);

	uint16_t u16RSVD4=((RSVD4+OFFSETFACTOR_100)*MULTIFACTOR_10);

	TxDataHandler_CAN2[0]=u16RSVD1;
	TxDataHandler_CAN2[1]=u16RSVD1>>8;
	TxDataHandler_CAN2[2]=u16RSVD2;
	TxDataHandler_CAN2[3]=u16RSVD2>>8;
	TxDataHandler_CAN2[4]=u16RSVD3;
	TxDataHandler_CAN2[5]=u16RSVD3>>8;
	TxDataHandler_CAN2[6]=u16RSVD4;
	TxDataHandler_CAN2[7]=u16RSVD4>>8;

	if (HAL_FDCAN_AddMessageToTxFifoQ(&hfdcan2, &TxHeader_CAN2, TxDataHandler_CAN2) != HAL_OK)
	{}
	else
	{}
	HAL_Delay(DELAY);
}

void API_CAN_OT_IDCPSFBGAIN_TRAFO_PSFB_FEC_OVER_TEMP(float DIODE_OVER_TEMPERATURE,float TRAFO_OVER_TEMPERATURE,float PSFB_OVER_TEMPERATURE,float FEC_OVER_TEMPERATURE)
{
	Converting Required Data type
	uint16_t u16DIODE_OVER_TEMPERATURE = (DIODE_OVER_TEMPERATURE*MULTIFACTOR_10);

	uint16_t u16TRAFO_OVER_TEMPERATURE = (TRAFO_OVER_TEMPERATURE*MULTIFACTOR_10);

	uint16_t u16PSFB_OVER_TEMPERATURE = (PSFB_OVER_TEMPERATURE*MULTIFACTOR_10);

	uint16_t u16FEC_OVER_TEMPERATURE = (FEC_OVER_TEMPERATURE*MULTIFACTOR_10);

	TxDataHandler1_CAN2[0]=u16DIODE_OVER_TEMPERATURE;
	TxDataHandler1_CAN2[1]=u16DIODE_OVER_TEMPERATURE>>8;
	TxDataHandler1_CAN2[2]=u16TRAFO_OVER_TEMPERATURE;
	TxDataHandler1_CAN2[3]=u16TRAFO_OVER_TEMPERATURE>>8;
	TxDataHandler1_CAN2[4]=u16PSFB_OVER_TEMPERATURE;
	TxDataHandler1_CAN2[5]=u16PSFB_OVER_TEMPERATURE>>8;
	TxDataHandler1_CAN2[6]=u16FEC_OVER_TEMPERATURE;
	TxDataHandler1_CAN2[7]=u16FEC_OVER_TEMPERATURE>>8;

	if (HAL_FDCAN_AddMessageToTxFifoQ(&hfdcan2, &TxHeader1_CAN2, TxDataHandler1_CAN2) != HAL_OK)
	{}
	else
	{}
	HAL_Delay(DELAY);
}

void API_CAN_DC_OVER_CURRNT_VOLT_DC_UNDER_CURRENT_VOLT(float DC_OVER_CURRENT,float DC_OVER_VOLTAGE,float DC_UNDER_VOLTAGE,float AC_OVER_CURRENT)
{
	Converting Required Data type
	uint16_t u16DC_OVER_CURRENT = (DC_OVER_CURRENT*MULTIFACTOR_10);

	uint16_t u16DC_OVER_VOLTAGE = (DC_OVER_VOLTAGE*MULTIFACTOR_10);

	uint16_t u16DC_UNDER_VOLTAGE = (DC_UNDER_VOLTAGE*MULTIFACTOR_10);

	uint16_t u16AC_OVER_CURRENT = (AC_OVER_CURRENT*MULTIFACTOR_10);

	TxDataHandler2_CAN2[0]=u16DC_OVER_CURRENT;
	TxDataHandler2_CAN2[1]=u16DC_OVER_CURRENT>>8;
	TxDataHandler2_CAN2[2]=u16DC_OVER_VOLTAGE;
	TxDataHandler2_CAN2[3]=u16DC_OVER_VOLTAGE>>8;
	TxDataHandler2_CAN2[4]=u16DC_UNDER_VOLTAGE;
	TxDataHandler2_CAN2[5]=u16DC_UNDER_VOLTAGE>>8;
	TxDataHandler2_CAN2[6]=u16AC_OVER_CURRENT;
	TxDataHandler2_CAN2[7]=u16AC_OVER_CURRENT>>8;

	if (HAL_FDCAN_AddMessageToTxFifoQ(&hfdcan2, &TxHeader2_CAN2, TxDataHandler2_CAN2) != HAL_OK)
	{}
	else
	{}
	HAL_Delay(DELAY);
}

void API_CAN2_HEARTBEAT_MASTER01_CELL0139()
{
	if (HAL_FDCAN_AddMessageToTxFifoQ(&hfdcan2, &TxHeader3_CAN2, TxDataHandler5_CAN2) != HAL_OK)
	{
		u8MASTER_CAN2_Status=0;
	}
	else
	{
		TxDataHandler5_CAN2[0]=u8connectorcounter_CAN2++;
		u8MASTER_CAN2_Status=1;
	}
	HAL_Delay(1);
}

void API_CAN_TRAFO_FEC_GAIN_OFFSET(float TRAFO_TEMP_GAIN,float TRAFO_TEMP_OFFSET,float FEC_TEMP_GAIN,float FEC_TEMP_OFFSET)
{
	//Converting Required Data type
	uint16_t u16TRAFO_TEMP_GAIN=(TRAFO_TEMP_GAIN*MULTIFACTOR_10);

	uint16_t u16TRAFO_TEMP_OFFSET=((TRAFO_TEMP_OFFSET+OFFSETFACTOR_100)*MULTIFACTOR_10);

	uint16_t u16FEC_TEMP_GAIN=(FEC_TEMP_GAIN*MULTIFACTOR_10);

	uint16_t u16FEC_TEMP_OFFSET=((FEC_TEMP_OFFSET+OFFSETFACTOR_100)*MULTIFACTOR_10);

	TxDataHandler3_CAN2[0]=u16TRAFO_TEMP_GAIN;
	TxDataHandler3_CAN2[1]=u16TRAFO_TEMP_GAIN>>8;
	TxDataHandler3_CAN2[2]=u16TRAFO_TEMP_OFFSET;
	TxDataHandler3_CAN2[3]=u16TRAFO_TEMP_OFFSET>>8;
	TxDataHandler3_CAN2[4]=u16FEC_TEMP_GAIN;
	TxDataHandler3_CAN2[5]=u16FEC_TEMP_GAIN>>8;
	TxDataHandler3_CAN2[6]=u16FEC_TEMP_OFFSET;
	TxDataHandler3_CAN2[7]=u16FEC_TEMP_OFFSET>>8;

	if (HAL_FDCAN_AddMessageToTxFifoQ(&hfdcan2, &TxHeader3_CAN2, TxDataHandler3_CAN2) != HAL_OK)
	{}
	else
	{}
	HAL_Delay(DELAY);
}

void API_CAN_PSFB_GAIN_OFFSET(float PSFB_TEMP_GAIN,float PSFB_TEMP_OFFSET,float RSVD1,float RSVD2)
{
	//Converting Required Data type
	uint16_t u16PSFB_TEMP_GAIN=(PSFB_TEMP_GAIN*MULTIFACTOR_10);

	uint16_t u16PSFB_TEMP_OFFSET=((PSFB_TEMP_OFFSET+OFFSETFACTOR_100)*MULTIFACTOR_10);

	uint16_t u16RSVD1=RSVD1;

	uint16_t u16RSVD2=RSVD2;

	TxDataHandler4_CAN2[0]=u16PSFB_TEMP_GAIN;
	TxDataHandler4_CAN2[1]=u16PSFB_TEMP_GAIN>>8;
	TxDataHandler4_CAN2[2]=u16PSFB_TEMP_OFFSET;
	TxDataHandler4_CAN2[3]=u16PSFB_TEMP_OFFSET>>8;
	TxDataHandler4_CAN2[4]=u16RSVD1;
	TxDataHandler4_CAN2[5]=u16RSVD1>>8;
	TxDataHandler4_CAN2[6]=u16RSVD2;
	TxDataHandler4_CAN2[7]=u16RSVD2>>8;

	if (HAL_FDCAN_AddMessageToTxFifoQ(&hfdcan2, &TxHeader4_CAN2, TxDataHandler4_CAN2) != HAL_OK)
	{}
	else
	{}
	HAL_Delay(DELAY);
}

void API_CAN_ID_IQ_VD_VQ(float Id, float Iq, float Vd, float Vq)
{
	uint16_t uId = ((Id + OFFSETFACTOR_100) * MULTIFACTOR_10);
	uint16_t uIq = ((Iq + OFFSETFACTOR_100) * MULTIFACTOR_10);
	uint16_t uVd = (Vd * MULTIFACTOR_10);
	uint16_t uVq = (Vq * MULTIFACTOR_10);

	TxDataHandler8_CAN2[0] = uId;
	TxDataHandler8_CAN2[1] = uId>>8;
	TxDataHandler8_CAN2[2] = uIq;
	TxDataHandler8_CAN2[3] = uIq >> 8;
	TxDataHandler8_CAN2[4] = uVd;
	TxDataHandler8_CAN2[5] = uVd >> 8;
	TxDataHandler8_CAN2[6] = uVq;
	TxDataHandler8_CAN2[7] = uVq >> 8;

	if (HAL_FDCAN_AddMessageToTxFifoQ(&hfdcan2, &TxHeader8_CAN2, TxDataHandler8_CAN2) != HAL_OK)
	{}
	else
	{}
	HAL_Delay(1);

}

void API_CAN_VOUT_IOUT_VR_VY(float Vout, float Iout, float Vr, float Vy)
{
	uint16_t uVout = (Vout * MULTIFACTOR_10);
	//uint16_t uIout = ( * MULTIFACTOR_10);
	uint16_t uIout = ((Iout + OFFSETFACTOR_100) * MULTIFACTOR_10);
	//uint16_t uVr = (Vr * MULTIFACTOR_10);
	uint16_t uVr = ((Vr + OFFSETFACTOR_100) * MULTIFACTOR_10);
	//uint16_t uVy = (Vy * MULTIFACTOR_10);
	uint16_t uVy = ((Vy + OFFSETFACTOR_100) * MULTIFACTOR_10);

	TxDataHandler9_CAN2[0] = uVout;
	TxDataHandler9_CAN2[1] = uVout>>8;
	TxDataHandler9_CAN2[2] = uIout;
	TxDataHandler9_CAN2[3] = uIout >> 8;
	TxDataHandler9_CAN2[4] = uVr;
	TxDataHandler9_CAN2[5] = uVr >> 8;
	TxDataHandler9_CAN2[6] = uVy;
	TxDataHandler9_CAN2[7] = uVy >> 8;

	if (HAL_FDCAN_AddMessageToTxFifoQ(&hfdcan2, &TxHeader9_CAN2, TxDataHandler9_CAN2) != HAL_OK)
	{}
	else
	{}
	HAL_Delay(1);
}

void API_CAN_VB_IR_IY_VDCREF(float Vb,float Ir, float Iy, float Vdcref)
{
	//uint16_t uVb = (Vb * MULTIFACTOR_10);
	uint16_t uVb = ((Vb + OFFSETFACTOR_100) * MULTIFACTOR_10);
	uint16_t uIr = (Ir * MULTIFACTOR_10);
	uint16_t uIy = (Iy * MULTIFACTOR_10);
	//uint16_t uVdcref = (Vdcref * MULTIFACTOR_10);
	uint16_t uVdcref = ((Vdcref + OFFSETFACTOR_100) * MULTIFACTOR_10);

	TxDataHandler10_CAN2[0] = uVb;
	TxDataHandler10_CAN2[1] = uVb>>8;
	TxDataHandler10_CAN2[2] = uIr;
	TxDataHandler10_CAN2[3] = uIr >> 8;
	TxDataHandler10_CAN2[4] = uIy;
	TxDataHandler10_CAN2[5] = uIy >> 8;
	TxDataHandler10_CAN2[6] = uVdcref;
	TxDataHandler10_CAN2[7] = uVdcref >> 8;

	if (HAL_FDCAN_AddMessageToTxFifoQ(&hfdcan2, &TxHeader10_CAN2, TxDataHandler10_CAN2) != HAL_OK)
	{}
	else
	{}
	HAL_Delay(1);
}

void API_CAN_IB_VDCDIV(float Ib, float VdcDiv, float rsvd1, float rsvd2)
{
	uint16_t uIb = (Ib * MULTIFACTOR_10);
	uint16_t uVdcDiv = (VdcDiv * MULTIFACTOR_10);
	uint16_t ursvd1 = ((rsvd1 +OFFSETFACTOR_100) * MULTIFACTOR_10);
	uint16_t ursvd2 = ((rsvd2 +OFFSETFACTOR_100) * MULTIFACTOR_10);

	TxDataHandler11_CAN2[0] = uIb;
	TxDataHandler11_CAN2[1] = uIb>>8;
	TxDataHandler11_CAN2[2] = uVdcDiv;
	TxDataHandler11_CAN2[3] = uVdcDiv >> 8;
	TxDataHandler11_CAN2[4] = ursvd1;
	TxDataHandler11_CAN2[5] = ursvd1 >> 8;
	TxDataHandler11_CAN2[6] = ursvd2;
	TxDataHandler11_CAN2[7] = ursvd2 >> 8;

	if (HAL_FDCAN_AddMessageToTxFifoQ(&hfdcan2, &TxHeader11_CAN2, TxDataHandler11_CAN2) != HAL_OK)
	{}
	else
	{}
	HAL_Delay(1);
}

void API_CAN2_MASTER_PC_DEBUG_1(uint16_t Debug1,uint16_t Debug2,uint16_t Debug3, uint16_t Debug4)
{

	TxDataHandler6_CAN2[0]=Debug1;
	TxDataHandler6_CAN2[1]=Debug1>>8;
	TxDataHandler6_CAN2[2]=Debug2;
	TxDataHandler6_CAN2[3]=Debug2>>8;
	TxDataHandler6_CAN2[4]=Debug3;
	TxDataHandler6_CAN2[5]=Debug3>>8;
	TxDataHandler6_CAN2[6]=Debug4;
	TxDataHandler6_CAN2[7]=Debug4>>8;

	if (HAL_FDCAN_AddMessageToTxFifoQ(&hfdcan2, &TxHeader5_CAN2, TxDataHandler6_CAN2) != HAL_OK)
	{}
	else
	{}
	HAL_Delay(DELAY);
}


void API_CAN2_MASTER_PC_DEBUG_2(uint16_t Debug5,uint16_t Debug6,uint16_t Debug7, uint16_t Debug8)
{

	TxDataHandler7_CAN2[0]=Debug5;
	TxDataHandler7_CAN2[1]=Debug5>>8;
	TxDataHandler7_CAN2[2]=Debug6;
	TxDataHandler7_CAN2[3]=Debug6>>8;
	TxDataHandler7_CAN2[4]=Debug7;
	TxDataHandler7_CAN2[5]=Debug7>>8;
	TxDataHandler7_CAN2[6]=Debug8;
	TxDataHandler7_CAN2[7]=Debug8>>8;

	if (HAL_FDCAN_AddMessageToTxFifoQ(&hfdcan2, &TxHeader6_CAN2, TxDataHandler7_CAN2) != HAL_OK)
	{}
	else
	{}
	HAL_Delay(DELAY);
}

void API_CAN2_MASTER_PC_DEBUG_3(uint16_t Debug9,uint16_t Debug10,uint16_t Debug11, uint16_t Debug12)
{

	TxDataHandler8_CAN2[0]=Debug9;
	TxDataHandler8_CAN2[1]=Debug9>>8;
	TxDataHandler8_CAN2[2]=Debug10;
	TxDataHandler8_CAN2[3]=Debug10>>8;
	TxDataHandler8_CAN2[4]=Debug11;
	TxDataHandler8_CAN2[5]=Debug11>>8;
	TxDataHandler8_CAN2[6]=Debug12;
	TxDataHandler8_CAN2[7]=Debug12>>8;

	if (HAL_FDCAN_AddMessageToTxFifoQ(&hfdcan2, &TxHeader7_CAN2, TxDataHandler8_CAN2) != HAL_OK)
	{}
	else
	{}
	HAL_Delay(DELAY);
}*/



