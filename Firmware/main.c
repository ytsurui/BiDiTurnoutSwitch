/*
 * main.c
 *
 * Created: 2021/12/31 0:07:21
 * Author : ytsurui
 */ 

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#include "cpuclk.h"
#include "rtc.h"
#include "usart_railcom.h"
#include "railcom_recv.h"
#include "display_controller.h"
#include "pushButton.h"
#include "turnoutDriver.h"
#include "trainaddrStorage.h"
#include "turnoutaddrStorage.h"
#include "dcc_input.h"
#include "lock_sensor.h"

#define NO_RAILCOM_COUNT_MAX 2000

void delay_ms(uint8_t ms) {
	while(ms--) {
		_delay_ms(1);
	}
}

void progSwAddr(uint16_t addr, uint8_t stat) {
	static uint16_t addrCache;
	static uint8_t lastStat;
	//return;
	
	if ((addr == 0) || (addr > 2048)) return;
	
	if ((addr == addrCache) && (lastStat != stat)) {
		writeTurnoutAddr(addr);
		set_7seg_data(addr);
	} else {
		addrCache = addr;
		lastStat = stat;
	}
}

void moveSwitchFromAccPacket(uint16_t addr, uint8_t stat) {
	uint16_t swAddr;
	swAddr = getTurnoutAddr();
	
	if ((swAddr == 0) || (swAddr > 2048)) return;
	
	if (addr == swAddr) {
		if (stat) {
			// closed
			setTurnout(TURNOUT_CLOSE);
		} else {
			// thrown
			setTurnout(TURNOUT_THROWN);
		}
	}
}

int main(void)
{
	//uint8_t count1 = 0;
	
	uint8_t dccRecvPacketCache[48];
	uint8_t dccRecvPacketLength;
	
	uint16_t noRailcomCounter = 0;
	uint16_t railcomFlushCount = 0;
	
	uint16_t swAddr;
	
	uint16_t trainAddr;
	
	uint8_t swMove;
	uint16_t clrCount;
	
	uint8_t initCount = 0;
	
	setSwitchCallback(moveSwitchFromAccPacket);
	
	setCLK();
	initRTC();
	initUART0();
	//initUART1();
	initTrainAddrStorage();
	initTurnoutAddrStorage();
	
	initDisplay();
	initButton();
	initTurnoutDriver();
	initLockSensor();
	initDCCinput();
	
	PORTC.DIR = 0x0C;
	PORTF.DIR |= 0x02;
	
	sei();
	
	while (1) {
		if (chkRTCflag()) {
			initCount++;
			buttonClock();
			displayClock();
			
			if (initCount > 100) {
				break;
			}
		}
		
		if (getButtonStat(BUTTON_ID_PROG)) {
			// Prog Mode
			initCount = 0xFF;
			break;
		}
	}
	
	if (initCount == 0xFF) {
		// Prog Mode
		set_prog_mode();
		setSwitchCallback(progSwAddr);
		clrCount = 0;
		
		while (1) {
			dccPacketShifter(&dccRecvPacketLength, dccRecvPacketCache);
			if (dccRecvPacketLength) {
				dccPacketRouter(dccRecvPacketLength, dccRecvPacketCache);
				dccRecvPacketLength = 0;
			}
			
			if (chkRTCflag()) {
				displayClock();
				buttonClock();
				
				if ((clrCount != 0) && (clrCount < 1000)) {
					clrCount++;
				}
			}
			
			if (getButtonStat(BUTTON_ID_CLR)) {
				// Long-Push Clear
				//clrCount++;
				if (clrCount == 0) {
					clrCount = 1;
				}
			} else {
				clrCount = 0;
			}
			
			if (clrCount >= 1000) {
				set_clr_msg();
				writeTurnoutAddr(0);
				clearAddrStorageRaw();
			}
			
		}
	}
	
	swAddr = getTurnoutAddr();
	if ((swAddr != 0) && (swAddr <= 2048)) {
		set_7seg_data(swAddr);
	}
	
	//if (getTurnoutAddr() != 0) {
	//	set_7seg_data(getTurnoutAddr());
	//}
	
	setSwitchCallback(moveSwitchFromAccPacket);
	
    while (1) 
    {
		dccPacketShifter(&dccRecvPacketLength, dccRecvPacketCache);
		if (dccRecvPacketLength) {
			dccPacketRouter(dccRecvPacketLength, dccRecvPacketCache);
			dccRecvPacketLength = 0;
		}
		
		if (chkRTCflag()) {
			// 1ms Timer
			lockSensorClock();
			displayClock();
			buttonClock();
			turnoutClock();
			
			timeoutCountup();
			
			if (lockSensorStat()) {
				// Turnout Lock	
				resetTurnoutTimer();
			}
			
			if (noRailcomCounter < NO_RAILCOM_COUNT_MAX) {
				noRailcomCounter++;	
				if (addrViewTimeout()) {
					set_led_power_stat(0);
					railcomFlushCount++;
					if (railcomFlushCount == 256) {
						set_null_msg(0);
					} else if (railcomFlushCount == 512) {
						set_null_msg(1);
					} else if (railcomFlushCount == 768) {
						set_null_msg(2);
					} else if (railcomFlushCount == 1024) {
						set_null_msg(3);
						railcomFlushCount = 0;
					} else if (railcomFlushCount > 1024) {
						railcomFlushCount = 0;
					}
				}
			} else {
				railcomFlushCount++;
				if (railcomFlushCount == 256) {
					set_led_power_stat(0);
					set_null_msg(0);
				} else if (railcomFlushCount == 512) {
					set_led_power_stat(1);
					railcomFlushCount = 0;
				} else if (railcomFlushCount > 512) {
					railcomFlushCount = 0;
				}
			}
			
			
		}
		
		
		while (UART0recvSize()) {
			RailcomByteReceive(UART0GetData());
			noRailcomCounter = 0;
		}
		
		if (trainAddrRecvStat()) {
			trainAddr = getTrainAddr();
			set_led_power_stat(0);
			
			if (trainAddr != 0) {
				set_7seg_data(trainAddr);
			}
			
			swMove = scanAddrStorage(trainAddr);
			if (swMove > 0) {
				if (swMove & TRAINSTORAGE_REGISTERED) {
					PORTF.OUTSET = 0x02; 
				} else {
					PORTF.OUTCLR = 0x02;
				}
				setTurnout(swMove & 0x03);
			} else {
				PORTF.OUTCLR = 0x02;
			}
			
		}
		
		if (pushButtonEvent(BUTTON_ID_SET_C)) {
			//PORTC.OUTTGL = 0x04;
			if (getButtonStat(BUTTON_ID_SET_C)) {
				trainAddr = getTrainAddr();
				swMove = setAddrStorage(trainAddr, 1);
				if (swMove == TRAINSTORAGE_WRITE_SUCCESS) {
					setTurnout(TURNOUT_CLOSE);
					//if (trainAddr > 0) {
						PORTF.OUTSET = 0x02;
					//}
				}
			}
		}
		
		if (pushButtonEvent(BUTTON_ID_SET_T)) {
			//PORTC.OUTTGL = 0x08;
			if (getButtonStat(BUTTON_ID_SET_T)) {
				trainAddr = getTrainAddr();
				swMove = setAddrStorage(getTrainAddr(), 2);
				if (swMove == TRAINSTORAGE_WRITE_SUCCESS) {
					setTurnout(TURNOUT_THROWN);
					//if (trainAddr > 0) {
						PORTF.OUTSET = 0x02;
					//}
				}
			}
		}
		
		if (pushButtonEvent(BUTTON_ID_CLR)) {
			//PORTF.OUTTGL = 0x02;
			if (getButtonStat(BUTTON_ID_CLR)) {
				PORTF.OUTCLR = 0x02;
				if (clearAddrStorage(getTrainAddr())) {
					//swMove = scanAddrStorage(0);
					//if (swMove > 0) {
					//	setTurnout(swMove & 0x03);
					//}
				}
			}
		}
		
		
		
		
		//delay_ms(200);
		//PORTC.OUTTGL |= 0x0C;
    }
}

