// Ryan Hippenstiel, Ian Leiby, Brendan Karper
// CMPE220
// Dr. Lee
// MIPS Assembler
//
// This is a basic MIPS assembler for a few MIPS instructions.
#include <stdio.h>
#define INPUT "assembler.asm"

int main(void)
{
   FILE *in;
   in = fopen(INPUT, "r");
   char[10] instructions;
   for(int a = 0; a < 10; a++){
     fscanf(in, "%s", &instructions[a]);
   }
}



//int preprocess_get_line(char label[], char instruction[], FILE* INPUT);
/*
int main(int argc, char *argv[])
{
    char *filename = "thisdoesntmatter.asm";
    if (argc >1)                                                        // if we put in an argument
    {
        filename = argv[1];                                             // make the filename what we typed it as 
    }
    FILE* inputfile = fopen(filename, "r");                             // make a new FILE type called input file, which opens our specified file
    if(inputfile == NULL)                                               // error if file not found
    {
        printf("Unable to open file, sorry\n");
        return 1;
    }
    while (preprocess_get_line(label, instruction, inputfile))          // while we are able to get lines
    {
        fprintf("%s: %s", label, instruction);                          // weprint those lines 
    }
    return 0;
}
*/
/*int preprocess_get_line(char label[], char instruction[], FILE* fp)
{
    fgets(str,260, fp);
    while(character != EOF)
    {
        printf("ASCII hex: %2x '%c'\n", (int)character, character);
        character = fgets(inputfile);
    }
    fclose(inputfile); 
} 
*/

   
