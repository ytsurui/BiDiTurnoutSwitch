/*
 * turnoutDriver.c
 *
 * Created: 2021/12/31 15:43:38
 *  Author: Y.Tsurui
 */

#include <avr/io.h>
#include "turnoutDriver.h"

uint8_t turnoutMoveStartFlag;
uint16_t turnoutCounter;
uint8_t turnoutMove;
uint8_t turnoutNowStat;

uint16_t turnoutLockCounter = 0;
#define TURNOUT_LOCK_MAX 3000;

uint8_t turnoutLockLEDcounter = 0;


void turnoutClock(void) {
	if (turnoutLockCounter > 0) {
		turnoutLockCounter--;
			
		
		if (turnoutLockCounter == 0) {
			if (turnoutNowStat == TURNOUT_CLOSE) {
				// LED Closed On
				PORTC.OUTSET = 0x04;
			} else if (turnoutNowStat == TURNOUT_THROWN) {
				// LED Thrown On
				PORTC.OUTSET = 0x08;
			}
			turnoutLockLEDcounter = 0;
		} else {
			turnoutLockLEDcounter++;
			if (turnoutLockLEDcounter == 0x3F) {
				if (turnoutNowStat == TURNOUT_CLOSE) {
					PORTC.OUTTGL = 0x04;
				} else if (turnoutNowStat == TURNOUT_THROWN) {
					PORTC.OUTTGL = 0x08;
				}
				turnoutLockLEDcounter = 0;
			}
		}
	}
	
	if (turnoutCounter == 0) {
		if (turnoutMoveStartFlag == 0) {
			return;
		}
		
		if (turnoutLockCounter != 0) {
			return;
		} 
		
		turnoutMove = turnoutMoveStartFlag;
		turnoutNowStat = turnoutMoveStartFlag;
		turnoutMoveStartFlag = 0;
		turnoutCounter = 1;
	}
	
	if (turnoutCounter == 1) {
		
		if (turnoutMove == TURNOUT_CLOSE) {
			PORTC.OUTSET = 0x04;
			PORTC.OUTCLR = 0x08;
		} else if (turnoutMove == TURNOUT_THROWN) {
			PORTC.OUTSET = 0x08;
			PORTC.OUTCLR = 0x04;
		} else {
			turnoutCounter = 0;
			turnoutMove = 0;
			return;
		}
	} else if (turnoutCounter < 1000) {
		if ((turnoutCounter & 0x007F) == 0x007F) {
			if (turnoutMove == TURNOUT_CLOSE) {
				PORTC.OUTTGL = 0x04;
				PORTC.OUTCLR = 0x08;
			} else if (turnoutMove == TURNOUT_THROWN) {
				PORTC.OUTTGL = 0x08;
				PORTC.OUTCLR = 0x04;
			}
		}
	} else if (turnoutCounter == 1001) {
		if (turnoutMove == TURNOUT_CLOSE) {
			PORTA.OUTSET = 0x05;
			PORTC.OUTSET = 0x04;
			PORTC.OUTCLR = 0x08;
		} else if (turnoutMove == TURNOUT_THROWN) {
			PORTA.OUTSET = 0x09;
			PORTC.OUTSET = 0x08;
			PORTC.OUTCLR = 0x04;
		} else {
			turnoutCounter = 0;
			turnoutMove = 0;
			return;
		}
		turnoutMove = 0;
	} else if (turnoutCounter == 1250) {
		PORTA.OUTCLR = 0x0D;
	} else if (turnoutCounter >= 2000) {
		if (turnoutMove > 0) {
			turnoutCounter = 1;
			return;
		}
		turnoutCounter = 0;
		return;
	}
	
	turnoutCounter++;
}

void initTurnoutDriver(void) {
	PORTA.DIRSET = 0x0D;	// output PA0,PA2,PA3
	PORTC.DIRSET = 0x0C;	// output PC2,PC3 (LED)
	turnoutCounter = 0;
}

void setTurnout(uint8_t dir) {
	//turnoutMove = dir;
	//if (turnoutCounter == 0) {
		//turnoutCounter = 1;
		//turnoutMoveStartFlag = 1;
	//}
	//turnoutMoveStartFlag = 1;
	turnoutMoveStartFlag = dir;
}

void resetTurnoutTimer(void) {
	turnoutLockCounter = TURNOUT_LOCK_MAX;
}

