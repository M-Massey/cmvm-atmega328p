avr-gcc -Os -Wall -DF_CPU=16000000UL -mmcu=atmega328p  _console.c _xtoa.c testVM.c hal.c out.c vm.c vmstack.c bsl_uart.c bsl_COut.c  -o testVM.o
avr-objcopy -O ihex -j .text -j .data testVM.o  testVM.hex
avrdude -c arduino -p atmega328p -b 57600 -P COM5 -D -Uflash:w:testVM.hex:i
echo done.  press any key to exit script

pause