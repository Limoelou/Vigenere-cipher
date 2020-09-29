#include <stdio.h>
#include <string.h>


int vigenere_encrypt(char *infile, char *outfile, char key[], int c_or_d);

int cypher(char c, char key[], int* keyindex, int c_or_d);

int* frequence(char* s);

int find_key_length(char* cyphered_text);
