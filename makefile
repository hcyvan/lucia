CC=gcc -Wall -std=c99
YACC=bison -d
LEX=flex
parser:main.o lex.o lucia.tab.o message.o lib.o
	$(CC) -o parser main.o lex.o lucia.tab.o message.o lib.o
main.o:main.c lib.h lucia.tab.h message.h
	$(CC) -o main.o -c main.c
lex.o:lex.yy.c message.h lucia.tab.h
	$(CC) -o lex.o -c lex.yy.c
lucia.tab.o:lucia.tab.c lucia.tab.h
	$(CC) -o lucia.tab.o -c lucia.tab.c
message.o:message.c	message.h
	$(CC) -o message.o -c message.c
lib.o:lib.h
	$(CC) -o lib.o -c lib.c
lex.yy.c:lucia.lex message.h
	$(LEX) lucia.lex
lucia.tab.c lucia.tab.h:lucia.y
	$(YACC) lucia.y

.PHONY:clean
clean:
	rm -f lex.yy.c lex.o message.o main.o lucia.tab.c lucia.tab.h lucia.tab.o lib.o
