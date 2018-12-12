// Ryan Hippenstiel, Ian Leiby, Brendan Karper
// CMPE220
// Dr. Lee
// MIPS Assembler
//
// This is a basic MIPS assembler for a few MIPS instructions.
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define INPUT "assembler.asm"

char *strrev(char *str)
{
      char *p1, *p2;

      if (! str || ! *str)
            return str;
      for (p1 = str, p2 = str + strlen(str) - 1; p2 > p1; ++p1, --p2)
      {
            *p1 ^= *p2;
            *p2 ^= *p1;
            *p1 ^= *p2;
      }
      return str;
}



char add[] = "add";
char sw[] = "sw";
char lw[] = "lw";
char addi[] = "addi";
char j[] = "j";
char sub[] = "sub";
char sll[] = "sll";
char slt[] = "slt";
char and[] = "and";
char or[] = "or";

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
} registerMap[] = {
	{"$t0", "01000"},
	{"$t1", "01001"},
	{"$t2", "01010"},
	{"$t3", "01011"},
	{"$s0", "10000"},
	{"$s1", "10001"},
	{"$s2", "10010"},
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
   char instructions[10][32];
   char hexadecimals[10][32];
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
     char *goingThruInstruction;
     char *individualInstruction;
     char *destination;
     char *source1;
     char *source2;
     char binary[] = "";
     int indexSource1 = 0;
     int indexSource2 = 0;
     int indexDestination = 0;
     int indexFunct = 0;
     // this part splits each instruction into the respective parts
     individualInstruction = strtok(instructions[a], search);
     destination = strtok(NULL, search);
     source1 = strtok(NULL, search);
     source2 = strtok(NULL, search); 
     printf("%s %s %s %s\n",individualInstruction, destination, source1, source2);
     
     // if individualInstruction is add, then do operations based off that
     if(strcmp(individualInstruction, add) == 0) {
	     for(int i = 0; i < 7; i++) {
		  if( strcmp(source1, registerMap[i].name) == 0){
			indexSource1 = i;
	       } 
	     }	  
	     for(int i = 0; i < 7; i++) {
                  if (strcmp(source2, registerMap[i].name) == 0) {
		        indexSource2 = i;
		 }
	     }
	     for(int i = 0; i < 7; i++) {
		     if (strcmp(destination, registerMap[i].name) == 0) {
                        indexDestination = i;
		}
	     }
	     for (int i = 0; i < 6; i++) {
	          if (strcmp(individualInstruction, rInstruction[i].name) == 0) {
		     indexFunct = i;
		  }

	     
	     }

	     strcat(binary, "000000");
	     strcat(binary, registerMap[indexSource1].function);
	     strcat(binary, registerMap[indexSource2].function);
	     strcat(binary, registerMap[indexDestination].function);
	     strcat(binary, "00000");
	     strcat(binary, rInstruction[indexFunct].function);
	    // strcat(registerMap[index].function, binary);
	     printf("%s\n", binary);
	     int value = (int)strtol(binary, NULL, 2);
	     char hexString[12];
	     char zero[] = "0x0";
	     sprintf(hexString, "%x", value);
	     if(strlen(hexString) < 8) {
		     strcat(zero, hexString);
		     strcpy(hexadecimals[0], zero);
		     printf("%s\n", hexadecimals[0]);
				     
	     } else {
	      printf("0x%s\n", hexString);

	     }
	     	     
     }
     
     if(strcmp(individualInstruction, addi) == 0) {
	     printf("this is an addi instruction\n");
             for(int i = 0; i < 7; i++) {
		  if( strcmp(source1, registerMap[i].name) == 0){
			indexSource1 = i;
	       } 
	     }	  
	     for(int i = 0; i < 7; i++) {
                  if (strcmp(destination, registerMap[i].name) == 0) {
		        indexDestination = i;
		 }
	     }
             for (int i = 0; i < 3; i++) {
	          if (strcmp(individualInstruction, iInstruction[i].name) == 0) {
		     indexFunct = i;

               }
	     }
	     strcat(binary, iInstruction[indexFunct].function);
	     strcat(binary, registerMap[indexSource1].function);
	     strcat(binary, registerMap[indexDestination].function);
	     int immediate = atoi(source2);
	     int index = 0;
	     char tempBinary[32];
	     while(immediate != 0) {
		     tempBinary[index] = (immediate % 2) + '0';
		     immediate /= 2;
		     index++;

	     }
	     tempBinary[index] = '\0';
	     strrev(tempBinary);
	     printf("binary is %s\n", tempBinary);




 
     if(strcmp(individualInstruction, sub) == 0) {
	     printf("this is a sub instruction\n");

             for(int i = 0; i < 7; i++) {
		  if( strcmp(source1, registerMap[i].name) == 0){
			indexSource1 = i;
	       } 
	     }	  
	     for(int i = 0; i < 7; i++) {
                  if (strcmp(source2, registerMap[i].name) == 0) {
		        indexSource2 = i;
		 }
	     }
	     for(int i = 0; i < 7; i++) {
		     if (strcmp(destination, registerMap[i].name) == 0) {
                        indexDestination = i;
		}
	     }
	     for (int i = 0; i < 6; i++) {
	          if (strcmp(individualInstruction, rInstruction[i].name) == 0) {
		     indexFunct = i;
		  }

	     
	     }
             strcat(binary, "000000");
	     strcat(binary, registerMap[indexSource1].function);
	     strcat(binary, registerMap[indexSource2].function);
	     strcat(binary, registerMap[indexDestination].function);
	     strcat(binary, "00000");
	     strcat(binary, rInstruction[indexFunct].function);
	    // strcat(registerMap[index].function, binary);
	     printf("%s\n", binary);
	     int value = (int)strtol(binary, NULL, 2);
	     char hexString[12];
	     char zero[] = "0x0";
	     sprintf(hexString, "%x", value);
	     if(strlen(hexString) < 8) {
		     strcat(zero, hexString);
		     strcpy(hexadecimals[0], zero);
		     printf("%s\n", hexadecimals[0]);
				     
	     } else {
	      printf("0x%s\n", hexString);

	     }


}
     if(strcmp(individualInstruction, slt) == 0) {
	     printf("this is a slt instruction\n");
             for(int i = 0; i < 7; i++) {
		  if( strcmp(source1, registerMap[i].name) == 0){
			indexSource1 = i;
	       } 
	     }	  
	     for(int i = 0; i < 7; i++) {
                  if (strcmp(source2, registerMap[i].name) == 0) {
		        indexSource2 = i;
		 }
	     }
	     for(int i = 0; i < 7; i++) {
		     if (strcmp(destination, registerMap[i].name) == 0) {
                        indexDestination = i;
		}
	     }
	     for (int i = 0; i < 6; i++) {
	          if (strcmp(individualInstruction, rInstruction[i].name) == 0) {
		     indexFunct = i;
		  }

	     
	     }
             strcat(binary, "000000");
	     strcat(binary, registerMap[indexSource1].function);
	     strcat(binary, registerMap[indexSource2].function);
	     strcat(binary, registerMap[indexDestination].function);
	     strcat(binary, "00000");
	     strcat(binary, rInstruction[indexFunct].function);
	    // strcat(registerMap[index].function, binary);
	     printf("%s\n", binary);
	     int value = (int)strtol(binary, NULL, 2);
	     char hexString[12];
	     char zero[] = "0x0";
	     sprintf(hexString, "%x", value);
	     if(strlen(hexString) < 8) {
		     strcat(zero, hexString);
		     strcpy(hexadecimals[0], zero);
		     printf("%s\n", hexadecimals[0]);
				     
	     } else {
	      printf("0x%s\n", hexString);

	     }

     }
     if(strcmp(individualInstruction, and) == 0) {
	     printf("this is an and instruction\n");
             for(int i = 0; i < 7; i++) {
		  if( strcmp(source1, registerMap[i].name) == 0){
			indexSource1 = i;
	       } 
	     }	  
	     for(int i = 0; i < 7; i++) {
                  if (strcmp(source2, registerMap[i].name) == 0) {
		        indexSource2 = i;
		 }
	     }
	     for(int i = 0; i < 7; i++) {
		     if (strcmp(destination, registerMap[i].name) == 0) {
                        indexDestination = i;
		}
	     }
	     for (int i = 0; i < 6; i++) {
	          if (strcmp(individualInstruction, rInstruction[i].name) == 0) {
		     indexFunct = i;
		  }

	     
	     }
             strcat(binary, "000000");
	     strcat(binary, registerMap[indexSource1].function);
	     strcat(binary, registerMap[indexSource2].function);
	     strcat(binary, registerMap[indexDestination].function);
	     strcat(binary, "00000");
	     strcat(binary, rInstruction[indexFunct].function);
	    // strcat(registerMap[index].function, binary);
	     printf("%s\n", binary);
	     int value = (int)strtol(binary, NULL, 2);
	     char hexString[12];
	     char zero[] = "0x0";
	     sprintf(hexString, "%x", value);
	     if(strlen(hexString) < 8) {
		     strcat(zero, hexString);
		     strcpy(hexadecimals[0], zero);
		     printf("%s\n", hexadecimals[0]);
				     
	     } else {
	      printf("0x%s\n", hexString);

	     }

     }
     if(strcmp(individualInstruction, or) == 0) {
	     printf("this is an or instruction\n");
             for(int i = 0; i < 7; i++) {
		  if( strcmp(source1, registerMap[i].name) == 0){
			indexSource1 = i;
	       } 
	     }	  
	     for(int i = 0; i < 7; i++) {
                  if (strcmp(source2, registerMap[i].name) == 0) {
		        indexSource2 = i;
		 }
	     }
	     for(int i = 0; i < 7; i++) {
		     if (strcmp(destination, registerMap[i].name) == 0) {
                        indexDestination = i;
		}
	     }
	     for (int i = 0; i < 6; i++) {
	          if (strcmp(individualInstruction, rInstruction[i].name) == 0) {
		     indexFunct = i;
		  }

	     
	     }
             strcat(binary, "000000");
	     strcat(binary, registerMap[indexSource1].function);
	     strcat(binary, registerMap[indexSource2].function);
	     strcat(binary, registerMap[indexDestination].function);
	     strcat(binary, "00000");
	     strcat(binary, rInstruction[indexFunct].function);
	    // strcat(registerMap[index].function, binary);
	     printf("%s\n", binary);
	     int value = (int)strtol(binary, NULL, 2);
	     char hexString[12];
	     char zero[] = "0x0";
	     sprintf(hexString, "%x", value);
	     if(strlen(hexString) < 8) {
		     strcat(zero, hexString);
		     strcpy(hexadecimals[0], zero);
		     printf("%s\n", hexadecimals[0]);
				     
	     } else {
	      printf("0x%s\n", hexString);

	     }

     }


     
    
    
    
     /** while(goingThruInstruction != NULL) {
	     individualInstruction = goingThruInstruction;
	     goingThruInstruction = strtok(instructions[a], search);
	     printf("%s\n", individualInstruction);
	     
     }
     
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
}



	
