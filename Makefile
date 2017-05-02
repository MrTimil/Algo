CFLAG=-c -Wall -std=c99 -g -o 

all: navy
navy: bibli.o navy.o 
	gcc -Wall -std=c99 -g -o navy $^ -lm

navy.o: navy.c bibli.h 
	gcc $(CFLAG) navy.o $<
	
bibli.o: bibli.c bibli.h
	gcc $(CFLAG) bibli.o bibli.c
	
clean:
	rm -f *.o
mrproper: clean
	rm -f navy
