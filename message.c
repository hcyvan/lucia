/*************************************************************************
    > File Name: message.c
	> Author: hcyvan
	> Mail: navych@126.com 
	> Created Time: 2015年05月17日 星期日 19时54分00秒
************************************************************************/
#include <stdlib.h>
#include <string.h>
#include "lucia.tab.h"
#include "message.h"
#include "lib.h"
int col=0;
int line=1;

string fileName;
symtab stab=NULL;

extern char *strdup(char *s);

symtab checkTable(char* s)
{
	if(stab==NULL){
		stab=(symtab)checked_malloc(sizeof(Symtab));
		stab->val=0;	//the default value of id 
		stab->next=NULL;
		stab->id=strdup(s);
		return stab;
	}else{
		symtab p=stab;
		while(p){
			if(!strcmp(p->id,s)){
				return p;
			}
			p=p->next;
		}
	}
	symtab p=(symtab)checked_malloc(sizeof(Symtab));
	p->next=stab;
	stab=p;
	stab->val=0;	//the default value of id 
	stab->id=strdup(s);
	return stab;
}


	
//YYSTYPE yylval;



