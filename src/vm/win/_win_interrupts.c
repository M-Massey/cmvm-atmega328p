/* interman.c -- Interrupt Management Interface for Dos16 - Small Model (with Digital Mars C/C++)
//
// Copyright (C) 1985-2019 by Michel de Champlain
//
*/

#include "_win_interrupts.h"
#include <dos.h>

u16 __saveAndDisable() {  ___saveAndDisable(); }

void __restore(u16 flags) { ___restore(); }


void  __setVector(u8 number, u32 handlerAddr) {
    _dos_setvect(number, (Handler)handlerAddr);
}

u32   __getVector(u8 number) {
    return (u32)_dos_getvect(number);
}
