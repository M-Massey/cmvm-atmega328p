#ifndef __win_interrupts_h
#define __win_interrupts_h

#include "_win_interrupts.h"
#include "_win_stdtype.h"

typedef void (__interrupt __far *Handler)();

#define __cli()  __emit__(0xFA)
#define __sei()  __emit__(0xFB)

#if ____x8086
// End-of-interrupt to 8259 controller
// B0 20    mov  al, 0x20
// E6 20    out  0x20, al
#define __endOfInterrupt() (__emit__(0xB0),__emit__(0x20),__emit__(0xE6),__emit__(0x20))
#define __iret()            __emit__(0xCF)
#endif

#define ___saveAndDisable() (__emit__(0x9C),__emit__(0xFA),__emit__(0x58))
/* asm {
        pushf        // 9C
        cli          // FA
        pop ax       // 58
   }
*/

#define ___restore()        (__emit__(0x55),__emit__(0x89),__emit__(0xE5),__emit__(0xFF),__emit__(0x76),__emit__(0x04),__emit__(0x9D),__emit__(0x5D))
/* asm {
        push  bp                // 55
        mov   bp, sp            // 89 E5
        push  word ptr [bp+4]   // FF 76 04
        popf                    // 9D
        pop   bp;               // 5D
    }
*/

u16 __saveAndDisable();
void __restore(u16 flags);

void  __setVector(u8 number, u32 handlerAddr);
u32   __getVector(u8 number);

#endif