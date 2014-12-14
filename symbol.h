#ifndef SYMBOL_H
#define SYMBOL_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef enum {
	S_INT,
	S_INT_ARRAY
}SymbolType;

typedef struct Symbol {
	SymbolType 		symbolType;
	char*			id;
	bool 			isConstant;
	int 			value;
	struct Symbol* 	next;
}Symbol;

Symbol* genSymbol(char* id, bool isconstant, int value);
Symbol* getSymbol(Symbol* symbolsList, char* id);
Symbol* addSymbol(Symbol** symbolList, char* id, bool isConstant, int value);
void printSymbol(Symbol* symbolList);

int   symbolNumber;

#endif

