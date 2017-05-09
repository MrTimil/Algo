#ifndef BIBLI_H
#define BIBLI_H

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
	int colonne; // x
	int ligne; // y  
	int size;
	int orientation; // 1 pour verticale, 0 pour horizontal 
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
* Initialisation de la grille, on met les booleen au valeur voulu
*
*/
void init_grid(struct grid *self);




/* 	
	fonction qui choisi une case au hasard
	on test sur un peu insérer le 1 er bateau dans un direction choisie aléatoirement (entre 1 et 4)
	si oui alors on l'insere dans notre terrain, sinon on essai une autre direction, quand on a usé les 4 directions possible, on retire une case différente aléatoirement
*/
void add_ship(struct grid *self);
	
/*
	On choisi de placer les mines (pas aléatoire, établir une strats) et on les places dans le terrain enemis pour ne pas tirer sur nos propre mines car on perdrait un tir et on détruirait notre propre mine
	STRAT 1 : on place 4 min toujours de la même facon, et la derniere aléatoirement dans les 4 cases du milieu
	
	
*/
void add_mine(struct grid *self, char *tab);


/*
 Permet de convertir les lettres A a J en entier, permet un developpement plus simple sans augementer la complexité 
*/	
char intToChar(int value);
int charToInt(char value);
	

bool is_ship(char *ch);
bool is_hit(char *ch);
void couler_bateau(char *coord);
bool inline_shot(int var_c,int var_l,int add_c,int add_l);
void garbage_ans();

#endif	
