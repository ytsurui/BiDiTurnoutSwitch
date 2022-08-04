/*
 * trainaddrStorage.h
 *
 * Created: 2021/12/31 16:11:50
 *  Author: Y.Tsurui
 */ 

void initTrainAddrStorage(void);

uint8_t scanAddrStorage(uint16_t trainAddr);
uint8_t clearAddrStorage(uint16_t trainAddr);
void clearAddrStorageRaw(void);
uint8_t setAddrStorage(uint16_t trainAddr, uint8_t swDirection);

#define TRAINSTORAGE_WRITE_FAILURE	0
#define TRAINSTORAGE_WRITE_SUCCESS	1
#define TRAINSTORAGE_ADDR_FULL		0xFF

#define TRAINSTORAGE_SWITCH_CLOSED	1
#define TRAINSTORAGE_SWITCH_THROWN	2
#define TRAINSTORAGE_SWITCH_RANDOM	3

#define TRAINSTORAGE_REGISTERED		0x40