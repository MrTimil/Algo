#include "graham.h"


void graham_scan(const struct vecset *in, struct vecset *out){
	const struct vec *b;
	const struct vec *f;
	b = vecset_min(in, &lowest_point, NULL);
	struct vecset *in2=malloc(sizeof(struct vecset));
	vecset_create(in2);
	for(int i=0;i<in->size;++i){
		if(in->data + i != b){
			vecset_push(in2,in->data[i]);
		}
		
	}
	vector_set_sort(in2,&comp_angle,b);

	f=&in2->data[0];	
	vecset_push(out,*b);
	vecset_push(out,*f);

	for(int i=1;i<in2->size;++i){
		while((out->size >= 2 ) && (is_right_turn(vecset_second(out),vecset_top(out), &in2->data[i]))){
			vecset_pop(out);
		}
		vecset_push(out,in2->data[i]);
	}

}
