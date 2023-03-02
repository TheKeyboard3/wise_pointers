#include "wptr_offset_accessor_tests.h"
#include <stddef.h>
#include <cstring>

namespace wptr_offset_accessor_tests{
    a::a(){
        i = 0;
    }

    a::a(int a){
        i = a;
    }

    b::b(){
        aaa = a(0);
        k = 0;
    }

    b::b(int u, int b){
        aaa = a(u);
        k = b;
    }

    int wptr_offset_accessor_test_constructor(){
        wptr_offset_accessor<b,a>* acc = new wptr_offset_accessor<b,a>(offsetof(b,aaa));
        b vr = b(65,87);
        if(acc->access(&vr)->i!=65)return 1;
        acc->access(&vr)->i++;
        if(acc->access(&vr)->i!=66)return 1;
        if(vr.k!=87)return 1;
        if(vr.aaa.i!=66)return 1;
        vr.aaa.i++;
        if(acc->access(&vr)->i!=67)return 1;
        return 0;
    }

    int wptr_offset_accessor_test_constructor_copy(){
        wptr_offset_accessor<b,a> acc2 = wptr_offset_accessor<b,a>(offsetof(b,aaa));
        wptr_offset_accessor<b,a> acc = wptr_offset_accessor<b,a>(acc2);
        b vr = b(65,87);
        if(acc.access(&vr)->i!=65)return 1;
        acc.access(&vr)->i++;
        if(acc.access(&vr)->i!=66)return 1;
        if(vr.k!=87)return 1;
        if(vr.aaa.i!=66)return 1;
        vr.aaa.i++;
        if(acc.access(&vr)->i!=67)return 1;
        return 0;
    }

    int wptr_offset_accessor_test_assignment(){
        wptr_offset_accessor<b,a> acc2 = wptr_offset_accessor<b,a>(offsetof(b,aaa));
        wptr_offset_accessor<b,a> acc = acc2;
        b vr = b(65,87);
        if(acc.access(&vr)->i!=65)return 1;
        acc.access(&vr)->i++;
        if(acc.access(&vr)->i!=66)return 1;
        if(vr.k!=87)return 1;
        if(vr.aaa.i!=66)return 1;
        vr.aaa.i++;
        if(acc.access(&vr)->i!=67)return 1;
        return 0;
    }

    int wptr_offset_accessor_test_access(){
        wptr_offset_accessor<b,a> acc = wptr_offset_accessor<b,a>(offsetof(b,aaa));
        b vr = b(65,87);
        if(acc.access(&vr)->i!=65)return 1;
        acc.access(&vr)->i++;
        if(acc.access(&vr)->i!=66)return 1;
        if(vr.k!=87)return 1;
        if(vr.aaa.i!=66)return 1;
        vr.aaa.i++;
        if(acc.access(&vr)->i!=67)return 1;
        return 0;
    }

    int wptr_offset_accessor_test_comparison(){
        wptr_offset_accessor<b,a> acc1 = wptr_offset_accessor<b,a>(0);
        wptr_offset_accessor<b,a> acc2 = wptr_offset_accessor<b,a>(1);
        wptr_offset_accessor<b,a> acc3 = wptr_offset_accessor<b,a>(0);
        if(acc1==acc2)return 1;
        if(acc1!=acc3)return 2;
        if(acc2==acc1)return 3;
        if(acc2==acc3)return 4;
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
    const int len = 5;
    test_exec tests[len] = {
        test_exec(&wptr_offset_accessor_tests::wptr_offset_accessor_test_access,"wptr_offset_accessor_test_access"),
        test_exec(&wptr_offset_accessor_tests::wptr_offset_accessor_test_assignment,"wptr_offset_accessor_test_assignment"),
        test_exec(&wptr_offset_accessor_tests::wptr_offset_accessor_test_comparison,"wptr_offset_accessor_test_comparison"),
        test_exec(&wptr_offset_accessor_tests::wptr_offset_accessor_test_constructor,"wptr_offset_accessor_test_constructor"),
        test_exec(&wptr_offset_accessor_tests::wptr_offset_accessor_test_constructor_copy,"wptr_offset_accessor_test_constructor_copy"),
    };
    for(int i = 0; i < len; i++){
        if(strncmp((const char*)&tests[i].name,argv[1],(size_t)64)==0)return tests[i].func();
    }
    return -3;
}
