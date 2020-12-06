/* interman.h -- Interrupt Management Interface
//
// Copyright (C) 1985-2019 by Michel de Champlain
//
*/

#ifndef __interman_h
#define __interman_h

#ifdef AVR
#include "avr/_avr_stdtype.h"
#include "avr/_avr_interrupts.h"
#else
#include "win/_win_stdtype.h"
#include "win/_win_interrupts.h"
#endif

void  Interrupt_Disable(void);
void  Interrupt_Enable(void);
u16   Interrupt_SaveAndDisable(void);
void  Interrupt_Restore(u16 flags);
void  Interrupt_SetVector(u8 number, u32 handlerAddr);
u32   Interrupt_GetVector(u8 number);

#endif
