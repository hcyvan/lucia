#ifndef _TRANSAST_H_
#define _TRANSAST_H_
#include "ast.h"
#include "type.h"
#include "symbol.h"

struct expOut_{
	void *exp;
	Ty ty;
};

/** Iterating the expression node in the absract syntax tree **/
struct expOut_ transExp(S_table,N_exp);

/** Iterating the statement node in the absract syntax tree **/
void transStm(S_table, N_stm);

/** Iterating the statement list node in the absract syntax tree **/
void transStmList(S_table, N_stmList);

/** Iterating from the root node in the absract syntax tree **/
void transProg(S_table, N_prog);

#endif
