/*
 * CAN3_Transmitting.c
 *
 *  Created on: Nov 21, 2023
 *      Author: ujwalpatel
 */

#include "CAN3_Transmitting.h"
//#include "fdcan.h"
#include "Master_Monitor_Parameter.h"
#include "Monitor_Master_Parameters.h"
#include "main.h"

#define MULTIFACTOR_10 10
#define MULTIFACTOR_100 100

/*

extern FDCAN_TxHeaderTypeDef TxHeader_CAN3,TxHeader1_CAN3,
TxHeader2_CAN3,
TxHeader3_CAN3,
TxHeader4_CAN3,
TxHeader5_CAN3,
TxHeader6_CAN3,
TxHeader7_CAN3,
TxHeader8_CAN3,
TxHeader9_CAN3,
TxHeader10_CAN3,
TxHeader11_CAN3,
TxHeader12_CAN3,
TxHeader13_CAN3,
TxHeader14_CAN3,
TxHeader15_CAN3,
TxHeader16_CAN3,
TxHeader17_CAN3,
TxHeader18_CAN3,
TxHeader19_CAN3,
TxHeader20_CAN3,
TxHeader21_CAN3,
TxHeader22_CAN3,
TxHeader23_CAN3,
TxHeader24_CAN3,
TxHeader25_CAN3,
TxHeader26_CAN3,
TxHeader27_CAN3,
TxHeader28_CAN3,
TxHeader29_CAN3,
TxHeader30_CAN3,
TxHeader31_CAN3,
TxHeader32_CAN3,
TxHeader33_CAN3,
TxHeader34_CAN3,
TxHeader35_CAN3,
TxHeader36_CAN3,
TxHeader37_CAN3,
TxHeader38_CAN3,
TxHeader39_CAN3;

uint8_t TxDataHandler_CAN3[64],TxDataHandler1_CAN3[64],TxDataHandler2_CAN3[64],
TxDataHandler3_CAN3[64],
TxDataHandler4_CAN3[64],
TxDataHandler5_CAN3[64],
TxDataHandler6_CAN3[64],
TxDataHandler7_CAN3[64],
TxDataHandler8_CAN3[64],
TxDataHandler9_CAN3[64],
TxDataHandler10_CAN3[64],
TxDataHandler11_CAN3[64],
TxDataHandler12_CAN3[64],
TxDataHandler13_CAN3[64],
TxDataHandler14_CAN3[64],
TxDataHandler15_CAN3[64],
TxDataHandler16_CAN3[64],
TxDataHandler17_CAN3[64],
TxDataHandler18_CAN3[64],
TxDataHandler19_CAN3[64],
TxDataHandler20_CAN3[64],
TxDataHandler21_CAN3[64],
TxDataHandler22_CAN3[64],
TxDataHandler23_CAN3[64],
TxDataHandler24_CAN3[64],
TxDataHandler25_CAN3[64],
TxDataHandler26_CAN3[64],
TxDataHandler27_CAN3[64],
TxDataHandler28_CAN3[64],
TxDataHandler29_CAN3[64],
TxDataHandler30_CAN3[64],
TxDataHandler31_CAN3[64],
TxDataHandler32_CAN3[64],
TxDataHandler33_CAN3[64],
TxDataHandler34_CAN3[64],
TxDataHandler35_CAN3[64],
TxDataHandler36_CAN3[64],
TxDataHandler37_CAN3[64],
TxDataHandler38_CAN3[64],
TxDataHandler39_CAN3[64],
u8sucess,u8Fail;

void Master_To_Monitor_Frame1_Master(uint16_t R_Phase_Volt,uint16_t Y_Phase_Volt,uint16_t B_Phase_Volt,float R_Phase_Current,float Y_Phase_Current, float B_Phase_Current,uint16_t System_Active_Power, float Power_Factor,
		float System_Freq, uint16_t Output_Voltage, uint16_t Output_Current, uint16_t Output_Power, uint16_t Mfault1, uint16_t Mfault2, uint16_t Mfault3,uint16_t Mfault4,
		uint16_t Mfault5,uint16_t Mfault6,uint16_t Mfault7,uint16_t Mfault8,uint16_t Mfault9,uint16_t Mfault10,uint16_t Mstatus1,uint16_t Mstatus2,
		uint16_t Mstatus3,uint16_t Mstatus4,uint16_t Mstatus5,uint16_t Mstatus6,uint16_t Mstatus7,uint16_t Mstatus8,uint16_t Mstatus9,uint16_t Mstatus10)
{
	uint16_t u16R_Phase_Volt=(R_Phase_Volt);
	uint16_t u16Y_Phase_Volt=(Y_Phase_Volt);
	uint16_t u16B_Phase_Volt=(B_Phase_Volt);

	uint16_t u16R_Phase_Current=(R_Phase_Current*MULTIFACTOR_10);
	uint16_t u16Y_Phase_Current=(Y_Phase_Current*MULTIFACTOR_10);
	uint16_t u16B_Phase_Current=(B_Phase_Current*MULTIFACTOR_10);

	uint16_t u16System_Active_Power=(System_Active_Power);

	uint16_t u16Power_Factor=(Power_Factor*MULTIFACTOR_100);
	uint16_t u16System_Freq=(System_Freq*MULTIFACTOR_10);

	uint16_t u16Output_Voltage=(Output_Voltage);
	uint16_t u16Output_Current=(Output_Current);
	uint16_t u16Output_Power=(Output_Power);
	uint16_t u16Mfault1=(Mfault1);
	uint16_t u16Mfault2=(Mfault2);
	uint16_t u16Mfault3=(Mfault3);
	uint16_t u16Mfault4=(Mfault4);
	uint16_t u16Mfault5=(Mfault5);
	uint16_t u16Mfault6=(Mfault6);
	uint16_t u16Mfault7=(Mfault7);
	uint16_t u16Mfault8=(Mfault8);
	uint16_t u16Mfault9=(Mfault9);
	uint16_t u16Mfault10=(Mfault10);
	uint16_t u16Mstatus1=(Mstatus1);
	uint16_t u16Mstatus2=(Mstatus2);
	uint16_t u16Mstatus3=(Mstatus3);
	uint16_t u16Mstatus4=(Mstatus4);

	uint16_t u16Mstatus5=(Mstatus5);
	uint16_t u16Mstatus6=(Mstatus6);
	uint16_t u16Mstatus7=(Mstatus7);
	uint16_t u16Mstatus8=(Mstatus8);
	uint16_t u16Mstatus9=(Mstatus9);
	uint16_t u16Mstatus10=(Mstatus10);



	TxDataHandler_CAN3[0]=u16R_Phase_Volt;
	TxDataHandler_CAN3[1]=u16R_Phase_Volt>>8;

	TxDataHandler_CAN3[2]=u16Y_Phase_Volt;
	TxDataHandler_CAN3[3]=u16Y_Phase_Volt>>8;

	TxDataHandler_CAN3[4]=u16B_Phase_Volt;
	TxDataHandler_CAN3[5]=u16B_Phase_Volt>>8;

	TxDataHandler_CAN3[6]=u16R_Phase_Current;
	TxDataHandler_CAN3[7]=u16R_Phase_Current>>8;

	TxDataHandler_CAN3[8]=u16Y_Phase_Current;
	TxDataHandler_CAN3[9]=u16Y_Phase_Current>>8;

	TxDataHandler_CAN3[10]=u16B_Phase_Current;
	TxDataHandler_CAN3[11]=u16B_Phase_Current>>8;

	TxDataHandler_CAN3[12]=u16System_Active_Power;
	TxDataHandler_CAN3[13]=u16System_Active_Power>>8;

	TxDataHandler_CAN3[14]=u16Power_Factor;
	TxDataHandler_CAN3[15]=u16Power_Factor>>8;

	TxDataHandler_CAN3[16]=u16System_Freq;
	TxDataHandler_CAN3[17]=u16System_Freq>>8;

	TxDataHandler_CAN3[18]=u16Output_Voltage;
	TxDataHandler_CAN3[19]=u16Output_Voltage>>8;

	TxDataHandler_CAN3[20]=u16Output_Current;
	TxDataHandler_CAN3[21]=u16Output_Current>>8;

	TxDataHandler_CAN3[22]=u16Output_Power;
	TxDataHandler_CAN3[23]=u16Output_Power>>8;

	TxDataHandler_CAN3[24]=u16Mfault1;
	TxDataHandler_CAN3[25]=u16Mfault1>>8;

	TxDataHandler_CAN3[26]=u16Mfault2;
	TxDataHandler_CAN3[27]=u16Mfault2>>8;

	TxDataHandler_CAN3[28]=u16Mfault3;
	TxDataHandler_CAN3[29]=u16Mfault3>>8;

	TxDataHandler_CAN3[30]=u16Mfault4;
	TxDataHandler_CAN3[31]=u16Mfault4>>8;

	TxDataHandler_CAN3[32]=u16Mfault5;
	TxDataHandler_CAN3[33]=u16Mfault5>>8;

	TxDataHandler_CAN3[34]=u16Mfault6;
	TxDataHandler_CAN3[35]=u16Mfault6>>8;

	TxDataHandler_CAN3[36]=u16Mfault7;
	TxDataHandler_CAN3[37]=u16Mfault7>>8;

	TxDataHandler_CAN3[38]=u16Mfault8;
	TxDataHandler_CAN3[39]=u16Mfault8>>8;

	TxDataHandler_CAN3[40]=u16Mfault9;
	TxDataHandler_CAN3[41]=u16Mfault9>>8;

	TxDataHandler_CAN3[42]=u16Mfault10;
	TxDataHandler_CAN3[43]=u16Mfault10>>8;

	TxDataHandler_CAN3[44]=u16Mstatus1;
	TxDataHandler_CAN3[45]=u16Mstatus1>>8;

	TxDataHandler_CAN3[46]=u16Mstatus2;
	TxDataHandler_CAN3[47]=u16Mstatus2>>8;

	TxDataHandler_CAN3[48]=u16Mstatus3;
	TxDataHandler_CAN3[49]=u16Mstatus3>>8;

	TxDataHandler_CAN3[50]=u16Mstatus4;
	TxDataHandler_CAN3[51]=u16Mstatus4>>8;

	TxDataHandler_CAN3[52]=u16Mstatus5;
	TxDataHandler_CAN3[53]=u16Mstatus5>>8;

	TxDataHandler_CAN3[54]=u16Mstatus6;
	TxDataHandler_CAN3[55]=u16Mstatus6>>8;

	TxDataHandler_CAN3[56]=u16Mstatus7;
	TxDataHandler_CAN3[57]=u16Mstatus7>>8;

	TxDataHandler_CAN3[58]=u16Mstatus8;
	TxDataHandler_CAN3[59]=u16Mstatus8>>8;

	TxDataHandler_CAN3[60]=u16Mstatus9;
	TxDataHandler_CAN3[61]=u16Mstatus9>>8;

	TxDataHandler_CAN3[62]=u16Mstatus10;
	TxDataHandler_CAN3[63]=u16Mstatus10>>8;

	if (HAL_FDCAN_AddMessageToTxFifoQ(&hfdcan3, &TxHeader_CAN3, TxDataHandler_CAN3) != HAL_OK)
	{u8Fail++;}
	else
	{u8sucess++;}
	HAL_Delay(1);
}
//1
void Master_To_Monitor_Frame2_Slave1(float Diode_Temperature,float Transformer_Temperature,float FEC_Temperature,float PSFB_Temperature,float DC_Busvoltage,float DC_Bus_Current,float FEC_input_Current,float PSFB_Output_Voltage,
		float PSFB_Output_Current,uint16_t SFault1_2,uint16_t SFault3_4,uint16_t SFault5_6,uint16_t SFault7_8,uint16_t SStatus1_2,uint16_t SStatus3_4,uint16_t RSVD_1,
		uint16_t RSVD_2,uint16_t RSVD_3,uint16_t RSVD_4,uint16_t RSVD_5,uint16_t RSVD_6,uint16_t RSVD_7,uint16_t RSVD_8,uint16_t RSVD_9,
		uint16_t RSVD_10,uint16_t RSVD_11,uint16_t RSVD_12,uint16_t RSVD_13,uint16_t RSVD_14,uint16_t RSVD_15,uint16_t RSVD_16,uint16_t RSVD_17)
{

	uint16_t u16Diode_Temperature=(Diode_Temperature*MULTIFACTOR_10);
	uint16_t u16Transformer_Temperature=(Transformer_Temperature*MULTIFACTOR_10);
	uint16_t u16FEC_Temperature=(FEC_Temperature*MULTIFACTOR_10);

	uint16_t u16PSFB_Temperature=(PSFB_Temperature*MULTIFACTOR_10);
	uint16_t u16DC_Busvoltage=(DC_Busvoltage*MULTIFACTOR_10);
	uint16_t u16DC_Bus_Current=(DC_Bus_Current*MULTIFACTOR_10);

	uint16_t u16FEC_input_Current=(FEC_input_Current*MULTIFACTOR_10);
	uint16_t u16PSFB_Output_Voltage=(PSFB_Output_Voltage*MULTIFACTOR_10);
	uint16_t u16PSFB_Output_Current=(PSFB_Output_Current*MULTIFACTOR_10);

	uint16_t u16SFault1_2=(SFault1_2);
	uint16_t u16SFault3_4=(SFault3_4);
	uint16_t u16SFault5_6=(SFault5_6);
	uint16_t u16SFault7_8=(SFault7_8);

	uint16_t u16SStatus1_2=(SStatus1_2);
	uint16_t u16SStatus3_4=(SStatus3_4);

	uint16_t u16RSVD_1=(RSVD_1);
	uint16_t u16RSVD_2=(RSVD_2);
	uint16_t u16RSVD_3=(RSVD_3);
	uint16_t u16RSVD_4=(RSVD_4);
	uint16_t u16RSVD_5=(RSVD_5);
	uint16_t u16RSVD_6=(RSVD_6);
	uint16_t u16RSVD_7=(RSVD_7);
	uint16_t u16RSVD_8=(RSVD_8);
	uint16_t u16RSVD_9=(RSVD_9);
	uint16_t u16RSVD_10=(RSVD_10);
	uint16_t u16RSVD_11=(RSVD_11);
	uint16_t u16RSVD_12=(RSVD_12);
	uint16_t u16RSVD_13=(RSVD_13);
	uint16_t u16RSVD_14=(RSVD_14);
	uint16_t u16RSVD_15=(RSVD_15);
	uint16_t u16RSVD_16=(RSVD_16);
	uint16_t u16RSVD_17=(RSVD_17);


	TxDataHandler1_CAN3[0]=u16Diode_Temperature;
	TxDataHandler1_CAN3[1]=u16Diode_Temperature>>8;

	TxDataHandler1_CAN3[2]=u16Transformer_Temperature;
	TxDataHandler1_CAN3[3]=u16Transformer_Temperature>>8;

	TxDataHandler1_CAN3[4]=u16FEC_Temperature;
	TxDataHandler1_CAN3[5]=u16FEC_Temperature>>8;

	TxDataHandler1_CAN3[6]=u16PSFB_Temperature;
	TxDataHandler1_CAN3[7]=u16PSFB_Temperature>>8;

	TxDataHandler1_CAN3[8]=u16DC_Busvoltage;
	TxDataHandler1_CAN3[9]=u16DC_Busvoltage>>8;

	TxDataHandler1_CAN3[10]=u16DC_Bus_Current;
	TxDataHandler1_CAN3[11]=u16DC_Bus_Current>>8;

	TxDataHandler1_CAN3[12]=u16FEC_input_Current;
	TxDataHandler1_CAN3[13]=u16FEC_input_Current>>8;

	TxDataHandler1_CAN3[14]=u16PSFB_Output_Voltage;
	TxDataHandler1_CAN3[15]=u16PSFB_Output_Voltage>>8;

	TxDataHandler1_CAN3[16]=u16PSFB_Output_Current;
	TxDataHandler1_CAN3[17]=u16PSFB_Output_Current>>8;

	TxDataHandler1_CAN3[18]=u16SFault1_2;
	TxDataHandler1_CAN3[19]=u16SFault1_2>>8;

	TxDataHandler1_CAN3[20]=u16SFault3_4;
	TxDataHandler1_CAN3[21]=u16SFault3_4>>8;

	TxDataHandler1_CAN3[22]=u16SFault5_6;
	TxDataHandler1_CAN3[23]=u16SFault5_6>>8;

	TxDataHandler1_CAN3[24]=u16SFault7_8;
	TxDataHandler1_CAN3[25]=u16SFault7_8>>8;

	TxDataHandler1_CAN3[26]=u16SStatus1_2;
	TxDataHandler1_CAN3[27]=u16SStatus1_2>>8;

	TxDataHandler1_CAN3[28]=u16SStatus3_4;
	TxDataHandler1_CAN3[29]=u16SStatus3_4>>8;

	TxDataHandler1_CAN3[30]=u16RSVD_1;
	TxDataHandler1_CAN3[31]=u16RSVD_1>>8;

	TxDataHandler1_CAN3[32]=u16RSVD_2;
	TxDataHandler1_CAN3[33]=u16RSVD_2>>8;

	TxDataHandler1_CAN3[34]=u16RSVD_3;
	TxDataHandler1_CAN3[35]=u16RSVD_3>>8;

	TxDataHandler1_CAN3[36]=u16RSVD_4;
	TxDataHandler1_CAN3[37]=u16RSVD_4>>8;

	TxDataHandler1_CAN3[38]=u16RSVD_5;
	TxDataHandler1_CAN3[39]=u16RSVD_5>>8;

	TxDataHandler1_CAN3[40]=u16RSVD_6;
	TxDataHandler1_CAN3[41]=u16RSVD_6>>8;

	TxDataHandler1_CAN3[42]=u16RSVD_7;
	TxDataHandler1_CAN3[43]=u16RSVD_7>>8;

	TxDataHandler1_CAN3[44]=u16RSVD_8;
	TxDataHandler1_CAN3[45]=u16RSVD_8>>8;

	TxDataHandler1_CAN3[46]=u16RSVD_9;
	TxDataHandler1_CAN3[47]=u16RSVD_9>>8;

	TxDataHandler1_CAN3[48]=u16RSVD_10;
	TxDataHandler1_CAN3[49]=u16RSVD_10>>8;

	TxDataHandler1_CAN3[50]=u16RSVD_11;
	TxDataHandler1_CAN3[51]=u16RSVD_11>>8;

	TxDataHandler1_CAN3[52]=u16RSVD_12;
	TxDataHandler1_CAN3[53]=u16RSVD_12>>8;

	TxDataHandler1_CAN3[54]=u16RSVD_13;
	TxDataHandler1_CAN3[55]=u16RSVD_13>>8;

	TxDataHandler1_CAN3[56]=u16RSVD_14;
	TxDataHandler1_CAN3[57]=u16RSVD_14>>8;

	TxDataHandler1_CAN3[58]=u16RSVD_15;
	TxDataHandler1_CAN3[59]=u16RSVD_15>>8;

	TxDataHandler1_CAN3[60]=u16RSVD_16;
	TxDataHandler1_CAN3[61]=u16RSVD_16>>8;

	TxDataHandler1_CAN3[62]=u16RSVD_17;
	TxDataHandler1_CAN3[63]=u16RSVD_17>>8;

	if (HAL_FDCAN_AddMessageToTxFifoQ(&hfdcan3, &TxHeader1_CAN3, TxDataHandler1_CAN3) != HAL_OK)
	{}
	else
	{}
	HAL_Delay(1);
}

//2
void Master_To_Monitor_Frame3_Slave2(float Diode_Temperature,float Transformer_Temperature,float FEC_Temperature,float PSFB_Temperature,float DC_Busvoltage,float DC_Bus_Current,float FEC_input_Current,float PSFB_Output_Voltage,
		float PSFB_Output_Current,uint16_t SFault1_2,uint16_t SFault3_4,uint16_t SFault5_6,uint16_t SFault7_8,uint16_t SStatus1_2,uint16_t SStatus3_4,uint16_t RSVD_1,
		uint16_t RSVD_2,uint16_t RSVD_3,uint16_t RSVD_4,uint16_t RSVD_5,uint16_t RSVD_6,uint16_t RSVD_7,uint16_t RSVD_8,uint16_t RSVD_9,
		uint16_t RSVD_10,uint16_t RSVD_11,uint16_t RSVD_12,uint16_t RSVD_13,uint16_t RSVD_14,uint16_t RSVD_15,uint16_t RSVD_16,uint16_t RSVD_17)
{

	uint16_t u16Diode_Temperature=(Diode_Temperature*MULTIFACTOR_10);
	uint16_t u16Transformer_Temperature=(Transformer_Temperature*MULTIFACTOR_10);
	uint16_t u16FEC_Temperature=(FEC_Temperature*MULTIFACTOR_10);

	uint16_t u16PSFB_Temperature=(PSFB_Temperature*MULTIFACTOR_10);
	uint16_t u16DC_Busvoltage=(DC_Busvoltage*MULTIFACTOR_10);
	uint16_t u16DC_Bus_Current=(DC_Bus_Current*MULTIFACTOR_10);

	uint16_t u16FEC_input_Current=(FEC_input_Current*MULTIFACTOR_10);
	uint16_t u16PSFB_Output_Voltage=(PSFB_Output_Voltage*MULTIFACTOR_10);
	uint16_t u16PSFB_Output_Current=(PSFB_Output_Current*MULTIFACTOR_10);

	uint16_t u16SFault1_2=(SFault1_2);
	uint16_t u16SFault3_4=(SFault3_4);
	uint16_t u16SFault5_6=(SFault5_6);
	uint16_t u16SFault7_8=(SFault7_8);

	uint16_t u16SStatus1_2=(SStatus1_2);
	uint16_t u16SStatus3_4=(SStatus3_4);

	uint16_t u16RSVD_1=(RSVD_1);
	uint16_t u16RSVD_2=(RSVD_2);
	uint16_t u16RSVD_3=(RSVD_3);
	uint16_t u16RSVD_4=(RSVD_4);
	uint16_t u16RSVD_5=(RSVD_5);
	uint16_t u16RSVD_6=(RSVD_6);
	uint16_t u16RSVD_7=(RSVD_7);
	uint16_t u16RSVD_8=(RSVD_8);
	uint16_t u16RSVD_9=(RSVD_9);
	uint16_t u16RSVD_10=(RSVD_10);
	uint16_t u16RSVD_11=(RSVD_11);
	uint16_t u16RSVD_12=(RSVD_12);
	uint16_t u16RSVD_13=(RSVD_13);
	uint16_t u16RSVD_14=(RSVD_14);
	uint16_t u16RSVD_15=(RSVD_15);
	uint16_t u16RSVD_16=(RSVD_16);
	uint16_t u16RSVD_17=(RSVD_17);


	TxDataHandler2_CAN3[0]=u16Diode_Temperature;
	TxDataHandler2_CAN3[1]=u16Diode_Temperature>>8;

	TxDataHandler2_CAN3[2]=u16Transformer_Temperature;
	TxDataHandler2_CAN3[3]=u16Transformer_Temperature>>8;

	TxDataHandler2_CAN3[4]=u16FEC_Temperature;
	TxDataHandler2_CAN3[5]=u16FEC_Temperature>>8;

	TxDataHandler2_CAN3[6]=u16PSFB_Temperature;
	TxDataHandler2_CAN3[7]=u16PSFB_Temperature>>8;

	TxDataHandler2_CAN3[8]=u16DC_Busvoltage;
	TxDataHandler2_CAN3[9]=u16DC_Busvoltage>>8;

	TxDataHandler2_CAN3[10]=u16DC_Bus_Current;
	TxDataHandler2_CAN3[11]=u16DC_Bus_Current>>8;

	TxDataHandler2_CAN3[12]=u16FEC_input_Current;
	TxDataHandler2_CAN3[13]=u16FEC_input_Current>>8;

	TxDataHandler2_CAN3[14]=u16PSFB_Output_Voltage;
	TxDataHandler2_CAN3[15]=u16PSFB_Output_Voltage>>8;

	TxDataHandler2_CAN3[16]=u16PSFB_Output_Current;
	TxDataHandler2_CAN3[17]=u16PSFB_Output_Current>>8;

	TxDataHandler2_CAN3[18]=u16SFault1_2;
	TxDataHandler2_CAN3[19]=u16SFault1_2>>8;

	TxDataHandler2_CAN3[20]=u16SFault3_4;
	TxDataHandler2_CAN3[21]=u16SFault3_4>>8;

	TxDataHandler2_CAN3[22]=u16SFault5_6;
	TxDataHandler2_CAN3[23]=u16SFault5_6>>8;

	TxDataHandler2_CAN3[24]=u16SFault7_8;
	TxDataHandler2_CAN3[25]=u16SFault7_8>>8;

	TxDataHandler2_CAN3[26]=u16SStatus1_2;
	TxDataHandler2_CAN3[27]=u16SStatus1_2>>8;

	TxDataHandler2_CAN3[28]=u16SStatus3_4;
	TxDataHandler2_CAN3[29]=u16SStatus3_4>>8;

	TxDataHandler2_CAN3[30]=u16RSVD_1;
	TxDataHandler2_CAN3[31]=u16RSVD_1>>8;

	TxDataHandler2_CAN3[32]=u16RSVD_2;
	TxDataHandler2_CAN3[33]=u16RSVD_2>>8;

	TxDataHandler2_CAN3[34]=u16RSVD_3;
	TxDataHandler2_CAN3[35]=u16RSVD_3>>8;

	TxDataHandler2_CAN3[36]=u16RSVD_4;
	TxDataHandler2_CAN3[37]=u16RSVD_4>>8;

	TxDataHandler2_CAN3[38]=u16RSVD_5;
	TxDataHandler2_CAN3[39]=u16RSVD_5>>8;

	TxDataHandler2_CAN3[40]=u16RSVD_6;
	TxDataHandler2_CAN3[41]=u16RSVD_6>>8;

	TxDataHandler2_CAN3[42]=u16RSVD_7;
	TxDataHandler2_CAN3[43]=u16RSVD_7>>8;

	TxDataHandler2_CAN3[44]=u16RSVD_8;
	TxDataHandler2_CAN3[45]=u16RSVD_8>>8;

	TxDataHandler2_CAN3[46]=u16RSVD_9;
	TxDataHandler2_CAN3[47]=u16RSVD_9>>8;

	TxDataHandler2_CAN3[48]=u16RSVD_10;
	TxDataHandler2_CAN3[49]=u16RSVD_10>>8;

	TxDataHandler2_CAN3[50]=u16RSVD_11;
	TxDataHandler2_CAN3[51]=u16RSVD_11>>8;

	TxDataHandler2_CAN3[52]=u16RSVD_12;
	TxDataHandler2_CAN3[53]=u16RSVD_12>>8;

	TxDataHandler2_CAN3[54]=u16RSVD_13;
	TxDataHandler2_CAN3[55]=u16RSVD_13>>8;

	TxDataHandler2_CAN3[56]=u16RSVD_14;
	TxDataHandler2_CAN3[57]=u16RSVD_14>>8;

	TxDataHandler2_CAN3[58]=u16RSVD_15;
	TxDataHandler2_CAN3[59]=u16RSVD_15>>8;

	TxDataHandler2_CAN3[60]=u16RSVD_16;
	TxDataHandler2_CAN3[61]=u16RSVD_16>>8;

	TxDataHandler2_CAN3[62]=u16RSVD_17;
	TxDataHandler2_CAN3[63]=u16RSVD_17>>8;

	if (HAL_FDCAN_AddMessageToTxFifoQ(&hfdcan3, &TxHeader2_CAN3, TxDataHandler2_CAN3) != HAL_OK)
	{}
	else
	{}
	HAL_Delay(1);
}
//3
void Master_To_Monitor_Frame4_Slave3(float Diode_Temperature,float Transformer_Temperature,float FEC_Temperature,float PSFB_Temperature,float DC_Busvoltage,float DC_Bus_Current,float FEC_input_Current,float PSFB_Output_Voltage,
		float PSFB_Output_Current,uint16_t SFault1_2,uint16_t SFault3_4,uint16_t SFault5_6,uint16_t SFault7_8,uint16_t SStatus1_2,uint16_t SStatus3_4,uint16_t RSVD_1,
		uint16_t RSVD_2,uint16_t RSVD_3,uint16_t RSVD_4,uint16_t RSVD_5,uint16_t RSVD_6,uint16_t RSVD_7,uint16_t RSVD_8,uint16_t RSVD_9,
		uint16_t RSVD_10,uint16_t RSVD_11,uint16_t RSVD_12,uint16_t RSVD_13,uint16_t RSVD_14,uint16_t RSVD_15,uint16_t RSVD_16,uint16_t RSVD_17)
{

	uint16_t u16Diode_Temperature=(Diode_Temperature*MULTIFACTOR_10);
	uint16_t u16Transformer_Temperature=(Transformer_Temperature*MULTIFACTOR_10);
	uint16_t u16FEC_Temperature=(FEC_Temperature*MULTIFACTOR_10);

	uint16_t u16PSFB_Temperature=(PSFB_Temperature*MULTIFACTOR_10);
	uint16_t u16DC_Busvoltage=(DC_Busvoltage*MULTIFACTOR_10);
	uint16_t u16DC_Bus_Current=(DC_Bus_Current*MULTIFACTOR_10);

	uint16_t u16FEC_input_Current=(FEC_input_Current*MULTIFACTOR_10);
	uint16_t u16PSFB_Output_Voltage=(PSFB_Output_Voltage*MULTIFACTOR_10);
	uint16_t u16PSFB_Output_Current=(PSFB_Output_Current*MULTIFACTOR_10);

	uint16_t u16SFault1_2=(SFault1_2);
	uint16_t u16SFault3_4=(SFault3_4);
	uint16_t u16SFault5_6=(SFault5_6);
	uint16_t u16SFault7_8=(SFault7_8);

	uint16_t u16SStatus1_2=(SStatus1_2);
	uint16_t u16SStatus3_4=(SStatus3_4);

	uint16_t u16RSVD_1=(RSVD_1);
	uint16_t u16RSVD_2=(RSVD_2);
	uint16_t u16RSVD_3=(RSVD_3);
	uint16_t u16RSVD_4=(RSVD_4);
	uint16_t u16RSVD_5=(RSVD_5);
	uint16_t u16RSVD_6=(RSVD_6);
	uint16_t u16RSVD_7=(RSVD_7);
	uint16_t u16RSVD_8=(RSVD_8);
	uint16_t u16RSVD_9=(RSVD_9);
	uint16_t u16RSVD_10=(RSVD_10);
	uint16_t u16RSVD_11=(RSVD_11);
	uint16_t u16RSVD_12=(RSVD_12);
	uint16_t u16RSVD_13=(RSVD_13);
	uint16_t u16RSVD_14=(RSVD_14);
	uint16_t u16RSVD_15=(RSVD_15);
	uint16_t u16RSVD_16=(RSVD_16);
	uint16_t u16RSVD_17=(RSVD_17);


	TxDataHandler3_CAN3[0]=u16Diode_Temperature;
	TxDataHandler3_CAN3[1]=u16Diode_Temperature>>8;

	TxDataHandler3_CAN3[2]=u16Transformer_Temperature;
	TxDataHandler3_CAN3[3]=u16Transformer_Temperature>>8;

	TxDataHandler3_CAN3[4]=u16FEC_Temperature;
	TxDataHandler3_CAN3[5]=u16FEC_Temperature>>8;

	TxDataHandler3_CAN3[6]=u16PSFB_Temperature;
	TxDataHandler3_CAN3[7]=u16PSFB_Temperature>>8;

	TxDataHandler3_CAN3[8]=u16DC_Busvoltage;
	TxDataHandler3_CAN3[9]=u16DC_Busvoltage>>8;

	TxDataHandler3_CAN3[10]=u16DC_Bus_Current;
	TxDataHandler3_CAN3[11]=u16DC_Bus_Current>>8;

	TxDataHandler3_CAN3[12]=u16FEC_input_Current;
	TxDataHandler3_CAN3[13]=u16FEC_input_Current>>8;

	TxDataHandler3_CAN3[14]=u16PSFB_Output_Voltage;
	TxDataHandler3_CAN3[15]=u16PSFB_Output_Voltage>>8;

	TxDataHandler3_CAN3[16]=u16PSFB_Output_Current;
	TxDataHandler3_CAN3[17]=u16PSFB_Output_Current>>8;

	TxDataHandler3_CAN3[18]=u16SFault1_2;
	TxDataHandler3_CAN3[19]=u16SFault1_2>>8;

	TxDataHandler3_CAN3[20]=u16SFault3_4;
	TxDataHandler3_CAN3[21]=u16SFault3_4>>8;

	TxDataHandler3_CAN3[22]=u16SFault5_6;
	TxDataHandler3_CAN3[23]=u16SFault5_6>>8;

	TxDataHandler3_CAN3[24]=u16SFault7_8;
	TxDataHandler3_CAN3[25]=u16SFault7_8>>8;

	TxDataHandler3_CAN3[26]=u16SStatus1_2;
	TxDataHandler3_CAN3[27]=u16SStatus1_2>>8;

	TxDataHandler3_CAN3[28]=u16SStatus3_4;
	TxDataHandler3_CAN3[29]=u16SStatus3_4>>8;

	TxDataHandler3_CAN3[30]=u16RSVD_1;
	TxDataHandler3_CAN3[31]=u16RSVD_1>>8;

	TxDataHandler3_CAN3[32]=u16RSVD_2;
	TxDataHandler3_CAN3[33]=u16RSVD_2>>8;

	TxDataHandler3_CAN3[34]=u16RSVD_3;
	TxDataHandler3_CAN3[35]=u16RSVD_3>>8;

	TxDataHandler3_CAN3[36]=u16RSVD_4;
	TxDataHandler3_CAN3[37]=u16RSVD_4>>8;

	TxDataHandler3_CAN3[38]=u16RSVD_5;
	TxDataHandler3_CAN3[39]=u16RSVD_5>>8;

	TxDataHandler3_CAN3[40]=u16RSVD_6;
	TxDataHandler3_CAN3[41]=u16RSVD_6>>8;

	TxDataHandler3_CAN3[42]=u16RSVD_7;
	TxDataHandler3_CAN3[43]=u16RSVD_7>>8;

	TxDataHandler3_CAN3[44]=u16RSVD_8;
	TxDataHandler3_CAN3[45]=u16RSVD_8>>8;

	TxDataHandler3_CAN3[46]=u16RSVD_9;
	TxDataHandler3_CAN3[47]=u16RSVD_9>>8;

	TxDataHandler3_CAN3[48]=u16RSVD_10;
	TxDataHandler3_CAN3[49]=u16RSVD_10>>8;

	TxDataHandler3_CAN3[50]=u16RSVD_11;
	TxDataHandler3_CAN3[51]=u16RSVD_11>>8;

	TxDataHandler3_CAN3[52]=u16RSVD_12;
	TxDataHandler3_CAN3[53]=u16RSVD_12>>8;

	TxDataHandler3_CAN3[54]=u16RSVD_13;
	TxDataHandler3_CAN3[55]=u16RSVD_13>>8;

	TxDataHandler3_CAN3[56]=u16RSVD_14;
	TxDataHandler3_CAN3[57]=u16RSVD_14>>8;

	TxDataHandler3_CAN3[58]=u16RSVD_15;
	TxDataHandler3_CAN3[59]=u16RSVD_15>>8;

	TxDataHandler3_CAN3[60]=u16RSVD_16;
	TxDataHandler3_CAN3[61]=u16RSVD_16>>8;

	TxDataHandler3_CAN3[62]=u16RSVD_17;
	TxDataHandler3_CAN3[63]=u16RSVD_17>>8;

	if (HAL_FDCAN_AddMessageToTxFifoQ(&hfdcan3, &TxHeader3_CAN3, TxDataHandler3_CAN3) != HAL_OK)
	{}
	else
	{}
	HAL_Delay(1);
}
//4
void Master_To_Monitor_Frame5_Slave4(float Diode_Temperature,float Transformer_Temperature,float FEC_Temperature,float PSFB_Temperature,float DC_Busvoltage,float DC_Bus_Current,float FEC_input_Current,float PSFB_Output_Voltage,
		float PSFB_Output_Current,uint16_t SFault1_2,uint16_t SFault3_4,uint16_t SFault5_6,uint16_t SFault7_8,uint16_t SStatus1_2,uint16_t SStatus3_4,uint16_t RSVD_1,
		uint16_t RSVD_2,uint16_t RSVD_3,uint16_t RSVD_4,uint16_t RSVD_5,uint16_t RSVD_6,uint16_t RSVD_7,uint16_t RSVD_8,uint16_t RSVD_9,
		uint16_t RSVD_10,uint16_t RSVD_11,uint16_t RSVD_12,uint16_t RSVD_13,uint16_t RSVD_14,uint16_t RSVD_15,uint16_t RSVD_16,uint16_t RSVD_17)
{

	uint16_t u16Diode_Temperature=(Diode_Temperature*MULTIFACTOR_10);
	uint16_t u16Transformer_Temperature=(Transformer_Temperature*MULTIFACTOR_10);
	uint16_t u16FEC_Temperature=(FEC_Temperature*MULTIFACTOR_10);

	uint16_t u16PSFB_Temperature=(PSFB_Temperature*MULTIFACTOR_10);
	uint16_t u16DC_Busvoltage=(DC_Busvoltage*MULTIFACTOR_10);
	uint16_t u16DC_Bus_Current=(DC_Bus_Current*MULTIFACTOR_10);

	uint16_t u16FEC_input_Current=(FEC_input_Current*MULTIFACTOR_10);
	uint16_t u16PSFB_Output_Voltage=(PSFB_Output_Voltage*MULTIFACTOR_10);
	uint16_t u16PSFB_Output_Current=(PSFB_Output_Current*MULTIFACTOR_10);

	uint16_t u16SFault1_2=(SFault1_2);
	uint16_t u16SFault3_4=(SFault3_4);
	uint16_t u16SFault5_6=(SFault5_6);
	uint16_t u16SFault7_8=(SFault7_8);

	uint16_t u16SStatus1_2=(SStatus1_2);
	uint16_t u16SStatus3_4=(SStatus3_4);

	uint16_t u16RSVD_1=(RSVD_1);
	uint16_t u16RSVD_2=(RSVD_2);
	uint16_t u16RSVD_3=(RSVD_3);
	uint16_t u16RSVD_4=(RSVD_4);
	uint16_t u16RSVD_5=(RSVD_5);
	uint16_t u16RSVD_6=(RSVD_6);
	uint16_t u16RSVD_7=(RSVD_7);
	uint16_t u16RSVD_8=(RSVD_8);
	uint16_t u16RSVD_9=(RSVD_9);
	uint16_t u16RSVD_10=(RSVD_10);
	uint16_t u16RSVD_11=(RSVD_11);
	uint16_t u16RSVD_12=(RSVD_12);
	uint16_t u16RSVD_13=(RSVD_13);
	uint16_t u16RSVD_14=(RSVD_14);
	uint16_t u16RSVD_15=(RSVD_15);
	uint16_t u16RSVD_16=(RSVD_16);
	uint16_t u16RSVD_17=(RSVD_17);


	TxDataHandler4_CAN3[0]=u16Diode_Temperature;
	TxDataHandler4_CAN3[1]=u16Diode_Temperature>>8;

	TxDataHandler4_CAN3[2]=u16Transformer_Temperature;
	TxDataHandler4_CAN3[3]=u16Transformer_Temperature>>8;

	TxDataHandler4_CAN3[4]=u16FEC_Temperature;
	TxDataHandler4_CAN3[5]=u16FEC_Temperature>>8;

	TxDataHandler4_CAN3[6]=u16PSFB_Temperature;
	TxDataHandler4_CAN3[7]=u16PSFB_Temperature>>8;

	TxDataHandler4_CAN3[8]=u16DC_Busvoltage;
	TxDataHandler4_CAN3[9]=u16DC_Busvoltage>>8;

	TxDataHandler4_CAN3[10]=u16DC_Bus_Current;
	TxDataHandler4_CAN3[11]=u16DC_Bus_Current>>8;

	TxDataHandler4_CAN3[12]=u16FEC_input_Current;
	TxDataHandler4_CAN3[13]=u16FEC_input_Current>>8;

	TxDataHandler4_CAN3[14]=u16PSFB_Output_Voltage;
	TxDataHandler4_CAN3[15]=u16PSFB_Output_Voltage>>8;

	TxDataHandler4_CAN3[16]=u16PSFB_Output_Current;
	TxDataHandler4_CAN3[17]=u16PSFB_Output_Current>>8;

	TxDataHandler4_CAN3[18]=u16SFault1_2;
	TxDataHandler4_CAN3[19]=u16SFault1_2>>8;

	TxDataHandler4_CAN3[20]=u16SFault3_4;
	TxDataHandler4_CAN3[21]=u16SFault3_4>>8;

	TxDataHandler4_CAN3[22]=u16SFault5_6;
	TxDataHandler4_CAN3[23]=u16SFault5_6>>8;

	TxDataHandler4_CAN3[24]=u16SFault7_8;
	TxDataHandler4_CAN3[25]=u16SFault7_8>>8;

	TxDataHandler4_CAN3[26]=u16SStatus1_2;
	TxDataHandler4_CAN3[27]=u16SStatus1_2>>8;

	TxDataHandler4_CAN3[28]=u16SStatus3_4;
	TxDataHandler4_CAN3[29]=u16SStatus3_4>>8;

	TxDataHandler4_CAN3[30]=u16RSVD_1;
	TxDataHandler4_CAN3[31]=u16RSVD_1>>8;

	TxDataHandler4_CAN3[32]=u16RSVD_2;
	TxDataHandler4_CAN3[33]=u16RSVD_2>>8;

	TxDataHandler4_CAN3[34]=u16RSVD_3;
	TxDataHandler4_CAN3[35]=u16RSVD_3>>8;

	TxDataHandler4_CAN3[36]=u16RSVD_4;
	TxDataHandler4_CAN3[37]=u16RSVD_4>>8;

	TxDataHandler4_CAN3[38]=u16RSVD_5;
	TxDataHandler4_CAN3[39]=u16RSVD_5>>8;

	TxDataHandler4_CAN3[40]=u16RSVD_6;
	TxDataHandler4_CAN3[41]=u16RSVD_6>>8;

	TxDataHandler4_CAN3[42]=u16RSVD_7;
	TxDataHandler4_CAN3[43]=u16RSVD_7>>8;

	TxDataHandler4_CAN3[44]=u16RSVD_8;
	TxDataHandler4_CAN3[45]=u16RSVD_8>>8;

	TxDataHandler4_CAN3[46]=u16RSVD_9;
	TxDataHandler4_CAN3[47]=u16RSVD_9>>8;

	TxDataHandler4_CAN3[48]=u16RSVD_10;
	TxDataHandler4_CAN3[49]=u16RSVD_10>>8;

	TxDataHandler4_CAN3[50]=u16RSVD_11;
	TxDataHandler4_CAN3[51]=u16RSVD_11>>8;

	TxDataHandler4_CAN3[52]=u16RSVD_12;
	TxDataHandler4_CAN3[53]=u16RSVD_12>>8;

	TxDataHandler4_CAN3[54]=u16RSVD_13;
	TxDataHandler4_CAN3[55]=u16RSVD_13>>8;

	TxDataHandler4_CAN3[56]=u16RSVD_14;
	TxDataHandler4_CAN3[57]=u16RSVD_14>>8;

	TxDataHandler4_CAN3[58]=u16RSVD_15;
	TxDataHandler4_CAN3[59]=u16RSVD_15>>8;

	TxDataHandler4_CAN3[60]=u16RSVD_16;
	TxDataHandler4_CAN3[61]=u16RSVD_16>>8;

	TxDataHandler4_CAN3[62]=u16RSVD_17;
	TxDataHandler4_CAN3[63]=u16RSVD_17>>8;

	if (HAL_FDCAN_AddMessageToTxFifoQ(&hfdcan3, &TxHeader4_CAN3, TxDataHandler4_CAN3) != HAL_OK)
	{}
	else
	{}
	HAL_Delay(1);
}
//5
void Master_To_Monitor_Frame6_Slave5(float Diode_Temperature,float Transformer_Temperature,float FEC_Temperature,float PSFB_Temperature,float DC_Busvoltage,float DC_Bus_Current,float FEC_input_Current,float PSFB_Output_Voltage,
		float PSFB_Output_Current,uint16_t SFault1_2,uint16_t SFault3_4,uint16_t SFault5_6,uint16_t SFault7_8,uint16_t SStatus1_2,uint16_t SStatus3_4,uint16_t RSVD_1,
		uint16_t RSVD_2,uint16_t RSVD_3,uint16_t RSVD_4,uint16_t RSVD_5,uint16_t RSVD_6,uint16_t RSVD_7,uint16_t RSVD_8,uint16_t RSVD_9,
		uint16_t RSVD_10,uint16_t RSVD_11,uint16_t RSVD_12,uint16_t RSVD_13,uint16_t RSVD_14,uint16_t RSVD_15,uint16_t RSVD_16,uint16_t RSVD_17)
{

	uint16_t u16Diode_Temperature=(Diode_Temperature*MULTIFACTOR_10);
	uint16_t u16Transformer_Temperature=(Transformer_Temperature*MULTIFACTOR_10);
	uint16_t u16FEC_Temperature=(FEC_Temperature*MULTIFACTOR_10);

	uint16_t u16PSFB_Temperature=(PSFB_Temperature*MULTIFACTOR_10);
	uint16_t u16DC_Busvoltage=(DC_Busvoltage*MULTIFACTOR_10);
	uint16_t u16DC_Bus_Current=(DC_Bus_Current*MULTIFACTOR_10);

	uint16_t u16FEC_input_Current=(FEC_input_Current*MULTIFACTOR_10);
	uint16_t u16PSFB_Output_Voltage=(PSFB_Output_Voltage*MULTIFACTOR_10);
	uint16_t u16PSFB_Output_Current=(PSFB_Output_Current*MULTIFACTOR_10);

	uint16_t u16SFault1_2=(SFault1_2);
	uint16_t u16SFault3_4=(SFault3_4);
	uint16_t u16SFault5_6=(SFault5_6);
	uint16_t u16SFault7_8=(SFault7_8);

	uint16_t u16SStatus1_2=(SStatus1_2);
	uint16_t u16SStatus3_4=(SStatus3_4);

	uint16_t u16RSVD_1=(RSVD_1);
	uint16_t u16RSVD_2=(RSVD_2);
	uint16_t u16RSVD_3=(RSVD_3);
	uint16_t u16RSVD_4=(RSVD_4);
	uint16_t u16RSVD_5=(RSVD_5);
	uint16_t u16RSVD_6=(RSVD_6);
	uint16_t u16RSVD_7=(RSVD_7);
	uint16_t u16RSVD_8=(RSVD_8);
	uint16_t u16RSVD_9=(RSVD_9);
	uint16_t u16RSVD_10=(RSVD_10);
	uint16_t u16RSVD_11=(RSVD_11);
	uint16_t u16RSVD_12=(RSVD_12);
	uint16_t u16RSVD_13=(RSVD_13);
	uint16_t u16RSVD_14=(RSVD_14);
	uint16_t u16RSVD_15=(RSVD_15);
	uint16_t u16RSVD_16=(RSVD_16);
	uint16_t u16RSVD_17=(RSVD_17);


	TxDataHandler5_CAN3[0]=u16Diode_Temperature;
	TxDataHandler5_CAN3[1]=u16Diode_Temperature>>8;

	TxDataHandler5_CAN3[2]=u16Transformer_Temperature;
	TxDataHandler5_CAN3[3]=u16Transformer_Temperature>>8;

	TxDataHandler5_CAN3[4]=u16FEC_Temperature;
	TxDataHandler5_CAN3[5]=u16FEC_Temperature>>8;

	TxDataHandler5_CAN3[6]=u16PSFB_Temperature;
	TxDataHandler5_CAN3[7]=u16PSFB_Temperature>>8;

	TxDataHandler5_CAN3[8]=u16DC_Busvoltage;
	TxDataHandler5_CAN3[9]=u16DC_Busvoltage>>8;

	TxDataHandler5_CAN3[10]=u16DC_Bus_Current;
	TxDataHandler5_CAN3[11]=u16DC_Bus_Current>>8;

	TxDataHandler5_CAN3[12]=u16FEC_input_Current;
	TxDataHandler5_CAN3[13]=u16FEC_input_Current>>8;

	TxDataHandler5_CAN3[14]=u16PSFB_Output_Voltage;
	TxDataHandler5_CAN3[15]=u16PSFB_Output_Voltage>>8;

	TxDataHandler5_CAN3[16]=u16PSFB_Output_Current;
	TxDataHandler5_CAN3[17]=u16PSFB_Output_Current>>8;

	TxDataHandler5_CAN3[18]=u16SFault1_2;
	TxDataHandler5_CAN3[19]=u16SFault1_2>>8;

	TxDataHandler5_CAN3[20]=u16SFault3_4;
	TxDataHandler5_CAN3[21]=u16SFault3_4>>8;

	TxDataHandler5_CAN3[22]=u16SFault5_6;
	TxDataHandler5_CAN3[23]=u16SFault5_6>>8;

	TxDataHandler5_CAN3[24]=u16SFault7_8;
	TxDataHandler5_CAN3[25]=u16SFault7_8>>8;

	TxDataHandler5_CAN3[26]=u16SStatus1_2;
	TxDataHandler5_CAN3[27]=u16SStatus1_2>>8;

	TxDataHandler5_CAN3[28]=u16SStatus3_4;
	TxDataHandler5_CAN3[29]=u16SStatus3_4>>8;

	TxDataHandler5_CAN3[30]=u16RSVD_1;
	TxDataHandler5_CAN3[31]=u16RSVD_1>>8;

	TxDataHandler5_CAN3[32]=u16RSVD_2;
	TxDataHandler5_CAN3[33]=u16RSVD_2>>8;

	TxDataHandler5_CAN3[34]=u16RSVD_3;
	TxDataHandler5_CAN3[35]=u16RSVD_3>>8;

	TxDataHandler5_CAN3[36]=u16RSVD_4;
	TxDataHandler5_CAN3[37]=u16RSVD_4>>8;

	TxDataHandler5_CAN3[38]=u16RSVD_5;
	TxDataHandler5_CAN3[39]=u16RSVD_5>>8;

	TxDataHandler5_CAN3[40]=u16RSVD_6;
	TxDataHandler5_CAN3[41]=u16RSVD_6>>8;

	TxDataHandler5_CAN3[42]=u16RSVD_7;
	TxDataHandler5_CAN3[43]=u16RSVD_7>>8;

	TxDataHandler5_CAN3[44]=u16RSVD_8;
	TxDataHandler5_CAN3[45]=u16RSVD_8>>8;

	TxDataHandler5_CAN3[46]=u16RSVD_9;
	TxDataHandler5_CAN3[47]=u16RSVD_9>>8;

	TxDataHandler5_CAN3[48]=u16RSVD_10;
	TxDataHandler5_CAN3[49]=u16RSVD_10>>8;

	TxDataHandler5_CAN3[50]=u16RSVD_11;
	TxDataHandler5_CAN3[51]=u16RSVD_11>>8;

	TxDataHandler5_CAN3[52]=u16RSVD_12;
	TxDataHandler5_CAN3[53]=u16RSVD_12>>8;

	TxDataHandler5_CAN3[54]=u16RSVD_13;
	TxDataHandler5_CAN3[55]=u16RSVD_13>>8;

	TxDataHandler5_CAN3[56]=u16RSVD_14;
	TxDataHandler5_CAN3[57]=u16RSVD_14>>8;

	TxDataHandler5_CAN3[58]=u16RSVD_15;
	TxDataHandler5_CAN3[59]=u16RSVD_15>>8;

	TxDataHandler5_CAN3[60]=u16RSVD_16;
	TxDataHandler5_CAN3[61]=u16RSVD_16>>8;

	TxDataHandler5_CAN3[62]=u16RSVD_17;
	TxDataHandler5_CAN3[63]=u16RSVD_17>>8;

	if (HAL_FDCAN_AddMessageToTxFifoQ(&hfdcan3, &TxHeader5_CAN3, TxDataHandler5_CAN3) != HAL_OK)
	{}
	else
	{}
	HAL_Delay(1);
}
//6
void Master_To_Monitor_Frame7_Slave6(float Diode_Temperature,float Transformer_Temperature,float FEC_Temperature,float PSFB_Temperature,float DC_Busvoltage,float DC_Bus_Current,float FEC_input_Current,float PSFB_Output_Voltage,
		float PSFB_Output_Current,uint16_t SFault1_2,uint16_t SFault3_4,uint16_t SFault5_6,uint16_t SFault7_8,uint16_t SStatus1_2,uint16_t SStatus3_4,uint16_t RSVD_1,
		uint16_t RSVD_2,uint16_t RSVD_3,uint16_t RSVD_4,uint16_t RSVD_5,uint16_t RSVD_6,uint16_t RSVD_7,uint16_t RSVD_8,uint16_t RSVD_9,
		uint16_t RSVD_10,uint16_t RSVD_11,uint16_t RSVD_12,uint16_t RSVD_13,uint16_t RSVD_14,uint16_t RSVD_15,uint16_t RSVD_16,uint16_t RSVD_17)
{

	uint16_t u16Diode_Temperature=(Diode_Temperature*MULTIFACTOR_10);
	uint16_t u16Transformer_Temperature=(Transformer_Temperature*MULTIFACTOR_10);
	uint16_t u16FEC_Temperature=(FEC_Temperature*MULTIFACTOR_10);

	uint16_t u16PSFB_Temperature=(PSFB_Temperature*MULTIFACTOR_10);
	uint16_t u16DC_Busvoltage=(DC_Busvoltage*MULTIFACTOR_10);
	uint16_t u16DC_Bus_Current=(DC_Bus_Current*MULTIFACTOR_10);

	uint16_t u16FEC_input_Current=(FEC_input_Current*MULTIFACTOR_10);
	uint16_t u16PSFB_Output_Voltage=(PSFB_Output_Voltage*MULTIFACTOR_10);
	uint16_t u16PSFB_Output_Current=(PSFB_Output_Current*MULTIFACTOR_10);

	uint16_t u16SFault1_2=(SFault1_2);
	uint16_t u16SFault3_4=(SFault3_4);
	uint16_t u16SFault5_6=(SFault5_6);
	uint16_t u16SFault7_8=(SFault7_8);

	uint16_t u16SStatus1_2=(SStatus1_2);
	uint16_t u16SStatus3_4=(SStatus3_4);

	uint16_t u16RSVD_1=(RSVD_1);
	uint16_t u16RSVD_2=(RSVD_2);
	uint16_t u16RSVD_3=(RSVD_3);
	uint16_t u16RSVD_4=(RSVD_4);
	uint16_t u16RSVD_5=(RSVD_5);
	uint16_t u16RSVD_6=(RSVD_6);
	uint16_t u16RSVD_7=(RSVD_7);
	uint16_t u16RSVD_8=(RSVD_8);
	uint16_t u16RSVD_9=(RSVD_9);
	uint16_t u16RSVD_10=(RSVD_10);
	uint16_t u16RSVD_11=(RSVD_11);
	uint16_t u16RSVD_12=(RSVD_12);
	uint16_t u16RSVD_13=(RSVD_13);
	uint16_t u16RSVD_14=(RSVD_14);
	uint16_t u16RSVD_15=(RSVD_15);
	uint16_t u16RSVD_16=(RSVD_16);
	uint16_t u16RSVD_17=(RSVD_17);


	TxDataHandler6_CAN3[0]=u16Diode_Temperature;
	TxDataHandler6_CAN3[1]=u16Diode_Temperature>>8;

	TxDataHandler6_CAN3[2]=u16Transformer_Temperature;
	TxDataHandler6_CAN3[3]=u16Transformer_Temperature>>8;

	TxDataHandler6_CAN3[4]=u16FEC_Temperature;
	TxDataHandler6_CAN3[5]=u16FEC_Temperature>>8;

	TxDataHandler6_CAN3[6]=u16PSFB_Temperature;
	TxDataHandler6_CAN3[7]=u16PSFB_Temperature>>8;

	TxDataHandler6_CAN3[8]=u16DC_Busvoltage;
	TxDataHandler6_CAN3[9]=u16DC_Busvoltage>>8;

	TxDataHandler6_CAN3[10]=u16DC_Bus_Current;
	TxDataHandler6_CAN3[11]=u16DC_Bus_Current>>8;

	TxDataHandler6_CAN3[12]=u16FEC_input_Current;
	TxDataHandler6_CAN3[13]=u16FEC_input_Current>>8;

	TxDataHandler6_CAN3[14]=u16PSFB_Output_Voltage;
	TxDataHandler6_CAN3[15]=u16PSFB_Output_Voltage>>8;

	TxDataHandler6_CAN3[16]=u16PSFB_Output_Current;
	TxDataHandler6_CAN3[17]=u16PSFB_Output_Current>>8;

	TxDataHandler6_CAN3[18]=u16SFault1_2;
	TxDataHandler6_CAN3[19]=u16SFault1_2>>8;

	TxDataHandler6_CAN3[20]=u16SFault3_4;
	TxDataHandler6_CAN3[21]=u16SFault3_4>>8;

	TxDataHandler6_CAN3[22]=u16SFault5_6;
	TxDataHandler6_CAN3[23]=u16SFault5_6>>8;

	TxDataHandler6_CAN3[24]=u16SFault7_8;
	TxDataHandler6_CAN3[25]=u16SFault7_8>>8;

	TxDataHandler6_CAN3[26]=u16SStatus1_2;
	TxDataHandler6_CAN3[27]=u16SStatus1_2>>8;

	TxDataHandler6_CAN3[28]=u16SStatus3_4;
	TxDataHandler6_CAN3[29]=u16SStatus3_4>>8;

	TxDataHandler6_CAN3[30]=u16RSVD_1;
	TxDataHandler6_CAN3[31]=u16RSVD_1>>8;

	TxDataHandler6_CAN3[32]=u16RSVD_2;
	TxDataHandler6_CAN3[33]=u16RSVD_2>>8;

	TxDataHandler6_CAN3[34]=u16RSVD_3;
	TxDataHandler6_CAN3[35]=u16RSVD_3>>8;

	TxDataHandler6_CAN3[36]=u16RSVD_4;
	TxDataHandler6_CAN3[37]=u16RSVD_4>>8;

	TxDataHandler6_CAN3[38]=u16RSVD_5;
	TxDataHandler6_CAN3[39]=u16RSVD_5>>8;

	TxDataHandler6_CAN3[40]=u16RSVD_6;
	TxDataHandler6_CAN3[41]=u16RSVD_6>>8;

	TxDataHandler6_CAN3[42]=u16RSVD_7;
	TxDataHandler6_CAN3[43]=u16RSVD_7>>8;

	TxDataHandler6_CAN3[44]=u16RSVD_8;
	TxDataHandler6_CAN3[45]=u16RSVD_8>>8;

	TxDataHandler6_CAN3[46]=u16RSVD_9;
	TxDataHandler6_CAN3[47]=u16RSVD_9>>8;

	TxDataHandler6_CAN3[48]=u16RSVD_10;
	TxDataHandler6_CAN3[49]=u16RSVD_10>>8;

	TxDataHandler6_CAN3[50]=u16RSVD_11;
	TxDataHandler6_CAN3[51]=u16RSVD_11>>8;

	TxDataHandler6_CAN3[52]=u16RSVD_12;
	TxDataHandler6_CAN3[53]=u16RSVD_12>>8;

	TxDataHandler6_CAN3[54]=u16RSVD_13;
	TxDataHandler6_CAN3[55]=u16RSVD_13>>8;

	TxDataHandler6_CAN3[56]=u16RSVD_14;
	TxDataHandler6_CAN3[57]=u16RSVD_14>>8;

	TxDataHandler6_CAN3[58]=u16RSVD_15;
	TxDataHandler6_CAN3[59]=u16RSVD_15>>8;

	TxDataHandler6_CAN3[60]=u16RSVD_16;
	TxDataHandler6_CAN3[61]=u16RSVD_16>>8;

	TxDataHandler6_CAN3[62]=u16RSVD_17;
	TxDataHandler6_CAN3[63]=u16RSVD_17>>8;

	if (HAL_FDCAN_AddMessageToTxFifoQ(&hfdcan3, &TxHeader6_CAN3, TxDataHandler6_CAN3) != HAL_OK)
	{}
	else
	{}
	HAL_Delay(1);
}
//7
void Master_To_Monitor_Frame8_Slave7(float Diode_Temperature,float Transformer_Temperature,float FEC_Temperature,float PSFB_Temperature,float DC_Busvoltage,float DC_Bus_Current,float FEC_input_Current,float PSFB_Output_Voltage,
		float PSFB_Output_Current,uint16_t SFault1_2,uint16_t SFault3_4,uint16_t SFault5_6,uint16_t SFault7_8,uint16_t SStatus1_2,uint16_t SStatus3_4,uint16_t RSVD_1,
		uint16_t RSVD_2,uint16_t RSVD_3,uint16_t RSVD_4,uint16_t RSVD_5,uint16_t RSVD_6,uint16_t RSVD_7,uint16_t RSVD_8,uint16_t RSVD_9,
		uint16_t RSVD_10,uint16_t RSVD_11,uint16_t RSVD_12,uint16_t RSVD_13,uint16_t RSVD_14,uint16_t RSVD_15,uint16_t RSVD_16,uint16_t RSVD_17)
{

	uint16_t u16Diode_Temperature=(Diode_Temperature*MULTIFACTOR_10);
	uint16_t u16Transformer_Temperature=(Transformer_Temperature*MULTIFACTOR_10);
	uint16_t u16FEC_Temperature=(FEC_Temperature*MULTIFACTOR_10);

	uint16_t u16PSFB_Temperature=(PSFB_Temperature*MULTIFACTOR_10);
	uint16_t u16DC_Busvoltage=(DC_Busvoltage*MULTIFACTOR_10);
	uint16_t u16DC_Bus_Current=(DC_Bus_Current*MULTIFACTOR_10);

	uint16_t u16FEC_input_Current=(FEC_input_Current*MULTIFACTOR_10);
	uint16_t u16PSFB_Output_Voltage=(PSFB_Output_Voltage*MULTIFACTOR_10);
	uint16_t u16PSFB_Output_Current=(PSFB_Output_Current*MULTIFACTOR_10);

	uint16_t u16SFault1_2=(SFault1_2);
	uint16_t u16SFault3_4=(SFault3_4);
	uint16_t u16SFault5_6=(SFault5_6);
	uint16_t u16SFault7_8=(SFault7_8);

	uint16_t u16SStatus1_2=(SStatus1_2);
	uint16_t u16SStatus3_4=(SStatus3_4);

	uint16_t u16RSVD_1=(RSVD_1);
	uint16_t u16RSVD_2=(RSVD_2);
	uint16_t u16RSVD_3=(RSVD_3);
	uint16_t u16RSVD_4=(RSVD_4);
	uint16_t u16RSVD_5=(RSVD_5);
	uint16_t u16RSVD_6=(RSVD_6);
	uint16_t u16RSVD_7=(RSVD_7);
	uint16_t u16RSVD_8=(RSVD_8);
	uint16_t u16RSVD_9=(RSVD_9);
	uint16_t u16RSVD_10=(RSVD_10);
	uint16_t u16RSVD_11=(RSVD_11);
	uint16_t u16RSVD_12=(RSVD_12);
	uint16_t u16RSVD_13=(RSVD_13);
	uint16_t u16RSVD_14=(RSVD_14);
	uint16_t u16RSVD_15=(RSVD_15);
	uint16_t u16RSVD_16=(RSVD_16);
	uint16_t u16RSVD_17=(RSVD_17);


	TxDataHandler7_CAN3[0]=u16Diode_Temperature;
	TxDataHandler7_CAN3[1]=u16Diode_Temperature>>8;

	TxDataHandler7_CAN3[2]=u16Transformer_Temperature;
	TxDataHandler7_CAN3[3]=u16Transformer_Temperature>>8;

	TxDataHandler7_CAN3[4]=u16FEC_Temperature;
	TxDataHandler7_CAN3[5]=u16FEC_Temperature>>8;

	TxDataHandler7_CAN3[6]=u16PSFB_Temperature;
	TxDataHandler7_CAN3[7]=u16PSFB_Temperature>>8;

	TxDataHandler7_CAN3[8]=u16DC_Busvoltage;
	TxDataHandler7_CAN3[9]=u16DC_Busvoltage>>8;

	TxDataHandler7_CAN3[10]=u16DC_Bus_Current;
	TxDataHandler7_CAN3[11]=u16DC_Bus_Current>>8;

	TxDataHandler7_CAN3[12]=u16FEC_input_Current;
	TxDataHandler7_CAN3[13]=u16FEC_input_Current>>8;

	TxDataHandler7_CAN3[14]=u16PSFB_Output_Voltage;
	TxDataHandler7_CAN3[15]=u16PSFB_Output_Voltage>>8;

	TxDataHandler7_CAN3[16]=u16PSFB_Output_Current;
	TxDataHandler7_CAN3[17]=u16PSFB_Output_Current>>8;

	TxDataHandler7_CAN3[18]=u16SFault1_2;
	TxDataHandler7_CAN3[19]=u16SFault1_2>>8;

	TxDataHandler7_CAN3[20]=u16SFault3_4;
	TxDataHandler7_CAN3[21]=u16SFault3_4>>8;

	TxDataHandler7_CAN3[22]=u16SFault5_6;
	TxDataHandler7_CAN3[23]=u16SFault5_6>>8;

	TxDataHandler7_CAN3[24]=u16SFault7_8;
	TxDataHandler7_CAN3[25]=u16SFault7_8>>8;

	TxDataHandler7_CAN3[26]=u16SStatus1_2;
	TxDataHandler7_CAN3[27]=u16SStatus1_2>>8;

	TxDataHandler7_CAN3[28]=u16SStatus3_4;
	TxDataHandler7_CAN3[29]=u16SStatus3_4>>8;

	TxDataHandler7_CAN3[30]=u16RSVD_1;
	TxDataHandler7_CAN3[31]=u16RSVD_1>>8;

	TxDataHandler7_CAN3[32]=u16RSVD_2;
	TxDataHandler7_CAN3[33]=u16RSVD_2>>8;

	TxDataHandler7_CAN3[34]=u16RSVD_3;
	TxDataHandler7_CAN3[35]=u16RSVD_3>>8;

	TxDataHandler7_CAN3[36]=u16RSVD_4;
	TxDataHandler7_CAN3[37]=u16RSVD_4>>8;

	TxDataHandler7_CAN3[38]=u16RSVD_5;
	TxDataHandler7_CAN3[39]=u16RSVD_5>>8;

	TxDataHandler7_CAN3[40]=u16RSVD_6;
	TxDataHandler7_CAN3[41]=u16RSVD_6>>8;

	TxDataHandler7_CAN3[42]=u16RSVD_7;
	TxDataHandler7_CAN3[43]=u16RSVD_7>>8;

	TxDataHandler7_CAN3[44]=u16RSVD_8;
	TxDataHandler7_CAN3[45]=u16RSVD_8>>8;

	TxDataHandler7_CAN3[46]=u16RSVD_9;
	TxDataHandler7_CAN3[47]=u16RSVD_9>>8;

	TxDataHandler7_CAN3[48]=u16RSVD_10;
	TxDataHandler7_CAN3[49]=u16RSVD_10>>8;

	TxDataHandler7_CAN3[50]=u16RSVD_11;
	TxDataHandler7_CAN3[51]=u16RSVD_11>>8;

	TxDataHandler7_CAN3[52]=u16RSVD_12;
	TxDataHandler7_CAN3[53]=u16RSVD_12>>8;

	TxDataHandler7_CAN3[54]=u16RSVD_13;
	TxDataHandler7_CAN3[55]=u16RSVD_13>>8;

	TxDataHandler7_CAN3[56]=u16RSVD_14;
	TxDataHandler7_CAN3[57]=u16RSVD_14>>8;

	TxDataHandler7_CAN3[58]=u16RSVD_15;
	TxDataHandler7_CAN3[59]=u16RSVD_15>>8;

	TxDataHandler7_CAN3[60]=u16RSVD_16;
	TxDataHandler7_CAN3[61]=u16RSVD_16>>8;

	TxDataHandler7_CAN3[62]=u16RSVD_17;
	TxDataHandler7_CAN3[63]=u16RSVD_17>>8;

	if (HAL_FDCAN_AddMessageToTxFifoQ(&hfdcan3, &TxHeader7_CAN3, TxDataHandler7_CAN3) != HAL_OK)
	{}
	else
	{}
	HAL_Delay(1);
}
//8
void Master_To_Monitor_Frame9_Slave8(float Diode_Temperature,float Transformer_Temperature,float FEC_Temperature,float PSFB_Temperature,float DC_Busvoltage,float DC_Bus_Current,float FEC_input_Current,float PSFB_Output_Voltage,
		float PSFB_Output_Current,uint16_t SFault1_2,uint16_t SFault3_4,uint16_t SFault5_6,uint16_t SFault7_8,uint16_t SStatus1_2,uint16_t SStatus3_4,uint16_t RSVD_1,
		uint16_t RSVD_2,uint16_t RSVD_3,uint16_t RSVD_4,uint16_t RSVD_5,uint16_t RSVD_6,uint16_t RSVD_7,uint16_t RSVD_8,uint16_t RSVD_9,
		uint16_t RSVD_10,uint16_t RSVD_11,uint16_t RSVD_12,uint16_t RSVD_13,uint16_t RSVD_14,uint16_t RSVD_15,uint16_t RSVD_16,uint16_t RSVD_17)
{

	uint16_t u16Diode_Temperature=(Diode_Temperature*MULTIFACTOR_10);
	uint16_t u16Transformer_Temperature=(Transformer_Temperature*MULTIFACTOR_10);
	uint16_t u16FEC_Temperature=(FEC_Temperature*MULTIFACTOR_10);

	uint16_t u16PSFB_Temperature=(PSFB_Temperature*MULTIFACTOR_10);
	uint16_t u16DC_Busvoltage=(DC_Busvoltage*MULTIFACTOR_10);
	uint16_t u16DC_Bus_Current=(DC_Bus_Current*MULTIFACTOR_10);

	uint16_t u16FEC_input_Current=(FEC_input_Current*MULTIFACTOR_10);
	uint16_t u16PSFB_Output_Voltage=(PSFB_Output_Voltage*MULTIFACTOR_10);
	uint16_t u16PSFB_Output_Current=(PSFB_Output_Current*MULTIFACTOR_10);

	uint16_t u16SFault1_2=(SFault1_2);
	uint16_t u16SFault3_4=(SFault3_4);
	uint16_t u16SFault5_6=(SFault5_6);
	uint16_t u16SFault7_8=(SFault7_8);

	uint16_t u16SStatus1_2=(SStatus1_2);
	uint16_t u16SStatus3_4=(SStatus3_4);

	uint16_t u16RSVD_1=(RSVD_1);
	uint16_t u16RSVD_2=(RSVD_2);
	uint16_t u16RSVD_3=(RSVD_3);
	uint16_t u16RSVD_4=(RSVD_4);
	uint16_t u16RSVD_5=(RSVD_5);
	uint16_t u16RSVD_6=(RSVD_6);
	uint16_t u16RSVD_7=(RSVD_7);
	uint16_t u16RSVD_8=(RSVD_8);
	uint16_t u16RSVD_9=(RSVD_9);
	uint16_t u16RSVD_10=(RSVD_10);
	uint16_t u16RSVD_11=(RSVD_11);
	uint16_t u16RSVD_12=(RSVD_12);
	uint16_t u16RSVD_13=(RSVD_13);
	uint16_t u16RSVD_14=(RSVD_14);
	uint16_t u16RSVD_15=(RSVD_15);
	uint16_t u16RSVD_16=(RSVD_16);
	uint16_t u16RSVD_17=(RSVD_17);


	TxDataHandler8_CAN3[0]=u16Diode_Temperature;
	TxDataHandler8_CAN3[1]=u16Diode_Temperature>>8;

	TxDataHandler8_CAN3[2]=u16Transformer_Temperature;
	TxDataHandler8_CAN3[3]=u16Transformer_Temperature>>8;

	TxDataHandler8_CAN3[4]=u16FEC_Temperature;
	TxDataHandler8_CAN3[5]=u16FEC_Temperature>>8;

	TxDataHandler8_CAN3[6]=u16PSFB_Temperature;
	TxDataHandler8_CAN3[7]=u16PSFB_Temperature>>8;

	TxDataHandler8_CAN3[8]=u16DC_Busvoltage;
	TxDataHandler8_CAN3[9]=u16DC_Busvoltage>>8;

	TxDataHandler8_CAN3[10]=u16DC_Bus_Current;
	TxDataHandler8_CAN3[11]=u16DC_Bus_Current>>8;

	TxDataHandler8_CAN3[12]=u16FEC_input_Current;
	TxDataHandler8_CAN3[13]=u16FEC_input_Current>>8;

	TxDataHandler8_CAN3[14]=u16PSFB_Output_Voltage;
	TxDataHandler8_CAN3[15]=u16PSFB_Output_Voltage>>8;

	TxDataHandler8_CAN3[16]=u16PSFB_Output_Current;
	TxDataHandler8_CAN3[17]=u16PSFB_Output_Current>>8;

	TxDataHandler8_CAN3[18]=u16SFault1_2;
	TxDataHandler8_CAN3[19]=u16SFault1_2>>8;

	TxDataHandler8_CAN3[20]=u16SFault3_4;
	TxDataHandler8_CAN3[21]=u16SFault3_4>>8;

	TxDataHandler8_CAN3[22]=u16SFault5_6;
	TxDataHandler8_CAN3[23]=u16SFault5_6>>8;

	TxDataHandler8_CAN3[24]=u16SFault7_8;
	TxDataHandler8_CAN3[25]=u16SFault7_8>>8;

	TxDataHandler8_CAN3[26]=u16SStatus1_2;
	TxDataHandler8_CAN3[27]=u16SStatus1_2>>8;

	TxDataHandler8_CAN3[28]=u16SStatus3_4;
	TxDataHandler8_CAN3[29]=u16SStatus3_4>>8;

	TxDataHandler8_CAN3[30]=u16RSVD_1;
	TxDataHandler8_CAN3[31]=u16RSVD_1>>8;

	TxDataHandler8_CAN3[32]=u16RSVD_2;
	TxDataHandler8_CAN3[33]=u16RSVD_2>>8;

	TxDataHandler8_CAN3[34]=u16RSVD_3;
	TxDataHandler8_CAN3[35]=u16RSVD_3>>8;

	TxDataHandler8_CAN3[36]=u16RSVD_4;
	TxDataHandler8_CAN3[37]=u16RSVD_4>>8;

	TxDataHandler8_CAN3[38]=u16RSVD_5;
	TxDataHandler8_CAN3[39]=u16RSVD_5>>8;

	TxDataHandler8_CAN3[40]=u16RSVD_6;
	TxDataHandler8_CAN3[41]=u16RSVD_6>>8;

	TxDataHandler8_CAN3[42]=u16RSVD_7;
	TxDataHandler8_CAN3[43]=u16RSVD_7>>8;

	TxDataHandler8_CAN3[44]=u16RSVD_8;
	TxDataHandler8_CAN3[45]=u16RSVD_8>>8;

	TxDataHandler8_CAN3[46]=u16RSVD_9;
	TxDataHandler8_CAN3[47]=u16RSVD_9>>8;

	TxDataHandler8_CAN3[48]=u16RSVD_10;
	TxDataHandler8_CAN3[49]=u16RSVD_10>>8;

	TxDataHandler8_CAN3[50]=u16RSVD_11;
	TxDataHandler8_CAN3[51]=u16RSVD_11>>8;

	TxDataHandler8_CAN3[52]=u16RSVD_12;
	TxDataHandler8_CAN3[53]=u16RSVD_12>>8;

	TxDataHandler8_CAN3[54]=u16RSVD_13;
	TxDataHandler8_CAN3[55]=u16RSVD_13>>8;

	TxDataHandler8_CAN3[56]=u16RSVD_14;
	TxDataHandler8_CAN3[57]=u16RSVD_14>>8;

	TxDataHandler8_CAN3[58]=u16RSVD_15;
	TxDataHandler8_CAN3[59]=u16RSVD_15>>8;

	TxDataHandler8_CAN3[60]=u16RSVD_16;
	TxDataHandler8_CAN3[61]=u16RSVD_16>>8;

	TxDataHandler8_CAN3[62]=u16RSVD_17;
	TxDataHandler8_CAN3[63]=u16RSVD_17>>8;

	if (HAL_FDCAN_AddMessageToTxFifoQ(&hfdcan3, &TxHeader8_CAN3, TxDataHandler8_CAN3) != HAL_OK)
	{}
	else
	{}
	HAL_Delay(1);
}
//9
void Master_To_Monitor_Frame10_Slave9(float Diode_Temperature,float Transformer_Temperature,float FEC_Temperature,float PSFB_Temperature,float DC_Busvoltage,float DC_Bus_Current,float FEC_input_Current,float PSFB_Output_Voltage,
		float PSFB_Output_Current,uint16_t SFault1_2,uint16_t SFault3_4,uint16_t SFault5_6,uint16_t SFault7_8,uint16_t SStatus1_2,uint16_t SStatus3_4,uint16_t RSVD_1,
		uint16_t RSVD_2,uint16_t RSVD_3,uint16_t RSVD_4,uint16_t RSVD_5,uint16_t RSVD_6,uint16_t RSVD_7,uint16_t RSVD_8,uint16_t RSVD_9,
		uint16_t RSVD_10,uint16_t RSVD_11,uint16_t RSVD_12,uint16_t RSVD_13,uint16_t RSVD_14,uint16_t RSVD_15,uint16_t RSVD_16,uint16_t RSVD_17)
{

	uint16_t u16Diode_Temperature=(Diode_Temperature*MULTIFACTOR_10);
	uint16_t u16Transformer_Temperature=(Transformer_Temperature*MULTIFACTOR_10);
	uint16_t u16FEC_Temperature=(FEC_Temperature*MULTIFACTOR_10);

	uint16_t u16PSFB_Temperature=(PSFB_Temperature*MULTIFACTOR_10);
	uint16_t u16DC_Busvoltage=(DC_Busvoltage*MULTIFACTOR_10);
	uint16_t u16DC_Bus_Current=(DC_Bus_Current*MULTIFACTOR_10);

	uint16_t u16FEC_input_Current=(FEC_input_Current*MULTIFACTOR_10);
	uint16_t u16PSFB_Output_Voltage=(PSFB_Output_Voltage*MULTIFACTOR_10);
	uint16_t u16PSFB_Output_Current=(PSFB_Output_Current*MULTIFACTOR_10);

	uint16_t u16SFault1_2=(SFault1_2);
	uint16_t u16SFault3_4=(SFault3_4);
	uint16_t u16SFault5_6=(SFault5_6);
	uint16_t u16SFault7_8=(SFault7_8);

	uint16_t u16SStatus1_2=(SStatus1_2);
	uint16_t u16SStatus3_4=(SStatus3_4);

	uint16_t u16RSVD_1=(RSVD_1);
	uint16_t u16RSVD_2=(RSVD_2);
	uint16_t u16RSVD_3=(RSVD_3);
	uint16_t u16RSVD_4=(RSVD_4);
	uint16_t u16RSVD_5=(RSVD_5);
	uint16_t u16RSVD_6=(RSVD_6);
	uint16_t u16RSVD_7=(RSVD_7);
	uint16_t u16RSVD_8=(RSVD_8);
	uint16_t u16RSVD_9=(RSVD_9);
	uint16_t u16RSVD_10=(RSVD_10);
	uint16_t u16RSVD_11=(RSVD_11);
	uint16_t u16RSVD_12=(RSVD_12);
	uint16_t u16RSVD_13=(RSVD_13);
	uint16_t u16RSVD_14=(RSVD_14);
	uint16_t u16RSVD_15=(RSVD_15);
	uint16_t u16RSVD_16=(RSVD_16);
	uint16_t u16RSVD_17=(RSVD_17);


	TxDataHandler9_CAN3[0]=u16Diode_Temperature;
	TxDataHandler9_CAN3[1]=u16Diode_Temperature>>8;

	TxDataHandler9_CAN3[2]=u16Transformer_Temperature;
	TxDataHandler9_CAN3[3]=u16Transformer_Temperature>>8;

	TxDataHandler9_CAN3[4]=u16FEC_Temperature;
	TxDataHandler9_CAN3[5]=u16FEC_Temperature>>8;

	TxDataHandler9_CAN3[6]=u16PSFB_Temperature;
	TxDataHandler9_CAN3[7]=u16PSFB_Temperature>>8;

	TxDataHandler9_CAN3[8]=u16DC_Busvoltage;
	TxDataHandler9_CAN3[9]=u16DC_Busvoltage>>8;

	TxDataHandler9_CAN3[10]=u16DC_Bus_Current;
	TxDataHandler9_CAN3[11]=u16DC_Bus_Current>>8;

	TxDataHandler9_CAN3[12]=u16FEC_input_Current;
	TxDataHandler9_CAN3[13]=u16FEC_input_Current>>8;

	TxDataHandler9_CAN3[14]=u16PSFB_Output_Voltage;
	TxDataHandler9_CAN3[15]=u16PSFB_Output_Voltage>>8;

	TxDataHandler9_CAN3[16]=u16PSFB_Output_Current;
	TxDataHandler9_CAN3[17]=u16PSFB_Output_Current>>8;

	TxDataHandler9_CAN3[18]=u16SFault1_2;
	TxDataHandler9_CAN3[19]=u16SFault1_2>>8;

	TxDataHandler9_CAN3[20]=u16SFault3_4;
	TxDataHandler9_CAN3[21]=u16SFault3_4>>8;

	TxDataHandler9_CAN3[22]=u16SFault5_6;
	TxDataHandler9_CAN3[23]=u16SFault5_6>>8;

	TxDataHandler9_CAN3[24]=u16SFault7_8;
	TxDataHandler9_CAN3[25]=u16SFault7_8>>8;

	TxDataHandler9_CAN3[26]=u16SStatus1_2;
	TxDataHandler9_CAN3[27]=u16SStatus1_2>>8;

	TxDataHandler9_CAN3[28]=u16SStatus3_4;
	TxDataHandler9_CAN3[29]=u16SStatus3_4>>8;

	TxDataHandler9_CAN3[30]=u16RSVD_1;
	TxDataHandler9_CAN3[31]=u16RSVD_1>>8;

	TxDataHandler9_CAN3[32]=u16RSVD_2;
	TxDataHandler9_CAN3[33]=u16RSVD_2>>8;

	TxDataHandler9_CAN3[34]=u16RSVD_3;
	TxDataHandler9_CAN3[35]=u16RSVD_3>>8;

	TxDataHandler9_CAN3[36]=u16RSVD_4;
	TxDataHandler9_CAN3[37]=u16RSVD_4>>8;

	TxDataHandler9_CAN3[38]=u16RSVD_5;
	TxDataHandler9_CAN3[39]=u16RSVD_5>>8;

	TxDataHandler9_CAN3[40]=u16RSVD_6;
	TxDataHandler9_CAN3[41]=u16RSVD_6>>8;

	TxDataHandler9_CAN3[42]=u16RSVD_7;
	TxDataHandler9_CAN3[43]=u16RSVD_7>>8;

	TxDataHandler9_CAN3[44]=u16RSVD_8;
	TxDataHandler9_CAN3[45]=u16RSVD_8>>8;

	TxDataHandler9_CAN3[46]=u16RSVD_9;
	TxDataHandler9_CAN3[47]=u16RSVD_9>>8;

	TxDataHandler9_CAN3[48]=u16RSVD_10;
	TxDataHandler9_CAN3[49]=u16RSVD_10>>8;

	TxDataHandler9_CAN3[50]=u16RSVD_11;
	TxDataHandler9_CAN3[51]=u16RSVD_11>>8;

	TxDataHandler9_CAN3[52]=u16RSVD_12;
	TxDataHandler9_CAN3[53]=u16RSVD_12>>8;

	TxDataHandler9_CAN3[54]=u16RSVD_13;
	TxDataHandler9_CAN3[55]=u16RSVD_13>>8;

	TxDataHandler9_CAN3[56]=u16RSVD_14;
	TxDataHandler9_CAN3[57]=u16RSVD_14>>8;

	TxDataHandler9_CAN3[58]=u16RSVD_15;
	TxDataHandler9_CAN3[59]=u16RSVD_15>>8;

	TxDataHandler9_CAN3[60]=u16RSVD_16;
	TxDataHandler9_CAN3[61]=u16RSVD_16>>8;

	TxDataHandler9_CAN3[62]=u16RSVD_17;
	TxDataHandler9_CAN3[63]=u16RSVD_17>>8;

	if (HAL_FDCAN_AddMessageToTxFifoQ(&hfdcan3, &TxHeader9_CAN3, TxDataHandler9_CAN3) != HAL_OK)
	{}
	else
	{}
	HAL_Delay(1);
}
//10
void Master_To_Monitor_Frame11_Slave10(float Diode_Temperature,float Transformer_Temperature,float FEC_Temperature,float PSFB_Temperature,float DC_Busvoltage,float DC_Bus_Current,float FEC_input_Current,float PSFB_Output_Voltage,
		float PSFB_Output_Current,uint16_t SFault1_2,uint16_t SFault3_4,uint16_t SFault5_6,uint16_t SFault7_8,uint16_t SStatus1_2,uint16_t SStatus3_4,uint16_t RSVD_1,
		uint16_t RSVD_2,uint16_t RSVD_3,uint16_t RSVD_4,uint16_t RSVD_5,uint16_t RSVD_6,uint16_t RSVD_7,uint16_t RSVD_8,uint16_t RSVD_9,
		uint16_t RSVD_10,uint16_t RSVD_11,uint16_t RSVD_12,uint16_t RSVD_13,uint16_t RSVD_14,uint16_t RSVD_15,uint16_t RSVD_16,uint16_t RSVD_17)
{

	uint16_t u16Diode_Temperature=(Diode_Temperature*MULTIFACTOR_10);
	uint16_t u16Transformer_Temperature=(Transformer_Temperature*MULTIFACTOR_10);
	uint16_t u16FEC_Temperature=(FEC_Temperature*MULTIFACTOR_10);

	uint16_t u16PSFB_Temperature=(PSFB_Temperature*MULTIFACTOR_10);
	uint16_t u16DC_Busvoltage=(DC_Busvoltage*MULTIFACTOR_10);
	uint16_t u16DC_Bus_Current=(DC_Bus_Current*MULTIFACTOR_10);

	uint16_t u16FEC_input_Current=(FEC_input_Current*MULTIFACTOR_10);
	uint16_t u16PSFB_Output_Voltage=(PSFB_Output_Voltage*MULTIFACTOR_10);
	uint16_t u16PSFB_Output_Current=(PSFB_Output_Current*MULTIFACTOR_10);

	uint16_t u16SFault1_2=(SFault1_2);
	uint16_t u16SFault3_4=(SFault3_4);
	uint16_t u16SFault5_6=(SFault5_6);
	uint16_t u16SFault7_8=(SFault7_8);

	uint16_t u16SStatus1_2=(SStatus1_2);
	uint16_t u16SStatus3_4=(SStatus3_4);

	uint16_t u16RSVD_1=(RSVD_1);
	uint16_t u16RSVD_2=(RSVD_2);
	uint16_t u16RSVD_3=(RSVD_3);
	uint16_t u16RSVD_4=(RSVD_4);
	uint16_t u16RSVD_5=(RSVD_5);
	uint16_t u16RSVD_6=(RSVD_6);
	uint16_t u16RSVD_7=(RSVD_7);
	uint16_t u16RSVD_8=(RSVD_8);
	uint16_t u16RSVD_9=(RSVD_9);
	uint16_t u16RSVD_10=(RSVD_10);
	uint16_t u16RSVD_11=(RSVD_11);
	uint16_t u16RSVD_12=(RSVD_12);
	uint16_t u16RSVD_13=(RSVD_13);
	uint16_t u16RSVD_14=(RSVD_14);
	uint16_t u16RSVD_15=(RSVD_15);
	uint16_t u16RSVD_16=(RSVD_16);
	uint16_t u16RSVD_17=(RSVD_17);


	TxDataHandler10_CAN3[0]=u16Diode_Temperature;
	TxDataHandler10_CAN3[1]=u16Diode_Temperature>>8;

	TxDataHandler10_CAN3[2]=u16Transformer_Temperature;
	TxDataHandler10_CAN3[3]=u16Transformer_Temperature>>8;

	TxDataHandler10_CAN3[4]=u16FEC_Temperature;
	TxDataHandler10_CAN3[5]=u16FEC_Temperature>>8;

	TxDataHandler10_CAN3[6]=u16PSFB_Temperature;
	TxDataHandler10_CAN3[7]=u16PSFB_Temperature>>8;

	TxDataHandler10_CAN3[8]=u16DC_Busvoltage;
	TxDataHandler10_CAN3[9]=u16DC_Busvoltage>>8;

	TxDataHandler10_CAN3[10]=u16DC_Bus_Current;
	TxDataHandler10_CAN3[11]=u16DC_Bus_Current>>8;

	TxDataHandler10_CAN3[12]=u16FEC_input_Current;
	TxDataHandler10_CAN3[13]=u16FEC_input_Current>>8;

	TxDataHandler10_CAN3[14]=u16PSFB_Output_Voltage;
	TxDataHandler10_CAN3[15]=u16PSFB_Output_Voltage>>8;

	TxDataHandler10_CAN3[16]=u16PSFB_Output_Current;
	TxDataHandler10_CAN3[17]=u16PSFB_Output_Current>>8;

	TxDataHandler10_CAN3[18]=u16SFault1_2;
	TxDataHandler10_CAN3[19]=u16SFault1_2>>8;

	TxDataHandler10_CAN3[20]=u16SFault3_4;
	TxDataHandler10_CAN3[21]=u16SFault3_4>>8;

	TxDataHandler10_CAN3[22]=u16SFault5_6;
	TxDataHandler10_CAN3[23]=u16SFault5_6>>8;

	TxDataHandler10_CAN3[24]=u16SFault7_8;
	TxDataHandler10_CAN3[25]=u16SFault7_8>>8;

	TxDataHandler10_CAN3[26]=u16SStatus1_2;
	TxDataHandler10_CAN3[27]=u16SStatus1_2>>8;

	TxDataHandler10_CAN3[28]=u16SStatus3_4;
	TxDataHandler10_CAN3[29]=u16SStatus3_4>>8;

	TxDataHandler10_CAN3[30]=u16RSVD_1;
	TxDataHandler10_CAN3[31]=u16RSVD_1>>8;

	TxDataHandler10_CAN3[32]=u16RSVD_2;
	TxDataHandler10_CAN3[33]=u16RSVD_2>>8;

	TxDataHandler10_CAN3[34]=u16RSVD_3;
	TxDataHandler10_CAN3[35]=u16RSVD_3>>8;

	TxDataHandler10_CAN3[36]=u16RSVD_4;
	TxDataHandler10_CAN3[37]=u16RSVD_4>>8;

	TxDataHandler10_CAN3[38]=u16RSVD_5;
	TxDataHandler10_CAN3[39]=u16RSVD_5>>8;

	TxDataHandler10_CAN3[40]=u16RSVD_6;
	TxDataHandler10_CAN3[41]=u16RSVD_6>>8;

	TxDataHandler10_CAN3[42]=u16RSVD_7;
	TxDataHandler10_CAN3[43]=u16RSVD_7>>8;

	TxDataHandler10_CAN3[44]=u16RSVD_8;
	TxDataHandler10_CAN3[45]=u16RSVD_8>>8;

	TxDataHandler10_CAN3[46]=u16RSVD_9;
	TxDataHandler10_CAN3[47]=u16RSVD_9>>8;

	TxDataHandler10_CAN3[48]=u16RSVD_10;
	TxDataHandler10_CAN3[49]=u16RSVD_10>>8;

	TxDataHandler10_CAN3[50]=u16RSVD_11;
	TxDataHandler10_CAN3[51]=u16RSVD_11>>8;

	TxDataHandler10_CAN3[52]=u16RSVD_12;
	TxDataHandler10_CAN3[53]=u16RSVD_12>>8;

	TxDataHandler10_CAN3[54]=u16RSVD_13;
	TxDataHandler10_CAN3[55]=u16RSVD_13>>8;

	TxDataHandler10_CAN3[56]=u16RSVD_14;
	TxDataHandler10_CAN3[57]=u16RSVD_14>>8;

	TxDataHandler10_CAN3[58]=u16RSVD_15;
	TxDataHandler10_CAN3[59]=u16RSVD_15>>8;

	TxDataHandler10_CAN3[60]=u16RSVD_16;
	TxDataHandler10_CAN3[61]=u16RSVD_16>>8;

	TxDataHandler10_CAN3[62]=u16RSVD_17;
	TxDataHandler10_CAN3[63]=u16RSVD_17>>8;

	if (HAL_FDCAN_AddMessageToTxFifoQ(&hfdcan3, &TxHeader10_CAN3, TxDataHandler10_CAN3) != HAL_OK)
	{}
	else
	{}
	HAL_Delay(1);
}
//11
void Master_To_Monitor_Frame12_Slave11(float Diode_Temperature,float Transformer_Temperature,float FEC_Temperature,float PSFB_Temperature,float DC_Busvoltage,float DC_Bus_Current,float FEC_input_Current,float PSFB_Output_Voltage,
		float PSFB_Output_Current,uint16_t SFault1_2,uint16_t SFault3_4,uint16_t SFault5_6,uint16_t SFault7_8,uint16_t SStatus1_2,uint16_t SStatus3_4,uint16_t RSVD_1,
		uint16_t RSVD_2,uint16_t RSVD_3,uint16_t RSVD_4,uint16_t RSVD_5,uint16_t RSVD_6,uint16_t RSVD_7,uint16_t RSVD_8,uint16_t RSVD_9,
		uint16_t RSVD_10,uint16_t RSVD_11,uint16_t RSVD_12,uint16_t RSVD_13,uint16_t RSVD_14,uint16_t RSVD_15,uint16_t RSVD_16,uint16_t RSVD_17)
{

	uint16_t u16Diode_Temperature=(Diode_Temperature*MULTIFACTOR_10);
	uint16_t u16Transformer_Temperature=(Transformer_Temperature*MULTIFACTOR_10);
	uint16_t u16FEC_Temperature=(FEC_Temperature*MULTIFACTOR_10);

	uint16_t u16PSFB_Temperature=(PSFB_Temperature*MULTIFACTOR_10);
	uint16_t u16DC_Busvoltage=(DC_Busvoltage*MULTIFACTOR_10);
	uint16_t u16DC_Bus_Current=(DC_Bus_Current*MULTIFACTOR_10);

	uint16_t u16FEC_input_Current=(FEC_input_Current*MULTIFACTOR_10);
	uint16_t u16PSFB_Output_Voltage=(PSFB_Output_Voltage*MULTIFACTOR_10);
	uint16_t u16PSFB_Output_Current=(PSFB_Output_Current*MULTIFACTOR_10);

	uint16_t u16SFault1_2=(SFault1_2);
	uint16_t u16SFault3_4=(SFault3_4);
	uint16_t u16SFault5_6=(SFault5_6);
	uint16_t u16SFault7_8=(SFault7_8);

	uint16_t u16SStatus1_2=(SStatus1_2);
	uint16_t u16SStatus3_4=(SStatus3_4);

	uint16_t u16RSVD_1=(RSVD_1);
	uint16_t u16RSVD_2=(RSVD_2);
	uint16_t u16RSVD_3=(RSVD_3);
	uint16_t u16RSVD_4=(RSVD_4);
	uint16_t u16RSVD_5=(RSVD_5);
	uint16_t u16RSVD_6=(RSVD_6);
	uint16_t u16RSVD_7=(RSVD_7);
	uint16_t u16RSVD_8=(RSVD_8);
	uint16_t u16RSVD_9=(RSVD_9);
	uint16_t u16RSVD_10=(RSVD_10);
	uint16_t u16RSVD_11=(RSVD_11);
	uint16_t u16RSVD_12=(RSVD_12);
	uint16_t u16RSVD_13=(RSVD_13);
	uint16_t u16RSVD_14=(RSVD_14);
	uint16_t u16RSVD_15=(RSVD_15);
	uint16_t u16RSVD_16=(RSVD_16);
	uint16_t u16RSVD_17=(RSVD_17);


	TxDataHandler11_CAN3[0]=u16Diode_Temperature;
	TxDataHandler11_CAN3[1]=u16Diode_Temperature>>8;

	TxDataHandler11_CAN3[2]=u16Transformer_Temperature;
	TxDataHandler11_CAN3[3]=u16Transformer_Temperature>>8;

	TxDataHandler11_CAN3[4]=u16FEC_Temperature;
	TxDataHandler11_CAN3[5]=u16FEC_Temperature>>8;

	TxDataHandler11_CAN3[6]=u16PSFB_Temperature;
	TxDataHandler11_CAN3[7]=u16PSFB_Temperature>>8;

	TxDataHandler11_CAN3[8]=u16DC_Busvoltage;
	TxDataHandler11_CAN3[9]=u16DC_Busvoltage>>8;

	TxDataHandler11_CAN3[10]=u16DC_Bus_Current;
	TxDataHandler11_CAN3[11]=u16DC_Bus_Current>>8;

	TxDataHandler11_CAN3[12]=u16FEC_input_Current;
	TxDataHandler11_CAN3[13]=u16FEC_input_Current>>8;

	TxDataHandler11_CAN3[14]=u16PSFB_Output_Voltage;
	TxDataHandler11_CAN3[15]=u16PSFB_Output_Voltage>>8;

	TxDataHandler11_CAN3[16]=u16PSFB_Output_Current;
	TxDataHandler11_CAN3[17]=u16PSFB_Output_Current>>8;

	TxDataHandler11_CAN3[18]=u16SFault1_2;
	TxDataHandler11_CAN3[19]=u16SFault1_2>>8;

	TxDataHandler11_CAN3[20]=u16SFault3_4;
	TxDataHandler11_CAN3[21]=u16SFault3_4>>8;

	TxDataHandler11_CAN3[22]=u16SFault5_6;
	TxDataHandler11_CAN3[23]=u16SFault5_6>>8;

	TxDataHandler11_CAN3[24]=u16SFault7_8;
	TxDataHandler11_CAN3[25]=u16SFault7_8>>8;

	TxDataHandler11_CAN3[26]=u16SStatus1_2;
	TxDataHandler11_CAN3[27]=u16SStatus1_2>>8;

	TxDataHandler11_CAN3[28]=u16SStatus3_4;
	TxDataHandler11_CAN3[29]=u16SStatus3_4>>8;

	TxDataHandler11_CAN3[30]=u16RSVD_1;
	TxDataHandler11_CAN3[31]=u16RSVD_1>>8;

	TxDataHandler11_CAN3[32]=u16RSVD_2;
	TxDataHandler11_CAN3[33]=u16RSVD_2>>8;

	TxDataHandler11_CAN3[34]=u16RSVD_3;
	TxDataHandler11_CAN3[35]=u16RSVD_3>>8;

	TxDataHandler11_CAN3[36]=u16RSVD_4;
	TxDataHandler11_CAN3[37]=u16RSVD_4>>8;

	TxDataHandler11_CAN3[38]=u16RSVD_5;
	TxDataHandler11_CAN3[39]=u16RSVD_5>>8;

	TxDataHandler11_CAN3[40]=u16RSVD_6;
	TxDataHandler11_CAN3[41]=u16RSVD_6>>8;

	TxDataHandler11_CAN3[42]=u16RSVD_7;
	TxDataHandler11_CAN3[43]=u16RSVD_7>>8;

	TxDataHandler11_CAN3[44]=u16RSVD_8;
	TxDataHandler11_CAN3[45]=u16RSVD_8>>8;

	TxDataHandler11_CAN3[46]=u16RSVD_9;
	TxDataHandler11_CAN3[47]=u16RSVD_9>>8;

	TxDataHandler11_CAN3[48]=u16RSVD_10;
	TxDataHandler11_CAN3[49]=u16RSVD_10>>8;

	TxDataHandler11_CAN3[50]=u16RSVD_11;
	TxDataHandler11_CAN3[51]=u16RSVD_11>>8;

	TxDataHandler11_CAN3[52]=u16RSVD_12;
	TxDataHandler11_CAN3[53]=u16RSVD_12>>8;

	TxDataHandler11_CAN3[54]=u16RSVD_13;
	TxDataHandler11_CAN3[55]=u16RSVD_13>>8;

	TxDataHandler11_CAN3[56]=u16RSVD_14;
	TxDataHandler11_CAN3[57]=u16RSVD_14>>8;

	TxDataHandler11_CAN3[58]=u16RSVD_15;
	TxDataHandler11_CAN3[59]=u16RSVD_15>>8;

	TxDataHandler11_CAN3[60]=u16RSVD_16;
	TxDataHandler11_CAN3[61]=u16RSVD_16>>8;

	TxDataHandler11_CAN3[62]=u16RSVD_17;
	TxDataHandler11_CAN3[63]=u16RSVD_17>>8;

	if (HAL_FDCAN_AddMessageToTxFifoQ(&hfdcan3, &TxHeader11_CAN3, TxDataHandler11_CAN3) != HAL_OK)
	{}
	else
	{}
	HAL_Delay(1);
}
//12
void Master_To_Monitor_Frame13_Slave12(float Diode_Temperature,float Transformer_Temperature,float FEC_Temperature,float PSFB_Temperature,float DC_Busvoltage,float DC_Bus_Current,float FEC_input_Current,float PSFB_Output_Voltage,
		float PSFB_Output_Current,uint16_t SFault1_2,uint16_t SFault3_4,uint16_t SFault5_6,uint16_t SFault7_8,uint16_t SStatus1_2,uint16_t SStatus3_4,uint16_t RSVD_1,
		uint16_t RSVD_2,uint16_t RSVD_3,uint16_t RSVD_4,uint16_t RSVD_5,uint16_t RSVD_6,uint16_t RSVD_7,uint16_t RSVD_8,uint16_t RSVD_9,
		uint16_t RSVD_10,uint16_t RSVD_11,uint16_t RSVD_12,uint16_t RSVD_13,uint16_t RSVD_14,uint16_t RSVD_15,uint16_t RSVD_16,uint16_t RSVD_17)
{

	uint16_t u16Diode_Temperature=(Diode_Temperature*MULTIFACTOR_10);
	uint16_t u16Transformer_Temperature=(Transformer_Temperature*MULTIFACTOR_10);
	uint16_t u16FEC_Temperature=(FEC_Temperature*MULTIFACTOR_10);

	uint16_t u16PSFB_Temperature=(PSFB_Temperature*MULTIFACTOR_10);
	uint16_t u16DC_Busvoltage=(DC_Busvoltage*MULTIFACTOR_10);
	uint16_t u16DC_Bus_Current=(DC_Bus_Current*MULTIFACTOR_10);

	uint16_t u16FEC_input_Current=(FEC_input_Current*MULTIFACTOR_10);
	uint16_t u16PSFB_Output_Voltage=(PSFB_Output_Voltage*MULTIFACTOR_10);
	uint16_t u16PSFB_Output_Current=(PSFB_Output_Current*MULTIFACTOR_10);

	uint16_t u16SFault1_2=(SFault1_2);
	uint16_t u16SFault3_4=(SFault3_4);
	uint16_t u16SFault5_6=(SFault5_6);
	uint16_t u16SFault7_8=(SFault7_8);

	uint16_t u16SStatus1_2=(SStatus1_2);
	uint16_t u16SStatus3_4=(SStatus3_4);

	uint16_t u16RSVD_1=(RSVD_1);
	uint16_t u16RSVD_2=(RSVD_2);
	uint16_t u16RSVD_3=(RSVD_3);
	uint16_t u16RSVD_4=(RSVD_4);
	uint16_t u16RSVD_5=(RSVD_5);
	uint16_t u16RSVD_6=(RSVD_6);
	uint16_t u16RSVD_7=(RSVD_7);
	uint16_t u16RSVD_8=(RSVD_8);
	uint16_t u16RSVD_9=(RSVD_9);
	uint16_t u16RSVD_10=(RSVD_10);
	uint16_t u16RSVD_11=(RSVD_11);
	uint16_t u16RSVD_12=(RSVD_12);
	uint16_t u16RSVD_13=(RSVD_13);
	uint16_t u16RSVD_14=(RSVD_14);
	uint16_t u16RSVD_15=(RSVD_15);
	uint16_t u16RSVD_16=(RSVD_16);
	uint16_t u16RSVD_17=(RSVD_17);


	TxDataHandler12_CAN3[0]=u16Diode_Temperature;
	TxDataHandler12_CAN3[1]=u16Diode_Temperature>>8;

	TxDataHandler12_CAN3[2]=u16Transformer_Temperature;
	TxDataHandler12_CAN3[3]=u16Transformer_Temperature>>8;

	TxDataHandler12_CAN3[4]=u16FEC_Temperature;
	TxDataHandler12_CAN3[5]=u16FEC_Temperature>>8;

	TxDataHandler12_CAN3[6]=u16PSFB_Temperature;
	TxDataHandler12_CAN3[7]=u16PSFB_Temperature>>8;

	TxDataHandler12_CAN3[8]=u16DC_Busvoltage;
	TxDataHandler12_CAN3[9]=u16DC_Busvoltage>>8;

	TxDataHandler12_CAN3[10]=u16DC_Bus_Current;
	TxDataHandler12_CAN3[11]=u16DC_Bus_Current>>8;

	TxDataHandler12_CAN3[12]=u16FEC_input_Current;
	TxDataHandler12_CAN3[13]=u16FEC_input_Current>>8;

	TxDataHandler12_CAN3[14]=u16PSFB_Output_Voltage;
	TxDataHandler12_CAN3[15]=u16PSFB_Output_Voltage>>8;

	TxDataHandler12_CAN3[16]=u16PSFB_Output_Current;
	TxDataHandler12_CAN3[17]=u16PSFB_Output_Current>>8;

	TxDataHandler12_CAN3[18]=u16SFault1_2;
	TxDataHandler12_CAN3[19]=u16SFault1_2>>8;

	TxDataHandler12_CAN3[20]=u16SFault3_4;
	TxDataHandler12_CAN3[21]=u16SFault3_4>>8;

	TxDataHandler12_CAN3[22]=u16SFault5_6;
	TxDataHandler12_CAN3[23]=u16SFault5_6>>8;

	TxDataHandler12_CAN3[24]=u16SFault7_8;
	TxDataHandler12_CAN3[25]=u16SFault7_8>>8;

	TxDataHandler12_CAN3[26]=u16SStatus1_2;
	TxDataHandler12_CAN3[27]=u16SStatus1_2>>8;

	TxDataHandler12_CAN3[28]=u16SStatus3_4;
	TxDataHandler12_CAN3[29]=u16SStatus3_4>>8;

	TxDataHandler12_CAN3[30]=u16RSVD_1;
	TxDataHandler12_CAN3[31]=u16RSVD_1>>8;

	TxDataHandler12_CAN3[32]=u16RSVD_2;
	TxDataHandler12_CAN3[33]=u16RSVD_2>>8;

	TxDataHandler12_CAN3[34]=u16RSVD_3;
	TxDataHandler12_CAN3[35]=u16RSVD_3>>8;

	TxDataHandler12_CAN3[36]=u16RSVD_4;
	TxDataHandler12_CAN3[37]=u16RSVD_4>>8;

	TxDataHandler12_CAN3[38]=u16RSVD_5;
	TxDataHandler12_CAN3[39]=u16RSVD_5>>8;

	TxDataHandler12_CAN3[40]=u16RSVD_6;
	TxDataHandler12_CAN3[41]=u16RSVD_6>>8;

	TxDataHandler12_CAN3[42]=u16RSVD_7;
	TxDataHandler12_CAN3[43]=u16RSVD_7>>8;

	TxDataHandler12_CAN3[44]=u16RSVD_8;
	TxDataHandler12_CAN3[45]=u16RSVD_8>>8;

	TxDataHandler12_CAN3[46]=u16RSVD_9;
	TxDataHandler12_CAN3[47]=u16RSVD_9>>8;

	TxDataHandler12_CAN3[48]=u16RSVD_10;
	TxDataHandler12_CAN3[49]=u16RSVD_10>>8;

	TxDataHandler12_CAN3[50]=u16RSVD_11;
	TxDataHandler12_CAN3[51]=u16RSVD_11>>8;

	TxDataHandler12_CAN3[52]=u16RSVD_12;
	TxDataHandler12_CAN3[53]=u16RSVD_12>>8;

	TxDataHandler12_CAN3[54]=u16RSVD_13;
	TxDataHandler12_CAN3[55]=u16RSVD_13>>8;

	TxDataHandler12_CAN3[56]=u16RSVD_14;
	TxDataHandler12_CAN3[57]=u16RSVD_14>>8;

	TxDataHandler12_CAN3[58]=u16RSVD_15;
	TxDataHandler12_CAN3[59]=u16RSVD_15>>8;

	TxDataHandler12_CAN3[60]=u16RSVD_16;
	TxDataHandler12_CAN3[61]=u16RSVD_16>>8;

	TxDataHandler12_CAN3[62]=u16RSVD_17;
	TxDataHandler12_CAN3[63]=u16RSVD_17>>8;

	if (HAL_FDCAN_AddMessageToTxFifoQ(&hfdcan3, &TxHeader12_CAN3, TxDataHandler12_CAN3) != HAL_OK)
	{}
	else
	{}
	HAL_Delay(1);
}
//13
void Master_To_Monitor_Frame14_Slave13(float Diode_Temperature,float Transformer_Temperature,float FEC_Temperature,float PSFB_Temperature,float DC_Busvoltage,float DC_Bus_Current,float FEC_input_Current,float PSFB_Output_Voltage,
		float PSFB_Output_Current,uint16_t SFault1_2,uint16_t SFault3_4,uint16_t SFault5_6,uint16_t SFault7_8,uint16_t SStatus1_2,uint16_t SStatus3_4,uint16_t RSVD_1,
		uint16_t RSVD_2,uint16_t RSVD_3,uint16_t RSVD_4,uint16_t RSVD_5,uint16_t RSVD_6,uint16_t RSVD_7,uint16_t RSVD_8,uint16_t RSVD_9,
		uint16_t RSVD_10,uint16_t RSVD_11,uint16_t RSVD_12,uint16_t RSVD_13,uint16_t RSVD_14,uint16_t RSVD_15,uint16_t RSVD_16,uint16_t RSVD_17)
{

	uint16_t u16Diode_Temperature=(Diode_Temperature*MULTIFACTOR_10);
	uint16_t u16Transformer_Temperature=(Transformer_Temperature*MULTIFACTOR_10);
	uint16_t u16FEC_Temperature=(FEC_Temperature*MULTIFACTOR_10);

	uint16_t u16PSFB_Temperature=(PSFB_Temperature*MULTIFACTOR_10);
	uint16_t u16DC_Busvoltage=(DC_Busvoltage*MULTIFACTOR_10);
	uint16_t u16DC_Bus_Current=(DC_Bus_Current*MULTIFACTOR_10);

	uint16_t u16FEC_input_Current=(FEC_input_Current*MULTIFACTOR_10);
	uint16_t u16PSFB_Output_Voltage=(PSFB_Output_Voltage*MULTIFACTOR_10);
	uint16_t u16PSFB_Output_Current=(PSFB_Output_Current*MULTIFACTOR_10);

	uint16_t u16SFault1_2=(SFault1_2);
	uint16_t u16SFault3_4=(SFault3_4);
	uint16_t u16SFault5_6=(SFault5_6);
	uint16_t u16SFault7_8=(SFault7_8);

	uint16_t u16SStatus1_2=(SStatus1_2);
	uint16_t u16SStatus3_4=(SStatus3_4);

	uint16_t u16RSVD_1=(RSVD_1);
	uint16_t u16RSVD_2=(RSVD_2);
	uint16_t u16RSVD_3=(RSVD_3);
	uint16_t u16RSVD_4=(RSVD_4);
	uint16_t u16RSVD_5=(RSVD_5);
	uint16_t u16RSVD_6=(RSVD_6);
	uint16_t u16RSVD_7=(RSVD_7);
	uint16_t u16RSVD_8=(RSVD_8);
	uint16_t u16RSVD_9=(RSVD_9);
	uint16_t u16RSVD_10=(RSVD_10);
	uint16_t u16RSVD_11=(RSVD_11);
	uint16_t u16RSVD_12=(RSVD_12);
	uint16_t u16RSVD_13=(RSVD_13);
	uint16_t u16RSVD_14=(RSVD_14);
	uint16_t u16RSVD_15=(RSVD_15);
	uint16_t u16RSVD_16=(RSVD_16);
	uint16_t u16RSVD_17=(RSVD_17);


	TxDataHandler13_CAN3[0]=u16Diode_Temperature;
	TxDataHandler13_CAN3[1]=u16Diode_Temperature>>8;

	TxDataHandler13_CAN3[2]=u16Transformer_Temperature;
	TxDataHandler13_CAN3[3]=u16Transformer_Temperature>>8;

	TxDataHandler13_CAN3[4]=u16FEC_Temperature;
	TxDataHandler13_CAN3[5]=u16FEC_Temperature>>8;

	TxDataHandler13_CAN3[6]=u16PSFB_Temperature;
	TxDataHandler13_CAN3[7]=u16PSFB_Temperature>>8;

	TxDataHandler13_CAN3[8]=u16DC_Busvoltage;
	TxDataHandler13_CAN3[9]=u16DC_Busvoltage>>8;

	TxDataHandler13_CAN3[10]=u16DC_Bus_Current;
	TxDataHandler13_CAN3[11]=u16DC_Bus_Current>>8;

	TxDataHandler13_CAN3[12]=u16FEC_input_Current;
	TxDataHandler13_CAN3[13]=u16FEC_input_Current>>8;

	TxDataHandler13_CAN3[14]=u16PSFB_Output_Voltage;
	TxDataHandler13_CAN3[15]=u16PSFB_Output_Voltage>>8;

	TxDataHandler13_CAN3[16]=u16PSFB_Output_Current;
	TxDataHandler13_CAN3[17]=u16PSFB_Output_Current>>8;

	TxDataHandler13_CAN3[18]=u16SFault1_2;
	TxDataHandler13_CAN3[19]=u16SFault1_2>>8;

	TxDataHandler13_CAN3[20]=u16SFault3_4;
	TxDataHandler13_CAN3[21]=u16SFault3_4>>8;

	TxDataHandler13_CAN3[22]=u16SFault5_6;
	TxDataHandler13_CAN3[23]=u16SFault5_6>>8;

	TxDataHandler13_CAN3[24]=u16SFault7_8;
	TxDataHandler13_CAN3[25]=u16SFault7_8>>8;

	TxDataHandler13_CAN3[26]=u16SStatus1_2;
	TxDataHandler13_CAN3[27]=u16SStatus1_2>>8;

	TxDataHandler13_CAN3[28]=u16SStatus3_4;
	TxDataHandler13_CAN3[29]=u16SStatus3_4>>8;

	TxDataHandler13_CAN3[30]=u16RSVD_1;
	TxDataHandler13_CAN3[31]=u16RSVD_1>>8;

	TxDataHandler13_CAN3[32]=u16RSVD_2;
	TxDataHandler13_CAN3[33]=u16RSVD_2>>8;

	TxDataHandler13_CAN3[34]=u16RSVD_3;
	TxDataHandler13_CAN3[35]=u16RSVD_3>>8;

	TxDataHandler13_CAN3[36]=u16RSVD_4;
	TxDataHandler13_CAN3[37]=u16RSVD_4>>8;

	TxDataHandler13_CAN3[38]=u16RSVD_5;
	TxDataHandler13_CAN3[39]=u16RSVD_5>>8;

	TxDataHandler13_CAN3[40]=u16RSVD_6;
	TxDataHandler13_CAN3[41]=u16RSVD_6>>8;

	TxDataHandler13_CAN3[42]=u16RSVD_7;
	TxDataHandler13_CAN3[43]=u16RSVD_7>>8;

	TxDataHandler13_CAN3[44]=u16RSVD_8;
	TxDataHandler13_CAN3[45]=u16RSVD_8>>8;

	TxDataHandler13_CAN3[46]=u16RSVD_9;
	TxDataHandler13_CAN3[47]=u16RSVD_9>>8;

	TxDataHandler13_CAN3[48]=u16RSVD_10;
	TxDataHandler13_CAN3[49]=u16RSVD_10>>8;

	TxDataHandler13_CAN3[50]=u16RSVD_11;
	TxDataHandler13_CAN3[51]=u16RSVD_11>>8;

	TxDataHandler13_CAN3[52]=u16RSVD_12;
	TxDataHandler13_CAN3[53]=u16RSVD_12>>8;

	TxDataHandler13_CAN3[54]=u16RSVD_13;
	TxDataHandler13_CAN3[55]=u16RSVD_13>>8;

	TxDataHandler13_CAN3[56]=u16RSVD_14;
	TxDataHandler13_CAN3[57]=u16RSVD_14>>8;

	TxDataHandler13_CAN3[58]=u16RSVD_15;
	TxDataHandler13_CAN3[59]=u16RSVD_15>>8;

	TxDataHandler13_CAN3[60]=u16RSVD_16;
	TxDataHandler13_CAN3[61]=u16RSVD_16>>8;

	TxDataHandler13_CAN3[62]=u16RSVD_17;
	TxDataHandler13_CAN3[63]=u16RSVD_17>>8;

	if (HAL_FDCAN_AddMessageToTxFifoQ(&hfdcan3, &TxHeader13_CAN3, TxDataHandler13_CAN3) != HAL_OK)
	{}
	else
	{}
	HAL_Delay(1);
}
//14
void Master_To_Monitor_Frame15_Slave14(float Diode_Temperature,float Transformer_Temperature,float FEC_Temperature,float PSFB_Temperature,float DC_Busvoltage,float DC_Bus_Current,float FEC_input_Current,float PSFB_Output_Voltage,
		float PSFB_Output_Current,uint16_t SFault1_2,uint16_t SFault3_4,uint16_t SFault5_6,uint16_t SFault7_8,uint16_t SStatus1_2,uint16_t SStatus3_4,uint16_t RSVD_1,
		uint16_t RSVD_2,uint16_t RSVD_3,uint16_t RSVD_4,uint16_t RSVD_5,uint16_t RSVD_6,uint16_t RSVD_7,uint16_t RSVD_8,uint16_t RSVD_9,
		uint16_t RSVD_10,uint16_t RSVD_11,uint16_t RSVD_12,uint16_t RSVD_13,uint16_t RSVD_14,uint16_t RSVD_15,uint16_t RSVD_16,uint16_t RSVD_17)
{

	uint16_t u16Diode_Temperature=(Diode_Temperature*MULTIFACTOR_10);
	uint16_t u16Transformer_Temperature=(Transformer_Temperature*MULTIFACTOR_10);
	uint16_t u16FEC_Temperature=(FEC_Temperature*MULTIFACTOR_10);

	uint16_t u16PSFB_Temperature=(PSFB_Temperature*MULTIFACTOR_10);
	uint16_t u16DC_Busvoltage=(DC_Busvoltage*MULTIFACTOR_10);
	uint16_t u16DC_Bus_Current=(DC_Bus_Current*MULTIFACTOR_10);

	uint16_t u16FEC_input_Current=(FEC_input_Current*MULTIFACTOR_10);
	uint16_t u16PSFB_Output_Voltage=(PSFB_Output_Voltage*MULTIFACTOR_10);
	uint16_t u16PSFB_Output_Current=(PSFB_Output_Current*MULTIFACTOR_10);

	uint16_t u16SFault1_2=(SFault1_2);
	uint16_t u16SFault3_4=(SFault3_4);
	uint16_t u16SFault5_6=(SFault5_6);
	uint16_t u16SFault7_8=(SFault7_8);

	uint16_t u16SStatus1_2=(SStatus1_2);
	uint16_t u16SStatus3_4=(SStatus3_4);

	uint16_t u16RSVD_1=(RSVD_1);
	uint16_t u16RSVD_2=(RSVD_2);
	uint16_t u16RSVD_3=(RSVD_3);
	uint16_t u16RSVD_4=(RSVD_4);
	uint16_t u16RSVD_5=(RSVD_5);
	uint16_t u16RSVD_6=(RSVD_6);
	uint16_t u16RSVD_7=(RSVD_7);
	uint16_t u16RSVD_8=(RSVD_8);
	uint16_t u16RSVD_9=(RSVD_9);
	uint16_t u16RSVD_10=(RSVD_10);
	uint16_t u16RSVD_11=(RSVD_11);
	uint16_t u16RSVD_12=(RSVD_12);
	uint16_t u16RSVD_13=(RSVD_13);
	uint16_t u16RSVD_14=(RSVD_14);
	uint16_t u16RSVD_15=(RSVD_15);
	uint16_t u16RSVD_16=(RSVD_16);
	uint16_t u16RSVD_17=(RSVD_17);


	TxDataHandler14_CAN3[0]=u16Diode_Temperature;
	TxDataHandler14_CAN3[1]=u16Diode_Temperature>>8;

	TxDataHandler14_CAN3[2]=u16Transformer_Temperature;
	TxDataHandler14_CAN3[3]=u16Transformer_Temperature>>8;

	TxDataHandler14_CAN3[4]=u16FEC_Temperature;
	TxDataHandler14_CAN3[5]=u16FEC_Temperature>>8;

	TxDataHandler14_CAN3[6]=u16PSFB_Temperature;
	TxDataHandler14_CAN3[7]=u16PSFB_Temperature>>8;

	TxDataHandler14_CAN3[8]=u16DC_Busvoltage;
	TxDataHandler14_CAN3[9]=u16DC_Busvoltage>>8;

	TxDataHandler14_CAN3[10]=u16DC_Bus_Current;
	TxDataHandler14_CAN3[11]=u16DC_Bus_Current>>8;

	TxDataHandler14_CAN3[12]=u16FEC_input_Current;
	TxDataHandler14_CAN3[13]=u16FEC_input_Current>>8;

	TxDataHandler14_CAN3[14]=u16PSFB_Output_Voltage;
	TxDataHandler14_CAN3[15]=u16PSFB_Output_Voltage>>8;

	TxDataHandler14_CAN3[16]=u16PSFB_Output_Current;
	TxDataHandler14_CAN3[17]=u16PSFB_Output_Current>>8;

	TxDataHandler14_CAN3[18]=u16SFault1_2;
	TxDataHandler14_CAN3[19]=u16SFault1_2>>8;

	TxDataHandler14_CAN3[20]=u16SFault3_4;
	TxDataHandler14_CAN3[21]=u16SFault3_4>>8;

	TxDataHandler14_CAN3[22]=u16SFault5_6;
	TxDataHandler14_CAN3[23]=u16SFault5_6>>8;

	TxDataHandler14_CAN3[24]=u16SFault7_8;
	TxDataHandler14_CAN3[25]=u16SFault7_8>>8;

	TxDataHandler14_CAN3[26]=u16SStatus1_2;
	TxDataHandler14_CAN3[27]=u16SStatus1_2>>8;

	TxDataHandler14_CAN3[28]=u16SStatus3_4;
	TxDataHandler14_CAN3[29]=u16SStatus3_4>>8;

	TxDataHandler14_CAN3[30]=u16RSVD_1;
	TxDataHandler14_CAN3[31]=u16RSVD_1>>8;

	TxDataHandler14_CAN3[32]=u16RSVD_2;
	TxDataHandler14_CAN3[33]=u16RSVD_2>>8;

	TxDataHandler14_CAN3[34]=u16RSVD_3;
	TxDataHandler14_CAN3[35]=u16RSVD_3>>8;

	TxDataHandler14_CAN3[36]=u16RSVD_4;
	TxDataHandler14_CAN3[37]=u16RSVD_4>>8;

	TxDataHandler14_CAN3[38]=u16RSVD_5;
	TxDataHandler14_CAN3[39]=u16RSVD_5>>8;

	TxDataHandler14_CAN3[40]=u16RSVD_6;
	TxDataHandler14_CAN3[41]=u16RSVD_6>>8;

	TxDataHandler14_CAN3[42]=u16RSVD_7;
	TxDataHandler14_CAN3[43]=u16RSVD_7>>8;

	TxDataHandler14_CAN3[44]=u16RSVD_8;
	TxDataHandler14_CAN3[45]=u16RSVD_8>>8;

	TxDataHandler14_CAN3[46]=u16RSVD_9;
	TxDataHandler14_CAN3[47]=u16RSVD_9>>8;

	TxDataHandler14_CAN3[48]=u16RSVD_10;
	TxDataHandler14_CAN3[49]=u16RSVD_10>>8;

	TxDataHandler14_CAN3[50]=u16RSVD_11;
	TxDataHandler14_CAN3[51]=u16RSVD_11>>8;

	TxDataHandler14_CAN3[52]=u16RSVD_12;
	TxDataHandler14_CAN3[53]=u16RSVD_12>>8;

	TxDataHandler14_CAN3[54]=u16RSVD_13;
	TxDataHandler14_CAN3[55]=u16RSVD_13>>8;

	TxDataHandler14_CAN3[56]=u16RSVD_14;
	TxDataHandler14_CAN3[57]=u16RSVD_14>>8;

	TxDataHandler14_CAN3[58]=u16RSVD_15;
	TxDataHandler14_CAN3[59]=u16RSVD_15>>8;

	TxDataHandler14_CAN3[60]=u16RSVD_16;
	TxDataHandler14_CAN3[61]=u16RSVD_16>>8;

	TxDataHandler14_CAN3[62]=u16RSVD_17;
	TxDataHandler14_CAN3[63]=u16RSVD_17>>8;

	if (HAL_FDCAN_AddMessageToTxFifoQ(&hfdcan3, &TxHeader14_CAN3, TxDataHandler14_CAN3) != HAL_OK)
	{}
	else
	{}
	HAL_Delay(1);
}
//15
void Master_To_Monitor_Frame16_Slave15(float Diode_Temperature,float Transformer_Temperature,float FEC_Temperature,float PSFB_Temperature,float DC_Busvoltage,float DC_Bus_Current,float FEC_input_Current,float PSFB_Output_Voltage,
		float PSFB_Output_Current,uint16_t SFault1_2,uint16_t SFault3_4,uint16_t SFault5_6,uint16_t SFault7_8,uint16_t SStatus1_2,uint16_t SStatus3_4,uint16_t RSVD_1,
		uint16_t RSVD_2,uint16_t RSVD_3,uint16_t RSVD_4,uint16_t RSVD_5,uint16_t RSVD_6,uint16_t RSVD_7,uint16_t RSVD_8,uint16_t RSVD_9,
		uint16_t RSVD_10,uint16_t RSVD_11,uint16_t RSVD_12,uint16_t RSVD_13,uint16_t RSVD_14,uint16_t RSVD_15,uint16_t RSVD_16,uint16_t RSVD_17)
{

	uint16_t u16Diode_Temperature=(Diode_Temperature*MULTIFACTOR_10);
	uint16_t u16Transformer_Temperature=(Transformer_Temperature*MULTIFACTOR_10);
	uint16_t u16FEC_Temperature=(FEC_Temperature*MULTIFACTOR_10);

	uint16_t u16PSFB_Temperature=(PSFB_Temperature*MULTIFACTOR_10);
	uint16_t u16DC_Busvoltage=(DC_Busvoltage*MULTIFACTOR_10);
	uint16_t u16DC_Bus_Current=(DC_Bus_Current*MULTIFACTOR_10);

	uint16_t u16FEC_input_Current=(FEC_input_Current*MULTIFACTOR_10);
	uint16_t u16PSFB_Output_Voltage=(PSFB_Output_Voltage*MULTIFACTOR_10);
	uint16_t u16PSFB_Output_Current=(PSFB_Output_Current*MULTIFACTOR_10);

	uint16_t u16SFault1_2=(SFault1_2);
	uint16_t u16SFault3_4=(SFault3_4);
	uint16_t u16SFault5_6=(SFault5_6);
	uint16_t u16SFault7_8=(SFault7_8);

	uint16_t u16SStatus1_2=(SStatus1_2);
	uint16_t u16SStatus3_4=(SStatus3_4);

	uint16_t u16RSVD_1=(RSVD_1);
	uint16_t u16RSVD_2=(RSVD_2);
	uint16_t u16RSVD_3=(RSVD_3);
	uint16_t u16RSVD_4=(RSVD_4);
	uint16_t u16RSVD_5=(RSVD_5);
	uint16_t u16RSVD_6=(RSVD_6);
	uint16_t u16RSVD_7=(RSVD_7);
	uint16_t u16RSVD_8=(RSVD_8);
	uint16_t u16RSVD_9=(RSVD_9);
	uint16_t u16RSVD_10=(RSVD_10);
	uint16_t u16RSVD_11=(RSVD_11);
	uint16_t u16RSVD_12=(RSVD_12);
	uint16_t u16RSVD_13=(RSVD_13);
	uint16_t u16RSVD_14=(RSVD_14);
	uint16_t u16RSVD_15=(RSVD_15);
	uint16_t u16RSVD_16=(RSVD_16);
	uint16_t u16RSVD_17=(RSVD_17);


	TxDataHandler15_CAN3[0]=u16Diode_Temperature;
	TxDataHandler15_CAN3[1]=u16Diode_Temperature>>8;

	TxDataHandler15_CAN3[2]=u16Transformer_Temperature;
	TxDataHandler15_CAN3[3]=u16Transformer_Temperature>>8;

	TxDataHandler15_CAN3[4]=u16FEC_Temperature;
	TxDataHandler15_CAN3[5]=u16FEC_Temperature>>8;

	TxDataHandler15_CAN3[6]=u16PSFB_Temperature;
	TxDataHandler15_CAN3[7]=u16PSFB_Temperature>>8;

	TxDataHandler15_CAN3[8]=u16DC_Busvoltage;
	TxDataHandler15_CAN3[9]=u16DC_Busvoltage>>8;

	TxDataHandler15_CAN3[10]=u16DC_Bus_Current;
	TxDataHandler15_CAN3[11]=u16DC_Bus_Current>>8;

	TxDataHandler15_CAN3[12]=u16FEC_input_Current;
	TxDataHandler15_CAN3[13]=u16FEC_input_Current>>8;

	TxDataHandler15_CAN3[14]=u16PSFB_Output_Voltage;
	TxDataHandler15_CAN3[15]=u16PSFB_Output_Voltage>>8;

	TxDataHandler15_CAN3[16]=u16PSFB_Output_Current;
	TxDataHandler15_CAN3[17]=u16PSFB_Output_Current>>8;

	TxDataHandler15_CAN3[18]=u16SFault1_2;
	TxDataHandler15_CAN3[19]=u16SFault1_2>>8;

	TxDataHandler15_CAN3[20]=u16SFault3_4;
	TxDataHandler15_CAN3[21]=u16SFault3_4>>8;

	TxDataHandler15_CAN3[22]=u16SFault5_6;
	TxDataHandler15_CAN3[23]=u16SFault5_6>>8;

	TxDataHandler15_CAN3[24]=u16SFault7_8;
	TxDataHandler15_CAN3[25]=u16SFault7_8>>8;

	TxDataHandler15_CAN3[26]=u16SStatus1_2;
	TxDataHandler15_CAN3[27]=u16SStatus1_2>>8;

	TxDataHandler15_CAN3[28]=u16SStatus3_4;
	TxDataHandler15_CAN3[29]=u16SStatus3_4>>8;

	TxDataHandler15_CAN3[30]=u16RSVD_1;
	TxDataHandler15_CAN3[31]=u16RSVD_1>>8;

	TxDataHandler15_CAN3[32]=u16RSVD_2;
	TxDataHandler15_CAN3[33]=u16RSVD_2>>8;

	TxDataHandler15_CAN3[34]=u16RSVD_3;
	TxDataHandler15_CAN3[35]=u16RSVD_3>>8;

	TxDataHandler15_CAN3[36]=u16RSVD_4;
	TxDataHandler15_CAN3[37]=u16RSVD_4>>8;

	TxDataHandler15_CAN3[38]=u16RSVD_5;
	TxDataHandler15_CAN3[39]=u16RSVD_5>>8;

	TxDataHandler15_CAN3[40]=u16RSVD_6;
	TxDataHandler15_CAN3[41]=u16RSVD_6>>8;

	TxDataHandler15_CAN3[42]=u16RSVD_7;
	TxDataHandler15_CAN3[43]=u16RSVD_7>>8;

	TxDataHandler15_CAN3[44]=u16RSVD_8;
	TxDataHandler15_CAN3[45]=u16RSVD_8>>8;

	TxDataHandler15_CAN3[46]=u16RSVD_9;
	TxDataHandler15_CAN3[47]=u16RSVD_9>>8;

	TxDataHandler15_CAN3[48]=u16RSVD_10;
	TxDataHandler15_CAN3[49]=u16RSVD_10>>8;

	TxDataHandler15_CAN3[50]=u16RSVD_11;
	TxDataHandler15_CAN3[51]=u16RSVD_11>>8;

	TxDataHandler15_CAN3[52]=u16RSVD_12;
	TxDataHandler15_CAN3[53]=u16RSVD_12>>8;

	TxDataHandler15_CAN3[54]=u16RSVD_13;
	TxDataHandler15_CAN3[55]=u16RSVD_13>>8;

	TxDataHandler15_CAN3[56]=u16RSVD_14;
	TxDataHandler15_CAN3[57]=u16RSVD_14>>8;

	TxDataHandler15_CAN3[58]=u16RSVD_15;
	TxDataHandler15_CAN3[59]=u16RSVD_15>>8;

	TxDataHandler15_CAN3[60]=u16RSVD_16;
	TxDataHandler15_CAN3[61]=u16RSVD_16>>8;

	TxDataHandler15_CAN3[62]=u16RSVD_17;
	TxDataHandler15_CAN3[63]=u16RSVD_17>>8;

	if (HAL_FDCAN_AddMessageToTxFifoQ(&hfdcan3, &TxHeader15_CAN3, TxDataHandler15_CAN3) != HAL_OK)
	{}
	else
	{}
	HAL_Delay(1);
}
//16
void Master_To_Monitor_Frame17_Slave16(float Diode_Temperature,float Transformer_Temperature,float FEC_Temperature,float PSFB_Temperature,float DC_Busvoltage,float DC_Bus_Current,float FEC_input_Current,float PSFB_Output_Voltage,
		float PSFB_Output_Current,uint16_t SFault1_2,uint16_t SFault3_4,uint16_t SFault5_6,uint16_t SFault7_8,uint16_t SStatus1_2,uint16_t SStatus3_4,uint16_t RSVD_1,
		uint16_t RSVD_2,uint16_t RSVD_3,uint16_t RSVD_4,uint16_t RSVD_5,uint16_t RSVD_6,uint16_t RSVD_7,uint16_t RSVD_8,uint16_t RSVD_9,
		uint16_t RSVD_10,uint16_t RSVD_11,uint16_t RSVD_12,uint16_t RSVD_13,uint16_t RSVD_14,uint16_t RSVD_15,uint16_t RSVD_16,uint16_t RSVD_17)
{

	uint16_t u16Diode_Temperature=(Diode_Temperature*MULTIFACTOR_10);
	uint16_t u16Transformer_Temperature=(Transformer_Temperature*MULTIFACTOR_10);
	uint16_t u16FEC_Temperature=(FEC_Temperature*MULTIFACTOR_10);

	uint16_t u16PSFB_Temperature=(PSFB_Temperature*MULTIFACTOR_10);
	uint16_t u16DC_Busvoltage=(DC_Busvoltage*MULTIFACTOR_10);
	uint16_t u16DC_Bus_Current=(DC_Bus_Current*MULTIFACTOR_10);

	uint16_t u16FEC_input_Current=(FEC_input_Current*MULTIFACTOR_10);
	uint16_t u16PSFB_Output_Voltage=(PSFB_Output_Voltage*MULTIFACTOR_10);
	uint16_t u16PSFB_Output_Current=(PSFB_Output_Current*MULTIFACTOR_10);

	uint16_t u16SFault1_2=(SFault1_2);
	uint16_t u16SFault3_4=(SFault3_4);
	uint16_t u16SFault5_6=(SFault5_6);
	uint16_t u16SFault7_8=(SFault7_8);

	uint16_t u16SStatus1_2=(SStatus1_2);
	uint16_t u16SStatus3_4=(SStatus3_4);

	uint16_t u16RSVD_1=(RSVD_1);
	uint16_t u16RSVD_2=(RSVD_2);
	uint16_t u16RSVD_3=(RSVD_3);
	uint16_t u16RSVD_4=(RSVD_4);
	uint16_t u16RSVD_5=(RSVD_5);
	uint16_t u16RSVD_6=(RSVD_6);
	uint16_t u16RSVD_7=(RSVD_7);
	uint16_t u16RSVD_8=(RSVD_8);
	uint16_t u16RSVD_9=(RSVD_9);
	uint16_t u16RSVD_10=(RSVD_10);
	uint16_t u16RSVD_11=(RSVD_11);
	uint16_t u16RSVD_12=(RSVD_12);
	uint16_t u16RSVD_13=(RSVD_13);
	uint16_t u16RSVD_14=(RSVD_14);
	uint16_t u16RSVD_15=(RSVD_15);
	uint16_t u16RSVD_16=(RSVD_16);
	uint16_t u16RSVD_17=(RSVD_17);


	TxDataHandler16_CAN3[0]=u16Diode_Temperature;
	TxDataHandler16_CAN3[1]=u16Diode_Temperature>>8;

	TxDataHandler16_CAN3[2]=u16Transformer_Temperature;
	TxDataHandler16_CAN3[3]=u16Transformer_Temperature>>8;

	TxDataHandler16_CAN3[4]=u16FEC_Temperature;
	TxDataHandler16_CAN3[5]=u16FEC_Temperature>>8;

	TxDataHandler16_CAN3[6]=u16PSFB_Temperature;
	TxDataHandler16_CAN3[7]=u16PSFB_Temperature>>8;

	TxDataHandler16_CAN3[8]=u16DC_Busvoltage;
	TxDataHandler16_CAN3[9]=u16DC_Busvoltage>>8;

	TxDataHandler16_CAN3[10]=u16DC_Bus_Current;
	TxDataHandler16_CAN3[11]=u16DC_Bus_Current>>8;

	TxDataHandler16_CAN3[12]=u16FEC_input_Current;
	TxDataHandler16_CAN3[13]=u16FEC_input_Current>>8;

	TxDataHandler16_CAN3[14]=u16PSFB_Output_Voltage;
	TxDataHandler16_CAN3[15]=u16PSFB_Output_Voltage>>8;

	TxDataHandler16_CAN3[16]=u16PSFB_Output_Current;
	TxDataHandler16_CAN3[17]=u16PSFB_Output_Current>>8;

	TxDataHandler16_CAN3[18]=u16SFault1_2;
	TxDataHandler16_CAN3[19]=u16SFault1_2>>8;

	TxDataHandler16_CAN3[20]=u16SFault3_4;
	TxDataHandler16_CAN3[21]=u16SFault3_4>>8;

	TxDataHandler16_CAN3[22]=u16SFault5_6;
	TxDataHandler16_CAN3[23]=u16SFault5_6>>8;

	TxDataHandler16_CAN3[24]=u16SFault7_8;
	TxDataHandler16_CAN3[25]=u16SFault7_8>>8;

	TxDataHandler16_CAN3[26]=u16SStatus1_2;
	TxDataHandler16_CAN3[27]=u16SStatus1_2>>8;

	TxDataHandler16_CAN3[28]=u16SStatus3_4;
	TxDataHandler16_CAN3[29]=u16SStatus3_4>>8;

	TxDataHandler16_CAN3[30]=u16RSVD_1;
	TxDataHandler16_CAN3[31]=u16RSVD_1>>8;

	TxDataHandler16_CAN3[32]=u16RSVD_2;
	TxDataHandler16_CAN3[33]=u16RSVD_2>>8;

	TxDataHandler16_CAN3[34]=u16RSVD_3;
	TxDataHandler16_CAN3[35]=u16RSVD_3>>8;

	TxDataHandler16_CAN3[36]=u16RSVD_4;
	TxDataHandler16_CAN3[37]=u16RSVD_4>>8;

	TxDataHandler16_CAN3[38]=u16RSVD_5;
	TxDataHandler16_CAN3[39]=u16RSVD_5>>8;

	TxDataHandler16_CAN3[40]=u16RSVD_6;
	TxDataHandler16_CAN3[41]=u16RSVD_6>>8;

	TxDataHandler16_CAN3[42]=u16RSVD_7;
	TxDataHandler16_CAN3[43]=u16RSVD_7>>8;

	TxDataHandler16_CAN3[44]=u16RSVD_8;
	TxDataHandler16_CAN3[45]=u16RSVD_8>>8;

	TxDataHandler16_CAN3[46]=u16RSVD_9;
	TxDataHandler16_CAN3[47]=u16RSVD_9>>8;

	TxDataHandler16_CAN3[48]=u16RSVD_10;
	TxDataHandler16_CAN3[49]=u16RSVD_10>>8;

	TxDataHandler16_CAN3[50]=u16RSVD_11;
	TxDataHandler16_CAN3[51]=u16RSVD_11>>8;

	TxDataHandler16_CAN3[52]=u16RSVD_12;
	TxDataHandler16_CAN3[53]=u16RSVD_12>>8;

	TxDataHandler16_CAN3[54]=u16RSVD_13;
	TxDataHandler16_CAN3[55]=u16RSVD_13>>8;

	TxDataHandler16_CAN3[56]=u16RSVD_14;
	TxDataHandler16_CAN3[57]=u16RSVD_14>>8;

	TxDataHandler16_CAN3[58]=u16RSVD_15;
	TxDataHandler16_CAN3[59]=u16RSVD_15>>8;

	TxDataHandler16_CAN3[60]=u16RSVD_16;
	TxDataHandler16_CAN3[61]=u16RSVD_16>>8;

	TxDataHandler16_CAN3[62]=u16RSVD_17;
	TxDataHandler16_CAN3[63]=u16RSVD_17>>8;

	if (HAL_FDCAN_AddMessageToTxFifoQ(&hfdcan3, &TxHeader16_CAN3, TxDataHandler16_CAN3) != HAL_OK)
	{}
	else
	{}
	HAL_Delay(1);
}
//17
void Master_To_Monitor_Frame18_Slave17(float Diode_Temperature,float Transformer_Temperature,float FEC_Temperature,float PSFB_Temperature,float DC_Busvoltage,float DC_Bus_Current,float FEC_input_Current,float PSFB_Output_Voltage,
		float PSFB_Output_Current,uint16_t SFault1_2,uint16_t SFault3_4,uint16_t SFault5_6,uint16_t SFault7_8,uint16_t SStatus1_2,uint16_t SStatus3_4,uint16_t RSVD_1,
		uint16_t RSVD_2,uint16_t RSVD_3,uint16_t RSVD_4,uint16_t RSVD_5,uint16_t RSVD_6,uint16_t RSVD_7,uint16_t RSVD_8,uint16_t RSVD_9,
		uint16_t RSVD_10,uint16_t RSVD_11,uint16_t RSVD_12,uint16_t RSVD_13,uint16_t RSVD_14,uint16_t RSVD_15,uint16_t RSVD_16,uint16_t RSVD_17)
{

	uint16_t u16Diode_Temperature=(Diode_Temperature*MULTIFACTOR_10);
	uint16_t u16Transformer_Temperature=(Transformer_Temperature*MULTIFACTOR_10);
	uint16_t u16FEC_Temperature=(FEC_Temperature*MULTIFACTOR_10);

	uint16_t u16PSFB_Temperature=(PSFB_Temperature*MULTIFACTOR_10);
	uint16_t u16DC_Busvoltage=(DC_Busvoltage*MULTIFACTOR_10);
	uint16_t u16DC_Bus_Current=(DC_Bus_Current*MULTIFACTOR_10);

	uint16_t u16FEC_input_Current=(FEC_input_Current*MULTIFACTOR_10);
	uint16_t u16PSFB_Output_Voltage=(PSFB_Output_Voltage*MULTIFACTOR_10);
	uint16_t u16PSFB_Output_Current=(PSFB_Output_Current*MULTIFACTOR_10);

	uint16_t u16SFault1_2=(SFault1_2);
	uint16_t u16SFault3_4=(SFault3_4);
	uint16_t u16SFault5_6=(SFault5_6);
	uint16_t u16SFault7_8=(SFault7_8);

	uint16_t u16SStatus1_2=(SStatus1_2);
	uint16_t u16SStatus3_4=(SStatus3_4);

	uint16_t u16RSVD_1=(RSVD_1);
	uint16_t u16RSVD_2=(RSVD_2);
	uint16_t u16RSVD_3=(RSVD_3);
	uint16_t u16RSVD_4=(RSVD_4);
	uint16_t u16RSVD_5=(RSVD_5);
	uint16_t u16RSVD_6=(RSVD_6);
	uint16_t u16RSVD_7=(RSVD_7);
	uint16_t u16RSVD_8=(RSVD_8);
	uint16_t u16RSVD_9=(RSVD_9);
	uint16_t u16RSVD_10=(RSVD_10);
	uint16_t u16RSVD_11=(RSVD_11);
	uint16_t u16RSVD_12=(RSVD_12);
	uint16_t u16RSVD_13=(RSVD_13);
	uint16_t u16RSVD_14=(RSVD_14);
	uint16_t u16RSVD_15=(RSVD_15);
	uint16_t u16RSVD_16=(RSVD_16);
	uint16_t u16RSVD_17=(RSVD_17);


	TxDataHandler17_CAN3[0]=u16Diode_Temperature;
	TxDataHandler17_CAN3[1]=u16Diode_Temperature>>8;

	TxDataHandler17_CAN3[2]=u16Transformer_Temperature;
	TxDataHandler17_CAN3[3]=u16Transformer_Temperature>>8;

	TxDataHandler17_CAN3[4]=u16FEC_Temperature;
	TxDataHandler17_CAN3[5]=u16FEC_Temperature>>8;

	TxDataHandler17_CAN3[6]=u16PSFB_Temperature;
	TxDataHandler17_CAN3[7]=u16PSFB_Temperature>>8;

	TxDataHandler17_CAN3[8]=u16DC_Busvoltage;
	TxDataHandler17_CAN3[9]=u16DC_Busvoltage>>8;

	TxDataHandler17_CAN3[10]=u16DC_Bus_Current;
	TxDataHandler17_CAN3[11]=u16DC_Bus_Current>>8;

	TxDataHandler17_CAN3[12]=u16FEC_input_Current;
	TxDataHandler17_CAN3[13]=u16FEC_input_Current>>8;

	TxDataHandler17_CAN3[14]=u16PSFB_Output_Voltage;
	TxDataHandler17_CAN3[15]=u16PSFB_Output_Voltage>>8;

	TxDataHandler17_CAN3[16]=u16PSFB_Output_Current;
	TxDataHandler17_CAN3[17]=u16PSFB_Output_Current>>8;

	TxDataHandler17_CAN3[18]=u16SFault1_2;
	TxDataHandler17_CAN3[19]=u16SFault1_2>>8;

	TxDataHandler17_CAN3[20]=u16SFault3_4;
	TxDataHandler17_CAN3[21]=u16SFault3_4>>8;

	TxDataHandler17_CAN3[22]=u16SFault5_6;
	TxDataHandler17_CAN3[23]=u16SFault5_6>>8;

	TxDataHandler17_CAN3[24]=u16SFault7_8;
	TxDataHandler17_CAN3[25]=u16SFault7_8>>8;

	TxDataHandler17_CAN3[26]=u16SStatus1_2;
	TxDataHandler17_CAN3[27]=u16SStatus1_2>>8;

	TxDataHandler17_CAN3[28]=u16SStatus3_4;
	TxDataHandler17_CAN3[29]=u16SStatus3_4>>8;

	TxDataHandler17_CAN3[30]=u16RSVD_1;
	TxDataHandler17_CAN3[31]=u16RSVD_1>>8;

	TxDataHandler17_CAN3[32]=u16RSVD_2;
	TxDataHandler17_CAN3[33]=u16RSVD_2>>8;

	TxDataHandler17_CAN3[34]=u16RSVD_3;
	TxDataHandler17_CAN3[35]=u16RSVD_3>>8;

	TxDataHandler17_CAN3[36]=u16RSVD_4;
	TxDataHandler17_CAN3[37]=u16RSVD_4>>8;

	TxDataHandler17_CAN3[38]=u16RSVD_5;
	TxDataHandler17_CAN3[39]=u16RSVD_5>>8;

	TxDataHandler17_CAN3[40]=u16RSVD_6;
	TxDataHandler17_CAN3[41]=u16RSVD_6>>8;

	TxDataHandler17_CAN3[42]=u16RSVD_7;
	TxDataHandler17_CAN3[43]=u16RSVD_7>>8;

	TxDataHandler17_CAN3[44]=u16RSVD_8;
	TxDataHandler17_CAN3[45]=u16RSVD_8>>8;

	TxDataHandler17_CAN3[46]=u16RSVD_9;
	TxDataHandler17_CAN3[47]=u16RSVD_9>>8;

	TxDataHandler17_CAN3[48]=u16RSVD_10;
	TxDataHandler17_CAN3[49]=u16RSVD_10>>8;

	TxDataHandler17_CAN3[50]=u16RSVD_11;
	TxDataHandler17_CAN3[51]=u16RSVD_11>>8;

	TxDataHandler17_CAN3[52]=u16RSVD_12;
	TxDataHandler17_CAN3[53]=u16RSVD_12>>8;

	TxDataHandler17_CAN3[54]=u16RSVD_13;
	TxDataHandler17_CAN3[55]=u16RSVD_13>>8;

	TxDataHandler17_CAN3[56]=u16RSVD_14;
	TxDataHandler17_CAN3[57]=u16RSVD_14>>8;

	TxDataHandler17_CAN3[58]=u16RSVD_15;
	TxDataHandler17_CAN3[59]=u16RSVD_15>>8;

	TxDataHandler17_CAN3[60]=u16RSVD_16;
	TxDataHandler17_CAN3[61]=u16RSVD_16>>8;

	TxDataHandler17_CAN3[62]=u16RSVD_17;
	TxDataHandler17_CAN3[63]=u16RSVD_17>>8;

	if (HAL_FDCAN_AddMessageToTxFifoQ(&hfdcan3, &TxHeader17_CAN3, TxDataHandler17_CAN3) != HAL_OK)
	{}
	else
	{}
	HAL_Delay(1);
}
//18
void Master_To_Monitor_Frame19_Slave18(float Diode_Temperature,float Transformer_Temperature,float FEC_Temperature,float PSFB_Temperature,float DC_Busvoltage,float DC_Bus_Current,float FEC_input_Current,float PSFB_Output_Voltage,
		float PSFB_Output_Current,uint16_t SFault1_2,uint16_t SFault3_4,uint16_t SFault5_6,uint16_t SFault7_8,uint16_t SStatus1_2,uint16_t SStatus3_4,uint16_t RSVD_1,
		uint16_t RSVD_2,uint16_t RSVD_3,uint16_t RSVD_4,uint16_t RSVD_5,uint16_t RSVD_6,uint16_t RSVD_7,uint16_t RSVD_8,uint16_t RSVD_9,
		uint16_t RSVD_10,uint16_t RSVD_11,uint16_t RSVD_12,uint16_t RSVD_13,uint16_t RSVD_14,uint16_t RSVD_15,uint16_t RSVD_16,uint16_t RSVD_17)
{

	uint16_t u16Diode_Temperature=(Diode_Temperature*MULTIFACTOR_10);
	uint16_t u16Transformer_Temperature=(Transformer_Temperature*MULTIFACTOR_10);
	uint16_t u16FEC_Temperature=(FEC_Temperature*MULTIFACTOR_10);

	uint16_t u16PSFB_Temperature=(PSFB_Temperature*MULTIFACTOR_10);
	uint16_t u16DC_Busvoltage=(DC_Busvoltage*MULTIFACTOR_10);
	uint16_t u16DC_Bus_Current=(DC_Bus_Current*MULTIFACTOR_10);

	uint16_t u16FEC_input_Current=(FEC_input_Current*MULTIFACTOR_10);
	uint16_t u16PSFB_Output_Voltage=(PSFB_Output_Voltage*MULTIFACTOR_10);
	uint16_t u16PSFB_Output_Current=(PSFB_Output_Current*MULTIFACTOR_10);

	uint16_t u16SFault1_2=(SFault1_2);
	uint16_t u16SFault3_4=(SFault3_4);
	uint16_t u16SFault5_6=(SFault5_6);
	uint16_t u16SFault7_8=(SFault7_8);

	uint16_t u16SStatus1_2=(SStatus1_2);
	uint16_t u16SStatus3_4=(SStatus3_4);

	uint16_t u16RSVD_1=(RSVD_1);
	uint16_t u16RSVD_2=(RSVD_2);
	uint16_t u16RSVD_3=(RSVD_3);
	uint16_t u16RSVD_4=(RSVD_4);
	uint16_t u16RSVD_5=(RSVD_5);
	uint16_t u16RSVD_6=(RSVD_6);
	uint16_t u16RSVD_7=(RSVD_7);
	uint16_t u16RSVD_8=(RSVD_8);
	uint16_t u16RSVD_9=(RSVD_9);
	uint16_t u16RSVD_10=(RSVD_10);
	uint16_t u16RSVD_11=(RSVD_11);
	uint16_t u16RSVD_12=(RSVD_12);
	uint16_t u16RSVD_13=(RSVD_13);
	uint16_t u16RSVD_14=(RSVD_14);
	uint16_t u16RSVD_15=(RSVD_15);
	uint16_t u16RSVD_16=(RSVD_16);
	uint16_t u16RSVD_17=(RSVD_17);


	TxDataHandler18_CAN3[0]=u16Diode_Temperature;
	TxDataHandler18_CAN3[1]=u16Diode_Temperature>>8;

	TxDataHandler18_CAN3[2]=u16Transformer_Temperature;
	TxDataHandler18_CAN3[3]=u16Transformer_Temperature>>8;

	TxDataHandler18_CAN3[4]=u16FEC_Temperature;
	TxDataHandler18_CAN3[5]=u16FEC_Temperature>>8;

	TxDataHandler18_CAN3[6]=u16PSFB_Temperature;
	TxDataHandler18_CAN3[7]=u16PSFB_Temperature>>8;

	TxDataHandler18_CAN3[8]=u16DC_Busvoltage;
	TxDataHandler18_CAN3[9]=u16DC_Busvoltage>>8;

	TxDataHandler18_CAN3[10]=u16DC_Bus_Current;
	TxDataHandler18_CAN3[11]=u16DC_Bus_Current>>8;

	TxDataHandler18_CAN3[12]=u16FEC_input_Current;
	TxDataHandler18_CAN3[13]=u16FEC_input_Current>>8;

	TxDataHandler18_CAN3[14]=u16PSFB_Output_Voltage;
	TxDataHandler18_CAN3[15]=u16PSFB_Output_Voltage>>8;

	TxDataHandler18_CAN3[16]=u16PSFB_Output_Current;
	TxDataHandler18_CAN3[17]=u16PSFB_Output_Current>>8;

	TxDataHandler18_CAN3[18]=u16SFault1_2;
	TxDataHandler18_CAN3[19]=u16SFault1_2>>8;

	TxDataHandler18_CAN3[20]=u16SFault3_4;
	TxDataHandler18_CAN3[21]=u16SFault3_4>>8;

	TxDataHandler18_CAN3[22]=u16SFault5_6;
	TxDataHandler18_CAN3[23]=u16SFault5_6>>8;

	TxDataHandler18_CAN3[24]=u16SFault7_8;
	TxDataHandler18_CAN3[25]=u16SFault7_8>>8;

	TxDataHandler18_CAN3[26]=u16SStatus1_2;
	TxDataHandler18_CAN3[27]=u16SStatus1_2>>8;

	TxDataHandler18_CAN3[28]=u16SStatus3_4;
	TxDataHandler18_CAN3[29]=u16SStatus3_4>>8;

	TxDataHandler18_CAN3[30]=u16RSVD_1;
	TxDataHandler18_CAN3[31]=u16RSVD_1>>8;

	TxDataHandler18_CAN3[32]=u16RSVD_2;
	TxDataHandler18_CAN3[33]=u16RSVD_2>>8;

	TxDataHandler18_CAN3[34]=u16RSVD_3;
	TxDataHandler18_CAN3[35]=u16RSVD_3>>8;

	TxDataHandler18_CAN3[36]=u16RSVD_4;
	TxDataHandler18_CAN3[37]=u16RSVD_4>>8;

	TxDataHandler18_CAN3[38]=u16RSVD_5;
	TxDataHandler18_CAN3[39]=u16RSVD_5>>8;

	TxDataHandler18_CAN3[40]=u16RSVD_6;
	TxDataHandler18_CAN3[41]=u16RSVD_6>>8;

	TxDataHandler18_CAN3[42]=u16RSVD_7;
	TxDataHandler18_CAN3[43]=u16RSVD_7>>8;

	TxDataHandler18_CAN3[44]=u16RSVD_8;
	TxDataHandler18_CAN3[45]=u16RSVD_8>>8;

	TxDataHandler18_CAN3[46]=u16RSVD_9;
	TxDataHandler18_CAN3[47]=u16RSVD_9>>8;

	TxDataHandler18_CAN3[48]=u16RSVD_10;
	TxDataHandler18_CAN3[49]=u16RSVD_10>>8;

	TxDataHandler18_CAN3[50]=u16RSVD_11;
	TxDataHandler18_CAN3[51]=u16RSVD_11>>8;

	TxDataHandler18_CAN3[52]=u16RSVD_12;
	TxDataHandler18_CAN3[53]=u16RSVD_12>>8;

	TxDataHandler18_CAN3[54]=u16RSVD_13;
	TxDataHandler18_CAN3[55]=u16RSVD_13>>8;

	TxDataHandler18_CAN3[56]=u16RSVD_14;
	TxDataHandler18_CAN3[57]=u16RSVD_14>>8;

	TxDataHandler18_CAN3[58]=u16RSVD_15;
	TxDataHandler18_CAN3[59]=u16RSVD_15>>8;

	TxDataHandler18_CAN3[60]=u16RSVD_16;
	TxDataHandler18_CAN3[61]=u16RSVD_16>>8;

	TxDataHandler18_CAN3[62]=u16RSVD_17;
	TxDataHandler18_CAN3[63]=u16RSVD_17>>8;

	if (HAL_FDCAN_AddMessageToTxFifoQ(&hfdcan3, &TxHeader18_CAN3, TxDataHandler18_CAN3) != HAL_OK)
	{}
	else
	{}
	HAL_Delay(1);
}
//19
void Master_To_Monitor_Frame20_Slave19(float Diode_Temperature,float Transformer_Temperature,float FEC_Temperature,float PSFB_Temperature,float DC_Busvoltage,float DC_Bus_Current,float FEC_input_Current,float PSFB_Output_Voltage,
		float PSFB_Output_Current,uint16_t SFault1_2,uint16_t SFault3_4,uint16_t SFault5_6,uint16_t SFault7_8,uint16_t SStatus1_2,uint16_t SStatus3_4,uint16_t RSVD_1,
		uint16_t RSVD_2,uint16_t RSVD_3,uint16_t RSVD_4,uint16_t RSVD_5,uint16_t RSVD_6,uint16_t RSVD_7,uint16_t RSVD_8,uint16_t RSVD_9,
		uint16_t RSVD_10,uint16_t RSVD_11,uint16_t RSVD_12,uint16_t RSVD_13,uint16_t RSVD_14,uint16_t RSVD_15,uint16_t RSVD_16,uint16_t RSVD_17)
{

	uint16_t u16Diode_Temperature=(Diode_Temperature*MULTIFACTOR_10);
	uint16_t u16Transformer_Temperature=(Transformer_Temperature*MULTIFACTOR_10);
	uint16_t u16FEC_Temperature=(FEC_Temperature*MULTIFACTOR_10);

	uint16_t u16PSFB_Temperature=(PSFB_Temperature*MULTIFACTOR_10);
	uint16_t u16DC_Busvoltage=(DC_Busvoltage*MULTIFACTOR_10);
	uint16_t u16DC_Bus_Current=(DC_Bus_Current*MULTIFACTOR_10);

	uint16_t u16FEC_input_Current=(FEC_input_Current*MULTIFACTOR_10);
	uint16_t u16PSFB_Output_Voltage=(PSFB_Output_Voltage*MULTIFACTOR_10);
	uint16_t u16PSFB_Output_Current=(PSFB_Output_Current*MULTIFACTOR_10);

	uint16_t u16SFault1_2=(SFault1_2);
	uint16_t u16SFault3_4=(SFault3_4);
	uint16_t u16SFault5_6=(SFault5_6);
	uint16_t u16SFault7_8=(SFault7_8);

	uint16_t u16SStatus1_2=(SStatus1_2);
	uint16_t u16SStatus3_4=(SStatus3_4);

	uint16_t u16RSVD_1=(RSVD_1);
	uint16_t u16RSVD_2=(RSVD_2);
	uint16_t u16RSVD_3=(RSVD_3);
	uint16_t u16RSVD_4=(RSVD_4);
	uint16_t u16RSVD_5=(RSVD_5);
	uint16_t u16RSVD_6=(RSVD_6);
	uint16_t u16RSVD_7=(RSVD_7);
	uint16_t u16RSVD_8=(RSVD_8);
	uint16_t u16RSVD_9=(RSVD_9);
	uint16_t u16RSVD_10=(RSVD_10);
	uint16_t u16RSVD_11=(RSVD_11);
	uint16_t u16RSVD_12=(RSVD_12);
	uint16_t u16RSVD_13=(RSVD_13);
	uint16_t u16RSVD_14=(RSVD_14);
	uint16_t u16RSVD_15=(RSVD_15);
	uint16_t u16RSVD_16=(RSVD_16);
	uint16_t u16RSVD_17=(RSVD_17);


	TxDataHandler19_CAN3[0]=u16Diode_Temperature;
	TxDataHandler19_CAN3[1]=u16Diode_Temperature>>8;

	TxDataHandler19_CAN3[2]=u16Transformer_Temperature;
	TxDataHandler19_CAN3[3]=u16Transformer_Temperature>>8;

	TxDataHandler19_CAN3[4]=u16FEC_Temperature;
	TxDataHandler19_CAN3[5]=u16FEC_Temperature>>8;

	TxDataHandler19_CAN3[6]=u16PSFB_Temperature;
	TxDataHandler19_CAN3[7]=u16PSFB_Temperature>>8;

	TxDataHandler19_CAN3[8]=u16DC_Busvoltage;
	TxDataHandler19_CAN3[9]=u16DC_Busvoltage>>8;

	TxDataHandler19_CAN3[10]=u16DC_Bus_Current;
	TxDataHandler19_CAN3[11]=u16DC_Bus_Current>>8;

	TxDataHandler19_CAN3[12]=u16FEC_input_Current;
	TxDataHandler19_CAN3[13]=u16FEC_input_Current>>8;

	TxDataHandler19_CAN3[14]=u16PSFB_Output_Voltage;
	TxDataHandler19_CAN3[15]=u16PSFB_Output_Voltage>>8;

	TxDataHandler19_CAN3[16]=u16PSFB_Output_Current;
	TxDataHandler19_CAN3[17]=u16PSFB_Output_Current>>8;

	TxDataHandler19_CAN3[18]=u16SFault1_2;
	TxDataHandler19_CAN3[19]=u16SFault1_2>>8;

	TxDataHandler19_CAN3[20]=u16SFault3_4;
	TxDataHandler19_CAN3[21]=u16SFault3_4>>8;

	TxDataHandler19_CAN3[22]=u16SFault5_6;
	TxDataHandler19_CAN3[23]=u16SFault5_6>>8;

	TxDataHandler19_CAN3[24]=u16SFault7_8;
	TxDataHandler19_CAN3[25]=u16SFault7_8>>8;

	TxDataHandler19_CAN3[26]=u16SStatus1_2;
	TxDataHandler19_CAN3[27]=u16SStatus1_2>>8;

	TxDataHandler19_CAN3[28]=u16SStatus3_4;
	TxDataHandler19_CAN3[29]=u16SStatus3_4>>8;

	TxDataHandler19_CAN3[30]=u16RSVD_1;
	TxDataHandler19_CAN3[31]=u16RSVD_1>>8;

	TxDataHandler19_CAN3[32]=u16RSVD_2;
	TxDataHandler19_CAN3[33]=u16RSVD_2>>8;

	TxDataHandler19_CAN3[34]=u16RSVD_3;
	TxDataHandler19_CAN3[35]=u16RSVD_3>>8;

	TxDataHandler19_CAN3[36]=u16RSVD_4;
	TxDataHandler19_CAN3[37]=u16RSVD_4>>8;

	TxDataHandler19_CAN3[38]=u16RSVD_5;
	TxDataHandler19_CAN3[39]=u16RSVD_5>>8;

	TxDataHandler19_CAN3[40]=u16RSVD_6;
	TxDataHandler19_CAN3[41]=u16RSVD_6>>8;

	TxDataHandler19_CAN3[42]=u16RSVD_7;
	TxDataHandler19_CAN3[43]=u16RSVD_7>>8;

	TxDataHandler19_CAN3[44]=u16RSVD_8;
	TxDataHandler19_CAN3[45]=u16RSVD_8>>8;

	TxDataHandler19_CAN3[46]=u16RSVD_9;
	TxDataHandler19_CAN3[47]=u16RSVD_9>>8;

	TxDataHandler19_CAN3[48]=u16RSVD_10;
	TxDataHandler19_CAN3[49]=u16RSVD_10>>8;

	TxDataHandler19_CAN3[50]=u16RSVD_11;
	TxDataHandler19_CAN3[51]=u16RSVD_11>>8;

	TxDataHandler19_CAN3[52]=u16RSVD_12;
	TxDataHandler19_CAN3[53]=u16RSVD_12>>8;

	TxDataHandler19_CAN3[54]=u16RSVD_13;
	TxDataHandler19_CAN3[55]=u16RSVD_13>>8;

	TxDataHandler19_CAN3[56]=u16RSVD_14;
	TxDataHandler19_CAN3[57]=u16RSVD_14>>8;

	TxDataHandler19_CAN3[58]=u16RSVD_15;
	TxDataHandler19_CAN3[59]=u16RSVD_15>>8;

	TxDataHandler19_CAN3[60]=u16RSVD_16;
	TxDataHandler19_CAN3[61]=u16RSVD_16>>8;

	TxDataHandler19_CAN3[62]=u16RSVD_17;
	TxDataHandler19_CAN3[63]=u16RSVD_17>>8;

	if (HAL_FDCAN_AddMessageToTxFifoQ(&hfdcan3, &TxHeader19_CAN3, TxDataHandler19_CAN3) != HAL_OK)
	{}
	else
	{}
	HAL_Delay(1);
}
//20
void Master_To_Monitor_Frame21_Slave20(float Diode_Temperature,float Transformer_Temperature,float FEC_Temperature,float PSFB_Temperature,float DC_Busvoltage,float DC_Bus_Current,float FEC_input_Current,float PSFB_Output_Voltage,
		float PSFB_Output_Current,uint16_t SFault1_2,uint16_t SFault3_4,uint16_t SFault5_6,uint16_t SFault7_8,uint16_t SStatus1_2,uint16_t SStatus3_4,uint16_t RSVD_1,
		uint16_t RSVD_2,uint16_t RSVD_3,uint16_t RSVD_4,uint16_t RSVD_5,uint16_t RSVD_6,uint16_t RSVD_7,uint16_t RSVD_8,uint16_t RSVD_9,
		uint16_t RSVD_10,uint16_t RSVD_11,uint16_t RSVD_12,uint16_t RSVD_13,uint16_t RSVD_14,uint16_t RSVD_15,uint16_t RSVD_16,uint16_t RSVD_17)
{

	uint16_t u16Diode_Temperature=(Diode_Temperature*MULTIFACTOR_10);
	uint16_t u16Transformer_Temperature=(Transformer_Temperature*MULTIFACTOR_10);
	uint16_t u16FEC_Temperature=(FEC_Temperature*MULTIFACTOR_10);

	uint16_t u16PSFB_Temperature=(PSFB_Temperature*MULTIFACTOR_10);
	uint16_t u16DC_Busvoltage=(DC_Busvoltage*MULTIFACTOR_10);
	uint16_t u16DC_Bus_Current=(DC_Bus_Current*MULTIFACTOR_10);

	uint16_t u16FEC_input_Current=(FEC_input_Current*MULTIFACTOR_10);
	uint16_t u16PSFB_Output_Voltage=(PSFB_Output_Voltage*MULTIFACTOR_10);
	uint16_t u16PSFB_Output_Current=(PSFB_Output_Current*MULTIFACTOR_10);

	uint16_t u16SFault1_2=(SFault1_2);
	uint16_t u16SFault3_4=(SFault3_4);
	uint16_t u16SFault5_6=(SFault5_6);
	uint16_t u16SFault7_8=(SFault7_8);

	uint16_t u16SStatus1_2=(SStatus1_2);
	uint16_t u16SStatus3_4=(SStatus3_4);

	uint16_t u16RSVD_1=(RSVD_1);
	uint16_t u16RSVD_2=(RSVD_2);
	uint16_t u16RSVD_3=(RSVD_3);
	uint16_t u16RSVD_4=(RSVD_4);
	uint16_t u16RSVD_5=(RSVD_5);
	uint16_t u16RSVD_6=(RSVD_6);
	uint16_t u16RSVD_7=(RSVD_7);
	uint16_t u16RSVD_8=(RSVD_8);
	uint16_t u16RSVD_9=(RSVD_9);
	uint16_t u16RSVD_10=(RSVD_10);
	uint16_t u16RSVD_11=(RSVD_11);
	uint16_t u16RSVD_12=(RSVD_12);
	uint16_t u16RSVD_13=(RSVD_13);
	uint16_t u16RSVD_14=(RSVD_14);
	uint16_t u16RSVD_15=(RSVD_15);
	uint16_t u16RSVD_16=(RSVD_16);
	uint16_t u16RSVD_17=(RSVD_17);


	TxDataHandler20_CAN3[0]=u16Diode_Temperature;
	TxDataHandler20_CAN3[1]=u16Diode_Temperature>>8;

	TxDataHandler20_CAN3[2]=u16Transformer_Temperature;
	TxDataHandler20_CAN3[3]=u16Transformer_Temperature>>8;

	TxDataHandler20_CAN3[4]=u16FEC_Temperature;
	TxDataHandler20_CAN3[5]=u16FEC_Temperature>>8;

	TxDataHandler20_CAN3[6]=u16PSFB_Temperature;
	TxDataHandler20_CAN3[7]=u16PSFB_Temperature>>8;

	TxDataHandler20_CAN3[8]=u16DC_Busvoltage;
	TxDataHandler20_CAN3[9]=u16DC_Busvoltage>>8;

	TxDataHandler20_CAN3[10]=u16DC_Bus_Current;
	TxDataHandler20_CAN3[11]=u16DC_Bus_Current>>8;

	TxDataHandler20_CAN3[12]=u16FEC_input_Current;
	TxDataHandler20_CAN3[13]=u16FEC_input_Current>>8;

	TxDataHandler20_CAN3[14]=u16PSFB_Output_Voltage;
	TxDataHandler20_CAN3[15]=u16PSFB_Output_Voltage>>8;

	TxDataHandler20_CAN3[16]=u16PSFB_Output_Current;
	TxDataHandler20_CAN3[17]=u16PSFB_Output_Current>>8;

	TxDataHandler20_CAN3[18]=u16SFault1_2;
	TxDataHandler20_CAN3[19]=u16SFault1_2>>8;

	TxDataHandler20_CAN3[20]=u16SFault3_4;
	TxDataHandler20_CAN3[21]=u16SFault3_4>>8;

	TxDataHandler20_CAN3[22]=u16SFault5_6;
	TxDataHandler20_CAN3[23]=u16SFault5_6>>8;

	TxDataHandler20_CAN3[24]=u16SFault7_8;
	TxDataHandler20_CAN3[25]=u16SFault7_8>>8;

	TxDataHandler20_CAN3[26]=u16SStatus1_2;
	TxDataHandler20_CAN3[27]=u16SStatus1_2>>8;

	TxDataHandler20_CAN3[28]=u16SStatus3_4;
	TxDataHandler20_CAN3[29]=u16SStatus3_4>>8;

	TxDataHandler20_CAN3[30]=u16RSVD_1;
	TxDataHandler20_CAN3[31]=u16RSVD_1>>8;

	TxDataHandler20_CAN3[32]=u16RSVD_2;
	TxDataHandler20_CAN3[33]=u16RSVD_2>>8;

	TxDataHandler20_CAN3[34]=u16RSVD_3;
	TxDataHandler20_CAN3[35]=u16RSVD_3>>8;

	TxDataHandler20_CAN3[36]=u16RSVD_4;
	TxDataHandler20_CAN3[37]=u16RSVD_4>>8;

	TxDataHandler20_CAN3[38]=u16RSVD_5;
	TxDataHandler20_CAN3[39]=u16RSVD_5>>8;

	TxDataHandler20_CAN3[40]=u16RSVD_6;
	TxDataHandler20_CAN3[41]=u16RSVD_6>>8;

	TxDataHandler20_CAN3[42]=u16RSVD_7;
	TxDataHandler20_CAN3[43]=u16RSVD_7>>8;

	TxDataHandler20_CAN3[44]=u16RSVD_8;
	TxDataHandler20_CAN3[45]=u16RSVD_8>>8;

	TxDataHandler20_CAN3[46]=u16RSVD_9;
	TxDataHandler20_CAN3[47]=u16RSVD_9>>8;

	TxDataHandler20_CAN3[48]=u16RSVD_10;
	TxDataHandler20_CAN3[49]=u16RSVD_10>>8;

	TxDataHandler20_CAN3[50]=u16RSVD_11;
	TxDataHandler20_CAN3[51]=u16RSVD_11>>8;

	TxDataHandler20_CAN3[52]=u16RSVD_12;
	TxDataHandler20_CAN3[53]=u16RSVD_12>>8;

	TxDataHandler20_CAN3[54]=u16RSVD_13;
	TxDataHandler20_CAN3[55]=u16RSVD_13>>8;

	TxDataHandler20_CAN3[56]=u16RSVD_14;
	TxDataHandler20_CAN3[57]=u16RSVD_14>>8;

	TxDataHandler20_CAN3[58]=u16RSVD_15;
	TxDataHandler20_CAN3[59]=u16RSVD_15>>8;

	TxDataHandler20_CAN3[60]=u16RSVD_16;
	TxDataHandler20_CAN3[61]=u16RSVD_16>>8;

	TxDataHandler20_CAN3[62]=u16RSVD_17;
	TxDataHandler20_CAN3[63]=u16RSVD_17>>8;

	if (HAL_FDCAN_AddMessageToTxFifoQ(&hfdcan3, &TxHeader20_CAN3, TxDataHandler20_CAN3) != HAL_OK)
	{}
	else
	{}
	HAL_Delay(1);
}
//21
void Master_To_Monitor_Frame22_Slave21(float Diode_Temperature,float Transformer_Temperature,float FEC_Temperature,float PSFB_Temperature,float DC_Busvoltage,float DC_Bus_Current,float FEC_input_Current,float PSFB_Output_Voltage,
		float PSFB_Output_Current,uint16_t SFault1_2,uint16_t SFault3_4,uint16_t SFault5_6,uint16_t SFault7_8,uint16_t SStatus1_2,uint16_t SStatus3_4,uint16_t RSVD_1,
		uint16_t RSVD_2,uint16_t RSVD_3,uint16_t RSVD_4,uint16_t RSVD_5,uint16_t RSVD_6,uint16_t RSVD_7,uint16_t RSVD_8,uint16_t RSVD_9,
		uint16_t RSVD_10,uint16_t RSVD_11,uint16_t RSVD_12,uint16_t RSVD_13,uint16_t RSVD_14,uint16_t RSVD_15,uint16_t RSVD_16,uint16_t RSVD_17)
{

	uint16_t u16Diode_Temperature=(Diode_Temperature*MULTIFACTOR_10);
	uint16_t u16Transformer_Temperature=(Transformer_Temperature*MULTIFACTOR_10);
	uint16_t u16FEC_Temperature=(FEC_Temperature*MULTIFACTOR_10);

	uint16_t u16PSFB_Temperature=(PSFB_Temperature*MULTIFACTOR_10);
	uint16_t u16DC_Busvoltage=(DC_Busvoltage*MULTIFACTOR_10);
	uint16_t u16DC_Bus_Current=(DC_Bus_Current*MULTIFACTOR_10);

	uint16_t u16FEC_input_Current=(FEC_input_Current*MULTIFACTOR_10);
	uint16_t u16PSFB_Output_Voltage=(PSFB_Output_Voltage*MULTIFACTOR_10);
	uint16_t u16PSFB_Output_Current=(PSFB_Output_Current*MULTIFACTOR_10);

	uint16_t u16SFault1_2=(SFault1_2);
	uint16_t u16SFault3_4=(SFault3_4);
	uint16_t u16SFault5_6=(SFault5_6);
	uint16_t u16SFault7_8=(SFault7_8);

	uint16_t u16SStatus1_2=(SStatus1_2);
	uint16_t u16SStatus3_4=(SStatus3_4);

	uint16_t u16RSVD_1=(RSVD_1);
	uint16_t u16RSVD_2=(RSVD_2);
	uint16_t u16RSVD_3=(RSVD_3);
	uint16_t u16RSVD_4=(RSVD_4);
	uint16_t u16RSVD_5=(RSVD_5);
	uint16_t u16RSVD_6=(RSVD_6);
	uint16_t u16RSVD_7=(RSVD_7);
	uint16_t u16RSVD_8=(RSVD_8);
	uint16_t u16RSVD_9=(RSVD_9);
	uint16_t u16RSVD_10=(RSVD_10);
	uint16_t u16RSVD_11=(RSVD_11);
	uint16_t u16RSVD_12=(RSVD_12);
	uint16_t u16RSVD_13=(RSVD_13);
	uint16_t u16RSVD_14=(RSVD_14);
	uint16_t u16RSVD_15=(RSVD_15);
	uint16_t u16RSVD_16=(RSVD_16);
	uint16_t u16RSVD_17=(RSVD_17);


	TxDataHandler21_CAN3[0]=u16Diode_Temperature;
	TxDataHandler21_CAN3[1]=u16Diode_Temperature>>8;

	TxDataHandler21_CAN3[2]=u16Transformer_Temperature;
	TxDataHandler21_CAN3[3]=u16Transformer_Temperature>>8;

	TxDataHandler21_CAN3[4]=u16FEC_Temperature;
	TxDataHandler21_CAN3[5]=u16FEC_Temperature>>8;

	TxDataHandler21_CAN3[6]=u16PSFB_Temperature;
	TxDataHandler21_CAN3[7]=u16PSFB_Temperature>>8;

	TxDataHandler21_CAN3[8]=u16DC_Busvoltage;
	TxDataHandler21_CAN3[9]=u16DC_Busvoltage>>8;

	TxDataHandler21_CAN3[10]=u16DC_Bus_Current;
	TxDataHandler21_CAN3[11]=u16DC_Bus_Current>>8;

	TxDataHandler21_CAN3[12]=u16FEC_input_Current;
	TxDataHandler21_CAN3[13]=u16FEC_input_Current>>8;

	TxDataHandler21_CAN3[14]=u16PSFB_Output_Voltage;
	TxDataHandler21_CAN3[15]=u16PSFB_Output_Voltage>>8;

	TxDataHandler21_CAN3[16]=u16PSFB_Output_Current;
	TxDataHandler21_CAN3[17]=u16PSFB_Output_Current>>8;

	TxDataHandler21_CAN3[18]=u16SFault1_2;
	TxDataHandler21_CAN3[19]=u16SFault1_2>>8;

	TxDataHandler21_CAN3[20]=u16SFault3_4;
	TxDataHandler21_CAN3[21]=u16SFault3_4>>8;

	TxDataHandler21_CAN3[22]=u16SFault5_6;
	TxDataHandler21_CAN3[23]=u16SFault5_6>>8;

	TxDataHandler21_CAN3[24]=u16SFault7_8;
	TxDataHandler21_CAN3[25]=u16SFault7_8>>8;

	TxDataHandler21_CAN3[26]=u16SStatus1_2;
	TxDataHandler21_CAN3[27]=u16SStatus1_2>>8;

	TxDataHandler21_CAN3[28]=u16SStatus3_4;
	TxDataHandler21_CAN3[29]=u16SStatus3_4>>8;

	TxDataHandler21_CAN3[30]=u16RSVD_1;
	TxDataHandler21_CAN3[31]=u16RSVD_1>>8;

	TxDataHandler21_CAN3[32]=u16RSVD_2;
	TxDataHandler21_CAN3[33]=u16RSVD_2>>8;

	TxDataHandler21_CAN3[34]=u16RSVD_3;
	TxDataHandler21_CAN3[35]=u16RSVD_3>>8;

	TxDataHandler21_CAN3[36]=u16RSVD_4;
	TxDataHandler21_CAN3[37]=u16RSVD_4>>8;

	TxDataHandler21_CAN3[38]=u16RSVD_5;
	TxDataHandler21_CAN3[39]=u16RSVD_5>>8;

	TxDataHandler21_CAN3[40]=u16RSVD_6;
	TxDataHandler21_CAN3[41]=u16RSVD_6>>8;

	TxDataHandler21_CAN3[42]=u16RSVD_7;
	TxDataHandler21_CAN3[43]=u16RSVD_7>>8;

	TxDataHandler21_CAN3[44]=u16RSVD_8;
	TxDataHandler21_CAN3[45]=u16RSVD_8>>8;

	TxDataHandler21_CAN3[46]=u16RSVD_9;
	TxDataHandler21_CAN3[47]=u16RSVD_9>>8;

	TxDataHandler21_CAN3[48]=u16RSVD_10;
	TxDataHandler21_CAN3[49]=u16RSVD_10>>8;

	TxDataHandler21_CAN3[50]=u16RSVD_11;
	TxDataHandler21_CAN3[51]=u16RSVD_11>>8;

	TxDataHandler21_CAN3[52]=u16RSVD_12;
	TxDataHandler21_CAN3[53]=u16RSVD_12>>8;

	TxDataHandler21_CAN3[54]=u16RSVD_13;
	TxDataHandler21_CAN3[55]=u16RSVD_13>>8;

	TxDataHandler21_CAN3[56]=u16RSVD_14;
	TxDataHandler21_CAN3[57]=u16RSVD_14>>8;

	TxDataHandler21_CAN3[58]=u16RSVD_15;
	TxDataHandler21_CAN3[59]=u16RSVD_15>>8;

	TxDataHandler21_CAN3[60]=u16RSVD_16;
	TxDataHandler21_CAN3[61]=u16RSVD_16>>8;

	TxDataHandler21_CAN3[62]=u16RSVD_17;
	TxDataHandler21_CAN3[63]=u16RSVD_17>>8;

	if (HAL_FDCAN_AddMessageToTxFifoQ(&hfdcan3, &TxHeader21_CAN3, TxDataHandler21_CAN3) != HAL_OK)
	{}
	else
	{}
	HAL_Delay(1);
}
//22
void Master_To_Monitor_Frame23_Slave22(float Diode_Temperature,float Transformer_Temperature,float FEC_Temperature,float PSFB_Temperature,float DC_Busvoltage,float DC_Bus_Current,float FEC_input_Current,float PSFB_Output_Voltage,
		float PSFB_Output_Current,uint16_t SFault1_2,uint16_t SFault3_4,uint16_t SFault5_6,uint16_t SFault7_8,uint16_t SStatus1_2,uint16_t SStatus3_4,uint16_t RSVD_1,
		uint16_t RSVD_2,uint16_t RSVD_3,uint16_t RSVD_4,uint16_t RSVD_5,uint16_t RSVD_6,uint16_t RSVD_7,uint16_t RSVD_8,uint16_t RSVD_9,
		uint16_t RSVD_10,uint16_t RSVD_11,uint16_t RSVD_12,uint16_t RSVD_13,uint16_t RSVD_14,uint16_t RSVD_15,uint16_t RSVD_16,uint16_t RSVD_17)
{

	uint16_t u16Diode_Temperature=(Diode_Temperature*MULTIFACTOR_10);
	uint16_t u16Transformer_Temperature=(Transformer_Temperature*MULTIFACTOR_10);
	uint16_t u16FEC_Temperature=(FEC_Temperature*MULTIFACTOR_10);

	uint16_t u16PSFB_Temperature=(PSFB_Temperature*MULTIFACTOR_10);
	uint16_t u16DC_Busvoltage=(DC_Busvoltage*MULTIFACTOR_10);
	uint16_t u16DC_Bus_Current=(DC_Bus_Current*MULTIFACTOR_10);

	uint16_t u16FEC_input_Current=(FEC_input_Current*MULTIFACTOR_10);
	uint16_t u16PSFB_Output_Voltage=(PSFB_Output_Voltage*MULTIFACTOR_10);
	uint16_t u16PSFB_Output_Current=(PSFB_Output_Current*MULTIFACTOR_10);

	uint16_t u16SFault1_2=(SFault1_2);
	uint16_t u16SFault3_4=(SFault3_4);
	uint16_t u16SFault5_6=(SFault5_6);
	uint16_t u16SFault7_8=(SFault7_8);

	uint16_t u16SStatus1_2=(SStatus1_2);
	uint16_t u16SStatus3_4=(SStatus3_4);

	uint16_t u16RSVD_1=(RSVD_1);
	uint16_t u16RSVD_2=(RSVD_2);
	uint16_t u16RSVD_3=(RSVD_3);
	uint16_t u16RSVD_4=(RSVD_4);
	uint16_t u16RSVD_5=(RSVD_5);
	uint16_t u16RSVD_6=(RSVD_6);
	uint16_t u16RSVD_7=(RSVD_7);
	uint16_t u16RSVD_8=(RSVD_8);
	uint16_t u16RSVD_9=(RSVD_9);
	uint16_t u16RSVD_10=(RSVD_10);
	uint16_t u16RSVD_11=(RSVD_11);
	uint16_t u16RSVD_12=(RSVD_12);
	uint16_t u16RSVD_13=(RSVD_13);
	uint16_t u16RSVD_14=(RSVD_14);
	uint16_t u16RSVD_15=(RSVD_15);
	uint16_t u16RSVD_16=(RSVD_16);
	uint16_t u16RSVD_17=(RSVD_17);


	TxDataHandler22_CAN3[0]=u16Diode_Temperature;
	TxDataHandler22_CAN3[1]=u16Diode_Temperature>>8;

	TxDataHandler22_CAN3[2]=u16Transformer_Temperature;
	TxDataHandler22_CAN3[3]=u16Transformer_Temperature>>8;

	TxDataHandler22_CAN3[4]=u16FEC_Temperature;
	TxDataHandler22_CAN3[5]=u16FEC_Temperature>>8;

	TxDataHandler22_CAN3[6]=u16PSFB_Temperature;
	TxDataHandler22_CAN3[7]=u16PSFB_Temperature>>8;

	TxDataHandler22_CAN3[8]=u16DC_Busvoltage;
	TxDataHandler22_CAN3[9]=u16DC_Busvoltage>>8;

	TxDataHandler22_CAN3[10]=u16DC_Bus_Current;
	TxDataHandler22_CAN3[11]=u16DC_Bus_Current>>8;

	TxDataHandler22_CAN3[12]=u16FEC_input_Current;
	TxDataHandler22_CAN3[13]=u16FEC_input_Current>>8;

	TxDataHandler22_CAN3[14]=u16PSFB_Output_Voltage;
	TxDataHandler22_CAN3[15]=u16PSFB_Output_Voltage>>8;

	TxDataHandler22_CAN3[16]=u16PSFB_Output_Current;
	TxDataHandler22_CAN3[17]=u16PSFB_Output_Current>>8;

	TxDataHandler22_CAN3[18]=u16SFault1_2;
	TxDataHandler22_CAN3[19]=u16SFault1_2>>8;

	TxDataHandler22_CAN3[20]=u16SFault3_4;
	TxDataHandler22_CAN3[21]=u16SFault3_4>>8;

	TxDataHandler22_CAN3[22]=u16SFault5_6;
	TxDataHandler22_CAN3[23]=u16SFault5_6>>8;

	TxDataHandler22_CAN3[24]=u16SFault7_8;
	TxDataHandler22_CAN3[25]=u16SFault7_8>>8;

	TxDataHandler22_CAN3[26]=u16SStatus1_2;
	TxDataHandler22_CAN3[27]=u16SStatus1_2>>8;

	TxDataHandler22_CAN3[28]=u16SStatus3_4;
	TxDataHandler22_CAN3[29]=u16SStatus3_4>>8;

	TxDataHandler22_CAN3[30]=u16RSVD_1;
	TxDataHandler22_CAN3[31]=u16RSVD_1>>8;

	TxDataHandler22_CAN3[32]=u16RSVD_2;
	TxDataHandler22_CAN3[33]=u16RSVD_2>>8;

	TxDataHandler22_CAN3[34]=u16RSVD_3;
	TxDataHandler22_CAN3[35]=u16RSVD_3>>8;

	TxDataHandler22_CAN3[36]=u16RSVD_4;
	TxDataHandler22_CAN3[37]=u16RSVD_4>>8;

	TxDataHandler22_CAN3[38]=u16RSVD_5;
	TxDataHandler22_CAN3[39]=u16RSVD_5>>8;

	TxDataHandler22_CAN3[40]=u16RSVD_6;
	TxDataHandler22_CAN3[41]=u16RSVD_6>>8;

	TxDataHandler22_CAN3[42]=u16RSVD_7;
	TxDataHandler22_CAN3[43]=u16RSVD_7>>8;

	TxDataHandler22_CAN3[44]=u16RSVD_8;
	TxDataHandler22_CAN3[45]=u16RSVD_8>>8;

	TxDataHandler22_CAN3[46]=u16RSVD_9;
	TxDataHandler22_CAN3[47]=u16RSVD_9>>8;

	TxDataHandler22_CAN3[48]=u16RSVD_10;
	TxDataHandler22_CAN3[49]=u16RSVD_10>>8;

	TxDataHandler22_CAN3[50]=u16RSVD_11;
	TxDataHandler22_CAN3[51]=u16RSVD_11>>8;

	TxDataHandler22_CAN3[52]=u16RSVD_12;
	TxDataHandler22_CAN3[53]=u16RSVD_12>>8;

	TxDataHandler22_CAN3[54]=u16RSVD_13;
	TxDataHandler22_CAN3[55]=u16RSVD_13>>8;

	TxDataHandler22_CAN3[56]=u16RSVD_14;
	TxDataHandler22_CAN3[57]=u16RSVD_14>>8;

	TxDataHandler22_CAN3[58]=u16RSVD_15;
	TxDataHandler22_CAN3[59]=u16RSVD_15>>8;

	TxDataHandler22_CAN3[60]=u16RSVD_16;
	TxDataHandler22_CAN3[61]=u16RSVD_16>>8;

	TxDataHandler22_CAN3[62]=u16RSVD_17;
	TxDataHandler22_CAN3[63]=u16RSVD_17>>8;

	if (HAL_FDCAN_AddMessageToTxFifoQ(&hfdcan3, &TxHeader22_CAN3, TxDataHandler22_CAN3) != HAL_OK)
	{}
	else
	{}
	HAL_Delay(1);
}
//23
void Master_To_Monitor_Frame24_Slave23(float Diode_Temperature,float Transformer_Temperature,float FEC_Temperature,float PSFB_Temperature,float DC_Busvoltage,float DC_Bus_Current,float FEC_input_Current,float PSFB_Output_Voltage,
		float PSFB_Output_Current,uint16_t SFault1_2,uint16_t SFault3_4,uint16_t SFault5_6,uint16_t SFault7_8,uint16_t SStatus1_2,uint16_t SStatus3_4,uint16_t RSVD_1,
		uint16_t RSVD_2,uint16_t RSVD_3,uint16_t RSVD_4,uint16_t RSVD_5,uint16_t RSVD_6,uint16_t RSVD_7,uint16_t RSVD_8,uint16_t RSVD_9,
		uint16_t RSVD_10,uint16_t RSVD_11,uint16_t RSVD_12,uint16_t RSVD_13,uint16_t RSVD_14,uint16_t RSVD_15,uint16_t RSVD_16,uint16_t RSVD_17)
{

	uint16_t u16Diode_Temperature=(Diode_Temperature*MULTIFACTOR_10);
	uint16_t u16Transformer_Temperature=(Transformer_Temperature*MULTIFACTOR_10);
	uint16_t u16FEC_Temperature=(FEC_Temperature*MULTIFACTOR_10);

	uint16_t u16PSFB_Temperature=(PSFB_Temperature*MULTIFACTOR_10);
	uint16_t u16DC_Busvoltage=(DC_Busvoltage*MULTIFACTOR_10);
	uint16_t u16DC_Bus_Current=(DC_Bus_Current*MULTIFACTOR_10);

	uint16_t u16FEC_input_Current=(FEC_input_Current*MULTIFACTOR_10);
	uint16_t u16PSFB_Output_Voltage=(PSFB_Output_Voltage*MULTIFACTOR_10);
	uint16_t u16PSFB_Output_Current=(PSFB_Output_Current*MULTIFACTOR_10);

	uint16_t u16SFault1_2=(SFault1_2);
	uint16_t u16SFault3_4=(SFault3_4);
	uint16_t u16SFault5_6=(SFault5_6);
	uint16_t u16SFault7_8=(SFault7_8);

	uint16_t u16SStatus1_2=(SStatus1_2);
	uint16_t u16SStatus3_4=(SStatus3_4);

	uint16_t u16RSVD_1=(RSVD_1);
	uint16_t u16RSVD_2=(RSVD_2);
	uint16_t u16RSVD_3=(RSVD_3);
	uint16_t u16RSVD_4=(RSVD_4);
	uint16_t u16RSVD_5=(RSVD_5);
	uint16_t u16RSVD_6=(RSVD_6);
	uint16_t u16RSVD_7=(RSVD_7);
	uint16_t u16RSVD_8=(RSVD_8);
	uint16_t u16RSVD_9=(RSVD_9);
	uint16_t u16RSVD_10=(RSVD_10);
	uint16_t u16RSVD_11=(RSVD_11);
	uint16_t u16RSVD_12=(RSVD_12);
	uint16_t u16RSVD_13=(RSVD_13);
	uint16_t u16RSVD_14=(RSVD_14);
	uint16_t u16RSVD_15=(RSVD_15);
	uint16_t u16RSVD_16=(RSVD_16);
	uint16_t u16RSVD_17=(RSVD_17);


	TxDataHandler23_CAN3[0]=u16Diode_Temperature;
	TxDataHandler23_CAN3[1]=u16Diode_Temperature>>8;

	TxDataHandler23_CAN3[2]=u16Transformer_Temperature;
	TxDataHandler23_CAN3[3]=u16Transformer_Temperature>>8;

	TxDataHandler23_CAN3[4]=u16FEC_Temperature;
	TxDataHandler23_CAN3[5]=u16FEC_Temperature>>8;

	TxDataHandler23_CAN3[6]=u16PSFB_Temperature;
	TxDataHandler23_CAN3[7]=u16PSFB_Temperature>>8;

	TxDataHandler23_CAN3[8]=u16DC_Busvoltage;
	TxDataHandler23_CAN3[9]=u16DC_Busvoltage>>8;

	TxDataHandler23_CAN3[10]=u16DC_Bus_Current;
	TxDataHandler23_CAN3[11]=u16DC_Bus_Current>>8;

	TxDataHandler23_CAN3[12]=u16FEC_input_Current;
	TxDataHandler23_CAN3[13]=u16FEC_input_Current>>8;

	TxDataHandler23_CAN3[14]=u16PSFB_Output_Voltage;
	TxDataHandler23_CAN3[15]=u16PSFB_Output_Voltage>>8;

	TxDataHandler23_CAN3[16]=u16PSFB_Output_Current;
	TxDataHandler23_CAN3[17]=u16PSFB_Output_Current>>8;

	TxDataHandler23_CAN3[18]=u16SFault1_2;
	TxDataHandler23_CAN3[19]=u16SFault1_2>>8;

	TxDataHandler23_CAN3[20]=u16SFault3_4;
	TxDataHandler23_CAN3[21]=u16SFault3_4>>8;

	TxDataHandler23_CAN3[22]=u16SFault5_6;
	TxDataHandler23_CAN3[23]=u16SFault5_6>>8;

	TxDataHandler23_CAN3[24]=u16SFault7_8;
	TxDataHandler23_CAN3[25]=u16SFault7_8>>8;

	TxDataHandler23_CAN3[26]=u16SStatus1_2;
	TxDataHandler23_CAN3[27]=u16SStatus1_2>>8;

	TxDataHandler23_CAN3[28]=u16SStatus3_4;
	TxDataHandler23_CAN3[29]=u16SStatus3_4>>8;

	TxDataHandler23_CAN3[30]=u16RSVD_1;
	TxDataHandler23_CAN3[31]=u16RSVD_1>>8;

	TxDataHandler23_CAN3[32]=u16RSVD_2;
	TxDataHandler23_CAN3[33]=u16RSVD_2>>8;

	TxDataHandler23_CAN3[34]=u16RSVD_3;
	TxDataHandler23_CAN3[35]=u16RSVD_3>>8;

	TxDataHandler23_CAN3[36]=u16RSVD_4;
	TxDataHandler23_CAN3[37]=u16RSVD_4>>8;

	TxDataHandler23_CAN3[38]=u16RSVD_5;
	TxDataHandler23_CAN3[39]=u16RSVD_5>>8;

	TxDataHandler23_CAN3[40]=u16RSVD_6;
	TxDataHandler23_CAN3[41]=u16RSVD_6>>8;

	TxDataHandler23_CAN3[42]=u16RSVD_7;
	TxDataHandler23_CAN3[43]=u16RSVD_7>>8;

	TxDataHandler23_CAN3[44]=u16RSVD_8;
	TxDataHandler23_CAN3[45]=u16RSVD_8>>8;

	TxDataHandler23_CAN3[46]=u16RSVD_9;
	TxDataHandler23_CAN3[47]=u16RSVD_9>>8;

	TxDataHandler23_CAN3[48]=u16RSVD_10;
	TxDataHandler23_CAN3[49]=u16RSVD_10>>8;

	TxDataHandler23_CAN3[50]=u16RSVD_11;
	TxDataHandler23_CAN3[51]=u16RSVD_11>>8;

	TxDataHandler23_CAN3[52]=u16RSVD_12;
	TxDataHandler23_CAN3[53]=u16RSVD_12>>8;

	TxDataHandler23_CAN3[54]=u16RSVD_13;
	TxDataHandler23_CAN3[55]=u16RSVD_13>>8;

	TxDataHandler23_CAN3[56]=u16RSVD_14;
	TxDataHandler23_CAN3[57]=u16RSVD_14>>8;

	TxDataHandler23_CAN3[58]=u16RSVD_15;
	TxDataHandler23_CAN3[59]=u16RSVD_15>>8;

	TxDataHandler23_CAN3[60]=u16RSVD_16;
	TxDataHandler23_CAN3[61]=u16RSVD_16>>8;

	TxDataHandler23_CAN3[62]=u16RSVD_17;
	TxDataHandler23_CAN3[63]=u16RSVD_17>>8;

	if (HAL_FDCAN_AddMessageToTxFifoQ(&hfdcan3, &TxHeader23_CAN3, TxDataHandler23_CAN3) != HAL_OK)
	{}
	else
	{}
	HAL_Delay(1);
}
//24
void Master_To_Monitor_Frame25_Slave24(float Diode_Temperature,float Transformer_Temperature,float FEC_Temperature,float PSFB_Temperature,float DC_Busvoltage,float DC_Bus_Current,float FEC_input_Current,float PSFB_Output_Voltage,
		float PSFB_Output_Current,uint16_t SFault1_2,uint16_t SFault3_4,uint16_t SFault5_6,uint16_t SFault7_8,uint16_t SStatus1_2,uint16_t SStatus3_4,uint16_t RSVD_1,
		uint16_t RSVD_2,uint16_t RSVD_3,uint16_t RSVD_4,uint16_t RSVD_5,uint16_t RSVD_6,uint16_t RSVD_7,uint16_t RSVD_8,uint16_t RSVD_9,
		uint16_t RSVD_10,uint16_t RSVD_11,uint16_t RSVD_12,uint16_t RSVD_13,uint16_t RSVD_14,uint16_t RSVD_15,uint16_t RSVD_16,uint16_t RSVD_17)
{

	uint16_t u16Diode_Temperature=(Diode_Temperature*MULTIFACTOR_10);
	uint16_t u16Transformer_Temperature=(Transformer_Temperature*MULTIFACTOR_10);
	uint16_t u16FEC_Temperature=(FEC_Temperature*MULTIFACTOR_10);

	uint16_t u16PSFB_Temperature=(PSFB_Temperature*MULTIFACTOR_10);
	uint16_t u16DC_Busvoltage=(DC_Busvoltage*MULTIFACTOR_10);
	uint16_t u16DC_Bus_Current=(DC_Bus_Current*MULTIFACTOR_10);

	uint16_t u16FEC_input_Current=(FEC_input_Current*MULTIFACTOR_10);
	uint16_t u16PSFB_Output_Voltage=(PSFB_Output_Voltage*MULTIFACTOR_10);
	uint16_t u16PSFB_Output_Current=(PSFB_Output_Current*MULTIFACTOR_10);

	uint16_t u16SFault1_2=(SFault1_2);
	uint16_t u16SFault3_4=(SFault3_4);
	uint16_t u16SFault5_6=(SFault5_6);
	uint16_t u16SFault7_8=(SFault7_8);

	uint16_t u16SStatus1_2=(SStatus1_2);
	uint16_t u16SStatus3_4=(SStatus3_4);

	uint16_t u16RSVD_1=(RSVD_1);
	uint16_t u16RSVD_2=(RSVD_2);
	uint16_t u16RSVD_3=(RSVD_3);
	uint16_t u16RSVD_4=(RSVD_4);
	uint16_t u16RSVD_5=(RSVD_5);
	uint16_t u16RSVD_6=(RSVD_6);
	uint16_t u16RSVD_7=(RSVD_7);
	uint16_t u16RSVD_8=(RSVD_8);
	uint16_t u16RSVD_9=(RSVD_9);
	uint16_t u16RSVD_10=(RSVD_10);
	uint16_t u16RSVD_11=(RSVD_11);
	uint16_t u16RSVD_12=(RSVD_12);
	uint16_t u16RSVD_13=(RSVD_13);
	uint16_t u16RSVD_14=(RSVD_14);
	uint16_t u16RSVD_15=(RSVD_15);
	uint16_t u16RSVD_16=(RSVD_16);
	uint16_t u16RSVD_17=(RSVD_17);


	TxDataHandler24_CAN3[0]=u16Diode_Temperature;
	TxDataHandler24_CAN3[1]=u16Diode_Temperature>>8;

	TxDataHandler24_CAN3[2]=u16Transformer_Temperature;
	TxDataHandler24_CAN3[3]=u16Transformer_Temperature>>8;

	TxDataHandler24_CAN3[4]=u16FEC_Temperature;
	TxDataHandler24_CAN3[5]=u16FEC_Temperature>>8;

	TxDataHandler24_CAN3[6]=u16PSFB_Temperature;
	TxDataHandler24_CAN3[7]=u16PSFB_Temperature>>8;

	TxDataHandler24_CAN3[8]=u16DC_Busvoltage;
	TxDataHandler24_CAN3[9]=u16DC_Busvoltage>>8;

	TxDataHandler24_CAN3[10]=u16DC_Bus_Current;
	TxDataHandler24_CAN3[11]=u16DC_Bus_Current>>8;

	TxDataHandler24_CAN3[12]=u16FEC_input_Current;
	TxDataHandler24_CAN3[13]=u16FEC_input_Current>>8;

	TxDataHandler24_CAN3[14]=u16PSFB_Output_Voltage;
	TxDataHandler24_CAN3[15]=u16PSFB_Output_Voltage>>8;

	TxDataHandler24_CAN3[16]=u16PSFB_Output_Current;
	TxDataHandler24_CAN3[17]=u16PSFB_Output_Current>>8;

	TxDataHandler24_CAN3[18]=u16SFault1_2;
	TxDataHandler24_CAN3[19]=u16SFault1_2>>8;

	TxDataHandler24_CAN3[20]=u16SFault3_4;
	TxDataHandler24_CAN3[21]=u16SFault3_4>>8;

	TxDataHandler24_CAN3[22]=u16SFault5_6;
	TxDataHandler24_CAN3[23]=u16SFault5_6>>8;

	TxDataHandler24_CAN3[24]=u16SFault7_8;
	TxDataHandler24_CAN3[25]=u16SFault7_8>>8;

	TxDataHandler24_CAN3[26]=u16SStatus1_2;
	TxDataHandler24_CAN3[27]=u16SStatus1_2>>8;

	TxDataHandler24_CAN3[28]=u16SStatus3_4;
	TxDataHandler24_CAN3[29]=u16SStatus3_4>>8;

	TxDataHandler24_CAN3[30]=u16RSVD_1;
	TxDataHandler24_CAN3[31]=u16RSVD_1>>8;

	TxDataHandler24_CAN3[32]=u16RSVD_2;
	TxDataHandler24_CAN3[33]=u16RSVD_2>>8;

	TxDataHandler24_CAN3[34]=u16RSVD_3;
	TxDataHandler24_CAN3[35]=u16RSVD_3>>8;

	TxDataHandler24_CAN3[36]=u16RSVD_4;
	TxDataHandler24_CAN3[37]=u16RSVD_4>>8;

	TxDataHandler24_CAN3[38]=u16RSVD_5;
	TxDataHandler24_CAN3[39]=u16RSVD_5>>8;

	TxDataHandler24_CAN3[40]=u16RSVD_6;
	TxDataHandler24_CAN3[41]=u16RSVD_6>>8;

	TxDataHandler24_CAN3[42]=u16RSVD_7;
	TxDataHandler24_CAN3[43]=u16RSVD_7>>8;

	TxDataHandler24_CAN3[44]=u16RSVD_8;
	TxDataHandler24_CAN3[45]=u16RSVD_8>>8;

	TxDataHandler24_CAN3[46]=u16RSVD_9;
	TxDataHandler24_CAN3[47]=u16RSVD_9>>8;

	TxDataHandler24_CAN3[48]=u16RSVD_10;
	TxDataHandler24_CAN3[49]=u16RSVD_10>>8;

	TxDataHandler24_CAN3[50]=u16RSVD_11;
	TxDataHandler24_CAN3[51]=u16RSVD_11>>8;

	TxDataHandler24_CAN3[52]=u16RSVD_12;
	TxDataHandler24_CAN3[53]=u16RSVD_12>>8;

	TxDataHandler24_CAN3[54]=u16RSVD_13;
	TxDataHandler24_CAN3[55]=u16RSVD_13>>8;

	TxDataHandler24_CAN3[56]=u16RSVD_14;
	TxDataHandler24_CAN3[57]=u16RSVD_14>>8;

	TxDataHandler24_CAN3[58]=u16RSVD_15;
	TxDataHandler24_CAN3[59]=u16RSVD_15>>8;

	TxDataHandler24_CAN3[60]=u16RSVD_16;
	TxDataHandler24_CAN3[61]=u16RSVD_16>>8;

	TxDataHandler24_CAN3[62]=u16RSVD_17;
	TxDataHandler24_CAN3[63]=u16RSVD_17>>8;

	if (HAL_FDCAN_AddMessageToTxFifoQ(&hfdcan3, &TxHeader24_CAN3, TxDataHandler24_CAN3) != HAL_OK)
	{}
	else
	{}
	HAL_Delay(1);
}
//25
void Master_To_Monitor_Frame26_Slave25(float Diode_Temperature,float Transformer_Temperature,float FEC_Temperature,float PSFB_Temperature,float DC_Busvoltage,float DC_Bus_Current,float FEC_input_Current,float PSFB_Output_Voltage,
		float PSFB_Output_Current,uint16_t SFault1_2,uint16_t SFault3_4,uint16_t SFault5_6,uint16_t SFault7_8,uint16_t SStatus1_2,uint16_t SStatus3_4,uint16_t RSVD_1,
		uint16_t RSVD_2,uint16_t RSVD_3,uint16_t RSVD_4,uint16_t RSVD_5,uint16_t RSVD_6,uint16_t RSVD_7,uint16_t RSVD_8,uint16_t RSVD_9,
		uint16_t RSVD_10,uint16_t RSVD_11,uint16_t RSVD_12,uint16_t RSVD_13,uint16_t RSVD_14,uint16_t RSVD_15,uint16_t RSVD_16,uint16_t RSVD_17)
{

	uint16_t u16Diode_Temperature=(Diode_Temperature*MULTIFACTOR_10);
	uint16_t u16Transformer_Temperature=(Transformer_Temperature*MULTIFACTOR_10);
	uint16_t u16FEC_Temperature=(FEC_Temperature*MULTIFACTOR_10);

	uint16_t u16PSFB_Temperature=(PSFB_Temperature*MULTIFACTOR_10);
	uint16_t u16DC_Busvoltage=(DC_Busvoltage*MULTIFACTOR_10);
	uint16_t u16DC_Bus_Current=(DC_Bus_Current*MULTIFACTOR_10);

	uint16_t u16FEC_input_Current=(FEC_input_Current*MULTIFACTOR_10);
	uint16_t u16PSFB_Output_Voltage=(PSFB_Output_Voltage*MULTIFACTOR_10);
	uint16_t u16PSFB_Output_Current=(PSFB_Output_Current*MULTIFACTOR_10);

	uint16_t u16SFault1_2=(SFault1_2);
	uint16_t u16SFault3_4=(SFault3_4);
	uint16_t u16SFault5_6=(SFault5_6);
	uint16_t u16SFault7_8=(SFault7_8);

	uint16_t u16SStatus1_2=(SStatus1_2);
	uint16_t u16SStatus3_4=(SStatus3_4);

	uint16_t u16RSVD_1=(RSVD_1);
	uint16_t u16RSVD_2=(RSVD_2);
	uint16_t u16RSVD_3=(RSVD_3);
	uint16_t u16RSVD_4=(RSVD_4);
	uint16_t u16RSVD_5=(RSVD_5);
	uint16_t u16RSVD_6=(RSVD_6);
	uint16_t u16RSVD_7=(RSVD_7);
	uint16_t u16RSVD_8=(RSVD_8);
	uint16_t u16RSVD_9=(RSVD_9);
	uint16_t u16RSVD_10=(RSVD_10);
	uint16_t u16RSVD_11=(RSVD_11);
	uint16_t u16RSVD_12=(RSVD_12);
	uint16_t u16RSVD_13=(RSVD_13);
	uint16_t u16RSVD_14=(RSVD_14);
	uint16_t u16RSVD_15=(RSVD_15);
	uint16_t u16RSVD_16=(RSVD_16);
	uint16_t u16RSVD_17=(RSVD_17);


	TxDataHandler25_CAN3[0]=u16Diode_Temperature;
	TxDataHandler25_CAN3[1]=u16Diode_Temperature>>8;

	TxDataHandler25_CAN3[2]=u16Transformer_Temperature;
	TxDataHandler25_CAN3[3]=u16Transformer_Temperature>>8;

	TxDataHandler25_CAN3[4]=u16FEC_Temperature;
	TxDataHandler25_CAN3[5]=u16FEC_Temperature>>8;

	TxDataHandler25_CAN3[6]=u16PSFB_Temperature;
	TxDataHandler25_CAN3[7]=u16PSFB_Temperature>>8;

	TxDataHandler25_CAN3[8]=u16DC_Busvoltage;
	TxDataHandler25_CAN3[9]=u16DC_Busvoltage>>8;

	TxDataHandler25_CAN3[10]=u16DC_Bus_Current;
	TxDataHandler25_CAN3[11]=u16DC_Bus_Current>>8;

	TxDataHandler25_CAN3[12]=u16FEC_input_Current;
	TxDataHandler25_CAN3[13]=u16FEC_input_Current>>8;

	TxDataHandler25_CAN3[14]=u16PSFB_Output_Voltage;
	TxDataHandler25_CAN3[15]=u16PSFB_Output_Voltage>>8;

	TxDataHandler25_CAN3[16]=u16PSFB_Output_Current;
	TxDataHandler25_CAN3[17]=u16PSFB_Output_Current>>8;

	TxDataHandler25_CAN3[18]=u16SFault1_2;
	TxDataHandler25_CAN3[19]=u16SFault1_2>>8;

	TxDataHandler25_CAN3[20]=u16SFault3_4;
	TxDataHandler25_CAN3[21]=u16SFault3_4>>8;

	TxDataHandler25_CAN3[22]=u16SFault5_6;
	TxDataHandler25_CAN3[23]=u16SFault5_6>>8;

	TxDataHandler25_CAN3[24]=u16SFault7_8;
	TxDataHandler25_CAN3[25]=u16SFault7_8>>8;

	TxDataHandler25_CAN3[26]=u16SStatus1_2;
	TxDataHandler25_CAN3[27]=u16SStatus1_2>>8;

	TxDataHandler25_CAN3[28]=u16SStatus3_4;
	TxDataHandler25_CAN3[29]=u16SStatus3_4>>8;

	TxDataHandler25_CAN3[30]=u16RSVD_1;
	TxDataHandler25_CAN3[31]=u16RSVD_1>>8;

	TxDataHandler25_CAN3[32]=u16RSVD_2;
	TxDataHandler25_CAN3[33]=u16RSVD_2>>8;

	TxDataHandler25_CAN3[34]=u16RSVD_3;
	TxDataHandler25_CAN3[35]=u16RSVD_3>>8;

	TxDataHandler25_CAN3[36]=u16RSVD_4;
	TxDataHandler25_CAN3[37]=u16RSVD_4>>8;

	TxDataHandler25_CAN3[38]=u16RSVD_5;
	TxDataHandler25_CAN3[39]=u16RSVD_5>>8;

	TxDataHandler25_CAN3[40]=u16RSVD_6;
	TxDataHandler25_CAN3[41]=u16RSVD_6>>8;

	TxDataHandler25_CAN3[42]=u16RSVD_7;
	TxDataHandler25_CAN3[43]=u16RSVD_7>>8;

	TxDataHandler25_CAN3[44]=u16RSVD_8;
	TxDataHandler25_CAN3[45]=u16RSVD_8>>8;

	TxDataHandler25_CAN3[46]=u16RSVD_9;
	TxDataHandler25_CAN3[47]=u16RSVD_9>>8;

	TxDataHandler25_CAN3[48]=u16RSVD_10;
	TxDataHandler25_CAN3[49]=u16RSVD_10>>8;

	TxDataHandler25_CAN3[50]=u16RSVD_11;
	TxDataHandler25_CAN3[51]=u16RSVD_11>>8;

	TxDataHandler25_CAN3[52]=u16RSVD_12;
	TxDataHandler25_CAN3[53]=u16RSVD_12>>8;

	TxDataHandler25_CAN3[54]=u16RSVD_13;
	TxDataHandler25_CAN3[55]=u16RSVD_13>>8;

	TxDataHandler25_CAN3[56]=u16RSVD_14;
	TxDataHandler25_CAN3[57]=u16RSVD_14>>8;

	TxDataHandler25_CAN3[58]=u16RSVD_15;
	TxDataHandler25_CAN3[59]=u16RSVD_15>>8;

	TxDataHandler25_CAN3[60]=u16RSVD_16;
	TxDataHandler25_CAN3[61]=u16RSVD_16>>8;

	TxDataHandler25_CAN3[62]=u16RSVD_17;
	TxDataHandler25_CAN3[63]=u16RSVD_17>>8;

	if (HAL_FDCAN_AddMessageToTxFifoQ(&hfdcan3, &TxHeader25_CAN3, TxDataHandler25_CAN3) != HAL_OK)
	{}
	else
	{}
	HAL_Delay(1);
}
//26
void Master_To_Monitor_Frame27_Slave26(float Diode_Temperature,float Transformer_Temperature,float FEC_Temperature,float PSFB_Temperature,float DC_Busvoltage,float DC_Bus_Current,float FEC_input_Current,float PSFB_Output_Voltage,
		float PSFB_Output_Current,uint16_t SFault1_2,uint16_t SFault3_4,uint16_t SFault5_6,uint16_t SFault7_8,uint16_t SStatus1_2,uint16_t SStatus3_4,uint16_t RSVD_1,
		uint16_t RSVD_2,uint16_t RSVD_3,uint16_t RSVD_4,uint16_t RSVD_5,uint16_t RSVD_6,uint16_t RSVD_7,uint16_t RSVD_8,uint16_t RSVD_9,
		uint16_t RSVD_10,uint16_t RSVD_11,uint16_t RSVD_12,uint16_t RSVD_13,uint16_t RSVD_14,uint16_t RSVD_15,uint16_t RSVD_16,uint16_t RSVD_17)
{

	uint16_t u16Diode_Temperature=(Diode_Temperature*MULTIFACTOR_10);
	uint16_t u16Transformer_Temperature=(Transformer_Temperature*MULTIFACTOR_10);
	uint16_t u16FEC_Temperature=(FEC_Temperature*MULTIFACTOR_10);

	uint16_t u16PSFB_Temperature=(PSFB_Temperature*MULTIFACTOR_10);
	uint16_t u16DC_Busvoltage=(DC_Busvoltage*MULTIFACTOR_10);
	uint16_t u16DC_Bus_Current=(DC_Bus_Current*MULTIFACTOR_10);

	uint16_t u16FEC_input_Current=(FEC_input_Current*MULTIFACTOR_10);
	uint16_t u16PSFB_Output_Voltage=(PSFB_Output_Voltage*MULTIFACTOR_10);
	uint16_t u16PSFB_Output_Current=(PSFB_Output_Current*MULTIFACTOR_10);

	uint16_t u16SFault1_2=(SFault1_2);
	uint16_t u16SFault3_4=(SFault3_4);
	uint16_t u16SFault5_6=(SFault5_6);
	uint16_t u16SFault7_8=(SFault7_8);

	uint16_t u16SStatus1_2=(SStatus1_2);
	uint16_t u16SStatus3_4=(SStatus3_4);

	uint16_t u16RSVD_1=(RSVD_1);
	uint16_t u16RSVD_2=(RSVD_2);
	uint16_t u16RSVD_3=(RSVD_3);
	uint16_t u16RSVD_4=(RSVD_4);
	uint16_t u16RSVD_5=(RSVD_5);
	uint16_t u16RSVD_6=(RSVD_6);
	uint16_t u16RSVD_7=(RSVD_7);
	uint16_t u16RSVD_8=(RSVD_8);
	uint16_t u16RSVD_9=(RSVD_9);
	uint16_t u16RSVD_10=(RSVD_10);
	uint16_t u16RSVD_11=(RSVD_11);
	uint16_t u16RSVD_12=(RSVD_12);
	uint16_t u16RSVD_13=(RSVD_13);
	uint16_t u16RSVD_14=(RSVD_14);
	uint16_t u16RSVD_15=(RSVD_15);
	uint16_t u16RSVD_16=(RSVD_16);
	uint16_t u16RSVD_17=(RSVD_17);


	TxDataHandler26_CAN3[0]=u16Diode_Temperature;
	TxDataHandler26_CAN3[1]=u16Diode_Temperature>>8;

	TxDataHandler26_CAN3[2]=u16Transformer_Temperature;
	TxDataHandler26_CAN3[3]=u16Transformer_Temperature>>8;

	TxDataHandler26_CAN3[4]=u16FEC_Temperature;
	TxDataHandler26_CAN3[5]=u16FEC_Temperature>>8;

	TxDataHandler26_CAN3[6]=u16PSFB_Temperature;
	TxDataHandler26_CAN3[7]=u16PSFB_Temperature>>8;

	TxDataHandler26_CAN3[8]=u16DC_Busvoltage;
	TxDataHandler26_CAN3[9]=u16DC_Busvoltage>>8;

	TxDataHandler26_CAN3[10]=u16DC_Bus_Current;
	TxDataHandler26_CAN3[11]=u16DC_Bus_Current>>8;

	TxDataHandler26_CAN3[12]=u16FEC_input_Current;
	TxDataHandler26_CAN3[13]=u16FEC_input_Current>>8;

	TxDataHandler26_CAN3[14]=u16PSFB_Output_Voltage;
	TxDataHandler26_CAN3[15]=u16PSFB_Output_Voltage>>8;

	TxDataHandler26_CAN3[16]=u16PSFB_Output_Current;
	TxDataHandler26_CAN3[17]=u16PSFB_Output_Current>>8;

	TxDataHandler26_CAN3[18]=u16SFault1_2;
	TxDataHandler26_CAN3[19]=u16SFault1_2>>8;

	TxDataHandler26_CAN3[20]=u16SFault3_4;
	TxDataHandler26_CAN3[21]=u16SFault3_4>>8;

	TxDataHandler26_CAN3[22]=u16SFault5_6;
	TxDataHandler26_CAN3[23]=u16SFault5_6>>8;

	TxDataHandler26_CAN3[24]=u16SFault7_8;
	TxDataHandler26_CAN3[25]=u16SFault7_8>>8;

	TxDataHandler26_CAN3[26]=u16SStatus1_2;
	TxDataHandler26_CAN3[27]=u16SStatus1_2>>8;

	TxDataHandler26_CAN3[28]=u16SStatus3_4;
	TxDataHandler26_CAN3[29]=u16SStatus3_4>>8;

	TxDataHandler26_CAN3[30]=u16RSVD_1;
	TxDataHandler26_CAN3[31]=u16RSVD_1>>8;

	TxDataHandler26_CAN3[32]=u16RSVD_2;
	TxDataHandler26_CAN3[33]=u16RSVD_2>>8;

	TxDataHandler26_CAN3[34]=u16RSVD_3;
	TxDataHandler26_CAN3[35]=u16RSVD_3>>8;

	TxDataHandler26_CAN3[36]=u16RSVD_4;
	TxDataHandler26_CAN3[37]=u16RSVD_4>>8;

	TxDataHandler26_CAN3[38]=u16RSVD_5;
	TxDataHandler26_CAN3[39]=u16RSVD_5>>8;

	TxDataHandler26_CAN3[40]=u16RSVD_6;
	TxDataHandler26_CAN3[41]=u16RSVD_6>>8;

	TxDataHandler26_CAN3[42]=u16RSVD_7;
	TxDataHandler26_CAN3[43]=u16RSVD_7>>8;

	TxDataHandler26_CAN3[44]=u16RSVD_8;
	TxDataHandler26_CAN3[45]=u16RSVD_8>>8;

	TxDataHandler26_CAN3[46]=u16RSVD_9;
	TxDataHandler26_CAN3[47]=u16RSVD_9>>8;

	TxDataHandler26_CAN3[48]=u16RSVD_10;
	TxDataHandler26_CAN3[49]=u16RSVD_10>>8;

	TxDataHandler26_CAN3[50]=u16RSVD_11;
	TxDataHandler26_CAN3[51]=u16RSVD_11>>8;

	TxDataHandler26_CAN3[52]=u16RSVD_12;
	TxDataHandler26_CAN3[53]=u16RSVD_12>>8;

	TxDataHandler26_CAN3[54]=u16RSVD_13;
	TxDataHandler26_CAN3[55]=u16RSVD_13>>8;

	TxDataHandler26_CAN3[56]=u16RSVD_14;
	TxDataHandler26_CAN3[57]=u16RSVD_14>>8;

	TxDataHandler26_CAN3[58]=u16RSVD_15;
	TxDataHandler26_CAN3[59]=u16RSVD_15>>8;

	TxDataHandler26_CAN3[60]=u16RSVD_16;
	TxDataHandler26_CAN3[61]=u16RSVD_16>>8;

	TxDataHandler26_CAN3[62]=u16RSVD_17;
	TxDataHandler26_CAN3[63]=u16RSVD_17>>8;

	if (HAL_FDCAN_AddMessageToTxFifoQ(&hfdcan3, &TxHeader26_CAN3, TxDataHandler26_CAN3) != HAL_OK)
	{}
	else
	{}
	HAL_Delay(1);
}
//27
void Master_To_Monitor_Frame28_Slave27(float Diode_Temperature,float Transformer_Temperature,float FEC_Temperature,float PSFB_Temperature,float DC_Busvoltage,float DC_Bus_Current,float FEC_input_Current,float PSFB_Output_Voltage,
		float PSFB_Output_Current,uint16_t SFault1_2,uint16_t SFault3_4,uint16_t SFault5_6,uint16_t SFault7_8,uint16_t SStatus1_2,uint16_t SStatus3_4,uint16_t RSVD_1,
		uint16_t RSVD_2,uint16_t RSVD_3,uint16_t RSVD_4,uint16_t RSVD_5,uint16_t RSVD_6,uint16_t RSVD_7,uint16_t RSVD_8,uint16_t RSVD_9,
		uint16_t RSVD_10,uint16_t RSVD_11,uint16_t RSVD_12,uint16_t RSVD_13,uint16_t RSVD_14,uint16_t RSVD_15,uint16_t RSVD_16,uint16_t RSVD_17)
{

	uint16_t u16Diode_Temperature=(Diode_Temperature*MULTIFACTOR_10);
	uint16_t u16Transformer_Temperature=(Transformer_Temperature*MULTIFACTOR_10);
	uint16_t u16FEC_Temperature=(FEC_Temperature*MULTIFACTOR_10);

	uint16_t u16PSFB_Temperature=(PSFB_Temperature*MULTIFACTOR_10);
	uint16_t u16DC_Busvoltage=(DC_Busvoltage*MULTIFACTOR_10);
	uint16_t u16DC_Bus_Current=(DC_Bus_Current*MULTIFACTOR_10);

	uint16_t u16FEC_input_Current=(FEC_input_Current*MULTIFACTOR_10);
	uint16_t u16PSFB_Output_Voltage=(PSFB_Output_Voltage*MULTIFACTOR_10);
	uint16_t u16PSFB_Output_Current=(PSFB_Output_Current*MULTIFACTOR_10);

	uint16_t u16SFault1_2=(SFault1_2);
	uint16_t u16SFault3_4=(SFault3_4);
	uint16_t u16SFault5_6=(SFault5_6);
	uint16_t u16SFault7_8=(SFault7_8);

	uint16_t u16SStatus1_2=(SStatus1_2);
	uint16_t u16SStatus3_4=(SStatus3_4);

	uint16_t u16RSVD_1=(RSVD_1);
	uint16_t u16RSVD_2=(RSVD_2);
	uint16_t u16RSVD_3=(RSVD_3);
	uint16_t u16RSVD_4=(RSVD_4);
	uint16_t u16RSVD_5=(RSVD_5);
	uint16_t u16RSVD_6=(RSVD_6);
	uint16_t u16RSVD_7=(RSVD_7);
	uint16_t u16RSVD_8=(RSVD_8);
	uint16_t u16RSVD_9=(RSVD_9);
	uint16_t u16RSVD_10=(RSVD_10);
	uint16_t u16RSVD_11=(RSVD_11);
	uint16_t u16RSVD_12=(RSVD_12);
	uint16_t u16RSVD_13=(RSVD_13);
	uint16_t u16RSVD_14=(RSVD_14);
	uint16_t u16RSVD_15=(RSVD_15);
	uint16_t u16RSVD_16=(RSVD_16);
	uint16_t u16RSVD_17=(RSVD_17);


	TxDataHandler27_CAN3[0]=u16Diode_Temperature;
	TxDataHandler27_CAN3[1]=u16Diode_Temperature>>8;

	TxDataHandler27_CAN3[2]=u16Transformer_Temperature;
	TxDataHandler27_CAN3[3]=u16Transformer_Temperature>>8;

	TxDataHandler27_CAN3[4]=u16FEC_Temperature;
	TxDataHandler27_CAN3[5]=u16FEC_Temperature>>8;

	TxDataHandler27_CAN3[6]=u16PSFB_Temperature;
	TxDataHandler27_CAN3[7]=u16PSFB_Temperature>>8;

	TxDataHandler27_CAN3[8]=u16DC_Busvoltage;
	TxDataHandler27_CAN3[9]=u16DC_Busvoltage>>8;

	TxDataHandler27_CAN3[10]=u16DC_Bus_Current;
	TxDataHandler27_CAN3[11]=u16DC_Bus_Current>>8;

	TxDataHandler27_CAN3[12]=u16FEC_input_Current;
	TxDataHandler27_CAN3[13]=u16FEC_input_Current>>8;

	TxDataHandler27_CAN3[14]=u16PSFB_Output_Voltage;
	TxDataHandler27_CAN3[15]=u16PSFB_Output_Voltage>>8;

	TxDataHandler27_CAN3[16]=u16PSFB_Output_Current;
	TxDataHandler27_CAN3[17]=u16PSFB_Output_Current>>8;

	TxDataHandler27_CAN3[18]=u16SFault1_2;
	TxDataHandler27_CAN3[19]=u16SFault1_2>>8;

	TxDataHandler27_CAN3[20]=u16SFault3_4;
	TxDataHandler27_CAN3[21]=u16SFault3_4>>8;

	TxDataHandler27_CAN3[22]=u16SFault5_6;
	TxDataHandler27_CAN3[23]=u16SFault5_6>>8;

	TxDataHandler27_CAN3[24]=u16SFault7_8;
	TxDataHandler27_CAN3[25]=u16SFault7_8>>8;

	TxDataHandler27_CAN3[26]=u16SStatus1_2;
	TxDataHandler27_CAN3[27]=u16SStatus1_2>>8;

	TxDataHandler27_CAN3[28]=u16SStatus3_4;
	TxDataHandler27_CAN3[29]=u16SStatus3_4>>8;

	TxDataHandler27_CAN3[30]=u16RSVD_1;
	TxDataHandler27_CAN3[31]=u16RSVD_1>>8;

	TxDataHandler27_CAN3[32]=u16RSVD_2;
	TxDataHandler27_CAN3[33]=u16RSVD_2>>8;

	TxDataHandler27_CAN3[34]=u16RSVD_3;
	TxDataHandler27_CAN3[35]=u16RSVD_3>>8;

	TxDataHandler27_CAN3[36]=u16RSVD_4;
	TxDataHandler27_CAN3[37]=u16RSVD_4>>8;

	TxDataHandler27_CAN3[38]=u16RSVD_5;
	TxDataHandler27_CAN3[39]=u16RSVD_5>>8;

	TxDataHandler27_CAN3[40]=u16RSVD_6;
	TxDataHandler27_CAN3[41]=u16RSVD_6>>8;

	TxDataHandler27_CAN3[42]=u16RSVD_7;
	TxDataHandler27_CAN3[43]=u16RSVD_7>>8;

	TxDataHandler27_CAN3[44]=u16RSVD_8;
	TxDataHandler27_CAN3[45]=u16RSVD_8>>8;

	TxDataHandler27_CAN3[46]=u16RSVD_9;
	TxDataHandler27_CAN3[47]=u16RSVD_9>>8;

	TxDataHandler27_CAN3[48]=u16RSVD_10;
	TxDataHandler27_CAN3[49]=u16RSVD_10>>8;

	TxDataHandler27_CAN3[50]=u16RSVD_11;
	TxDataHandler27_CAN3[51]=u16RSVD_11>>8;

	TxDataHandler27_CAN3[52]=u16RSVD_12;
	TxDataHandler27_CAN3[53]=u16RSVD_12>>8;

	TxDataHandler27_CAN3[54]=u16RSVD_13;
	TxDataHandler27_CAN3[55]=u16RSVD_13>>8;

	TxDataHandler27_CAN3[56]=u16RSVD_14;
	TxDataHandler27_CAN3[57]=u16RSVD_14>>8;

	TxDataHandler27_CAN3[58]=u16RSVD_15;
	TxDataHandler27_CAN3[59]=u16RSVD_15>>8;

	TxDataHandler27_CAN3[60]=u16RSVD_16;
	TxDataHandler27_CAN3[61]=u16RSVD_16>>8;

	TxDataHandler27_CAN3[62]=u16RSVD_17;
	TxDataHandler27_CAN3[63]=u16RSVD_17>>8;

	if (HAL_FDCAN_AddMessageToTxFifoQ(&hfdcan3, &TxHeader27_CAN3, TxDataHandler27_CAN3) != HAL_OK)
	{}
	else
	{}
	HAL_Delay(1);
}
//28
void Master_To_Monitor_Frame29_Slave28(float Diode_Temperature,float Transformer_Temperature,float FEC_Temperature,float PSFB_Temperature,float DC_Busvoltage,float DC_Bus_Current,float FEC_input_Current,float PSFB_Output_Voltage,
		float PSFB_Output_Current,uint16_t SFault1_2,uint16_t SFault3_4,uint16_t SFault5_6,uint16_t SFault7_8,uint16_t SStatus1_2,uint16_t SStatus3_4,uint16_t RSVD_1,
		uint16_t RSVD_2,uint16_t RSVD_3,uint16_t RSVD_4,uint16_t RSVD_5,uint16_t RSVD_6,uint16_t RSVD_7,uint16_t RSVD_8,uint16_t RSVD_9,
		uint16_t RSVD_10,uint16_t RSVD_11,uint16_t RSVD_12,uint16_t RSVD_13,uint16_t RSVD_14,uint16_t RSVD_15,uint16_t RSVD_16,uint16_t RSVD_17)
{

	uint16_t u16Diode_Temperature=(Diode_Temperature*MULTIFACTOR_10);
	uint16_t u16Transformer_Temperature=(Transformer_Temperature*MULTIFACTOR_10);
	uint16_t u16FEC_Temperature=(FEC_Temperature*MULTIFACTOR_10);

	uint16_t u16PSFB_Temperature=(PSFB_Temperature*MULTIFACTOR_10);
	uint16_t u16DC_Busvoltage=(DC_Busvoltage*MULTIFACTOR_10);
	uint16_t u16DC_Bus_Current=(DC_Bus_Current*MULTIFACTOR_10);

	uint16_t u16FEC_input_Current=(FEC_input_Current*MULTIFACTOR_10);
	uint16_t u16PSFB_Output_Voltage=(PSFB_Output_Voltage*MULTIFACTOR_10);
	uint16_t u16PSFB_Output_Current=(PSFB_Output_Current*MULTIFACTOR_10);

	uint16_t u16SFault1_2=(SFault1_2);
	uint16_t u16SFault3_4=(SFault3_4);
	uint16_t u16SFault5_6=(SFault5_6);
	uint16_t u16SFault7_8=(SFault7_8);

	uint16_t u16SStatus1_2=(SStatus1_2);
	uint16_t u16SStatus3_4=(SStatus3_4);

	uint16_t u16RSVD_1=(RSVD_1);
	uint16_t u16RSVD_2=(RSVD_2);
	uint16_t u16RSVD_3=(RSVD_3);
	uint16_t u16RSVD_4=(RSVD_4);
	uint16_t u16RSVD_5=(RSVD_5);
	uint16_t u16RSVD_6=(RSVD_6);
	uint16_t u16RSVD_7=(RSVD_7);
	uint16_t u16RSVD_8=(RSVD_8);
	uint16_t u16RSVD_9=(RSVD_9);
	uint16_t u16RSVD_10=(RSVD_10);
	uint16_t u16RSVD_11=(RSVD_11);
	uint16_t u16RSVD_12=(RSVD_12);
	uint16_t u16RSVD_13=(RSVD_13);
	uint16_t u16RSVD_14=(RSVD_14);
	uint16_t u16RSVD_15=(RSVD_15);
	uint16_t u16RSVD_16=(RSVD_16);
	uint16_t u16RSVD_17=(RSVD_17);


	TxDataHandler28_CAN3[0]=u16Diode_Temperature;
	TxDataHandler28_CAN3[1]=u16Diode_Temperature>>8;

	TxDataHandler28_CAN3[2]=u16Transformer_Temperature;
	TxDataHandler28_CAN3[3]=u16Transformer_Temperature>>8;

	TxDataHandler28_CAN3[4]=u16FEC_Temperature;
	TxDataHandler28_CAN3[5]=u16FEC_Temperature>>8;

	TxDataHandler28_CAN3[6]=u16PSFB_Temperature;
	TxDataHandler28_CAN3[7]=u16PSFB_Temperature>>8;

	TxDataHandler28_CAN3[8]=u16DC_Busvoltage;
	TxDataHandler28_CAN3[9]=u16DC_Busvoltage>>8;

	TxDataHandler28_CAN3[10]=u16DC_Bus_Current;
	TxDataHandler28_CAN3[11]=u16DC_Bus_Current>>8;

	TxDataHandler28_CAN3[12]=u16FEC_input_Current;
	TxDataHandler28_CAN3[13]=u16FEC_input_Current>>8;

	TxDataHandler28_CAN3[14]=u16PSFB_Output_Voltage;
	TxDataHandler28_CAN3[15]=u16PSFB_Output_Voltage>>8;

	TxDataHandler28_CAN3[16]=u16PSFB_Output_Current;
	TxDataHandler28_CAN3[17]=u16PSFB_Output_Current>>8;

	TxDataHandler28_CAN3[18]=u16SFault1_2;
	TxDataHandler28_CAN3[19]=u16SFault1_2>>8;

	TxDataHandler28_CAN3[20]=u16SFault3_4;
	TxDataHandler28_CAN3[21]=u16SFault3_4>>8;

	TxDataHandler28_CAN3[22]=u16SFault5_6;
	TxDataHandler28_CAN3[23]=u16SFault5_6>>8;

	TxDataHandler28_CAN3[24]=u16SFault7_8;
	TxDataHandler28_CAN3[25]=u16SFault7_8>>8;

	TxDataHandler28_CAN3[26]=u16SStatus1_2;
	TxDataHandler28_CAN3[27]=u16SStatus1_2>>8;

	TxDataHandler28_CAN3[28]=u16SStatus3_4;
	TxDataHandler28_CAN3[29]=u16SStatus3_4>>8;

	TxDataHandler28_CAN3[30]=u16RSVD_1;
	TxDataHandler28_CAN3[31]=u16RSVD_1>>8;

	TxDataHandler28_CAN3[32]=u16RSVD_2;
	TxDataHandler28_CAN3[33]=u16RSVD_2>>8;

	TxDataHandler28_CAN3[34]=u16RSVD_3;
	TxDataHandler28_CAN3[35]=u16RSVD_3>>8;

	TxDataHandler28_CAN3[36]=u16RSVD_4;
	TxDataHandler28_CAN3[37]=u16RSVD_4>>8;

	TxDataHandler28_CAN3[38]=u16RSVD_5;
	TxDataHandler28_CAN3[39]=u16RSVD_5>>8;

	TxDataHandler28_CAN3[40]=u16RSVD_6;
	TxDataHandler28_CAN3[41]=u16RSVD_6>>8;

	TxDataHandler28_CAN3[42]=u16RSVD_7;
	TxDataHandler28_CAN3[43]=u16RSVD_7>>8;

	TxDataHandler28_CAN3[44]=u16RSVD_8;
	TxDataHandler28_CAN3[45]=u16RSVD_8>>8;

	TxDataHandler28_CAN3[46]=u16RSVD_9;
	TxDataHandler28_CAN3[47]=u16RSVD_9>>8;

	TxDataHandler28_CAN3[48]=u16RSVD_10;
	TxDataHandler28_CAN3[49]=u16RSVD_10>>8;

	TxDataHandler28_CAN3[50]=u16RSVD_11;
	TxDataHandler28_CAN3[51]=u16RSVD_11>>8;

	TxDataHandler28_CAN3[52]=u16RSVD_12;
	TxDataHandler28_CAN3[53]=u16RSVD_12>>8;

	TxDataHandler28_CAN3[54]=u16RSVD_13;
	TxDataHandler28_CAN3[55]=u16RSVD_13>>8;

	TxDataHandler28_CAN3[56]=u16RSVD_14;
	TxDataHandler28_CAN3[57]=u16RSVD_14>>8;

	TxDataHandler28_CAN3[58]=u16RSVD_15;
	TxDataHandler28_CAN3[59]=u16RSVD_15>>8;

	TxDataHandler28_CAN3[60]=u16RSVD_16;
	TxDataHandler28_CAN3[61]=u16RSVD_16>>8;

	TxDataHandler28_CAN3[62]=u16RSVD_17;
	TxDataHandler28_CAN3[63]=u16RSVD_17>>8;

	if (HAL_FDCAN_AddMessageToTxFifoQ(&hfdcan3, &TxHeader28_CAN3, TxDataHandler28_CAN3) != HAL_OK)
	{}
	else
	{}
	HAL_Delay(1);
}
//29
void Master_To_Monitor_Frame30_Slave29(float Diode_Temperature,float Transformer_Temperature,float FEC_Temperature,float PSFB_Temperature,float DC_Busvoltage,float DC_Bus_Current,float FEC_input_Current,float PSFB_Output_Voltage,
		float PSFB_Output_Current,uint16_t SFault1_2,uint16_t SFault3_4,uint16_t SFault5_6,uint16_t SFault7_8,uint16_t SStatus1_2,uint16_t SStatus3_4,uint16_t RSVD_1,
		uint16_t RSVD_2,uint16_t RSVD_3,uint16_t RSVD_4,uint16_t RSVD_5,uint16_t RSVD_6,uint16_t RSVD_7,uint16_t RSVD_8,uint16_t RSVD_9,
		uint16_t RSVD_10,uint16_t RSVD_11,uint16_t RSVD_12,uint16_t RSVD_13,uint16_t RSVD_14,uint16_t RSVD_15,uint16_t RSVD_16,uint16_t RSVD_17)
{

	uint16_t u16Diode_Temperature=(Diode_Temperature*MULTIFACTOR_10);
	uint16_t u16Transformer_Temperature=(Transformer_Temperature*MULTIFACTOR_10);
	uint16_t u16FEC_Temperature=(FEC_Temperature*MULTIFACTOR_10);

	uint16_t u16PSFB_Temperature=(PSFB_Temperature*MULTIFACTOR_10);
	uint16_t u16DC_Busvoltage=(DC_Busvoltage*MULTIFACTOR_10);
	uint16_t u16DC_Bus_Current=(DC_Bus_Current*MULTIFACTOR_10);

	uint16_t u16FEC_input_Current=(FEC_input_Current*MULTIFACTOR_10);
	uint16_t u16PSFB_Output_Voltage=(PSFB_Output_Voltage*MULTIFACTOR_10);
	uint16_t u16PSFB_Output_Current=(PSFB_Output_Current*MULTIFACTOR_10);

	uint16_t u16SFault1_2=(SFault1_2);
	uint16_t u16SFault3_4=(SFault3_4);
	uint16_t u16SFault5_6=(SFault5_6);
	uint16_t u16SFault7_8=(SFault7_8);

	uint16_t u16SStatus1_2=(SStatus1_2);
	uint16_t u16SStatus3_4=(SStatus3_4);

	uint16_t u16RSVD_1=(RSVD_1);
	uint16_t u16RSVD_2=(RSVD_2);
	uint16_t u16RSVD_3=(RSVD_3);
	uint16_t u16RSVD_4=(RSVD_4);
	uint16_t u16RSVD_5=(RSVD_5);
	uint16_t u16RSVD_6=(RSVD_6);
	uint16_t u16RSVD_7=(RSVD_7);
	uint16_t u16RSVD_8=(RSVD_8);
	uint16_t u16RSVD_9=(RSVD_9);
	uint16_t u16RSVD_10=(RSVD_10);
	uint16_t u16RSVD_11=(RSVD_11);
	uint16_t u16RSVD_12=(RSVD_12);
	uint16_t u16RSVD_13=(RSVD_13);
	uint16_t u16RSVD_14=(RSVD_14);
	uint16_t u16RSVD_15=(RSVD_15);
	uint16_t u16RSVD_16=(RSVD_16);
	uint16_t u16RSVD_17=(RSVD_17);


	TxDataHandler29_CAN3[0]=u16Diode_Temperature;
	TxDataHandler29_CAN3[1]=u16Diode_Temperature>>8;

	TxDataHandler29_CAN3[2]=u16Transformer_Temperature;
	TxDataHandler29_CAN3[3]=u16Transformer_Temperature>>8;

	TxDataHandler29_CAN3[4]=u16FEC_Temperature;
	TxDataHandler29_CAN3[5]=u16FEC_Temperature>>8;

	TxDataHandler29_CAN3[6]=u16PSFB_Temperature;
	TxDataHandler29_CAN3[7]=u16PSFB_Temperature>>8;

	TxDataHandler29_CAN3[8]=u16DC_Busvoltage;
	TxDataHandler29_CAN3[9]=u16DC_Busvoltage>>8;

	TxDataHandler29_CAN3[10]=u16DC_Bus_Current;
	TxDataHandler29_CAN3[11]=u16DC_Bus_Current>>8;

	TxDataHandler29_CAN3[12]=u16FEC_input_Current;
	TxDataHandler29_CAN3[13]=u16FEC_input_Current>>8;

	TxDataHandler29_CAN3[14]=u16PSFB_Output_Voltage;
	TxDataHandler29_CAN3[15]=u16PSFB_Output_Voltage>>8;

	TxDataHandler29_CAN3[16]=u16PSFB_Output_Current;
	TxDataHandler29_CAN3[17]=u16PSFB_Output_Current>>8;

	TxDataHandler29_CAN3[18]=u16SFault1_2;
	TxDataHandler29_CAN3[19]=u16SFault1_2>>8;

	TxDataHandler29_CAN3[20]=u16SFault3_4;
	TxDataHandler29_CAN3[21]=u16SFault3_4>>8;

	TxDataHandler29_CAN3[22]=u16SFault5_6;
	TxDataHandler29_CAN3[23]=u16SFault5_6>>8;

	TxDataHandler29_CAN3[24]=u16SFault7_8;
	TxDataHandler29_CAN3[25]=u16SFault7_8>>8;

	TxDataHandler29_CAN3[26]=u16SStatus1_2;
	TxDataHandler29_CAN3[27]=u16SStatus1_2>>8;

	TxDataHandler29_CAN3[28]=u16SStatus3_4;
	TxDataHandler29_CAN3[29]=u16SStatus3_4>>8;

	TxDataHandler29_CAN3[30]=u16RSVD_1;
	TxDataHandler29_CAN3[31]=u16RSVD_1>>8;

	TxDataHandler29_CAN3[32]=u16RSVD_2;
	TxDataHandler29_CAN3[33]=u16RSVD_2>>8;

	TxDataHandler29_CAN3[34]=u16RSVD_3;
	TxDataHandler29_CAN3[35]=u16RSVD_3>>8;

	TxDataHandler29_CAN3[36]=u16RSVD_4;
	TxDataHandler29_CAN3[37]=u16RSVD_4>>8;

	TxDataHandler29_CAN3[38]=u16RSVD_5;
	TxDataHandler29_CAN3[39]=u16RSVD_5>>8;

	TxDataHandler29_CAN3[40]=u16RSVD_6;
	TxDataHandler29_CAN3[41]=u16RSVD_6>>8;

	TxDataHandler29_CAN3[42]=u16RSVD_7;
	TxDataHandler29_CAN3[43]=u16RSVD_7>>8;

	TxDataHandler29_CAN3[44]=u16RSVD_8;
	TxDataHandler29_CAN3[45]=u16RSVD_8>>8;

	TxDataHandler29_CAN3[46]=u16RSVD_9;
	TxDataHandler29_CAN3[47]=u16RSVD_9>>8;

	TxDataHandler29_CAN3[48]=u16RSVD_10;
	TxDataHandler29_CAN3[49]=u16RSVD_10>>8;

	TxDataHandler29_CAN3[50]=u16RSVD_11;
	TxDataHandler29_CAN3[51]=u16RSVD_11>>8;

	TxDataHandler29_CAN3[52]=u16RSVD_12;
	TxDataHandler29_CAN3[53]=u16RSVD_12>>8;

	TxDataHandler29_CAN3[54]=u16RSVD_13;
	TxDataHandler29_CAN3[55]=u16RSVD_13>>8;

	TxDataHandler29_CAN3[56]=u16RSVD_14;
	TxDataHandler29_CAN3[57]=u16RSVD_14>>8;

	TxDataHandler29_CAN3[58]=u16RSVD_15;
	TxDataHandler29_CAN3[59]=u16RSVD_15>>8;

	TxDataHandler29_CAN3[60]=u16RSVD_16;
	TxDataHandler29_CAN3[61]=u16RSVD_16>>8;

	TxDataHandler29_CAN3[62]=u16RSVD_17;
	TxDataHandler29_CAN3[63]=u16RSVD_17>>8;

	if (HAL_FDCAN_AddMessageToTxFifoQ(&hfdcan3, &TxHeader29_CAN3, TxDataHandler29_CAN3) != HAL_OK)
	{}
	else
	{}
	HAL_Delay(1);
}
//30
void Master_To_Monitor_Frame31_Slave30(float Diode_Temperature,float Transformer_Temperature,float FEC_Temperature,float PSFB_Temperature,float DC_Busvoltage,float DC_Bus_Current,float FEC_input_Current,float PSFB_Output_Voltage,
		float PSFB_Output_Current,uint16_t SFault1_2,uint16_t SFault3_4,uint16_t SFault5_6,uint16_t SFault7_8,uint16_t SStatus1_2,uint16_t SStatus3_4,uint16_t RSVD_1,
		uint16_t RSVD_2,uint16_t RSVD_3,uint16_t RSVD_4,uint16_t RSVD_5,uint16_t RSVD_6,uint16_t RSVD_7,uint16_t RSVD_8,uint16_t RSVD_9,
		uint16_t RSVD_10,uint16_t RSVD_11,uint16_t RSVD_12,uint16_t RSVD_13,uint16_t RSVD_14,uint16_t RSVD_15,uint16_t RSVD_16,uint16_t RSVD_17)
{

	uint16_t u16Diode_Temperature=(Diode_Temperature*MULTIFACTOR_10);
	uint16_t u16Transformer_Temperature=(Transformer_Temperature*MULTIFACTOR_10);
	uint16_t u16FEC_Temperature=(FEC_Temperature*MULTIFACTOR_10);

	uint16_t u16PSFB_Temperature=(PSFB_Temperature*MULTIFACTOR_10);
	uint16_t u16DC_Busvoltage=(DC_Busvoltage*MULTIFACTOR_10);
	uint16_t u16DC_Bus_Current=(DC_Bus_Current*MULTIFACTOR_10);

	uint16_t u16FEC_input_Current=(FEC_input_Current*MULTIFACTOR_10);
	uint16_t u16PSFB_Output_Voltage=(PSFB_Output_Voltage*MULTIFACTOR_10);
	uint16_t u16PSFB_Output_Current=(PSFB_Output_Current*MULTIFACTOR_10);

	uint16_t u16SFault1_2=(SFault1_2);
	uint16_t u16SFault3_4=(SFault3_4);
	uint16_t u16SFault5_6=(SFault5_6);
	uint16_t u16SFault7_8=(SFault7_8);

	uint16_t u16SStatus1_2=(SStatus1_2);
	uint16_t u16SStatus3_4=(SStatus3_4);

	uint16_t u16RSVD_1=(RSVD_1);
	uint16_t u16RSVD_2=(RSVD_2);
	uint16_t u16RSVD_3=(RSVD_3);
	uint16_t u16RSVD_4=(RSVD_4);
	uint16_t u16RSVD_5=(RSVD_5);
	uint16_t u16RSVD_6=(RSVD_6);
	uint16_t u16RSVD_7=(RSVD_7);
	uint16_t u16RSVD_8=(RSVD_8);
	uint16_t u16RSVD_9=(RSVD_9);
	uint16_t u16RSVD_10=(RSVD_10);
	uint16_t u16RSVD_11=(RSVD_11);
	uint16_t u16RSVD_12=(RSVD_12);
	uint16_t u16RSVD_13=(RSVD_13);
	uint16_t u16RSVD_14=(RSVD_14);
	uint16_t u16RSVD_15=(RSVD_15);
	uint16_t u16RSVD_16=(RSVD_16);
	uint16_t u16RSVD_17=(RSVD_17);


	TxDataHandler30_CAN3[0]=u16Diode_Temperature;
	TxDataHandler30_CAN3[1]=u16Diode_Temperature>>8;

	TxDataHandler30_CAN3[2]=u16Transformer_Temperature;
	TxDataHandler30_CAN3[3]=u16Transformer_Temperature>>8;

	TxDataHandler30_CAN3[4]=u16FEC_Temperature;
	TxDataHandler30_CAN3[5]=u16FEC_Temperature>>8;

	TxDataHandler30_CAN3[6]=u16PSFB_Temperature;
	TxDataHandler30_CAN3[7]=u16PSFB_Temperature>>8;

	TxDataHandler30_CAN3[8]=u16DC_Busvoltage;
	TxDataHandler30_CAN3[9]=u16DC_Busvoltage>>8;

	TxDataHandler30_CAN3[10]=u16DC_Bus_Current;
	TxDataHandler30_CAN3[11]=u16DC_Bus_Current>>8;

	TxDataHandler30_CAN3[12]=u16FEC_input_Current;
	TxDataHandler30_CAN3[13]=u16FEC_input_Current>>8;

	TxDataHandler30_CAN3[14]=u16PSFB_Output_Voltage;
	TxDataHandler30_CAN3[15]=u16PSFB_Output_Voltage>>8;

	TxDataHandler30_CAN3[16]=u16PSFB_Output_Current;
	TxDataHandler30_CAN3[17]=u16PSFB_Output_Current>>8;

	TxDataHandler30_CAN3[18]=u16SFault1_2;
	TxDataHandler30_CAN3[19]=u16SFault1_2>>8;

	TxDataHandler30_CAN3[20]=u16SFault3_4;
	TxDataHandler30_CAN3[21]=u16SFault3_4>>8;

	TxDataHandler30_CAN3[22]=u16SFault5_6;
	TxDataHandler30_CAN3[23]=u16SFault5_6>>8;

	TxDataHandler30_CAN3[24]=u16SFault7_8;
	TxDataHandler30_CAN3[25]=u16SFault7_8>>8;

	TxDataHandler30_CAN3[26]=u16SStatus1_2;
	TxDataHandler30_CAN3[27]=u16SStatus1_2>>8;

	TxDataHandler30_CAN3[28]=u16SStatus3_4;
	TxDataHandler30_CAN3[29]=u16SStatus3_4>>8;

	TxDataHandler30_CAN3[30]=u16RSVD_1;
	TxDataHandler30_CAN3[31]=u16RSVD_1>>8;

	TxDataHandler30_CAN3[32]=u16RSVD_2;
	TxDataHandler30_CAN3[33]=u16RSVD_2>>8;

	TxDataHandler30_CAN3[34]=u16RSVD_3;
	TxDataHandler30_CAN3[35]=u16RSVD_3>>8;

	TxDataHandler30_CAN3[36]=u16RSVD_4;
	TxDataHandler30_CAN3[37]=u16RSVD_4>>8;

	TxDataHandler30_CAN3[38]=u16RSVD_5;
	TxDataHandler30_CAN3[39]=u16RSVD_5>>8;

	TxDataHandler30_CAN3[40]=u16RSVD_6;
	TxDataHandler30_CAN3[41]=u16RSVD_6>>8;

	TxDataHandler30_CAN3[42]=u16RSVD_7;
	TxDataHandler30_CAN3[43]=u16RSVD_7>>8;

	TxDataHandler30_CAN3[44]=u16RSVD_8;
	TxDataHandler30_CAN3[45]=u16RSVD_8>>8;

	TxDataHandler30_CAN3[46]=u16RSVD_9;
	TxDataHandler30_CAN3[47]=u16RSVD_9>>8;

	TxDataHandler30_CAN3[48]=u16RSVD_10;
	TxDataHandler30_CAN3[49]=u16RSVD_10>>8;

	TxDataHandler30_CAN3[50]=u16RSVD_11;
	TxDataHandler30_CAN3[51]=u16RSVD_11>>8;

	TxDataHandler30_CAN3[52]=u16RSVD_12;
	TxDataHandler30_CAN3[53]=u16RSVD_12>>8;

	TxDataHandler30_CAN3[54]=u16RSVD_13;
	TxDataHandler30_CAN3[55]=u16RSVD_13>>8;

	TxDataHandler30_CAN3[56]=u16RSVD_14;
	TxDataHandler30_CAN3[57]=u16RSVD_14>>8;

	TxDataHandler30_CAN3[58]=u16RSVD_15;
	TxDataHandler30_CAN3[59]=u16RSVD_15>>8;

	TxDataHandler30_CAN3[60]=u16RSVD_16;
	TxDataHandler30_CAN3[61]=u16RSVD_16>>8;

	TxDataHandler30_CAN3[62]=u16RSVD_17;
	TxDataHandler30_CAN3[63]=u16RSVD_17>>8;

	if (HAL_FDCAN_AddMessageToTxFifoQ(&hfdcan3, &TxHeader30_CAN3, TxDataHandler30_CAN3) != HAL_OK)
	{}
	else
	{}
	HAL_Delay(1);
}
//31
void Master_To_Monitor_Frame32_Slave31(float Diode_Temperature,float Transformer_Temperature,float FEC_Temperature,float PSFB_Temperature,float DC_Busvoltage,float DC_Bus_Current,float FEC_input_Current,float PSFB_Output_Voltage,
		float PSFB_Output_Current,uint16_t SFault1_2,uint16_t SFault3_4,uint16_t SFault5_6,uint16_t SFault7_8,uint16_t SStatus1_2,uint16_t SStatus3_4,uint16_t RSVD_1,
		uint16_t RSVD_2,uint16_t RSVD_3,uint16_t RSVD_4,uint16_t RSVD_5,uint16_t RSVD_6,uint16_t RSVD_7,uint16_t RSVD_8,uint16_t RSVD_9,
		uint16_t RSVD_10,uint16_t RSVD_11,uint16_t RSVD_12,uint16_t RSVD_13,uint16_t RSVD_14,uint16_t RSVD_15,uint16_t RSVD_16,uint16_t RSVD_17)
{

	uint16_t u16Diode_Temperature=(Diode_Temperature*MULTIFACTOR_10);
	uint16_t u16Transformer_Temperature=(Transformer_Temperature*MULTIFACTOR_10);
	uint16_t u16FEC_Temperature=(FEC_Temperature*MULTIFACTOR_10);

	uint16_t u16PSFB_Temperature=(PSFB_Temperature*MULTIFACTOR_10);
	uint16_t u16DC_Busvoltage=(DC_Busvoltage*MULTIFACTOR_10);
	uint16_t u16DC_Bus_Current=(DC_Bus_Current*MULTIFACTOR_10);

	uint16_t u16FEC_input_Current=(FEC_input_Current*MULTIFACTOR_10);
	uint16_t u16PSFB_Output_Voltage=(PSFB_Output_Voltage*MULTIFACTOR_10);
	uint16_t u16PSFB_Output_Current=(PSFB_Output_Current*MULTIFACTOR_10);

	uint16_t u16SFault1_2=(SFault1_2);
	uint16_t u16SFault3_4=(SFault3_4);
	uint16_t u16SFault5_6=(SFault5_6);
	uint16_t u16SFault7_8=(SFault7_8);

	uint16_t u16SStatus1_2=(SStatus1_2);
	uint16_t u16SStatus3_4=(SStatus3_4);

	uint16_t u16RSVD_1=(RSVD_1);
	uint16_t u16RSVD_2=(RSVD_2);
	uint16_t u16RSVD_3=(RSVD_3);
	uint16_t u16RSVD_4=(RSVD_4);
	uint16_t u16RSVD_5=(RSVD_5);
	uint16_t u16RSVD_6=(RSVD_6);
	uint16_t u16RSVD_7=(RSVD_7);
	uint16_t u16RSVD_8=(RSVD_8);
	uint16_t u16RSVD_9=(RSVD_9);
	uint16_t u16RSVD_10=(RSVD_10);
	uint16_t u16RSVD_11=(RSVD_11);
	uint16_t u16RSVD_12=(RSVD_12);
	uint16_t u16RSVD_13=(RSVD_13);
	uint16_t u16RSVD_14=(RSVD_14);
	uint16_t u16RSVD_15=(RSVD_15);
	uint16_t u16RSVD_16=(RSVD_16);
	uint16_t u16RSVD_17=(RSVD_17);


	TxDataHandler31_CAN3[0]=u16Diode_Temperature;
	TxDataHandler31_CAN3[1]=u16Diode_Temperature>>8;

	TxDataHandler31_CAN3[2]=u16Transformer_Temperature;
	TxDataHandler31_CAN3[3]=u16Transformer_Temperature>>8;

	TxDataHandler31_CAN3[4]=u16FEC_Temperature;
	TxDataHandler31_CAN3[5]=u16FEC_Temperature>>8;

	TxDataHandler31_CAN3[6]=u16PSFB_Temperature;
	TxDataHandler31_CAN3[7]=u16PSFB_Temperature>>8;

	TxDataHandler31_CAN3[8]=u16DC_Busvoltage;
	TxDataHandler31_CAN3[9]=u16DC_Busvoltage>>8;

	TxDataHandler31_CAN3[10]=u16DC_Bus_Current;
	TxDataHandler31_CAN3[11]=u16DC_Bus_Current>>8;

	TxDataHandler31_CAN3[12]=u16FEC_input_Current;
	TxDataHandler31_CAN3[13]=u16FEC_input_Current>>8;

	TxDataHandler31_CAN3[14]=u16PSFB_Output_Voltage;
	TxDataHandler31_CAN3[15]=u16PSFB_Output_Voltage>>8;

	TxDataHandler31_CAN3[16]=u16PSFB_Output_Current;
	TxDataHandler31_CAN3[17]=u16PSFB_Output_Current>>8;

	TxDataHandler31_CAN3[18]=u16SFault1_2;
	TxDataHandler31_CAN3[19]=u16SFault1_2>>8;

	TxDataHandler31_CAN3[20]=u16SFault3_4;
	TxDataHandler31_CAN3[21]=u16SFault3_4>>8;

	TxDataHandler31_CAN3[22]=u16SFault5_6;
	TxDataHandler31_CAN3[23]=u16SFault5_6>>8;

	TxDataHandler31_CAN3[24]=u16SFault7_8;
	TxDataHandler31_CAN3[25]=u16SFault7_8>>8;

	TxDataHandler31_CAN3[26]=u16SStatus1_2;
	TxDataHandler31_CAN3[27]=u16SStatus1_2>>8;

	TxDataHandler31_CAN3[28]=u16SStatus3_4;
	TxDataHandler31_CAN3[29]=u16SStatus3_4>>8;

	TxDataHandler31_CAN3[30]=u16RSVD_1;
	TxDataHandler31_CAN3[31]=u16RSVD_1>>8;

	TxDataHandler31_CAN3[32]=u16RSVD_2;
	TxDataHandler31_CAN3[33]=u16RSVD_2>>8;

	TxDataHandler31_CAN3[34]=u16RSVD_3;
	TxDataHandler31_CAN3[35]=u16RSVD_3>>8;

	TxDataHandler31_CAN3[36]=u16RSVD_4;
	TxDataHandler31_CAN3[37]=u16RSVD_4>>8;

	TxDataHandler31_CAN3[38]=u16RSVD_5;
	TxDataHandler31_CAN3[39]=u16RSVD_5>>8;

	TxDataHandler31_CAN3[40]=u16RSVD_6;
	TxDataHandler31_CAN3[41]=u16RSVD_6>>8;

	TxDataHandler31_CAN3[42]=u16RSVD_7;
	TxDataHandler31_CAN3[43]=u16RSVD_7>>8;

	TxDataHandler31_CAN3[44]=u16RSVD_8;
	TxDataHandler31_CAN3[45]=u16RSVD_8>>8;

	TxDataHandler31_CAN3[46]=u16RSVD_9;
	TxDataHandler31_CAN3[47]=u16RSVD_9>>8;

	TxDataHandler31_CAN3[48]=u16RSVD_10;
	TxDataHandler31_CAN3[49]=u16RSVD_10>>8;

	TxDataHandler31_CAN3[50]=u16RSVD_11;
	TxDataHandler31_CAN3[51]=u16RSVD_11>>8;

	TxDataHandler31_CAN3[52]=u16RSVD_12;
	TxDataHandler31_CAN3[53]=u16RSVD_12>>8;

	TxDataHandler31_CAN3[54]=u16RSVD_13;
	TxDataHandler31_CAN3[55]=u16RSVD_13>>8;

	TxDataHandler31_CAN3[56]=u16RSVD_14;
	TxDataHandler31_CAN3[57]=u16RSVD_14>>8;

	TxDataHandler31_CAN3[58]=u16RSVD_15;
	TxDataHandler31_CAN3[59]=u16RSVD_15>>8;

	TxDataHandler31_CAN3[60]=u16RSVD_16;
	TxDataHandler31_CAN3[61]=u16RSVD_16>>8;

	TxDataHandler31_CAN3[62]=u16RSVD_17;
	TxDataHandler31_CAN3[63]=u16RSVD_17>>8;

	if (HAL_FDCAN_AddMessageToTxFifoQ(&hfdcan3, &TxHeader31_CAN3, TxDataHandler31_CAN3) != HAL_OK)
	{}
	else
	{}
	HAL_Delay(1);
}
//32
void Master_To_Monitor_Frame33_Slave32(float Diode_Temperature,float Transformer_Temperature,float FEC_Temperature,float PSFB_Temperature,float DC_Busvoltage,float DC_Bus_Current,float FEC_input_Current,float PSFB_Output_Voltage,
		float PSFB_Output_Current,uint16_t SFault1_2,uint16_t SFault3_4,uint16_t SFault5_6,uint16_t SFault7_8,uint16_t SStatus1_2,uint16_t SStatus3_4,uint16_t RSVD_1,
		uint16_t RSVD_2,uint16_t RSVD_3,uint16_t RSVD_4,uint16_t RSVD_5,uint16_t RSVD_6,uint16_t RSVD_7,uint16_t RSVD_8,uint16_t RSVD_9,
		uint16_t RSVD_10,uint16_t RSVD_11,uint16_t RSVD_12,uint16_t RSVD_13,uint16_t RSVD_14,uint16_t RSVD_15,uint16_t RSVD_16,uint16_t RSVD_17)
{

	uint16_t u16Diode_Temperature=(Diode_Temperature*MULTIFACTOR_10);
	uint16_t u16Transformer_Temperature=(Transformer_Temperature*MULTIFACTOR_10);
	uint16_t u16FEC_Temperature=(FEC_Temperature*MULTIFACTOR_10);

	uint16_t u16PSFB_Temperature=(PSFB_Temperature*MULTIFACTOR_10);
	uint16_t u16DC_Busvoltage=(DC_Busvoltage*MULTIFACTOR_10);
	uint16_t u16DC_Bus_Current=(DC_Bus_Current*MULTIFACTOR_10);

	uint16_t u16FEC_input_Current=(FEC_input_Current*MULTIFACTOR_10);
	uint16_t u16PSFB_Output_Voltage=(PSFB_Output_Voltage*MULTIFACTOR_10);
	uint16_t u16PSFB_Output_Current=(PSFB_Output_Current*MULTIFACTOR_10);

	uint16_t u16SFault1_2=(SFault1_2);
	uint16_t u16SFault3_4=(SFault3_4);
	uint16_t u16SFault5_6=(SFault5_6);
	uint16_t u16SFault7_8=(SFault7_8);

	uint16_t u16SStatus1_2=(SStatus1_2);
	uint16_t u16SStatus3_4=(SStatus3_4);

	uint16_t u16RSVD_1=(RSVD_1);
	uint16_t u16RSVD_2=(RSVD_2);
	uint16_t u16RSVD_3=(RSVD_3);
	uint16_t u16RSVD_4=(RSVD_4);
	uint16_t u16RSVD_5=(RSVD_5);
	uint16_t u16RSVD_6=(RSVD_6);
	uint16_t u16RSVD_7=(RSVD_7);
	uint16_t u16RSVD_8=(RSVD_8);
	uint16_t u16RSVD_9=(RSVD_9);
	uint16_t u16RSVD_10=(RSVD_10);
	uint16_t u16RSVD_11=(RSVD_11);
	uint16_t u16RSVD_12=(RSVD_12);
	uint16_t u16RSVD_13=(RSVD_13);
	uint16_t u16RSVD_14=(RSVD_14);
	uint16_t u16RSVD_15=(RSVD_15);
	uint16_t u16RSVD_16=(RSVD_16);
	uint16_t u16RSVD_17=(RSVD_17);


	TxDataHandler32_CAN3[0]=u16Diode_Temperature;
	TxDataHandler32_CAN3[1]=u16Diode_Temperature>>8;

	TxDataHandler32_CAN3[2]=u16Transformer_Temperature;
	TxDataHandler32_CAN3[3]=u16Transformer_Temperature>>8;

	TxDataHandler32_CAN3[4]=u16FEC_Temperature;
	TxDataHandler32_CAN3[5]=u16FEC_Temperature>>8;

	TxDataHandler32_CAN3[6]=u16PSFB_Temperature;
	TxDataHandler32_CAN3[7]=u16PSFB_Temperature>>8;

	TxDataHandler32_CAN3[8]=u16DC_Busvoltage;
	TxDataHandler32_CAN3[9]=u16DC_Busvoltage>>8;

	TxDataHandler32_CAN3[10]=u16DC_Bus_Current;
	TxDataHandler32_CAN3[11]=u16DC_Bus_Current>>8;

	TxDataHandler32_CAN3[12]=u16FEC_input_Current;
	TxDataHandler32_CAN3[13]=u16FEC_input_Current>>8;

	TxDataHandler32_CAN3[14]=u16PSFB_Output_Voltage;
	TxDataHandler32_CAN3[15]=u16PSFB_Output_Voltage>>8;

	TxDataHandler32_CAN3[16]=u16PSFB_Output_Current;
	TxDataHandler32_CAN3[17]=u16PSFB_Output_Current>>8;

	TxDataHandler32_CAN3[18]=u16SFault1_2;
	TxDataHandler32_CAN3[19]=u16SFault1_2>>8;

	TxDataHandler32_CAN3[20]=u16SFault3_4;
	TxDataHandler32_CAN3[21]=u16SFault3_4>>8;

	TxDataHandler32_CAN3[22]=u16SFault5_6;
	TxDataHandler32_CAN3[23]=u16SFault5_6>>8;

	TxDataHandler32_CAN3[24]=u16SFault7_8;
	TxDataHandler32_CAN3[25]=u16SFault7_8>>8;

	TxDataHandler32_CAN3[26]=u16SStatus1_2;
	TxDataHandler32_CAN3[27]=u16SStatus1_2>>8;

	TxDataHandler32_CAN3[28]=u16SStatus3_4;
	TxDataHandler32_CAN3[29]=u16SStatus3_4>>8;

	TxDataHandler32_CAN3[30]=u16RSVD_1;
	TxDataHandler32_CAN3[31]=u16RSVD_1>>8;

	TxDataHandler32_CAN3[32]=u16RSVD_2;
	TxDataHandler32_CAN3[33]=u16RSVD_2>>8;

	TxDataHandler32_CAN3[34]=u16RSVD_3;
	TxDataHandler32_CAN3[35]=u16RSVD_3>>8;

	TxDataHandler32_CAN3[36]=u16RSVD_4;
	TxDataHandler32_CAN3[37]=u16RSVD_4>>8;

	TxDataHandler32_CAN3[38]=u16RSVD_5;
	TxDataHandler32_CAN3[39]=u16RSVD_5>>8;

	TxDataHandler32_CAN3[40]=u16RSVD_6;
	TxDataHandler32_CAN3[41]=u16RSVD_6>>8;

	TxDataHandler32_CAN3[42]=u16RSVD_7;
	TxDataHandler32_CAN3[43]=u16RSVD_7>>8;

	TxDataHandler32_CAN3[44]=u16RSVD_8;
	TxDataHandler32_CAN3[45]=u16RSVD_8>>8;

	TxDataHandler32_CAN3[46]=u16RSVD_9;
	TxDataHandler32_CAN3[47]=u16RSVD_9>>8;

	TxDataHandler32_CAN3[48]=u16RSVD_10;
	TxDataHandler32_CAN3[49]=u16RSVD_10>>8;

	TxDataHandler32_CAN3[50]=u16RSVD_11;
	TxDataHandler32_CAN3[51]=u16RSVD_11>>8;

	TxDataHandler32_CAN3[52]=u16RSVD_12;
	TxDataHandler32_CAN3[53]=u16RSVD_12>>8;

	TxDataHandler32_CAN3[54]=u16RSVD_13;
	TxDataHandler32_CAN3[55]=u16RSVD_13>>8;

	TxDataHandler32_CAN3[56]=u16RSVD_14;
	TxDataHandler32_CAN3[57]=u16RSVD_14>>8;

	TxDataHandler32_CAN3[58]=u16RSVD_15;
	TxDataHandler32_CAN3[59]=u16RSVD_15>>8;

	TxDataHandler32_CAN3[60]=u16RSVD_16;
	TxDataHandler32_CAN3[61]=u16RSVD_16>>8;

	TxDataHandler32_CAN3[62]=u16RSVD_17;
	TxDataHandler32_CAN3[63]=u16RSVD_17>>8;

	if (HAL_FDCAN_AddMessageToTxFifoQ(&hfdcan3, &TxHeader32_CAN3, TxDataHandler32_CAN3) != HAL_OK)
	{}
	else
	{}
	HAL_Delay(1);
}
//33
void Master_To_Monitor_Frame34_Slave33(float Diode_Temperature,float Transformer_Temperature,float FEC_Temperature,float PSFB_Temperature,float DC_Busvoltage,float DC_Bus_Current,float FEC_input_Current,float PSFB_Output_Voltage,
		float PSFB_Output_Current,uint16_t SFault1_2,uint16_t SFault3_4,uint16_t SFault5_6,uint16_t SFault7_8,uint16_t SStatus1_2,uint16_t SStatus3_4,uint16_t RSVD_1,
		uint16_t RSVD_2,uint16_t RSVD_3,uint16_t RSVD_4,uint16_t RSVD_5,uint16_t RSVD_6,uint16_t RSVD_7,uint16_t RSVD_8,uint16_t RSVD_9,
		uint16_t RSVD_10,uint16_t RSVD_11,uint16_t RSVD_12,uint16_t RSVD_13,uint16_t RSVD_14,uint16_t RSVD_15,uint16_t RSVD_16,uint16_t RSVD_17)
{

	uint16_t u16Diode_Temperature=(Diode_Temperature*MULTIFACTOR_10);
	uint16_t u16Transformer_Temperature=(Transformer_Temperature*MULTIFACTOR_10);
	uint16_t u16FEC_Temperature=(FEC_Temperature*MULTIFACTOR_10);

	uint16_t u16PSFB_Temperature=(PSFB_Temperature*MULTIFACTOR_10);
	uint16_t u16DC_Busvoltage=(DC_Busvoltage*MULTIFACTOR_10);
	uint16_t u16DC_Bus_Current=(DC_Bus_Current*MULTIFACTOR_10);

	uint16_t u16FEC_input_Current=(FEC_input_Current*MULTIFACTOR_10);
	uint16_t u16PSFB_Output_Voltage=(PSFB_Output_Voltage*MULTIFACTOR_10);
	uint16_t u16PSFB_Output_Current=(PSFB_Output_Current*MULTIFACTOR_10);

	uint16_t u16SFault1_2=(SFault1_2);
	uint16_t u16SFault3_4=(SFault3_4);
	uint16_t u16SFault5_6=(SFault5_6);
	uint16_t u16SFault7_8=(SFault7_8);

	uint16_t u16SStatus1_2=(SStatus1_2);
	uint16_t u16SStatus3_4=(SStatus3_4);

	uint16_t u16RSVD_1=(RSVD_1);
	uint16_t u16RSVD_2=(RSVD_2);
	uint16_t u16RSVD_3=(RSVD_3);
	uint16_t u16RSVD_4=(RSVD_4);
	uint16_t u16RSVD_5=(RSVD_5);
	uint16_t u16RSVD_6=(RSVD_6);
	uint16_t u16RSVD_7=(RSVD_7);
	uint16_t u16RSVD_8=(RSVD_8);
	uint16_t u16RSVD_9=(RSVD_9);
	uint16_t u16RSVD_10=(RSVD_10);
	uint16_t u16RSVD_11=(RSVD_11);
	uint16_t u16RSVD_12=(RSVD_12);
	uint16_t u16RSVD_13=(RSVD_13);
	uint16_t u16RSVD_14=(RSVD_14);
	uint16_t u16RSVD_15=(RSVD_15);
	uint16_t u16RSVD_16=(RSVD_16);
	uint16_t u16RSVD_17=(RSVD_17);


	TxDataHandler33_CAN3[0]=u16Diode_Temperature;
	TxDataHandler33_CAN3[1]=u16Diode_Temperature>>8;

	TxDataHandler33_CAN3[2]=u16Transformer_Temperature;
	TxDataHandler33_CAN3[3]=u16Transformer_Temperature>>8;

	TxDataHandler33_CAN3[4]=u16FEC_Temperature;
	TxDataHandler33_CAN3[5]=u16FEC_Temperature>>8;

	TxDataHandler33_CAN3[6]=u16PSFB_Temperature;
	TxDataHandler33_CAN3[7]=u16PSFB_Temperature>>8;

	TxDataHandler33_CAN3[8]=u16DC_Busvoltage;
	TxDataHandler33_CAN3[9]=u16DC_Busvoltage>>8;

	TxDataHandler33_CAN3[10]=u16DC_Bus_Current;
	TxDataHandler33_CAN3[11]=u16DC_Bus_Current>>8;

	TxDataHandler33_CAN3[12]=u16FEC_input_Current;
	TxDataHandler33_CAN3[13]=u16FEC_input_Current>>8;

	TxDataHandler33_CAN3[14]=u16PSFB_Output_Voltage;
	TxDataHandler33_CAN3[15]=u16PSFB_Output_Voltage>>8;

	TxDataHandler33_CAN3[16]=u16PSFB_Output_Current;
	TxDataHandler33_CAN3[17]=u16PSFB_Output_Current>>8;

	TxDataHandler33_CAN3[18]=u16SFault1_2;
	TxDataHandler33_CAN3[19]=u16SFault1_2>>8;

	TxDataHandler33_CAN3[20]=u16SFault3_4;
	TxDataHandler33_CAN3[21]=u16SFault3_4>>8;

	TxDataHandler33_CAN3[22]=u16SFault5_6;
	TxDataHandler33_CAN3[23]=u16SFault5_6>>8;

	TxDataHandler33_CAN3[24]=u16SFault7_8;
	TxDataHandler33_CAN3[25]=u16SFault7_8>>8;

	TxDataHandler33_CAN3[26]=u16SStatus1_2;
	TxDataHandler33_CAN3[27]=u16SStatus1_2>>8;

	TxDataHandler33_CAN3[28]=u16SStatus3_4;
	TxDataHandler33_CAN3[29]=u16SStatus3_4>>8;

	TxDataHandler33_CAN3[30]=u16RSVD_1;
	TxDataHandler33_CAN3[31]=u16RSVD_1>>8;

	TxDataHandler33_CAN3[32]=u16RSVD_2;
	TxDataHandler33_CAN3[33]=u16RSVD_2>>8;

	TxDataHandler33_CAN3[34]=u16RSVD_3;
	TxDataHandler33_CAN3[35]=u16RSVD_3>>8;

	TxDataHandler33_CAN3[36]=u16RSVD_4;
	TxDataHandler33_CAN3[37]=u16RSVD_4>>8;

	TxDataHandler33_CAN3[38]=u16RSVD_5;
	TxDataHandler33_CAN3[39]=u16RSVD_5>>8;

	TxDataHandler33_CAN3[40]=u16RSVD_6;
	TxDataHandler33_CAN3[41]=u16RSVD_6>>8;

	TxDataHandler33_CAN3[42]=u16RSVD_7;
	TxDataHandler33_CAN3[43]=u16RSVD_7>>8;

	TxDataHandler33_CAN3[44]=u16RSVD_8;
	TxDataHandler33_CAN3[45]=u16RSVD_8>>8;

	TxDataHandler33_CAN3[46]=u16RSVD_9;
	TxDataHandler33_CAN3[47]=u16RSVD_9>>8;

	TxDataHandler33_CAN3[48]=u16RSVD_10;
	TxDataHandler33_CAN3[49]=u16RSVD_10>>8;

	TxDataHandler33_CAN3[50]=u16RSVD_11;
	TxDataHandler33_CAN3[51]=u16RSVD_11>>8;

	TxDataHandler33_CAN3[52]=u16RSVD_12;
	TxDataHandler33_CAN3[53]=u16RSVD_12>>8;

	TxDataHandler33_CAN3[54]=u16RSVD_13;
	TxDataHandler33_CAN3[55]=u16RSVD_13>>8;

	TxDataHandler33_CAN3[56]=u16RSVD_14;
	TxDataHandler33_CAN3[57]=u16RSVD_14>>8;

	TxDataHandler33_CAN3[58]=u16RSVD_15;
	TxDataHandler33_CAN3[59]=u16RSVD_15>>8;

	TxDataHandler33_CAN3[60]=u16RSVD_16;
	TxDataHandler33_CAN3[61]=u16RSVD_16>>8;

	TxDataHandler33_CAN3[62]=u16RSVD_17;
	TxDataHandler33_CAN3[63]=u16RSVD_17>>8;

	if (HAL_FDCAN_AddMessageToTxFifoQ(&hfdcan3, &TxHeader33_CAN3, TxDataHandler33_CAN3) != HAL_OK)
	{}
	else
	{}
	HAL_Delay(1);
}
//34
void Master_To_Monitor_Frame35_Slave34(float Diode_Temperature,float Transformer_Temperature,float FEC_Temperature,float PSFB_Temperature,float DC_Busvoltage,float DC_Bus_Current,float FEC_input_Current,float PSFB_Output_Voltage,
		float PSFB_Output_Current,uint16_t SFault1_2,uint16_t SFault3_4,uint16_t SFault5_6,uint16_t SFault7_8,uint16_t SStatus1_2,uint16_t SStatus3_4,uint16_t RSVD_1,
		uint16_t RSVD_2,uint16_t RSVD_3,uint16_t RSVD_4,uint16_t RSVD_5,uint16_t RSVD_6,uint16_t RSVD_7,uint16_t RSVD_8,uint16_t RSVD_9,
		uint16_t RSVD_10,uint16_t RSVD_11,uint16_t RSVD_12,uint16_t RSVD_13,uint16_t RSVD_14,uint16_t RSVD_15,uint16_t RSVD_16,uint16_t RSVD_17)
{

	uint16_t u16Diode_Temperature=(Diode_Temperature*MULTIFACTOR_10);
	uint16_t u16Transformer_Temperature=(Transformer_Temperature*MULTIFACTOR_10);
	uint16_t u16FEC_Temperature=(FEC_Temperature*MULTIFACTOR_10);

	uint16_t u16PSFB_Temperature=(PSFB_Temperature*MULTIFACTOR_10);
	uint16_t u16DC_Busvoltage=(DC_Busvoltage*MULTIFACTOR_10);
	uint16_t u16DC_Bus_Current=(DC_Bus_Current*MULTIFACTOR_10);

	uint16_t u16FEC_input_Current=(FEC_input_Current*MULTIFACTOR_10);
	uint16_t u16PSFB_Output_Voltage=(PSFB_Output_Voltage*MULTIFACTOR_10);
	uint16_t u16PSFB_Output_Current=(PSFB_Output_Current*MULTIFACTOR_10);

	uint16_t u16SFault1_2=(SFault1_2);
	uint16_t u16SFault3_4=(SFault3_4);
	uint16_t u16SFault5_6=(SFault5_6);
	uint16_t u16SFault7_8=(SFault7_8);

	uint16_t u16SStatus1_2=(SStatus1_2);
	uint16_t u16SStatus3_4=(SStatus3_4);

	uint16_t u16RSVD_1=(RSVD_1);
	uint16_t u16RSVD_2=(RSVD_2);
	uint16_t u16RSVD_3=(RSVD_3);
	uint16_t u16RSVD_4=(RSVD_4);
	uint16_t u16RSVD_5=(RSVD_5);
	uint16_t u16RSVD_6=(RSVD_6);
	uint16_t u16RSVD_7=(RSVD_7);
	uint16_t u16RSVD_8=(RSVD_8);
	uint16_t u16RSVD_9=(RSVD_9);
	uint16_t u16RSVD_10=(RSVD_10);
	uint16_t u16RSVD_11=(RSVD_11);
	uint16_t u16RSVD_12=(RSVD_12);
	uint16_t u16RSVD_13=(RSVD_13);
	uint16_t u16RSVD_14=(RSVD_14);
	uint16_t u16RSVD_15=(RSVD_15);
	uint16_t u16RSVD_16=(RSVD_16);
	uint16_t u16RSVD_17=(RSVD_17);


	TxDataHandler34_CAN3[0]=u16Diode_Temperature;
	TxDataHandler34_CAN3[1]=u16Diode_Temperature>>8;

	TxDataHandler34_CAN3[2]=u16Transformer_Temperature;
	TxDataHandler34_CAN3[3]=u16Transformer_Temperature>>8;

	TxDataHandler34_CAN3[4]=u16FEC_Temperature;
	TxDataHandler34_CAN3[5]=u16FEC_Temperature>>8;

	TxDataHandler34_CAN3[6]=u16PSFB_Temperature;
	TxDataHandler34_CAN3[7]=u16PSFB_Temperature>>8;

	TxDataHandler34_CAN3[8]=u16DC_Busvoltage;
	TxDataHandler34_CAN3[9]=u16DC_Busvoltage>>8;

	TxDataHandler34_CAN3[10]=u16DC_Bus_Current;
	TxDataHandler34_CAN3[11]=u16DC_Bus_Current>>8;

	TxDataHandler34_CAN3[12]=u16FEC_input_Current;
	TxDataHandler34_CAN3[13]=u16FEC_input_Current>>8;

	TxDataHandler34_CAN3[14]=u16PSFB_Output_Voltage;
	TxDataHandler34_CAN3[15]=u16PSFB_Output_Voltage>>8;

	TxDataHandler34_CAN3[16]=u16PSFB_Output_Current;
	TxDataHandler34_CAN3[17]=u16PSFB_Output_Current>>8;

	TxDataHandler34_CAN3[18]=u16SFault1_2;
	TxDataHandler34_CAN3[19]=u16SFault1_2>>8;

	TxDataHandler34_CAN3[20]=u16SFault3_4;
	TxDataHandler34_CAN3[21]=u16SFault3_4>>8;

	TxDataHandler34_CAN3[22]=u16SFault5_6;
	TxDataHandler34_CAN3[23]=u16SFault5_6>>8;

	TxDataHandler34_CAN3[24]=u16SFault7_8;
	TxDataHandler34_CAN3[25]=u16SFault7_8>>8;

	TxDataHandler34_CAN3[26]=u16SStatus1_2;
	TxDataHandler34_CAN3[27]=u16SStatus1_2>>8;

	TxDataHandler34_CAN3[28]=u16SStatus3_4;
	TxDataHandler34_CAN3[29]=u16SStatus3_4>>8;

	TxDataHandler34_CAN3[30]=u16RSVD_1;
	TxDataHandler34_CAN3[31]=u16RSVD_1>>8;

	TxDataHandler34_CAN3[32]=u16RSVD_2;
	TxDataHandler34_CAN3[33]=u16RSVD_2>>8;

	TxDataHandler34_CAN3[34]=u16RSVD_3;
	TxDataHandler34_CAN3[35]=u16RSVD_3>>8;

	TxDataHandler34_CAN3[36]=u16RSVD_4;
	TxDataHandler34_CAN3[37]=u16RSVD_4>>8;

	TxDataHandler34_CAN3[38]=u16RSVD_5;
	TxDataHandler34_CAN3[39]=u16RSVD_5>>8;

	TxDataHandler34_CAN3[40]=u16RSVD_6;
	TxDataHandler34_CAN3[41]=u16RSVD_6>>8;

	TxDataHandler34_CAN3[42]=u16RSVD_7;
	TxDataHandler34_CAN3[43]=u16RSVD_7>>8;

	TxDataHandler34_CAN3[44]=u16RSVD_8;
	TxDataHandler34_CAN3[45]=u16RSVD_8>>8;

	TxDataHandler34_CAN3[46]=u16RSVD_9;
	TxDataHandler34_CAN3[47]=u16RSVD_9>>8;

	TxDataHandler34_CAN3[48]=u16RSVD_10;
	TxDataHandler34_CAN3[49]=u16RSVD_10>>8;

	TxDataHandler34_CAN3[50]=u16RSVD_11;
	TxDataHandler34_CAN3[51]=u16RSVD_11>>8;

	TxDataHandler34_CAN3[52]=u16RSVD_12;
	TxDataHandler34_CAN3[53]=u16RSVD_12>>8;

	TxDataHandler34_CAN3[54]=u16RSVD_13;
	TxDataHandler34_CAN3[55]=u16RSVD_13>>8;

	TxDataHandler34_CAN3[56]=u16RSVD_14;
	TxDataHandler34_CAN3[57]=u16RSVD_14>>8;

	TxDataHandler34_CAN3[58]=u16RSVD_15;
	TxDataHandler34_CAN3[59]=u16RSVD_15>>8;

	TxDataHandler34_CAN3[60]=u16RSVD_16;
	TxDataHandler34_CAN3[61]=u16RSVD_16>>8;

	TxDataHandler34_CAN3[62]=u16RSVD_17;
	TxDataHandler34_CAN3[63]=u16RSVD_17>>8;

	if (HAL_FDCAN_AddMessageToTxFifoQ(&hfdcan3, &TxHeader34_CAN3, TxDataHandler34_CAN3) != HAL_OK)
	{}
	else
	{}
	HAL_Delay(1);
}
//35
void Master_To_Monitor_Frame36_Slave35(float Diode_Temperature,float Transformer_Temperature,float FEC_Temperature,float PSFB_Temperature,float DC_Busvoltage,float DC_Bus_Current,float FEC_input_Current,float PSFB_Output_Voltage,
		float PSFB_Output_Current,uint16_t SFault1_2,uint16_t SFault3_4,uint16_t SFault5_6,uint16_t SFault7_8,uint16_t SStatus1_2,uint16_t SStatus3_4,uint16_t RSVD_1,
		uint16_t RSVD_2,uint16_t RSVD_3,uint16_t RSVD_4,uint16_t RSVD_5,uint16_t RSVD_6,uint16_t RSVD_7,uint16_t RSVD_8,uint16_t RSVD_9,
		uint16_t RSVD_10,uint16_t RSVD_11,uint16_t RSVD_12,uint16_t RSVD_13,uint16_t RSVD_14,uint16_t RSVD_15,uint16_t RSVD_16,uint16_t RSVD_17)
{

	uint16_t u16Diode_Temperature=(Diode_Temperature*MULTIFACTOR_10);
	uint16_t u16Transformer_Temperature=(Transformer_Temperature*MULTIFACTOR_10);
	uint16_t u16FEC_Temperature=(FEC_Temperature*MULTIFACTOR_10);

	uint16_t u16PSFB_Temperature=(PSFB_Temperature*MULTIFACTOR_10);
	uint16_t u16DC_Busvoltage=(DC_Busvoltage*MULTIFACTOR_10);
	uint16_t u16DC_Bus_Current=(DC_Bus_Current*MULTIFACTOR_10);

	uint16_t u16FEC_input_Current=(FEC_input_Current*MULTIFACTOR_10);
	uint16_t u16PSFB_Output_Voltage=(PSFB_Output_Voltage*MULTIFACTOR_10);
	uint16_t u16PSFB_Output_Current=(PSFB_Output_Current*MULTIFACTOR_10);

	uint16_t u16SFault1_2=(SFault1_2);
	uint16_t u16SFault3_4=(SFault3_4);
	uint16_t u16SFault5_6=(SFault5_6);
	uint16_t u16SFault7_8=(SFault7_8);

	uint16_t u16SStatus1_2=(SStatus1_2);
	uint16_t u16SStatus3_4=(SStatus3_4);

	uint16_t u16RSVD_1=(RSVD_1);
	uint16_t u16RSVD_2=(RSVD_2);
	uint16_t u16RSVD_3=(RSVD_3);
	uint16_t u16RSVD_4=(RSVD_4);
	uint16_t u16RSVD_5=(RSVD_5);
	uint16_t u16RSVD_6=(RSVD_6);
	uint16_t u16RSVD_7=(RSVD_7);
	uint16_t u16RSVD_8=(RSVD_8);
	uint16_t u16RSVD_9=(RSVD_9);
	uint16_t u16RSVD_10=(RSVD_10);
	uint16_t u16RSVD_11=(RSVD_11);
	uint16_t u16RSVD_12=(RSVD_12);
	uint16_t u16RSVD_13=(RSVD_13);
	uint16_t u16RSVD_14=(RSVD_14);
	uint16_t u16RSVD_15=(RSVD_15);
	uint16_t u16RSVD_16=(RSVD_16);
	uint16_t u16RSVD_17=(RSVD_17);


	TxDataHandler35_CAN3[0]=u16Diode_Temperature;
	TxDataHandler35_CAN3[1]=u16Diode_Temperature>>8;

	TxDataHandler35_CAN3[2]=u16Transformer_Temperature;
	TxDataHandler35_CAN3[3]=u16Transformer_Temperature>>8;

	TxDataHandler35_CAN3[4]=u16FEC_Temperature;
	TxDataHandler35_CAN3[5]=u16FEC_Temperature>>8;

	TxDataHandler35_CAN3[6]=u16PSFB_Temperature;
	TxDataHandler35_CAN3[7]=u16PSFB_Temperature>>8;

	TxDataHandler35_CAN3[8]=u16DC_Busvoltage;
	TxDataHandler35_CAN3[9]=u16DC_Busvoltage>>8;

	TxDataHandler35_CAN3[10]=u16DC_Bus_Current;
	TxDataHandler35_CAN3[11]=u16DC_Bus_Current>>8;

	TxDataHandler35_CAN3[12]=u16FEC_input_Current;
	TxDataHandler35_CAN3[13]=u16FEC_input_Current>>8;

	TxDataHandler35_CAN3[14]=u16PSFB_Output_Voltage;
	TxDataHandler35_CAN3[15]=u16PSFB_Output_Voltage>>8;

	TxDataHandler35_CAN3[16]=u16PSFB_Output_Current;
	TxDataHandler35_CAN3[17]=u16PSFB_Output_Current>>8;

	TxDataHandler35_CAN3[18]=u16SFault1_2;
	TxDataHandler35_CAN3[19]=u16SFault1_2>>8;

	TxDataHandler35_CAN3[20]=u16SFault3_4;
	TxDataHandler35_CAN3[21]=u16SFault3_4>>8;

	TxDataHandler35_CAN3[22]=u16SFault5_6;
	TxDataHandler35_CAN3[23]=u16SFault5_6>>8;

	TxDataHandler35_CAN3[24]=u16SFault7_8;
	TxDataHandler35_CAN3[25]=u16SFault7_8>>8;

	TxDataHandler35_CAN3[26]=u16SStatus1_2;
	TxDataHandler35_CAN3[27]=u16SStatus1_2>>8;

	TxDataHandler35_CAN3[28]=u16SStatus3_4;
	TxDataHandler35_CAN3[29]=u16SStatus3_4>>8;

	TxDataHandler35_CAN3[30]=u16RSVD_1;
	TxDataHandler35_CAN3[31]=u16RSVD_1>>8;

	TxDataHandler35_CAN3[32]=u16RSVD_2;
	TxDataHandler35_CAN3[33]=u16RSVD_2>>8;

	TxDataHandler35_CAN3[34]=u16RSVD_3;
	TxDataHandler35_CAN3[35]=u16RSVD_3>>8;

	TxDataHandler35_CAN3[36]=u16RSVD_4;
	TxDataHandler35_CAN3[37]=u16RSVD_4>>8;

	TxDataHandler35_CAN3[38]=u16RSVD_5;
	TxDataHandler35_CAN3[39]=u16RSVD_5>>8;

	TxDataHandler35_CAN3[40]=u16RSVD_6;
	TxDataHandler35_CAN3[41]=u16RSVD_6>>8;

	TxDataHandler35_CAN3[42]=u16RSVD_7;
	TxDataHandler35_CAN3[43]=u16RSVD_7>>8;

	TxDataHandler35_CAN3[44]=u16RSVD_8;
	TxDataHandler35_CAN3[45]=u16RSVD_8>>8;

	TxDataHandler35_CAN3[46]=u16RSVD_9;
	TxDataHandler35_CAN3[47]=u16RSVD_9>>8;

	TxDataHandler35_CAN3[48]=u16RSVD_10;
	TxDataHandler35_CAN3[49]=u16RSVD_10>>8;

	TxDataHandler35_CAN3[50]=u16RSVD_11;
	TxDataHandler35_CAN3[51]=u16RSVD_11>>8;

	TxDataHandler35_CAN3[52]=u16RSVD_12;
	TxDataHandler35_CAN3[53]=u16RSVD_12>>8;

	TxDataHandler35_CAN3[54]=u16RSVD_13;
	TxDataHandler35_CAN3[55]=u16RSVD_13>>8;

	TxDataHandler35_CAN3[56]=u16RSVD_14;
	TxDataHandler35_CAN3[57]=u16RSVD_14>>8;

	TxDataHandler35_CAN3[58]=u16RSVD_15;
	TxDataHandler35_CAN3[59]=u16RSVD_15>>8;

	TxDataHandler35_CAN3[60]=u16RSVD_16;
	TxDataHandler35_CAN3[61]=u16RSVD_16>>8;

	TxDataHandler35_CAN3[62]=u16RSVD_17;
	TxDataHandler35_CAN3[63]=u16RSVD_17>>8;

	if (HAL_FDCAN_AddMessageToTxFifoQ(&hfdcan3, &TxHeader35_CAN3, TxDataHandler35_CAN3) != HAL_OK)
	{}
	else
	{}
	HAL_Delay(1);
}
//36
void Master_To_Monitor_Frame37_Slave36(float Diode_Temperature,float Transformer_Temperature,float FEC_Temperature,float PSFB_Temperature,float DC_Busvoltage,float DC_Bus_Current,float FEC_input_Current,float PSFB_Output_Voltage,
		float PSFB_Output_Current,uint16_t SFault1_2,uint16_t SFault3_4,uint16_t SFault5_6,uint16_t SFault7_8,uint16_t SStatus1_2,uint16_t SStatus3_4,uint16_t RSVD_1,
		uint16_t RSVD_2,uint16_t RSVD_3,uint16_t RSVD_4,uint16_t RSVD_5,uint16_t RSVD_6,uint16_t RSVD_7,uint16_t RSVD_8,uint16_t RSVD_9,
		uint16_t RSVD_10,uint16_t RSVD_11,uint16_t RSVD_12,uint16_t RSVD_13,uint16_t RSVD_14,uint16_t RSVD_15,uint16_t RSVD_16,uint16_t RSVD_17)
{

	uint16_t u16Diode_Temperature=(Diode_Temperature*MULTIFACTOR_10);
	uint16_t u16Transformer_Temperature=(Transformer_Temperature*MULTIFACTOR_10);
	uint16_t u16FEC_Temperature=(FEC_Temperature*MULTIFACTOR_10);

	uint16_t u16PSFB_Temperature=(PSFB_Temperature*MULTIFACTOR_10);
	uint16_t u16DC_Busvoltage=(DC_Busvoltage*MULTIFACTOR_10);
	uint16_t u16DC_Bus_Current=(DC_Bus_Current*MULTIFACTOR_10);

	uint16_t u16FEC_input_Current=(FEC_input_Current*MULTIFACTOR_10);
	uint16_t u16PSFB_Output_Voltage=(PSFB_Output_Voltage*MULTIFACTOR_10);
	uint16_t u16PSFB_Output_Current=(PSFB_Output_Current*MULTIFACTOR_10);

	uint16_t u16SFault1_2=(SFault1_2);
	uint16_t u16SFault3_4=(SFault3_4);
	uint16_t u16SFault5_6=(SFault5_6);
	uint16_t u16SFault7_8=(SFault7_8);

	uint16_t u16SStatus1_2=(SStatus1_2);
	uint16_t u16SStatus3_4=(SStatus3_4);

	uint16_t u16RSVD_1=(RSVD_1);
	uint16_t u16RSVD_2=(RSVD_2);
	uint16_t u16RSVD_3=(RSVD_3);
	uint16_t u16RSVD_4=(RSVD_4);
	uint16_t u16RSVD_5=(RSVD_5);
	uint16_t u16RSVD_6=(RSVD_6);
	uint16_t u16RSVD_7=(RSVD_7);
	uint16_t u16RSVD_8=(RSVD_8);
	uint16_t u16RSVD_9=(RSVD_9);
	uint16_t u16RSVD_10=(RSVD_10);
	uint16_t u16RSVD_11=(RSVD_11);
	uint16_t u16RSVD_12=(RSVD_12);
	uint16_t u16RSVD_13=(RSVD_13);
	uint16_t u16RSVD_14=(RSVD_14);
	uint16_t u16RSVD_15=(RSVD_15);
	uint16_t u16RSVD_16=(RSVD_16);
	uint16_t u16RSVD_17=(RSVD_17);


	TxDataHandler36_CAN3[0]=u16Diode_Temperature;
	TxDataHandler36_CAN3[1]=u16Diode_Temperature>>8;

	TxDataHandler36_CAN3[2]=u16Transformer_Temperature;
	TxDataHandler36_CAN3[3]=u16Transformer_Temperature>>8;

	TxDataHandler36_CAN3[4]=u16FEC_Temperature;
	TxDataHandler36_CAN3[5]=u16FEC_Temperature>>8;

	TxDataHandler36_CAN3[6]=u16PSFB_Temperature;
	TxDataHandler36_CAN3[7]=u16PSFB_Temperature>>8;

	TxDataHandler36_CAN3[8]=u16DC_Busvoltage;
	TxDataHandler36_CAN3[9]=u16DC_Busvoltage>>8;

	TxDataHandler36_CAN3[10]=u16DC_Bus_Current;
	TxDataHandler36_CAN3[11]=u16DC_Bus_Current>>8;

	TxDataHandler36_CAN3[12]=u16FEC_input_Current;
	TxDataHandler36_CAN3[13]=u16FEC_input_Current>>8;

	TxDataHandler36_CAN3[14]=u16PSFB_Output_Voltage;
	TxDataHandler36_CAN3[15]=u16PSFB_Output_Voltage>>8;

	TxDataHandler36_CAN3[16]=u16PSFB_Output_Current;
	TxDataHandler36_CAN3[17]=u16PSFB_Output_Current>>8;

	TxDataHandler36_CAN3[18]=u16SFault1_2;
	TxDataHandler36_CAN3[19]=u16SFault1_2>>8;

	TxDataHandler36_CAN3[20]=u16SFault3_4;
	TxDataHandler36_CAN3[21]=u16SFault3_4>>8;

	TxDataHandler36_CAN3[22]=u16SFault5_6;
	TxDataHandler36_CAN3[23]=u16SFault5_6>>8;

	TxDataHandler36_CAN3[24]=u16SFault7_8;
	TxDataHandler36_CAN3[25]=u16SFault7_8>>8;

	TxDataHandler36_CAN3[26]=u16SStatus1_2;
	TxDataHandler36_CAN3[27]=u16SStatus1_2>>8;

	TxDataHandler36_CAN3[28]=u16SStatus3_4;
	TxDataHandler36_CAN3[29]=u16SStatus3_4>>8;

	TxDataHandler36_CAN3[30]=u16RSVD_1;
	TxDataHandler36_CAN3[31]=u16RSVD_1>>8;

	TxDataHandler36_CAN3[32]=u16RSVD_2;
	TxDataHandler36_CAN3[33]=u16RSVD_2>>8;

	TxDataHandler36_CAN3[34]=u16RSVD_3;
	TxDataHandler36_CAN3[35]=u16RSVD_3>>8;

	TxDataHandler36_CAN3[36]=u16RSVD_4;
	TxDataHandler36_CAN3[37]=u16RSVD_4>>8;

	TxDataHandler36_CAN3[38]=u16RSVD_5;
	TxDataHandler36_CAN3[39]=u16RSVD_5>>8;

	TxDataHandler36_CAN3[40]=u16RSVD_6;
	TxDataHandler36_CAN3[41]=u16RSVD_6>>8;

	TxDataHandler36_CAN3[42]=u16RSVD_7;
	TxDataHandler36_CAN3[43]=u16RSVD_7>>8;

	TxDataHandler36_CAN3[44]=u16RSVD_8;
	TxDataHandler36_CAN3[45]=u16RSVD_8>>8;

	TxDataHandler36_CAN3[46]=u16RSVD_9;
	TxDataHandler36_CAN3[47]=u16RSVD_9>>8;

	TxDataHandler36_CAN3[48]=u16RSVD_10;
	TxDataHandler36_CAN3[49]=u16RSVD_10>>8;

	TxDataHandler36_CAN3[50]=u16RSVD_11;
	TxDataHandler36_CAN3[51]=u16RSVD_11>>8;

	TxDataHandler36_CAN3[52]=u16RSVD_12;
	TxDataHandler36_CAN3[53]=u16RSVD_12>>8;

	TxDataHandler36_CAN3[54]=u16RSVD_13;
	TxDataHandler36_CAN3[55]=u16RSVD_13>>8;

	TxDataHandler36_CAN3[56]=u16RSVD_14;
	TxDataHandler36_CAN3[57]=u16RSVD_14>>8;

	TxDataHandler36_CAN3[58]=u16RSVD_15;
	TxDataHandler36_CAN3[59]=u16RSVD_15>>8;

	TxDataHandler36_CAN3[60]=u16RSVD_16;
	TxDataHandler36_CAN3[61]=u16RSVD_16>>8;

	TxDataHandler36_CAN3[62]=u16RSVD_17;
	TxDataHandler36_CAN3[63]=u16RSVD_17>>8;

	if (HAL_FDCAN_AddMessageToTxFifoQ(&hfdcan3, &TxHeader36_CAN3, TxDataHandler36_CAN3) != HAL_OK)
	{}
	else
	{}
	HAL_Delay(1);
}
//37
void Master_To_Monitor_Frame38_Slave37(float Diode_Temperature,float Transformer_Temperature,float FEC_Temperature,float PSFB_Temperature,float DC_Busvoltage,float DC_Bus_Current,float FEC_input_Current,float PSFB_Output_Voltage,
		float PSFB_Output_Current,uint16_t SFault1_2,uint16_t SFault3_4,uint16_t SFault5_6,uint16_t SFault7_8,uint16_t SStatus1_2,uint16_t SStatus3_4,uint16_t RSVD_1,
		uint16_t RSVD_2,uint16_t RSVD_3,uint16_t RSVD_4,uint16_t RSVD_5,uint16_t RSVD_6,uint16_t RSVD_7,uint16_t RSVD_8,uint16_t RSVD_9,
		uint16_t RSVD_10,uint16_t RSVD_11,uint16_t RSVD_12,uint16_t RSVD_13,uint16_t RSVD_14,uint16_t RSVD_15,uint16_t RSVD_16,uint16_t RSVD_17)
{

	uint16_t u16Diode_Temperature=(Diode_Temperature*MULTIFACTOR_10);
	uint16_t u16Transformer_Temperature=(Transformer_Temperature*MULTIFACTOR_10);
	uint16_t u16FEC_Temperature=(FEC_Temperature*MULTIFACTOR_10);

	uint16_t u16PSFB_Temperature=(PSFB_Temperature*MULTIFACTOR_10);
	uint16_t u16DC_Busvoltage=(DC_Busvoltage*MULTIFACTOR_10);
	uint16_t u16DC_Bus_Current=(DC_Bus_Current*MULTIFACTOR_10);

	uint16_t u16FEC_input_Current=(FEC_input_Current*MULTIFACTOR_10);
	uint16_t u16PSFB_Output_Voltage=(PSFB_Output_Voltage*MULTIFACTOR_10);
	uint16_t u16PSFB_Output_Current=(PSFB_Output_Current*MULTIFACTOR_10);

	uint16_t u16SFault1_2=(SFault1_2);
	uint16_t u16SFault3_4=(SFault3_4);
	uint16_t u16SFault5_6=(SFault5_6);
	uint16_t u16SFault7_8=(SFault7_8);

	uint16_t u16SStatus1_2=(SStatus1_2);
	uint16_t u16SStatus3_4=(SStatus3_4);

	uint16_t u16RSVD_1=(RSVD_1);
	uint16_t u16RSVD_2=(RSVD_2);
	uint16_t u16RSVD_3=(RSVD_3);
	uint16_t u16RSVD_4=(RSVD_4);
	uint16_t u16RSVD_5=(RSVD_5);
	uint16_t u16RSVD_6=(RSVD_6);
	uint16_t u16RSVD_7=(RSVD_7);
	uint16_t u16RSVD_8=(RSVD_8);
	uint16_t u16RSVD_9=(RSVD_9);
	uint16_t u16RSVD_10=(RSVD_10);
	uint16_t u16RSVD_11=(RSVD_11);
	uint16_t u16RSVD_12=(RSVD_12);
	uint16_t u16RSVD_13=(RSVD_13);
	uint16_t u16RSVD_14=(RSVD_14);
	uint16_t u16RSVD_15=(RSVD_15);
	uint16_t u16RSVD_16=(RSVD_16);
	uint16_t u16RSVD_17=(RSVD_17);


	TxDataHandler37_CAN3[0]=u16Diode_Temperature;
	TxDataHandler37_CAN3[1]=u16Diode_Temperature>>8;

	TxDataHandler37_CAN3[2]=u16Transformer_Temperature;
	TxDataHandler37_CAN3[3]=u16Transformer_Temperature>>8;

	TxDataHandler37_CAN3[4]=u16FEC_Temperature;
	TxDataHandler37_CAN3[5]=u16FEC_Temperature>>8;

	TxDataHandler37_CAN3[6]=u16PSFB_Temperature;
	TxDataHandler37_CAN3[7]=u16PSFB_Temperature>>8;

	TxDataHandler37_CAN3[8]=u16DC_Busvoltage;
	TxDataHandler37_CAN3[9]=u16DC_Busvoltage>>8;

	TxDataHandler37_CAN3[10]=u16DC_Bus_Current;
	TxDataHandler37_CAN3[11]=u16DC_Bus_Current>>8;

	TxDataHandler37_CAN3[12]=u16FEC_input_Current;
	TxDataHandler37_CAN3[13]=u16FEC_input_Current>>8;

	TxDataHandler37_CAN3[14]=u16PSFB_Output_Voltage;
	TxDataHandler37_CAN3[15]=u16PSFB_Output_Voltage>>8;

	TxDataHandler37_CAN3[16]=u16PSFB_Output_Current;
	TxDataHandler37_CAN3[17]=u16PSFB_Output_Current>>8;

	TxDataHandler37_CAN3[18]=u16SFault1_2;
	TxDataHandler37_CAN3[19]=u16SFault1_2>>8;

	TxDataHandler37_CAN3[20]=u16SFault3_4;
	TxDataHandler37_CAN3[21]=u16SFault3_4>>8;

	TxDataHandler37_CAN3[22]=u16SFault5_6;
	TxDataHandler37_CAN3[23]=u16SFault5_6>>8;

	TxDataHandler37_CAN3[24]=u16SFault7_8;
	TxDataHandler37_CAN3[25]=u16SFault7_8>>8;

	TxDataHandler37_CAN3[26]=u16SStatus1_2;
	TxDataHandler37_CAN3[27]=u16SStatus1_2>>8;

	TxDataHandler37_CAN3[28]=u16SStatus3_4;
	TxDataHandler37_CAN3[29]=u16SStatus3_4>>8;

	TxDataHandler37_CAN3[30]=u16RSVD_1;
	TxDataHandler37_CAN3[31]=u16RSVD_1>>8;

	TxDataHandler37_CAN3[32]=u16RSVD_2;
	TxDataHandler37_CAN3[33]=u16RSVD_2>>8;

	TxDataHandler37_CAN3[34]=u16RSVD_3;
	TxDataHandler37_CAN3[35]=u16RSVD_3>>8;

	TxDataHandler37_CAN3[36]=u16RSVD_4;
	TxDataHandler37_CAN3[37]=u16RSVD_4>>8;

	TxDataHandler37_CAN3[38]=u16RSVD_5;
	TxDataHandler37_CAN3[39]=u16RSVD_5>>8;

	TxDataHandler37_CAN3[40]=u16RSVD_6;
	TxDataHandler37_CAN3[41]=u16RSVD_6>>8;

	TxDataHandler37_CAN3[42]=u16RSVD_7;
	TxDataHandler37_CAN3[43]=u16RSVD_7>>8;

	TxDataHandler37_CAN3[44]=u16RSVD_8;
	TxDataHandler37_CAN3[45]=u16RSVD_8>>8;

	TxDataHandler37_CAN3[46]=u16RSVD_9;
	TxDataHandler37_CAN3[47]=u16RSVD_9>>8;

	TxDataHandler37_CAN3[48]=u16RSVD_10;
	TxDataHandler37_CAN3[49]=u16RSVD_10>>8;

	TxDataHandler37_CAN3[50]=u16RSVD_11;
	TxDataHandler37_CAN3[51]=u16RSVD_11>>8;

	TxDataHandler37_CAN3[52]=u16RSVD_12;
	TxDataHandler37_CAN3[53]=u16RSVD_12>>8;

	TxDataHandler37_CAN3[54]=u16RSVD_13;
	TxDataHandler37_CAN3[55]=u16RSVD_13>>8;

	TxDataHandler37_CAN3[56]=u16RSVD_14;
	TxDataHandler37_CAN3[57]=u16RSVD_14>>8;

	TxDataHandler37_CAN3[58]=u16RSVD_15;
	TxDataHandler37_CAN3[59]=u16RSVD_15>>8;

	TxDataHandler37_CAN3[60]=u16RSVD_16;
	TxDataHandler37_CAN3[61]=u16RSVD_16>>8;

	TxDataHandler37_CAN3[62]=u16RSVD_17;
	TxDataHandler37_CAN3[63]=u16RSVD_17>>8;

	if (HAL_FDCAN_AddMessageToTxFifoQ(&hfdcan3, &TxHeader37_CAN3, TxDataHandler37_CAN3) != HAL_OK)
	{}
	else
	{}
	HAL_Delay(1);
}
//38
void Master_To_Monitor_Frame39_Slave38(float Diode_Temperature,float Transformer_Temperature,float FEC_Temperature,float PSFB_Temperature,float DC_Busvoltage,float DC_Bus_Current,float FEC_input_Current,float PSFB_Output_Voltage,
		float PSFB_Output_Current,uint16_t SFault1_2,uint16_t SFault3_4,uint16_t SFault5_6,uint16_t SFault7_8,uint16_t SStatus1_2,uint16_t SStatus3_4,uint16_t RSVD_1,
		uint16_t RSVD_2,uint16_t RSVD_3,uint16_t RSVD_4,uint16_t RSVD_5,uint16_t RSVD_6,uint16_t RSVD_7,uint16_t RSVD_8,uint16_t RSVD_9,
		uint16_t RSVD_10,uint16_t RSVD_11,uint16_t RSVD_12,uint16_t RSVD_13,uint16_t RSVD_14,uint16_t RSVD_15,uint16_t RSVD_16,uint16_t RSVD_17)
{

	uint16_t u16Diode_Temperature=(Diode_Temperature*MULTIFACTOR_10);
	uint16_t u16Transformer_Temperature=(Transformer_Temperature*MULTIFACTOR_10);
	uint16_t u16FEC_Temperature=(FEC_Temperature*MULTIFACTOR_10);

	uint16_t u16PSFB_Temperature=(PSFB_Temperature*MULTIFACTOR_10);
	uint16_t u16DC_Busvoltage=(DC_Busvoltage*MULTIFACTOR_10);
	uint16_t u16DC_Bus_Current=(DC_Bus_Current*MULTIFACTOR_10);

	uint16_t u16FEC_input_Current=(FEC_input_Current*MULTIFACTOR_10);
	uint16_t u16PSFB_Output_Voltage=(PSFB_Output_Voltage*MULTIFACTOR_10);
	uint16_t u16PSFB_Output_Current=(PSFB_Output_Current*MULTIFACTOR_10);

	uint16_t u16SFault1_2=(SFault1_2);
	uint16_t u16SFault3_4=(SFault3_4);
	uint16_t u16SFault5_6=(SFault5_6);
	uint16_t u16SFault7_8=(SFault7_8);

	uint16_t u16SStatus1_2=(SStatus1_2);
	uint16_t u16SStatus3_4=(SStatus3_4);

	uint16_t u16RSVD_1=(RSVD_1);
	uint16_t u16RSVD_2=(RSVD_2);
	uint16_t u16RSVD_3=(RSVD_3);
	uint16_t u16RSVD_4=(RSVD_4);
	uint16_t u16RSVD_5=(RSVD_5);
	uint16_t u16RSVD_6=(RSVD_6);
	uint16_t u16RSVD_7=(RSVD_7);
	uint16_t u16RSVD_8=(RSVD_8);
	uint16_t u16RSVD_9=(RSVD_9);
	uint16_t u16RSVD_10=(RSVD_10);
	uint16_t u16RSVD_11=(RSVD_11);
	uint16_t u16RSVD_12=(RSVD_12);
	uint16_t u16RSVD_13=(RSVD_13);
	uint16_t u16RSVD_14=(RSVD_14);
	uint16_t u16RSVD_15=(RSVD_15);
	uint16_t u16RSVD_16=(RSVD_16);
	uint16_t u16RSVD_17=(RSVD_17);


	TxDataHandler38_CAN3[0]=u16Diode_Temperature;
	TxDataHandler38_CAN3[1]=u16Diode_Temperature>>8;

	TxDataHandler38_CAN3[2]=u16Transformer_Temperature;
	TxDataHandler38_CAN3[3]=u16Transformer_Temperature>>8;

	TxDataHandler38_CAN3[4]=u16FEC_Temperature;
	TxDataHandler38_CAN3[5]=u16FEC_Temperature>>8;

	TxDataHandler38_CAN3[6]=u16PSFB_Temperature;
	TxDataHandler38_CAN3[7]=u16PSFB_Temperature>>8;

	TxDataHandler38_CAN3[8]=u16DC_Busvoltage;
	TxDataHandler38_CAN3[9]=u16DC_Busvoltage>>8;

	TxDataHandler38_CAN3[10]=u16DC_Bus_Current;
	TxDataHandler38_CAN3[11]=u16DC_Bus_Current>>8;

	TxDataHandler38_CAN3[12]=u16FEC_input_Current;
	TxDataHandler38_CAN3[13]=u16FEC_input_Current>>8;

	TxDataHandler38_CAN3[14]=u16PSFB_Output_Voltage;
	TxDataHandler38_CAN3[15]=u16PSFB_Output_Voltage>>8;

	TxDataHandler38_CAN3[16]=u16PSFB_Output_Current;
	TxDataHandler38_CAN3[17]=u16PSFB_Output_Current>>8;

	TxDataHandler38_CAN3[18]=u16SFault1_2;
	TxDataHandler38_CAN3[19]=u16SFault1_2>>8;

	TxDataHandler38_CAN3[20]=u16SFault3_4;
	TxDataHandler38_CAN3[21]=u16SFault3_4>>8;

	TxDataHandler38_CAN3[22]=u16SFault5_6;
	TxDataHandler38_CAN3[23]=u16SFault5_6>>8;

	TxDataHandler38_CAN3[24]=u16SFault7_8;
	TxDataHandler38_CAN3[25]=u16SFault7_8>>8;

	TxDataHandler38_CAN3[26]=u16SStatus1_2;
	TxDataHandler38_CAN3[27]=u16SStatus1_2>>8;

	TxDataHandler38_CAN3[28]=u16SStatus3_4;
	TxDataHandler38_CAN3[29]=u16SStatus3_4>>8;

	TxDataHandler38_CAN3[30]=u16RSVD_1;
	TxDataHandler38_CAN3[31]=u16RSVD_1>>8;

	TxDataHandler38_CAN3[32]=u16RSVD_2;
	TxDataHandler38_CAN3[33]=u16RSVD_2>>8;

	TxDataHandler38_CAN3[34]=u16RSVD_3;
	TxDataHandler38_CAN3[35]=u16RSVD_3>>8;

	TxDataHandler38_CAN3[36]=u16RSVD_4;
	TxDataHandler38_CAN3[37]=u16RSVD_4>>8;

	TxDataHandler38_CAN3[38]=u16RSVD_5;
	TxDataHandler38_CAN3[39]=u16RSVD_5>>8;

	TxDataHandler38_CAN3[40]=u16RSVD_6;
	TxDataHandler38_CAN3[41]=u16RSVD_6>>8;

	TxDataHandler38_CAN3[42]=u16RSVD_7;
	TxDataHandler38_CAN3[43]=u16RSVD_7>>8;

	TxDataHandler38_CAN3[44]=u16RSVD_8;
	TxDataHandler38_CAN3[45]=u16RSVD_8>>8;

	TxDataHandler38_CAN3[46]=u16RSVD_9;
	TxDataHandler38_CAN3[47]=u16RSVD_9>>8;

	TxDataHandler38_CAN3[48]=u16RSVD_10;
	TxDataHandler38_CAN3[49]=u16RSVD_10>>8;

	TxDataHandler38_CAN3[50]=u16RSVD_11;
	TxDataHandler38_CAN3[51]=u16RSVD_11>>8;

	TxDataHandler38_CAN3[52]=u16RSVD_12;
	TxDataHandler38_CAN3[53]=u16RSVD_12>>8;

	TxDataHandler38_CAN3[54]=u16RSVD_13;
	TxDataHandler38_CAN3[55]=u16RSVD_13>>8;

	TxDataHandler38_CAN3[56]=u16RSVD_14;
	TxDataHandler38_CAN3[57]=u16RSVD_14>>8;

	TxDataHandler38_CAN3[58]=u16RSVD_15;
	TxDataHandler38_CAN3[59]=u16RSVD_15>>8;

	TxDataHandler38_CAN3[60]=u16RSVD_16;
	TxDataHandler38_CAN3[61]=u16RSVD_16>>8;

	TxDataHandler38_CAN3[62]=u16RSVD_17;
	TxDataHandler38_CAN3[63]=u16RSVD_17>>8;

	if (HAL_FDCAN_AddMessageToTxFifoQ(&hfdcan3, &TxHeader38_CAN3, TxDataHandler38_CAN3) != HAL_OK)
	{}
	else
	{}
	HAL_Delay(1);
}
//39
void Master_To_Monitor_Frame40_Slave39(float Diode_Temperature,float Transformer_Temperature,float FEC_Temperature,float PSFB_Temperature,float DC_Busvoltage,float DC_Bus_Current,float FEC_input_Current,float PSFB_Output_Voltage,
		float PSFB_Output_Current,uint16_t SFault1_2,uint16_t SFault3_4,uint16_t SFault5_6,uint16_t SFault7_8,uint16_t SStatus1_2,uint16_t SStatus3_4,uint16_t RSVD_1,
		uint16_t RSVD_2,uint16_t RSVD_3,uint16_t RSVD_4,uint16_t RSVD_5,uint16_t RSVD_6,uint16_t RSVD_7,uint16_t RSVD_8,uint16_t RSVD_9,
		uint16_t RSVD_10,uint16_t RSVD_11,uint16_t RSVD_12,uint16_t RSVD_13,uint16_t RSVD_14,uint16_t RSVD_15,uint16_t RSVD_16,uint16_t RSVD_17)
{

	uint16_t u16Diode_Temperature=(Diode_Temperature*MULTIFACTOR_10);
	uint16_t u16Transformer_Temperature=(Transformer_Temperature*MULTIFACTOR_10);
	uint16_t u16FEC_Temperature=(FEC_Temperature*MULTIFACTOR_10);

	uint16_t u16PSFB_Temperature=(PSFB_Temperature*MULTIFACTOR_10);
	uint16_t u16DC_Busvoltage=(DC_Busvoltage*MULTIFACTOR_10);
	uint16_t u16DC_Bus_Current=(DC_Bus_Current*MULTIFACTOR_10);

	uint16_t u16FEC_input_Current=(FEC_input_Current*MULTIFACTOR_10);
	uint16_t u16PSFB_Output_Voltage=(PSFB_Output_Voltage*MULTIFACTOR_10);
	uint16_t u16PSFB_Output_Current=(PSFB_Output_Current*MULTIFACTOR_10);

	uint16_t u16SFault1_2=(SFault1_2);
	uint16_t u16SFault3_4=(SFault3_4);
	uint16_t u16SFault5_6=(SFault5_6);
	uint16_t u16SFault7_8=(SFault7_8);

	uint16_t u16SStatus1_2=(SStatus1_2);
	uint16_t u16SStatus3_4=(SStatus3_4);

	uint16_t u16RSVD_1=(RSVD_1);
	uint16_t u16RSVD_2=(RSVD_2);
	uint16_t u16RSVD_3=(RSVD_3);
	uint16_t u16RSVD_4=(RSVD_4);
	uint16_t u16RSVD_5=(RSVD_5);
	uint16_t u16RSVD_6=(RSVD_6);
	uint16_t u16RSVD_7=(RSVD_7);
	uint16_t u16RSVD_8=(RSVD_8);
	uint16_t u16RSVD_9=(RSVD_9);
	uint16_t u16RSVD_10=(RSVD_10);
	uint16_t u16RSVD_11=(RSVD_11);
	uint16_t u16RSVD_12=(RSVD_12);
	uint16_t u16RSVD_13=(RSVD_13);
	uint16_t u16RSVD_14=(RSVD_14);
	uint16_t u16RSVD_15=(RSVD_15);
	uint16_t u16RSVD_16=(RSVD_16);
	uint16_t u16RSVD_17=(RSVD_17);


	TxDataHandler39_CAN3[0]=u16Diode_Temperature;
	TxDataHandler39_CAN3[1]=u16Diode_Temperature>>8;

	TxDataHandler39_CAN3[2]=u16Transformer_Temperature;
	TxDataHandler39_CAN3[3]=u16Transformer_Temperature>>8;

	TxDataHandler39_CAN3[4]=u16FEC_Temperature;
	TxDataHandler39_CAN3[5]=u16FEC_Temperature>>8;

	TxDataHandler39_CAN3[6]=u16PSFB_Temperature;
	TxDataHandler39_CAN3[7]=u16PSFB_Temperature>>8;

	TxDataHandler39_CAN3[8]=u16DC_Busvoltage;
	TxDataHandler39_CAN3[9]=u16DC_Busvoltage>>8;

	TxDataHandler39_CAN3[10]=u16DC_Bus_Current;
	TxDataHandler39_CAN3[11]=u16DC_Bus_Current>>8;

	TxDataHandler39_CAN3[12]=u16FEC_input_Current;
	TxDataHandler39_CAN3[13]=u16FEC_input_Current>>8;

	TxDataHandler39_CAN3[14]=u16PSFB_Output_Voltage;
	TxDataHandler39_CAN3[15]=u16PSFB_Output_Voltage>>8;

	TxDataHandler39_CAN3[16]=u16PSFB_Output_Current;
	TxDataHandler39_CAN3[17]=u16PSFB_Output_Current>>8;

	TxDataHandler39_CAN3[18]=u16SFault1_2;
	TxDataHandler39_CAN3[19]=u16SFault1_2>>8;

	TxDataHandler39_CAN3[20]=u16SFault3_4;
	TxDataHandler39_CAN3[21]=u16SFault3_4>>8;

	TxDataHandler39_CAN3[22]=u16SFault5_6;
	TxDataHandler39_CAN3[23]=u16SFault5_6>>8;

	TxDataHandler39_CAN3[24]=u16SFault7_8;
	TxDataHandler39_CAN3[25]=u16SFault7_8>>8;

	TxDataHandler39_CAN3[26]=u16SStatus1_2;
	TxDataHandler39_CAN3[27]=u16SStatus1_2>>8;

	TxDataHandler39_CAN3[28]=u16SStatus3_4;
	TxDataHandler39_CAN3[29]=u16SStatus3_4>>8;

	TxDataHandler39_CAN3[30]=u16RSVD_1;
	TxDataHandler39_CAN3[31]=u16RSVD_1>>8;

	TxDataHandler39_CAN3[32]=u16RSVD_2;
	TxDataHandler39_CAN3[33]=u16RSVD_2>>8;

	TxDataHandler39_CAN3[34]=u16RSVD_3;
	TxDataHandler39_CAN3[35]=u16RSVD_3>>8;

	TxDataHandler39_CAN3[36]=u16RSVD_4;
	TxDataHandler39_CAN3[37]=u16RSVD_4>>8;

	TxDataHandler39_CAN3[38]=u16RSVD_5;
	TxDataHandler39_CAN3[39]=u16RSVD_5>>8;

	TxDataHandler39_CAN3[40]=u16RSVD_6;
	TxDataHandler39_CAN3[41]=u16RSVD_6>>8;

	TxDataHandler39_CAN3[42]=u16RSVD_7;
	TxDataHandler39_CAN3[43]=u16RSVD_7>>8;

	TxDataHandler39_CAN3[44]=u16RSVD_8;
	TxDataHandler39_CAN3[45]=u16RSVD_8>>8;

	TxDataHandler39_CAN3[46]=u16RSVD_9;
	TxDataHandler39_CAN3[47]=u16RSVD_9>>8;

	TxDataHandler39_CAN3[48]=u16RSVD_10;
	TxDataHandler39_CAN3[49]=u16RSVD_10>>8;

	TxDataHandler39_CAN3[50]=u16RSVD_11;
	TxDataHandler39_CAN3[51]=u16RSVD_11>>8;

	TxDataHandler39_CAN3[52]=u16RSVD_12;
	TxDataHandler39_CAN3[53]=u16RSVD_12>>8;

	TxDataHandler39_CAN3[54]=u16RSVD_13;
	TxDataHandler39_CAN3[55]=u16RSVD_13>>8;

	TxDataHandler39_CAN3[56]=u16RSVD_14;
	TxDataHandler39_CAN3[57]=u16RSVD_14>>8;

	TxDataHandler39_CAN3[58]=u16RSVD_15;
	TxDataHandler39_CAN3[59]=u16RSVD_15>>8;

	TxDataHandler39_CAN3[60]=u16RSVD_16;
	TxDataHandler39_CAN3[61]=u16RSVD_16>>8;

	TxDataHandler39_CAN3[62]=u16RSVD_17;
	TxDataHandler39_CAN3[63]=u16RSVD_17>>8;

	if (HAL_FDCAN_AddMessageToTxFifoQ(&hfdcan3, &TxHeader39_CAN3, TxDataHandler39_CAN3) != HAL_OK)
	{}
	else
	{}
	HAL_Delay(1);
}*/
