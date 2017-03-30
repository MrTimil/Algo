#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <time.h> 
#include "marche_jarvis.h"

// Marche de Jarvis 

void jarvis_march(const struct vecset *in, struct vecset *out){
	srand(time(NULL)); // initialisation de rand
	assert(in);
	assert(out);
	
	// F premier point de l'enveloppe (FIRST)
	const struct vec *F = vecset_min(in,&comparaison_jarvis, NULL);
	

	// C  le point courant
	const struct vec *C;
	C = F;
	const struct vec *N;
	do{
		vecset_add(out,*C);
		N=C;
		// while n != de courant, prendre un point au hasard 
		while (C == N){
			N = &in->data[rand()%(in->size)];
		}
		
		for (size_t i = 0 ; i < in->size ; ++i){
			if(is_left_turn(C,&in->data[i],N)){
				N = &in->data[i];
			}
		}
		C=N; 
	}while(F!=C);
}

