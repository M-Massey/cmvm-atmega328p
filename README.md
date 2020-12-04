# Cm VM port for Atmega 328p<!-- omit in toc -->

- [Important Repo Locations](#important-repo-locations)
- [Instructions from Nat](#instructions-from-nat)

## Important Repo Locations

- [Professor Communications](docs/list-of-comms.md)
- [Cm VM and Test Suite Precompiled for Windows x64](ref_src/nat/cm/dist)

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
