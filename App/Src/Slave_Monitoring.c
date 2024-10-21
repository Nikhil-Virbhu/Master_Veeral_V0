#define SLAVE_MONITOR
//#define BYPASS_AFE_START_BUTTON



#include "Slave_Monitoring.h"
#include "CAN_Parameters.h"
#include "CAN2_Receving.h"
#include "process.h"
#include "protection.h"
#include "io.h"


/*
 *  Function to determine overall health of all the cells - slaves
 */
void slave_health(uint8_t noOfSlaves)
{

//	uint8_t i;
//	for(i=1; i<=noOfSlaves; i++)
//	{
//		slaveFaultFlag = slaveFaultFlag || Cell[i].Status1.bits.sHealthStatus;
//		if(slaveFaultFlag==1){
//			turnOff();
//			break;
//		}
//	}

	if(Cell[14].Status1.bits.sHealthStatus == 1) //|| Cell[14].Status1.bits.sHealthStatus == 1 || Cell[27].Status1.bits.sHealthStatus == 1 )
			//  ||			Cell[2].Status1.bits.sHealthStatus == 1 || Cell[15].Status1.bits.sHealthStatus == 1 || Cell[28].Status1.bits.sHealthStatus == 1)
		{
		slaveFaultFlag = 1;
		turnOff();
	}
	if(Cell[14].Status1.bits.sHealthStatus == 0)// && Cell[14].Status1.bits.sHealthStatus == 0 && Cell[27].Status1.bits.sHealthStatus == 0)
		//&&			Cell[2].Status1.bits.sHealthStatus == 0 && Cell[15].Status1.bits.sHealthStatus == 0 && Cell[28].Status1.bits.sHealthStatus == 0)
		{
		slaveFaultFlag = 0;
	}
}

/*
 * Function to determine if all PSFB ramp up is complete
 * CALL FUNCTION FROM: 40msec Task in Sequence.C file, Low priority task
 *
 */
void checkPsfbStatus(uint8_t noOfSlaves)
{
	uint8_t initState = 1;
//	uint8_t i;
//	for(i=1;i<noOfSlaves;i++)
//	{
//		initState = initState && Cell[i].Status1.bits.psfbFeedback;
//	}

	initState = (Cell[14].Status1.bits.psfbFeedback);// && Cell[14].Status1.bits.psfbFeedback && Cell[27].Status1.bits.psfbFeedback);
			//&& Cell[2].Status1.bits.psfbFeedback && Cell[15].Status1.bits.psfbFeedback && Cell[28].Status1.bits.psfbFeedback);
		psfbFeedback = initState;
		if (psfbFeedback == 1 && PSFBFeedbackWaitFlag == 1){
		PSFBFeedbackWaitFlag = 0;
	}
// This provision is used to bypass afe_on button and Directly start AFEC Pulse/Algorithm as soon as all PSFBFeedBack are Received.
#ifdef BYPASS_AFE_START_BUTTON
	if(Turn_ONOFF_Flag == 0 && psfb_OnOff_Flag==1 && psfbFeedback == 1 && masterFaultFlag == 0 && slaveFaultFlag == 0)
		{
			Turn_ONOFF_Flag = 1; //System on
			StartTime_ParameterInit();
			cmd.bits.system_on = 1;
			PSFBFeedbackWaitFlag=0;
			setDigiOut(LED1, GPIO_PIN_SET);
		}
#else
	if(Turn_ONOFF_Flag == 0 && psfb_OnOff_Flag==1 && psfbFeedback == 1 && masterFaultFlag == 0 && slaveFaultFlag == 0 && AFEOnFlag == 1 && (GridAngle<=5.0f*180.0f/3.14f))
			{
				StartTime_ParameterInit();
				cmd.bits.system_on = 1; // (GLOBAL CAN BIT WHICH INDICATE THE FULL SYSTEM TURN ON)
				PSFBFeedbackWaitFlag=0;
				Turn_ONOFF_Flag = 1; // (lOCAL FULL SYSTEM TURN ON INDICATION FLAG)This Flag Indicates that full system is ON and Control System is started Execution.
				setDigiOut(LED1, GPIO_PIN_SET);
			}
#endif
}

/*
 * Function to determine if all PSFB ramp up is complete
 */
void psfbTimeout()
{
	if(PSFBFeedbackWaitFlag == 1){
		psfbCounter++;
		if(psfbCounter>20){
			turnOff();
		}
	}
}

void check_slave_firmware(uint8_t noOfSlaves)
{
	uint8_t i;
	uint8_t compV = Cell[1].Major_Firmware;
	for(i=2; i<= noOfSlaves; i++)
	{
		if(Cell[i].Major_Firmware != compV)
		{
			criticalFault2.bits.slave_fw_fault = 1;
		}
	}
}
