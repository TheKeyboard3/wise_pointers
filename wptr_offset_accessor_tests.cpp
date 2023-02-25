#include "wptr_offset_accessor_tests.h"
#include <stddef.h>

namespace wptr_offset_accessor_tests{
    a::a(){
        i = 0;
    }

    a::a(int a){
        i = a;
    }

    b::b(){
        aaa = a(0);
        k = 0;
    }

    b::b(int u, int b){
        aaa = a(u);
        k = b;
    }

    int wptr_offset_accessor_test_constructor(){
        wptr_offset_accessor<b,a>* acc = new wptr_offset_accessor<b,a>(offsetof(b,aaa));
        b vr = b(65,87);
        if(acc->access(&vr)->i!=65)return 1;
        acc->access(&vr)->i++;
        if(acc->access(&vr)->i!=66)return 1;
        if(vr.k!=87)return 1;
        if(vr.aaa.i!=66)return 1;
        vr.aaa.i++;
        if(acc->access(&vr)->i!=67)return 1;
        return 0;
    }

    int wptr_offset_accessor_test_constructor_copy(){
        wptr_offset_accessor<b,a> acc2 = wptr_offset_accessor<b,a>(offsetof(b,aaa));
        wptr_offset_accessor<b,a> acc = wptr_offset_accessor<b,a>(acc2);
        b vr = b(65,87);
        if(acc.access(&vr)->i!=65)return 1;
        acc.access(&vr)->i++;
        if(acc.access(&vr)->i!=66)return 1;
        if(vr.k!=87)return 1;
        if(vr.aaa.i!=66)return 1;
        vr.aaa.i++;
        if(acc.access(&vr)->i!=67)return 1;
        return 0;
    }

    int wptr_offset_accessor_test_assignment(){
        wptr_offset_accessor<b,a> acc2 = wptr_offset_accessor<b,a>(offsetof(b,aaa));
        wptr_offset_accessor<b,a> acc = acc2;
        b vr = b(65,87);
        if(acc.access(&vr)->i!=65)return 1;
        acc.access(&vr)->i++;
        if(acc.access(&vr)->i!=66)return 1;
        if(vr.k!=87)return 1;
        if(vr.aaa.i!=66)return 1;
        vr.aaa.i++;
        if(acc.access(&vr)->i!=67)return 1;
        return 0;
    }

    int wptr_offset_accessor_test_access(){
        wptr_offset_accessor<b,a> acc = wptr_offset_accessor<b,a>(offsetof(b,aaa));
        b vr = b(65,87);
        if(acc.access(&vr)->i!=65)return 1;
        acc.access(&vr)->i++;
        if(acc.access(&vr)->i!=66)return 1;
        if(vr.k!=87)return 1;
        if(vr.aaa.i!=66)return 1;
        vr.aaa.i++;
        if(acc.access(&vr)->i!=67)return 1;
        return 0;
    }

    int wptr_offset_accessor_test_comparison(){
        wptr_offset_accessor<b,a> acc1 = wptr_offset_accessor<b,a>(0);
        wptr_offset_accessor<b,a> acc2 = wptr_offset_accessor<b,a>(1);
        wptr_offset_accessor<b,a> acc3 = wptr_offset_accessor<b,a>(0);
        if(acc1==acc2)return 1;
        if(acc1!=acc3)return 2;
        if(acc2==acc1)return 3;
        if(acc2==acc3)return 4;
        return 0;
    }
}
