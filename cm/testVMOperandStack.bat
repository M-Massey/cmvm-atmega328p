avr-gcc -Os -Wall -DF_CPU=16000000UL -mmcu=atmega328p tvmstack.c vmstack.c hal.c out.c bsl_COut.c _xtoa.c -o tvmstack.o
avr-objcopy -O ihex -j .text -j .data tvmstack.o  tvmstack.hex
avrdude -c arduino -p atmega328p -b 57600 -P COM5 -D -Uflash:w:tvmstack.hex:i
pause
