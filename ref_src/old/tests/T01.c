
#include <stdio.h>
#include <string.h>

void Main() {
    puts("Test 01: Value Types (Literals)\n");
    puts("-128|127|127|127|000DECAF|0000AB8D|0|9|a|A|10|10|10|10|10|false|true\n");
    // Integral literals:
    puti(-128); putc(’|’); puti(+127); putc(’|’);
    puti(127); putc(’|’); putu(127U); putc(’|’);
    putx(0xDECAF); putc(’|’); putx(0XAB8D); putc(’|’);
    // Character literals:
    putc(’0’); putc(’|’); putc(’9’); putc(’|’);
    putc(’a’); putc(’|’); putc(’A’); putc(’|’);
    puti(’\n’); putc(’|’); puti(’\xA’); putc(’|’);
    puti(’\uA’); putc(’|’); puti(0xA); putc(’|’); puti(0x00000A); putc(’|’);
    // Boolean literals:
    putb(false); putc(’|’); putb(true);
    putn();
}