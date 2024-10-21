#include "main.h"
#ifdef SLAVE_MONITOR
	uint8_t PSFBFeedbackWaitFlag; // This flag shows the waiting period for completion of PSFB start and its start feedback command.
	uint8_t AFEOnFlag;
	void slave_health(uint8_t noOfSlaves);
	void checkPsfbStatus(uint8_t noOfSlaves);
	void psfbTimeout(void);
	void check_slave_firmware(uint8_t noOfSlaves);
#else
	extern uint8_t PSFBFeedbackWaitFlag;
	extern uint8_t AFEOnFlag;
	extern void slave_health(uint8_t noOfSlaves);
	extern void checkPsfbStatus(uint8_t noOfSlaves);
	extern void psfbTimeout(void);
	extern void check_slave_firmware(uint8_t noOfSlaves);
#endif
