#ifndef LIB_H
#define LIB_H

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
long vecset_partition(struct vecset *self, long i, long j, comp_func_t func, const void *ctx);
void vecset_quick_sort_partial(struct vecset *data, long i, long j,comp_func_t func, const void *ctx);
void vector_set_sort(struct vecset *self,comp_func_t func, const void *ctx);
void vecset_push(struct vecset *self,struct vec p);
void vecset_pop(struct vecset *self);
const struct vec *vecset_top(const struct vecset *self);
const struct vec *vecset_second(const struct vecset *self);
int lowest_point(const struct vec *p1,const struct vec *p2, const void *ctx);
int lowest_abs(const struct vec *p1,const struct vec *p2,const void *ctx);
int hightest_abs(const struct vec *p1,const struct vec *p2,const void *ctx);
int comp_angle(const struct vec *p1,const struct vec *p2,const void *ctx);
struct vec *farthest_point(const struct vecset *self,const struct vec *p1,const struct vec *p2);

#endif 
