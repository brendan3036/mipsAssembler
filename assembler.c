/*
 * Project: MIPS Assembler
 * Programmer: Ian Leiby, Brendan Karper, Ryan Hippenstiel
 * Course: CMPE 220
 * Section: 2 (3-4:50pm)
 * Instructor: S. Lee
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define INPUT "assembler.asm"
#define OUTPUT "output.txt"

void append(char* s, char c)
{
        int len = strlen(s);
        s[len] = c;
        s[len+1] = '\0';
}

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
   FILE *in;
   FILE *out;
   char line[128];
   in = fopen(INPUT, "r");
   out = fopen(OUTPUT, "w");
   char instructions[10][32];
   char hexadecimals[10][32];
   int i = 0;


   while(fgets(instructions[i], sizeof(instructions[i]), in))
   {
     i++;
   }
   for(int a = 0; a < 10; a++){
     char *search = " ";
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
	     int value = (int)strtol(binary, NULL, 2);
	     char hexString[12];
	     char zero[] = "0x0";
	     sprintf(hexString, "%x", value);
	     if(strlen(hexString) < 8) {
		     strcat(zero, hexString);
		     strcpy(hexadecimals[0], zero);
		     fprintf(out, "%s\n", hexadecimals[0]);
				     
	     } else {
	      fprintf(out, "0x%s\n", hexString);

	     }
	     	     
     }
     
     if(strcmp(individualInstruction, addi) == 0) {
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
	     int index1 = 0;
	     char tempBinary[16] = "";
	     while(immediate != 0) {
		     tempBinary[index1] = (immediate % 2) + '0';
		     immediate /= 2;
		     index1++;

	     }
	     tempBinary[index1] = '\0';
	     strrev(tempBinary);
             
	     int total = strlen(binary) + strlen(tempBinary);
	     int length = 32 - total;
	     length -= 7;
	    
	     char zeroes[length];
	     for (int j = 0; j < length; j++) {
		    // append(zeroes, '0');
		    zeroes[j] = '0';
	     }
	     strcat(binary, zeroes);
	     strcat(binary, tempBinary);
     }


 
     if(strcmp(individualInstruction, sub) == 0) {

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
	     int value = (int)strtol(binary, NULL, 2);
	     char hexString[12];
	     char zero[] = "0x0";
	     sprintf(hexString, "%x", value);
	     if(strlen(hexString) < 8) {
		     strcat(zero, hexString);
		     strcpy(hexadecimals[0], zero);
		     fprintf(out, "%s\n", hexadecimals[0]);
				     
	     } else {
	      fprintf(out, "0x%s\n", hexString);
	     }
}
     if(strcmp(individualInstruction, slt) == 0) {
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
	     int value = (int)strtol(binary, NULL, 2);
	     char hexString[12];
	     char zero[] = "0x0";
	     sprintf(hexString, "%x", value);
	     if(strlen(hexString) < 8) {
		     strcat(zero, hexString);
		     strcpy(hexadecimals[0], zero);
		     fprintf(out, "%s\n", hexadecimals[0]);
	     } else {
	      fprintf(out, "0x%s\n", hexString);
	     }	     
     }
     if(strcmp(individualInstruction, and) == 0) {
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
	     int value = (int)strtol(binary, NULL, 2);
	     char hexString[12];
	     char zero[] = "0x0";
	     sprintf(hexString, "%x", value);
	     if(strlen(hexString) < 8) {
		     strcat(zero, hexString);
		     strcpy(hexadecimals[0], zero);
		     fprintf(out, "%s\n", hexadecimals[0]);
				     
	     } else {
	      fprintf(out, "0x%s\n", hexString);
	     }
     }
     if(strcmp(individualInstruction, or) == 0) {
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
	     int value = (int)strtol(binary, NULL, 2);
	     char hexString[12];
	     char zero[] = "0x0";
	     sprintf(hexString, "%x", value);
	     if(strlen(hexString) < 8) {
		     strcat(zero, hexString);
		     strcpy(hexadecimals[0], zero);
		     fprintf(out, "%s\n", hexadecimals[0]);
				     
	     } else {
	      fprintf(out, "0x%s\n", hexString);
	     }
     }
}
       printf("Output hexadecimal values are in file output.txt\n");
       fclose(in);   
       fclose(out);
       return 0;
}





	
