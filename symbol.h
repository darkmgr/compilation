#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define false 0
#define true 1

#define SYMBOL_TYPECTE_ENTIER 0
#define SYMBOL_TYPECTE_BOOL 1
#define SYMBOL_TYPECTE_CHAR 2
#define SYMBOL_TYPECTE_UNIT 3

#define SYMBOL_TYPESYMBOL_CTE 0
#define SYMBOL_TYPESYMBOL_FCT 1

typedef int bool;
typedef struct symbol symbol;

typedef enum {
	INT = 1,
	INT_CST,
	INT_VECT,
	REAL,
	REAL_CST,
	REAL_VECT,
	COMPLEX,
	COMPLEX_CST,
	COMPLEX_VECT,
	BOOL,
	BOOL_CST,
	BOOL_VECT,
	FUNCTION,
	SYMBOL
}symbolType;

typedef enum {
		constant,
		input,
		output,
		global,
		local,
		algo
}declaration;

typedef union
{
	union
	{
		bool val;
		bool *vect;
	}boolean;
	
	union
	{
		int val;
		int *vect;
	}integer;
	
	union
	{
		double val;
		double *vect;
	}real;
	
	struct{
		double real;
		double imaginaire;
	}complex;
	
	union
	{
		char *val;
	}string;
}symbolVal;

struct symbol {
	char *name;
	int index;
	symbolType type;
	symbolVal val;
	declaration zone;
	int composed;
};

symbol** symTable;


typedef struct idType{
	char *string;
	int size;
}idType;
