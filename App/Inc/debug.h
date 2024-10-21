/*File description: DAC debug header file
 *Functions used:
 *Reference document:
 */
#include "main.h"
#include "dac.h"

#define TOTAL_DAC_SIGNALS 11
enum DAC_Output_Quantity {dac_vac_r,dac_vac_y,dac_vac_b,dac_sogi,dac_srf,dac_iac_r,dac_iac_y,dac_iac_b,dac_vr,dac_vy,dac_vb};
#define RX_DATA_BUFF 200
#define TX_DATA_BUFF 200

#ifdef _DEBUG_H_
	uint8_t dac1 = 1 , dac2 = 4 ; //DAC Variables
	uint32_t dac1_data;
	uint32_t dac2_data;
	float DAC_Value[TOTAL_DAC_SIGNALS];
	uint32_t DAC_update(uint8_t signal);
	void DAC_Out(void);
	uint8_t RxData[RX_DATA_BUFF]; //UART Receive buffer
	uint8_t TxData[TX_DATA_BUFF]; //UART Transmit buffer

#else
	extern uint8_t dac1, dac2; //DAC Variables
	extern uint32_t dac1_data;
	extern uint32_t dac2_data;
	extern float DAC_Value[TOTAL_DAC_SIGNALS];
	extern uint32_t DAC_update(uint8_t signal);
	extern void DAC_Out(void);
	extern uint8_t RxData[RX_DATA_BUFF]; //UART Receive buffer
	extern uint8_t TxData[TX_DATA_BUFF]; //UART Transmit buffer
#endif
