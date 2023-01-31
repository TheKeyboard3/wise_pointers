#include "wptr_managed_tests.h"
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
