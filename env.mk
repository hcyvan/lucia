CC=gcc
YACC=bison -v -d
LEX=flex
INCLUDE=-I../include/
CFlags=-Wall -std=c99 $(INCLUDE)

# general rule ** something worng **
#%.o:%c
#	$(CC) -o $(ROOT)/debug/$@ -c $<
