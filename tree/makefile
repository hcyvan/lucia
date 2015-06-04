include $(ROOT)/env.mk

# all .c file
SRC=$(wildcard *.c)
# sub the .c to .o
OBJ=$(patsubst %.c,%.o,$(SRC))

#.PHONY:all
all:$(OBJ)
%.o:%.c makefile
	$(CC) $(CFlags) -c $< -o $(ROOT)/debug/$@ 



