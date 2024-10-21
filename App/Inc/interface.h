/*
 * interface.h
 *
 *  Created on: 05-Dec-2023
 *      Author: KeyurAcharya
 *       *      Description: This file will have all possible interfaces to the MCU hardwares which are needed by APP.
 *      		We are doing this so the MCU call in APP can be reduced and strictly defined.
 *
 *      		By following this method we want to achieve an interface layer between the MCU and APP
 */
/*
 * DC contactor command is connected to RLY1 --> CN33  (pin no PD15)
 * DC ciontactor feedback is connected to DIO 	--> CN17 	  (pin no PD2)
 */

#ifndef INC_INTERFACE_H_
#define INC_INTERFACE_H_

#define DC_CONTACTOR_CLOSE_FB 		0					// DI received +24 Vdc
#define DC_CONTACTOR_OPEN_FB		1

#define GET_DC_CONTACTOR_FB			((HAL_GPIO_ReadPin(DI0_GPIO_Port,DI0_Pin)))						//DC contactor is connected to DI0

#define DC_CONTACTOR_CLOSE			(HAL_GPIO_WritePin(RLY1_GPIO_Port,RLY1_Pin,1))				//setting 1 on relay turns on the DC contactor (close)
#define DC_CONTACTOR_OPEN				(HAL_GPIO_WritePin(RLY1_GPIO_Port,RLY1_Pin,0))			//setting 0 on relay turns off the DC contactor (open)

#define DC_CONTACTOR_TEST						((HAL_GPIO_ReadPin(U_DB2_GPIO_Port,U_DB2_Pin)))
#define DC_CONTACTOR_TEST_CLOSE			((HAL_GPIO_ReadPin(U_DB3_GPIO_Port,U_DB3_Pin)))
#define DC_CONTACTOR_TEST_CLOSE_IND	(HAL_GPIO_WritePin(U_DB4_GPIO_Port,U_DB4_Pin,1))
#define DC_CONTACTOR_TEST_OPEN_IND		(HAL_GPIO_WritePin(U_DB4_GPIO_Port,U_DB4_Pin,0))
#define DC_CONTACTOR_TEST_FB_REC			(HAL_GPIO_WritePin(U_DB5_GPIO_Port,U_DB5_Pin,1))
#define DC_CONTACTOR_TEST_FB_FAIL			(HAL_GPIO_WritePin(U_DB5_GPIO_Port,U_DB5_Pin,0))

#endif /* INC_INTERFACE_H_ */
