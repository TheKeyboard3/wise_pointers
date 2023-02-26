#include "wptr_dereference_accessor_tests.h"
#include <cstring>

namespace wptr_dereference_accessor_tests{
    a::a(){
        i = 0;
    }

    a::a(int a){
        i = a;
    }

    int& a::operator*(){
        return i;
    }

    const wptr_dereference_accessor<a,int> acc = wptr_dereference_accessor<a,int>();

    int wptr_dereference_accessor_test_constructor(){
        wptr_dereference_accessor<a,int>* acc2 = new wptr_dereference_accessor<a,int>();
        a obj = a(65);
        if((*acc2->access(&obj))!=65)return 1;
        obj.i++;
        if((*acc2->access(&obj))!=66)return 2;
        return 0;
    }

    int wptr_dereference_accessor_test_constructor_copy(){
        const wptr_dereference_accessor<a,int> acc1 = wptr_dereference_accessor<a,int>();
        const wptr_dereference_accessor<a,int> acc2 = wptr_dereference_accessor<a,int>(acc1);
        a obj = a(65);
        if((*acc2.access(&obj))!=65)return 1;
        obj.i++;
        if((*acc2.access(&obj))!=66)return 2;
        return 0;
    }

    int wptr_dereference_accessor_test_assignment(){
        const wptr_dereference_accessor<a,int> acc1 = wptr_dereference_accessor<a,int>();
        const wptr_dereference_accessor<a,int> acc2 = acc1;
        a obj = a(65);
        if((*acc2.access(&obj))!=65)return 1;
        obj.i++;
        if((*acc2.access(&obj))!=66)return 2;
        return 0;
    }

    int wptr_dereference_accessor_test_access(){
        a obj = a(65);
        if((*acc.access(&obj))!=65)return 1;
        obj.i++;
        if((*acc.access(&obj))!=66)return 2;
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
        test_exec(&wptr_dereference_accessor_tests::wptr_dereference_accessor_test_access,"wptr_dereference_accessor_test_access"),
        test_exec(&wptr_dereference_accessor_tests::wptr_dereference_accessor_test_assignment,"wptr_dereference_accessor_test_assignment"),
        test_exec(&wptr_dereference_accessor_tests::wptr_dereference_accessor_test_constructor,"wptr_dereference_accessor_test_constructor"),
        test_exec(&wptr_dereference_accessor_tests::wptr_dereference_accessor_test_constructor_copy,"wptr_dereference_accessor_test_constructor_copy"),
    };
    for(int i = 0; i < len; i++){
        if(strncmp((const char*)&tests[i].name,argv[1],(size_t)64)==0)return tests[i].func();
    }
    return -3;
}
