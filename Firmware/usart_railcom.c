/*
 * usart_railcom.c
 *
 * Created: 2021/12/31 0:29:32
 *  Author: Y.Tsurui
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#include "railcom_recv.h"

#define rx_bufsize (20)

typedef struct
{
	char buf[rx_bufsize];
	uint8_t buf_in;
	uint8_t buf_size;
} RxBuf_t;

#define USART0_BAUD_RATE(BAUD_RATE) ((float)(20000000 * 64 / (16 * (float)BAUD_RATE)) + 0.5)

volatile RxBuf_t RxBuf;

ISR(USART0_RXC_vect)
{
	uint8_t recvData;
	
	USART0.STATUS |= USART_RXCIF_bm;
	USART0.RXDATAH |= USART_RXCIF_bm;
	recvData = USART0.RXDATAL;
	
	if (RxBuf.buf_size >= rx_bufsize) {
		RxBuf.buf_size = 0;
		return;
	}
	RxBuf.buf[RxBuf.buf_in++] = recvData;
	if (RxBuf.buf_in >= rx_bufsize) RxBuf.buf_in = 0;
	RxBuf.buf_size++;
}

void initUART0(void) {
	PORTA.DIRSET &= ~0x02;	// Input PA1
	PORTA.PIN1CTRL = PORT_INVEN_bm;
	
	USART0.BAUD = (uint16_t)USART0_BAUD_RATE(250000);
	
	USART0.CTRLB = 0 << USART_MPCM_bp       // Multi-processor Communication Mode: disabled
	| 0 << USART_ODME_bp				// Open Drain Mode Enable: disabled
	| 1 << USART_RXEN_bp				// Receiver Enable: enabled
	| USART_RXMODE_NORMAL_gc			// Normal mode
	| 0 << USART_SFDEN_bp				// Start Frame Detection Enable: disabled
	| 0 << USART_TXEN_bp;				// Transmitter Enable: disabled
	
	USART0.CTRLA |= USART_RXCIE_bm;
	
	USART0.CTRLC = USART_CHSIZE_8BIT_gc;
}

void enableUART0()
{
	USART0.CTRLB = 0 << USART_MPCM_bp       // Multi-processor Communication Mode: disabled
	| 0 << USART_ODME_bp				// Open Drain Mode Enable: disabled
	| 1 << USART_RXEN_bp				// Receiver Enable: enabled
	| USART_RXMODE_NORMAL_gc			// Normal mode
	| 0 << USART_SFDEN_bp				// Start Frame Detection Enable: disabled
	| 0 << USART_TXEN_bp;				// Transmitter Enable: disabled
}

/*
void disableUART0()
{
	USART0.CTRLB = 0 << USART_MPCM_bp       // Multi-processor Communication Mode: disabled
	| 0 << USART_ODME_bp				// Open Drain Mode Enable: disabled
	| 1 << USART_RXEN_bp				// Receiver Enable: enabled
	| USART_RXMODE_NORMAL_gc			// Normal mode
	| 0 << USART_SFDEN_bp				// Start Frame Detection Enable: disabled
	| 0 << USART_TXEN_bp;				// Transmitter Enable: disabled
	
	PORTB.OUTSET |= PIN2_bm;
}
*/

uint8_t UART0recvSize(void) {
	return RxBuf.buf_size;
}

uint8_t UART0GetData(void) {
	uint8_t data;
	uint8_t pos;
	
	while (!RxBuf.buf_size);
	
	cli();
	pos = RxBuf.buf_in - RxBuf.buf_size;
	if (RxBuf.buf_in < RxBuf.buf_size) {
		pos += rx_bufsize;
	}
	data = RxBuf.buf[pos];
	if (RxBuf.buf_size == 0) {
		RxBuf.buf_size += rx_bufsize;
	}
	RxBuf.buf_size--;
	sei();
	return data;
}