#include "mylib.h"
#include <stdio.h>

struct C{
	int a;
	int b;
};

C* c_func(C* cptr){ return cptr; }

int a = 5;

/*
class B{
public:
    static int a;
    void show();
};
*/

void B::show(){
	printf("b hello\n"); 
}

int B::a = 1;

void myPrint(){
	printf("hello inline\n");
}

B* b_factory(B* b_ptr){
    B* ret = new B(*b_ptr);
    return ret;
}

