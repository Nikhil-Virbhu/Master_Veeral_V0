/*
 * CAN1_Receving.h
 *
 *  Created on: Aug 4, 2023
 *      Author: ujwalpatel
 */

#ifndef INC_CAN1_RECEVING_H_
#define INC_CAN1_RECEVING_H_

#include "main.h"
//#include "CAN_Parameters.h"
void checkCAN1Status(void);
void counterReset_CAN1(void);

void Master_CANFD3_Received(void);


#endif /* INC_CAN1_RECEVING_H_ */
