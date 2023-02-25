#include "wptr_no_accessor_tests.h"
namespace wptr_no_accessor_tests{
    a::a(){
        i = 0;
    }

    a::a(int a){
        i = a;
    }

    int& a::operator*(){
        return i;
    }

    const wptr_no_accessor<a> acc = wptr_no_accessor<a>();

    int wptr_no_accessor_test_constructor(){
        wptr_no_accessor<a>* acc2 = new wptr_no_accessor<a>();
        a obj = a(65);
        if((*acc2->access(&obj)).i!=65)return 1;
        obj.i++;
        if((*acc2->access(&obj)).i!=66)return 2;
        delete acc2;
        return 0;
    }

    int wptr_no_accessor_test_constructor_copy(){
        wptr_no_accessor<a> acc1 = wptr_no_accessor<a>();
        wptr_no_accessor<a> acc2 = wptr_no_accessor<a>(acc1);
        a obj = a(65);
        if((*acc2.access(&obj)).i!=65)return 1;
        obj.i++;
        if((*acc2.access(&obj)).i!=66)return 2;
        return 0;
    }

    int wptr_no_accessor_test_assignment(){
        wptr_no_accessor<a> acc1 = wptr_no_accessor<a>();
        wptr_no_accessor<a> acc2 = acc1;
        a obj = a(65);
        if((*acc2.access(&obj)).i!=65)return 1;
        obj.i++;
        if((*acc2.access(&obj)).i!=66)return 2;
        return 0;
    }

    int wptr_no_accessor_test_access(){
        a obj = a(65);
        if((*acc.access(&obj)).i!=65)return 1;
        obj.i++;
        if((*acc.access(&obj)).i!=66)return 2;
        return 0;
    }
}
