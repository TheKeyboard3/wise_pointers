#include "wptr_itr_accessor_tests.h"
namespace wptr_itr_accessor_tests{
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

    arrwrapper::arrwrapper(const wptr_itr_accessor_tests::arrwrapper& other)
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

    int wptr_itr_accessor_test_constructor(){
        arrwrapper wrapper = arrwrapper(3);
        wrapper[0].i=88;
        wrapper[1].i=100;
        wrapper[2].i=94;
        wptr_itr_accessor<arrwrapper,int,a> acc = wptr_itr_accessor<arrwrapper,int,a>();
        if(acc.access(&wrapper)->i!=88)return 1;
        acc = wptr_itr_accessor<arrwrapper,int,a>(1);
        if(acc.access(&wrapper)->i!=100)return 1;
        return 0;
    }

    int wptr_itr_accessor_test_constructor_copy(){
        arrwrapper wrapper = arrwrapper(3);
        wrapper[0].i=88;
        wrapper[1].i=100;
        wrapper[2].i=94;
        wptr_itr_accessor<arrwrapper,int,a> acc = wptr_itr_accessor<arrwrapper,int,a>(1);
        if(acc.access(&wrapper)->i!=100)return 1;
        wptr_itr_accessor<arrwrapper,int,a> acc2 = wptr_itr_accessor<arrwrapper,int,a>(acc);
        if(acc2.access(&wrapper)->i!=100)return 1;
        return 0;
    }

    int wptr_itr_accessor_test_assignment(){
        arrwrapper wrapper = arrwrapper(3);
        wrapper[0].i=88;
        wrapper[1].i=100;
        wrapper[2].i=94;
        wptr_itr_accessor<arrwrapper,int,a> acc = wptr_itr_accessor<arrwrapper,int,a>(1);
        if(acc.access(&wrapper)->i!=100)return 1;
        wptr_itr_accessor<arrwrapper,int,a> acc2 = acc;
        if(acc2.access(&wrapper)->i!=100)return 1;
        return 0;
    }

    int wptr_itr_accessor_test_access(){
        arrwrapper wrapper = arrwrapper(3);
        wrapper[0].i=88;
        wrapper[1].i=100;
        wrapper[2].i=94;
        wptr_itr_accessor<arrwrapper,int,a> acc = wptr_itr_accessor<arrwrapper,int,a>(0);
        if(acc.access(&wrapper)->i!=88)return 1;
        acc = wptr_itr_accessor<arrwrapper,int,a>(1);
        if(acc.access(&wrapper)->i!=100)return 1;
        acc = wptr_itr_accessor<arrwrapper,int,a>(2);
        if(acc.access(&wrapper)->i!=94)return 1;
        return 0;
    }

    int wptr_itr_accessor_test_comparison(){
        wptr_itr_accessor<arrwrapper,int,a> acc1 = wptr_itr_accessor<arrwrapper,int,a>(1);
        wptr_itr_accessor<arrwrapper,int,a> acc2 = wptr_itr_accessor<arrwrapper,int,a>(0);
        wptr_itr_accessor<arrwrapper,int,a> acc3 = wptr_itr_accessor<arrwrapper,int,a>(1);
        if(acc1==acc2)return 1;
        if(acc1!=acc3)return 2;
        if(acc2==acc1)return 3;
        if(acc2==acc3)return 4;
        return 0;
    }
}
