#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#define BUFSIZE 256


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
	//int orientation; // 1 pour verticale, 0 pour horizontal 
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
void init_grid(struct grid *self){
	for(size_t i = 0 ; i < 10 ; i++){
		for(size_t j = 0 ; j < 10 ; j++){
			self->data[i][j].bateauIsHere=false;
			self->data[i][j].mineIsHere=false;
		}
	}
}

/* 	
	On choisi de placer nos bateau toujours au même endroit
*/
void add_ship(struct grid *self){
	// bateau de 5 
	struct bateau bat5;
	bat5.colonne = 5;
	bat5.ligne = 0;
	bat5.size=5;
	//bat5.orientation=1;
	bat5.nbToucher=0;
	
	
	for (size_t i=0 ; i < bat5.size ; ++i){
		self->data[bat5.ligne][bat5.colonne+i].bateauIsHere=true;
	}
	
	//bateau de 4 
	struct bateau bat4;
	bat4.colonne = 0;
	bat4.ligne = 6;
	bat4.size=4;
	//bat4.orientation=1;
	bat4.nbToucher=0;
	
	
	for (size_t i = 0 ; i < bat4.size ; ++i){
		self->data[bat4.ligne+i][bat4.colonne].bateauIsHere=true;
	}
	
	//bateau de 3 
	struct bateau bat3A;
	bat3A.colonne = 1;
	bat3A.ligne = 1;
	bat3A.size=3;
	//bat3A.orientation=1;
	bat3A.nbToucher=0;
	
	
	//bateau de 3 
	struct bateau bat3B;
	bat3B.colonne = 7;
	bat3B.ligne = 8;
	bat3B.size=3;
	//bat3A.orientation=1;
	bat3B.nbToucher=0;
	
	
	for (size_t i = 0 ; i < bat3A.size ; ++i){
		self->data[bat3A.ligne+i][bat3A.colonne].bateauIsHere=true;
		self->data[bat3B.ligne][bat3B.colonne+i].bateauIsHere=true;
	}
	
	//bateau de 3 
	struct bateau bat2;
	bat2.colonne = 4;
	bat2.ligne = 9;
	bat2.size=2;
	//bat2.orientation=1;
	bat2.nbToucher=0;
	
	
	for (size_t i = 0 ; i < bat3A.size ; ++i){
		self->data[bat2.ligne][bat2.colonne+i].bateauIsHere=true;
	}

	
	for(size_t i = 0 ; i < 10 ; i++){
		for(size_t j = 0 ; j < 10 ; j++){
			if (self->data[i][j].bateauIsHere==true){
				printf("x");
			}else{
				if(self->data[i][j].mineIsHere==true){
					printf("y");
				}else{
					printf("_");
				}	
			}
		}
		printf("\n");
	}
	
	
}
	
/*
	On choisi de placer les mines (pas aléatoirement) et on les places dans le terrain enemis pour ne pas tirer sur nos propre mines car on perdrait un tir et on détruirait notre propre mine
	STRAT 1 : on place 4 min toujours de la même facon, et la derniere aléatoirement dans les 4 cases du milieu
	
	
*/
void add_mine(struct grid *self){
	self->data[2][2].mineIsHere=true;
	self->data[2][7].mineIsHere=true;
	self->data[7][2].mineIsHere=true;
	self->data[7][7].mineIsHere=true;
	
	srand(time(NULL));
	int x = rand()%2+4; 
	int y = rand()%2+4;
	//printf("%d\n",x);
	//printf("%d\n",y);
	
	self->data[x][y].mineIsHere=true;
	/*
	
	printf("%d\n",self->data[2][2].mineIsHere);
	printf("%d\n",self->data[2][7].mineIsHere);
	printf("%d\n",self->data[7][2].mineIsHere);
	printf("%d\n",self->data[7][7].mineIsHere);
	
	printf("%d\n",self->data[x][y].mineIsHere);
	
	*/
}


	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
