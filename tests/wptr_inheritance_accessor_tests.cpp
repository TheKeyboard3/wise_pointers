#include "wptr_inheritance_accessor_tests.h"
#include <cstring>

namespace wptr_inheritance_accessor_tests{
    a::a(){
        i = 0;
    }

    a::a(int a){
        i=a;
    }

    void a::inc(){
        i++;
    }

    b::b() : a(){
        k = 0;
    }

    b::b(int u, int b) : a(u){
        k=b;
    }

    void b::incb(){
        k++;
    }

    const wptr_inheritance_accessor<b,a> acc = wptr_inheritance_accessor<b,a>();


    int wptr_inheritance_accessor_test_constructor(){
        wptr_inheritance_accessor<b,a>* acc2 = new wptr_inheritance_accessor<b,a>();
        b obj = b(65,85);
        if((*acc2->access(&obj)).i!=65)return 1;
        obj.incb();
        if((*acc2->access(&obj)).i!=65)return 2;
        if(obj.k!=86)return 3;
        if(obj.i!=65)return 4;
        obj.inc();
        if((*acc2->access(&obj)).i!=66)return 5;
        if(obj.k!=86)return 6;
        if(obj.i!=66)return 7;
        delete acc2;
        return 0;
    }

    int wptr_inheritance_accessor_test_constructor_copy(){
        wptr_inheritance_accessor<b,a> acc1 = wptr_inheritance_accessor<b,a>();
        wptr_inheritance_accessor<b,a> acc2 = wptr_inheritance_accessor<b,a>(acc1);
        b obj = b(65,85);
        if((*acc2.access(&obj)).i!=65)return 1;
        obj.incb();
        if((*acc2.access(&obj)).i!=65)return 2;
        if(obj.k!=86)return 3;
        if(obj.i!=65)return 4;
        obj.inc();
        if((*acc2.access(&obj)).i!=66)return 5;
        if(obj.k!=86)return 6;
        if(obj.i!=66)return 7;
        return 0;
    }

    int wptr_inheritance_accessor_test_assignment(){
        wptr_inheritance_accessor<b,a> acc1 = wptr_inheritance_accessor<b,a>();
        wptr_inheritance_accessor<b,a> acc2 = acc1;
        b obj = b(65,85);
        if((*acc2.access(&obj)).i!=65)return 1;
        obj.incb();
        if((*acc2.access(&obj)).i!=65)return 2;
        if(obj.k!=86)return 3;
        if(obj.i!=65)return 4;
        obj.inc();
        if((*acc2.access(&obj)).i!=66)return 5;
        if(obj.k!=86)return 6;
        if(obj.i!=66)return 7;
        return 0;
    }


    int wptr_inheritance_accessor_test_access(){
        b obj = b(65,85);
        if((*acc.access(&obj)).i!=65)return 1;
        obj.incb();
        if((*acc.access(&obj)).i!=65)return 2;
        if(obj.k!=86)return 3;
        if(obj.i!=65)return 4;
        obj.inc();
        if((*acc.access(&obj)).i!=66)return 5;
        if(obj.k!=86)return 6;
        if(obj.i!=66)return 7;
        return 0;
    }
}

struct test_exec{
    int (*func)();
    char name[64];
    test_exec(int (*test_func)(), const char* str){
        func = test_func;
        strncpy((char*)&name,str,(size_t)63);
        name[63]='\0';
    }
};

int main(int argc, char **argv) {
    if(argc!=2)return argc;
    if(argv==nullptr)return -2;
    const int len = 4;
    test_exec tests[len] = {
        test_exec(&wptr_inheritance_accessor_tests::wptr_inheritance_accessor_test_access,"wptr_inheritance_accessor_test_access"),
        test_exec(&wptr_inheritance_accessor_tests::wptr_inheritance_accessor_test_assignment,"wptr_inheritance_accessor_test_assignment"),
        test_exec(&wptr_inheritance_accessor_tests::wptr_inheritance_accessor_test_constructor,"wptr_inheritance_accessor_test_constructor"),
        test_exec(&wptr_inheritance_accessor_tests::wptr_inheritance_accessor_test_constructor_copy,"wptr_inheritance_accessor_test_constructor_copy"),
    };
    for(int i = 0; i < len; i++){
        if(strncmp((const char*)&tests[i].name,argv[1],(size_t)64)==0)return tests[i].func();
    }
    return -3;
}
