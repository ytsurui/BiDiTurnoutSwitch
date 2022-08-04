/*
 * railcom_recv.h
 *
 * Created: 2020/12/29 0:54:23
 *  Author: ytsurui
 */ 


void RailcomByteReceive(uint8_t data);
void timeoutCountup(void);
uint8_t addrViewTimeout(void);

uint8_t trainAddrRecvStat(void);
uint16_t getTrainAddr(void);
