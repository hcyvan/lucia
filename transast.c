#include "transast.h"
#include "lib.h"

struct expOut_ transExp(S_table env,N_exp exp)
{
	switch(exp->type){
		case _IDS:
			{		// "{}" is needed. Insure e is defined.
			struct expOut_ e;
			S_symbol key=symbolConvert(exp->val.id);
			e.ty=(Ty)ST_lookUp(env,key);
			return e;
			}
			break;
		case _CONST:
			{
			struct expOut_ e;
			e.ty=Ty_Nil();
			return e;
			}
			break;
		case _BOPEXP:
			{
			struct expOut_ left=transExp(env,exp->val.bopExp->left);
			struct expOut_ right=transExp(env,exp->val.bopExp->right);
			if(left.ty->kind!=right.ty->kind)
				errorExit("Type is not the same in the binary operator\n");
			return left;
			}	
		case _MOPEXP:
			{
			struct expOut_ e=transExp(env,exp->val.mopExp->exp);
			return e;
			}	
		default:
			break;
	}
	struct expOut_ e;
	e.ty=Ty_Void();
	return e;		
}

void transStm(S_table env,N_stm stm)
{
	switch(stm->type){
		case _EXP:
			transExp(env,stm->val.exp);
			break;
		case _PRINT:
			transExp(env,stm->val.exp);
			//to be continue
			break;
		case _ASSIGN:
			{
			S_symbol key=symbolConvert(stm->val.assign.id);
			Ty ty_id=(Ty)ST_lookUp(env,key);
			struct expOut_ e=transExp(env,stm->val.assign.exp);		
			if(e.ty->kind!=ty_id->kind)
				errorExit("type is not the same in assignment statement\n");
			}
			break;
		case _IFSTM:
			transExp(env,stm->val.ifstm.exp);
			/**
			to be continue
				if(exp){stmlist} 
			**/
			transStmList(env,stm->val.ifstm.stmList);	
			break;
		default:
			break;
	}
}
		
void transStmList(S_table env, N_stmList stmList)
{
	switch(stmList->type){
		case _STM:
			{
			transStm(env,stmList->val.stm);
			}
			break;
		case _LIST:
			{
			transStmList(env,stmList->val.stmList.stmList);
			transStm(env,stmList->val.stmList.stm);
			}
			break;
		default:
			break;
	}
}

void transProg(S_table env,N_prog prog)
{
	if(prog->type==_STMLIST)
		transStmList(env,prog->val.stmList);
}
	





