#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "bibli.h"

#define BUFSIZE 256



int main() {
	setbuf(stdout, NULL);
	char buffer[BUFSIZE];
	char buf[BUFSIZE];
	char coordonnerPremierPollTouche[BUFSIZE];
	
	srand(time(NULL));
	
	char *scan[] = {"B1","F1","I1","B5","F5","I5","B8","F8","I8","D1","D5","D8","B3","F3","I3"};
	
	int jeu =1;   // permet d'avoir la boucle de jeu 
 	int i =0; 	  // compteur pour le choix des coord de POLL
 	int shoot = 0; // permet de savoir si on veut tirer ou pas, c'est déterminer au tour de boucle d'avant
 	int pollSET =0; // permet de savoir qu'on a toucher au coup précédent et donc que le prochain shoot sera a ces coord
 	int  pollFail=0; // permet de savoir si le poll précedent a réussi ou non
 	int pasEncoreCouler=1; // permet de savoir si on a déja couler un bateau ou non 
 	int tabCoordDebutBateau=0; // permet de sauvegarder les coord du premier poll pour le bateau qu'on essai de couler actuellement
	// déclaration de la grille de jeu 
	struct grid grille;
	// initialisation de la grille 
	init_grid(&grille);
	
	// déclaration du tableau contenant la position des mines 
	char tabMine[10];
	
	// ajout des mines dans la grille
	add_mine(&grille,tabMine);
	
	for (int i = 0 ; i < 10 ; i+=2){
			printf("%c%d\n",intToChar(tabMine[i]),tabMine[i+1]);		
	}
	
	// ajout des ships dans la grille
	
	add_ship(&grille);
		
	do{
		fgets(buffer, BUFSIZE, stdin);
	}while(strcmp(buffer,"START\n")!=0);
	
	fprintf(stderr,"START\n");
 
 	
	do{
		fprintf(stderr, "Tour de boucle\n");
		//Action de notre joueur 
		
		// choix entre poll , shoot (ou move) 
		
		if(shoot ==1){ 	// si le poll réussit au tour d'avant, on shoot sur les coord que renvoi le poll
			shoot=0;	
			
			// pour le moment, on poll selon les coord du tableau de poll, si on touche, on repoll sur la même coord, jusqu'a ce que le poll ne réussisse pas, puis on recommence a poll selon le tableau
			
			// piste d'amélioration : la premiere fois que le poll ne repond rien, on repoll a la premier coord qui a touché, (cas d'un bateau quon aurait toucher au milieu et qu'on est partie a droite avec les polls et donc on ne detecte pas la gauche du bateau, sinon on refait un tour de boucle sans couler le bateau et on pert des actions pour rien
		
			fprintf(stderr,"On va tirer : %s\n",buf);	// information dans le log
			printf("SHOOT\n");
			printf("%s",buf);
		
			// on tire au coordonnées qu'on a enregistrer
			// on enregistre le fait qu'on ai toucher et donc que le poll suivant doit etre a ces coord 
			pollSET = 1;
		}else{
			if(pollFail ==1 && tabCoordDebutBateau != 0){ // on poll sur la premier coord qu'on a poll et qui a donner un résultat
				fprintf(stderr,"POLL\n%s\n",coordonnerPremierPollTouche);	
				printf("POLL\n%s\n",coordonnerPremierPollTouche);	
				pollFail++;
				pasEncoreCouler=1;
			}else if(pollSET ==0){
				fprintf(stderr,"POLL\n%s\n",scan[i%15]);		// on poll selon le tableau (ratissage de la grille)
				printf("POLL\n%s\n",scan[i%15]);				// on scan
				i++;
			}else{												// on poll la ou on vient de tirer 
				fprintf(stderr,"POLL\n%s\n",buf);		
				printf("POLL\n%s",buf);	
				pollSET=0;
				pollFail=0;					
			}
			
			if(pollFail ==2){	// On a couler le bateau 
				pollFail = 0;
				pollSET =0;
				tabCoordDebutBateau=0;
			}
		}
		//fprintf(stderr,"coord : %s",buf);
	
		//Réception des infos du serveur 
		fgets(buffer,BUFSIZE,stdin);	
		if (strcmp(buffer, "HIT\n") == 0){
		  // On a touché un bateau
		  // on recupère les coordonnée du shoot 
		  // fgets(buf,BUFSIZE,stdin);				
		  //couler_bateau(buffer);
		}
		else if(strcmp(buffer, "MISS\n") == 0){
		  // On a raté un tir 
		  
		}
		else if(strcmp(buffer, "SHIP\n") == 0){
		  // On lit la coordonnee du bateau renvoye par le serveur
		  fgets(buf, BUFSIZE, stdin);
		  fprintf(stderr, "\t%s", buf);
		  
		// on sauvegarde le fait qu'on veut shoot 
		 shoot =1;
		 
		 if(pasEncoreCouler==1 && tabCoordDebutBateau==0){
		 	for(int j = 0 ; j < BUFSIZE ; j++ ){
		 		coordonnerPremierPollTouche[j]=buf[j];
		 	}
		 	pasEncoreCouler=0;
		 }
	
		}
		else if(strcmp(buffer, "EMPTY\n") == 0){
		  // le sondage n'a pas trouvé de bateau
		  fprintf(stderr, "PAS DE BATEAU ici : \t%s", buf);
		  pollFail++;
		}
		else if(strcmp(buffer, "OK\n") == 0){
		  // MOVE a réussi
		}
		else if(strcmp(buffer, "BOOM\n") == 0){
		  // bateau bougé a touché une mine
		}
		else{
		  // on poll 
		}

		// Réception des infos sur l'adversaire 
		fgets(buffer, BUFSIZE, stdin);
		fprintf(stderr, "Adversaire: ");
		fprintf(stderr, "%s", buffer);
		if(strcmp(buffer, "KABOOM\n") == 0){
		  
		}
		else if(strcmp(buffer, "MISSED\n") == 0){
		  fgets(buffer, BUFSIZE, stdin);

		}
		else if(strcmp(buffer, "ATTACK\n") == 0){
		  fgets(buffer, BUFSIZE, stdin);
		}
		
		fprintf(stderr,"\n\nmanche\n");
  }while(jeu == 1);
return EXIT_SUCCESS;

}
