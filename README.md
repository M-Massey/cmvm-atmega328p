# Cm VM port for Atmega 328p <!-- omit in toc -->

## Table of Contents <!-- omit in toc -->

- [1. Important Repo Locations](#1-important-repo-locations)
- [2. Prerequisites](#2-prerequisites)
- [3. Task 0: Port & Compile AUnit](#3-task-0-port--compile-aunit)
- [4. Task 1: Port & Compile Cm VM](#4-task-1-port--compile-cm-vm)
- [5. Tasks 2-4: Isolate and port the BSL and HAL layers to Atmega328p](#5-tasks-2-4-isolate-and-port-the-bsl-and-hal-layers-to-atmega328p)
- [6. Task 5: Implement a program loader](#6-task-5-implement-a-program-loader)
- [7. Task 6: Port the interrupt manager to Atmega328p](#7-task-6-port-the-interrupt-manager-to-atmega328p)
- [8. Task 7: Implement an I/O interface with HAL and BSL layers](#8-task-7-implement-an-io-interface-with-hal-and-bsl-layers)
- [9. Task 8: Project report and Git repo](#9-task-8-project-report-and-git-repo)
- [Useful References](#useful-references)
- [Instructions from Nat](#instructions-from-nat)

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






## Useful References

- [Atmega328p External Interrupts Explanation](https://www.arxterra.com/11-atmega328p-external-interrupts/#ATmega328P_External_Interrupt_Enable)
- [i386 Instruction Set](https://pdos.csail.mit.edu/6.828/2008/readings/i386/c17.htm)
- [AMD64 Instruction Handout](http://6.s081.scripts.mit.edu/sp18/x86-64-architecture-guide.html)
- [AMD64 Manual Volume 1](https://www.amd.com/system/files/TechDocs/24592.pdf)

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
- run : dumpf dist\T01.exe
