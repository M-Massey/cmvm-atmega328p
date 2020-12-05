/* interman.c -- Interrupt Management Interface for Dos16 - Small Model (with Digital Mars C/C++)
//
// Copyright (C) 1985-2019 by Michel de Champlain
//
*/

#include "interman.h"
#include <dos.h>
#include <avr/io.h>
#include <avr/interrupt.h>

typedef void (__interrupt __far *Handler)();

// #define __cli()  _CLI()
// #define __sli()  sei()

//#if ____x8086
// End-of-interrupt to 8259 controller
// B0 20    mov  al, 0x20
// E6 20    out  0x20, al
//#define __endOfInterrupt() (__emit__(0xB0),__emit__(0x20),__emit__(0xE6),__emit__(0x20))
//#define __iret()            __emit__(0xCF)
//#endif

//#define __saveAndDisable() (__emit__(0x9C),__emit__(0xFA),__emit__(0x58))
//#define __restore()        (__emit__(0x55),__emit__(0x89),__emit__(0xE5),__emit__(0xFF),__emit__(0x76),__emit__(0x04),__emit__(0x9D),__emit__(0x5D))

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
