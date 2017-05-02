#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#define BUFSIZE 256


// Structure 
// dans le main struct state tab1[10][10];
// la struct state permet de décrire une case 
struct state{
	int nbTir; 	
	bool bateauIsHere;
	bool mineIsHere;
	
};
// permet de décrire le bateau
struct bateau{
	int ligne;
	int colonne;
	int size;
	int direction;
	int nbToucher;
};

struct grid{
int size;
struct state data[10][10];
};

// Fonctions 


// création des bateaux 

/* flottes :	1 bateau de 5
				1 bateau de 4
				2 bateau de 3
				1 bateau de 2 
				
*/



/* 	
	fonction qui choisi une case au hasard
	on test sur un peu insérer le 1 er bateau dans un direction choisie aléatoirement (entre 1 et 4)
	si oui alors on l'insere dans notre terrain, sinon on essai une autre direction, quand on a usé les 4 directions possible, on retire une case différente aléatoirement
*/
void add_ship(struct state *self){
	
}
	
/*
	On choisi de placer les mines (pas aléatoire, établir une strats) et on les places dans le terrain enemis pour ne pas tirer sur nos propre mines car on perdrait un tir et on détruirait notre propre mine
	STRAT 1 : on place 4 min toujours de la même facon, et la derniere aléatoirement dans les 4 cases du milieu
	
	
*/
void add_mine(struct grid *self){
	self->data[2][2].mineIsHere=true;
	self->data[2][7].mineIsHere=true;
	self->data[7][2].mineIsHere=true;
	self->data[7][7].mineIsHere=true;
	
	srand(time(NULL));
	int x = rand()%4; 
	printf("%d",x);
}

char intToChar(int value){
	switch(value){
		case 0 : return 'A';break;
		case 1 : return 'B';break;
		case 2 : return 'C';break;
		case 3 : return 'D';break;
		case 4 : return 'E';break;
		case 5 : return 'F';break;
		case 6 : return 'G';break;
		case 7 : return 'H';break;
		case 8 : return 'I';break;
		default: return 'J';break;
	}
	return '-'; // ne l'attendra jamais
}

int charToInt(char value){
	switch(value){
		case 'A' : return 0;break;
		case 'B' : return 1;break;
		case 'C' : return 2;break;
		case 'D' : return 3;break;
		case 'E' : return 4;break;
		case 'F' : return 5;break;
		case 'G' : return 6;break;
		case 'H' : return 7;break;
		case 'I' : return 8;break;
		default: return 9;break;
	}
	return 10; // ne l'attendra jamais
}

	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
