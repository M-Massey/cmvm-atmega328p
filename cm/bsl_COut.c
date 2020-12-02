/* bsl_COut.c - Implementation of a Console for Cm Hardware Abstract Layer for Output Interface. - was _cout.c
//              Everything is private (static). Need to activate DebugXtoa to test all xtoa functions.
//
// Copyright (C) 1999-2020 by Michel de Champlain
//
*/

#include "_outdesc.h"
#include "_xtoa.h"

#include <avr/io.h>
#include <avr/interrupt.h>
#define FOSC  16000000 // Clock Speed
#define BAUD 57600
#define MYUBRR FOSC/16/BAUD-1

void USART_Init(unsigned int ubrr){
  /*Set baud rate */
  UBRR0H = (unsigned char)(ubrr>>8);
  UBRR0L = (unsigned char)ubrr;
 /* Enable receiver and transmitter */
  UCSR0B = (1<<RXEN0) | (1<<TXEN0);
  /* Set frame format: 8data, 2stop bit */
  UCSR0C = (1<<USBS0)|(3<<UCSZ00);
}

void USART_Transmit(unsigned char data)
{
  /* Wait for empty transmit buffer */
  while (!(UCSR0A & (1<<UDRE0)));
  /* Put data into buffer, sends the data */
  UDR0 = data;
}
// Transmit a character to UART.
static void TxChar(char c) {
       USART_Transmit(c);

}

void USART_Flush(void){
  unsigned char dummy;
  while (UCSR0A & (1<<RXC0))
  dummy = UDR0;
}

// From '_console.c'
static void Console_Putchar(char c) { TxChar(c); }

static char buf[12];    // Buffer reserved for conversion to ascii characters.
                        // Need to cover max size (12) on a "i32" (sign + 10 chars + null)

static void COut_Init(void) {
  USART_Init(MYUBRR);
}

static void COut_PutB(bool b)        { Console_Putchar(b ? 'T' : 'F'); }
static void COut_PutC(char c)        { Console_Putchar(c); }
static void COut_PutS(const char* s) { while (*s) Console_Putchar(*s++); }
static void COut_PutI(i32  i)        {_itoa(i, buf); COut_PutS(buf); }
static void COut_PutU(u32  u)        {_utoa(u, buf, 0, 10); COut_PutS(buf); }
static void COut_PutX(u32  x)        {_utoa(x, buf, 0, 16); COut_PutS(buf); } // Same behavior as Dos16 VM:
                                                                                     // Hex alpha in upppercase
static void COut_PutN(void)          { Console_Putchar('\n'); }

static IVMOutDesc cout = {
    COut_PutB,
    COut_PutC,
    COut_PutI,
    COut_PutU,
    COut_PutS,
    COut_PutX,
    COut_PutN
};

static bool init = 0;

IOut Out_GetFactory(const char* whichOne) {
    if (!init) {      // To make sure it will be done only once.
        whichOne = 0; // To avoid the warning on the unreferenced formal parameter.
        COut_Init();
        init = true;
    }
    return &cout;
}

//---------------------------------[ Example of a private unit testing ]--------------

#ifdef DebugXtoa

#include <util/delay.h>

#define MS_DELAY 1000

static void TestCout(void) {
    COut_PutS("Test xtoa\r\n");
    COut_PutS("123456789ABCDEF\r\n");

    _itoa(1234, buf);            COut_PutS(buf);
    _utoa(56789, buf, 0, 10);    COut_PutS(buf);
    _utoa(0xABCDEF, buf, 0, 16); COut_PutS(buf);
    COut_PutN();
}

int main (void) {
    COut_Init();        // Testing a direct call to init (as a first test).
    Out_GetFactory("");   // Testing the factory that hides everything and does a lazy init.

    // Set onboard LED for output. Just to see a blinking feedback from the Nano board.
    DDRB |= (1 << PB5);

    while(1) {
        TestCout();

        PORTB |= _BV(PORTB5);  // Turn the LED on.
        _delay_ms(MS_DELAY);
        PORTB &= ~_BV(PORTB5); // Turn the LED on.
        _delay_ms(MS_DELAY);
         USART_Flush();
    }
}
#endif
