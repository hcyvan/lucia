CC=gcc -Wall -std=c99
YACC=bison -v -d
LEX=flex
OBJECTS=main.o lex.o lucia.tab.o message.o lib.o ast.o symbol.o type.o table.o syminfo.o

parser:$(OBJECTS)
	$(CC) -o parser $(OBJECTS)
main.o:main.c lib.h lucia.tab.h message.h
	$(CC) -o main.o -c main.c
lex.o:lex.yy.c lucia.tab.h
	$(CC) -o lex.o -c lex.yy.c
lex.yy.c:lucia.lex message.h
	$(LEX) lucia.lex
lucia.tab.o:lucia.tab.c lucia.tab.h
	$(CC) -o lucia.tab.o -c lucia.tab.c
lucia.tab.c lucia.tab.h:lucia.y
	$(YACC) lucia.y

# general rule
%.o:%.c %.h makefile
	$(CC) -c $< -o $@

.PHONY:clean
clean:
	rm -f lex.yy.c lucia.tab.c lucia.tab.h lucia.output lucia.tab.o parser $(OBJECTS)
