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
int* frequence(char* s)
{
    char c;
    int occ_table_index = 0;
    int s_length = strlen(s);
    int key_length = 0;
    int* occ_table = malloc(256 * sizeof(int));
    if(occ_table == NULL)
    {
	errx(EXIT_FAILURE, "can't allocate size for occ_table");
    }
    for(int i = 0; i < 256; i++){ occ_table[i] = 0;}
    for(int j = 0; j < s_length; j++)
    {
	    c = s[j];
	    occ_table_index = (int)c;
	    occ_table[occ_table_index]++;
    }
    return occ_table;
}

int find_key_length(char* cyphered_text)
{
    float IC;
    int text_length = strlen(cyphered_text);
    float frequence;
    int final_length = 0;
    for(int key_length = 0; key_length < 10; key_length ++)
    {
	for(int i = 0; i < text_length; i++)
	{
	       
	}
    }
    return final_length;
}

int main(int argc, char* argv[])
{
    char* string_test = "coucou";

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
	printf("Wrong usage of vigenere.");
    }

    if(*argv[1] == 'o')
    {
	int* occ_table;
	occ_table = frequence(string_test);
	free(occ_table);
    }
}
