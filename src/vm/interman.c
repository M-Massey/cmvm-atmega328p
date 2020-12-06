/* interman.c -- Interrupt Management Interface for Dos16 - Small Model (with Digital Mars C/C++)
//
// Copyright (C) 1985-2019 by Michel de Champlain
//
*/

#include "interman.h"
#include <avr/io.h>
#include <avr/interrupt.h>

typedef void (__interrupt __far *Handler)();

public void  Interrupt_Disable(void) { 
    _CLI();
    };
public void  Interrupt_Enable(void)  {
     sei();
     };

public u16   Interrupt_SaveAndDisable(void) { 
    u16 flags =  SREG;
    Interrupt_Disable();
    return flags;
};

public void  Interrupt_Restore(u16 flags) { __restore();
    SREG = flags;
    Interrupt_Enable();
};

// public void  Interrupt_SetVector(u8 number, u32 handlerAddr) {
//     _dos_setvect(number, (Handler)handlerAddr);
// }

// public u32   Interrupt_GetVector(u8 number) {
//     return (u32)_dos_getvect(number);
// }
