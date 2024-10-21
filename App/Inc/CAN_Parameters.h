/*
 * CAN_Parameters.h
 *
 *  Created on: Aug 4, 2023
 *      Author: ujwalpatel
 */
#include "main.h"

typedef union
	{
		struct
		{
			uint8_t sHealthStatus: 1;
			uint8_t psfbFeedback : 1;
			uint8_t rsvd2 : 1;
			uint8_t rsvd3 : 1;
			uint8_t rsvd4 : 1;
			uint8_t rsvd5 : 1;
			uint8_t rsvd6 : 1;
			uint8_t rsvd7 : 1;
		}bits;
		uint8_t byte;
	}slStatus1_t;

typedef union
{
	struct
	{
		uint8_t B1H1_fault : 1;
		uint8_t B1L1_fault : 1;
		uint8_t B1H2_fault : 1;
		uint8_t B1L2_fault : 1;
		uint8_t B2H1_fault : 1;
		uint8_t B2L1_fault : 1;
		uint8_t B2H2_fault : 1;
		uint8_t B2L2_fault : 1;
	}bits;
	uint8_t byte;
}slfault5_t;

typedef struct
{
	float DCBUSVOLTAGE;
	float PSFB_INPUT_DC_CURRENT;
	float FEC_INPUT_AC_CURRENT;
	float PSFB_OUTPUT_DC_CURRENT;

	float PSFB_OUTPUT_DC_VOLTAGE;
	float AC_VOLTAGE_OPTIONAL;
	float AC_CURRENT_OPTIONAL;
	float TRAFO_TEMPERATURE;

	float FEC_TEMPERATURE;
	float PSFB_TEMPERATURE;
	float DIODE_TEMPERATURE;
	float Rsvd2;

	float PHASE_DELAY;
	float VDC_GAIN;
	float VDC_OFFSET;
	float Rsvd3;

	uint8_t Fault1;
	uint8_t Fault2;
	uint8_t Fault3;
	uint8_t Fault4;
	slfault5_t Fault5;
	uint8_t Fault6;
	uint8_t Fault7;
	uint8_t Fault8;

	slStatus1_t Status1;
	uint8_t Status2;
	uint8_t Status3;
	uint8_t Major_Firmware;

}CANReadParamters;


#ifdef CAN_PARAMETERS_H

	CANReadParamters Cell[40];

#else

	extern CANReadParamters Cell[40];

#endif
