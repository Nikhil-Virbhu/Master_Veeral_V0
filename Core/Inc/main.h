/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32g4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define V_DB2_Pin GPIO_PIN_2
#define V_DB2_GPIO_Port GPIOE
#define V_DB3_Pin GPIO_PIN_3
#define V_DB3_GPIO_Port GPIOE
#define V_DB4_Pin GPIO_PIN_4
#define V_DB4_GPIO_Port GPIOE
#define V_DB5_Pin GPIO_PIN_5
#define V_DB5_GPIO_Port GPIOE
#define V_DB6_Pin GPIO_PIN_6
#define V_DB6_GPIO_Port GPIOE
#define DI8_Pin GPIO_PIN_13
#define DI8_GPIO_Port GPIOC
#define SW3_Pin GPIO_PIN_9
#define SW3_GPIO_Port GPIOF
#define DI7_Pin GPIO_PIN_10
#define DI7_GPIO_Port GPIOF
#define W_DB0_Pin GPIO_PIN_0
#define W_DB0_GPIO_Port GPIOC
#define W_DB1_Pin GPIO_PIN_1
#define W_DB1_GPIO_Port GPIOC
#define W_DB2_Pin GPIO_PIN_2
#define W_DB2_GPIO_Port GPIOC
#define W_DB3_Pin GPIO_PIN_3
#define W_DB3_GPIO_Port GPIOC
#define DI6_Pin GPIO_PIN_2
#define DI6_GPIO_Port GPIOF
#define VAC_U_Pin GPIO_PIN_0
#define VAC_U_GPIO_Port GPIOA
#define VAC_V_Pin GPIO_PIN_1
#define VAC_V_GPIO_Port GPIOA
#define VAC_W_Pin GPIO_PIN_2
#define VAC_W_GPIO_Port GPIOA
#define VOUT_Pin GPIO_PIN_3
#define VOUT_GPIO_Port GPIOA
#define DAC1_Pin GPIO_PIN_4
#define DAC1_GPIO_Port GPIOA
#define DAC2_Pin GPIO_PIN_5
#define DAC2_GPIO_Port GPIOA
#define VAC_E_Pin GPIO_PIN_6
#define VAC_E_GPIO_Port GPIOA
#define IOUT_Pin GPIO_PIN_7
#define IOUT_GPIO_Port GPIOA
#define W_DB4_Pin GPIO_PIN_4
#define W_DB4_GPIO_Port GPIOC
#define W_DB5_Pin GPIO_PIN_5
#define W_DB5_GPIO_Port GPIOC
#define U_DB0_Pin GPIO_PIN_0
#define U_DB0_GPIO_Port GPIOB
#define U_DB1_Pin GPIO_PIN_1
#define U_DB1_GPIO_Port GPIOB
#define U_DB2_Pin GPIO_PIN_2
#define U_DB2_GPIO_Port GPIOB
#define V_DB7_Pin GPIO_PIN_7
#define V_DB7_GPIO_Port GPIOE
#define SYNC1_Pin GPIO_PIN_8
#define SYNC1_GPIO_Port GPIOE
#define SYNC2_Pin GPIO_PIN_9
#define SYNC2_GPIO_Port GPIOE
#define SYNC3_Pin GPIO_PIN_10
#define SYNC3_GPIO_Port GPIOE
#define STRB1_Pin GPIO_PIN_11
#define STRB1_GPIO_Port GPIOE
#define STRB2_Pin GPIO_PIN_12
#define STRB2_GPIO_Port GPIOE
#define V1_65_Pin GPIO_PIN_14
#define V1_65_GPIO_Port GPIOE
#define RLY2_Pin GPIO_PIN_15
#define RLY2_GPIO_Port GPIOE
#define ACK_SLV_Pin GPIO_PIN_10
#define ACK_SLV_GPIO_Port GPIOB
#define STRB3_Pin GPIO_PIN_11
#define STRB3_GPIO_Port GPIOB
#define E_FLT2_Pin GPIO_PIN_14
#define E_FLT2_GPIO_Port GPIOB
#define E_FLT1_Pin GPIO_PIN_15
#define E_FLT1_GPIO_Port GPIOB
#define TX_Pin GPIO_PIN_8
#define TX_GPIO_Port GPIOD
#define RX_Pin GPIO_PIN_9
#define RX_GPIO_Port GPIOD
#define IAC_W_Pin GPIO_PIN_10
#define IAC_W_GPIO_Port GPIOD
#define IAC_V_Pin GPIO_PIN_11
#define IAC_V_GPIO_Port GPIOD
#define IAC_U_Pin GPIO_PIN_12
#define IAC_U_GPIO_Port GPIOD
#define Tmpr2_Pin GPIO_PIN_13
#define Tmpr2_GPIO_Port GPIOD
#define Tmpr1_Pin GPIO_PIN_14
#define Tmpr1_GPIO_Port GPIOD
#define RLY1_Pin GPIO_PIN_15
#define RLY1_GPIO_Port GPIOD
#define W_DB6_Pin GPIO_PIN_6
#define W_DB6_GPIO_Port GPIOC
#define W_DB7_Pin GPIO_PIN_7
#define W_DB7_GPIO_Port GPIOC
#define SCL3_Pin GPIO_PIN_8
#define SCL3_GPIO_Port GPIOC
#define SDA3_Pin GPIO_PIN_9
#define SDA3_GPIO_Port GPIOC
#define PWM1H_AFE_Pin GPIO_PIN_8
#define PWM1H_AFE_GPIO_Port GPIOA
#define I_REF_Pin GPIO_PIN_9
#define I_REF_GPIO_Port GPIOA
#define PWM2H_AFE_Pin GPIO_PIN_10
#define PWM2H_AFE_GPIO_Port GPIOA
#define SW1_Pin GPIO_PIN_11
#define SW1_GPIO_Port GPIOA
#define TO_SG1_Pin GPIO_PIN_10
#define TO_SG1_GPIO_Port GPIOC
#define TO_SG2_Pin GPIO_PIN_11
#define TO_SG2_GPIO_Port GPIOC
#define TO_SG3_Pin GPIO_PIN_12
#define TO_SG3_GPIO_Port GPIOC
#define SW2_Pin GPIO_PIN_1
#define SW2_GPIO_Port GPIOD
#define DI0_Pin GPIO_PIN_2
#define DI0_GPIO_Port GPIOD
#define DI1_Pin GPIO_PIN_3
#define DI1_GPIO_Port GPIOD
#define DI2_Pin GPIO_PIN_4
#define DI2_GPIO_Port GPIOD
#define DI3_Pin GPIO_PIN_5
#define DI3_GPIO_Port GPIOD
#define DI4_Pin GPIO_PIN_6
#define DI4_GPIO_Port GPIOD
#define DI5_Pin GPIO_PIN_7
#define DI5_GPIO_Port GPIOD
#define U_DB3_Pin GPIO_PIN_3
#define U_DB3_GPIO_Port GPIOB
#define U_DB4_Pin GPIO_PIN_4
#define U_DB4_GPIO_Port GPIOB
#define U_DB5_Pin GPIO_PIN_5
#define U_DB5_GPIO_Port GPIOB
#define U_DB6_Pin GPIO_PIN_6
#define U_DB6_GPIO_Port GPIOB
#define U_DB7_Pin GPIO_PIN_7
#define U_DB7_GPIO_Port GPIOB
#define RLY3_Pin GPIO_PIN_9
#define RLY3_GPIO_Port GPIOB
#define V_DB0_Pin GPIO_PIN_0
#define V_DB0_GPIO_Port GPIOE
#define V_DB1_Pin GPIO_PIN_1
#define V_DB1_GPIO_Port GPIOE

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
