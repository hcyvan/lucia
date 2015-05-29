#include "type.h"

struct Ty_ tynil={Ty_nil};
struct Ty_ tyint={Ty_int};
struct Ty_ tydouble={Ty_double};
struct Ty_ tystring={Ty_string};
struct Ty_ tybool={Ty_bool};
struct Ty_ tyvoid={Ty_void};
Ty Ty_Nil(void)
{
	return &tynil;
}

Ty Ty_Int(void)
{
	return &tyint;
}
Ty Ty_Double(void)
{
	return &tydouble;
}

Ty Ty_String(void)
{
	return &tystring;
}

Ty Ty_Bool(void)
{
	return &tybool;
}

Ty Ty_Void(void)
{
	return &tyvoid;
}
