include $(ROOT)/env.mk

.PHONY:all
all:lucia.tab.o lex.o main.o
lucia.tab.o:lucia.tab.c lucia.tab.h
	$(CC) $(CFlags) -c lucia.tab.c -o $(ROOT)/debug/lucia.tab.o
	mv lucia.tab.c $(ROOT)/debug/lucia.tab.c
	mv lucia.output $(ROOT)/debug/lucia.output
lucia.tab.h lucia.tab.c:lucia.y
	$(YACC) lucia.y
	mv lucia.tab.h $(ROOT)/include/
lex.o:lex.yy.c
	$(CC) $(CFlags) -c lex.yy.c -o $(ROOT)/debug/lex.o
	mv lex.yy.c $(ROOT)/debug/lex.yy.c
lex.yy.c:lucia.lex
	$(LEX) lucia.lex
main.o:main.c lucia.tab.h
	$(CC) $(CFlags) -c main.c -o $(ROOT)/debug/main.o
	
