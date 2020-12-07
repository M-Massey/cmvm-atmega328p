#ifndef ___avr_uart_h
#define ___avr_uart_h

#include "_avr_stdtype.h"

void USART_Init(unsigned int ubrr);
void USART_Transmit(unsigned char data);
void USART_Flush(void);
u8 USART_Receive(void);

#endif