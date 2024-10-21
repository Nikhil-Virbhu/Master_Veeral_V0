#include "main.h"
/* File description:
*/
typedef enum {
	IN1 = 0U,
	IN2,
	IN3,
	IN4,
	IN5,
	IN6,
	IN7,
	IN8,
	IN9
}digiIn;
typedef enum {
	OUT1,
	OUT2,
	OUT3,
	LED1
}digiOut;

#ifdef _IO_
	uint8_t psfbCounter;
	uint16_t masterAddress;
	void getDigiIn(void);
	void checkDebounce(void);
	void setDigiOut(digiOut relayNo, GPIO_PinState state);
	void generateAddress(void);
#else
	extern uint8_t fuse1,fuse2,fuse3;
	extern uint8_t psfbCounter;
	extern uint16_t masterAddress;
	extern void checkDebounce(void);
	extern void getDigiIn();
	extern void setDigiOut(digiOut relayNo, GPIO_PinState state);
	extern void generateAddress();
#endif
