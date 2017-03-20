#ifndef GEO_STRUC_H
#define GEO_STRUC_H

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>

struct vec{
	double x;
	double y;
}; 

double dot(const struct vec *v1, const struct vec *v2);
double cross(const struct vec *p1,const struct vec *p2, const struct vec *p3);
bool is_left_turn(const struct vec *p1,const struct vec *p2, const struct vec *p3);

#endif 
