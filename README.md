
To compile the virtual machine on your host : bash build.sh
This will create an executable in the dist folder.

To compile the AUnit.c : gcc -o build/aunit AUnit.c
This will create an executable in the dist folder

To run the tests: cm.exe T01.exe > T1.txt
This will run the test and write the output to T1.txt file

To run the aunit.exe : aunit T1.txt
