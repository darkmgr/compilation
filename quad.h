#include "symbol.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct quad {
    int           index;
    int       		 s1;
    int 			 s2;
    int 			 s3;

    struct quad *next;
} Quad;

Quad* genQuad(int s1, int s2, int s3);
Quad* addQuadList(Quad **quad, int index);

void printQuad(Quad *quad);
void printMips(Quad *quad);

int   quadNumber;
Quad *quadTable;