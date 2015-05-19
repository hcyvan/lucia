/*************************************************************************
    > File Name: message.c
	> Author: hcyvan
	> Mail: navych@126.com 
	> Created Time: 2015年05月17日 星期日 19时54分00秒
************************************************************************/
#ifndef _MESSAGE_H_
#define _MESSAGE_H_
#include "lucia.tab.h"
//Position of tokens
extern int col;
extern int line;

//symbol table
typedef struct _symtab{
	int val;
	char* id;
	struct _symtab* next;
} Symtab, *symtab;
// check symbol table stack
//if the id is exist,return the point;otherwise create a new symbol table
symtab checkTable(char*);
#endif


