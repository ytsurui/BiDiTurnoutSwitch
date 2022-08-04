/*
 * lock_sensor.c
 *
 * Created: 2022/02/12 17:45:32
 *  Author: Y.Tsurui
 */ 

#include <avr/io.h>

uint8_t lockSensorStatusFlag;
uint8_t lockSensorCount;
#define LOCKSENSOR_COUNT_MAX 3


void initLockSensor(void) {
	// PD7 Input & Pullup
	PORTD.DIRCLR = 0x80;
	PORTD.PIN7CTRL = PORT_PULLUPEN_bm;
	lockSensorStatusFlag = 0;
	lockSensorCount = 0;
}

void lockSensorClock(void) {
	uint8_t sensorStat;
	
	sensorStat = (~PORTD.IN & 0x80);
	
	if (sensorStat) {
		if (lockSensorCount < LOCKSENSOR_COUNT_MAX) lockSensorCount++;
		if (lockSensorCount == LOCKSENSOR_COUNT_MAX) lockSensorStatusFlag = 1;
	} else {
		if (lockSensorCount > 0) lockSensorCount--;
		if (lockSensorCount == 0) lockSensorStatusFlag = 0;
	}
}

uint8_t lockSensorStat(void) {
	if (lockSensorStatusFlag) {
		return (1);
	}
	return (0);
}