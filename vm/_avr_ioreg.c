/* ioreg.c -- I/O Register Interface for Windows
//
// Copyright (C) 1985-2020 by Michel de Champlain
//
*/

#include "_avr_ioreg.h"

#include <avr/io.h>



// Software internal counters and values
static u32 _nReads;
static u32 _nWrites;

u32 bsl_IOReg_Read(u32 port) {
    ++_nReads;
    return _SFR_IO8((u8)port);
}

void bsl_IOReg_Write(u32 port, u32 value) {
    ++_nWrites;
    _SFR_IO8((u8)port) = (u8)value;
}
