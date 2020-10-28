# Vigenere encryption and cryptanalysis methods

# RESUME
The Vigenere encryption is an encryption algorithm which is similar the casear’s code in the
way it operates. It uses the length of the key to split the message into n characters. Then the
i-th letter of the text is shifted according to the i-th letter of the key, making the cryptanalysis
far more difficult but not impossible.

# ENCRYPTION AND DECRYPTION IMPLEMENTATION

The src/vigenere.c file which contains the source code for the vigenere encryption.
compiling it with ’make’ gives the executable ’vigenere’.
To use it : ./vigenere c/d infile outfile key
c : encrypt the infile
d : decrypt the infile
infile : the input file to be encrypted or decrypted given the right key
outfile : the output file key: the key for the encryption / decryption


# 3 CRYPTANALYSIS WITH KASISKI TEST

# 3.1 FIND KEY LENGTH
To find the key length, we need to test each possible length from 1 to 10 and divide the ciphertext into substrings based on the key length we are testing.
For each possible length that we are testing we compute the average of the indexes of coincidence of each substring and we store these averages in an array. The maximum average
corresponds to the most probable length of key.

# 3.2 SEARCH FOR PROBABLE KEY
When we get the k length of the key, we separate the message into k subsets in a table with
build_sub_array().
We then need to use mutual_IC() to calculate the ICM of each subset. Then we use IMC_offset()
on each subset which calculate the highest ICM possible with a shift between 0 and 255, and
then return the corresponding shift value (the offset).
We build a table with build_offset_table() containing each subset and its corresponding best
offset.

# 3.3 KEY EXTRACTOR
Each offset represents a distance between K0 and Ki (0 < i < key length). Each subset is also
encrypted with one letter of the key.
We then need to shift each subset by offset + K0 where K0 is a value between 0 and 255
to get the 256 possibilities of the key and print it with print_possible_keys(). The real key for
the cipher is one of the 256 keys printed !
