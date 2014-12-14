LEX = lex
YACC = yacc -d -v
CC = gcc
#SRC = quad.c quad.h symbol.h symbol.c

stenC: StenC.c y.tab.c lex.yy.c
	$(CC) y.tab.c lex.yy.c quad.h quad.c symbol.h symbol.c -ly -lfl -Wall -g
y.tab.c: StenC.y
	$(YACC) StenC.y
lex.yy.c: analyseur_StenC.l
	$(LEX) analyseur_StenC.l
