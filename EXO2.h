#ifndef EXO2_H
#define EXO2_H

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>

#include "geo_struc.h"

struct vecset {
	struct vec *data;
	size_t size;
	size_t capacity;
};
// DECLARATION  

	typedef int (*comp_func_t)(const struct vec *p1, const struct vec *p2, const void *ctx); 
	
void vecset_create(struct vecset *self);
void vecset_destroy(struct vecset *self);
void vecset_add(struct vecset *self, struct vec p);
const struct vec *vecset_max(const struct vecset *self, comp_func_t func, const void *ctx);
const struct vec *vecset_min(const struct vecset *self, comp_func_t func, const void *ctx);
void vecset_swap(struct vecset *self, size_t i, size_t j);
long vecset_partition(struct vecset *self, long i, long j, comp_func_t func);
void vecset_quick_sort_partial(struct vecset *data, long i, long j,comp_func_t func);
void vector_set_sort(struct vecset *self,comp_func_t func, const void *ctx);
int comparaison_jarvis(const struct vec *p1,const struct vec *p2,const void *ctx);

#endif 
