#include "lib.h"
#include "lucia.tab.h"
#include "message.h"
#include "ast.h"
#include "symbol.h"
#include "type.h"
extern FILE *yyin;
extern int yyparse(void);

/** Declaration a symbol table point. It's visible for 
	other objects. **/
S_table symbolTable;

/** Declaration the point of a abstract syntax tree.
	The point will point a abstract syntax tree which
	allocated by yyparse(), and the tree won't be 
	destroid even if yyparse() is over. This space can
	be used by other modules **/
N_prog asTree;

int main(int argc,char** argv)
{
	/** Create a symbol table **/
	symbolTable=ST_create();
	
	if(argc > 1){	
		FILE * file=fopen(argv[1],"r");
		if(!file)
			errorExit("Can't open source file\n");
		yyin = file;
	}
	/** Recieve tokens from yylex() and return a 
		absract syntax tree point. **/
	yyparse();

	return 0;
}


