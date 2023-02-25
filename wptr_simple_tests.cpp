#include "wptr_simple_tests.h"
namespace wptr_simple_tests{
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

    int wptr_simple_test_constructor(){
        wptr_simple<a> i(a(65));
        wptr_simple<a> k;
        if(!k.empty())return 1;
        if(k.getRefCount()!=0)return 1;
        if(k.getReferenced()!=nullptr)return 1;
        return i->i!=65;
    }

    int wptr_simple_test_constructor_copy(){
        wptr_simple<a> i = wptr_simple<a>(a(65));
        wptr_simple<a> j = wptr_simple<a>(i);
        wptr_simple<a> k;
        if(!k.empty())return 1;
        if(k.getRefCount()!=0)return 1;
        if(k.getReferenced()!=nullptr)return 1;
        j = wptr_simple<a>(k);
        if(i.getRefCount()!=1)return 1;
        if(!k.empty())return 1;
        if(!j.empty())return 1;
        j = wptr_simple<a>(i);
        j->i++;
        return !((j->i==66)&&(i->i==65));
    }

    int wptr_simple_test_assignment(){
        wptr_simple<a> i = wptr_simple<a>(a(65));
        wptr_simple<a> j;
        j = i;
        j->i++;
        if(i.getRefCount()!=2)return 1;
        if(j.getRefCount()!=2)return 1;
        if(j.empty())return 1;
        if(i.empty())return 1;
        wptr_simple<a> k;
        if(!k.empty())return 1;
        if(k.getReferenced()!=nullptr)return 1;
        j = k;
        if(i.getRefCount()!=1)return 1;
        if(!k.empty())return 1;
        if(k.getRefCount()!=0)return 1;
        if(!j.empty())return 1;
        if(j.getRefCount()!=0)return 1;
        j = i;
        return !((j->i==66)&&(i->i==66));
    }

    int wptr_simple_test_reference(){
        wptr_simple<a> i = wptr_simple<a>(a(65));
        wptr_base_readable<a>* i_ptr = &i;
        if(i.getRefCount()!=1)return 1;
        wptr_simple<a> j;
        if(!j.empty())return 1;
        j = i;
        if(i.getRefCount()!=2)return 1;
        if(i.empty())return 1;
        wptr_simple<a> k(i);
        if(i.empty())return 1;
        if(k.empty())return 1;
        if(i.getRefCount()!=2)return 1;
        if(k.getRefCount()!=1)return 1;
        wptr_simple<a> k_fromptr(*i_ptr);
        if(i.empty())return 1;
        if(k_fromptr.empty())return 1;
        if(i.getRefCount()!=3)return 1;
        if(k_fromptr.getRefCount()!=3)return 1;
        return 0;
    }

    int wptr_simple_test_member_access(){
        wptr_simple<a> i = wptr_simple<a>(a(65));
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

    int wptr_simple_test_comparison(){
        wptr_simple<a> i_unptr = wptr_simple<a>(a(85));
        wptr_base_readable<a> *i = &i_unptr;
        wptr_simple<a> i_i(a(85));
        wptr_simple<a> j = wptr_simple<a>(*i);
        wptr_simple<a> k;
        wptr_simple<a> ki;
        k = j;
        ki = *i;
        if(i_i==*i)return 1;
        if(!(i_i!=*i))return 2;
        if(i_i==j)return 3;
        if(!(i_i!=j))return 4;
        if(j!=*i)return 5;
        if(!(j==*i))return 6;
        if(j!=k)return 7;
        if(!(j==k))return 8;
        if(*i!=ki)return 9;
        if(!(*i==ki))return 10;
        return 0;
    }

    int wptr_simple_test_duplicate(){
        wptr_simple<a> i = wptr_simple<a>(a(85));
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
