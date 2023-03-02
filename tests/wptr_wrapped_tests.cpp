#include "wptr_wrapped_tests.h"
#include "../wptr_simple.h"
#include "../wptr_inheritance.h"
#include "../wptr_no_accessor.h"
#include <cstring>

namespace wptr_wrapped_tests{
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

    int wptr_wrapped_test_constructor(){
        wptr_wrapped<a> wrapped = wptr_wrapped<a>();
        if(!wrapped.empty())return 1;
        return 0;
    }

    int wptr_wrapped_test_constructor_object(){
        wptr_wrapped<a>* wrapped = new wptr_wrapped<a>(a(65));
        if((*wrapped)->i!=65)return 1;
        (*wrapped)->i++;
        if((*wrapped)->i!=66)return 2;
        delete wrapped;
        return 0;
    }

    int wptr_wrapped_test_constructor_object_readable(){
        wptr_inheritance<wptr_no_accessor<a>,wptr_accessor<a,a>> acc_ptr = wptr_inheritance<wptr_no_accessor<a>,wptr_accessor<a,a>>(wptr_no_accessor<a>());
        wptr_wrapped<a> wrapped = wptr_wrapped<a>(a(65),(wptr_readable<wptr_accessor<a,a>>*)&acc_ptr);
        if(wrapped->i!=65)return 1;
        wrapped->i++;
        if(wrapped->i!=66)return 2;
        return 0;
    }

    int wptr_wrapped_test_constructor_base_readable_readable(){
        wptr_simple<a> a_ptr = wptr_simple<a>(a(65));
        wptr_inheritance<wptr_no_accessor<a>,wptr_accessor<a,a>> acc_ptr = wptr_inheritance<wptr_no_accessor<a>,wptr_accessor<a,a>>(wptr_no_accessor<a>());
        wptr_wrapped<a> wrapped = wptr_wrapped<a>(*((wptr_base_readable<a>*)&a_ptr),(wptr_readable<wptr_accessor<a,a>>*)&acc_ptr);
        if(wrapped->i!=65)return 1;
        if(a_ptr->i!=65)return 2;
        wrapped->i++;
        if(wrapped->i!=66)return 3;
        if(a_ptr->i!=66)return 4;
        return 0;
    }

    int wptr_wrapped_test_constructor_copy(){
        wptr_simple<a> a_ptr = wptr_simple<a>(a(65));
        wptr_inheritance<wptr_no_accessor<a>,wptr_accessor<a,a>> acc_ptr = wptr_inheritance<wptr_no_accessor<a>,wptr_accessor<a,a>>(wptr_no_accessor<a>());
        wptr_wrapped<a> wrapped2 = wptr_wrapped<a>(*((wptr_base_readable<a>*)&a_ptr),(wptr_readable<wptr_accessor<a,a>>*)&acc_ptr);
        wptr_wrapped<a> wrapped = wptr_wrapped<a>(wrapped2);
        if(wrapped->i!=65)return 1;
        if(wrapped2->i!=65)return 2;
        if(a_ptr->i!=65)return 3;
        wrapped->i++;
        if(wrapped->i!=66)return 4;
        if(wrapped2->i!=66)return 5;
        if(a_ptr->i!=66)return 6;
        return 0;
    }

    int wptr_wrapped_test_constructor_base_readable(){
        wptr_simple<a> a_ptr = wptr_simple<a>(a(65));
        wptr_wrapped<a> wrapped = wptr_wrapped<a>(*((wptr_base_readable<a>*)&a_ptr));
        if(wrapped->i!=65)return 1;
        if(a_ptr->i!=65)return 2;
        wrapped->i++;
        if(wrapped->i!=66)return 3;
        if(a_ptr->i!=66)return 4;
        return 0;
    }

    int wptr_wrapped_test_assignment(){
        wptr_simple<a> a_ptr = wptr_simple<a>(a(65));
        wptr_wrapped<a> wrapped = wptr_wrapped<a>();
        wrapped = a_ptr;
        if(wrapped->i!=65)return 1;
        if(a_ptr->i!=65)return 2;
        wrapped->i++;
        if(wrapped->i!=66)return 3;
        if(a_ptr->i!=66)return 4;
        return 0;
    }

    int wptr_wrapped_test_member_access(){
        wptr_simple<a> a_ptr = wptr_simple<a>(a(65));
        wptr_wrapped<a> wrapped = wptr_wrapped<a>();
        wrapped = a_ptr;
        if(wrapped->i!=65)return 1;
        if((*wrapped).i!=65)return 2;
        if(a_ptr->i!=65)return 3;
        wrapped->i++;
        if(wrapped->i!=66)return 4;
        if((*wrapped).i!=66)return 5;
        if(a_ptr->i!=66)return 6;
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
    const int len = 8;
    test_exec tests[len] = {
        test_exec(&wptr_wrapped_tests::wptr_wrapped_test_assignment,"wptr_wrapped_test_assignment"),
        test_exec(&wptr_wrapped_tests::wptr_wrapped_test_constructor,"wptr_wrapped_test_constructor"),
        test_exec(&wptr_wrapped_tests::wptr_wrapped_test_constructor_base_readable,"wptr_wrapped_test_constructor_base_readable"),
        test_exec(&wptr_wrapped_tests::wptr_wrapped_test_constructor_base_readable_readable,"wptr_wrapped_test_constructor_base_readable_readable"),
        test_exec(&wptr_wrapped_tests::wptr_wrapped_test_constructor_copy,"wptr_wrapped_test_constructor_copy"),
        test_exec(&wptr_wrapped_tests::wptr_wrapped_test_constructor_object,"wptr_wrapped_test_constructor_object"),
        test_exec(&wptr_wrapped_tests::wptr_wrapped_test_constructor_object_readable,"wptr_wrapped_test_constructor_object_readable"),
        test_exec(&wptr_wrapped_tests::wptr_wrapped_test_member_access,"wptr_wrapped_test_member_access"),
    };
    for(int i = 0; i < len; i++){
        if(strncmp((const char*)&tests[i].name,argv[1],(size_t)64)==0)return tests[i].func();
    }
    return -3;
}
