all: compile

compile: yacc flex
	gcc *.c -lfl -o analyseur -lpthread

flex: analyseur_StenC.lex
	flex analyseur_StenC.lex

yacc: prog.y
	yacc -d -v prog.y

zip: clean
	zip MullerSaidani.zip *
	
clean:
	rm -f *.o analyseur *.tab.* lex.* y.output *.zip
