%{
#include <stdio.h>
#include <stdlib.h>
#include "message.h"
int yyerror(char* msg)
{
	printf("%s\n",msg);                                                         
	exit(EXIT_FAILURE);
}
int yylex(void);
%}

%union{
	int pos;
	int ival;
	char* sval;
	struct _symtab* tab;
}
%token <tab> ID
%token <ival> STRING INT COMMA COLON SEMICOLON LPAREN RPAREN LBRACK RBRACK LBRACE RBRACE DOT PLUS MINUS TIMES DIVIDE EQ NEQ LT LE GT GE AND OR ASSIGN ARRAY IF THEN ELSE WHILE FOR TO DO LET IN END OF BREAK NIL FUNCTION VAR TYPE 

%type <ival> exp
%%
stmList:stmList stm '\n'
		| stm '\n'
		;
stm: ID '=' exp		{$1->val=$3;}
	| '?' exp		{printf("%d\n",$2);}
	| exp
	;
exp :'(' exp ')'	{$$=$2;}	
	| exp '+' exp	{$$=$1+$3;}
	| exp '-' exp	{$$=$1-$3;}
	| exp '*' exp	{$$=$1*$3;}
	| exp '/' exp	{$$=$1/$3;}
	| '-' exp		{$$=-$2;}
	| ID			{$$=$1->val;}
	| INT			{$$=$1;}
	;
