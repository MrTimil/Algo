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
	On choisi de placer nos bateau toujours au même endroit
*/
void add_ship(struct grid *self){
char buffer[BUFSIZE];
	// bateau de 5 
	struct bateau bat5;
	bat5.colonne = 5;
	bat5.ligne = 0;
	bat5.size=5;
	bat5.orientation=0;
	bat5.nbToucher=0;
	
	
	for (size_t i=0 ; i < bat5.size ; ++i){
		self->data[bat5.ligne][bat5.colonne+i].bateauIsHere=true;
	}
	
	printf("%c%d",intToChar(bat5.colonne),bat5.ligne);
	printf("%c%d\n",intToChar(bat5.colonne+bat5.size-1),bat5.ligne);
	fgets(buffer, BUFSIZE, stdin);
	//bateau de 4 
	struct bateau bat4;
	bat4.colonne = 0;
	bat4.ligne = 6;
	bat4.size=4;
	bat4.orientation=1;
	bat4.nbToucher=0;
	
	
	for (size_t i = 0 ; i < bat4.size ; ++i){
		self->data[bat4.ligne+i][bat4.colonne].bateauIsHere=true;
	}
	
	printf("%c%d",intToChar(bat4.colonne),bat4.ligne);
	printf("%c%d\n",intToChar(bat4.colonne),(bat4.ligne+bat4.size-1));
	fgets(buffer, BUFSIZE, stdin);
	//bateau de 3 
	struct bateau bat3A;
	bat3A.colonne = 1;
	bat3A.ligne = 1;
	bat3A.size=3;
	bat3A.orientation=1;
	bat3A.nbToucher=0;
	
	
	//bateau de 3 
	struct bateau bat3B;
	bat3B.colonne = 7;
	bat3B.ligne = 8;
	bat3B.size=3;
	bat3A.orientation=0;
	bat3B.nbToucher=0;
	
	
	for (size_t i = 0 ; i < bat3A.size ; ++i){
		self->data[bat3A.ligne+i][bat3A.colonne].bateauIsHere=true;
		self->data[bat3B.ligne][bat3B.colonne+i].bateauIsHere=true;
	}
	
	printf("%c%d",intToChar(bat3A.colonne),bat3A.ligne);
	printf("%c%d\n",intToChar(bat3A.colonne),(bat3A.ligne+bat3A.size-1));
	fgets(buffer, BUFSIZE, stdin);
	printf("%c%d",intToChar(bat3B.colonne),bat3B.ligne);
	printf("%c%d\n",intToChar(bat3B.colonne+bat3B.size-1),bat3B.ligne);
	fgets(buffer, BUFSIZE, stdin);
	//bateau de 2 
	struct bateau bat2;
	bat2.colonne = 4;
	bat2.ligne = 9;
	bat2.size=2;
	bat2.orientation=0;
	bat2.nbToucher=0;
	
	
	for (size_t i = 0 ; i < bat2.size ; ++i){
		self->data[bat2.ligne][bat2.colonne+i].bateauIsHere=true;
	}

	printf("%c%d",intToChar(bat2.colonne),bat2.ligne);
	printf("%c%d\n",intToChar(bat2.colonne+bat2.size-1),bat2.ligne);
	fgets(buffer, BUFSIZE, stdin);
	// affiche les bateau et les mines
	/*
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
	*/
	
}
	
/*
	On choisi de placer les mines (pas aléatoirement) et on les places dans le terrain enemis pour ne pas tirer sur nos propre mines car on perdrait un tir et on détruirait notre propre mine
	STRAT 1 : on place 4 min toujours de la même facon, et la derniere aléatoirement dans les 4 cases du milieu
	
	
*/
void add_mine(struct grid *self, char *tab){
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
