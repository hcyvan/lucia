#ifndef _SYMINFO_H_
#define _SYMINFO_H_
#include "type.h"
typedef struct S_info_* S_info;
struct S_info_{
	Ty type;
	union{
		int ival;
		int bval;
		double dval;
		char * sval;	
		void* other;	// user-defined value
	} value;
};

	

S_info SI_create(void);



#endif
