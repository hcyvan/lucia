#ifndef _TYPE_H_
#define _TYPE_H_

typedef struct Ty_* Ty;

struct Ty_ {
	enum{Ty_nil,Ty_int,Ty_double,Ty_string,Ty_bool,Ty_void} kind;
	union{
	} u;
};
Ty Ty_Nil(void);
Ty Ty_Int(void);
Ty Ty_Double(void);
Ty Ty_String(void);
Ty Ty_Bool(void);
Ty Ty_Void(void);

#endif
