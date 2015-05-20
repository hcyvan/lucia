%{
#include "message.h"
#include "ast.h"
#include "lib.h"
extern int yylineno;		//yylineno is the line number of source
int yyerror(char* msg)
{
	printf("%s : %d\n",msg,yylineno); 
	exit(EXIT_FAILURE);
}
int yylex(void);
%}

%union{
	int pos;
	int ival;
	double dval;
	char cval;
	char* sval;
	struct N_value_* valt;
	struct N_exp_* expt;
	struct N_bopExp_* bopExpt;
	struct N_stm_* stmt;
	struct N_stmList_* stmListt;
	struct N_prog_* progt;
}
%token <sval> ID
%token <ival> VALUE
%token <ival> INT
%token <dval> DOUBLE
%token <cval> CHAR

%type <valt> n_value
%type <expt> n_exp
%type <bopExpt> n_bopExp
%type <stmt> n_stm
%type <stmListt> n_stmList
%type <progt> n_prog


%start n_prog
%left '+' '-'
%left '*' '/'
%%
n_prog: n_stmList				{$$=Prog_STMLIST($1);}
n_stmList:n_stmList n_stm  '\n'	{$$=StmList_STMLIST($1,$2);}
		| n_stm  '\n'			{$$=StmList_STM($1);}				
		;
n_stm: ID '=' n_exp			{$$=Stm_ASSIGN($1,$3);}
		| n_exp				{$$=Stm_EXP($1);}
		| '?' n_exp			{$$=Stm_PRINT($2);}
		;
n_exp: n_bopExp				{$$=Exp_BOPEXP($1);}
		| ID				{$$=Exp_IDS($1);}
		| n_value			{$$=Exp_VALUES($1);}
		;
n_bopExp:n_exp '+' n_exp	{$$=BopExp_PLUS($1,$3);}
	    | n_exp '-' n_exp	{$$=BopExp_MINUS($1,$3);}
	    | n_exp '*' n_exp	{$$=BopExp_TIMES($1,$3);}
        | n_exp '/' n_exp	{$$=BopExp_DIVIDE($1,$3);}


n_value:INT				{$$=Value_INT($1);}
		| DOUBLE		{$$=Value_DOUBLE($1);}
		| CHAR			{$$=Value_CHAR($1);}
		;







