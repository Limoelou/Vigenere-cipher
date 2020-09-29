OPT=-g -Wall -I./include
OBJ= obj/vigenere.o obj/kasiski.o

ALL:vigenere kasiski

kasiski: obj/kasiski.o
	$(CC) -o $@ $^

obj/kasiski.o: src/kasiski.c include/vigenere.h
	$(CC) -o $@ -c $< $(OPT)

vigenere: obj/vigenere.o 
	$(CC) -o $@ $^

obj/vigenere.o: src/vigenere.c include/vigenere.h
	$(CC) -o $@ -c $< $(OPT)

clean:
	rm -rf obj/*.o
	rm ./vigenere
	rm ./kasiski
