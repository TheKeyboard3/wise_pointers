#include "wptr_managed_tests.h"
#include <cstring>

namespace wptr_managed_tests{
    a::a(){
        i = 0;
    }

    a::a(int a){
        i=a;
    }

    void a::inc(){
        i++;
    }

    int wptr_managed_test_constructor(){
        wptr_managed<a> i = wptr_managed<a>(a(65));
        return i->i!=65;
    }

    int wptr_managed_test_constructor_copy(){
        wptr_managed<a> i = wptr_managed<a>(a(65));
        wptr_managed<a> j = wptr_managed<a>(i);
        return j->i!=65;
    }

    int wptr_managed_test_reference(){
        wptr_managed<a> i = wptr_managed<a>(a(65));
        if(i.getRefCount()!=0)return 1;
        i.refc_inc();
        i.refc_inc();
        if(i.getRefCount()!=2)return 1;
        i.refc_dec();
        if(i.getRefCount()!=1)return 1;
        return 0;
    }

    int wptr_managed_test_member_access(){
        wptr_managed<a> i = wptr_managed<a>(a(65));
        if(i->i!=65)return 1;
        if((*i).i!=65)return 1;
        i->i++;
        if(i->i!=66)return 1;
        if((*i).i!=66)return 1;
        (*i).i--;
        if(i->i!=65)return 1;
        if((*i).i!=65)return 1;
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
        test_exec(&wptr_managed_tests::wptr_managed_test_constructor,"wptr_managed_test_constructor"),
        test_exec(&wptr_managed_tests::wptr_managed_test_constructor_copy,"wptr_managed_test_constructor_copy"),
        test_exec(&wptr_managed_tests::wptr_managed_test_member_access,"wptr_managed_test_member_access"),
        test_exec(&wptr_managed_tests::wptr_managed_test_reference,"wptr_managed_test_reference"),
    };
    for(int i = 0; i < len; i++){
        if(strncmp((const char*)&tests[i].name,argv[1],(size_t)64)==0)return tests[i].func();
    }
    return -3;
}
