#ifndef _AST_H_
#define _AST_H_
typedef struct N_prog_ *N_prog;
typedef struct N_stmList_ *N_stmList;
typedef struct N_stm_ *N_stm;
typedef struct N_exp_ *N_exp;
typedef struct N_value_ *N_value;
typedef struct N_bopExp_ *N_bopExp;
struct N_prog_{
	enum{_STMLIST} type;
	union{
		N_stmList stmList;
	} val;
};
struct N_stmList_{
	enum{_LIST,_STM} type;
	union{
		struct{N_stmList stmList; N_stm stm;} stmList;
		N_stm stm;
	} val;
};
struct N_stm_{
	enum{_ASSIGN,_EXP,_PRINT} type;
	union{
		struct{char* id; N_exp exp;} assign;
		N_exp exp;
	} val;
};
struct N_exp_{
	enum{_VALUES,_IDS,_BOPEXP} type;
	union{
		N_value value;
		char* id;
		N_bopExp bopExp;
	} val;
};
struct N_bopExp_{
	enum{_PLUS,_MINUS,_TIMES,_DIVIDSE} type;
	N_exp left;
	N_exp right;
};
struct N_value_{
	enum{_INT,_DOUBLE,_CHAR} type;
	union{
		int i;
		double d;
		char c;
	} val;
};

//constructor
N_prog Prog_STMLIST(N_stmList);
N_stmList StmList_STMLIST(N_stmList,N_stm);
N_stmList StmList_STM(N_stm);
N_stm Stm_ASSIGN(char*,N_exp);
N_stm Stm_EXP(N_exp);
N_stm Stm_PRINT(N_exp);
N_exp Exp_VALUES(N_value);
N_exp Exp_IDS(char*);
N_exp Exp_BOPEXP(N_bopExp);
N_value	Value_INT(int);
N_value	Value_DOUBLE(double);
N_value	Value_CHAR(char);
N_bopExp BopExp_PLUS(N_exp,N_exp);
N_bopExp BopExp_MINUS(N_exp,N_exp);
N_bopExp BopExp_TIMES(N_exp,N_exp);
N_bopExp BopExp_DIVIDE(N_exp,N_exp);

#endif