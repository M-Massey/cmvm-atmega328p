avr-gcc -Os -Wall -DF_CPU=16000000UL -mmcu=atmega328p  _console.c _xtoa.c test.c hal.c out.c ioreg.c vm.c vmstack.c bsl_COut.c  -o test.o
avr-objcopy -O ihex -j .text -j .data test.o  test.hex
avrdude -c arduino -p atmega328p -b 57600 -P COM5 -D -Uflash:w:test.hex:i
pause