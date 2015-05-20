CC=gcc -Wall -std=c99
YACC=bison -v -d
LEX=flex
parser:main.o lex.o lucia.tab.o message.o lib.o ast.o
	$(CC) -o parser main.o lex.o lucia.tab.o message.o lib.o ast.o
main.o:main.c lib.h lucia.tab.h message.h
	$(CC) -o main.o -c main.c
lex.o:lex.yy.c lucia.tab.h
	$(CC) -o lex.o -c lex.yy.c
lucia.tab.o:lucia.tab.c lucia.tab.h
	$(CC) -o lucia.tab.o -c lucia.tab.c
message.o:message.c	message.h
	$(CC) -o message.o -c message.c
lib.o:lib.c lib.h
	$(CC) -o lib.o -c lib.c
ast.o:ast.c ast.h 
	$(CC) -o ast.o -c ast.c
lex.yy.c:lucia.lex message.h
	$(LEX) lucia.lex
lucia.tab.c lucia.tab.h:lucia.y
	$(YACC) lucia.y

.PHONY:clean
clean:
	rm -f lex.yy.c lex.o message.o main.o lucia.tab.c lucia.tab.h lucia.output lucia.tab.o lib.o ast.o parser
