# Cm VM port for Atmega 328p <!-- omit in toc -->

## Table of Contents <!-- omit in toc -->

- [1 Cm Virtual Machine Instructions](#1-cm-virtual-machine-instructions)
  - [1.1 Build Requirements](#11-build-requirements)
  - [1.2 Build/Download Instructions](#12-builddownload-instructions)
  - [1.3 Operation Instructions](#13-operation-instructions)
- [2 Serial Loader Instructions](#2-serial-loader-instructions)
  - [2.1 Build Requirements](#21-build-requirements)
  - [2.2 Build Instructions](#22-build-instructions)
  - [2.3 cmload Usage Instructions](#23-cmload-usage-instructions)
- [3 Useful References](#3-useful-references)

## 1 Cm Virtual Machine Instructions

### 1.1 Build Requirements

- AVR Toolchain
  - Windows: [WinAVR](https://sourceforge.net/projects/winavr/) is quite convenient
  - Other: [Microchip Toolchains](https://www.microchip.com/mplab/avr-support/avr-and-arm-toolchains-c-compilers)
    - Gonna need to find avrdude somewhere.
- [PowerShell](https://github.com/PowerShell/PowerShell/releases)

### 1.2 Build/Download Instructions

1. Run the following from the root of the repo. `<driver>` is the suffix of the admin driver file with the `main` function to orchestrate the virtual machine code. `<serial>` is whatever serial port your arduino is plugged into on your machine.

```powershell
.\build-for-avr.ps1 -Driver ./cmvm/admin-avr-<driver> -UploadPort <serial>
```

### 1.3 Operation Instructions

These depending on what driver you uploaded as the orchestor of the VM.

If you uploaded `./cmvm/admin_avr_serial_loadable.c`, you'll need to use the serial loader as described in section 2.3 cmload Usage Instructions

Otherwise, if you're running a `./cmvm/admin_avr_test_*.c` file, where `*` is the name of the test, just open up your favorite serial monitor at a BAUD of `57600`, and have fun.

## 2 Serial Loader Instructions

### 2.1 Build Requirements

- [dotnet sdk](https://dotnet.microsoft.com/download)

### 2.2 Build Instructions

1. Head into the `cmload` dir

```bash
cd cmload
```

2. Build the C# project.

```bash
dotnet build -c "Release" -o ../bin/cmload
```

3. Find the build artifacts in the `bin/cmload` directory from the root of the repo. There'll be an executable you can run.

### 2.3 cmload Usage Instructions

```
PS B:\cmvm-atmega328p\bin> .\cmload.exe      

Usage: cmload.exe <file.exe> <serial>

Win32 Example: cmload.exe program.exe COM4
Linux Example: cmload.exe program.exe ttyusb0
```


## 3 Useful References

- [ATmega328P Datasheet](https://ww1.microchip.com/downloads/en/DeviceDoc/Atmel-7810-Automotive-Microcontrollers-ATmega328P_Datasheet.pdf)
- [Atmega328p External Interrupts Explanation](https://www.arxterra.com/11-atmega328p-external-interrupts/#ATmega328P_External_Interrupt_Enable)
- [i386 Instruction Set](https://pdos.csail.mit.edu/6.828/2008/readings/i386/c17.htm)
- [AMD64 Instruction Handout](http://6.s081.scripts.mit.edu/sp18/x86-64-architecture-guide.html)
- [AMD64 Manual Volume 1](https://www.amd.com/system/files/TechDocs/24592.pdf)

<!-- 
---------------------
---------------------
---------------------

## Older Stuff

## 1. Important Repo Locations

- [Professor Communications](docs/list-of-comms.md)
- [Cm VM and Test Suite Precompiled for Windows x64](ref_src/nat/cm/dist)

## 2. Prerequisites

One of the Cm VM's goal is to allow for testing of Cm code on a Windows, Mac, or Linux host prior to executing on an embedded device with limmited debugging capabilities.

Windows:

- [GCC Compiler - MingW](https://osdn.net/projects/mingw/releases/)

Mac:

- [GCC Compiler - Command Line Tools for Xcode](https://developer.apple.com/download/more/)

## 3. Task 0: Port & Compile AUnit

Mac/Linux:

TODO: Check end of line chars on Mac and Linux vs. Windows (`\n` vs `\r\n`).

Windows/MacOS/Linux:

Run the following from the root of the repo.

```bash
gcc -o tools/bin/aunit tools/AUnit.c
```

### Change log

1. Added exit code to return statement to get rid of this warning:

```txt
tools\AUnit.c: In function 'main':
tools\AUnit.c:121:13: warning: 'return' with no value, in function returning non-void
  121 |             return;
      |             ^~~~~~
tools\AUnit.c:53:5: note: declared here
   53 | int main(int argc, char** argv) {
      |  
```

## 4. Task 1: Port & Compile Cm VM

MacOS/Linux:

TODO: If we have time, maybe we'll port to linux and mac os.

Windows:

Run this from the root of the repo.

```powershell
gcc -o dist/cm _console.c _cout.c _xtoa.c admin.c hal.c ioreg.c out.c vm.c vmstack.c
```

## 5. Tasks 2-4: Isolate and port the BSL and HAL layers to Atmega328p

## 6. Task 5: Implement a program loader

## 7. Task 6: Port the interrupt manager to Atmega328p

## 8. Task 7: Implement an I/O interface with HAL and BSL layers

## 9. Task 8: Project report and Git repo








## Instructions from Nat

To compile the virtual machine on your host :

```bash
gcc -o dist/cm _console.c _cout.c _xtoa.c admin.c hal.c ioreg.c out.c vm.c vmstack.c
```

This will create an executable in the dist folder.

To compile the AUnit.c :

```bash
gcc -o build/aunit AUnit.c
```

This will create an executable in the dist folder

To run the tests: cm.exe T01.exe > T1.txt
This will run the test and write the output to T1.txt file

To run the aunit.exe : aunit T1.txt

To test BLS and HAL on the microconroller:

- connect your Arduino to your machine 
- use Putty with connection type: serial, serial line: COM5, speed: 57600. In Category, click on Terminal and check the "Implicit CR in every LF".
- run each .bat file in your command line. Example : testVMOperandStack.bat
These .bat files load the program on the microcotnroller. 
You can compare the output in Putty with the expected output to see if characters are transmited in the right way.

To see the binary contents of the executable files T01.exe...T12.exe

- compile the dumpFile.c : gcc -o dupmf dumpFile.c
- run : dumpf dist\T01.exe -->
