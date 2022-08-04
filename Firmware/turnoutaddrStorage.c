/*
 * turnoutaddrStorage.c
 *
 * Created: 2022/06/05 13:56:26
 *  Author: ytsurui
 */ 

#include <avr/io.h>
#include <avr/eeprom.h>

#include "turnoutaddrStorage.h"

uint16_t __attribute__((section(".eeprom"))) turnoutAddrMem;
uint16_t turnoutAddrCache;



void initTurnoutAddrStorage(void) {
	eeprom_busy_wait();
	turnoutAddrCache = eeprom_read_word(&turnoutAddrMem);
	
	//if (turnoutAddrCache > 2048) {
	//	turnoutAddrCache = 0xFFFF;
	//}
}

uint16_t getTurnoutAddr(void)
{
	
	return (turnoutAddrCache);
}

void writeTurnoutAddr(uint16_t newAddr)
{
	eeprom_busy_wait();
	eeprom_update_word(&turnoutAddrMem, newAddr);
}