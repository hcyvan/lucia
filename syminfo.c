#include "syminfo.h"
#include "lib.h"

S_info SI_create(void)
{
	S_info p=(S_info)checked_malloc(sizeof(*p));
	return p;
}


