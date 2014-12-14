#ifndef LIST_H
#define LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "quad.h"

#define T Quad *

typedef struct element element;

struct element {
    T        	head;
    *element 	tail;
};

typedef *element list;

void complete(list lst, int quad);
void freeList(list l);
list nil();
list cons(T v, list l);
list concat(list l1, list l2);

#endif

