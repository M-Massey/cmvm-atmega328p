# Important Communications from Prof

## Precompiled T01-T12 binary files and the VM port in 4 steps (Nov. 23)
Hi Everyone,

To get the pre-compiled T01-T12 files to run, you must recompile the whole Cm VM on the host. If you look carefully at the batch file I gave you, I run these programs like this: cm.exe T01.exe where 'cm.exe' is the cm VM executable program on the host. T01-T12 are .exe (binary) files that can only be executed by the VM. Therefore, you cannot run them on Windows, macOS, or Linux.  It is normal to get an incompatibility error with all these OSs.

T01-T12.exe files are precompiled binaries. You don't need to recompile them since they are portable amongst any platform (Windows, macOS, and Linux) as long as you run them with the Cm VM. It is the same kind of portability as the Java VM byte code. You should have no problem.

Yesterday, I completed the port of the Cm VM on the Arduino Nano. The VM takes less than 6KB of flash smile Tests are running fine (as expected) on the host and target.

During lecture 11 last week, I have presented examples of making tests in four steps on the Arduino Nano. Tests programs in C and batch files were available in a zip file on Moodle to incrementally port the VM on target in following these steps:

1. Unit test for xtoa and UART transmit functions to port the BSL layer
2. Unit test for I/O functions to port the HAL layer (indirectly doing an integration test in reusing the BSL layer)
3. Unit test for the VM Operand Stack (again, indirectly doing an integration test in reusing the BSL and HAL layers)
4. How to make a first basic test to run the VM on target with a preloaded tiny program.

I explained briefly (step 4) how to make a conditional compilation with the admin.c that contains the VM main by replacing the loadObjFile() function with a simple first basic precompiled binary (.exe). I will go over this last step again in my lecture this week. This first easy test can be run on target (before starting writing a loader using the UART) by hardcoding some small tests (4 bytes) in the admin.c file, such as

```txt
Addr  Machine code  Instruction
0000  91            ldc.i3  1
0001  FF 82         trap    82
0003  00            halt
```

Example: (to print '1' on the console output)

```c
u8 mem[] = { 0x91, 0xFF, 0x82, 0x00 };
```

With this test, I got the following output on the Arduino Nano using PuTTY:

```txt
Cm Virtual Machine  v0.1.00.1101a (ATMega328P)
Copyright (c) 2001-2020  Michel de Champlain
1
```

Example: (to run T11.exe)

```c
u8 mem[]= { 0xE1, 0x00, 0x25, 0x71, 0xD5, 0x00, 0x2F, 0xFF, 0x85, 0xD5, 0x00, 0x44, 0xFF, 0x85,
0xD9, 0x09, 0xA8, 0xE0, 0x0E, 0xA0, 0x90, 0x1C, 0xE3, 0x04, 0xE0, 0x09, 0xA0, 0xB4, 0x00, 0xFF,
0x82, 0xE0, 0xF4, 0xFF, 0x87, 0x03, 0x04, 0xE7, 0xFF, 0xFF, 0xE7, 0xFF, 0xDB, 0x00, 0x54, 0x2E,
0x53, 0x74, 0x6D, 0x74, 0x00, 0x54, 0x65, 0x73, 0x74, 0x20, 0x31, 0x31, 0x3A, 0x20, 0x62, 0x72,
0x65, 0x61, 0x6B, 0x20, 0x53, 0x74, 0x61, 0x74, 0x65, 0x6D, 0x65, 0x6E, 0x74, 0x0A, 0x00, 0x39,
0x38, 0x37, 0x36, 0x35, 0x34, 0x33, 0x32, 0x31, 0x30, 0x0A, 0x00 };
```

With test T11.exe, I got the following output on the Arduino Nano using PuTTY:

```txt
Cm Virtual Machine  v0.1.00.1101a (ATMega328P)
Copyright (c) 2001-2020  Michel de Champlain
Test 11: break Statement
9876543210
9876543210
```

Whatever step you are at, I will be available today during my office hours if you have any questions.
For this week's lecture, I will discuss the loader using the UART and the protocol to load the T01-T12.exe from the host to the Arduino Nano RAM.

Best Regards,
Dr. de Champlain