#include "lib.h"
#include <math.h>
// Tableau dynamique
// 2.1
void vecset_create(struct vecset *self){
	self -> data = malloc(sizeof(int));
	self -> capacity = 0;
	self -> size = 0;
}
	
// 2.2 
void vecset_destroy(struct vecset *self){
	free(self->data);
}

// 2.3 
void vecset_add(struct vecset *self, struct vec p){
	if (self->size == self->capacity) {
		if (self->capacity ==0){
			self->capacity =1;
		}
		self->capacity *= 2;
		struct vec *data = calloc(self->capacity, sizeof(struct vec));
		memcpy(data, self->data, self->size * sizeof(struct vec));
		free(self->data);
		self->data = data;
	}
	self->data[self->size] = p;
	self->size += 1;

}
	

	
// 2.4 
const struct vec *vecset_max(const struct vecset *self, comp_func_t func, const void *ctx){
	struct vec *max = &self->data[0];
	for (size_t i = 1 ; i < self->size ; ++i){
		//accès a donnée dans le tableau self->data[i].x
		if(func(max,&(self->data[i]),ctx) < 0){
			max=&self->data[i];
		}
	}	
	
	return max ;
}

// 2.5
const struct vec *vecset_min(const struct vecset *self, comp_func_t func, const void *ctx){
	struct vec *min = &self->data[0];	
	for (size_t i = 1 ; i < self->size ; ++i){
		if(func(min,&(self->data[i]),ctx) > 0){
			min=&self->data[i];
		}
	}
	return min ;
	
}

// quick sort


void vecset_swap(struct vecset *self, size_t i, size_t j) {
	struct vec tmp = self->data[i];
	self->data[i] = self->data[j];
	self->data[j] = tmp;
}

long vecset_partition(struct vecset *self, long i, long j, comp_func_t func, const void *ctx) {
	long pivot_index = i;
	const struct vec pivot = self->data[pivot_index];
	vecset_swap(self, pivot_index, j);
	long l = i;
		
	
	for (long k = i; k < j; ++k) {
		if (func(&(self->data[k]),&pivot,ctx)<0) {// remplacer par la fonction de comparaison 
			vecset_swap(self, k, l);
			l++;
		}
	}
	vecset_swap(self, l, j);
	return l;
}
void vecset_quick_sort_partial(struct vecset *data, long i, long j, comp_func_t func, const void *ctx) {
	if (i < j) {
		long p = vecset_partition(data, i, j,func,ctx);
		vecset_quick_sort_partial(data, i, p - 1,func,ctx);
		vecset_quick_sort_partial(data, p + 1, j,func,ctx);
	}
}		


void vector_set_sort(struct vecset *self,comp_func_t func, const void *ctx) {
	
	long n = self->size;
	vecset_quick_sort_partial(self, 0, n - 1,func,ctx);
}

void vecset_push(struct vecset *self,struct vec p){
	vecset_add(self,p);
}
void vecset_pop(struct vecset *self){
	self->size -= 1;
}


const struct vec *vecset_top(const struct vecset *self){
	const struct vec *res = &self->data[self->size-1];
	return res;
}
const struct vec *vecset_second(const struct vecset *self){
	const struct vec *res = &self->data[self->size-2];
	return res;
}

// fonction de comparaison : 
int lowest_point(const struct vec *p1,const struct vec *p2, const void *ctx){

	if (p1->y == p2->y){
		return p1->x - p2->x;
	}
	return p1->y - p2->y;
}
int comp_angle(const struct vec *p1,const struct vec *p2,const void *ctx){
	double px1,py1,px2,py2;
	const struct vec *comp = ctx;
	
	px1 = p1->x - comp->x; 
	py1 = p1->y - comp->y;

	px2 = p2->x - comp->x; 
	py2 = p2->y - comp->y;
	
	double angle1,angle2;
	angle1=atan2(py1,px1);
	angle2=atan2(py2,px2);
	
	if(angle1>angle2){
		return 1;
	}else if(angle1<angle2){
		return -1;
	}else{
		return 0;
	}
}


int comparaison_jarvis(const struct vec *p1,const struct vec *p2, const void *ctx){
 		if (p1->x == p2->x){
 			return 0;
 		}else{
 			if(p1->x > p2->x){
 				return 1;
 			}
 			return -1;
 		}
}
