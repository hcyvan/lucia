#include "lib.h"
#include <stdio.h>
#include <stdlib.h>
void* checked_malloc(int n)
{
	void *p=malloc(n);
	if(!p){
		errorExit("bad malloc\n");
	}
	return p;
}

void errorExit(char* s)
{
	perror(s);
	exit(EXIT_FAILURE);
}
