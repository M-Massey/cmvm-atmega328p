int Set(int value, int bit) {
    return value |= (1 << bit);
}
int Clear(int value, int bit) {
    return value &= ~(1 << bit);
}
int Toggle(int value, int bit) {
    return value ^= (1 << bit);
}
int Read(int value, int bit) {
    return (value >> bit) & 0x01;
}
void Main() {
    puts("Test 12: Bit functions\n");
    puts("|00000000|00000004|00000000|00000004|00000001|00000000\n");
    var int i = 0x00;
    var int r = 0x00;
    putc(’|’); putx(i);
    i = Bit.Set(i, 2);
    putc(’|’); putx(i);
    i = Bit.Clear(i, 2);
    putc(’|’); putx(i);
    i = Bit.Toggle(i, 2);
    putc(’|’); putx(i);
    r = Bit.Read(i, 2);
    putc(’|’); putx(r);
    r = Bit.Read(i, 0);
    putc(’|’); putx(r);
    putn();
}
