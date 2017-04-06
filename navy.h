#ifndef NAVY_H
#define NAVY_H

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>

#define TONY NULL


// Structure 

// la struct state permet de décrire une case 
struct state { 
	int ligne;
	int colonne;
	int nbTir; 	
	bool bateauIsHere;
	bool mineIsHere;
	
};
// permet de décrire le bateau
struct bateau {
	int ligne;
	int colonne;
	int size;
	int direction;
	int nbToucher;
};

 
// fonctions 
 

 
 


#endif 
