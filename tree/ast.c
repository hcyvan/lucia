#include "ast.h"
#include "../include/lib.h"
#include "../include/symbol.h"
#include "../include/table.h"
#include "../include/syminfo.h"
// symbol talbe create in main.o
extern S_table symbolTable;  

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
N_stm Stm_IFSTM(N_exp exp,N_stmList stmList)
{
	N_stm p=(N_stm)checked_malloc(sizeof(*p));
	p->type=_IFSTM;
	p->val.ifstm.exp=exp;
	p->val.ifstm.stmList=stmList;
	return p;
}
N_exp Exp_CONST(N_const value)
{
	N_exp p=(N_exp)checked_malloc(sizeof(*p));
	p->type=_CONST;
	p->val.value=value;
	return p;
}
N_exp Exp_IDS(char* id)
{
	N_exp p=(N_exp)checked_malloc(sizeof(*p));
	p->type=_IDS;
	p->val.id=strdup(id);
	/** The id should not add too symbol table now **/
	/*
	// Add id to symbol table
	void *key=(void*)symbolConvert(id);		// key
	//	S_info info=SI_create();			// value	
	ST_push(symbolTable,key,(void*)Ty_Nil());
	*/
	return p;
}
N_exp Exp_BOPEXP(N_bopExp bopExp)
{
	N_exp p=(N_exp)checked_malloc(sizeof(*p));
	p->type=_BOPEXP;
	p->val.bopExp=bopExp;
	return p;
}
N_exp Exp_MOPEXP(N_mopExp mopExp)
{
	N_exp p=(N_exp)checked_malloc(sizeof(*p));
	p->type=_MOPEXP;
	p->val.mopExp=mopExp;
	return p;
}
N_const	Const_INT(int i)
{
	N_const p=(N_const)checked_malloc(sizeof(*p));
	p->type=_INT;
	p->val.i=i;
	return p;
}
N_const	Const_DOUBLE(double d)
{
	N_const p=(N_const)checked_malloc(sizeof(*p));
	p->type=_DOUBLE;
	p->val.d=d;
	return p;
}
N_const	Const_CHAR(char c)
{
	N_const p=(N_const)checked_malloc(sizeof(*p));
	p->type=_CHAR;
	p->val.c=c;
	return p;
}
N_const	Const_STRING(char* s)
{
	N_const p=(N_const)checked_malloc(sizeof(*p));
	p->type=_STRING;		
	// strdup() to copy a string, and delete the two ' " '
	//p->val.s=strdup(s+1); 
	//char *qoute=strchr(p->val.s,'"');
	//*qoute='\0';
	p->val.s=checked_malloc(strlen(s)-1);
	strncpy(p->val.s,s+1,strlen(s)-1);
	*(p->val.s+strlen(s)-2)='\0';
	return p;
}
N_const	Const_BOOL(char* s)
{
	N_const p=(N_const)checked_malloc(sizeof(*p));
	p->type=_BOOL;
	if(strcmp(s,"true"))
		p->val.b=1;
	else
		p->val.b=0;
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
	p->type=_DIVIDE;
	p->left=left;
	p->right=right;
	return p;
}
N_bopExp BopExp_POW(N_exp left,N_exp right)
{
	N_bopExp p=(N_bopExp)checked_malloc(sizeof(*p));
	p->type=_POW;
	p->left=left;
	p->right=right;
	return p;
}
N_bopExp BopExp_AND(N_exp left,N_exp right)
{
	N_bopExp p=(N_bopExp)checked_malloc(sizeof(*p));
	p->type=_AND;
	p->left=left;
	p->right=right;
	return p;
}
N_bopExp BopExp_OR(N_exp left,N_exp right)
{
	N_bopExp p=(N_bopExp)checked_malloc(sizeof(*p));
	p->type=_OR;
	p->left=left;
	p->right=right;
	return p;
}
N_bopExp BopExp_EQ(N_exp left,N_exp right)
{
	N_bopExp p=(N_bopExp)checked_malloc(sizeof(*p));
	p->type=_EQ;
	p->left=left;
	p->right=right;
	return p;
}
N_bopExp BopExp_NE(N_exp left,N_exp right)
{
	N_bopExp p=(N_bopExp)checked_malloc(sizeof(*p));
	p->type=_NE;
	p->left=left;
	p->right=right;
	return p;
}
N_bopExp BopExp_GT(N_exp left,N_exp right)
{
	N_bopExp p=(N_bopExp)checked_malloc(sizeof(*p));
	p->type=_GT;
	p->left=left;
	p->right=right;
	return p;
}
N_bopExp BopExp_LT(N_exp left,N_exp right)
{
	N_bopExp p=(N_bopExp)checked_malloc(sizeof(*p));
	p->type=_LT;
	p->left=left;
	p->right=right;
	return p;
}
N_bopExp BopExp_GE(N_exp left,N_exp right)
{
	N_bopExp p=(N_bopExp)checked_malloc(sizeof(*p));
	p->type=_GE;
	p->left=left;
	p->right=right;
	return p;
}
N_bopExp BopExp_LE(N_exp left,N_exp right)
{
	N_bopExp p=(N_bopExp)checked_malloc(sizeof(*p));
	p->type=_LE;
	p->left=left;
	p->right=right;
	return p;
}
N_mopExp MopExp_NOT(N_exp exp)
{
	N_mopExp p=(N_mopExp)checked_malloc(sizeof(*p));
	p->type=_NOT;
	p->exp=exp;
	return p;
}
N_mopExp MopExp_NEGATIVE(N_exp exp)
{
	N_mopExp p=(N_mopExp)checked_malloc(sizeof(*p));
	p->type=_NEGATIVE;
	p->exp=exp;
	return p;
}
