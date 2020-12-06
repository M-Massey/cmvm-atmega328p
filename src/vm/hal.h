/* hal.h -- Hardware Abstraction Layer interface which decouples (or bridges)
//          the board support (machine dependent) modules to the VM portable code.
//
// Copyright (C) 1985-2020 by Michel de Champlain
//
*/

#ifndef __hal_h
#define __hal_h

#ifndef AVR
#include "_win_out.h"
#endif
#ifdef AVR
#include "_avr_out.h"
#endif

void Hal_Init(void);

#endif
