/*
 * CAN2_Transmitting.h
 *
 *  Created on: Aug 8, 2023
 *      Author: ujwalpatel
 */

#ifndef INC_CAN2_TRANSMITTING_H_
#define INC_CAN2_TRANSMITTING_H_

#include "main.h"

void API_CAN_IDC_IAC_GAIN_OFFSET(float RSVD1,float RSVD2,float RSVD3,float RSVD4);

void API_CAN_OT_IDCPSFBGAIN_TRAFO_PSFB_FEC_OVER_TEMP(float DIODE_OVER_TEMPERATURE,float TRAFO_OVER_TEMPERATURE,float PSFB_OVER_TEMPERATURE,float FEC_OVER_TEMPERATURE);

void API_CAN_DC_OVER_CURRNT_VOLT_DC_UNDER_CURRENT_VOLT(float DC_OVER_CURRENT,float DC_OVER_VOLTAGE,float DC_UNDER_VOLTAGE,float AC_OVER_CURRENT);

void API_CAN_TRAFO_FEC_GAIN_OFFSET(float TRAFO_TEMP_GAIN,float TRAFO_TEMP_OFFSET,float FEC_TEMP_GAIN,float FEC_TEMP_OFFSET);

void API_CAN_PSFB_GAIN_OFFSET(float PSFB_TEMP_GAIN,float PSFB_TEMP_OFFSET,float RSVD1,float RSVD2);

void API_CAN2_HEARTBEAT_MASTER01_CELL0139(void);

void API_CAN2_MASTER_PC_DEBUG_1(uint16_t Debug1,uint16_t Debug2,uint16_t Debug3, uint16_t Debug4);

void API_CAN2_MASTER_PC_DEBUG_2(uint16_t Debug5,uint16_t Debug6,uint16_t Debug7, uint16_t Debug8);

void API_CAN2_MASTER_PC_DEBUG_3(uint16_t Debug9,uint16_t Debug10,uint16_t Debug11, uint16_t Debug12);

void API_CAN_ID_IQ_VD_VQ(float Id, float Iq, float Vd, float Vq);

void API_CAN_VOUT_IOUT_VR_VY(float Vout, float Iout, float Vr, float Vy);

void API_CAN_VB_IR_IY_VDCREF(float Vb,float Ir, float Iy, float Vdcref);

void API_CAN_IB_VDCDIV(float Ib, float VdcDiv, float rsvd1, float rsvd2);

#endif /* INC_CAN2_TRANSMITTING_H_ */
