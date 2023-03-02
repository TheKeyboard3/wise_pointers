#include "wptr_itr_tests.h"
#include "../wptr_simple.h"
#include <cstring>

namespace wptr_itr_tests{
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

    arrwrapper::arrwrapper(const wptr_itr_tests::arrwrapper& other)
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

    int wptr_itr_test_constructor(){
        wptr_itr<arrwrapper,int,a> i(arrwrapper(3),1);
        wptr_itr<arrwrapper,int,a> k;
        if(!k.empty())return 2;
        if(k.getRefCount()!=0)return 3;
        if(k.getReferenced()!=nullptr)return 4;
        return !(
            (i->i==0)&&
            ((**(i.getReferenced()))[0].i==0)&&
            ((**(i.getReferenced()))[1].i==0)&&
            ((**(i.getReferenced()))[2].i==0)
        );
    }

    int wptr_itr_test_constructor_copy(){
        wptr_simple<arrwrapper> i = wptr_simple<arrwrapper>(arrwrapper(3));
        wptr_itr<arrwrapper,int,a> i_i(arrwrapper(3),1);
        if(i.getRefCount()!=1)return 11;
        wptr_itr<arrwrapper,int,a> j = wptr_itr<arrwrapper,int,a>(i,1);
        if(i.getRefCount()!=2)return 12;
        wptr_simple<arrwrapper> k;
        if(!k.empty())return 1;
        if(k.getRefCount()!=0)return 2;
        if(k.getReferenced()!=nullptr)return 3;
        j = wptr_itr<arrwrapper,int,a>(k,1);
        if(i.getRefCount()!=1)return 4;
        if(!k.empty())return 5;
        if(!j.empty())return 6;
        j = wptr_itr<arrwrapper,int,a>(i,1);
        j->i++;
        if(!(
            (j->i==1)&&
            ((*i)[0].i==0)&&
            ((*i)[1].i==1)&&
            ((*i)[2].i==0)&&
            ((**(j.getReferenced()))[0].i==0)&&
            ((**(j.getReferenced()))[1].i==1)&&
            ((**(j.getReferenced()))[2].i==0)
        ))return 7;
        j = wptr_itr<arrwrapper,int,a>(i_i);
        j->i++;
        if(i_i.getRefCount()!=1)return 8;
        if(!k.empty())return 9;
        if(j.empty())return 10;
        return !(
            (j->i==1)&&
            ((**i_i.getReferenced())[0].i==0)&&
            ((**i_i.getReferenced())[1].i==0)&&
            ((**i_i.getReferenced())[2].i==0)&&
            ((**(j.getReferenced()))[0].i==0)&&
            ((**(j.getReferenced()))[1].i==1)&&
            ((**(j.getReferenced()))[2].i==0)
        );
    }

    int wptr_itr_test_assignment(){
        wptr_simple<arrwrapper> i = wptr_simple<arrwrapper>(arrwrapper(3));
        wptr_itr<arrwrapper,int,a> i_i = wptr_itr<arrwrapper,int,a>(arrwrapper(3),1);
        wptr_itr<arrwrapper,int,a> j(1);
        j = i;
        j->i++;
        if(i.getRefCount()!=2)return 1;
        if(j.getRefCount()!=2)return 1;
        if(j.empty())return 1;
        if(i.empty())return 1;
        wptr_simple<arrwrapper> k;
        if(!k.empty())return 1;
        if(k.getReferenced()!=nullptr)return 1;
        j = k;
        if(i.getRefCount()!=1)return 1;
        if(!k.empty())return 1;
        if(k.getRefCount()!=0)return 1;
        if(!j.empty())return 1;
        if(j.getRefCount()!=0)return 1;
        j = i;
        if(!(
            (j->i==1)&&
            ((*i)[0].i==0)&&
            ((*i)[1].i==1)&&
            ((*i)[2].i==0)&&
            ((**(j.getReferenced()))[0].i==0)&&
            ((**(j.getReferenced()))[1].i==1)&&
            ((**(j.getReferenced()))[2].i==0)
        ))return 1;
        j = i_i;
        j->i++;
        if(i.getRefCount()!=1)return 1;
        if(i_i.getRefCount()!=2)return 1;
        if(j.getRefCount()!=2)return 1;
        if(j.empty())return 1;
        if(i_i.empty())return 1;
        return !(
            (j->i==1)&&
            ((**(i_i.getReferenced()))[0].i==0)&&
            ((**(i_i.getReferenced()))[1].i==1)&&
            ((**(i_i.getReferenced()))[2].i==0)&&
            ((**(j.getReferenced()))[0].i==0)&&
            ((**(j.getReferenced()))[1].i==1)&&
            ((**(j.getReferenced()))[2].i==0)
        );
    }

    int wptr_itr_test_reference(){
        wptr_itr<arrwrapper,int,a> i = wptr_itr<arrwrapper,int,a>(arrwrapper(3),1);
        if(i.getRefCount()!=1)return 1;
        if(i.empty())return 1;
        wptr_itr<arrwrapper,int,a> j;
        if(!j.empty())return 1;
        j = i;
        if(i.getRefCount()!=2)return 1;
        if(i.empty())return 1;
        wptr_itr<arrwrapper,int,a> k(i);
        if(i.empty())return 1;
        if(k.empty())return 1;
        if(i.getRefCount()!=2)return 1;
        if(k.getRefCount()!=1)return 1;
        return 0;
    }

    int wptr_itr_test_member_access(){
        wptr_itr<arrwrapper,int,a> i = wptr_itr<arrwrapper,int,a>(arrwrapper(3),1);
        if(!(
            (i->i==0)&&
            ((**(i.getReferenced()))[0].i==0)&&
            ((**(i.getReferenced()))[1].i==0)&&
            ((**(i.getReferenced()))[2].i==0)
        ))return 1;
        i->i++;
        if(!(
            (i->i==1)&&
            ((**(i.getReferenced()))[0].i==0)&&
            ((**(i.getReferenced()))[1].i==1)&&
            ((**(i.getReferenced()))[2].i==0)
        ))return 1;
        (*i).i--;
        if(!(
            (i->i==0)&&
            ((**(i.getReferenced()))[0].i==0)&&
            ((**(i.getReferenced()))[1].i==0)&&
            ((**(i.getReferenced()))[2].i==0)
        ))return 1;
        return 0;
    }

    int wptr_itr_test_comparison(){
        wptr_simple<arrwrapper> i = wptr_simple<arrwrapper>(arrwrapper(3));
        wptr_itr<arrwrapper,int,a> i_i(arrwrapper(3),1);
        wptr_itr<arrwrapper,int,a> j = wptr_itr<arrwrapper,int,a>(*(wptr_base_readable<arrwrapper>*)&i,0);
        wptr_itr<arrwrapper,int,a> k;
        wptr_itr<arrwrapper,int,a> ki(2);
        k = j;
        ki=i;
        if(i_i==i)return 1;
        if(!(i_i!=i))return 2;
        if(i_i==j)return 3;
        if(!(i_i!=j))return 4;
        if(j!=i)return 5;
        if(!(j==i))return 6;
        if(j!=k)return 7;
        if(!(j==k))return 8;
        if(i!=ki)return 9;
        if(!(i==ki))return 10;
        return 0;
    }

    int wptr_itr_test_duplicate(){
        wptr_itr<arrwrapper,int,a> i(arrwrapper(3),1);
        if(i.getRefCount()!=1)return 1;
        if(i.empty())return 1;
        wptr_readable<a>* j = i.duplicate();
        if(i.getRefCount()!=2)return 1;
        if(i.empty())return 1;
        if(j->getRefCount()!=2)return 1;
        delete j;
        if(i.getRefCount()!=1)return 1;
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
        test_exec(&wptr_itr_tests::wptr_itr_test_assignment,"wptr_itr_test_assignment"),
        test_exec(&wptr_itr_tests::wptr_itr_test_comparison,"wptr_itr_test_comparison"),
        test_exec(&wptr_itr_tests::wptr_itr_test_constructor,"wptr_itr_test_constructor"),
        test_exec(&wptr_itr_tests::wptr_itr_test_constructor_copy,"wptr_itr_test_constructor_copy"),
        test_exec(&wptr_itr_tests::wptr_itr_test_duplicate,"wptr_itr_test_duplicate"),
        test_exec(&wptr_itr_tests::wptr_itr_test_member_access,"wptr_itr_test_member_access"),
        test_exec(&wptr_itr_tests::wptr_itr_test_reference,"wptr_itr_test_reference"),
    };
    for(int i = 0; i < len; i++){
        if(strncmp((const char*)&tests[i].name,argv[1],(size_t)64)==0)return tests[i].func();
    }
    return -3;
}
