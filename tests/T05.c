void Main() {
    puts("Test 05: Relational Operators\n");
    puts("true|true|false|false\n");
    var int a, b; // Signed integer operands.
    var bool r; // Result.
    a = 1; b = 2;
    r = a < b; putb(r); putc(’|’); // true|
    a = 3; b = 4;
    r = a <= b; putb(r); putc(’|’); // true|
    a = 5; b = 6;
    r = a > b; putb(r); putc(’|’); // false|
    a = 7; b = 8;
    r = a >= b; putb(r); // false|
    putn();
}
