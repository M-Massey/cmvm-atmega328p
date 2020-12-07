/* hal.h -- Hardware Abstraction Layer interface which decouples (or bridges)
//          the board support (machine dependent) modules to the VM portable code.
//
// Copyright (C) 1985-2020 by Michel de Champlain
//
*/

#ifndef __hal_h
#define __hal_h

<<<<<<< HEAD:nat/cm/hal.h
#include "_out.h"
=======
#ifdef AVR
#include "_avr_out.h"
#else
#include "_win_out.h"
#endif
>>>>>>> main:src/vm/hal.h

void Hal_Init(void);

#endif
