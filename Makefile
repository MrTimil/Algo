CFLAG=-c -Wall -std=c99 -g -o


all: hull clean
hull: geo_struc.o hull.o 
	gcc -Wall -std=c99 -g -o hull $^

hull.o: hull.c geo_struc.h 
	gcc $(CFLAG) hull.o $<
	
geo_struc.o: geo_struc.c geo_struc.h
	gcc $(CFLAG) geo_struc.o geo_struc.c

clean:
	rm -f *.o
mrproper: clean
	rm -f hull
	
