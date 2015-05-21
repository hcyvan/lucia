#ifndef _SYMBOL_H_
#define _SYMBOL_H_

#define CONVERTSIZE	100
typedef struct S_table_ * S_table;
typedef struct S_symbol_* S_symbol;

struct S_symbol_{
	char* name;
	S_symbol next;
};

/** The hash function is form "Modern Compiler Implementation in C" **/
static unsigned int hash(char *);

/** insert a string to hashtable. If the string is exist, return the "it", otherwise,
	create a new one and push "it" into the hash chain in the hash table. **/
S_symbol symbolConvert(char *);

/** Create and return a symbol-hash table **/
S_table ST_create(void);
/** push a "symbol string"(binder) into a hash chain.**/
void ST_push(S_table, S_symbol,void *);
/** Pop a binder and return the (void*)key int the binder **/
void* ST_pop(S_table);
/** Search in the symbol table, and return the value. If the key
	is not exist, return NULL. **/
void* ST_lookUp(S_table,S_symbol);

/**	The two function is used to change scope of the symbol.
	ST_mark() : marker the symbol table;
	ST_popScope() : change scope;**/
void ST_mark(S_table);
void ST_popScope(S_table);


#endif
