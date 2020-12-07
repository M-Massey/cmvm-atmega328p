avr-gcc -Os -Wall -DF_CPU=16000000UL -mmcu=atmega328p  _console.c _xtoa.c hal_loader.c hal.c out.c vm.c vmstack.c bsl_uart.c bsl_COut.c  -o hal_loader.o
avr-objcopy -O ihex -j .text -j .data hal_loader.o  hal_loader.hex
avrdude -c arduino -p atmega328p -b 57600 -P COM5 -D -Uflash:w:hal_loader.hex:i
echo done.  press any key to exit script

pause