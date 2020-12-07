/* bsl_IOReg.h - IO Register Interface
//
// Copyright (C) 2020 by Michel de Champlain
//
*/

#ifndef __avr_ioreg_h
#define __avr_ioreg_h

#include "_avr_stdtype.h"

u32  bsl_IOReg_Read (u32 ioreg);
void bsl_IOReg_Write(u32 ioreg, u32 value);

#endif
