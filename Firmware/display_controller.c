/*
 * display_controller.c
 *
 * Created: 2021/12/31 0:49:56
 *  Author: Y.Tsurui
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/pgmspace.h>

#include "display_controller.h"

#define LED_A 0x01
#define LED_B 0x02
#define LED_C 0x04
#define LED_D 0x08
#define LED_E 0x10
#define LED_F 0x20
#define LED_G 0x40

uint8_t data_cache[4];
uint8_t select_flag = 0;

uint8_t power_flag = 0;

uint8_t appTimerFlag = 0;

//7-seg LED Port Assign
/*
A: PD0
B: PD1
C: PD2
D: PD3
E: PD4
F: PD5
G: PD6

CA1: PA4
CA2: PA5
CA3: PA6
CA4: PA7
*/

void set_port(uint8_t dec);

/*
ISR(TIMER1_COMPA_vect)
{
	appTimerFlag = 1;
	
	PORTD &= 0b11000011;
	
	if (power_flag) {
		PORTB &= 0x80;
		return;
	} else {
		set_port(data_cache[select_flag]);
		select_flag++;
	}	
	
	if (select_flag == 1) {
		PORTD |= 0b00000100;
	} else if (select_flag == 2) {
		PORTD |= 0b00010000;
	} else if (select_flag == 3) {
		PORTD |= 0b00100000;
	} else {
		PORTD |= 0b00001000;
		select_flag = 0;
	}
}

void set_7seg_timer(void)
{
	TCCR1A = 0b00000000;
	TCCR1B = 0b00001011;
	OCR1A = 128;
	OCR1B = OCR1A / 2;
	
	TIMSK |= 0b01000000;
	
	sei();
}
*/

void initDisplay(void) {
	PORTA.DIR |= 0xF0;
	PORTD.DIR |= 0x7F;
}

void displayClock(void) {
	PORTA.OUTCLR = 0xF0;
	
	if (power_flag) {
		PORTD.OUTCLR = 0x7F;
		return;
	} else {
		set_port(data_cache[select_flag]);
		select_flag++;
	}
	
	if (select_flag == 1) {
		PORTA.OUTSET = 0x80;
	} else if (select_flag == 2) {
		PORTA.OUTSET = 0x40;
	} else if (select_flag == 3) {
		PORTA.OUTSET = 0x20;
	} else {
		PORTA.OUTSET = 0x10;
		select_flag = 0;
	}
	
}

const PROGMEM uint8_t led7segDataTable[17] = {
	~(LED_A | LED_B | LED_C | LED_D | LED_E | LED_F),			// 0
	~(LED_B | LED_C),											// 1
	~(LED_A | LED_B | LED_D | LED_E | LED_G),					// 2
	~(LED_A | LED_B | LED_C | LED_D | LED_G),					// 3
	~(LED_B | LED_C | LED_F | LED_G),							// 4
	~(LED_A | LED_C | LED_D | LED_F | LED_G),					// 5
	~(LED_A | LED_C | LED_D | LED_E | LED_F | LED_G),			// 6
	~(LED_A | LED_B | LED_C),									// 7
	~(LED_A | LED_B | LED_C | LED_D | LED_E | LED_F | LED_G),	// 8
	~(LED_A | LED_B | LED_C | LED_D | LED_F | LED_G),			// 9
	~(LED_A | LED_B | LED_E | LED_F | LED_G),					// P
	~(LED_E | LED_G),											// r
	~(LED_C | LED_D | LED_E | LED_G),							// o
	~(LED_A | LED_B | LED_C | LED_D | LED_F | LED_G),			// g
	~(LED_G),													// -
	~(LED_G | LED_D | LED_E),									// C
	~(LED_E | LED_F | LED_D)									// L
};


void set_port(uint8_t dec)
{
	uint8_t readCache;
		
	//PORTB |= 0b01111111;
	PORTD.OUTSET = 0x7F;
	
	if (dec == 0xFF) {
		return;
	}
	
	if (dec > 0x80) {
		dec -= 119;
		readCache = pgm_read_byte(&led7segDataTable[dec]);
		//PORTB &= readCache;
		PORTD.OUT &= readCache;
	}
	
	if (dec < 10) {
		readCache = pgm_read_byte(&led7segDataTable[dec]);
		//PORTB &= readCache;
		PORTD.OUT &= readCache;
	}
	
	/*
	if (dec == 0) {
		//A-B-C-D-E-F
		PORTB &= ~(LED_A | LED_B | LED_C | LED_D | LED_E | LED_F);
	} else if (dec == 1) {	
		//B-C
		PORTB &= ~(LED_B | LED_C);
	} else if (dec == 2) {	
		//A-B-D-E-G
		PORTB &= ~(LED_A | LED_B | LED_D | LED_E | LED_G);
	} else if (dec == 3) {	
		//A-B-C-D-G
		PORTB &= ~(LED_A | LED_B | LED_C | LED_D | LED_G);
	} else if (dec == 4) {	
		//B-C-F-G
		PORTB &= ~(LED_B | LED_C | LED_F | LED_G);
	} else if (dec == 5) {	
		//A-C-D-F-G
		PORTB &= ~(LED_A | LED_C | LED_D | LED_F | LED_G);
	} else if (dec == 6) {	
		//A-C-D-E-F-G
		PORTB &= ~(LED_A | LED_C | LED_D | LED_E | LED_F | LED_G);
	} else if (dec == 7) {	
		//A-B-C
		PORTB &= ~(LED_A | LED_B | LED_C);
	} else if (dec == 8) {	
		//A-B-C-D-E-F-G
		PORTB &= ~(LED_A | LED_B | LED_C | LED_D | LED_E | LED_F | LED_G);
	} else if (dec == 9) {	
		//A-B-C-D-F-G
		PORTB &= ~(LED_A | LED_B | LED_C | LED_D | LED_F | LED_G);
	} else if (dec == 0x81) {
		//P (A-B-E-F-G)
		PORTB &= ~(LED_A | LED_B | LED_E | LED_F | LED_G);
	} else if (dec == 0x82) {
		//R (A-E-F)
		PORTB &= ~(LED_A | LED_E | LED_F);
	} else if (dec == 0x83) {
		//O (A-B-C-D-E-F)
		PORTB &= ~(LED_A| LED_B | LED_C | LED_D | LED_E | LED_F);
	} else if (dec == 0x84) {
		//G (A-B-C-D-F-G)
		PORTB &= ~(LED_A | LED_B | LED_C | LED_D | LED_F | LED_G);
	}
	*/
	
}

void set_7seg_data(uint16_t data)
{
	uint8_t i;
	
	for (i = 0; i < 4; i++) {
		if ((data == 0) && (i != 0)) {
			data_cache[i] = 0xFF;
		} else {
			data_cache[i] = data % 10;
			data = data / 10;
		}
	}
}

void set_led_power_stat(uint8_t stat)
{
	power_flag = stat;
}

void set_prog_mode(void)
{
	data_cache[0] = 0x84;
	data_cache[1] = 0x83;
	data_cache[2] = 0x82;
	data_cache[3] = 0x81;
}

void set_clr_msg(void)
{
	data_cache[0] = 0x82;
	data_cache[1] = 0x87;
	data_cache[2] = 0x86;
	data_cache[3] = 0xFF;
}

void set_null_msg(uint8_t pos) {
	uint8_t i;
	
	for (i = 0; i < 4; i++) {
		if (i == pos) {
			data_cache[i] = 0x85;
		} else {
			data_cache[i] = 0xFF;
		}
	}
}

uint8_t appTimer(void) {
	if (appTimerFlag) {
		appTimerFlag = 0;
		return (1);
	}
	return (0);
}