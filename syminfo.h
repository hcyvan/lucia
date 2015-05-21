#ifndef _SYMINFO_H_
#define _SYMINFO_H_
#include "type.h"
typedef struct S_info_* S_info;
struct S_info_{
	Ty type;
	union{
		int ival;
		double dval;
		char* sval;
	} val;
};

	

S_info SI_create(void);



#endif
