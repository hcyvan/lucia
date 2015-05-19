%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lucia.tab.h"
#include "message.h"
int column=1;
int yywrap(void)
{
	return 1;
}
void updatePosition()
{
	col=column;	
	column+=yyleng;
}
void newline()
{
	line+=1;
	column=1;
}
	
%}
%%
" "|\t						{updatePosition();}
\n							{newline();return yytext[0];}
","	 						{updatePosition();yylval.sval=yytext;return COMMA;}
for  					 	{updatePosition();yylval.sval=yytext;return FOR;}
[0-9]+					 	{updatePosition();yylval.ival=atoi(yytext);return INT;}
[_A-Za-z][_A-Za-z0-9]*		{updatePosition();yylval.tab=checkTable(yytext);return ID;}
.	 						{updatePosition();return yytext[0];}
