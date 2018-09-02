#include <stdio.h>
#include "mylib.h"

// 1. run before main
int add(int a, int b)
{
	printf("before main plus func\n");
	return a+b;
}

int d = 10;
int e = 20;
int c = add(d, e);
//add(d,e);

int main()
{
	// 2. static test
	printf("B::a(init) = %d\n", B::a);
	B::a = 4;
	printf("B::a = %d\n", B::a);
	B* bptr = new B();
	printf("B::a(bptr) = %d\n", bptr->a);

	// 3. globle extern in .h test
    printf("a = %d\n", a);

	// 4. class declare test
	B* bptr2 = b_factory(bptr);
	bptr2->show();

	return 0;
}
