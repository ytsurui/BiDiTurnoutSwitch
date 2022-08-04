/*
 * trainaddrStorage.c
 *
 * Created: 2021/12/31 16:11:24
 *  Author: Y.Tsurui
 */ 

#include <avr/io.h>
#include <avr/eeprom.h>

#include "trainaddrStorage.h"

#define ADDR_STORAGE_MAX 100

uint16_t __attribute__((section(".eeprom"))) addrStorageMem[ADDR_STORAGE_MAX + 1];
uint16_t addrStorage[ADDR_STORAGE_MAX];
uint8_t addrStorageUse[ADDR_STORAGE_MAX / 8];
uint8_t addrStorageStat[ADDR_STORAGE_MAX / 8];

uint8_t defaultStat;



uint16_t readMemAddr(uint8_t addr) {
	if (addr > ADDR_STORAGE_MAX) return (0);
	
	eeprom_busy_wait();
	return (eeprom_read_word(addrStorageMem + addr));
}

void writeMemAddr(uint8_t addr, uint16_t data) {
	eeprom_busy_wait();
	eeprom_update_word(addrStorageMem + addr, data);
}

uint8_t calcFlagIndex(uint8_t addr) {
	return (addr >> 3);
}

uint8_t calcFlagMask(uint8_t addr) {
	return (0x01 << (addr & 0x07));
}

void initTrainAddrStorage(void) {
	uint16_t readStat;
	uint8_t i;
	uint8_t flagIndex, flagMask;
	
	readStat = readMemAddr(ADDR_STORAGE_MAX);
	if (readStat == 0xFFFF) {
		// Initialize
		for (i = 0; i < ADDR_STORAGE_MAX + 1; i++) {
			writeMemAddr(i, 0);
		}
	}
	
	for (i = 0; i < ADDR_STORAGE_MAX; i++) {
		readStat = readMemAddr(i);
		addrStorage[i] = readStat & 0x3FFF;
		flagIndex = calcFlagIndex(i);
		flagMask = calcFlagMask(i);
		if (addrStorage[i] > 0) {
			addrStorageUse[flagIndex] |= flagMask;
			
			if (readStat & 0x8000) {
				addrStorageStat[flagIndex] |= flagMask;
			} else {
				addrStorageStat[flagIndex] &= ~flagMask;
			}
		} else {
			addrStorageUse[flagMask] &= ~flagMask;
		}
	}
	
	readStat = readMemAddr(ADDR_STORAGE_MAX);
	defaultStat = (uint8_t)((readStat & 0xFF00) >> 8);
	
}

// アドレスストレージをスキャンし、切り替える方向を返す
//
//		return:
//			0: No Operation
//			1: Closed
//			2: Thrown
//
uint8_t scanAddrStorage(uint16_t trainAddr) {
	uint8_t i;
	uint8_t flagIndex, flagMask;
	
	if (trainAddr > 0) {
		for (i = 0; i < ADDR_STORAGE_MAX; i++) {
			if (trainAddr == addrStorage[i]) {
				flagIndex = calcFlagIndex(i);
				flagMask = calcFlagMask(i);
			
				if (addrStorageUse[flagIndex] & flagMask) {
					if (addrStorageStat[flagIndex] & flagMask) {
						//return (2);	// Thrown
						return (TRAINSTORAGE_REGISTERED | TRAINSTORAGE_SWITCH_THROWN);
					} else {
						//return (1);	// Closed
						return (TRAINSTORAGE_REGISTERED | TRAINSTORAGE_SWITCH_CLOSED);
					}
				}
			
			}
		}
	}
	
	if (defaultStat & 0x40) {
		// Use Default
		if (trainAddr > 0) {
			if (defaultStat & 0x80) {
				return (TRAINSTORAGE_SWITCH_THROWN);
				} else {
				return (TRAINSTORAGE_SWITCH_CLOSED);
			}
		} else {
			if (defaultStat & 0x80) {
				return (TRAINSTORAGE_REGISTERED | TRAINSTORAGE_SWITCH_THROWN);
			} else {
				return (TRAINSTORAGE_REGISTERED | TRAINSTORAGE_SWITCH_CLOSED);
			}
		}
	}
	
	
	return (0);
}

uint8_t clearAddrStorage(uint16_t trainAddr) {
	uint8_t i;
	uint8_t flagIndex, flagMask;
	uint8_t deleteFlag = 0;
	
	if (trainAddr > 0) {
		for (i = 0; i < ADDR_STORAGE_MAX; i++) {
			if (trainAddr == addrStorage[i]) {
				deleteFlag = 1;
				flagIndex = calcFlagIndex(i);
				flagMask = calcFlagMask(i);
				
				writeMemAddr(i, 0);
				addrStorage[i] = 0;
				addrStorageUse[flagIndex] &= ~flagMask;
				addrStorageStat[flagIndex] &= ~flagMask;
			}
		}
		return (deleteFlag);
	}
	
	if (defaultStat == 0) return (0);
	defaultStat = 0;
	writeMemAddr(ADDR_STORAGE_MAX, 0);
	return (1);
}

void clearAddrStorageRaw(void) {
	uint8_t i;
	uint8_t flagIndex, flagMask;
	
	for (i = 0; i < ADDR_STORAGE_MAX; i++) {
		flagIndex = calcFlagIndex(i);
		flagMask = calcFlagMask(i);
		
		writeMemAddr(i, 0);
		addrStorage[i] = 0;
		addrStorageUse[flagIndex] &= ~flagMask;
		addrStorageStat[flagIndex] &= ~flagMask;
	}
	
	defaultStat = 0;
	writeMemAddr(ADDR_STORAGE_MAX, 0);
}

uint8_t setAddrStorage(uint16_t trainAddr, uint8_t swDirection) {
	uint8_t i;
	uint8_t writeAddrPos, flagIndex, flagMask;
	
	if (trainAddr > 0) {
		writeAddrPos = 0xFF;
		for (i = 0; i < ADDR_STORAGE_MAX; i++) {
			if (trainAddr == addrStorage[i]) {
				writeAddrPos = i;
				break;
			}
		}
		
		if (writeAddrPos == 0xFF) {
			for (i = 0; i < ADDR_STORAGE_MAX; i++) {
				if (addrStorage[i] == 0) {
					writeAddrPos = i;
					break;
				}
			}
		}
		
		if (writeAddrPos < 0xFF) {
			flagIndex = calcFlagIndex(writeAddrPos);
			flagMask = calcFlagMask(writeAddrPos);
			
			if (swDirection == 2) {
				if (addrStorageStat[flagIndex] & flagMask) {
					if (addrStorage[writeAddrPos] == trainAddr) return (0);
				}
				addrStorage[writeAddrPos] = trainAddr;
				trainAddr |= 0x8000;
				addrStorageStat[flagIndex] |= flagMask;
			} else {
				if (~addrStorageStat[flagIndex] & flagMask) {
					if (addrStorage[writeAddrPos] == trainAddr) return (0);
				}
				addrStorage[writeAddrPos] = trainAddr;
				addrStorageStat[flagIndex] &= ~flagMask;
			}
			addrStorageUse[flagIndex] |= flagMask;
			
			writeMemAddr(writeAddrPos, trainAddr);
			
			return (1);
		}
		
		return (0xFF);
	}
	
	if (swDirection == 2) {
		if (defaultStat == 0xC0) return (0);
		trainAddr = 0xC000;
		defaultStat = 0xC0;
	} else {
		if (defaultStat == 0x40) return (0);
		trainAddr = 0x4000;
		defaultStat = 0x40;
	}
	writeMemAddr(ADDR_STORAGE_MAX, trainAddr);
	return (1);
}