#include "EXO2.h"


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
			free(data);
		}
		self->data[self->size] = p;
		self->size += 1;	
	}
	

	
// 2.4 
	const struct vec *vecset_max(const struct vecset *self, comp_func_t func, const void *ctx){
	struct vec max = self->data[0];
	for (size_t i = 0 ; i < self->size ; ++i){
		//accès a donnée dans le tableau self->data[i].x
		if(func(&max,&(self->data[i]),NULL) < 0){
			max=self->data[i];
		}
	}
	const struct vec *res = &max ;
	return res;
}

// 2.5
const struct vec *vecset_min(const struct vecset *self, comp_func_t func, const void *ctx){
	struct vec min = self->data[0];
	for (size_t i = 0 ; i < self->size ; ++i){
		if(func(&min,&(self->data[i]),NULL) > 0){
			min=self->data[i];
		}
	}
	const struct vec *res = &min ;
	return res;
}

