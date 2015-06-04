export ROOT=$(shell pwd)
#变量VPATH定义了一组搜索路径。如果一个文件在文件名给出的路径中不存在，就在（VPATH+文件名中的路径）的路径中搜索该文.
export VPATH=$(ROOT)/debug:$(ROOT)/include
include env.mk
.PHONY:lucia
lucia:
	@cd parse && make
	@cd etc && make
	@cd tree && make
	@cd symbol && make
	@cd debug && make

.PHONY:clean
clean:
	rm -f lucia
	cd include && rm -f lucia.tab.h
	cd debug && rm -f *.o lucia.* lex.yy.c lucia

