/* interman.c -- Interrupt Management Interface for Dos16 - Small Model (with Digital Mars C/C++)
//
// Copyright (C) 1985-2019 by Michel de Champlain
//
*/

#include "interman.h"


void  Interrupt_Disable(void) { __cli(); }
void  Interrupt_Enable(void)  { __sei(); }

u16   Interrupt_SaveAndDisable(void) { 
    return __saveAndDisable(); 
}

void  Interrupt_Restore(u16 flags) { 
    return __restore(flags);
 }

void  Interrupt_SetVector(u8 number, u32 handlerAddr) {
    __setVector(number, handlerAddr);
}

u32   Interrupt_GetVector(u8 number) {
    return __getVector(number);
}
