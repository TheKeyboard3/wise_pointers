#include "wmptr_tests.h"
#include <stddef.h>

namespace wmptr_tests{
    c::c(){
        i = 0;
    }

    c::c(int a){
        i=a;
    }

    void c::inc(){
        i++;
    }

    c::c(const c& other){
        i = other.i;
    }

    a::a(){
        i = 0;
    }

    a::a(int a){
        b=c(a);
    }

    a::a(const a& other){
        i = other.i;
        b = c(other.b);
        q = other.q;
    }

    int wmptr_test_constructor(){
        wmptr<a,c> i(a(65),offsetof(a,b));
        wmptr<a,c> k;
        if(!k.empty())return 1;
        return i->i!=65;
    }

    int wmptr_test_constructor_copy(){
        wmptr<a,c> i(a(65),offsetof(a,b));
        wmptr<a,c> j = wmptr<a,c>(i);
        wmptr<a,c> k;
        if(!k.empty())return 1;
        j = wmptr<a,c>(k);
        if(i.getRefCount()!=1)return 1;
        if(!k.empty())return 1;
        if(!j.empty())return 1;
        j = wmptr<a,c>(i);
        j->i++;
        return !((j->i==66)&&(i->i==65));
    }

    int wmptr_test_assignment(){
        wmptr<a,c> i(a(65),offsetof(a,b));
        wmptr<a,c> j;
        j = i;
        j->i++;
        if(i.getRefCount()!=2)return 1;
        if(j.getRefCount()!=2)return 1;
        wmptr<a,c> k;
        if(!k.empty())return 1;
        j = k;
        if(i.getRefCount()!=1)return 1;
        if(!k.empty())return 1;
        if(!j.empty())return 1;
        j = i;
        return !((j->i==66)&&(i->i==66));
    }

    int wmptr_test_setOffset(){
        wptr<a> aptr(a(65));
        aptr->q=90;
        wmptr<a,c> i(aptr,offsetof(a,i));
        if(i->i!=0)return 1;
        (i->i)++;
        if(i->i!=1)return 1;
        i.setOffset(offsetof(a,q));
        if(i->i!=90)return 1;
        (i->i)++;
        if(i->i!=91)return 1;
        return 0;
    }

    int wmptr_test_setObject(){
        wptr<a> nptr;
        wptr<a> aptr(a(65));
        aptr->i=75;
        wptr<a> aptr2(a(68));
        aptr2->i=78;
        if(aptr.getRefCount()!=1)return 1;
        if(aptr2.getRefCount()!=1)return 1;
        wmptr<a,c> i(aptr,offsetof(a,i));
        if(aptr.getRefCount()!=2)return 1;
        if(i->i!=75)return 1;
        (i->i)++;
        if(i->i!=76)return 1;
        i.setObject(aptr2);
        if(aptr2.getRefCount()!=2)return 1;
        if(aptr.getRefCount()!=1)return 1;
        if(i->i!=78)return 1;
        (i->i)++;
        if(i->i!=79)return 1;
        i.setObject(nptr);
        if(aptr2.getRefCount()!=1)return 1;
        if(aptr.getRefCount()!=1)return 1;
        if(!nptr.empty())return 1;
        if(!i.empty())return 1;
        return 0;
    }

    int wmptr_test_reference(){
        wmptr<a,c> i(a(65),offsetof(a,b));
        if(i.getRefCount()!=1)return 1;
        wmptr<a,c> j;
        j = i;
        if(i.getRefCount()!=2)return 1;
        wmptr<a,c> k(i);
        if(i.getRefCount()!=2)return 1;
        if(k.getRefCount()!=1)return 1;
        return 0;
    }

    int wmptr_test_member_access(){
        wmptr<a,c> i(a(65),offsetof(a,b));
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
