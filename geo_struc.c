#include "geo_struc.h"
#include <stdio.h>
#include <stdlib.h>


double dot(const struct vec *v1, const struct vec *v2){
	return (v1->x*v2->x)+(v1->y*v2->y);
}

double cross(const struct vec *p1,const struct vec *p2, const struct vec *p3){
	return (((p2->x-p1->x)*(p3->y-p1->y))-((p2->y-p1->y)*(p3->x	-p1->x)));
}

bool is_left_turn(const struct vec *p1,const struct vec *p2, const struct vec *p3){
printf("%f",cross(p1,p2,p3));
	if(cross(p1,p2,p3)>0.0){
		return true;
	}
	return false;
}
