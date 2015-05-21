#include "lib.h"
#include "lucia.tab.h"
#include "message.h"
#include "ast.h"
#include "symbol.h"
extern FILE *yyin;
extern int yyparse(void);

S_table symbolTable;

int main(int argc,char** argv)
{
	// Create a symbol table
	symbolTable=ST_create();
		
	if(argc > 1){	
		FILE * file=fopen(argv[1],"r");
		if(!file)
			errorExit("Can't open source file\n");
		yyin = file;
	}
	yyparse();
	return 0;
}


