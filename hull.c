#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <assert.h>
#include <stdbool.h>


#include "graham.h"
#include "marche_jarvis.h"

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
	
	for (size_t i = 0; i < count; ++i) {
		struct vec p;
		fgets(buffer, BUFSIZE, stdin);
		char *endptr = buffer;
		p.x = strtod(endptr, &endptr);
		p.y = strtod(endptr, &endptr);
		
		vecset_push(in,p); 
	}	
	
	//appel de jarvis
	//jarvis_march(in,out);
	
	// appel de graham 
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
