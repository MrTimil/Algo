#ifndef QUICKHULL_H
#define QUICKHULL_H

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>

#include "lib.h"

void quickhull(const struct vecset *in, struct vecset *out);
struct vecset *findhull(const struct vecset *self,const struct vec *x,const struct vec *y);

#endif
