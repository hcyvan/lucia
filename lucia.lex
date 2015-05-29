%{
#include "lucia.tab.h"
#include "message.h"
#include "lib.h"
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
%option yylineno
%%
[0-9]+					 	{updatePosition();yylval.ival=atoi(yytext);return INT;}
[0-9]*\.[0-9]+				{updatePosition();yylval.dval=atof(yytext);return DOUBLE;}
true						{updatePosition();yylval.sval=yytext;return BOOL;}
false                       {updatePosition();yylval.sval=yytext;return BOOL;}
if							{updatePosition();return IF;}
&&							{updatePosition();return AND;}
\|\|						{updatePosition();return OR;}
!							{updatePosition();return NOT;}
==							{updatePosition();return EQ;}
!=                          {updatePosition();return NE;}
>                           {updatePosition();return GT;}
\<                           {updatePosition();return LT;}
=>							{updatePosition();return GE;}
\<=                          {updatePosition();return LE;}
[_A-Za-z][_A-Za-z0-9]*		{updatePosition();yylval.sval=strdup(yytext);return ID;}
\"[^\"]*\"						{updatePosition();yylval.sval=yytext;return STRING;}
" "|\t						{updatePosition();}
\n							{newline();}
.	 						{updatePosition();return yytext[0];}
