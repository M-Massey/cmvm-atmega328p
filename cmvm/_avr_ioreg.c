/* ioreg.c -- I/O Register Interface for Windows
//
// Copyright (C) 1985-2020 by Michel de Champlain
//
*/

#include "_avr_ioreg.h"
#include "_avr_interrupts.h"

#include <avr/io.h>



// Software internal counters and values
static u32 _nReads;
static u32 _nWrites;

u32 bsl_IOReg_Read(u32 port) {
    u16 temp_flags = __saveAndDisable();
    ++_nReads;
    u32 out = _SFR_IO8((u8)port);
    __restore(temp_flags);
    __sei();
    return out;
}

void bsl_IOReg_Write(u32 port, u32 value) {
    u16 temp_flags = __saveAndDisable();
    ++_nWrites;
    _SFR_IO8((u8)port) = (u8)value;
    __restore(temp_flags);
    __sei();
}
