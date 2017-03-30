CFLAG=-c -Wall -std=c99 -g -o 

all: hull clean
hull: geo_struc.o lib.o graham.o marche_jarvis.o hull.o 
	gcc -Wall -std=c99 -g -o hull $^ -lm

hull.o: hull.c geo_struc.h lib.h
	gcc $(CFLAG) hull.o $<
	
geo_struc.o: geo_struc.c geo_struc.h
	gcc $(CFLAG) geo_struc.o geo_struc.c
	
lib.o: lib.c lib.h geo_struc.h
	gcc $(CFLAG) lib.o lib.c

marche_jarvis.o: marche_jarvis.c marche_jarvis.h lib.h
	gcc $(CFLAG) marche_jarvis.o marche_jarvis.c 
	
graham.o: graham.c graham.h lib.h
	gcc $(CFLAG) graham.o graham.c
	
clean:
	rm -f *.o
mrproper: clean
	rm -f hull
	
