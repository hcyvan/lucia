#include "../include/syminfo.h"
#include "../include/lib.h"

S_info SI_create(void)
{
	S_info p=(S_info)checked_malloc(sizeof(*p));
	if(!p)
		errorExit("Can't malloc memory for S_info_\n");
	return p;
}


