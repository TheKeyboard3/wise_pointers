#include "wptr_complex_tests.h"
#include "../wptr_simple.h"
#include "../wptr_itr_accessor.h"
#include "../wptr_inheritance.h"
#include <cstring>

namespace wptr_complex_tests{
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

    arrwrapper::arrwrapper(const wptr_complex_tests::arrwrapper& other)
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

    int wptr_complex_test_constructor(){
        wptr_complex<arrwrapper,a> i;
        wptr_complex<arrwrapper,a> i2;
        wptr_simple<arrwrapper> aws = wptr_simple<arrwrapper>(arrwrapper(3));
        wptr_simple<wptr_itr_accessor<arrwrapper,int,a>> ws = wptr_simple<wptr_itr_accessor<arrwrapper,int,a>>(wptr_itr_accessor<arrwrapper,int,a>(0));
        if(!i2.empty())return 1;
        if(!i.empty())return 1;
        i2=aws;
        i.setAccessor((wptr_base_readable<wptr_itr_accessor<arrwrapper,int,a>>*)&ws);
        if(!i2.empty())return 1;
        if(!i.empty())return 1;
        i=aws;
        i2.setAccessor((wptr_base_readable<wptr_itr_accessor<arrwrapper,int,a>>*)&ws);
        if(i2.empty())return 1;
        if(i.empty())return 1;
        return 0;
    }

    int wptr_complex_test_constructor_obj_readable(){
        wptr_inheritance<wptr_itr_accessor<arrwrapper,int,a>,wptr_accessor<arrwrapper,a>> ws = wptr_inheritance<wptr_itr_accessor<arrwrapper,int,a>,wptr_accessor<arrwrapper,a>>(wptr_itr_accessor<arrwrapper,int,a>(1));
        wptr_complex<arrwrapper,a> i(arrwrapper(3),(wptr_readable<wptr_accessor<arrwrapper,a>>*)&ws);
        (**ws.getReferenced())=wptr_itr_accessor<arrwrapper,int,a>(2);
        if (!(
            (i->i==0)&&
            ((**(i.getReferenced()))[0].i==0)&&
            ((**(i.getReferenced()))[1].i==0)&&
            ((**(i.getReferenced()))[2].i==0)
        ))return 1;
        i->inc();
        return !(
            (i->i==1)&&
            ((**(i.getReferenced()))[0].i==0)&&
            ((**(i.getReferenced()))[1].i==0)&&
            ((**(i.getReferenced()))[2].i==1)
        );
    }

    int wptr_complex_test_constructor_obj_base_readable(){
        wptr_simple<wptr_itr_accessor<arrwrapper,int,a>> ws = wptr_simple<wptr_itr_accessor<arrwrapper,int,a>>(wptr_itr_accessor<arrwrapper,int,a>(1));
        wptr_complex<arrwrapper,a> i(arrwrapper(3),(wptr_base_readable<wptr_itr_accessor<arrwrapper,int,a>>*)&ws);
        (**ws.getReferenced())=wptr_itr_accessor<arrwrapper,int,a>(2);
        if (!(
            (i->i==0)&&
            ((**(i.getReferenced()))[0].i==0)&&
            ((**(i.getReferenced()))[1].i==0)&&
            ((**(i.getReferenced()))[2].i==0)
        ))return 1;
        i->inc();
        return !(
            (i->i==1)&&
            ((**(i.getReferenced()))[0].i==0)&&
            ((**(i.getReferenced()))[1].i==0)&&
            ((**(i.getReferenced()))[2].i==1)
        );
    }

    int wptr_complex_test_constructor_obj_accessor(){
        wptr_complex<arrwrapper,a> i(arrwrapper(3),wptr_itr_accessor<arrwrapper,int,a>(1));
        if (!(
            (i->i==0)&&
            ((**(i.getReferenced()))[0].i==0)&&
            ((**(i.getReferenced()))[1].i==0)&&
            ((**(i.getReferenced()))[2].i==0)
        ))return 1;
        i->inc();
        return !(
            (i->i==1)&&
            ((**(i.getReferenced()))[0].i==0)&&
            ((**(i.getReferenced()))[1].i==1)&&
            ((**(i.getReferenced()))[2].i==0)
        );
    }

    int wptr_complex_test_constructor_copy(){
        wptr_simple<wptr_itr_accessor<arrwrapper,int,a>> ws = wptr_simple<wptr_itr_accessor<arrwrapper,int,a>>(wptr_itr_accessor<arrwrapper,int,a>(1));
        wptr_complex<arrwrapper,a> i2(arrwrapper(3),(wptr_base_readable<wptr_itr_accessor<arrwrapper,int,a>>*)&ws);
        wptr_complex<arrwrapper,a> i(i2);
        (**ws.getReferenced())=wptr_itr_accessor<arrwrapper,int,a>(2);
        if(*((wptr_base_readable<arrwrapper>*)&i2)==*((wptr_base_readable<arrwrapper>*)&i))return 1;
        if (!(
            (i->i==0)&&
            ((**(i.getReferenced()))[0].i==0)&&
            ((**(i.getReferenced()))[1].i==0)&&
            ((**(i.getReferenced()))[2].i==0)
        ))return 1;
        i->inc();
        return !(
            (i->i==1)&&
            ((**(i.getReferenced()))[0].i==0)&&
            ((**(i.getReferenced()))[1].i==0)&&
            ((**(i.getReferenced()))[2].i==1)
        );
    }

    int wptr_complex_test_constructor_base_readable_readable(){
        wptr_simple<arrwrapper> aws = wptr_simple<arrwrapper>(arrwrapper(3));
        wptr_inheritance<wptr_itr_accessor<arrwrapper,int,a>,wptr_accessor<arrwrapper,a>> ws = wptr_inheritance<wptr_itr_accessor<arrwrapper,int,a>,wptr_accessor<arrwrapper,a>>(wptr_itr_accessor<arrwrapper,int,a>(1));
        wptr_complex<arrwrapper,a> i(*(wptr_base_readable<arrwrapper>*)&aws,(wptr_readable<wptr_accessor<arrwrapper,a>>*)&ws);
        (**ws.getReferenced())=wptr_itr_accessor<arrwrapper,int,a>(2);
        if(aws!=i)return 2;
        if (!(
            (i->i==0)&&
            ((**(i.getReferenced()))[0].i==0)&&
            ((**(i.getReferenced()))[1].i==0)&&
            ((**(i.getReferenced()))[2].i==0)
        ))return 3;
        i->inc();
        return !(
            (i->i==1)&&
            ((**(i.getReferenced()))[0].i==0)&&
            ((**(i.getReferenced()))[1].i==0)&&
            ((**(i.getReferenced()))[2].i==1)
        );
    }

    int wptr_complex_test_constructor_base_readable_base_readable(){
        wptr_simple<arrwrapper> aws = wptr_simple<arrwrapper>(arrwrapper(3));
        wptr_simple<wptr_itr_accessor<arrwrapper,int,a>> ws = wptr_simple<wptr_itr_accessor<arrwrapper,int,a>>(wptr_itr_accessor<arrwrapper,int,a>(1));
        wptr_complex<arrwrapper,a> i(*(wptr_base_readable<arrwrapper>*)&aws,(wptr_base_readable<wptr_itr_accessor<arrwrapper,int,a>>*)&ws);
        (**ws.getReferenced())=wptr_itr_accessor<arrwrapper,int,a>(2);
        if(aws!=i)return 2;
        if (!(
            (i->i==0)&&
            ((**(i.getReferenced()))[0].i==0)&&
            ((**(i.getReferenced()))[1].i==0)&&
            ((**(i.getReferenced()))[2].i==0)
        ))return 3;
        i->inc();
        return !(
            (i->i==1)&&
            ((**(i.getReferenced()))[0].i==0)&&
            ((**(i.getReferenced()))[1].i==0)&&
            ((**(i.getReferenced()))[2].i==1)
        );
    }

    int wptr_complex_test_constructor_base_readable_accessor(){
        wptr_simple<arrwrapper> aws = wptr_simple<arrwrapper>(arrwrapper(3));
        wptr_complex<arrwrapper,a> i(*(wptr_base_readable<arrwrapper>*)&aws,wptr_itr_accessor<arrwrapper,int,a>(1));
        if(i!=aws)return 2;
        if (!(
            (i->i==0)&&
            ((**(i.getReferenced()))[0].i==0)&&
            ((**(i.getReferenced()))[1].i==0)&&
            ((**(i.getReferenced()))[2].i==0)
        ))return 3;
        i->inc();
        return !(
            (i->i==1)&&
            ((**(i.getReferenced()))[0].i==0)&&
            ((**(i.getReferenced()))[1].i==1)&&
            ((**(i.getReferenced()))[2].i==0)
        );
    }

    int wptr_complex_test_assignment(){
        wptr_simple<wptr_itr_accessor<arrwrapper,int,a>> ws = wptr_simple<wptr_itr_accessor<arrwrapper,int,a>>(wptr_itr_accessor<arrwrapper,int,a>(1));
        wptr_complex<arrwrapper,a> i2(arrwrapper(3),(wptr_base_readable<wptr_itr_accessor<arrwrapper,int,a>>*)&ws);
        wptr_complex<arrwrapper,a> i;
        i = i2;
        (**ws.getReferenced())=wptr_itr_accessor<arrwrapper,int,a>(2);
        if((*((wptr_base_readable<arrwrapper>*)&i2))!=(*((wptr_base_readable<arrwrapper>*)&i)))return 2;
        if (!(
            (i->i==0)&&
            ((**(i.getReferenced()))[0].i==0)&&
            ((**(i.getReferenced()))[1].i==0)&&
            ((**(i.getReferenced()))[2].i==0)
        ))return 3;
        i->inc();
        return !(
            (i->i==1)&&
            ((**(i.getReferenced()))[0].i==0)&&
            ((**(i.getReferenced()))[1].i==0)&&
            ((**(i.getReferenced()))[2].i==1)
        );
    }

    int wptr_complex_test_assignment_base_readable(){
        wptr_simple<arrwrapper> aws = wptr_simple<arrwrapper>(arrwrapper(3));
        wptr_inheritance<wptr_itr_accessor<arrwrapper,int,a>,wptr_accessor<arrwrapper,a>> ws = wptr_inheritance<wptr_itr_accessor<arrwrapper,int,a>,wptr_accessor<arrwrapper,a>>(wptr_itr_accessor<arrwrapper,int,a>(1));
        wptr_complex<arrwrapper,a> i(arrwrapper(3),(wptr_readable<wptr_accessor<arrwrapper,a>>*)&ws);
        (**ws.getReferenced())=wptr_itr_accessor<arrwrapper,int,a>(2);
        if(aws==i)return 2;
        i=aws;
        if(aws!=i)return 3;
        if (!(
            (i->i==0)&&
            ((**(i.getReferenced()))[0].i==0)&&
            ((**(i.getReferenced()))[1].i==0)&&
            ((**(i.getReferenced()))[2].i==0)
        ))return 4;
        i->inc();
        return !(
            (i->i==1)&&
            ((**(i.getReferenced()))[0].i==0)&&
            ((**(i.getReferenced()))[1].i==0)&&
            ((**(i.getReferenced()))[2].i==1)
        );
    }

    int wptr_complex_test_getAccessor(){
        wptr_simple<arrwrapper> aws = wptr_simple<arrwrapper>(arrwrapper(3));
        wptr_simple<wptr_itr_accessor<arrwrapper,int,a>> ws = wptr_simple<wptr_itr_accessor<arrwrapper,int,a>>(wptr_itr_accessor<arrwrapper,int,a>(1));
        wptr_complex<arrwrapper,a> i(*(wptr_base_readable<arrwrapper>*)&aws,(wptr_base_readable<wptr_itr_accessor<arrwrapper,int,a>>*)&ws);
        (**ws.getReferenced())=wptr_itr_accessor<arrwrapper,int,a>(2);
        if (!(
            (i->i==0)&&
            ((**(i.getReferenced()))[0].i==0)&&
            ((**(i.getReferenced()))[1].i==0)&&
            ((**(i.getReferenced()))[2].i==0)
        ))return 1;
        i->inc();
        return !(
            (i->i==1)&&
            ((**(i.getReferenced()))[0].i==0)&&
            ((**(i.getReferenced()))[1].i==0)&&
            ((**(i.getReferenced()))[2].i==1)
        );
        return 0;
    }

    int wptr_complex_test_setAccessor_readable(){
        wptr_simple<wptr_itr_accessor<arrwrapper,int,a>> ws = wptr_simple<wptr_itr_accessor<arrwrapper,int,a>>(wptr_itr_accessor<arrwrapper,int,a>(0));
        wptr_complex<arrwrapper,a> i(arrwrapper(3),wptr_itr_accessor<arrwrapper,int,a>(1));
        if (!(
            (i->i==0)&&
            ((**(i.getReferenced()))[0].i==0)&&
            ((**(i.getReferenced()))[1].i==0)&&
            ((**(i.getReferenced()))[2].i==0)
        ))return 1;
        i->inc();
        if (!(
            (i->i==1)&&
            ((**(i.getReferenced()))[0].i==0)&&
            ((**(i.getReferenced()))[1].i==1)&&
            ((**(i.getReferenced()))[2].i==0)
        ))return 1;
        i.setAccessor((wptr_readable<wptr_accessor<arrwrapper,a>>*)&ws);
        (**ws.getReferenced())=wptr_itr_accessor<arrwrapper,int,a>(2);
        if (!(
            (i->i==0)&&
            ((**(i.getReferenced()))[0].i==0)&&
            ((**(i.getReferenced()))[1].i==1)&&
            ((**(i.getReferenced()))[2].i==0)
        ))return 1;
        i->inc();
        if (!(
            (i->i==1)&&
            ((**(i.getReferenced()))[0].i==0)&&
            ((**(i.getReferenced()))[1].i==1)&&
            ((**(i.getReferenced()))[2].i==1)
        ))return 1;
        return 0;
    }

    int wptr_complex_test_setAccessor_base_readable(){
        wptr_simple<wptr_itr_accessor<arrwrapper,int,a>> ws = wptr_simple<wptr_itr_accessor<arrwrapper,int,a>>(wptr_itr_accessor<arrwrapper,int,a>(0));
        wptr_complex<arrwrapper,a> i(arrwrapper(3),wptr_itr_accessor<arrwrapper,int,a>(1));
        if (!(
            (i->i==0)&&
            ((**(i.getReferenced()))[0].i==0)&&
            ((**(i.getReferenced()))[1].i==0)&&
            ((**(i.getReferenced()))[2].i==0)
        ))return 1;
        i->inc();
        if (!(
            (i->i==1)&&
            ((**(i.getReferenced()))[0].i==0)&&
            ((**(i.getReferenced()))[1].i==1)&&
            ((**(i.getReferenced()))[2].i==0)
        ))return 1;
        i.setAccessor((wptr_readable<wptr_accessor<arrwrapper,a>>*)&ws);
        (**ws.getReferenced())=wptr_itr_accessor<arrwrapper,int,a>(2);
        if (!(
            (i->i==0)&&
            ((**(i.getReferenced()))[0].i==0)&&
            ((**(i.getReferenced()))[1].i==1)&&
            ((**(i.getReferenced()))[2].i==0)
        ))return 1;
        i->inc();
        if (!(
            (i->i==1)&&
            ((**(i.getReferenced()))[0].i==0)&&
            ((**(i.getReferenced()))[1].i==1)&&
            ((**(i.getReferenced()))[2].i==1)
        ))return 1;
        return 0;
        return 0;
    }

    int wptr_complex_test_comparison(){
        wptr_simple<arrwrapper> aws = wptr_simple<arrwrapper>(arrwrapper(3));
        wptr_inheritance<wptr_itr_accessor<arrwrapper,int,a>,wptr_accessor<arrwrapper,a>> ws = wptr_inheritance<wptr_itr_accessor<arrwrapper,int,a>,wptr_accessor<arrwrapper,a>>(wptr_itr_accessor<arrwrapper,int,a>(1));
        wptr_complex<arrwrapper,a> i(arrwrapper(3),(wptr_readable<wptr_accessor<arrwrapper,a>>*)&ws);
        wptr_complex<arrwrapper,a> i2;
        if(aws==i)return 1;
        i=aws;
        if(aws!=i)return 1;
        if(i2==i)return 1;
        i2=i;
        if(i2!=i)return 1;
        return 0;
    }

    int wptr_complex_test_empty(){
        wptr_complex<arrwrapper,a> i;
        wptr_complex<arrwrapper,a> i2;
        wptr_simple<arrwrapper> aws = wptr_simple<arrwrapper>(arrwrapper(3));
        wptr_simple<wptr_itr_accessor<arrwrapper,int,a>> ws = wptr_simple<wptr_itr_accessor<arrwrapper,int,a>>(wptr_itr_accessor<arrwrapper,int,a>(0));
        if(!i2.empty())return 1;
        if(!i.empty())return 1;
        i2=aws;
        i.setAccessor((wptr_base_readable<wptr_itr_accessor<arrwrapper,int,a>>*)&ws);
        if(!i2.empty())return 1;
        if(!i.empty())return 1;
        i=aws;
        i2.setAccessor((wptr_base_readable<wptr_itr_accessor<arrwrapper,int,a>>*)&ws);
        if(i2.empty())return 1;
        if(i.empty())return 1;
        return 0;
    }

    int wptr_complex_test_reference(){
        wptr_simple<wptr_itr_accessor<arrwrapper,int,a>> ws = wptr_simple<wptr_itr_accessor<arrwrapper,int,a>>(wptr_itr_accessor<arrwrapper,int,a>(1));
        wptr_complex<arrwrapper,a> i2(arrwrapper(3),(wptr_base_readable<wptr_itr_accessor<arrwrapper,int,a>>*)&ws);
        wptr_complex<arrwrapper,a> k;
        wptr_complex<arrwrapper,a> i(i2);
        if(i2.getRefCount()!=1)return 1;
        if(k.getRefCount()!=0)return 2;
        if(i.getRefCount()!=1)return 3;
        wptr_complex<arrwrapper,a> i3;
        i3=i2;
        if(i2.getRefCount()!=2)return 4;
        if(i3.getRefCount()!=2)return 5;
        if(k.getRefCount()!=0)return 6;
        if(i.getRefCount()!=1)return 7;
        return 0;
    }

    int wptr_complex_test_member_access(){
        wptr_simple<wptr_itr_accessor<arrwrapper,int,a>> ws = wptr_simple<wptr_itr_accessor<arrwrapper,int,a>>(wptr_itr_accessor<arrwrapper,int,a>(0));
        wptr_complex<arrwrapper,a> i(arrwrapper(3),wptr_itr_accessor<arrwrapper,int,a>(1));
        if(i->i!=0)return 1;
        if (!(
            (i->i==0)&&
            ((**(i.getReferenced()))[0].i==0)&&
            ((**(i.getReferenced()))[1].i==0)&&
            ((**(i.getReferenced()))[2].i==0)
        ))return 1;
        i->inc();
        if(i->i!=1)return 1;
        if (!(
            (i->i==1)&&
            ((**(i.getReferenced()))[0].i==0)&&
            ((**(i.getReferenced()))[1].i==1)&&
            ((**(i.getReferenced()))[2].i==0)
        ))return 1;
        i.setAccessor((wptr_readable<wptr_accessor<arrwrapper,a>>*)&ws);
        if(i->i!=0)return 1;
        if (!(
            (i->i==0)&&
            ((**(i.getReferenced()))[0].i==0)&&
            ((**(i.getReferenced()))[1].i==1)&&
            ((**(i.getReferenced()))[2].i==0)
        ))return 1;
        i->inc();
        if(i->i!=1)return 1;
        if (!(
            (i->i==1)&&
            ((**(i.getReferenced()))[0].i==1)&&
            ((**(i.getReferenced()))[1].i==1)&&
            ((**(i.getReferenced()))[2].i==0)
        ))return 1;
        return 0;
    }

    int wptr_complex_test_duplicate(){
        wptr_simple<wptr_itr_accessor<arrwrapper,int,a>> ws = wptr_simple<wptr_itr_accessor<arrwrapper,int,a>>(wptr_itr_accessor<arrwrapper,int,a>(0));
        wptr_complex<arrwrapper,a> i(arrwrapper(3),wptr_itr_accessor<arrwrapper,int,a>(1));
        i->inc();
        if (!(
            (i->i==1)&&
            ((**(i.getReferenced()))[0].i==0)&&
            ((**(i.getReferenced()))[1].i==1)&&
            ((**(i.getReferenced()))[2].i==0)
        ))return 1;
        wptr_readable<a>* wptrr = i.duplicate();
        if((*wptrr)->i!=1)return 1;
        (*wptrr)->inc();
        if((*wptrr)->i!=2)return 1;
        if (!(
            (i->i==2)&&
            ((**(i.getReferenced()))[0].i==0)&&
            ((**(i.getReferenced()))[1].i==2)&&
            ((**(i.getReferenced()))[2].i==0)
        ))return 1;
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
    const int len = 18;
    test_exec tests[len] = {
        test_exec(&wptr_complex_tests::wptr_complex_test_assignment,"wptr_complex_test_assignment"),
        test_exec(&wptr_complex_tests::wptr_complex_test_assignment_base_readable,"wptr_complex_test_assignment_base_readable"),
        test_exec(&wptr_complex_tests::wptr_complex_test_comparison,"wptr_complex_test_comparison"),
        test_exec(&wptr_complex_tests::wptr_complex_test_constructor,"wptr_complex_test_constructor"),
        test_exec(&wptr_complex_tests::wptr_complex_test_constructor_base_readable_accessor,"wptr_complex_test_constructor_base_readable_accessor"),
        test_exec(&wptr_complex_tests::wptr_complex_test_constructor_base_readable_base_readable,"wptr_complex_test_constructor_base_readable_base_readable"),
        test_exec(&wptr_complex_tests::wptr_complex_test_constructor_base_readable_readable,"wptr_complex_test_constructor_base_readable_readable"),
        test_exec(&wptr_complex_tests::wptr_complex_test_constructor_copy,"wptr_complex_test_constructor_copy"),
        test_exec(&wptr_complex_tests::wptr_complex_test_constructor_obj_accessor,"wptr_complex_test_constructor_obj_accessor"),
        test_exec(&wptr_complex_tests::wptr_complex_test_constructor_obj_base_readable,"wptr_complex_test_constructor_obj_base_readable"),
        test_exec(&wptr_complex_tests::wptr_complex_test_constructor_obj_readable,"wptr_complex_test_constructor_obj_readable"),
        test_exec(&wptr_complex_tests::wptr_complex_test_duplicate,"wptr_complex_test_duplicate"),
        test_exec(&wptr_complex_tests::wptr_complex_test_empty,"wptr_complex_test_empty"),
        test_exec(&wptr_complex_tests::wptr_complex_test_getAccessor,"wptr_complex_test_getAccessor"),
        test_exec(&wptr_complex_tests::wptr_complex_test_member_access,"wptr_complex_test_member_access"),
        test_exec(&wptr_complex_tests::wptr_complex_test_reference,"wptr_complex_test_reference"),
        test_exec(&wptr_complex_tests::wptr_complex_test_setAccessor_base_readable,"wptr_complex_test_setAccessor_base_readable"),
        test_exec(&wptr_complex_tests::wptr_complex_test_setAccessor_readable,"wptr_complex_test_setAccessor_readable"),
    };
    for(int i = 0; i < len; i++){
        if(strncmp((const char*)&tests[i].name,argv[1],(size_t)64)==0)return tests[i].func();
    }
    return -3;
}
