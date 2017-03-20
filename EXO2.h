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

#endif 
