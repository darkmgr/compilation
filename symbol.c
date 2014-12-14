#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symbol.h"

Symbol* genSymbole(char* id, bool isConstant, int value){
	Symbol* newSymbol;

	//on verifie si on peut encore generer un symbol (memoire)
	if(!(newSymbol = malloc(sizeof(Symbol)))) {
        return (NULL);
    }
	
	if(id == NULL){
		// 100 is the maximum length of a temp
		char name[100] = "temp_";
		char str_number[95];
		sprintf(str_number, "%d", symbolNumber);
		strcat(name, str_number);
		newSymbol->id = strdup(name);
		//on incremente la variable global du nombre de quad genere
		symbolNumber++;
	} else {
		newSymbol->id = strdup(id);
	}
	newSymbol->isConstant = isConstant;
	newSymbol->value = value;
	newSymbol->next = NULL;

	return newSymbol;
}

Symbol* addSymbol(Symbol** symbolsList, char* id, bool isConstant, int value){
	Symbol* newSymbol = genSymbole(id, isConstant, value);
	
	if(*symbolList == NULL){
		*symbolList = symbolsList;
	} else {
		Symbol* list = *symbolList;

		while(list->next != NULL){
			list = list->next;
		}
		list->next = newSymbol;
	}
	return newSymbol;
}

Symbol* getSymbol(Symbol* symbolList, char* id) {
	Symbol* getSymbol = NULL;
	Symbol* list = symbolList;
	
	while(list != NULL && getSymbol == NULL){
			if(strcmp(list->id, id) == 0) {
				getSymbol = list;
			}
			list = list->next;
		}
	return getSymbol;
}

void printSymbol(Symbol* symbolList){
	printf("\n\n##### TABLE DES SYMBOLES #####\n");
	
	while(symbolList != NULL){
		printf("table des symboles : id: %s || value : %d \n", symbolList->id, symbolList->value);
		symbolList = symbolList->next;
	}
	printf("##### FIN TABLE SYMBOLE #####\n");
}
