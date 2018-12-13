Project: MIPS Assembler
Programmers: Ian Leiby, Brendan Karper, Ryan Hippenstiel
Course: CMPE 220
Section: 2 (3-4:50pm)
Instructor: S. Lee

Description of program:
  This assembler takes in a .asm file with almost any R format MIPS instruction per line without commas, and outputs an output.txt file that has each instruction converted from MIPS to binary to output as hexadecimal (one per line in output.txt).

Algorithm:
  Read in assembler.asm
  Read each MIPS instruction by line
  Break down instruction into parts using strtok
  Convert those parts into binary
  Concatenate those parts into a 32 bit binary 
  Convert 32 binary into hexadecimal and print to output file


How to run:
- Included in the .zip file will be:
	- this readme
	- assembler.c
	- assembler.asm
- Compile using "gcc assembler.c -o assembler"
- Run by typing "./assembler" in terminal.
- This will create an output file called "output.txt" that can be viewed by typing "vi output.txt"

Bugs:
- Only works for R format instructions(we honestly tried I format but had a lot of memory issues while debugging)
- Only works for .asm file with 10 instructions
- Only works on MIPS instructions without commas

