/*
 * usart_railcom.h
 *
 * Created: 2021/12/31 0:43:29
 *  Author: ytsurui
 */ 

void initUART0(void);
void enableUART0();
void disableUART0();

uint8_t UART0recvSize(void);
uint8_t UART0GetData(void);