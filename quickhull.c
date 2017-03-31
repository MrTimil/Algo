#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <time.h> 
#include "quickhull.h"

// QuickHull

void quickhull(const struct vecset *in, struct vecset *out){
	const struct vec *A = vecset_min(in,&lowest_abs,NULL);
	const struct vec *B = vecset_max(in,&lowest_abs,NULL);
	/*
	printf("Min %f %f\n",A->x,A->y);
	printf("Min %f %f\n",B->x,B->y); 
	
	printf("In : \n");
	for(int i=0;i<in->size;++i){
		printf("%f %f\n",in->data[i].x,in->data[i].y);
	}
	*/
	struct vecset *S1=malloc(sizeof(struct vecset));
	struct vecset *S2=malloc(sizeof(struct vecset));
	
	struct vecset *in2=malloc(sizeof(struct vecset));
	vecset_create(in2);
	vecset_create(S1);
	vecset_create(S2);
	// in2 = in \ {A,B}
	for(int i=0;i<in->size;++i){
		if(in->data + i !=A && in->data + i != B){
			vecset_push(in2,in->data[i]);
		}
	}
	
	
	for(int i=0;i<in2->size;++i){
		if(is_left_turn(A,B,&in2->data[i])){
			vecset_push(S1,in2->data[i]);
		}else{
			vecset_push(S2,in2->data[i]);
		}
	}
	
	struct vecset *r1 = findhull(S1,A,B);
	struct vecset *r2 = findhull(S2,B,A);
	
	vecset_push(out,*A);
	for(int i=0;i<r1->size;++i){
		vecset_push(out,r1->data[i]);
	}
	
	vecset_push(out,*B);
	for(int i=0;i<r2->size;++i){
		vecset_push(out,r2->data[i]);
	}
	vecset_destroy(S1);
    free(S1);
    vecset_destroy(S2);
	free(S2);    
    vecset_destroy(r1);
	free(r1);    
    vecset_destroy(r2);    
    free(r2);
    vecset_destroy(in2);    
    free(in2);
}

struct vecset *findhull(const struct vecset *self,const struct vec *x,const struct vec *y){
	if (self->size == 0) {
        struct vecset * T = malloc(sizeof(struct vecset));
		vecset_create(T);
		return T;
    }
	struct vec *M=farthest_point(self,x,y);
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
		if(is_left_turn(x,M,&in2->data[i])){
			vecset_push(S1,in2->data[i]);
		}
		if(is_left_turn(M,y,&in2->data[i])){
			vecset_push(S2,in2->data[i]);
		}
	}
	/*
	printf("S1 : \n");
	for(int i=0;i<S1->size;++i){
		printf("%f %f\n",S1->data[i].x,S1->data[i].y);
	}
	printf("S2 : \n");
	for(int i=0;i<S2->size;++i){
		printf("%f %f\n",S2->data[i].x,S2->data[i].y);
	}
	*/
	struct vecset *r1 = findhull(S1,x,M);
	struct vecset *r2 = findhull(S2,M,y);
	struct vecset *r = malloc(sizeof(struct vecset));
	vecset_create(r);
	for(int i=0;i<r1->size;++i){
		vecset_push(r,r1->data[i]);
	}
	vecset_push(r,*M);
	for(int i=0;i<r2->size;++i){
		vecset_push(r,r2->data[i]);
	}
	vecset_destroy(S1);
    free(S1);
    vecset_destroy(S2);
	free(S2);    
    vecset_destroy(r1);
	free(r1);    
    vecset_destroy(r2);    
    free(r2);
    vecset_destroy(in2);    
    free(in2);

	
	return r;
	
}
