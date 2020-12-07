/* ioreg.c -- I/O Register Interface for Windows
//
// Copyright (C) 1985-2020 by Michel de Champlain
//
*/

#include "ioreg.h"


u32 IOReg_Read(u32 port) {
    bsl_IOReg_Read(port);
}

void IOReg_Write(u32 port, u32 value) {
    bsl_IOReg_Write(port, value);
}
