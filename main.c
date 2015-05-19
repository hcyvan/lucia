/*************************************************************************
    > File Name: main.c
	> Author: hcyvan
	> Mail: navych@126.com 
	> Created Time: 2015年05月17日 星期日 15时47分01秒
************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "lib.h"
#include "lucia.tab.h"
#include "message.h"

extern FILE *yyin;
extern int yyparse(void);

string toknames[] = {
	"ID", "STRING", "INT", "COMMA", "COLON", "SEMICOLON", "LPAREN",
	"RPAREN", "LBRACK", "RBRACK", "LBRACE", "RBRACE", "DOT", "PLUS",
	"MINUS", "TIMES", "DIVIDE", "EQ", "NEQ", "LT", "LE", "GT", "GE",
	"AND", "OR", "ASSIGN", "ARRAY", "IF", "THEN", "ELSE", "WHILE", "FOR",
	"TO", "DO", "LET", "IN", "END", "OF", "BREAK", "NIL", "FUNCTION",
	"VAR", "TYPE"
};

string tokename(int tok)
{
	return tok<257 || tok>299 ? "BAD_TOK" : toknames[tok-257];
}

int main(int argc,char** argv)
{
	if(argc > 1){	
		FILE * file=fopen(argv[1],"r");
		if(!file){
			perror("Can't open source file\n");
			exit(EXIT_FAILURE);
		}	
		yyin = file;
	}
	yyparse();
	return 0;
}


