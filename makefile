export ROOT=$(shell pwd)
include env.mk
.PHONY:lucia
lucia:
	@(cd parse;make)
	@(cd etc;make)
	@(cd tree;make)
	@(cd symbol;make)
	@(cd debug;make)

.PHONY:clean
clean:
	rm -f lucia
	(cd include;rm -f lucia.tab.h)
	(cd debug;rm -f *.o lucia.* lex.yy.c)

