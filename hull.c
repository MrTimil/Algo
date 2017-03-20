#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <assert.h>
#include <stdbool.h>
#define BUFSIZE 256
#include "geo_struc.h"
// BOISSON Romain 
// PAQUETTE Emile 
// Projet d'Algorithme 

//sans utiliser les generator et viewer ./hull <fich.txt 2>hull.log
// en les utilisant : ./hull-generator 100 | ./hull-viewer ./hull



int main() {
	// TEST  
	struct vec p1;
	p1.x=1;
	p1.y=2;
	struct vec p2;
	p2.x=5;
	p2.y=5;
	//printf("%f",dot(&p1,&p2));
	struct vec p3;
	p3.x=2;
	p3.y=4;
	if(is_left_turn(&p1,&p2,&p3)){
		printf("Oui");
	}else{
		printf("Non");
	}
	
	
	setbuf(stdout, NULL); // avoid buffering in the output
	char buffer[BUFSIZE];
	fgets(buffer, BUFSIZE, stdin);
	size_t count = strtol(buffer, NULL, 10);
	for (size_t i = 0; i < count; ++i) {
		struct vec p;
		fgets(buffer, BUFSIZE, stdin);
		char *endptr = buffer;
		p.x = strtod(endptr, &endptr);
		p.y = strtod(endptr, &endptr);
		
		
		// then do something with p
		//on ajoute p a vecset, on complete le vecset in 
		// appel de 1 des 3 algos principaux
		// créer un nouveau vecsrt : le vecset out qui contient tout les points appartenant a l'enveloppe 
		// envoyer sur la sortie standard le nombre de points de l'enveloppe et sur chaque ligne, les coordonnées des points 
	}	
	return 0;
}



