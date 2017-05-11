#ifndef BIBLI_H
#define BIBLI_H

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#define BUFSIZE 256

// Fonctions 

/*
	Envoie les bateaux au serveur
*/
void add_ship();
/* 
STRAT 1 : on place 4 min toujours de la même façon, et la derniere aléatoirement dans les 4 cases du milieu. Les mines sont placées de manière optimisée en fonction des POLL que l'on fait.
*/
void add_mine();
/*
 Permet de convertir les lettres A a J en entier, permet un developpement plus simple sans augmenter la complexité 
*/	
char intToChar(int value);
int charToInt(char value);
	

#endif	
