// Ryan Hippenstiel, Ian Leiby, Brendan Karper
// CMPE220
// Dr. Lee
// MIPS Assembler
//
// This is a basic MIPS assembler for a few MIPS instructions.
#include <stdio.h>
#include <string.h>
#define INPUT "assembler.asm"

struct {
   const char *name;                                         // each R instruction has a name
   char *function;                                           // each R instruction has a purpose
} rInstruction[] = {
	{"add", "100000"},
	{"sub", "100010"},
	{"sll", "000000"},
	{"slt", "101010"},
	{"and", "100100"},
	{"or", "100101"},
	{NULL, 0}

    };

struct {
   const char *name;
   char *function;
} iInstruction[] = {
	{"sw", "101011"},
	{"lw", "100011"},
	{"addi", "001000"},
	{NULL, 0}

    };



struct {
   const char *name;
   char *function;
} jInstruction[] = {
	{"j", "000010"},
	{NULL, 0}
    };


int main(void)
{
  // const char *instructions[10];
   FILE *in;
   char line[128];
   in = fopen(INPUT, "r");
   char instructions[2][10];
   int i = 0;
   while(fgets(line, sizeof line, in) != NULL)
   {
     strcpy(instructions[i][0], line);            // should copy each line of instructions into array of instructions
     i++;
   }	   

  /** for(int a = 0; a < 10; a++){
     fscanf(in, "%s", &instructions[a]);
   }
   
   /**
    * We need a loop that runs through each instruction and 
    * assigns each part of the instruction to a string instructionName,
    * string register1, string register2, etc
    */


   return 0;
}

	
