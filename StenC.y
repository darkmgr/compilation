%{

	#include <stdio.h>
	#include <stdlib.h>
	#include <ctype.h>
	#include <string.h>
	#include <math.h>
	#include "symbol.h"
	#include "quad.h"
	#include "y.tab.h"

	int yylex();
	int yyerror();

	Symbol* tableSymboles = NULL;
	Quad* listeQuads = NULL;

%}

%union{
	int integer;
	char* string;
	struct Symbol* pointerSymbol;
}

%token INTEGER
%token IDENTIFIER
%token INT

%type <integer> INTEGER
%type <string> IDENTIFIER
%type <string> varDeclaration
%type <pointerSymbol> expression;
%type <pointerSymbol> variable;

/* les priorités pour les opérations */
%right '='
%left '+' '-'
%left '*' '/'

%%

axiom: listeInstructions '\n' {printSymbol(tableSymboles);printQuad(listeQuads);printMips(listeQuads);}
						;
listeInstructions: instruction ';'
				  | instruction ';' listeInstructions
				  ;

instruction: varDeclaration {printf("AN INSTRUCTION \n");}
			| assignationExpression {printf("ASSIGN INSTRUCTION \n");}
			| declarationTableau {printf("array list \n");}
			;

varDeclaration : typeVar IDENTIFIER {
					if(getSymbol(tableSymboles, $2) != NULL){
						printf("%s est déjà déclaré ! \n", $2);
						exit(0);
					} else {
						addSymbol(&tableSymboles, $2, false, 0);
						$$ = $2;
					}
				}
				;


typeVar: INT
		;

crochets: '[' INTEGER ']'
				;

multiCrochets: crochets multiCrochets
					 | crochets crochets
					 ;

listeNombre: INTEGER 
			| INTEGER ',' listeNombre
			;

listeAccolade:	'{' '}'
			  |  '{' listeNombre '}'
			  |  '{' listeAccolade ',' listeAccolade '}'
			  ;

declarationTableau : varDeclaration multiCrochets '=' listeAccolade
					| varDeclaration multiCrochets
					| IDENTIFIER '=' listeAccolade
					;

assignationExpression : varDeclaration '=' expression {
							Symbol* var_symbol = getSymbol(tableSymboles, $1);

							var_symbol->value = $3->value;
							Quad* newQuad = genQuad(Q_ASSIGN, $3, NULL, var_symbol);
							/* quad_add(&listeQuads, newQuad); */

					  }
					  | IDENTIFIER '=' expression {
							Symbol* symbol = getSymbol(tableSymboles, $1);

							if(symbol == NULL){
								printf("%s n'est pas déclaré \n", $1);
								exit(0);
							}
							var_symbol->value = $3->value;
							Quad* newQuad = genQuad(Q_ASSIGN, $3, NULL, symbol);
							/* addQuadList(&listeQuads, newQuad); */
					  }
					  ;
					
variable: IDENTIFIER {
				Symbol* symbol = getSymbol(tableSymboles, $1);

				if(symbol == NULL){
					printf("%s n'est pas déclaré \n", $1);
				}

				$$ = symbol;

		}
		| INTEGER {
			Symbol* temp2 = addSymbol(&tableSymboles, NULL, true, $1);
			Symbol* temp1 = addSymbol(&tableSymboles, NULL, true, $1);
			Quad* newQuad = genQuad(Q_ASSIGN, temp2, NULL, temp1);
			/* quad_add(&listeQuads, newQuad); */
			$$ = temp1;
		};

expression: expression '+' expression{
				$$ = addSymbol(&tableSymboles, NULL, false, calculQuad(Q_PLUS, $1->value, $3->value));
				$$->value =  calculQuad(Q_PLUS, $1->value, $3->value);
				Quad* newQuad = genQuad(Q_PLUS, $1, $3, $$);
				/* quad_add(&listeQuads, new_quad); */
			}
			|expression '-' expression{
				$$ = addSymbol(&tableSymboles, NULL, false, calculQuad(Q_MINUS, $1->value, $3->value));
				$$->value =  calculQuad(Q_MINUS, $1->value, $3->value);
				Quad* newQuad = genQuad(Q_MINUS, $1, $3, $$);
				/* quad_add(&listeQuads, new_quad); */
			}
			| expression '*' expression{
				$$ = addSymbol(&tableSymboles, NULL, false, calculQuad(Q_MULT, $1->value, $3->value));
				$$->value =  calculQuad(Q_MULT, $1->value, $3->value);
				Quad* newQuad = genQuad(Q_MULT, $1, $3, $$);
				/* quad_add(&listeQuads, new_quad); */
			}
			|expression '/' expression{
				$$ = addSymbol(&tableSymboles, NULL, false, calculQuad(Q_DIV, $1->value, $3->value));
				$$->value =  calculQuad(Q_DIV, $1->value, $3->value);
				Quad* newQuad = genQuad(Q_DIV, $1, $3, $$);
				/* quad_add(&listeQuads, new_quad); */
			}
			| '(' expression ')' {
				$$ = $2;
			}
			| variable {
				$$ = $1;
			}
			;
%%

int main(){
	printf("=== START ===\n");
	return yyparse();
}
