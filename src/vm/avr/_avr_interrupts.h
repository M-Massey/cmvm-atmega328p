/* interman.h -- Interrupt Management Interface
//
// Copyright (C) 1985-2019 by Michel de Champlain
//
*/

#ifndef __interrupts_h
#define __interrupts_h

#include "_avr_stdtype.h"

void __cli();
void __sei();

u16 __saveAndDisable();
void __restore(u16 flags);

// Not yet implemented
// void  __setVector(u8 number, u32 handlerAddr);
// u32   __getVector(u8 number);

#endif
