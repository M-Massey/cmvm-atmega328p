void Main() {
    puts("Test 07: Extended Bitwise Assignment Operators"); putn();
    puts("7FFFFFA6|3FFFFFD3|FFFFFD30"); putn();
    var int r;
    r = 0x7FFFFFA6; // 7FFFFFA6 = 01111111 11111111 11111111 10100110
    putx(r); putc(’|’);
    r >>= 1; // 3FFFFFD3 = 00111111 11111111 11111111 11010011
    putx(r); putc(’|’);
    r <<= 4; // FFFFFD30 = 11111111 11111111 11111101 00110000
    putx(r);
    putn();
}
