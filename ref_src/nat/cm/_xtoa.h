/* _xtoa.h - 'to ascii' functions (xtoa): itoa, utoa, and ftoa (used only as private functions)
//
// Copyright (C) 1999-2020 by Michel de Champlain
//
*/

#ifndef __CmVM_xtoa_h
#define __CmVM_xtoa_h

#include "_stdtype.h"

void _utoa(u32 n, char* buf, i8 next, u8 base);

void _itoa(i32 i, char* buf);

#define     _utoa(n,buf,base)          _utoa(n,buf,0,base)

#endif