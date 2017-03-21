
#include "marche_jarvis.h"

// Marche de Jarvis 

void jarvis_march(const struct vecset *in, struct vecset *out){
	// F premier point de l'enveloppe (FIRST)
	// C  le point courant
	// N le point suivant 
	// S ensemble de point 
	
	if(out != NULL){
		out = NULL;
	}
	
	struct vec F; // le point le plus a gauche 
	vecset_min(in,comparaison_jarvis, NULL); 
	
	struct vec C;
	C = F;
	
	do{
		vecset_add(out,C);
		struct vec N; 
		N = in->data[0];
		for (size_t i = 0 ; i < in->size ; ++i){
			if(is_left_turn(&C,&in->data[i],&N)){
				N = in->data[i];
			}
		}
		C=N; 
		
	}while((F.x != C.x) &&(F.y != C.y));
}

