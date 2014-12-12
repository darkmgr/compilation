#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "quad.h"

#define T Quad *

typedef struct element element;

struct element
{
    T        head;
    element *tail;
};

typedef element *list;

void complete(list lst, int quad);
void freelist(list l);
list nil();
list constructor(T v, list l);
list concat(list l1, list l2);
