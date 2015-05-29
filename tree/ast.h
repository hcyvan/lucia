#ifndef _AST_H_
#define _AST_H_
typedef struct N_prog_ *N_prog;
typedef struct N_stmList_ *N_stmList;
typedef struct N_stm_ *N_stm;
typedef struct N_exp_ *N_exp;
typedef struct N_const_ *N_const;
typedef struct N_bopExp_ *N_bopExp;
typedef struct N_mopExp_ *N_mopExp;
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
	enum{_ASSIGN,_EXP,_PRINT,_IFSTM} type;
	union{
		struct{char* id; N_exp exp;} assign;
		N_exp exp;
		struct{N_exp exp;N_stmList stmList;} ifstm;
	} val;
};
struct N_exp_{
	enum{_CONST,_IDS,_BOPEXP,_MOPEXP} type;
	union{
		N_const value;
		char* id;
		N_bopExp bopExp;
		N_mopExp mopExp;
	} val;
};
struct N_bopExp_{
	enum{_PLUS,_MINUS,_TIMES,_DIVIDSE,_POW,_AND,_OR,\
			_EQ,_NE,_GT,_LT,_GE,_LE} type;
	N_exp left;
	N_exp right;
};
struct N_mopExp_{
	enum{_NEGATIVE,_NOT} type;
	N_exp exp;
};
struct N_const_{
	enum{_INT,_DOUBLE,_CHAR,_STRING,_BOOL} type;
	union{
		int i;
		int b;
		double d;
		char c;
		char* s;
	} val;
};

//constructor
N_prog Prog_STMLIST(N_stmList);
N_stmList StmList_STMLIST(N_stmList,N_stm);
N_stmList StmList_STM(N_stm);
N_stm Stm_ASSIGN(char*,N_exp);
N_stm Stm_EXP(N_exp);
N_stm Stm_PRINT(N_exp);
N_stm Stm_IFSTM(N_exp,N_stmList);
N_exp Exp_CONST(N_const);
N_exp Exp_IDS(char*);
N_exp Exp_BOPEXP(N_bopExp);
N_exp Exp_MOPEXP(N_mopExp);
N_const	Const_INT(int);
N_const	Const_DOUBLE(double);
N_const	Const_CHAR(char);
N_const	Const_STRING(char*);
N_const	Const_BOOL(char*);
N_bopExp BopExp_PLUS(N_exp,N_exp);
N_bopExp BopExp_MINUS(N_exp,N_exp);
N_bopExp BopExp_TIMES(N_exp,N_exp);
N_bopExp BopExp_DIVIDE(N_exp,N_exp);
N_bopExp BopExp_POW(N_exp,N_exp);
N_bopExp BopExp_AND(N_exp,N_exp);
N_bopExp BopExp_OR(N_exp,N_exp);
N_bopExp BopExp_EQ(N_exp,N_exp);
N_bopExp BopExp_NE(N_exp,N_exp);
N_bopExp BopExp_GT(N_exp,N_exp);
N_bopExp BopExp_LT(N_exp,N_exp);
N_bopExp BopExp_GE(N_exp,N_exp);
N_bopExp BopExp_LE(N_exp,N_exp);
N_mopExp MopExp_NOT(N_exp);
N_mopExp MopExp_NEGATIVE(N_exp);

#endif
