#include "symbol.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum{ 
	Q_GOTO     = 1, 
	Q_IFEQGOTO = 2, 
	Q_ASSIGN   = 3,
	Q_FUNC 	   = 4, 
	Q_ADD      = 5, 
	Q_MULT     = 6,
	Q_DIV      = 7,
	Q_MINUS    = 8,
	Q_IFLTGOTO = 9,
	Q_IFLEGOTO = 10,
	Q_IFGTGOTO = 11,
	Q_IFGEGOTO = 12,
	Q_IFNEQGOTO = 13
}QuadType;

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