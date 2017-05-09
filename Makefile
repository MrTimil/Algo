CFLAG=-c -Wall -std=c99 -g -o 

all: bp_navy
bp_navy: bibli.o navy.o
	gcc -Wall -std=c99 -g -o bp_navy $^ -lm

navy.o: navy.c bibli.h 
	gcc $(CFLAG) navy.o $<
	
bibli.o: bibli.c bibli.h
	gcc $(CFLAG) bibli.o bibli.c
	
clean:	
	rm -f *.o
mrproper: clean
	rm -f navy
