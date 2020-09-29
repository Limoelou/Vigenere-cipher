#include "vigenere.h"

#include <err.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>



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

void print_table(int* occ_table)
{
    for(int i = 0; i < 256; i++)
    {
	printf("%d",occ_table[i]);
    }
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
    if(*argv[1] == 'o')
    {
	int* occ_table;
	occ_table = frequence(string_test);
	print_table(occ_table);
	free(occ_table);
    }

}
