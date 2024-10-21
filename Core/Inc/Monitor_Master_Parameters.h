/*
 * Monitor_Master_Parameters.h
 *
 *  Created on: Nov 29, 2023
 *      Author: ujwalpatel
 */

#ifndef INC_MONITOR_MASTER_PARAMETERS_H_
#define INC_MONITOR_MASTER_PARAMETERS_H_

#include "main.h"

typedef union
{
	struct
	{
		uint16_t converteron_off : 1; 	//bit 0
		uint16_t upstream_breaker : 1;	//bit 1
		uint16_t rsvd0 : 1;        		//bit 2
		uint16_t rsvd1 : 1;        		//bit 3
		uint16_t rsvd2 : 1;        		//bit 4
		uint16_t rsvd3 : 1;        		//bit 5
		uint16_t rsvd4 : 1;       		//bit 6
		uint16_t rsvd5 : 1;       		//bit 7
		uint16_t rsvd6 : 1;       		//bit 8
		uint16_t rsvd7 : 1;       		//bit 9
		uint16_t rsvd8 : 1;        		//bit 10
		uint16_t rsvd9 : 1;        		//bit 11
		uint16_t rsvd10: 1;        		//bit 12
		uint16_t rsvd11: 1;        		//bit 13
		uint16_t rsvd12: 1;       		//bit 14
		uint16_t rsvd13: 1;       		//bit 15
	}bits;
	uint16_t byte;
}control_para;

typedef union
{
	struct
		{
			uint16_t module_Enable  : 1;	//bit 0
			uint16_t rsvd0 			: 1;	//bit 1
			uint16_t rsvd1 			: 1;  	//bit 2
			uint16_t rsvd2 			: 1;  	//bit 3
			uint16_t rsvd3 			: 1;    //bit 4
			uint16_t rsvd4 			: 1;    //bit 5
			uint16_t rsvd5 			: 1;    //bit 6
			uint16_t rsvd6 			: 1;    //bit 7
			uint16_t rsvd7 			: 1;    //bit 8
			uint16_t rsvd8 			: 1;    //bit 9
			uint16_t rsvd9 			: 1;    //bit 10
			uint16_t rsvd10			: 1;    //bit 11
			uint16_t rsvd11			: 1;    //bit 12
			uint16_t rsvd12			: 1;    //bit 13
			uint16_t rsvd13			: 1;    //bit 14
			uint16_t rsvd14			: 1;    //bit 15
		}bits;
		uint16_t byte;
}module_enable;

typedef union
{
	struct
	{
		uint16_t DC_contactor : 1; 			//bit 0
		uint16_t LBS_command : 1;			//bit 1
		uint16_t main_breaker_command : 1;  //bit 2
		uint16_t space_heater_command : 1;  //bit 3
		uint16_t rsvd2 : 1;        			//bit 4
		uint16_t rsvd3 : 1;        			//bit 5
		uint16_t rsvd4 : 1;       			//bit 6
		uint16_t rsvd5 : 1;       			//bit 7
		uint16_t rsvd6 : 1;       			//bit 8
		uint16_t rsvd7 : 1;       			//bit 9
		uint16_t rsvd8 : 1;        			//bit 10
		uint16_t rsvd9 : 1;        			//bit 11
		uint16_t rsvd10: 1;        			//bit 12
		uint16_t rsvd11: 1;        			//bit 13
		uint16_t rsvd12: 1;       			//bit 14
		uint16_t rsvd13: 1;       			//bit 15
	}bits;
	uint16_t byte;
}commands;

typedef struct
{
	control_para control;
	float calibration_PT;
	float calibration_CT;
	float acGridOVL_limit;
	float acGridUVL_limit;
	float dcOutOVL_limit;
	float dcOutOCL_limit;
}HMI_Params;

typedef struct
{
	float totalOutPower_set;
	float OutVol_set;
	float OutCur_set;
}Output_Set;

typedef struct
{
	module_enable moduleEnable;
	uint16_t ratedPower;
	uint16_t ratedCurrent;
}Enable_and_rated_params;

typedef struct
{
    float trafo_temp_limit;
    float diode_temp_limit;
    float psfb_temp_limit;
    float afe_temp_limit;
    float Over_cur_limit;
    float Under_volt_limit;
    float Over_volt_limit;
}cell_limits;

#endif /* INC_MONITOR_MASTER_PARAMETERS_H_ */
