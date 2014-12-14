#include "list.h"

void freeList(list l) {
    if(l != NULL) {
        freeList(l->tail);
        free(l);
        l = NULL;
    }
}

void complete(list lst, int quad) {
    *element tmp = lst;

    while(tmp != NULL) {
        if((tmp->head->quadType != Q_ASSIGNMENT))
            tmp->head->res = quad;
		
        tmp = tmp->tail;
    }
}

list nil() {
    return NULL;
}

list cons(T v, list l) {
    *element tmp;

    *Quad newQuad = malloc(sizeof(Quad));

    if(!(tmp = malloc(sizeof(element))))
        return NULL;

    tmp->head = v;
    tmp->tail = l;

    return tmp;
}

list concat(list l1, list l2) {
    if(l1 == NULL)
        return l2;
    else {
        *element tmp = cons(l1->head, concat(l1->tail, l2));
        free(l1);
        return tmp;
    }
}
