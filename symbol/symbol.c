#include "../include/symbol.h"
#include "../include/lib.h"
#include "../include/type.h"
#include "../include/syminfo.h"

/** It's a hash table, but it is not a symbol table.
	We convert the symbol to a unique address, so the
	address can represent the symbol. It's easier to
	compare two address than two string in the symbol
	table **/
static S_symbol S_convertTable[CONVERTSIZE];

/** The hash function is form "Modern Compiler Implementation in C" **/
static unsigned int hash(char *s)
{
	unsigned int h=0;
	for(char *c=s; *c; ++c) 
		h=h*65599+*s;
	return h;
}

S_symbol symbolConvert(char *s)
{
	int index=hash(s)%TABLESIZE;

	// Find the same symbol
	for(S_symbol p=S_convertTable[index]; p!= NULL ; p=p->next){
		if(!strcmp(p->name,s)){
			return p;
		}
	}
	
	S_symbol sym=(S_symbol)checked_malloc(sizeof(*sym));
	sym->name=strdup(s);// segment fault debug: sym->name should be initialized
	sym->next=S_convertTable[index];
	S_convertTable[index]=sym;
	return sym;
}

S_table ST_create(void)
{
	return T_create();
}

void ST_push(S_table t,S_symbol key,void * value)
{
	T_push(t,(void*)key,value);
}

void* ST_pop(S_table t)
{
	return T_pop(t);
}

binder ST_lookUp(S_table t,S_symbol key)
{
	return T_lookUp(t,(void*)key);	
}

void* ST_getValue(S_table t, S_symbol key)
{
	if(ST_lookUp(t,(void*)key)){
		binder p=T_lookUp(t,(void*)key);
		return (void*)p->value;
	}
	// If the symbol is not exist, create new value(S_info_) for the key.
	void* value=(void*)SI_create();
	ST_push(t,key,value);
	return value;
}

void ST_setValue(S_table t,S_symbol key,void* value)
{
	binder p=ST_lookUp(t,key);
	assert(p);
	p->value=value;
}


/** This "symbol" is used as a sign to mark the scope **/
static struct S_symbol_ mark_ = {"<mark>",0};

void ST_mark(S_table t)
{
	ST_push(t,(void*)&mark_,NULL);
}

void ST_popScope(S_table t)
{
	void *s;
	while(s!=(void*)&mark_)
		s=ST_pop(t);
}
	
	
	


