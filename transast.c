#include "transast.h"
#include "lib.h"

struct expOut_ transExp(S_table env,N_exp exp)
{
	switch(exp->type){
		case _IDS:
			{		// "{}" is needed. Insure e is defined.
			struct expOut_ e;
			S_symbol key=symbolConvert(exp->val.id);
			S_info info=(S_info)ST_getValue(env,key);
			memcpy(&e.info,info,sizeof(struct S_info_));
			return e;
			}
			break;
		case _CONST:
			{
			struct expOut_ e;
				switch(exp->val.value->type){
					{
					case _INT:
						e.info.type=Ty_Int();
						e.info.value.ival=exp->val.value->val.i;
						break;
					case _DOUBLE:
						e.info.type=Ty_Double();
						e.info.value.bval=exp->val.value->val.d;
						break;
					case _STRING:
						e.info.type=Ty_String();
						e.info.value.sval=strdup(exp->val.value->val.s);
						break;
					case _BOOL:
						e.info.type=Ty_Bool();
						e.info.value.bval=exp->val.value->val.b;
					default:
						e.info.type=Ty_Void();
						break;
					}
				}
			return e;
			}
			break;
		case _BOPEXP:
			{
			struct expOut_ left=transExp(env,exp->val.bopExp->left);
			struct expOut_ right=transExp(env,exp->val.bopExp->right);
			struct expOut_ e;
			switch(exp->val.bopExp->type){
				case _PLUS:
					if(left.info.type!=right.info.type)
						errorExit("Type is not the same in the binary operator\n");
					e.info.type=left.info.type;
					if(left.info.type==Ty_Int())
						e.info.value.ival=left.info.value.ival+right.info.value.ival;
					if(left.info.type==Ty_Double())
						e.info.value.dval=left.info.value.dval+right.info.value.dval;
					if(left.info.type==Ty_String()){
						// malloc() new memory and concatenate two string
						e.info.value.sval=checked_malloc(strlen(left.info.value.sval) \
						+strlen(right.info.value.sval)+1);
						strcpy(e.info.value.sval,left.info.value.sval);
						strcat(e.info.value.sval,right.info.value.sval);
					}
					if(left.info.type==Ty_Bool()){
						///////////////////////////////////
						/////////////////////////////////////
						//////////////////////////////////////
						//bool //////////////////////////////
						////////////////////////////////////
						;
					}
					break;
				case _MINUS:
					if(left.info.type!=right.info.type)
						errorExit("Type is not the same in the binary operator\n");
					e.info.type=left.info.type;
					if(left.info.type==Ty_Int())
						e.info.value.ival=left.info.value.ival-right.info.value.ival;
					if(left.info.type==Ty_Double())
						e.info.value.dval=left.info.value.dval-right.info.value.dval;
					if(left.info.type==Ty_String()){
						///////////////////////////////////////
						////////////////////////////////////
						///			string MINUS ////////////
						//////////////////////////////////	
						;
					}
					if(left.info.type==Ty_Bool()){
						///////////////////////////////////
						/////////////////////////////////////
						//////////////////////////////////////
						//bool //////////////////////////////
						////////////////////////////////////
						;
					}
					break;
				case _TIMES:
					if(left.info.type!=right.info.type)
						errorExit("Type is not the same in the binary operator\n");
					e.info.type=left.info.type;
					if(left.info.type==Ty_Int())
						e.info.value.ival=left.info.value.ival*right.info.value.ival;
					if(left.info.type==Ty_Double())
						e.info.value.dval=left.info.value.dval*right.info.value.dval;
					if(left.info.type==Ty_String()){
						///////////////////////////////////////
						////////////////////////////////////
						///			string Time////////////
						//////////////////////////////////	
						;
					}
					if(left.info.type==Ty_Bool()){
						///////////////////////////////////
						/////////////////////////////////////
						//////////////////////////////////////
						//bool //////////////////////////////
						////////////////////////////////////
						;
					}  
					break;
				case _DIVIDSE:
					if(left.info.type!=right.info.type)
						errorExit("Type is not the same in the binary operator\n");
					e.info.type=left.info.type;
					if(left.info.type==Ty_Int())
						e.info.value.ival=left.info.value.ival/right.info.value.ival;
					if(left.info.type==Ty_Double())
						e.info.value.dval=left.info.value.dval/right.info.value.dval;
					if(left.info.type==Ty_String()){
						///////////////////////////////////////
						////////////////////////////////////
						///			string dived ////////////
						//////////////////////////////////	
						;
					}
					if(left.info.type==Ty_Bool()){
						///////////////////////////////////
						/////////////////////////////////////
						//////////////////////////////////////
						//bool //////////////////////////////
						////////////////////////////////////
						;
					}  
					break;
				//case _POW	
				//case _AND
				//case _OR
				//case _EQ
				//case _NE
				//case _GT
				//case _LT
				//case _GE
				//case _LE
				default:
					break;
			}
			return e;
			}	
		case _MOPEXP:
			{
			struct expOut_ e=transExp(env,exp->val.mopExp->exp);
			switch(exp->val.mopExp->type){
				case _NEGATIVE:
					if(e.info.type==Ty_Int())
						e.info.value.ival=-e.info.value.ival;
					if(e.info.type==Ty_Double())
						e.info.value.dval=-e.info.value.dval;
					if(e.info.type==Ty_String()){
						///////////////////////////////////////
						////////////////////////////////////
						///			string  ////////////
						//////////////////////////////////	
						// malloc() new memory and concatenate two string
					}
					if(e.info.type==Ty_Bool()){
						///////////////////////////////////
						/////////////////////////////////////
						//////////////////////////////////////
						//bool //////////////////////////////
						////////////////////////////////////
						;
					}
					break;
				case _NOT:
					if(e.info.type==Ty_Int()){
						/////////////////////////
						/////////////////////////
						;
					}
					if(e.info.type==Ty_Double()){
						/////////////////////////
						/////////////////////////
						;
					}
					if(e.info.type==Ty_String()){
						///////////////////////////////////////
						////////////////////////////////////
						///			string  ////////////
						//////////////////////////////////	
						// malloc() new memory and concatenate two string
					}
					if(e.info.type==Ty_Bool()){
						///////////////////////////////////
						/////////////////////////////////////
						//////////////////////////////////////
						//bool //////////////////////////////
						////////////////////////////////////
						;
					}
					break;
				default:
					break;
			}
			return e;
			}	
		default:
			break;
	}
	struct expOut_ e;
	e.info.type=Ty_Void();
	return e;		
}
void transStm(S_table env,N_stm stm)
{
	switch(stm->type){
		case _EXP:
			transExp(env,stm->val.exp);
			break;
		case _PRINT:
			{
			struct expOut_ e=transExp(env,stm->val.exp);
			if(e.info.type==Ty_Int())
				printf("%d",e.info.value.ival);
			else if(e.info.type==Ty_Double())
				printf("%f",e.info.value.dval);
			else if(e.info.type==Ty_String())
				printf("%s",e.info.value.sval);
			else if(e.info.type==Ty_Bool()){
				if(e.info.value.bval==1)
					printf("true");
				else
					printf("false");
			}
			}
			break;
		case _ASSIGN:
			{
			S_symbol key=symbolConvert(stm->val.assign.id);
			S_info info=(S_info)ST_getValue(env,key);
			struct expOut_ e=transExp(env,stm->val.assign.exp);		

			// Copy the memory of e.info to the symbol.
			// If the value is a string(char*), the memory
			// of the string would not be free, and it will
			// be free later.
			memcpy(info,&e.info,sizeof(struct S_info_));
			}
			break;
		case _IFSTM:
			transExp(env,stm->val.ifstm.exp);
			/////////////////////////////////////////
			//to be continue
			//	if(exp){stmlist} 
			////////////////////////////////////////////
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
	




