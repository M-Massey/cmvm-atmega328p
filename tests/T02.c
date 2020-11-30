
#include <stdio.h>
#include <string.h>

void Main() {
    puts("Test 02: Conditional Operator\n");
    puts("3|4|5\n");
    var int a, b, r;
    a = 3; b = 4;
    r = a < b ? a : b;
    puti(r); putc(’|’); // 3
    a = -4;
    r = a < 0 ? -a : a;
    puti(r); putc(’|’); // 4
    a = 5;
    r = a < 0 ? -a : a;
    puti(r); // 5
    putn();
}