#include "ast.h"
#include "lib.h"
N_prog Prog_STMLIST(N_stmList list)
{
	N_prog p=(N_prog)checked_malloc(sizeof(*p));
	p->type=_STMLIST;
	p->val.stmList=list;
	return p;
}
N_stmList StmList_STMLIST(N_stmList list ,N_stm stm)
{
	N_stmList p=(N_stmList)checked_malloc(sizeof(*p));
	p->type=_LIST;
	p->val.stmList.stmList=list;
	p->val.stmList.stm=stm;
	return p;
}
N_stmList StmList_STM(N_stm stm)
{
	N_stmList p=(N_stmList)checked_malloc(sizeof(*p));
	p->type=_STM;
	p->val.stm=stm;
	return p;
}
	
N_stm Stm_ASSIGN(char* id,N_exp exp)
{
	N_stm p=(N_stm)checked_malloc(sizeof(*p));
	p->type=_ASSIGN;
	p->val.assign.id=strdup(id);
	p->val.assign.exp=exp;
	return p;
}
N_stm Stm_EXP(N_exp exp)
{
	N_stm p=(N_stm)checked_malloc(sizeof(*p));
	p->type=_EXP;
	p->val.exp=exp;
	return p;
}
N_stm Stm_PRINT(N_exp exp)
{
	N_stm p=(N_stm)checked_malloc(sizeof(*p));
	p->type=_PRINT;
	p->val.exp=exp;
	return p;
}
N_exp Exp_VALUES(N_value value)
{
	N_exp p=(N_exp)checked_malloc(sizeof(*p));
	p->type=_VALUES;
	p->val.value=value;
	return p;
}
N_exp Exp_IDS(char* id)
{
	N_exp p=(N_exp)checked_malloc(sizeof(*p));
	p->type=_IDS;
	p->val.id=strdup(id);
	return p;
}
N_exp Exp_BOPEXP(N_bopExp bopExp)
{
	N_exp p=(N_exp)checked_malloc(sizeof(*p));
	p->type=_BOPEXP;
	p->val.bopExp=bopExp;
	return p;
}
N_value	Value_INT(int i)
{
	N_value p=(N_value)checked_malloc(sizeof(*p));
	p->type=_INT;
	p->val.i=i;
	return p;
}
N_value	Value_DOUBLE(double d)
{
	N_value p=(N_value)checked_malloc(sizeof(*p));
	p->type=_DOUBLE;
	p->val.d=d;
	return p;
}
N_value	Value_CHAR(char c)
{
	N_value p=(N_value)checked_malloc(sizeof(*p));
	p->type=_CHAR;
	p->val.c=c;
	return p;
}
N_bopExp BopExp_PLUS(N_exp left,N_exp right)
{
	N_bopExp p=(N_bopExp)checked_malloc(sizeof(*p));
	p->type=_PLUS;
	p->left=left;
	p->right=right;
	return p;
}
N_bopExp BopExp_MINUS(N_exp left,N_exp right)
{
	N_bopExp p=(N_bopExp)checked_malloc(sizeof(*p));
	p->type=_MINUS;
	p->left=left;
	p->right=right;
	return p;
}
N_bopExp BopExp_TIMES(N_exp left,N_exp right)
{
	N_bopExp p=(N_bopExp)checked_malloc(sizeof(*p));
	p->type=_TIMES;
	p->left=left;
	p->right=right;
	return p;
}
N_bopExp BopExp_DIVIDE(N_exp left,N_exp right)
{
	N_bopExp p=(N_bopExp)checked_malloc(sizeof(*p));
	p->type=_DIVIDSE;
	p->left=left;
	p->right=right;
	return p;
}
