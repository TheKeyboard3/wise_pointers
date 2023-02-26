#include "wptr_accessor_wrap_tests.h"
#include "wptr_no_accessor.h"
#include "wptr_simple.h"
#include <cstring>

namespace wptr_accessor_wrap_tests{
    a::a(){

    }

    a::a(int a){
        i = a;
    }

    void a::inc(){
        i++;
    }

    int wptr_accessor_wrap_test_constructor(){
        wptr_inheritance<wptr_no_accessor<a>,wptr_accessor<a,a>> na_ptr = wptr_inheritance<wptr_no_accessor<a>,wptr_accessor<a,a>>(wptr_no_accessor<a>());
        wptr_simple<a> val_ptr = wptr_simple<a>(a(65));
        wptr_accessor_wrap<a,a>* waw2 = new wptr_accessor_wrap<a,a>(&val_ptr,(wptr_readable<wptr_accessor<a,a>>*)&na_ptr);
        wptr_accessor_wrap<a,a>* waw = new wptr_accessor_wrap<a,a>();
        *waw = *waw2;
        if(waw->access()->i!=65)return 1;
        waw->access()->inc();
        if(waw->access()->i!=66)return 2;
        delete waw;
        delete waw2;
        return 0;
    }

    int wptr_accessor_wrap_test_constructor_readable(){
        wptr_inheritance<wptr_no_accessor<a>,wptr_accessor<a,a>> na_ptr = wptr_inheritance<wptr_no_accessor<a>,wptr_accessor<a,a>>(wptr_no_accessor<a>());
        wptr_simple<a> val_ptr = wptr_simple<a>(a(65));
        wptr_accessor_wrap<a,a>* waw = new wptr_accessor_wrap<a,a>(&val_ptr,(wptr_readable<wptr_accessor<a,a>>*)&na_ptr);
        if(waw->access()->i!=65)return 1;
        waw->access()->inc();
        if(waw->access()->i!=66)return 2;
        delete waw;
        return 0;
    }

    int wptr_accessor_wrap_test_constructor_base_readable(){
        wptr_simple<wptr_no_accessor<a>> na_ptr = wptr_simple<wptr_no_accessor<a>>(wptr_no_accessor<a>());
        wptr_simple<a> val_ptr = wptr_simple<a>(a(65));
        wptr_accessor_wrap<a,a>* waw = new wptr_accessor_wrap<a,a>(&val_ptr,(wptr_base_readable<wptr_no_accessor<a>>*)&na_ptr);
        if(waw->access()->i!=65)return 1;
        waw->access()->inc();
        if(waw->access()->i!=66)return 2;
        delete waw;
        return 0;
    }

    int wptr_accessor_wrap_test_constructor_copy(){
        wptr_simple<wptr_no_accessor<a>> na_ptr = wptr_simple<wptr_no_accessor<a>>(wptr_no_accessor<a>());
        wptr_simple<a> val_ptr = wptr_simple<a>(a(65));
        wptr_accessor_wrap<a,a>* waw2 = new wptr_accessor_wrap<a,a>(&val_ptr,(wptr_base_readable<wptr_no_accessor<a>>*)&na_ptr);
        wptr_accessor_wrap<a,a>* waw = new wptr_accessor_wrap<a,a>(*waw2);
        if(waw->access()->i!=65)return 1;
        waw->access()->inc();
        if(waw->access()->i!=66)return 2;
        delete waw;
        delete waw2;
        return 0;
    }

    int wptr_accessor_wrap_test_assignment(){
        wptr_simple<wptr_no_accessor<a>> na_ptr = wptr_simple<wptr_no_accessor<a>>(wptr_no_accessor<a>());
        wptr_simple<a> val_ptr = wptr_simple<a>(a(65));
        wptr_accessor_wrap<a,a>* waw2 = new wptr_accessor_wrap<a,a>(&val_ptr,(wptr_base_readable<wptr_no_accessor<a>>*)&na_ptr);
        wptr_accessor_wrap<a,a>* waw = new wptr_accessor_wrap<a,a>();
        *waw = *waw2;
        if(waw->access()->i!=65)return 1;
        waw->access()->inc();
        if(waw->access()->i!=66)return 2;
        delete waw;
        delete waw2;
        return 0;
    }

    int wptr_accessor_wrap_test_comparison(){
        wptr_simple<wptr_no_accessor<a>> na_ptr = wptr_simple<wptr_no_accessor<a>>(wptr_no_accessor<a>());
        wptr_simple<a> val_ptr = wptr_simple<a>(a(65));
        wptr_accessor_wrap<a,a>* waw2 = new wptr_accessor_wrap<a,a>(&val_ptr,(wptr_base_readable<wptr_no_accessor<a>>*)&na_ptr);
        wptr_accessor_wrap<a,a>* waw = new wptr_accessor_wrap<a,a>();
        *waw = *waw2;
        if(!(*waw==val_ptr))return 1;
        if(*waw!=val_ptr)return 2;
        if(!(*waw==*waw2))return 3;
        if(*waw!=*waw2)return 4;
        delete waw;
        delete waw2;
        return 0;
    }

    int wptr_accessor_wrap_test_access(){
        wptr_simple<wptr_no_accessor<a>> na_ptr = wptr_simple<wptr_no_accessor<a>>(wptr_no_accessor<a>());
        wptr_simple<a> val_ptr = wptr_simple<a>(a(65));
        wptr_accessor_wrap<a,a>* waw = new wptr_accessor_wrap<a,a>(&val_ptr,(wptr_readable<wptr_accessor<a,a>>*)&na_ptr);
        if(waw->access()->i!=65)return 1;
        waw->access()->inc();
        if(waw->access()->i!=66)return 2;
        delete waw;
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
    const int len = 7;
    test_exec tests[len] = {
        test_exec(&wptr_accessor_wrap_tests::wptr_accessor_wrap_test_access,"wptr_accessor_wrap_test_access"),
        test_exec(&wptr_accessor_wrap_tests::wptr_accessor_wrap_test_assignment,"wptr_accessor_wrap_test_assignment"),
        test_exec(&wptr_accessor_wrap_tests::wptr_accessor_wrap_test_comparison,"wptr_accessor_wrap_test_comparison"),
        test_exec(&wptr_accessor_wrap_tests::wptr_accessor_wrap_test_constructor,"wptr_accessor_wrap_test_constructor"),
        test_exec(&wptr_accessor_wrap_tests::wptr_accessor_wrap_test_constructor_base_readable,"wptr_accessor_wrap_test_constructor_base_readable"),
        test_exec(&wptr_accessor_wrap_tests::wptr_accessor_wrap_test_constructor_copy,"wptr_accessor_wrap_test_constructor_copy"),
        test_exec(&wptr_accessor_wrap_tests::wptr_accessor_wrap_test_constructor_readable,"wptr_accessor_wrap_test_constructor_readable"),
    };
    for(int i = 0; i < len; i++){
        if(strncmp((const char*)&tests[i].name,argv[1],(size_t)64)==0)return tests[i].func();
    }
    return -3;
}
