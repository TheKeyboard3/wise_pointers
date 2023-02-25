#include "wptr_inheritance_tests.h"
#include "wptr_simple.h"
namespace wptr_inheritance_tests{
    a::a(){
        i = 0;
    }

    a::a(int a){
        i=a;
    }

    void a::inc(){
        i++;
    }

    b::b() : a(){
        k = 0;
    }

    b::b(int u, int b) : a(u){
        k=b;
    }

    void b::incb(){
        k++;
    }

    int wptr_inheritance_test_constructor(){
        wptr_inheritance<b,a> i(b(65,85));
        wptr_inheritance<b,a> k;
        if(!k.empty())return 1;
        if(k.getRefCount()!=0)return 1;
        if(k.getReferenced()!=nullptr)return 1;
        return !((i->i==65)&&((*i.getReferenced())->k==85));
    }

    int wptr_inheritance_test_constructor_copy(){
        wptr_simple<b> i = wptr_simple<b>(b(65,85));
        wptr_inheritance<b,a> i_i(b(65,85));
        if(i.getRefCount()!=1)return 11;
        wptr_inheritance<b,a> j = wptr_inheritance<b,a>(i);
        if(i.getRefCount()!=2)return 12;
        wptr_simple<b> k;
        if(!k.empty())return 1;
        if(k.getRefCount()!=0)return 2;
        if(k.getReferenced()!=nullptr)return 3;
        j = wptr_inheritance<b,a>(k);
        if(i.getRefCount()!=1)return 4;
        if(!k.empty())return 5;
        if(!j.empty())return 6;
        j = wptr_inheritance<b,a>(i);
        j->i++;
        if(!((j->i==66)&&(i->i==66)&&(i->k==85)))return 7;
        j = wptr_inheritance<b,a>(i_i);
        j->i++;
        if(i_i.getRefCount()!=1)return 8;
        if(!k.empty())return 9;
        if(j.empty())return 10;
        return !((j->i==66)&&(i_i->i==65)&&((**i_i.getReferenced()).k==85));
    }

    int wptr_inheritance_test_assignment(){
        wptr_simple<b> i = wptr_simple<b>(b(65,85));
        wptr_inheritance<b,a> i_i = wptr_inheritance<b,a>(b(65,85));
        wptr_inheritance<b,a> j;
        j = i;
        j->i++;
        if(i.getRefCount()!=2)return 1;
        if(j.getRefCount()!=2)return 1;
        if(j.empty())return 1;
        if(i.empty())return 1;
        wptr_simple<b> k;
        if(!k.empty())return 1;
        if(k.getReferenced()!=nullptr)return 1;
        j = k;
        if(i.getRefCount()!=1)return 1;
        if(!k.empty())return 1;
        if(k.getRefCount()!=0)return 1;
        if(!j.empty())return 1;
        if(j.getRefCount()!=0)return 1;
        j = i;
        if(!((j->i==66)&&(i->i==66)))return 1;
        j = i_i;
        j->i++;
        if(i.getRefCount()!=1)return 1;
        if(i_i.getRefCount()!=2)return 1;
        if(j.getRefCount()!=2)return 1;
        if(j.empty())return 1;
        if(i_i.empty())return 1;
        return !((j->i==66)&&(i_i->i==66)&&((**i_i.getReferenced()).k==85));
    }

    int wptr_inheritance_test_reference(){
        wptr_inheritance<b,a> i = wptr_inheritance<b,a>(b(65,85));
        if(i.getRefCount()!=1)return 1;
        if(i.empty())return 1;
        wptr_inheritance<b,a> j;
        if(!j.empty())return 1;
        j = i;
        if(i.getRefCount()!=2)return 1;
        if(i.empty())return 1;
        wptr_inheritance<b,a> k(i);
        if(i.empty())return 1;
        if(k.empty())return 1;
        if(i.getRefCount()!=2)return 1;
        if(k.getRefCount()!=1)return 1;
        return 0;
    }

    int wptr_inheritance_test_member_access(){
        wptr_inheritance<b,a> i = wptr_inheritance<b,a>(b(65,85));
        if(i->i!=65)return 1;
        if((*i).i!=65)return 1;
        i->i++;
        if(i->i!=66)return 1;
        if((*i).i!=66)return 1;
        (*i).i--;
        if(i->i!=65)return 1;
        if((*i).i!=65)return 1;
        if((**i.getReferenced()).k!=85)return 1;
        return 0;
    }

    int wptr_inheritance_test_comparison(){
        wptr_simple<b> i = wptr_simple<b>(b(65,85));
        wptr_inheritance<b,a> i_i(b(65,85));
        wptr_inheritance<b,a> j = wptr_inheritance<b,a>(*(wptr_base_readable<b>*)&i);
        wptr_inheritance<b,a> k;
        wptr_inheritance<b,a> ki;
        k = j;
        ki = i;
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

    int wptr_inheritance_test_duplicate(){
        wptr_inheritance<b,a> i = wptr_inheritance<b,a>(b(65,85));
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
