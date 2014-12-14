#ifndef QUAD_H
#define QUAD_H

#include "symbol.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum{ 
	Q_ASSIGN,
	Q_PLUS,
	Q_MINUS,
	Q_DIV,
	Q_MULT
}QuadType;

typedef struct quad {
    int           		index;
	QuadType 			quadType;
    struct Symbol*      arg1;
    struct Symbol* 		arg2;
    struct Symbol* 		res;
    struct Quad*		next;
}Quad;

Quad* genQuad(QuadType type, Symbol* arg1, Symbol* arg2, Symbol* res);
Quad* addQuadList(Quad** quad, int index);
void quadFree(Quad* quad);
void printQuad(Quad* quad);
void printMips(Quad* quad);

int   quadNumber;
Quad *quadTable;

#endif
