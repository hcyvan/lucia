#ifndef _LIB_H_
#define _LIB_H_


typedef char* string;

// if malloc() return NULL, call exit().
void *checked_malloc(int);
// perror() massage and eixt()
void errorExit(char*);
		
#endif
