#include "bibli.h"

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
	ANCIENNE VERSION 
	
	On choisi de placer nos bateau toujours au même endroit
	
	OBJ : Placer les bateaux aléatoirement 

*/

// retourne true si on peut placer le bateau a ligne et colonne avec la taille et l'orientation (1 pour verticale et 0 pour horizontal) qu'on lui envoie 
bool placeBateau(struct grid *self,int taille, int colonneDebut, int ligneDebut, int orientation){
	for(int i = 0 ; i < taille ; i++){
		if(orientation == 1){
			if(self->data[colonneDebut][ligneDebut+i].bateauIsHere == true || ligneDebut+i >9){
				return false;
			}
		}else{ // orientation ==0 
			if(self->data[colonneDebut+i][ligneDebut].bateauIsHere == true || colonneDebut+i >9){
				return false;
			}
		}	
	}
	return true;
}

void add_ship(struct grid *self){
	srand(time(NULL));

	char buffer[BUFSIZE];	

	
	//-------------------
	// Bateau de taille 5
	//-------------------
	 
	struct bateau bat5;
	bat5.size=5;
	bool res=false;
	do{
		bat5.colonne = rand()%10;
		bat5.ligne = rand()%10;
		bat5.orientation = rand()%2;

		res = placeBateau(self, bat5.size, bat5.colonne, bat5.ligne, bat5.orientation);
	}while(res == false);
	

	//printf("colonneDebut : %c\n",(intToChar(bat5.colonne)));
	//printf("ligneDebut : %d\n", bat5.ligne);
		

	if(bat5.orientation == 0){		// horizontal
		for (size_t i=0 ; i < bat5.size ; ++i){ // on enregistre notre bateau dans notre grille 
			self->data[bat5.colonne+i][bat5.ligne].bateauIsHere=true;
		}		
		printf("%c%d",intToChar(bat5.colonne),bat5.ligne);
		printf("%c%d\n",intToChar(bat5.colonne+bat5.size-1),bat5.ligne);
		fgets(buffer, BUFSIZE, stdin);
		
		
		
	//printf("colonneFin : %c\n",(intToChar(bat5.colonne+bat5.size-1)));
	//printf("ligneFin : %d\n", bat5.ligne);
	}else{ // vertical 
		for (size_t i=0 ; i < bat5.size ; ++i){ // on enregistre notre bateau dans notre grille 
			self->data[bat5.colonne][bat5.ligne+i].bateauIsHere=true;
		}
		printf("%c%d",intToChar(bat5.colonne),bat5.ligne);
		printf("%c%d\n",intToChar(bat5.colonne),(bat5.ligne+bat5.size-1));
		fgets(buffer, BUFSIZE, stdin);
	//printf("colonneFin : %c\n",(intToChar(bat5.colonne)));
	//printf("ligneFin : %d\n", bat5.ligne+bat5.size-1);
	}
	//printf("orientation %d\n",bat5.orientation);
	
	
	//-------------------
	// Bateau de taille 4
	//-------------------
	
	
	struct bateau bat4;
	bat4.size=4;
	res=false;
	do{
		bat4.colonne = rand()%10;
		bat4.ligne = rand()%10;
		bat4.orientation = rand()%2;

		res = placeBateau(self, bat4.size, bat4.colonne, bat4.ligne, bat4.orientation);
	}while(res == false);

		//printf("colonneDebut : %c\n",(intToChar(bat4.colonne)));
		//printf("ligneDebut : %d\n", bat4.ligne);
		

	if(bat4.orientation == 0){
		for (size_t i=0 ; i < bat4.size ; ++i){ // on enregistre notre bateau dans notre grille 
			self->data[bat4.colonne+i][bat4.ligne].bateauIsHere=true;
		}
		printf("%c%d",intToChar(bat4.colonne),bat4.ligne);
		printf("%c%d\n",intToChar(bat4.colonne+bat4.size-1),bat4.ligne);
		fgets(buffer, BUFSIZE, stdin);
	//	printf("colonneFin : %c\n",(intToChar(bat4.colonne+bat4.size-1)));
	//	printf("ligneFin : %d\n", bat4.ligne);
	}else{
		for (size_t i=0 ; i < bat4.size ; ++i){ // on enregistre notre bateau dans notre grille 
			self->data[bat4.colonne][bat4.ligne+i].bateauIsHere=true;
		}
		printf("%c%d",intToChar(bat4.colonne),bat4.ligne);
		printf("%c%d\n",intToChar(bat4.colonne),bat4.ligne+bat4.size-1);
		fgets(buffer, BUFSIZE, stdin);
	//  printf("colonneFin : %c\n",(intToChar(bat4.colonne)));
	//	printf("ligneFin : %d\n", bat4.ligne+bat4.size-1);
	}
	//	printf("orientation %d\n",bat4.orientation);
	
	
	//-------------------
	// Bateaux de taille 3
	//-------------------
	
	//-------------------
	// Premier
	//-------------------
	struct bateau bat3;
	bat3.size=3;
	res=false;
	do{
		bat3.colonne = rand()%10;
		bat3.ligne = rand()%10;
		bat3.orientation = rand()%2;

		res = placeBateau(self, bat3.size, bat3.colonne, bat3.ligne, bat3.orientation);
	}while(res == false);

		//printf("colonneDebut : %c\n",(intToChar(bat3.colonne)));
		//printf("ligneDebut : %d\n", bat3.ligne);
		

	if(bat3.orientation == 0){
		for (size_t i=0 ; i < bat3.size ; ++i){ // on enregistre notre bateau dans notre grille 
			self->data[bat3.colonne+i][bat3.ligne].bateauIsHere=true;
		}
		printf("%c%d",intToChar(bat3.colonne),bat3.ligne);
		printf("%c%d\n",intToChar(bat3.colonne+bat3.size-1),bat3.ligne);
		fgets(buffer, BUFSIZE, stdin);
	//	printf("colonneFin : %c\n",(intToChar(bat3.colonne+bat3.size-1)));
	//	printf("ligneFin : %d\n", bat3.ligne);
	}else{
		for (size_t i=0 ; i < bat3.size ; ++i){ // on enregistre notre bateau dans notre grille 
			self->data[bat3.colonne][bat3.ligne+i].bateauIsHere=true;
		}
		printf("%c%d",intToChar(bat3.colonne),bat3.ligne);
		printf("%c%d\n",intToChar(bat3.colonne),bat3.ligne+bat3.size-1);
		fgets(buffer, BUFSIZE, stdin);
	//  printf("colonneFin : %c\n",(intToChar(bat3.colonne)));
	//	printf("ligneFin : %d\n", bat3.ligne+bat3.size-1);
	}
	//	printf("orientation %d\n",bat3.orientation);
	
	//-------------------
	// Deuxième
	//-------------------
	
	struct bateau bat3b;
	bat3b.size=3;
	res=false;
	do{
		bat3b.colonne = rand()%10;
		bat3b.ligne = rand()%10;
		bat3b.orientation = rand()%2;

		res = placeBateau(self, bat3b.size, bat3b.colonne, bat3b.ligne, bat3b.orientation);
	}while(res == false);

		//printf("colonneDebut : %c\n",(intToChar(bat3b.colonne)));
		//printf("ligneDebut : %d\n", bat3b.ligne);
		

	if(bat3b.orientation == 0){
		for (size_t i=0 ; i < bat3b.size ; ++i){ // on enregistre notre bateau dans notre grille 
			self->data[bat3b.colonne+i][bat3b.ligne].bateauIsHere=true;
		}
		printf("%c%d",intToChar(bat3b.colonne),bat3b.ligne);
		printf("%c%d\n",intToChar(bat3b.colonne+bat3b.size-1),bat3b.ligne);
		fgets(buffer, BUFSIZE, stdin);		
	//	printf("colonneFin : %c\n",(intToChar(bat3b.colonne+bat3b.size-1)));
	//	printf("ligneFin : %d\n", bat3b.ligne);
	}else{
		for (size_t i=0 ; i < bat3b.size ; ++i){ // on enregistre notre bateau dans notre grille 
			self->data[bat3b.colonne][bat3b.ligne+i].bateauIsHere=true;
		}
		printf("%c%d",intToChar(bat3b.colonne),bat3b.ligne);
		printf("%c%d\n",intToChar(bat3b.colonne),bat3b.ligne+bat3b.size-1);
		fgets(buffer, BUFSIZE, stdin);
	//  printf("colonneFin : %c\n",(intToChar(bat3b.colonne)));
	//	printf("ligneFin : %d\n", bat3b.ligne+bat3b.size-1);
	}
	//	printf("orientation %d\n",bat3b.orientation);
	
	
	//-------------------
	// Bateaux de taille 2
	//-------------------
	
	struct bateau bat2;
	bat2.size=2;
	res=false;
	do{
		bat2.colonne = rand()%10;
		bat2.ligne = rand()%10;
		bat2.orientation = rand()%2;

		res = placeBateau(self, bat2.size, bat2.colonne, bat2.ligne, bat2.orientation);
	}while(res == false);

		//printf("colonneDebut : %c\n",(intToChar(bat2.colonne)));
		//printf("ligneDebut : %d\n", bat2.ligne);
		

	if(bat2.orientation == 0){
		for (size_t i=0 ; i < bat2.size ; ++i){ // on enregistre notre bateau dans notre grille 
			self->data[bat2.colonne+i][bat2.ligne].bateauIsHere=true;
		}
		printf("%c%d",intToChar(bat2.colonne),bat2.ligne);
		printf("%c%d\n",intToChar(bat2.colonne+bat2.size-1),bat2.ligne);
		fgets(buffer, BUFSIZE, stdin);
	//	printf("colonneFin : %c\n",(intToChar(bat2.colonne+bat2.size-1)));
	//	printf("ligneFin : %d\n", bat2.ligne);
	}else{
		for (size_t i=0 ; i < bat2.size ; ++i){ // on enregistre notre bateau dans notre grille 
			self->data[bat2.colonne][bat2.ligne+i].bateauIsHere=true;
		}
		printf("%c%d",intToChar(bat2.colonne),bat2.ligne);
		printf("%c%d\n",intToChar(bat2.colonne),bat2.ligne+bat2.size-1);
		fgets(buffer, BUFSIZE, stdin);
	//  printf("colonneFin : %c\n",(intToChar(bat2.colonne)));
	//	printf("ligneFin : %d\n", bat2.ligne+bat2.size-1);
	}
	//	printf("orientation %d\n",bat2.orientation);
	
	
	/*
	
	for(size_t i = 0 ; i < 10 ; i++){
		for(size_t j = 0 ; j < 10 ; j++){
			if (self->data[j][i].bateauIsHere==true){
				printf("x");
			}else{
				if(self->data[j][i].mineIsHere==true){
					printf("y");
				}else{
					printf("_");
				}	
			}
		}
		printf("\n");
	}
	
	*/
}
	
/*
	On choisi de placer les mines (pas aléatoirement sauf la cinquième)
	On les places dans les endroit qu'on ne POLL pas dans notre premier parcours du tableau adverse
	
*/
void add_mine(struct grid *self, char *tab){
	self->data[3][8].mineIsHere=true;
	self->data[8][3].mineIsHere=true;
	self->data[3][1].mineIsHere=true;
	self->data[1][3].mineIsHere=true;
	
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
	
	

void couler_bateau(char *coord){
	int var_c = charToInt(coord[0]);
	int var_l = coord[1]-'0';
	bool shoot=false;
	//fprintf(stderr,"SALUT SALUT  :::: var_c = %d , var_l = %d \n",var_c,var_l); 
	
	shoot = inline_shot(var_c,var_l,-1,0);	// on tire a gauche 
	//fprintf(stderr,"ici");
	if(inline_shot(var_c,var_l,1,0)){ // on tire a droite  et mets shot a vrai uniquement si on a touche 
		shoot=true;
	}		
	
	if(shoot==false){
		inline_shot(var_c,var_l,0,-1);		//on tire en haut
		inline_shot(var_c,var_l,0,1);		//on tire en bas
	}
}

bool inline_shot(int var_c,int var_l,int add_c,int add_l){
	char serv_ans[BUFSIZE]="";
	bool had_shoot=false;
	int i = 0;
	
	do{
		serv_ans[0]='y';
		if(var_c+add_c >=0 && var_c+add_c <=9 && var_l+add_l >=0 && var_l+add_l <=9 ){
			var_c+=add_c;
			var_l+=add_l;
			fprintf(stderr,"SHOOT %c%d Reponse serv : ",intToChar(var_c),var_l);
			printf("SHOOT\n%c%d\n",intToChar(var_c),var_l);
			fgets(serv_ans, BUFSIZE, stdin);
			fprintf(stderr,"\nDerniere reponse serveur : ");
			fprintf(stderr,serv_ans);
			fprintf(stderr,"Fin shoot\n");
			garbage_ans();
		}
		if(strcmp(serv_ans,"HIT\n")==0){
			fprintf(stderr,"Touche!!!!! \n");
			had_shoot=true;
		}
		
	}while(strcmp(serv_ans,"HIT\n")==0);
	fprintf(stderr,"\ncouler ou rien \n");
	return had_shoot;
}

void garbage_ans(){
	char serv_ans[BUFSIZE];
	
	fprintf(stderr,"Garbage\n");
	fgets(serv_ans, BUFSIZE, stdin);
	fprintf(stderr,serv_ans);
	
	if(strcmp(serv_ans,"MISSED\n")==0|| strcmp(serv_ans,"ATTACK\n")==0){
		fgets(serv_ans, BUFSIZE, stdin);
		fprintf(stderr,serv_ans);
	}
	fprintf(stderr,"Fin Garbage\n");
}

