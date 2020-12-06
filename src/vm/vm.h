/* vm.h - Cm Virtual Machine - Interface
//
// Copyright (C) 1999-2020 by Michel de Champlain
//
*/

#ifndef __vm_h
#define __vm_h

#ifndef AVR
#include "_win_stdtype.h"
#endif
#ifdef AVR
#include "_avr_stdtype.h"
#endif

void VM_Init(u8* mainAddr);
void VM_execute(u8* startAddr);

#endif
