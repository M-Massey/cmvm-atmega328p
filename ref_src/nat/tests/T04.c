void Main() {
    puts("Test 04: Equality Operators\n");
    puts("false|true\n");
    var int i;
    var bool r; // Result.
    i = ’9’;
    r = i == 9; // false
    putb(r); putc(’|’);
    r = i != 9; // true
    putb(r);
    putn();
}
