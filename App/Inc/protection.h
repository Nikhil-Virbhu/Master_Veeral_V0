#include "main.h"

typedef union
{
  struct
  {
    uint8_t rOverVol : 1;        //bit 0
    uint8_t yOverVol : 1;        //bit 1
    uint8_t bOverVol : 1;        //bit 2
    uint8_t eOverVol : 1;        //bit 3
    uint8_t rUnderVol : 1;       //bit 4
    uint8_t yUnderVol : 1;       //bit 5
    uint8_t bUnderVol : 1;       //bit 6
    uint8_t eUnderVol : 1;       //bit 7
  }bits;
  uint8_t byte;
}acVoltFault_t;

typedef union
{
  struct
  {
    uint8_t rOverCur : 1;        //bit 0
    uint8_t yOverCur : 1;        //bit 1
    uint8_t bOverCur : 1;        //bit 2
    uint8_t rUnderCur : 1;        //bit 3
    uint8_t yUnderCur : 1;       //bit 4
    uint8_t bUnderCur : 1;       //bit 5
    uint8_t rsvd6 : 1;       //bit 6
    uint8_t rsvd7 : 1;       //bit 7
  }bits;
  uint8_t byte;
}acCurrFault_t;

typedef union
{
  struct
  {
    uint8_t ext_fault : 1;                  //bit 0
    uint8_t emergency_stop : 1;             //bit 1
    uint8_t rsvd2 : 1;                      //bit 2
    uint8_t mcu_error : 1;                  //bit 3
    uint8_t can_1_fail : 1;                   //bit 4
    uint8_t address_fault : 1;         //bit 5
    uint8_t eeprom_fault : 1;                //bit 6
    uint8_t can_2_fail : 1;                      //bit 7
  }bits;
  uint8_t byte;
 }criticalFault_t;

 typedef union
{
  struct
  {
    uint8_t fuse1_fail : 1;             //bit 0
    uint8_t door_feedback : 1;             //bit 1
    uint8_t fuse3_fail : 1;             //bit 2
    uint8_t slave_fw_fault : 1;                  //bit 3
    uint8_t DC_contactor_fail : 1;                  //bit 4
    uint8_t rsvd5 : 1;                  //bit 5
    uint8_t rsvd6 : 1;                  //bit 6
    uint8_t rsvd7 : 1;                  //bit 7
  }bits;
  uint8_t byte;
 }criticalFault2_t;

 typedef union
 {
   struct
   {
     uint8_t vOutOver : 1;              //bit 0
     uint8_t vOutUnder : 1;             //bit 1
     uint8_t iOutOver : 1;              //bit 2
     uint8_t iOutUnder : 1;             //bit 3
     uint8_t rsvd4 : 1;                 //bit 4
     uint8_t rsvd5 : 1;                 //bit 5
     uint8_t rsvd6 : 1;                 //bit 6
     uint8_t rsvd7 : 1;                 //bit 7
   }bits;
   uint8_t byte;
 }dcFault_t;

 typedef union
 {
   struct
   {
     uint8_t ntc1OverTemp : 1;              //bit 0
     uint8_t ntc2OverTemp : 1;             //bit 1
     uint8_t rsvd2 : 1;              //bit 2
     uint8_t rsvd3 : 1;             //bit 3
     uint8_t rsvd4 : 1;                 //bit 4
     uint8_t rsvd5 : 1;                 //bit 5
     uint8_t rsvd6 : 1;                 //bit 6
     uint8_t rsvd7 : 1;                 //bit 7
   }bits;
   uint8_t byte;
 }tempFault_t;

 typedef union
 {
 	struct
 	{
 		uint8_t system_on : 1;
 		uint8_t fault_reset : 1;
 		uint8_t emergency_stop : 1;
 		uint8_t psfb_on : 1;
 		uint8_t afe_pwm_mask : 1;
 		uint8_t rsvd5 : 1;
 		uint8_t rsvd6 : 1;
 		uint8_t rsvd7 : 1;
 	}bits;
 	uint8_t byte;
 }command_t;

 typedef union
 {
 	struct
 	{
 		uint8_t fuse_1 : 1;
 		uint8_t door_feedback : 1;
 		uint8_t fuse_3 : 1;
 		uint8_t rsvd3 : 1;
 		uint8_t rsvd4 : 1;
 		uint8_t rsvd5 : 1;
 		uint8_t rsvd6 : 1;
 		uint8_t rsvd7 : 1;
 	}bits;
 	uint8_t byte;
 }mstatus1_t;


 /*ovL - Over limit*/
 typedef struct
 {
	uint16_t ovlCount;
	uint16_t ovlFault;
	uint16_t ovlResetCount;
	uint16_t ovlNoOfReset;
	uint16_t ovlFaultLatched;
	uint32_t ovlCoolDownCount;
	uint16_t threshold;
	float threshold_time; // threshold_time
	uint16_t reset_threshold;
	float reset_threshold_time;// reset_threshold_time
	uint8_t autoreset;
	uint8_t cooldown_enable;
	uint32_t cooldown_time;
	uint8_t no_of_reset;
	uint16_t sampleFreq;
 }ovLFault_t;

 /*underLimit (underL)*/
 typedef struct
 {
 	uint16_t underLCount;
 	uint16_t underLFault;
 	uint16_t underLResetCount;
 	uint16_t underLNoOfReset;
 	uint16_t underLFaultLatched;
 	uint16_t underLCoolDownCount;
 	uint16_t threshold;
 	float threshold_time;
 	uint16_t reset_threshold;
 	float reset_threshold_time;
 	uint8_t autoreset;
 	uint8_t cooldown_enable;
 	uint32_t cooldown_time;
 	uint8_t no_of_reset;
 	uint16_t sampleFreq;
 }underLFault_t;

#ifdef _PROTECTION_
 	 acVoltFault_t acVoltFault;
 	 acCurrFault_t acCurrFault;
 	 criticalFault_t criticalFault;
 	 criticalFault2_t criticalFault2;
 	 tempFault_t tempFault;
 	 dcFault_t dcFault;
 	 command_t cmd;
 	 mstatus1_t status1;
 	 ovLFault_t RphOverVol,YphOverVol,BphOverVol,EphOverVol,RphOverCur,YphOverCur,BphOverCur,VoutOverVol,IoutOverCur,ntc1OverTemp,ntc2OverTemp;
 	 underLFault_t RphUnVol,YphUnVol,BphUnVol,VoutUnVol;
 	 uint8_t masterFaultFlag = 0,slaveFaultFlag = 0;
 	 void faultInit(void);
 	 void check_over_limit(ovLFault_t *fhand, float value);
 	 void check_under_limit(underLFault_t *fhand, float value);
 	 void check_over_limitI(ovLFault_t *fhand, float value);
 	 void check_fuse_fault(void);
 	 void check_emergency_fault(void);
     void protectionMonitoring_AC(void);
     void protectionMonitoring_DC(void);
     void protectionMonitoring_Temp(void);
 	 void manual_fault_reset(void);

#else
 	 extern acVoltFault_t acVoltFault;
 	 extern acCurrFault_t acCurrFault;
 	 extern criticalFault_t criticalFault;
 	 extern criticalFault2_t criticalFault2;
 	 extern tempFault_t tempFault;
 	 extern dcFault_t dcFault;
 	 extern command_t cmd;
 	 extern mstatus1_t status1;
 	 extern uint8_t masterFaultFlag,slaveFaultFlag;
 	 extern ovLFault_t RphOverVol,YphOverVol,BphOverVol,EphOverVol,RphOverCur,YphOverCur,BphOverCur,VoutOverVol,IoutOverCur,ntc1OverTemp,ntc2OverTemp;
 	 extern underLFault_t RphUnVol,YphUnVol,BphUnVol,VoutUnVol;
 	 extern void faultInit(void);
 	 extern void check_over_limit(ovLFault_t *fhand, float value);
 	 extern void check_under_limit(underLFault_t *fhand, float value);
 	 extern void check_fuse_fault(void);
 	 extern void check_emergency_fault(void);
 	 extern void protectionMonitoring_AC(void);
 	 extern void protectionMonitoring_DC(void);
 	 extern void protectionMonitoring_Temp(void);
 	 extern void manual_fault_reset(void);
#endif
