/*
 * dcc_input.c
 *
 * Created: 2022/01/02 23:47:57
 *  Author: Y.Tsurui
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>

uint16_t dccTimerCounterStart = 0;
uint16_t dccTimerCounter = 0;

uint8_t _preambleCount = 0;
uint8_t _dccPulseReceiveBit;

uint8_t _dccPulseBitCount;
uint8_t _dccPacketCount;
uint8_t _dccPacketError;

#define DCC_PACKET_LENGTH	32
uint8_t _dccPacketData[DCC_PACKET_LENGTH];

uint8_t dccRecvPacketCache[DCC_PACKET_LENGTH];
uint8_t dccRecvPacketCacheLength;
uint8_t dccRecvPacketCacheEnableFlag;


/* BaseClock = 20MHz */
#define DCC_PULSE_LENGTH_ONE_MIN	440		//44us (counter 1cycle = 100ns @ 20MHz / 2)
#define DCC_PULSE_LENGTH_ONE_MAX	900		//80us + 5us
#define DCC_PULSE_LENGTH_ZERO_MIN	1000	//90us
#define DCC_PULSE_LENGTH_ZERO_MAX	50000	//10000us

void (*switchCb)(uint16_t addr, uint8_t stat);
uint8_t switchCbAssigned;


ISR(PORTF_PORT_vect)
{
	PORTF.INTFLAGS |= PIN0_bm;
	
	if (PORTF.IN & PIN0_bm) {
		if (dccTimerCounterStart < TCB0.CNT) {
			dccTimerCounter = TCB0.CNT - dccTimerCounterStart;
		} else {
			dccTimerCounter = 0xFFFF - dccTimerCounterStart + TCB0.CNT;
		}
	} else {
		dccTimerCounterStart = TCB0.CNT;
	}
}


void initDCCinput(void)
{
	PORTF.DIRCLR = 0x01;	// Input PF0
	PORTF.PIN0CTRL = PORT_ISC_BOTHEDGES_gc;
	
	TCB0.CTRLA = TCB_CLKSEL_CLKDIV2_gc | TCB_ENABLE_bm;
	TCB0.CCMP = 0xFFFF;
	
	//switchCb = NULL;
	switchCbAssigned = 0;
}

void dccPacketShifter(uint8_t* pLength, uint8_t* packetBuf)
{
	uint16_t dccTimerTemp;
	
	if (dccTimerCounter == 0) return;
	dccTimerTemp = dccTimerCounter;
	dccTimerCounter = 0;
	
	if ((dccTimerTemp > DCC_PULSE_LENGTH_ONE_MIN) && (dccTimerTemp < DCC_PULSE_LENGTH_ONE_MAX)) {
		// bit is 1
		_dccPulseReceiveBit = 1;
		_preambleCount++;
		
		_dccPacketData[_dccPacketCount] = (_dccPacketData[_dccPacketCount] << 1) + 1;
	} else if ((dccTimerTemp > DCC_PULSE_LENGTH_ZERO_MIN) && (dccTimerTemp < DCC_PULSE_LENGTH_ZERO_MAX)) {
		// bit is 0
		_dccPulseReceiveBit = 0;
	
		if (_preambleCount >= 14) {
			// Packet Start Bit
			_dccPulseBitCount = 1;
			_dccPacketData[0] = 0;
			_dccPacketCount = 0;
			_dccPacketError = 0;
			_preambleCount = 0;
			return;
		}
	
		_preambleCount = 0;
		_dccPacketData[_dccPacketCount] = (_dccPacketData[_dccPacketCount] << 1);
	
	} else {
		return;
	}
	
	if (_dccPacketCount >= DCC_PACKET_LENGTH) {	// Ignore
		return;
	}
	
	if ((_dccPulseBitCount == 0) && (_dccPulseReceiveBit == 1)) {
		// Packet End Bit
		if (_dccPacketError == 0) {
			for ((*pLength) = 0; (*pLength) < _dccPacketCount; (*pLength)++) {
				packetBuf[(*pLength)] = _dccPacketData[(*pLength)];
			}
		} else {
			(*pLength) = 0;
		}
	} else {
		(*pLength) = 0;
	}
	
	
	_dccPulseBitCount++;
	if (_dccPulseBitCount == 9) {
		//dccTimeoutCounter = 0;
		
		// Byte End (1-8: Packet Pulse / 9 = end)
		if ((_dccPacketCount == 0) && (_dccPacketData[0] == 0xFF)) {
			// Preamble
			_dccPacketCount = 0xFF;
			return;
		}
		
		
		_dccPacketError ^= _dccPacketData[_dccPacketCount];
		_dccPacketCount++;
		_dccPacketData[_dccPacketCount] = 0;
		_dccPulseBitCount = 0;
		
	}
	
	
}


void dccPacketRouter(uint8_t packetLength, uint8_t packetData[])
{
	//uint8_t packetReadStartPos = 0;
	//uint8_t packetInstruction;
	
	uint16_t decodeAddr;
	uint16_t int_t;
	//uint8_t newStat;
	
	
	// 2-Byte Packet (None)
	if (packetLength == 2) return;
	
	if (packetLength == 3) {
		if ((packetData[0] == 0) && (packetData[1] == 0) && (packetData[2] == 0)) {
			// Reset
			//serviceModeFlag = 30;
			//resetPageFlag();
			return;
		} else if ((packetData[0] == 0xFF) && (packetData[1] == 0x00) && (packetData[2] == 0xFF)) {
			// Idle, Exit Service-Mode
			//serviceModeFlag = 0;
			return;
		} else if ((packetData[0] > 0x7F) && (packetData[0] < 0xC0) && (packetData[1] & 0x80)) {
			//Accessory Addr (packetData[0] = 10000000-10111111 (128-191)
			
			decodeAddr = 0;
			decodeAddr |= (packetData[0] & 0x3F);
			
			int_t = (~packetData[1] & 0x70) >> 4;
			decodeAddr |= (int_t << 6);
			
			decodeAddr = decodeAddr << 2;
			decodeAddr -= 1;
			
			int_t = packetData[1] & 0x06;
			decodeAddr &= ~0x03;
			decodeAddr |= (int_t >> 1);
			decodeAddr += 1; 
			
			//set_7seg_data(decodeAddr);
			
			//if (switchCb != NULL) {
			//	switchCb(decodeAddr, packetData[1] & 0x01);
			//}
			if (switchCbAssigned) {
				switchCb(decodeAddr, packetData[1] & 0x01);
			}
			
			return;
		}
	}
	
	//packetInstruction = packetData[packetReadStartPos] & 0xE0;
	
}

void setSwitchCallback(void (*method)(uint16_t, uint8_t)) {
	switchCb = method;
	switchCbAssigned = 1;
}