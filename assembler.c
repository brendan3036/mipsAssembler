// Ryan Hippenstiel, Ian Leiby, Brendan Karper
// CMPE220
// Dr. Lee
// MIPS Assembler
//
// This is a basic MIPS assembler for a few MIPS instructions.
#include <stdio.h>
#define INPUT "assembler.asm"

struct rInstruction
{
   const char *name;                                         // each R instruction has a name
   char *function;                                           // each R instruction has a purpose
} = {
	{"add", "100000"},
	{"sub", "100010"},
	{"sll", "000000"},
	{"slt", "101010"},
	{"and", "100100"},
	{"or", "100101"},
	{NULL, 0}

    };

struct iInstruction
{
   const char *name;
   char *function;
} = {
	{"sw", "101011"},
	{"lw", "100011"},
	{"addi", "001000"},
	{NULL, 0}

    };



struct jInstruction
{
   const char *name;
   char *function;
} = {
	{"j", "000010"},
	{NULL, 0}
    };


int main(void)
{
   FILE *in;
   in = fopen(INPUT, "r");
   char[10] instructions;
   for(int a = 0; a < 10; a++){
     fscanf(in, "%s", &instructions[a]);
   }
   
   /**
    * We need a loop that runs through each instruction and 
    * assigns each part of the instruction to a string instructionName,
    * string register1, string register2, etc
    */


   return 0;
}

	
