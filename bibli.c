#include "bibli.h"

// PROJET ALGO 
// BOISSON Romain
// PAQUETTE Emile

// Bibliothèque de fonctions 

/*	
	Version 1 : On placait les bateaux de manière fixe, on partait du principe que on ne pouvait pas stocker les coordonnées des bateaux entre deux partie, ce n'était donc pas nécessaire de changer la position de nos bateaux
	Version 2 : On place les bateaux de manière aléatoire : mais on remarque une perte de performance, avec la version 1, on gagnait en moyenne 975 fois sur 1000 contre le navy-dumb, avec les bateaux complètement aléatoire, on passe a 800 de moyenne, on pert donc 175 partie a cause du fait que nos bateaux sont aléatoire.
	Version 3 : On ecrit en dur des jeux de coordonnées, on stocke les différentes coordonnées dans un tableau, et au debut de la partie on choisi une disposition de maniere aléatoire

	Tableau permettant de stocker nos nbStrat stratégie (on peut visualiser les différentes flottes sur l'image fourni dans nos dossier : starts.ods) On choisi, dans nos 3 stratégie de ne jamais placé les bateaux sur les même coord qu'avant : on fait cela afin d'eviter de tomber contre un bot qui mémorise la position des bateaux et qui place des mines a ces coord
*/
char buffer[BUFSIZE];


void add_ship(){
	char *placement[] ={"J5J9C4C7I0I2A9C9F9G9","E4I4A5A8D8F8I7I9A0B0","J0J4E6H6B1B3B6B8E0F0"};

	int nbStrat = 3; 		// on choisi de faire 3 disposition différentes.
	srand(time(NULL));

	int choixStrat = rand()%(nbStrat-1); // on choisi la strat pour la partie actuelle

	for(int i=0;i<20;++i){
		if(i%4==0&&i!=0){
			printf("\n");
			fgets(buffer, BUFSIZE, stdin);
		}
		printf("%c",placement[choixStrat][i]);
	}
	printf("\n");
	fgets(buffer, BUFSIZE, stdin);
}

	
/*
	On choisi de placer les mines (pas aléatoirement sauf la cinquième)
	On les places dans les endroit qu'on ne POLL pas dans notre premier parcours du tableau adverse
	
*/
void add_mine(){
	srand(time(NULL));
	int x = rand()%2+4; 
	int y = rand()%2+4;
	int tab[10];
	// on stocke les mines dans un tableau tab. tab1 et tab2 correspond au coord de la mine 1
	tab[0] = 2;
	tab[1] = 2;
	tab[2] = 2;  
	tab[3] = 7;
	tab[4] = 7;
	tab[5] = 2;
	tab[6] = 7;
	tab[7] = 7;
	tab[8] = x;
	tab[9] = y;
	
	// affichage des mines 	
	for (int i = 0 ; i < 10 ; i+=2){
			printf("%c%d\n",intToChar(tab[i]),tab[i+1]);		
	}	
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
