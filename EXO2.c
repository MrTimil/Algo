

struct vecset {
	struct vec *data;
	size_t size;
	size_t capacity;
};
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
			int *data = calloc(self->capacity, sizeof(int));
			memcpy(data, self->data, self->size * sizeof(int));
			free(self->data);
			self->data = data;
		}
		self->data[self->size] = value;
		self->size += 1;	
	}
	
// DECLARATION  

	typedef int (*comp_func_t)(const struct vec *p1, const struct vec *p2, const void *ctx); 
	
// 2.4 
	const struct vec *vecset_max(const struct vecset *self, comp_func_t func, const void *ctx){
	size_t max = self->data[0];
	for (size_t i = 0 ; i < self->size ; ++i){
		//accès a donnée dans le tableau self->data[i].x 	
	}
	return max;
}

