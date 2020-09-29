#include "vigenere.h"

#include <err.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>



int vigenere_encrypt(char *infile, char *outfile, char key[], int c_or_d)
{
    int index = 0;
    int char_value = 0;
    int cypher_value = 0;
    FILE* fdin = fopen(infile, "r");
    FILE* fdout = fopen(outfile, "w");
    if(fdin == NULL){ exit(EXIT_FAILURE);}
    char_value = fgetc(fdin);
    while( char_value != EOF )
    {
	cypher_value = cypher(char_value, key, &index, c_or_d);
	fputc(cypher_value, fdout);
	char_value = fgetc(fdin);
    }
    fclose(fdin);
    fclose(fdout);
    return 0;
}

int cypher(char c, char key[], int* keyindex, int c_or_d)
{
    int cyphered_char = 0;
    if(c_or_d == 0)
    {
	cyphered_char = (c + key[*keyindex]) % 256;
    }
    else
    {
	cyphered_char = (c - key[*keyindex]) % 256;
    }
    if(*keyindex == strlen(key))
    {
    	*keyindex = 0;
    }
    else
    {
	 *keyindex += 1;
    }
    return cyphered_char;
}

int main(int argc, char* argv[])
{
    if(*argv[1] == 'c')
    {
	vigenere_encrypt(argv[2],argv[3],argv[4], 0);
    }
    else if (*argv[1] == 'd')
    {
	vigenere_encrypt(argv[2],argv[3],argv[4], 1);
    }
    else
    {
	printf("Wrong argument given to vigenere script.");
    }
}
