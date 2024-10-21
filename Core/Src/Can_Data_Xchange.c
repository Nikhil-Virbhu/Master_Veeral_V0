/*
 * Can_Data_Xchange.c
 *
 *  Created on: Aug 11, 2023
 *      Author: ujwalpatel
 */
#include "Can_Data_Xchange.h"
#include "process.h"
#include"debug.h"
#include"i2cEeprom.h"
#include "ntc_measurement.h"
#include "io.h"
#include "filter.h"
#include "pll.h"
#include "CAN1_Transmitting.h"
#include "CAN2_Transmitting.h"
#include "CAN3_Transmitting.h"
#include "CAN1_Receving.h"
#include "CAN2_Receving.h"
#include "CAN3_Receving.h"
#include "Monitor_Master_Parameters.h"
#include "Master_Monitor_Parameter.h"
#include "CAN_Parameters.h"
//#include "PID_Saturation.h"


#define RSVD 0
extern master_para master1, master2, master3, master4, master5, master6;
extern float Vd_cmd, Vq_cmd;

extern float Vd_cmd, Vq_cmd;
//extern PID_Structure IDref;

void MASTER_CAN_DATA_XCHANGE()
{

	//	API_CAN_IDC_IAC_GAIN_OFFSET(RSVD,RSVD,RSVD,RSVD);
	//
	//	API_CAN_OT_IDCPSFBGAIN_TRAFO_PSFB_FEC_OVER_TEMP(60, 0, 0, 0);
	//
	//	API_CAN_DC_OVER_CURRNT_VOLT_DC_UNDER_CURRENT_VOLT(5.5, 6.6, 7.7, 8.8);

//	API_CAN1_HEARTBEAT_MASTER01_CELL0139();

	//API_CAN2_HEARTBEAT_MASTER01_CELL0139();

	//	API_CAN2_MASTER_PC_DEBUG_1(10, 20, 30, 40);
	//
	//	API_CAN2_MASTER_PC_DEBUG_2(50, 60, 70, 80);
	//
	//	API_CAN2_MASTER_PC_DEBUG_3(90, 100, 110, 120);

	//API_CAN_TRAFO_FEC_GAIN_OFFSET(9.9, 10.1, 11.2, -12.5);

	//API_CAN_PSFB_GAIN_OFFSET(13.5, -14.5, 0, 0);Vd[2]

	//API_CAN_ID_IQ_VD_VQ(absValues.Id,  absValues.Iq,  absValues.Vd,  absValues.Vq);

	//API_CAN_VOUT_IOUT_VR_VY(absValues.Vout,  Vd_cmd,  Vq_cmd,  absValues.Vy);
	//API_CAN_VOUT_IOUT_VR_VY(absValues.Vout,  Vd_cmd,  Vrms[R_PHASE] ,  Vd[1]);

	//API_CAN_VB_IR_IY_VDCREF( absValues.Vb, absValues.Ir,  absValues.Iy,  IDref.Out[present]);
	//API_CAN_VB_IR_IY_VDCREF( Vq[1], absValues.Ir,  absValues.Iy,  IDref.Out[present]);

	//API_CAN_IB_VDCDIV(absValues.Ib, TempVdc_Bus_Divide,  VDref.Out[present],  VQref.Out[present]);//V_OUT[2]
	//API_CAN_IB_VDCDIV(absValues.Ib, V_OUT[1],  VoutRef.Dynamic,  VQref.Out[present]);

	//	API_CAN_IB_VDCDIV(absValues.Ib, TempVdc_Bus_Divide,  -50,  -61.5);
}


/*void MASTER_CANFD_3_DATA_XCHNAGE()
{
	//Master_To_Monitor_Frame1_Master();
	Master_To_Monitor_Frame1_Master(1000, 1001, 1003, 04, 05, 05, 06, 07, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 28, 27, 29, 30, 31);

	Master_To_Monitor_Frame2_Slave1(master1.cell[0].diode_temp, master1.cell[0].trafo_temp, master1.cell[0].fec_temp, master1.cell[0].psfb_temp, master1.cell[0].dc_bus_voltage, master1.cell[0].dc_bus_current, master1.cell[0].fec_input_current, master1.cell[0].psfb_output_voltage,master1.cell[0].psfb_output_current,
			master1.cell[0].sFault1_2.byte, master1.cell[0].sFault3_4.byte,master1.cell[0].sFault5_6.byte,master1.cell[0].sFault7_8.byte,master1.cell[0].sStatus1_2.byte,master1.cell[0].sStatus3_4.byte, master1.cell[0].rsvd0, master1.cell[0].rsvd1, master1.cell[0].rsvd2, master1.cell[0].rsvd3, master1.cell[0].rsvd4,
			master1.cell[0].rsvd5, master1.cell[0].rsvd6, master1.cell[0].rsvd7, master1.cell[0].rsvd8, master1.cell[0].rsvd9, master1.cell[0].rsvd10, master1.cell[0].rsvd11,master1.cell[0].rsvd12, master1.cell[0].rsvd13, master1.cell[0].rsvd14, master1.cell[0].rsvd15, master1.cell[0].rsvd16);

	Master_To_Monitor_Frame3_Slave2(master1.cell[1].diode_temp, master1.cell[1].trafo_temp, master1.cell[1].fec_temp, master1.cell[1].psfb_temp, master1.cell[1].dc_bus_voltage, master1.cell[1].dc_bus_current, master1.cell[1].fec_input_current, master1.cell[1].psfb_output_voltage,master1.cell[1].psfb_output_current,
			master1.cell[1].sFault1_2.byte, master1.cell[1].sFault3_4.byte,master1.cell[1].sFault5_6.byte,master1.cell[1].sFault7_8.byte,master1.cell[1].sStatus1_2.byte,master1.cell[1].sStatus3_4.byte, master1.cell[1].rsvd0, master1.cell[1].rsvd1, master1.cell[1].rsvd2, master1.cell[1].rsvd3, master1.cell[1].rsvd4,
			master1.cell[1].rsvd5, master1.cell[1].rsvd6, master1.cell[1].rsvd7, master1.cell[1].rsvd8, master1.cell[1].rsvd9, master1.cell[1].rsvd10, master1.cell[1].rsvd11,master1.cell[1].rsvd12, master1.cell[1].rsvd13, master1.cell[1].rsvd14, master1.cell[1].rsvd15, master1.cell[1].rsvd16);

	Master_To_Monitor_Frame4_Slave3(master1.cell[2].diode_temp, master1.cell[2].trafo_temp, master1.cell[2].fec_temp, master1.cell[2].psfb_temp, master1.cell[2].dc_bus_voltage, master1.cell[2].dc_bus_current, master1.cell[2].fec_input_current, master1.cell[2].psfb_output_voltage,master1.cell[2].psfb_output_current,
			master1.cell[2].sFault1_2.byte, master1.cell[2].sFault3_4.byte,master1.cell[2].sFault5_6.byte,master1.cell[2].sFault7_8.byte,master1.cell[2].sStatus1_2.byte,master1.cell[2].sStatus3_4.byte, master1.cell[2].rsvd0, master1.cell[2].rsvd1, master1.cell[2].rsvd2, master1.cell[2].rsvd3, master1.cell[2].rsvd4,
			master1.cell[2].rsvd5, master1.cell[2].rsvd6, master1.cell[2].rsvd7, master1.cell[2].rsvd8, master1.cell[2].rsvd9, master1.cell[2].rsvd10, master1.cell[2].rsvd11,master1.cell[2].rsvd12, master1.cell[2].rsvd13, master1.cell[2].rsvd14, master1.cell[2].rsvd15, master1.cell[2].rsvd16);

	Master_To_Monitor_Frame5_Slave4(master1.cell[3].diode_temp, master1.cell[3].trafo_temp, master1.cell[3].fec_temp, master1.cell[3].psfb_temp, master1.cell[3].dc_bus_voltage, master1.cell[3].dc_bus_current, master1.cell[3].fec_input_current, master1.cell[3].psfb_output_voltage,master1.cell[3].psfb_output_current,
			master1.cell[3].sFault1_2.byte, master1.cell[3].sFault3_4.byte,master1.cell[3].sFault5_6.byte,master1.cell[3].sFault7_8.byte,master1.cell[3].sStatus1_2.byte,master1.cell[3].sStatus3_4.byte, master1.cell[3].rsvd0, master1.cell[3].rsvd1, master1.cell[3].rsvd2, master1.cell[3].rsvd3, master1.cell[3].rsvd4,
			master1.cell[3].rsvd5, master1.cell[3].rsvd6, master1.cell[3].rsvd7, master1.cell[3].rsvd8, master1.cell[3].rsvd9, master1.cell[3].rsvd10, master1.cell[3].rsvd11,master1.cell[3].rsvd12, master1.cell[3].rsvd13, master1.cell[3].rsvd14, master1.cell[3].rsvd15, master1.cell[3].rsvd16);

	Master_To_Monitor_Frame6_Slave5(master1.cell[4].diode_temp, master1.cell[4].trafo_temp, master1.cell[4].fec_temp, master1.cell[4].psfb_temp, master1.cell[4].dc_bus_voltage, master1.cell[4].dc_bus_current, master1.cell[4].fec_input_current, master1.cell[4].psfb_output_voltage,master1.cell[4].psfb_output_current,
			master1.cell[4].sFault1_2.byte, master1.cell[4].sFault3_4.byte,master1.cell[4].sFault5_6.byte,master1.cell[4].sFault7_8.byte,master1.cell[4].sStatus1_2.byte,master1.cell[4].sStatus3_4.byte, master1.cell[4].rsvd0, master1.cell[4].rsvd1, master1.cell[4].rsvd2, master1.cell[4].rsvd3, master1.cell[4].rsvd4,
			master1.cell[4].rsvd5, master1.cell[4].rsvd6, master1.cell[4].rsvd7, master1.cell[4].rsvd8, master1.cell[4].rsvd9, master1.cell[4].rsvd10, master1.cell[4].rsvd11,master1.cell[4].rsvd12, master1.cell[4].rsvd13, master1.cell[4].rsvd14, master1.cell[4].rsvd15, master1.cell[4].rsvd16);

	Master_To_Monitor_Frame7_Slave6(master1.cell[5].diode_temp, master1.cell[5].trafo_temp, master1.cell[5].fec_temp, master1.cell[5].psfb_temp, master1.cell[5].dc_bus_voltage, master1.cell[5].dc_bus_current, master1.cell[5].fec_input_current, master1.cell[5].psfb_output_voltage,master1.cell[5].psfb_output_current,
			master1.cell[5].sFault1_2.byte, master1.cell[5].sFault3_4.byte,master1.cell[5].sFault5_6.byte,master1.cell[5].sFault7_8.byte,master1.cell[5].sStatus1_2.byte,master1.cell[5].sStatus3_4.byte, master1.cell[5].rsvd0, master1.cell[5].rsvd1, master1.cell[5].rsvd2, master1.cell[5].rsvd3, master1.cell[5].rsvd4,
			master1.cell[5].rsvd5, master1.cell[5].rsvd6, master1.cell[5].rsvd7, master1.cell[5].rsvd8, master1.cell[5].rsvd9, master1.cell[5].rsvd10, master1.cell[5].rsvd11,master1.cell[5].rsvd12, master1.cell[5].rsvd13, master1.cell[5].rsvd14, master1.cell[5].rsvd15, master1.cell[5].rsvd16);

	Master_To_Monitor_Frame8_Slave7(master1.cell[6].diode_temp, master1.cell[6].trafo_temp, master1.cell[6].fec_temp, master1.cell[6].psfb_temp, master1.cell[6].dc_bus_voltage, master1.cell[6].dc_bus_current, master1.cell[6].fec_input_current, master1.cell[6].psfb_output_voltage,master1.cell[6].psfb_output_current,
			master1.cell[6].sFault1_2.byte, master1.cell[6].sFault3_4.byte,master1.cell[6].sFault5_6.byte,master1.cell[6].sFault7_8.byte,master1.cell[6].sStatus1_2.byte,master1.cell[6].sStatus3_4.byte, master1.cell[6].rsvd0, master1.cell[6].rsvd1, master1.cell[6].rsvd2, master1.cell[6].rsvd3, master1.cell[6].rsvd4,
			master1.cell[6].rsvd5, master1.cell[6].rsvd6, master1.cell[6].rsvd7, master1.cell[6].rsvd8, master1.cell[6].rsvd9, master1.cell[6].rsvd10, master1.cell[6].rsvd11,master1.cell[6].rsvd12, master1.cell[6].rsvd13, master1.cell[6].rsvd14, master1.cell[6].rsvd15, master1.cell[6].rsvd16);

	Master_To_Monitor_Frame9_Slave8(master1.cell[7].diode_temp, master1.cell[7].trafo_temp, master1.cell[7].fec_temp, master1.cell[7].psfb_temp, master1.cell[7].dc_bus_voltage, master1.cell[7].dc_bus_current, master1.cell[7].fec_input_current, master1.cell[7].psfb_output_voltage,master1.cell[7].psfb_output_current,
			master1.cell[7].sFault1_2.byte, master1.cell[7].sFault3_4.byte,master1.cell[7].sFault5_6.byte,master1.cell[7].sFault7_8.byte,master1.cell[7].sStatus1_2.byte,master1.cell[7].sStatus3_4.byte, master1.cell[7].rsvd0, master1.cell[7].rsvd1, master1.cell[7].rsvd2, master1.cell[7].rsvd3, master1.cell[7].rsvd4,
			master1.cell[7].rsvd5, master1.cell[7].rsvd6, master1.cell[7].rsvd7, master1.cell[7].rsvd8, master1.cell[7].rsvd9, master1.cell[7].rsvd10, master1.cell[7].rsvd11,master1.cell[7].rsvd12, master1.cell[7].rsvd13, master1.cell[7].rsvd14, master1.cell[7].rsvd15, master1.cell[7].rsvd16);

	Master_To_Monitor_Frame10_Slave9(master1.cell[8].diode_temp, master1.cell[8].trafo_temp, master1.cell[8].fec_temp, master1.cell[8].psfb_temp, master1.cell[8].dc_bus_voltage, master1.cell[8].dc_bus_current, master1.cell[8].fec_input_current, master1.cell[8].psfb_output_voltage,master1.cell[8].psfb_output_current,
			master1.cell[8].sFault1_2.byte, master1.cell[8].sFault3_4.byte,master1.cell[8].sFault5_6.byte,master1.cell[8].sFault7_8.byte,master1.cell[8].sStatus1_2.byte,master1.cell[8].sStatus3_4.byte, master1.cell[8].rsvd0, master1.cell[8].rsvd1, master1.cell[8].rsvd2, master1.cell[8].rsvd3, master1.cell[8].rsvd4,
			master1.cell[8].rsvd5, master1.cell[8].rsvd6, master1.cell[8].rsvd7, master1.cell[8].rsvd8, master1.cell[8].rsvd9, master1.cell[8].rsvd10, master1.cell[8].rsvd11,master1.cell[8].rsvd12, master1.cell[8].rsvd13, master1.cell[8].rsvd14, master1.cell[8].rsvd15, master1.cell[8].rsvd16);

	Master_To_Monitor_Frame11_Slave10(master1.cell[9].diode_temp, master1.cell[9].trafo_temp, master1.cell[9].fec_temp, master1.cell[9].psfb_temp, master1.cell[9].dc_bus_voltage, master1.cell[9].dc_bus_current, master1.cell[9].fec_input_current, master1.cell[9].psfb_output_voltage,master1.cell[9].psfb_output_current,
			master1.cell[9].sFault1_2.byte, master1.cell[9].sFault3_4.byte,master1.cell[9].sFault5_6.byte,master1.cell[9].sFault7_8.byte,master1.cell[9].sStatus1_2.byte,master1.cell[9].sStatus3_4.byte, master1.cell[9].rsvd0, master1.cell[9].rsvd1, master1.cell[9].rsvd2, master1.cell[9].rsvd3, master1.cell[9].rsvd4,
			master1.cell[9].rsvd5, master1.cell[9].rsvd6, master1.cell[9].rsvd7, master1.cell[9].rsvd8, master1.cell[9].rsvd9, master1.cell[9].rsvd10, master1.cell[9].rsvd11,master1.cell[9].rsvd12, master1.cell[9].rsvd13, master1.cell[9].rsvd14, master1.cell[9].rsvd15, master1.cell[9].rsvd16);

	Master_To_Monitor_Frame12_Slave11(master1.cell[10].diode_temp, master1.cell[10].trafo_temp, master1.cell[10].fec_temp, master1.cell[10].psfb_temp, master1.cell[10].dc_bus_voltage, master1.cell[10].dc_bus_current, master1.cell[10].fec_input_current, master1.cell[10].psfb_output_voltage,master1.cell[10].psfb_output_current,
			master1.cell[10].sFault1_2.byte, master1.cell[10].sFault3_4.byte,master1.cell[10].sFault5_6.byte,master1.cell[10].sFault7_8.byte,master1.cell[10].sStatus1_2.byte,master1.cell[10].sStatus3_4.byte, master1.cell[10].rsvd0, master1.cell[10].rsvd1, master1.cell[10].rsvd2, master1.cell[10].rsvd3, master1.cell[10].rsvd4,
			master1.cell[10].rsvd5, master1.cell[10].rsvd6, master1.cell[10].rsvd7, master1.cell[10].rsvd8, master1.cell[10].rsvd9, master1.cell[10].rsvd10, master1.cell[10].rsvd11,master1.cell[10].rsvd12, master1.cell[10].rsvd13, master1.cell[10].rsvd14, master1.cell[10].rsvd15, master1.cell[10].rsvd16);

	Master_To_Monitor_Frame13_Slave12(master1.cell[11].diode_temp, master1.cell[11].trafo_temp, master1.cell[11].fec_temp, master1.cell[11].psfb_temp, master1.cell[11].dc_bus_voltage, master1.cell[11].dc_bus_current, master1.cell[11].fec_input_current, master1.cell[11].psfb_output_voltage,master1.cell[11].psfb_output_current,
			master1.cell[11].sFault1_2.byte, master1.cell[11].sFault3_4.byte,master1.cell[11].sFault5_6.byte,master1.cell[11].sFault7_8.byte,master1.cell[11].sStatus1_2.byte,master1.cell[11].sStatus3_4.byte, master1.cell[11].rsvd0, master1.cell[11].rsvd1, master1.cell[11].rsvd2, master1.cell[11].rsvd3, master1.cell[11].rsvd4,
			master1.cell[11].rsvd5, master1.cell[11].rsvd6, master1.cell[11].rsvd7, master1.cell[11].rsvd8, master1.cell[11].rsvd9, master1.cell[11].rsvd10, master1.cell[11].rsvd11,master1.cell[11].rsvd12, master1.cell[11].rsvd13, master1.cell[11].rsvd14, master1.cell[11].rsvd15, master1.cell[11].rsvd16);

	Master_To_Monitor_Frame14_Slave13(master1.cell[12].diode_temp, master1.cell[12].trafo_temp, master1.cell[12].fec_temp, master1.cell[12].psfb_temp, master1.cell[12].dc_bus_voltage, master1.cell[12].dc_bus_current, master1.cell[12].fec_input_current, master1.cell[12].psfb_output_voltage,master1.cell[12].psfb_output_current,
			master1.cell[12].sFault1_2.byte, master1.cell[12].sFault3_4.byte,master1.cell[12].sFault5_6.byte,master1.cell[12].sFault7_8.byte,master1.cell[12].sStatus1_2.byte,master1.cell[12].sStatus3_4.byte, master1.cell[12].rsvd0, master1.cell[12].rsvd1, master1.cell[12].rsvd2, master1.cell[12].rsvd3, master1.cell[12].rsvd4,
			master1.cell[12].rsvd5, master1.cell[12].rsvd6, master1.cell[12].rsvd7, master1.cell[12].rsvd8, master1.cell[12].rsvd9, master1.cell[12].rsvd10, master1.cell[12].rsvd11,master1.cell[12].rsvd12, master1.cell[12].rsvd13, master1.cell[12].rsvd14, master1.cell[12].rsvd15, master1.cell[12].rsvd16);

	Master_To_Monitor_Frame15_Slave14(master1.cell[13].diode_temp, master1.cell[13].trafo_temp, master1.cell[13].fec_temp, master1.cell[13].psfb_temp, master1.cell[13].dc_bus_voltage, master1.cell[13].dc_bus_current, master1.cell[13].fec_input_current, master1.cell[13].psfb_output_voltage,master1.cell[13].psfb_output_current,
			master1.cell[13].sFault1_2.byte, master1.cell[13].sFault3_4.byte,master1.cell[13].sFault5_6.byte,master1.cell[13].sFault7_8.byte,master1.cell[13].sStatus1_2.byte,master1.cell[13].sStatus3_4.byte, master1.cell[13].rsvd0, master1.cell[13].rsvd1, master1.cell[13].rsvd2, master1.cell[13].rsvd3, master1.cell[13].rsvd4,
			master1.cell[13].rsvd5, master1.cell[13].rsvd6, master1.cell[13].rsvd7, master1.cell[13].rsvd8, master1.cell[13].rsvd9, master1.cell[13].rsvd10, master1.cell[13].rsvd11,master1.cell[13].rsvd12, master1.cell[13].rsvd13, master1.cell[13].rsvd14, master1.cell[13].rsvd15, master1.cell[13].rsvd16);

	Master_To_Monitor_Frame16_Slave15(master1.cell[14].diode_temp, master1.cell[14].trafo_temp, master1.cell[14].fec_temp, master1.cell[14].psfb_temp, master1.cell[14].dc_bus_voltage, master1.cell[14].dc_bus_current, master1.cell[14].fec_input_current, master1.cell[14].psfb_output_voltage,master1.cell[14].psfb_output_current,
			master1.cell[14].sFault1_2.byte, master1.cell[14].sFault3_4.byte,master1.cell[14].sFault5_6.byte,master1.cell[14].sFault7_8.byte,master1.cell[14].sStatus1_2.byte,master1.cell[14].sStatus3_4.byte, master1.cell[14].rsvd0, master1.cell[14].rsvd1, master1.cell[14].rsvd2, master1.cell[14].rsvd3, master1.cell[14].rsvd4,
			master1.cell[14].rsvd5, master1.cell[14].rsvd6, master1.cell[14].rsvd7, master1.cell[14].rsvd8, master1.cell[14].rsvd9, master1.cell[14].rsvd10, master1.cell[14].rsvd11,master1.cell[14].rsvd12, master1.cell[14].rsvd13, master1.cell[14].rsvd14, master1.cell[14].rsvd15, master1.cell[14].rsvd16);

	Master_To_Monitor_Frame17_Slave16(master1.cell[15].diode_temp, master1.cell[15].trafo_temp, master1.cell[15].fec_temp, master1.cell[15].psfb_temp, master1.cell[15].dc_bus_voltage, master1.cell[15].dc_bus_current, master1.cell[15].fec_input_current, master1.cell[15].psfb_output_voltage,master1.cell[15].psfb_output_current,
			master1.cell[15].sFault1_2.byte, master1.cell[15].sFault3_4.byte,master1.cell[15].sFault5_6.byte,master1.cell[15].sFault7_8.byte,master1.cell[15].sStatus1_2.byte,master1.cell[15].sStatus3_4.byte, master1.cell[15].rsvd0, master1.cell[15].rsvd1, master1.cell[15].rsvd2, master1.cell[15].rsvd3, master1.cell[15].rsvd4,
			master1.cell[15].rsvd5, master1.cell[15].rsvd6, master1.cell[15].rsvd7, master1.cell[15].rsvd8, master1.cell[15].rsvd9, master1.cell[15].rsvd10, master1.cell[15].rsvd11,master1.cell[15].rsvd12, master1.cell[15].rsvd13, master1.cell[15].rsvd14, master1.cell[15].rsvd15, master1.cell[15].rsvd16);

	Master_To_Monitor_Frame18_Slave17(master1.cell[16].diode_temp, master1.cell[16].trafo_temp, master1.cell[16].fec_temp, master1.cell[16].psfb_temp, master1.cell[16].dc_bus_voltage, master1.cell[16].dc_bus_current, master1.cell[16].fec_input_current, master1.cell[16].psfb_output_voltage,master1.cell[16].psfb_output_current,
			master1.cell[16].sFault1_2.byte, master1.cell[16].sFault3_4.byte,master1.cell[16].sFault5_6.byte,master1.cell[16].sFault7_8.byte,master1.cell[16].sStatus1_2.byte,master1.cell[16].sStatus3_4.byte, master1.cell[16].rsvd0, master1.cell[16].rsvd1, master1.cell[16].rsvd2, master1.cell[16].rsvd3, master1.cell[16].rsvd4,
			master1.cell[16].rsvd5, master1.cell[16].rsvd6, master1.cell[16].rsvd7, master1.cell[16].rsvd8, master1.cell[16].rsvd9, master1.cell[16].rsvd10, master1.cell[16].rsvd11,master1.cell[16].rsvd12, master1.cell[16].rsvd13, master1.cell[16].rsvd14, master1.cell[16].rsvd15, master1.cell[16].rsvd16);

	Master_To_Monitor_Frame19_Slave18(master1.cell[17].diode_temp, master1.cell[17].trafo_temp, master1.cell[17].fec_temp, master1.cell[17].psfb_temp, master1.cell[17].dc_bus_voltage, master1.cell[17].dc_bus_current, master1.cell[17].fec_input_current, master1.cell[17].psfb_output_voltage,master1.cell[17].psfb_output_current,
			master1.cell[17].sFault1_2.byte, master1.cell[17].sFault3_4.byte,master1.cell[17].sFault5_6.byte,master1.cell[17].sFault7_8.byte,master1.cell[17].sStatus1_2.byte,master1.cell[17].sStatus3_4.byte, master1.cell[17].rsvd0, master1.cell[17].rsvd1, master1.cell[17].rsvd2, master1.cell[17].rsvd3, master1.cell[17].rsvd4,
			master1.cell[17].rsvd5, master1.cell[17].rsvd6, master1.cell[17].rsvd7, master1.cell[17].rsvd8, master1.cell[17].rsvd9, master1.cell[17].rsvd10, master1.cell[17].rsvd11,master1.cell[17].rsvd12, master1.cell[17].rsvd13, master1.cell[17].rsvd14, master1.cell[17].rsvd15, master1.cell[17].rsvd16);

	Master_To_Monitor_Frame20_Slave19(master1.cell[18].diode_temp, master1.cell[18].trafo_temp, master1.cell[18].fec_temp, master1.cell[18].psfb_temp, master1.cell[18].dc_bus_voltage, master1.cell[18].dc_bus_current, master1.cell[18].fec_input_current, master1.cell[18].psfb_output_voltage,master1.cell[18].psfb_output_current,
			master1.cell[18].sFault1_2.byte, master1.cell[18].sFault3_4.byte,master1.cell[18].sFault5_6.byte,master1.cell[18].sFault7_8.byte,master1.cell[18].sStatus1_2.byte,master1.cell[18].sStatus3_4.byte, master1.cell[18].rsvd0, master1.cell[18].rsvd1, master1.cell[18].rsvd2, master1.cell[18].rsvd3, master1.cell[18].rsvd4,
			master1.cell[18].rsvd5, master1.cell[18].rsvd6, master1.cell[18].rsvd7, master1.cell[18].rsvd8, master1.cell[18].rsvd9, master1.cell[18].rsvd10, master1.cell[18].rsvd11,master1.cell[18].rsvd12, master1.cell[18].rsvd13, master1.cell[18].rsvd14, master1.cell[18].rsvd15, master1.cell[18].rsvd16);

	Master_To_Monitor_Frame21_Slave20(master1.cell[19].diode_temp, master1.cell[19].trafo_temp, master1.cell[19].fec_temp, master1.cell[19].psfb_temp, master1.cell[19].dc_bus_voltage, master1.cell[19].dc_bus_current, master1.cell[19].fec_input_current, master1.cell[19].psfb_output_voltage,master1.cell[19].psfb_output_current,
			master1.cell[19].sFault1_2.byte, master1.cell[19].sFault3_4.byte,master1.cell[19].sFault5_6.byte,master1.cell[19].sFault7_8.byte,master1.cell[19].sStatus1_2.byte,master1.cell[19].sStatus3_4.byte, master1.cell[19].rsvd0, master1.cell[19].rsvd1, master1.cell[19].rsvd2, master1.cell[19].rsvd3, master1.cell[19].rsvd4,
			master1.cell[19].rsvd5, master1.cell[19].rsvd6, master1.cell[19].rsvd7, master1.cell[19].rsvd8, master1.cell[19].rsvd9, master1.cell[19].rsvd10, master1.cell[19].rsvd11,master1.cell[19].rsvd12, master1.cell[19].rsvd13, master1.cell[19].rsvd14, master1.cell[19].rsvd15, master1.cell[19].rsvd16);

	Master_To_Monitor_Frame22_Slave21(master1.cell[20].diode_temp, master1.cell[20].trafo_temp, master1.cell[20].fec_temp, master1.cell[20].psfb_temp, master1.cell[20].dc_bus_voltage, master1.cell[20].dc_bus_current, master1.cell[20].fec_input_current, master1.cell[20].psfb_output_voltage,master1.cell[20].psfb_output_current,
			master1.cell[20].sFault1_2.byte, master1.cell[20].sFault3_4.byte,master1.cell[20].sFault5_6.byte,master1.cell[20].sFault7_8.byte,master1.cell[20].sStatus1_2.byte,master1.cell[20].sStatus3_4.byte, master1.cell[20].rsvd0, master1.cell[20].rsvd1, master1.cell[20].rsvd2, master1.cell[20].rsvd3, master1.cell[20].rsvd4,
			master1.cell[20].rsvd5, master1.cell[20].rsvd6, master1.cell[20].rsvd7, master1.cell[20].rsvd8, master1.cell[20].rsvd9, master1.cell[20].rsvd10, master1.cell[20].rsvd11,master1.cell[20].rsvd12, master1.cell[20].rsvd13, master1.cell[20].rsvd14, master1.cell[20].rsvd15, master1.cell[20].rsvd16);

	Master_To_Monitor_Frame23_Slave22(master1.cell[21].diode_temp, master1.cell[21].trafo_temp, master1.cell[21].fec_temp, master1.cell[21].psfb_temp, master1.cell[21].dc_bus_voltage, master1.cell[21].dc_bus_current, master1.cell[21].fec_input_current, master1.cell[21].psfb_output_voltage,master1.cell[21].psfb_output_current,
			master1.cell[21].sFault1_2.byte, master1.cell[21].sFault3_4.byte,master1.cell[21].sFault5_6.byte,master1.cell[21].sFault7_8.byte,master1.cell[21].sStatus1_2.byte,master1.cell[21].sStatus3_4.byte, master1.cell[21].rsvd0, master1.cell[21].rsvd1, master1.cell[21].rsvd2, master1.cell[21].rsvd3, master1.cell[21].rsvd4,
			master1.cell[21].rsvd5, master1.cell[21].rsvd6, master1.cell[21].rsvd7, master1.cell[21].rsvd8, master1.cell[21].rsvd9, master1.cell[21].rsvd10, master1.cell[21].rsvd11,master1.cell[21].rsvd12, master1.cell[21].rsvd13, master1.cell[21].rsvd14, master1.cell[21].rsvd15, master1.cell[21].rsvd16);

	Master_To_Monitor_Frame24_Slave23(master1.cell[22].diode_temp, master1.cell[22].trafo_temp, master1.cell[22].fec_temp, master1.cell[22].psfb_temp, master1.cell[22].dc_bus_voltage, master1.cell[22].dc_bus_current, master1.cell[22].fec_input_current, master1.cell[22].psfb_output_voltage,master1.cell[22].psfb_output_current,
			master1.cell[22].sFault1_2.byte, master1.cell[22].sFault3_4.byte,master1.cell[22].sFault5_6.byte,master1.cell[22].sFault7_8.byte,master1.cell[22].sStatus1_2.byte,master1.cell[22].sStatus3_4.byte, master1.cell[22].rsvd0, master1.cell[22].rsvd1, master1.cell[22].rsvd2, master1.cell[22].rsvd3, master1.cell[22].rsvd4,
			master1.cell[22].rsvd5, master1.cell[22].rsvd6, master1.cell[22].rsvd7, master1.cell[22].rsvd8, master1.cell[22].rsvd9, master1.cell[22].rsvd10, master1.cell[22].rsvd11,master1.cell[22].rsvd12, master1.cell[22].rsvd13, master1.cell[22].rsvd14, master1.cell[22].rsvd15, master1.cell[22].rsvd16);

	Master_To_Monitor_Frame25_Slave24(master1.cell[23].diode_temp, master1.cell[23].trafo_temp, master1.cell[23].fec_temp, master1.cell[23].psfb_temp, master1.cell[23].dc_bus_voltage, master1.cell[23].dc_bus_current, master1.cell[23].fec_input_current, master1.cell[23].psfb_output_voltage,master1.cell[23].psfb_output_current,
			master1.cell[23].sFault1_2.byte, master1.cell[23].sFault3_4.byte,master1.cell[23].sFault5_6.byte,master1.cell[23].sFault7_8.byte,master1.cell[23].sStatus1_2.byte,master1.cell[23].sStatus3_4.byte, master1.cell[23].rsvd0, master1.cell[23].rsvd1, master1.cell[23].rsvd2, master1.cell[23].rsvd3, master1.cell[23].rsvd4,
			master1.cell[23].rsvd5, master1.cell[23].rsvd6, master1.cell[23].rsvd7, master1.cell[23].rsvd8, master1.cell[23].rsvd9, master1.cell[23].rsvd10, master1.cell[23].rsvd11,master1.cell[23].rsvd12, master1.cell[23].rsvd13, master1.cell[23].rsvd14, master1.cell[23].rsvd15, master1.cell[23].rsvd16);

	Master_To_Monitor_Frame26_Slave25(master1.cell[24].diode_temp, master1.cell[24].trafo_temp, master1.cell[24].fec_temp, master1.cell[24].psfb_temp, master1.cell[24].dc_bus_voltage, master1.cell[24].dc_bus_current, master1.cell[24].fec_input_current, master1.cell[24].psfb_output_voltage,master1.cell[24].psfb_output_current,
			master1.cell[24].sFault1_2.byte, master1.cell[24].sFault3_4.byte,master1.cell[24].sFault5_6.byte,master1.cell[24].sFault7_8.byte,master1.cell[24].sStatus1_2.byte,master1.cell[24].sStatus3_4.byte, master1.cell[24].rsvd0, master1.cell[24].rsvd1, master1.cell[24].rsvd2, master1.cell[24].rsvd3, master1.cell[24].rsvd4,
			master1.cell[24].rsvd5, master1.cell[24].rsvd6, master1.cell[24].rsvd7, master1.cell[24].rsvd8, master1.cell[24].rsvd9, master1.cell[24].rsvd10, master1.cell[24].rsvd11,master1.cell[24].rsvd12, master1.cell[24].rsvd13, master1.cell[24].rsvd14, master1.cell[24].rsvd15, master1.cell[24].rsvd16);

	Master_To_Monitor_Frame27_Slave26(master1.cell[25].diode_temp, master1.cell[25].trafo_temp, master1.cell[25].fec_temp, master1.cell[25].psfb_temp, master1.cell[25].dc_bus_voltage, master1.cell[25].dc_bus_current, master1.cell[25].fec_input_current, master1.cell[25].psfb_output_voltage,master1.cell[25].psfb_output_current,
			master1.cell[25].sFault1_2.byte, master1.cell[25].sFault3_4.byte,master1.cell[25].sFault5_6.byte,master1.cell[25].sFault7_8.byte,master1.cell[25].sStatus1_2.byte,master1.cell[25].sStatus3_4.byte, master1.cell[25].rsvd0, master1.cell[25].rsvd1, master1.cell[25].rsvd2, master1.cell[25].rsvd3, master1.cell[25].rsvd4,
			master1.cell[25].rsvd5, master1.cell[25].rsvd6, master1.cell[25].rsvd7, master1.cell[25].rsvd8, master1.cell[25].rsvd9, master1.cell[25].rsvd10, master1.cell[25].rsvd11,master1.cell[25].rsvd12, master1.cell[25].rsvd13, master1.cell[25].rsvd14, master1.cell[25].rsvd15, master1.cell[25].rsvd16);

	Master_To_Monitor_Frame28_Slave27(master1.cell[26].diode_temp, master1.cell[26].trafo_temp, master1.cell[26].fec_temp, master1.cell[26].psfb_temp, master1.cell[26].dc_bus_voltage, master1.cell[26].dc_bus_current, master1.cell[26].fec_input_current, master1.cell[26].psfb_output_voltage,master1.cell[26].psfb_output_current,
			master1.cell[26].sFault1_2.byte, master1.cell[26].sFault3_4.byte,master1.cell[26].sFault5_6.byte,master1.cell[26].sFault7_8.byte,master1.cell[26].sStatus1_2.byte,master1.cell[26].sStatus3_4.byte, master1.cell[26].rsvd0, master1.cell[26].rsvd1, master1.cell[26].rsvd2, master1.cell[26].rsvd3, master1.cell[26].rsvd4,
			master1.cell[26].rsvd5, master1.cell[26].rsvd6, master1.cell[26].rsvd7, master1.cell[26].rsvd8, master1.cell[26].rsvd9, master1.cell[26].rsvd10, master1.cell[26].rsvd11,master1.cell[26].rsvd12, master1.cell[26].rsvd13, master1.cell[26].rsvd14, master1.cell[26].rsvd15, master1.cell[26].rsvd16);

	Master_To_Monitor_Frame29_Slave28(master1.cell[27].diode_temp, master1.cell[27].trafo_temp, master1.cell[27].fec_temp, master1.cell[27].psfb_temp, master1.cell[27].dc_bus_voltage, master1.cell[27].dc_bus_current, master1.cell[27].fec_input_current, master1.cell[27].psfb_output_voltage,master1.cell[27].psfb_output_current,
			master1.cell[27].sFault1_2.byte, master1.cell[27].sFault3_4.byte,master1.cell[27].sFault5_6.byte,master1.cell[27].sFault7_8.byte,master1.cell[27].sStatus1_2.byte,master1.cell[27].sStatus3_4.byte, master1.cell[27].rsvd0, master1.cell[27].rsvd1, master1.cell[27].rsvd2, master1.cell[27].rsvd3, master1.cell[27].rsvd4,
			master1.cell[27].rsvd5, master1.cell[27].rsvd6, master1.cell[27].rsvd7, master1.cell[27].rsvd8, master1.cell[27].rsvd9, master1.cell[27].rsvd10, master1.cell[27].rsvd11,master1.cell[27].rsvd12, master1.cell[27].rsvd13, master1.cell[27].rsvd14, master1.cell[27].rsvd15, master1.cell[27].rsvd16);

	Master_To_Monitor_Frame30_Slave29(master1.cell[28].diode_temp, master1.cell[28].trafo_temp, master1.cell[28].fec_temp, master1.cell[28].psfb_temp, master1.cell[28].dc_bus_voltage, master1.cell[28].dc_bus_current, master1.cell[28].fec_input_current, master1.cell[28].psfb_output_voltage,master1.cell[28].psfb_output_current,
			master1.cell[28].sFault1_2.byte, master1.cell[28].sFault3_4.byte,master1.cell[28].sFault5_6.byte,master1.cell[28].sFault7_8.byte,master1.cell[28].sStatus1_2.byte,master1.cell[28].sStatus3_4.byte, master1.cell[28].rsvd0, master1.cell[28].rsvd1, master1.cell[28].rsvd2, master1.cell[28].rsvd3, master1.cell[28].rsvd4,
			master1.cell[28].rsvd5, master1.cell[28].rsvd6, master1.cell[28].rsvd7, master1.cell[28].rsvd8, master1.cell[28].rsvd9, master1.cell[28].rsvd10, master1.cell[28].rsvd11,master1.cell[28].rsvd12, master1.cell[28].rsvd13, master1.cell[28].rsvd14, master1.cell[28].rsvd15, master1.cell[28].rsvd16);

	Master_To_Monitor_Frame31_Slave30(master1.cell[29].diode_temp, master1.cell[29].trafo_temp, master1.cell[29].fec_temp, master1.cell[29].psfb_temp, master1.cell[29].dc_bus_voltage, master1.cell[29].dc_bus_current, master1.cell[29].fec_input_current, master1.cell[29].psfb_output_voltage,master1.cell[29].psfb_output_current,
			master1.cell[29].sFault1_2.byte, master1.cell[29].sFault3_4.byte,master1.cell[29].sFault5_6.byte,master1.cell[29].sFault7_8.byte,master1.cell[29].sStatus1_2.byte,master1.cell[29].sStatus3_4.byte, master1.cell[29].rsvd0, master1.cell[29].rsvd1, master1.cell[29].rsvd2, master1.cell[29].rsvd3, master1.cell[29].rsvd4,
			master1.cell[29].rsvd5, master1.cell[29].rsvd6, master1.cell[29].rsvd7, master1.cell[29].rsvd8, master1.cell[29].rsvd9, master1.cell[29].rsvd10, master1.cell[29].rsvd11,master1.cell[29].rsvd12, master1.cell[29].rsvd13, master1.cell[29].rsvd14, master1.cell[29].rsvd15, master1.cell[29].rsvd16);

	Master_To_Monitor_Frame32_Slave31(master1.cell[30].diode_temp, master1.cell[30].trafo_temp, master1.cell[30].fec_temp, master1.cell[30].psfb_temp, master1.cell[30].dc_bus_voltage, master1.cell[30].dc_bus_current, master1.cell[30].fec_input_current, master1.cell[30].psfb_output_voltage,master1.cell[30].psfb_output_current,
			master1.cell[30].sFault1_2.byte, master1.cell[30].sFault3_4.byte,master1.cell[30].sFault5_6.byte,master1.cell[30].sFault7_8.byte,master1.cell[30].sStatus1_2.byte,master1.cell[30].sStatus3_4.byte, master1.cell[30].rsvd0, master1.cell[30].rsvd1, master1.cell[30].rsvd2, master1.cell[30].rsvd3, master1.cell[30].rsvd4,
			master1.cell[30].rsvd5, master1.cell[30].rsvd6, master1.cell[30].rsvd7, master1.cell[30].rsvd8, master1.cell[30].rsvd9, master1.cell[30].rsvd10, master1.cell[30].rsvd11,master1.cell[30].rsvd12, master1.cell[30].rsvd13, master1.cell[30].rsvd14, master1.cell[30].rsvd15, master1.cell[30].rsvd16);

	Master_To_Monitor_Frame33_Slave32(master1.cell[31].diode_temp, master1.cell[31].trafo_temp, master1.cell[31].fec_temp, master1.cell[31].psfb_temp, master1.cell[31].dc_bus_voltage, master1.cell[31].dc_bus_current, master1.cell[31].fec_input_current, master1.cell[31].psfb_output_voltage,master1.cell[31].psfb_output_current,
			master1.cell[31].sFault1_2.byte, master1.cell[31].sFault3_4.byte,master1.cell[31].sFault5_6.byte,master1.cell[31].sFault7_8.byte,master1.cell[31].sStatus1_2.byte,master1.cell[31].sStatus3_4.byte, master1.cell[31].rsvd0, master1.cell[31].rsvd1, master1.cell[31].rsvd2, master1.cell[31].rsvd3, master1.cell[31].rsvd4,
			master1.cell[31].rsvd5, master1.cell[31].rsvd6, master1.cell[31].rsvd7, master1.cell[31].rsvd8, master1.cell[31].rsvd9, master1.cell[31].rsvd10, master1.cell[31].rsvd11,master1.cell[31].rsvd12, master1.cell[31].rsvd13, master1.cell[31].rsvd14, master1.cell[31].rsvd15, master1.cell[31].rsvd16);

	Master_To_Monitor_Frame34_Slave33(master1.cell[32].diode_temp, master1.cell[32].trafo_temp, master1.cell[32].fec_temp, master1.cell[32].psfb_temp, master1.cell[32].dc_bus_voltage, master1.cell[32].dc_bus_current, master1.cell[32].fec_input_current, master1.cell[32].psfb_output_voltage,master1.cell[32].psfb_output_current,
			master1.cell[32].sFault1_2.byte, master1.cell[32].sFault3_4.byte,master1.cell[32].sFault5_6.byte,master1.cell[32].sFault7_8.byte,master1.cell[32].sStatus1_2.byte,master1.cell[32].sStatus3_4.byte, master1.cell[32].rsvd0, master1.cell[32].rsvd1, master1.cell[32].rsvd2, master1.cell[32].rsvd3, master1.cell[32].rsvd4,
			master1.cell[32].rsvd5, master1.cell[32].rsvd6, master1.cell[32].rsvd7, master1.cell[32].rsvd8, master1.cell[32].rsvd9, master1.cell[32].rsvd10, master1.cell[32].rsvd11,master1.cell[32].rsvd12, master1.cell[32].rsvd13, master1.cell[32].rsvd14, master1.cell[32].rsvd15, master1.cell[32].rsvd16);


	Master_To_Monitor_Frame35_Slave34(master1.cell[33].diode_temp, master1.cell[33].trafo_temp, master1.cell[33].fec_temp, master1.cell[33].psfb_temp, master1.cell[33].dc_bus_voltage, master1.cell[33].dc_bus_current, master1.cell[33].fec_input_current, master1.cell[33].psfb_output_voltage,master1.cell[33].psfb_output_current,
			master1.cell[33].sFault1_2.byte, master1.cell[33].sFault3_4.byte,master1.cell[33].sFault5_6.byte,master1.cell[33].sFault7_8.byte,master1.cell[33].sStatus1_2.byte,master1.cell[33].sStatus3_4.byte, master1.cell[33].rsvd0, master1.cell[33].rsvd1, master1.cell[33].rsvd2, master1.cell[33].rsvd3, master1.cell[33].rsvd4,
			master1.cell[33].rsvd5, master1.cell[33].rsvd6, master1.cell[33].rsvd7, master1.cell[33].rsvd8, master1.cell[33].rsvd9, master1.cell[33].rsvd10, master1.cell[33].rsvd11,master1.cell[33].rsvd12, master1.cell[33].rsvd13, master1.cell[33].rsvd14, master1.cell[33].rsvd15, master1.cell[33].rsvd16);

	Master_To_Monitor_Frame36_Slave35(master1.cell[34].diode_temp, master1.cell[34].trafo_temp, master1.cell[34].fec_temp, master1.cell[34].psfb_temp, master1.cell[34].dc_bus_voltage, master1.cell[34].dc_bus_current, master1.cell[34].fec_input_current, master1.cell[34].psfb_output_voltage,master1.cell[34].psfb_output_current,
			master1.cell[34].sFault1_2.byte, master1.cell[34].sFault3_4.byte,master1.cell[34].sFault5_6.byte,master1.cell[34].sFault7_8.byte,master1.cell[34].sStatus1_2.byte,master1.cell[34].sStatus3_4.byte, master1.cell[34].rsvd0, master1.cell[34].rsvd1, master1.cell[34].rsvd2, master1.cell[34].rsvd3, master1.cell[34].rsvd4,
			master1.cell[34].rsvd5, master1.cell[34].rsvd6, master1.cell[34].rsvd7, master1.cell[34].rsvd8, master1.cell[34].rsvd9, master1.cell[34].rsvd10, master1.cell[34].rsvd11,master1.cell[34].rsvd12, master1.cell[34].rsvd13, master1.cell[34].rsvd14, master1.cell[34].rsvd15, master1.cell[34].rsvd16);

	Master_To_Monitor_Frame37_Slave36(master1.cell[35].diode_temp, master1.cell[35].trafo_temp, master1.cell[35].fec_temp, master1.cell[35].psfb_temp, master1.cell[35].dc_bus_voltage, master1.cell[35].dc_bus_current, master1.cell[35].fec_input_current, master1.cell[35].psfb_output_voltage,master1.cell[35].psfb_output_current,
			master1.cell[35].sFault1_2.byte, master1.cell[35].sFault3_4.byte,master1.cell[35].sFault5_6.byte,master1.cell[35].sFault7_8.byte,master1.cell[35].sStatus1_2.byte,master1.cell[35].sStatus3_4.byte, master1.cell[35].rsvd0, master1.cell[35].rsvd1, master1.cell[35].rsvd2, master1.cell[35].rsvd3, master1.cell[35].rsvd4,
			master1.cell[35].rsvd5, master1.cell[35].rsvd6, master1.cell[35].rsvd7, master1.cell[35].rsvd8, master1.cell[35].rsvd9, master1.cell[35].rsvd10, master1.cell[35].rsvd11,master1.cell[35].rsvd12, master1.cell[35].rsvd13, master1.cell[35].rsvd14, master1.cell[35].rsvd15, master1.cell[35].rsvd16);

	Master_To_Monitor_Frame38_Slave37(master1.cell[36].diode_temp, master1.cell[36].trafo_temp, master1.cell[36].fec_temp, master1.cell[36].psfb_temp, master1.cell[36].dc_bus_voltage, master1.cell[36].dc_bus_current, master1.cell[36].fec_input_current, master1.cell[36].psfb_output_voltage,master1.cell[36].psfb_output_current,
			master1.cell[36].sFault1_2.byte, master1.cell[36].sFault3_4.byte,master1.cell[36].sFault5_6.byte,master1.cell[36].sFault7_8.byte,master1.cell[36].sStatus1_2.byte,master1.cell[36].sStatus3_4.byte, master1.cell[36].rsvd0, master1.cell[36].rsvd1, master1.cell[36].rsvd2, master1.cell[36].rsvd3, master1.cell[36].rsvd4,
			master1.cell[36].rsvd5, master1.cell[36].rsvd6, master1.cell[36].rsvd7, master1.cell[36].rsvd8, master1.cell[36].rsvd9, master1.cell[36].rsvd10, master1.cell[36].rsvd11,master1.cell[36].rsvd12, master1.cell[36].rsvd13, master1.cell[36].rsvd14, master1.cell[36].rsvd15, master1.cell[36].rsvd16);

	Master_To_Monitor_Frame39_Slave38(master1.cell[37].diode_temp, master1.cell[37].trafo_temp, master1.cell[37].fec_temp, master1.cell[37].psfb_temp, master1.cell[37].dc_bus_voltage, master1.cell[37].dc_bus_current, master1.cell[37].fec_input_current, master1.cell[37].psfb_output_voltage,master1.cell[37].psfb_output_current,
			master1.cell[37].sFault1_2.byte, master1.cell[37].sFault3_4.byte,master1.cell[37].sFault5_6.byte,master1.cell[37].sFault7_8.byte,master1.cell[37].sStatus1_2.byte,master1.cell[37].sStatus3_4.byte, master1.cell[37].rsvd0, master1.cell[37].rsvd1, master1.cell[37].rsvd2, master1.cell[37].rsvd3, master1.cell[37].rsvd4,
			master1.cell[37].rsvd5, master1.cell[37].rsvd6, master1.cell[37].rsvd7, master1.cell[37].rsvd8, master1.cell[37].rsvd9, master1.cell[37].rsvd10, master1.cell[37].rsvd11,master1.cell[37].rsvd12, master1.cell[37].rsvd13, master1.cell[37].rsvd14, master1.cell[37].rsvd15, master1.cell[37].rsvd16);

	Master_To_Monitor_Frame40_Slave39(master1.cell[38].diode_temp, master1.cell[38].trafo_temp, master1.cell[38].fec_temp, master1.cell[38].psfb_temp, master1.cell[38].dc_bus_voltage, master1.cell[38].dc_bus_current, master1.cell[38].fec_input_current, master1.cell[38].psfb_output_voltage,master1.cell[38].psfb_output_current,
			master1.cell[38].sFault1_2.byte, master1.cell[38].sFault3_4.byte,master1.cell[38].sFault5_6.byte,master1.cell[38].sFault7_8.byte,master1.cell[38].sStatus1_2.byte,master1.cell[38].sStatus3_4.byte, master1.cell[38].rsvd0, master1.cell[38].rsvd1, master1.cell[38].rsvd2, master1.cell[38].rsvd3, master1.cell[38].rsvd4,
			master1.cell[38].rsvd5, master1.cell[38].rsvd6, master1.cell[38].rsvd7, master1.cell[38].rsvd8, master1.cell[38].rsvd9, master1.cell[38].rsvd10, master1.cell[38].rsvd11,master1.cell[38].rsvd12, master1.cell[38].rsvd13, master1.cell[38].rsvd14, master1.cell[38].rsvd15, master1.cell[38].rsvd16);

}*/
