/*
 * pushButton.c
 *
 * Created: 2021/12/31 14:48:37
 *  Author: Y.Tsurui
 */ 

#include <avr/io.h>
#define BUTTON_COUNT_THRESHOLD 10
#define BUTTON_COUNT_MAX 20

uint8_t btnCount[4];

uint8_t buttonLastStat;
uint8_t buttonChangeFlag;


void buttonClock() {
	uint8_t i;
	uint8_t buttonStat;
	uint8_t buttonMask;
	
	buttonStat = (PORTF.IN & 0x3C) >> 2;
	buttonMask = 0x01;
	
	for (i = 0; i < 4; i++) {
		if (buttonStat & buttonMask) {
			if (btnCount[i] > 0) {
				btnCount[i]--;
			}
		} else {
			if (btnCount[i] < BUTTON_COUNT_MAX) {
				btnCount[i]++;
			}
		}
		
		if (btnCount[i] > BUTTON_COUNT_THRESHOLD) {
			if (~buttonLastStat & buttonMask) {
				buttonLastStat |= buttonMask;
				buttonChangeFlag |= buttonMask;
			}
		} else {
			if (buttonLastStat & buttonMask) {
				buttonLastStat &= ~buttonMask;
				buttonChangeFlag |= buttonMask;
			}
		}
		
		buttonMask = buttonMask << 1;
	}
}

void initButton(void) {
	PORTF.DIRCLR = 0x3C;	//(PF2 / PF3 / PF4 / PF5)
	PORTF.PIN2CTRL = PORT_PULLUPEN_bm;	// C
	PORTF.PIN3CTRL = PORT_PULLUPEN_bm;	// T
	PORTF.PIN4CTRL = PORT_PULLUPEN_bm;	// CLR
	PORTF.PIN5CTRL = PORT_PULLUPEN_bm;	// PROG
}

uint8_t getButtonStat(uint8_t buttonId) {
	if (btnCount[buttonId] > BUTTON_COUNT_THRESHOLD) {
		return (1);	
	}
	return (0);
}

uint8_t pushButtonEvent(uint8_t buttonId) {
	uint8_t buttonMask;
	
	buttonMask = 0x01 << buttonId;
	
	if (buttonChangeFlag & buttonMask) {
		buttonChangeFlag &= ~buttonMask;
		return (1);
	}
	return (0);
}