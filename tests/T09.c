const int Min = 0;
const int Max = 9;

int Tick(int count, bool directionUp) {
    if (directionUp) { // If with an else clause.
    if (++count > Max) { // Nested if without an else clause.
        count = Min;
    }
    } else { // Else clause of the outer if statement.
        if (--count < Min) { // Nested if without an else clause.
            count = Max;
    }
}
puti(count); putc(’|’);
return count;
}
void Main() {
    puts("Test 09: if-else Statement\n");
    puts("9|0|9|0|1|\n");
    var int count;
    var bool directionUp;
    count = 8;
    directionUp = true;
    count = Tick(count, directionUp); // 9
    count = Tick(count, directionUp); // 0
    directionUp = false;
    count = Tick(count, directionUp); // 9
    directionUp = true;
    count = Tick(count, directionUp); // 0
    count = Tick(count, directionUp); // 1
    putn();
}
