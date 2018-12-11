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
   char instructions[10][30];
   int i = 0;

   // runs through asm file and prints them, ideally
   // we want to do things with them instead of print them
   /**
   while(fgets(instructions[i], sizeof(instructions[i]), in))
   {
     i++;
   }
   for(int a = 0; a < 10; a++){
     printf("%s",  instructions[a]);
   }
   **/

   // this is the one we're messing with 
   while(fgets(instructions[i], sizeof(instructions[i]), in))
   {
     i++;
   }
   for(int a = 0; a < 10; a++){
     char *search = " ";
    // char *search2 = ", ";
     char *individualInstruction;
     char *destination;
     individualInstruction = strtok(instructions[a], search);
     destination = strtok(instructions[a], search);
     printf("%s, %s\n", individualInstruction, destination);
     
     
     /**
      * if individualInstruction = "add"
      * then destination = strtok(instructions[a], search
      */
   }



   
  
   /**
    * We need a loop that runs through each instruction and 
    * assigns each part of the instruction to a string instructionName,
    * string register1, string register2, etc
    */

   fclose(in);
   return 0;
}

	
