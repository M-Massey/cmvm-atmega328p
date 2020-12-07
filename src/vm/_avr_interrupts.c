/* interman.c -- Interrupt Management Interface for Dos16 - Small Model (with Digital Mars C/C++)
//
// Copyright (C) 1985-2019 by Michel de Champlain
//
*/

#include "_avr_interrupts.h"

#include <avr/io.h>
#include <avr/interrupt.h>

void  __cli(void) { cli(); }
void  __sei(void)  { sei(); }

u16   __saveAndDisable(void) { 
    u16 flags =  SREG;
    __cli();
    return flags;
}

void  __restore(u16 flags) {
    SREG = flags;
}

// Not yet implemented

void  __setVector(u8 number, u32 handlerAddr) {
    // meh..
}

u32   __getVector(u8 number) {
    return 0; //meh..
}
