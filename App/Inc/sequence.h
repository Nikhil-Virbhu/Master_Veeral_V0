/*
 * sequence.h
 *
 *  Created on: 05-Oct-2023
 *      Author: KeyurAcharya
 */
#include "main.h"
#ifdef INC_SEQUENCE_H_

	/* Declaration of flags */
	uint8_t DC_contactor_close;
	uint8_t dc_contactor_close_wait;
	uint8_t dc_contactor_open_wait;

	void task_1ms(void);
	void task_1ms(void);
	void task_40ms(void);
	void task_100ms(void);
	void task_250ms(void);
	void task_1s(void);


#else

	extern void task_1ms(void);
	extern void task_40ms(void);
	extern void task_100ms(void);
	extern void task_250ms(void);
	extern void task_1s(void);
	extern uint8_t DC_contactor_close;
	extern uint8_t dc_contactor_close_wait;
	extern uint8_t dc_contactor_open_wait;

#endif /* INC_SEQUENCE_H_ */
