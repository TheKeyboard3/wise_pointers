#include "wptr_dereference_accessor_tests.h"
namespace wptr_dereference_accessor_tests{
    a::a(){
        i = 0;
    }

    a::a(int a){
        i = a;
    }

    int& a::operator*(){
        return i;
    }

    const wptr_dereference_accessor<a,int> acc = wptr_dereference_accessor<a,int>();

    int wptr_dereference_accessor_test_constructor(){
        wptr_dereference_accessor<a,int>* acc2 = new wptr_dereference_accessor<a,int>();
        a obj = a(65);
        if((*acc2->access(&obj))!=65)return 1;
        obj.i++;
        if((*acc2->access(&obj))!=66)return 2;
        return 0;
    }

    int wptr_dereference_accessor_test_constructor_copy(){
        const wptr_dereference_accessor<a,int> acc1 = wptr_dereference_accessor<a,int>();
        const wptr_dereference_accessor<a,int> acc2 = wptr_dereference_accessor<a,int>(acc1);
        a obj = a(65);
        if((*acc2.access(&obj))!=65)return 1;
        obj.i++;
        if((*acc2.access(&obj))!=66)return 2;
        return 0;
    }

    int wptr_dereference_accessor_test_assignment(){
        const wptr_dereference_accessor<a,int> acc1 = wptr_dereference_accessor<a,int>();
        const wptr_dereference_accessor<a,int> acc2 = acc1;
        a obj = a(65);
        if((*acc2.access(&obj))!=65)return 1;
        obj.i++;
        if((*acc2.access(&obj))!=66)return 2;
        return 0;
    }

    int wptr_dereference_accessor_test_access(){
        a obj = a(65);
        if((*acc.access(&obj))!=65)return 1;
        obj.i++;
        if((*acc.access(&obj))!=66)return 2;
        return 0;
    }
}
