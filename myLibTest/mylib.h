extern int a;

// 1. class B 的 forward declaration(.cpp中实现不行，.h中实现可以)，
//    struct C 的 forward declaration(.cpp .h中实现都可以)。
// 问题源头 - skynet源代码中在头文件里出现了struct skynet_message;之类的声明
class B{
public:
    static int a;
    void show();
};

B* b_factory(B* b_instance);

struct C;

C* c_func(C* c_in);
