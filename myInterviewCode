#include "stdafx.h"
#include <stdio.h>
#include <list>
#include <iostream>
using namespace std;

class Foo {
public:
    Foo() { cout << "1"; }
    Foo(const Foo &f) { cout << "2"; }
    Foo(Foo&& f) { cout << "3"; }
    void* operator new(size_t s) {
        cout << "4";
        return ::operator new(s);
    }
};

void Func(int a, int *p) {
    printf("%p, %p, %p", &a, &p, p);
}

class A {
public:
    A() { cout << "A"; }
};
class B {
public:
    B() { cout << "B"; }
};
class C:virtual public A {
public:
    C() { cout << "C"; }
};
class D:public B, public C {
public:
    D() { cout << "D"; }
};

D d;

int main()
{
    list<Foo> L;
    L.push_back(Foo());

    cout << endl;
    int a = 0, b = 0;
    Func(a, &b);
    return 0;
}
