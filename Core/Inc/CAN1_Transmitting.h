/*
 * CAN1_Transmitting.h
 *
 *  Created on: Jul 21, 2023
 *      Author: ujwalpatel
 */

#ifndef INC_CAN1_TRANSMITTING_H_
#define INC_CAN1_TRANSMITTING_H_

#include "main.h"

void API_CAN_Duty_RYB(uint16_t DUTY_RATIO_FEC_R,uint16_t DUTY_RATIO_FEC_Y,uint16_t DUTY_RATIO_FEC_B,uint16_t CMNDS);
void API_CAN1_HEARTBEAT_MASTER01_CELL0139();
#endif /* INC_CAN1_TRANSMITTING_H_ */
