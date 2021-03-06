%{
#include "../include/message.h"
#include "../include/ast.h"
#include "../include/lib.h"
//#include "symbol.h"
//#include "table.h"
extern int yylineno;		// yylineno is the line number of source
//extern struct T_table_ *symboltable; 

/** The root point of a abstract syntax tree.
	The point is declared in main.o, and won't
	be destroied even yyparse() is finished.**/
extern N_prog asTree;

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
	struct N_prog_* progt;
	struct N_stmList_* stmListt;
	struct N_stm_* stmt;
	struct N_exp_* expt;
	struct N_bopExp_* bopExpt;
	struct N_mopExp_* mopExpt;
	struct N_const_* constt;
}

%token <sval> ID
%token <ival> INT
%token <dval> DOUBLE
%token <cval> CHAR
%token <sval> STRING
%token <sval> BOOL
%token 	AND OR NOT IF EQ NE GT LT GE LE 

%type <progt> n_prog
%type <stmListt> n_stmList
%type <stmt> n_stm
%type <expt> n_exp
%type <bopExpt> n_bopExp
%type <mopExpt> n_mopExp
%type <constt> n_const


%start n_prog
%nonassoc NEGATIVE
%left OR
%left AND
%left EQ NE GT LT GE LE
%left '+' '-'
%left '*' '/'
%left '^'
%right NOT
%%
n_prog: n_stmList		{asTree=Prog_STMLIST($1);return 0;}
		;
n_stmList:n_stmList n_stm  {$$=StmList_STMLIST($1,$2);}
		| n_stm 		{$$=StmList_STM($1);}				
		;
n_stm: ID '=' n_exp	';'	{$$=Stm_ASSIGN($1,$3);}
	| n_exp			';'		{$$=Stm_EXP($1);}
	| '?' n_exp		';'		{$$=Stm_PRINT($2);}
	| IF '(' n_exp ')''{'n_stmList '}' {$$=Stm_IFSTM($3,$6);}
	| ';'					{;}
	;
n_exp: 	n_const				{$$=Exp_CONST($1);}
		| ID				{$$=Exp_IDS($1);}
		| n_bopExp			{$$=Exp_BOPEXP($1);}
		| n_mopExp			{$$=Exp_MOPEXP($1);}
		;
n_bopExp:n_exp '+' n_exp	{$$=BopExp_PLUS($1,$3);}
	    | n_exp '-' n_exp	{$$=BopExp_MINUS($1,$3);}
	    | n_exp '*' n_exp	{$$=BopExp_TIMES($1,$3);}
        | n_exp '/' n_exp	{$$=BopExp_DIVIDE($1,$3);}
		| n_exp '^' n_exp	{$$=BopExp_POW($1,$3);}
		| n_exp AND n_exp	{$$=BopExp_AND($1,$3);}
		| n_exp OR n_exp	{$$=BopExp_OR($1,$3);}
		| n_exp EQ n_exp	{$$=BopExp_EQ($1,$3);}
		| n_exp NE n_exp	{$$=BopExp_NE($1,$3);}
		| n_exp GT n_exp	{$$=BopExp_GT($1,$3);}
		| n_exp LT n_exp	{$$=BopExp_LT($1,$3);}
		| n_exp GE n_exp	{$$=BopExp_GE($1,$3);}
		| n_exp LE n_exp	{$$=BopExp_LE($1,$3);}
		;
n_mopExp:'-' n_exp %prec NEGATIVE			{$$=MopExp_NEGATIVE($2);}
		| NOT n_exp			{$$=MopExp_NOT($2);}
		;

n_const:INT				{$$=Const_INT($1);}
		| DOUBLE		{$$=Const_DOUBLE($1);}
		| CHAR			{$$=Const_CHAR($1);}
		| STRING		{$$=Const_STRING($1);}
		| BOOL			{$$=Const_BOOL($1);}
		;





