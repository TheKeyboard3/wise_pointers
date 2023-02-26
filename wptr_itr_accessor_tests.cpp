#include "wptr_itr_accessor_tests.h"
#include <cstring>

namespace wptr_itr_accessor_tests{
    a::a(){
        i = 0;
    }

    a::a(int a){
        i=a;
    }

    a::a(const a& other){
        i = other.i;
    }

    void a::inc(){
        i++;
    }

    arrwrapper::arrwrapper(){
        size = 0;
        arr = nullptr;
    }

    arrwrapper::arrwrapper(int s){
        size = s;
        arr = new a[size];
        for(int i = 0; i < size; i++)arr[i]=a();
    }

    arrwrapper::arrwrapper(const wptr_itr_accessor_tests::arrwrapper& other)
    {
        size = other.size;
        arr = new a[size];
        for(int i = 0; i < size; i++)arr[i]=a(other.arr[i]);
    }

    arrwrapper::~arrwrapper(){
        if(arr!=nullptr)delete arr;
    }

    const arrwrapper& arrwrapper::operator=(const arrwrapper& other){
        if(arr!=nullptr)delete arr;
        size = other.size;
        arr = new a[size];
        for(int i = 0; i < size; i++)arr[i]=a(other.arr[i]);
        return other;
    }

    a& arrwrapper::operator[](int ind){
        return arr[ind];
    }

    int wptr_itr_accessor_test_constructor(){
        arrwrapper wrapper = arrwrapper(3);
        wrapper[0].i=88;
        wrapper[1].i=100;
        wrapper[2].i=94;
        wptr_itr_accessor<arrwrapper,int,a> acc = wptr_itr_accessor<arrwrapper,int,a>();
        if(acc.access(&wrapper)->i!=88)return 1;
        acc = wptr_itr_accessor<arrwrapper,int,a>(1);
        if(acc.access(&wrapper)->i!=100)return 1;
        return 0;
    }

    int wptr_itr_accessor_test_constructor_copy(){
        arrwrapper wrapper = arrwrapper(3);
        wrapper[0].i=88;
        wrapper[1].i=100;
        wrapper[2].i=94;
        wptr_itr_accessor<arrwrapper,int,a> acc = wptr_itr_accessor<arrwrapper,int,a>(1);
        if(acc.access(&wrapper)->i!=100)return 1;
        wptr_itr_accessor<arrwrapper,int,a> acc2 = wptr_itr_accessor<arrwrapper,int,a>(acc);
        if(acc2.access(&wrapper)->i!=100)return 1;
        return 0;
    }

    int wptr_itr_accessor_test_assignment(){
        arrwrapper wrapper = arrwrapper(3);
        wrapper[0].i=88;
        wrapper[1].i=100;
        wrapper[2].i=94;
        wptr_itr_accessor<arrwrapper,int,a> acc = wptr_itr_accessor<arrwrapper,int,a>(1);
        if(acc.access(&wrapper)->i!=100)return 1;
        wptr_itr_accessor<arrwrapper,int,a> acc2 = acc;
        if(acc2.access(&wrapper)->i!=100)return 1;
        return 0;
    }

    int wptr_itr_accessor_test_access(){
        arrwrapper wrapper = arrwrapper(3);
        wrapper[0].i=88;
        wrapper[1].i=100;
        wrapper[2].i=94;
        wptr_itr_accessor<arrwrapper,int,a> acc = wptr_itr_accessor<arrwrapper,int,a>(0);
        if(acc.access(&wrapper)->i!=88)return 1;
        acc = wptr_itr_accessor<arrwrapper,int,a>(1);
        if(acc.access(&wrapper)->i!=100)return 1;
        acc = wptr_itr_accessor<arrwrapper,int,a>(2);
        if(acc.access(&wrapper)->i!=94)return 1;
        return 0;
    }

    int wptr_itr_accessor_test_comparison(){
        wptr_itr_accessor<arrwrapper,int,a> acc1 = wptr_itr_accessor<arrwrapper,int,a>(1);
        wptr_itr_accessor<arrwrapper,int,a> acc2 = wptr_itr_accessor<arrwrapper,int,a>(0);
        wptr_itr_accessor<arrwrapper,int,a> acc3 = wptr_itr_accessor<arrwrapper,int,a>(1);
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
        test_exec(&wptr_itr_accessor_tests::wptr_itr_accessor_test_access,"wptr_itr_accessor_test_access"),
        test_exec(&wptr_itr_accessor_tests::wptr_itr_accessor_test_assignment,"wptr_itr_accessor_test_assignment"),
        test_exec(&wptr_itr_accessor_tests::wptr_itr_accessor_test_comparison,"wptr_itr_accessor_test_comparison"),
        test_exec(&wptr_itr_accessor_tests::wptr_itr_accessor_test_constructor,"wptr_itr_accessor_test_constructor"),
        test_exec(&wptr_itr_accessor_tests::wptr_itr_accessor_test_constructor_copy,"wptr_itr_accessor_test_constructor_copy"),
    };
    for(int i = 0; i < len; i++){
        if(strncmp((const char*)&tests[i].name,argv[1],(size_t)64)==0)return tests[i].func();
    }
    return -3;
}
