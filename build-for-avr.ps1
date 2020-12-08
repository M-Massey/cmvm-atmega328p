# Powershell Script to compile, test, and upload the CmVM for Windows 64-bit and AVR 8-bit platforms

param (
    [System.IO.FileInfo]$Loader,
    [switch]$Upload,
    [string]$UploadPort
)

$ErrorActionPreference = "Stop";

Write-Host

if ($Loader.Exists) {
    Write-Host "Building $($Loader.BaseName) for ATmega328p..."

    Set-Location .\cmvm

    avr-gcc -Os -Wall -DAVR -DInterruptManagerOn -DF_CPU=16000000UL -mmcu=atmega328p -o ..\bin\avr.o `
        $($Loader.FullName) `
        hal.c `
        vm.c `
        vmstack.c `
        out.c `
        interman.c `
        ioreg.c `
        _avr_cout.c `
        _avr_xtoa.c `
        _avr_interrupts.c `
        _avr_uart.c `
        _avr_ioreg.c
    
    Set-Location ..

    avr-objcopy -O ihex -j .text -j .data .\bin\avr.o .\bin\avr.hex

}
else {
    Write-Host "Could not find specified program loader implementation."
}

if ($Upload -and $UploadPort.Length -gt 0) {
    
    avrdude -c arduino -p atmega328p -b 57600 -P $UploadPort -D -Uflash:w:bin/avr.hex:i
}
elseif ($Upload) {
    Write-Error "Please specify a port!"
    Write-Host "Exitting..."
}

