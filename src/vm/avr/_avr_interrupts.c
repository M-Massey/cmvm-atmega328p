/* interman.c -- Interrupt Management Interface for Dos16 - Small Model (with Digital Mars C/C++)
//
// Copyright (C) 1985-2019 by Michel de Champlain
//
*/

#include "_avr_interrupts.h"
#include <avr/io.h>
#include <avr/interrupt.h>

typedef void (__interrupt __far *Handler)();

public void  __cli(void) { cli(); }
public void  __sei(void)  { sei(); }

public u16   __saveAndDisable(void) { 
    u16 flags =  SREG;
    __cli();
    return flags;
};

public void  __restore(u16 flags) {
    SREG = flags;
    __sei();
};

// Not yet implemented

// public void  __setVector(u8 number, u32 handlerAddr) {
//     _dos_setvect(number, (Handler)handlerAddr);
// }

// public u32   __getVector(u8 number) {
//     return (u32)_dos_getvect(number);
// }
