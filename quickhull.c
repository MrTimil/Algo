#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <time.h> 
#include "quickhull.h"

// Marche de Jarvis 

void quickhull(const struct vecset *in, struct vecset *out){
	
}

struct vecset *findhull(const struct vecset *self,const struct vec *x,const struct vec *y){
	if(self==NULL){
		return NULL;
	}
	struct vec *M=malloc(sizeof(struct vec)); //=farthest_point(x,y);
	struct vecset *S1=malloc(sizeof(struct vecset));
	struct vecset *S2=malloc(sizeof(struct vecset));
	
	struct vecset *in2=malloc(sizeof(struct vecset));
	vecset_create(in2);
	vecset_create(S1);
	vecset_create(S2);
	
	for(int i=0;i<self->size;++i){
		if(self->data + i != M){
			vecset_push(in2,self->data[i]);
		}
	}
	
	for(int i=0;i<in2->size;++i){
		if(is_left_turn(x,y,&in2->data[i])){
			vecset_push(S1,in2->data[i]);
		}else{
			vecset_push(S2,in2->data[i]);
		}
	}
	
	struct vecset *r1 = findhull(S1,x,M);
	struct vecset *r2 = findhull(S2,M,y);
	
	
	return r1;
	
}
