#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "bibli.h"

#define BUFSIZE 256

// PROJET ALGO 
// BOISSON Romain
// PAQUETTE Emile

int main(){
	setbuf(stdout, NULL);
	char buffer[BUFSIZE];
	char buf[BUFSIZE];
	char coordonnerPremierPollTouche[BUFSIZE];
	
	srand(time(NULL));
	
	char *scan[] = {"B1","F1","I1","B5","F5","I5","B8","F8","I8","D1","D5","D8","B3","F3","I3"};
	
	int jeu=1;   // permet d'avoir la boucle de jeu 
 	int i=0; 	 // compteur pour le choix des coord de POLL
 	int shoot=0; // permet de savoir si on veut tirer ou pas, c'est déterminé au tour de boucle d'avant
 	int pollSET=0; // permet de savoir qu'on a touché au coup précédent et donc que le prochain shoot sera a ces coord
 	int  pollFail=0; // permet de savoir si le poll précédent a réussi ou non
 	int pasEncoreCouler=1; // permet de savoir si on a déja coulé un bateau ou non 
 	int tabCoordDebutBateau=0; // permet de sauvegarder les coord du premier poll pour le bateau qu'on essaie de couler actuellement

	// envoi au serveur des position des mines et des bateaux
	add_mine();
	add_ship();
		
	// attente du "start" du server
	do{
		fgets(buffer, BUFSIZE, stdin);
	}while(strcmp(buffer,"START\n")!=0);
	
	fprintf(stderr,"START\n");
 
 	// Stratégie : 
 	/* 
 	On poll selon les coord du tableau de poll, si on touche, on repoll sur la même coord, 
 	jusqu'a ce que le poll ne réussisse pas, puis on recommence a poll selon le tableau
 	Amélioration : la premiere fois que le poll ne répond rien, on repoll a la premiere coord qui a touchée, 
 	(cas d'un bateau qu'on aurait touché au milieu et qu'on est parti a droite avec les polls et donc on ne detecte pas la gauche du bateau,
 	sinon on refait un tour de boucle sans couler le bateau et on pert des actions pour rien.
 */
 
 	// boucle de jeu
	do{
		fprintf(stderr, "Tour de boucle\n");
		
		//----------------------
		//Action de notre joueur 
		//----------------------
		
		// choix entre POLL ou SHOOT
		// Le move étant trop punitif (perte d'un bateau si on se déplace sur une mine), nous avons décidé de ne pas l'implémenter 
		
		if(shoot ==1){ 	// si le poll réussit au tour d'avant, on shoot sur les coord que nous a renvoyer le poll
			shoot=0;	
			
			fprintf(stderr,"On va tirer : %s\n",buf);	// information dans le log
			printf("SHOOT\n");							
			printf("%s",buf); // on tire aux coordonnées que nous a renvoyées le POLL au tour d'avant
			pollSET = 1; // on enregistre le fait qu'on ait touché et donc que le poll suivant doit etre a ces coord 
		}else{
			if(pollFail ==1 && tabCoordDebutBateau != 0){ // on poll sur la premier coord qu'on a poll et qui a donné un résultat
				fprintf(stderr,"POLL\n%s\n",coordonnerPremierPollTouche);	
				printf("POLL\n%s\n",coordonnerPremierPollTouche);	
				pollFail++;
				pasEncoreCouler=1;
			}else if(pollSET ==0){								// si on a pas effectué de tir au tour précédent, alors on continue de POLL
				fprintf(stderr,"POLL\n%s\n",scan[i%15]);		
				printf("POLL\n%s\n",scan[i%15]);				
				i++;
			}else{												// sinon on POLL la ou on vient de tirer 
				fprintf(stderr,"POLL\n%s\n",buf);
				printf("POLL\n%s",buf);
				pollSET=0;
				pollFail=0;
			}
			
			if(pollFail ==2){									// On a couler le bateau 
				pollFail = 0;									// on reset les valeurs pour permettre de recommencer a POLL
				pollSET =0;
				tabCoordDebutBateau=0;
			}
		}
		
		//----------------------
		//Réception des infos du serveur 
		//----------------------
		
		fgets(buffer,BUFSIZE,stdin);	
		if (strcmp(buffer, "HIT\n") == 0){
			// On a touché un bateau
		}else if(strcmp(buffer, "MISS\n") == 0){
			// On a raté un tir 
		}else if(strcmp(buffer, "SHIP\n") == 0){
			// On lit la coordonnée du bateau renvoyé par le serveur
			fgets(buf, BUFSIZE, stdin);
			fprintf(stderr, "\t%s", buf);

			// on sauvegarde le fait qu'on veut shoot 
			shoot=1;
		 
			 if(pasEncoreCouler==1 && tabCoordDebutBateau==0){
			 	for(int j = 0 ; j < BUFSIZE ; j++ ){
			 		coordonnerPremierPollTouche[j]=buf[j];
			 	}
			 	pasEncoreCouler=0;
			 }
		}else if(strcmp(buffer, "EMPTY\n") == 0){
		  // le sondage n'a pas trouvé de bateau
		  fprintf(stderr, "PAS DE BATEAU ici : \t%s", buf);
		  pollFail++;
		}else if(strcmp(buffer, "OK\n") == 0){
		  // MOVE a réussi
		}else if(strcmp(buffer, "BOOM\n") == 0){
		  // bateau bougé a touché une mine
		}else{
		  // on poll 
		}
 
		//----------------------
		//Réception des infos sur l'adversaire 
		//----------------------
		
		
		fgets(buffer, BUFSIZE, stdin);
		fprintf(stderr, "Adversaire: ");
		fprintf(stderr, "%s", buffer);
		if(strcmp(buffer, "MISSED\n") == 0){
			fgets(buffer, BUFSIZE, stdin);
		}else if(strcmp(buffer, "ATTACK\n") == 0){
			fgets(buffer, BUFSIZE, stdin);
		}
  	}while(jeu == 1);

return EXIT_SUCCESS;
}
