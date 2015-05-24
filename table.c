#include "table.h"
#include "lib.h"

S_table T_create(void)
{
	S_table p=(S_table)checked_malloc(sizeof(*p));
	for(int i=0;i<TABLESIZE;++i)
		p->table[i]=NULL;
	p->topKey=NULL;
	return p;
}

void T_push(S_table t, void* key,void * value)
{
	assert(t&&key);
	int index=((unsigned)key) % TABLESIZE;

	binder b=(binder)checked_malloc(sizeof(*b));
	b->key=key;
	b->value=value;
	b->next=t->table[index];
	b->preKey=t->topKey;

	t->table[index]=b;
	t->topKey=key;
}

void* T_pop(S_table t)
{
	assert(t);
	int index=((unsigned)t->topKey) % TABLESIZE;

	binder p =t->table[index];
	t->table[index]=t->table[index]->next;
	t->topKey=p->preKey;
	
	void* key=p->key;
	free(p);
	return key;
}

binder T_lookUp(S_table t,void *key)
{
	assert(t&&key);
	int index=((unsigned)key) % TABLESIZE;

	for(binder p=t->table[index];p;p=p->next)
		if(p->key==key){
			return p;
		}
	return NULL;
}



