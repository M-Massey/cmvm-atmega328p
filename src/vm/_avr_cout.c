/* _cout.c - Implementation of a Console for Cm Hardware Abstract Layer for Output Interface.
//
// Copyright (C) 1999-2020 by Michel de Champlain
//
*/

#include "_avr_outdesc.h"

//#define ConsoleOutputWithPrintf 1

#if ConsoleOutputWithPrintf

#include <stdio.h>

static void COut_PutB(bool b)        { printf("%s", b ? "true" : "false"); }
static void COut_PutC(char c)        { printf("%c", c); }
static void COut_PutS(const char* s) { printf("%s", s); }
static void COut_PutI(i32  i)        { printf("%ld", i); }
static void COut_PutU(u32  u)        { printf("%lu", u); }
static void COut_PutX(u32  u)        { printf("%08lX", u); } // To make hex output always aligned to 8 hex digits.
static void COut_PutN(void)          { printf("\n"); }

 //this else part is to be able to test the output on arduino, 
 //here we use putchar to print out because it doesnt take as much space as printf()
#else 
#include "_avr_xtoa.h"

// External refs to 'console.c' without
void  Console_Putchar(char  c);

static char  buf[12];                /* to cover max size (12) "i32" (10+sign+null) */

static void COut_PutB(bool b)        { Console_Putchar(b ? 'T' : 'F'); }
static void COut_PutC(char c)        { Console_Putchar(c); }
static void COut_PutS(const char* s) { while (*s) Console_Putchar(*s++); }
static void COut_PutI(i32  i)        { _itoa(i, buf); COut_PutS(buf); }
static void COut_PutU(u32  u)        { System_utoa(u, buf, 10); COut_PutS(buf); }
static void COut_PutX(u32  x)        { System_utoa(x, buf, 16); COut_PutS(buf); } // Same behavior as Dos16 VM: 
                                                                                   // Hex alpha in upppercase
static void COut_PutN(void)          { Console_Putchar('\n'); }
#endif

static IVMOutDesc cout = {
    COut_PutB,
    COut_PutC,
    COut_PutI,
    COut_PutU,
    COut_PutS,
    COut_PutX,
    COut_PutN
};

IOut Out_GetFactory(const char* whichOne) {
    whichOne = 0; // To avoid the warning on the unreferenced formal parameter
    return &cout;
}