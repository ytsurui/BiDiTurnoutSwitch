/*
 * usart_serial.c
 *
 * Created: 2022/01/18 19:43:10
 *  Author: Y.Tsurui
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdio.h>

#define serial_rx_bufsize 20
#define serial_tx_bufsize 50

typedef struct
{
	char rxbuf[serial_rx_bufsize];
	char txbuf[serial_tx_bufsize];
	uint8_t buf_in;
	uint8_t buf_size;
	uint8_t tx_buf_in;
	uint8_t tx_buf_size;
} SerialBuf_t;

#define USART1_BAUD_RATE(BAUD_RATE) ((float)(20000000 * 64 / (16 * (float)BAUD_RATE)) + 0.5)

volatile SerialBuf_t serialBuf;

void usart_serial_putchar(unsigned char data);

ISR(USART1_RXC_vect)
{
	uint8_t recvData;
	
	USART0.STATUS |= USART_RXCIF_bm;
	USART0.RXDATAH |= USART_RXCIF_bm;
	recvData = USART0.RXDATAL;
	
	if (serialBuf.buf_size >= serial_rx_bufsize) {
		serialBuf.buf_size = 0;
		return;
	}
	serialBuf.rxbuf[serialBuf.buf_in++] = recvData;
	if (serialBuf.buf_in >= serial_rx_bufsize) serialBuf.buf_in = 0;
	serialBuf.buf_size++;
}

void initUART1(void) {
	PORTC.DIRSET &= ~PIN1_bm;	// Input PC1
	
	USART1.BAUD = (uint16_t)USART1_BAUD_RATE(115200);
	
	USART1.CTRLB = 0 << USART_MPCM_bp       // Multi-processor Communication Mode: disabled
	| 0 << USART_ODME_bp				// Open Drain Mode Enable: disabled
	| 1 << USART_RXEN_bp				// Receiver Enable: enabled
	| USART_RXMODE_NORMAL_gc			// Normal mode
	| 0 << USART_SFDEN_bp				// Start Frame Detection Enable: disabled
	| 1 << USART_TXEN_bp;				// Transmitter Enable: disabled
	
	USART1.CTRLA |= USART_RXCIE_bm;
	
	USART1.CTRLC = USART_CHSIZE_8BIT_gc;
	
	fdevopen(usart_serial_putchar, NULL);
}

uint8_t UART1recvSize(void) {
	return serialBuf.buf_size;
}

uint8_t UART1GetData(void) {
	uint8_t data;
	uint8_t pos;
	
	while (!serialBuf.buf_size);
	
	cli();
	pos = serialBuf.buf_in - serialBuf.buf_size;
	if (serialBuf.buf_in < serialBuf.buf_size) {
		pos += serial_rx_bufsize;
	}
	data = serialBuf.rxbuf[pos];
	if (serialBuf.buf_size == 0) {
		serialBuf.buf_size += serial_rx_bufsize;
	}
	serialBuf.buf_size--;
	sei();
	return data;
}


void usart_serial_putchar(unsigned char data)
{
	
}

void calcUniqueAddress(void) {
	uint8_t data1, data2, data3, data4;
	
	data1 = SIGROW.SERNUM0 ^ SIGROW.SERNUM4 ^ SIGROW.SERNUM8;
	data2 = SIGROW.SERNUM1 ^ SIGROW.SERNUM5 ^ SIGROW.SERNUM9;
	data3 = SIGROW.SERNUM2 ^ SIGROW.SERNUM6;
	data4 = SIGROW.SERNUM3 ^ SIGROW.SERNUM7;
}