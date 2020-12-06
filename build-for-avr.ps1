# Powershell Script to compile, test, and upload the CmVM for Windows 64-bit and AVR 8-bit platforms

param (
    [System.IO.FileInfo]$Loader
)

$ErrorActionPreference = "Stop";

Write-Host

if ($Loader.Exists) {
    Write-Host "Building $($Loader.BaseName) for ATmega328p..."

    Set-Location .\src\vm

    avr-gcc -Os -Wall -DAVR -DInterruptManagerOn -DF_CPU=16000000UL -mmcu=atmega328p -o ..\..\bin\avr.o `
        $($Loader.FullName) `
        hal.c `
        vm.c `
        vmstack.c `
        opcode.h `
        out.c `
        interman.c `
        ioreg.c `
        _avr_console.c `
        _avr_cout.c `
        _avr_xtoa.c `
        _avr_interrupts.c
    
    Set-Location ../..

}
else {
    Write-Host "Could not find specified program loader implementation."
}


