/*
 * dcc_input.h
 *
 * Created: 2022/01/02 23:48:24
 *  Author: Y.Tsurui
 */ 

void initDCCinput(void);
void dccPacketShifter(uint8_t* pLength, uint8_t* packetBuf);
void dccPacketRouter(uint8_t packetLength, uint8_t packetData[]);

void setSwitchCallback(void (*method)(uint16_t, uint8_t));