#include "wptr_tests.h"
namespace wptr_tests{
    a::a(){
        i = 0;
    }

    a::a(int a){
        i=a;
    }

    void a::inc(){
        i++;
    }
    int wptr_test_constructor(){
        wptr<a> i(a(65));
        wptr<a> k;
        if(!k.empty())return 1;
        if(k.getTo()!=nullptr)return 1;
        return i->i!=65;
    }

    int wptr_test_constructor_copy(){
        wptr<a> i = wptr<a>(a(65));
        wptr<a> j = wptr<a>(i);
        wptr<a> k;
        if(!k.empty())return 1;
        if(k.getTo()!=nullptr)return 1;
        j = wptr<a>(k);
        if(i.getRefCount()!=1)return 1;
        if(!k.empty())return 1;
        if(!j.empty())return 1;
        j = wptr<a>(i);
        j->i++;
        return !((j->i==66)&&(i->i==65));
    }

    int wptr_test_assignment(){
        wptr<a> i = wptr<a>(a(65));
        wptr<a> j;
        j = i;
        j->i++;
        if(i.getRefCount()!=2)return 1;
        if(j.getRefCount()!=2)return 1;
        wptr<a> k;
        if(!k.empty())return 1;
        if(k.getTo()!=nullptr)return 1;
        j = k;
        if(i.getRefCount()!=1)return 1;
        if(!k.empty())return 1;
        if(!j.empty())return 1;
        j = i;
        return !((j->i==66)&&(i->i==66));
    }

    int wptr_test_reference(){
        wptr<a> i = wptr<a>(a(65));
        if(i.getRefCount()!=1)return 1;
        wptr<a> j;
        j = i;
        if(i.getRefCount()!=2)return 1;
        wptr<a> k(i);
        if(i.getRefCount()!=2)return 1;
        if(k.getRefCount()!=1)return 1;
        return 0;
    }

    int wptr_test_member_access(){
        wptr<a> i = wptr<a>(a(65));
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
