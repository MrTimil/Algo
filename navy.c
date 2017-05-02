#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bibli.h"
#define BUFSIZE 256



int main() {
	
	setbuf(stdout, NULL);
	char buffer[BUFSIZE];
	
	// déclaration de la grille de jeu 
	struct grid grille;
	init_grid(&grille);
 	
	// mines
	
	// déclaration du tableau contenant la position des mines 
	char tabMine[10];
	
	add_mine(&grille,tabMine);
	
	for (int i = 0 ; i < 10 ; i+=2){
			printf("%c%d\n",intToChar(tabMine[i]),tabMine[i+1]);		
	}
	
	// ships
	
	add_ship(&grille);
		
	/*
	
	for (;;) {
		printf("SHOOT\n"); // or POOL or MOVE
		printf("D2\n");
		fgets(buffer, BUFSIZE, stdin);
		assert(strcmp(buffer, "MISS\n") == 0);
		fgets(buffer, BUFSIZE, stdin); // NOTHING or ATTACK
	}
	return EXIT_SUCCESS;
 	*/

}
