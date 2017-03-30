#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <assert.h>
#include <stdbool.h>


#include "graham.h"

#define BUFSIZE 256
// BOISSON Romain 
// PAQUETTE Emile 
// Projet d'Algorithme 

//sans utiliser les generator et viewer ./hull <fich.txt 2>hull.log
// en les utilisant : ./hull-generator 100 | ./hull-viewer ./hull



int main() {
	setbuf(stdout, NULL); // avoid buffering in the output
	char buffer[BUFSIZE];
	fgets(buffer, BUFSIZE, stdin);
	size_t count = strtol(buffer, NULL, 10);
	
	struct vecset *in=malloc(sizeof(struct vecset));
	struct vecset *out=malloc(sizeof(struct vecset));
	vecset_create(in);
	vecset_create(out);
	/*
	struct vec p4;
	struct vec p5;
	struct vec p6;
	p4.x= 1;
	p4.y= 1;
	
	p5.x= 5;
	p5.y= 5;
	
	p6.x= 7;
	p6.y= 3;
	*/
	// FIN DES TESTS
	
	for (size_t i = 0; i < count; ++i) {
		struct vec p;
		fgets(buffer, BUFSIZE, stdin);
		char *endptr = buffer;
		p.x = strtod(endptr, &endptr);
		p.y = strtod(endptr, &endptr);
		
		
		vecset_push(in,p); 
	}	
	graham_scan(in,out);
	
	printf("%zu\n",out->size);
	for(int i=0;i<out->size;++i){
		printf("%f %f\n",out->data[i].x,out->data[i].y);
	}
	
	vecset_destroy(in);
	vecset_destroy(out);
	free(in);
	free(out);
	return 0;
}



