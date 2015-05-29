#ifndef _TABLE_H_
#define _TABLE_H_
/** This module prvide a data structure to stroe the symbol
	table. binder_ is organised as a hash table by S_table.
	The interfaces of the realization are below. **/

#define TABLESIZE	100
typedef struct binder_* binder;
typedef struct S_table_* S_table;

/** The key in binder can be the address of a symbol, 
	so that it's easier to compare. **/
struct binder_{
	void* key;
	void* value;
	binder next;
	void* preKey;
};
struct S_table_{
	binder table[TABLESIZE];
	void *topKey;
};


/** Create and return a hash table **/
S_table T_create(void);
/** push a "key"(binder) into a hash chain.**/
void T_push(S_table, void*,void *);
/** Pop a binder and return the (void*)key int the binder **/
void* T_pop(S_table);
/** Search in the hash table, and return the point ofbinder.
	If the key is not exist, return NULL. **/
binder T_lookUp(S_table,void*);

#endif
