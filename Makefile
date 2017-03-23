CFLAG=-c -Wall -std=c99 -g -o

all: hull clean
hull: geo_struc.o EXO2.o graham.o marche_jarvis.o hull.o 
	gcc -Wall -std=c99 -g -o hull $^

hull.o: hull.c geo_struc.h EXO2.h
	gcc $(CFLAG) hull.o $<
	
geo_struc.o: geo_struc.c geo_struc.h
	gcc $(CFLAG) geo_struc.o geo_struc.c
	
EXO2.o: EXO2.c EXO2.h geo_struc.h
	gcc $(CFLAG) EXO2.o EXO2.c

marche_jarvis.o: marche_jarvis.c marche_jarvis.h EXO2.h
	gcc $(CFLAG) marche_jarvis.o marche_jarvis.c 
	
graham.o: graham.c graham.h EXO2.h
	gcc $(CFLAG) graham.o graham.c
	
clean:
	rm -f *.o
mrproper: clean
	rm -f hull
	
