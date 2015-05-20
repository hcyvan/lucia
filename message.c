#include "lucia.tab.h"
#include "message.h"
#include "lib.h"
int col=0;
int line=1;

char* fileName;
symtab stab=NULL;

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

