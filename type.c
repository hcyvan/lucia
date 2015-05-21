#include "type.h"

static struct Ty_ tynil={Ty_nil};
static struct Ty_ tyint={Ty_int};
static struct Ty_ tystring={Ty_string};
static struct Ty_ tyvoid={Ty_void};

Ty Ty_Nil(void)
{
	return &tynil;
}

Ty Ty_Int(void)
{
	return &tyint;
}

Ty Ty_String(void)
{
	return &tystring;
}

Ty Ty_Void(void)
{
	return &tyvoid;
}

