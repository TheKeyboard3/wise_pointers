#include "wptr_accessor_chain_tests.h"
#include "wptr_inheritance_accessor.h"
#include "wptr_offset_accessor.h"
#include "wptr_simple.h"
#include "wptr_inheritance.h"
#include <stddef.h>

namespace wptr_accessor_chain_tests{
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

    int wptr_accessor_chain_test_constructor(){
        wptr_inheritance<wptr_inheritance_accessor<b,a>,wptr_accessor<b,a>> acc1_ptr = wptr_inheritance<wptr_inheritance_accessor<b,a>,wptr_accessor<b,a>>(wptr_inheritance_accessor<b,a>());
        wptr_inheritance<wptr_offset_accessor<a,int>,wptr_accessor<a,int>> acc2_ptr = wptr_inheritance<wptr_offset_accessor<a,int>,wptr_accessor<a,int>>(wptr_offset_accessor<a,int>(offsetof(a,i)));
        wptr_accessor_chain<b,a,int>* acc2 = new wptr_accessor_chain<b,a,int>();
        acc2->SetAccessor1(&acc1_ptr);
        acc2->SetAccessor2(&acc2_ptr);
        b obj = b(65,85);
        if((*acc2->access(&obj))!=65)return 1;
        obj.incb();
        if((*acc2->access(&obj))!=65)return 2;
        if(obj.k!=86)return 3;
        if(obj.i!=65)return 4;
        obj.inc();
        if((*acc2->access(&obj))!=66)return 5;
        if(obj.k!=86)return 6;
        if(obj.i!=66)return 7;
        delete acc2;
        return 0;
    }

    int wptr_accessor_chain_test_constructor_readable(){
        wptr_simple<wptr_inheritance_accessor<b,a>> acc1_ptr = wptr_simple<wptr_inheritance_accessor<b,a>>(wptr_inheritance_accessor<b,a>());
        wptr_simple<wptr_offset_accessor<a,int>> acc2_ptr = wptr_simple<wptr_offset_accessor<a,int>>(wptr_offset_accessor<a,int>(offsetof(a,i)));
        wptr_accessor_chain<b,a,int>* acc2 = new wptr_accessor_chain<b,a,int>(&acc1_ptr,&acc2_ptr);
        b obj = b(65,85);
        if((*acc2->access(&obj))!=65)return 1;
        obj.incb();
        if((*acc2->access(&obj))!=65)return 2;
        if(obj.k!=86)return 3;
        if(obj.i!=65)return 4;
        obj.inc();
        if((*acc2->access(&obj))!=66)return 5;
        if(obj.k!=86)return 6;
        if(obj.i!=66)return 7;
        delete acc2;
        return 0;
    }

    int wptr_accessor_chain_test_constructor_base_readable(){
        wptr_simple<wptr_inheritance_accessor<b,a>> acc1_ptr = wptr_simple<wptr_inheritance_accessor<b,a>>(wptr_inheritance_accessor<b,a>());
        wptr_simple<wptr_offset_accessor<a,int>> acc2_ptr = wptr_simple<wptr_offset_accessor<a,int>>(wptr_offset_accessor<a,int>(offsetof(a,i)));
        wptr_accessor_chain<b,a,int>* acc2 = new wptr_accessor_chain<b,a,int>(
            (wptr_base_readable<wptr_inheritance_accessor<b,a>>*)&acc1_ptr,
            (wptr_base_readable<wptr_offset_accessor<a,int>>*)&acc2_ptr
        );
        b obj = b(65,85);
        if((*acc2->access(&obj))!=65)return 1;
        obj.incb();
        if((*acc2->access(&obj))!=65)return 2;
        if(obj.k!=86)return 3;
        if(obj.i!=65)return 4;
        obj.inc();
        if((*acc2->access(&obj))!=66)return 5;
        if(obj.k!=86)return 6;
        if(obj.i!=66)return 7;
        delete acc2;
        return 0;
    }

    int wptr_accessor_chain_test_constructor_copy(){
        wptr_simple<wptr_inheritance_accessor<b,a>> acc1_ptr = wptr_simple<wptr_inheritance_accessor<b,a>>(wptr_inheritance_accessor<b,a>());
        wptr_simple<wptr_offset_accessor<a,int>> acc2_ptr = wptr_simple<wptr_offset_accessor<a,int>>(wptr_offset_accessor<a,int>(offsetof(a,i)));
        wptr_accessor_chain<b,a,int>* acc1 = new wptr_accessor_chain<b,a,int>(
            (wptr_base_readable<wptr_inheritance_accessor<b,a>>*)&acc1_ptr,
            (wptr_base_readable<wptr_offset_accessor<a,int>>*)&acc2_ptr
        );
        wptr_accessor_chain<b,a,int>* acc2 = new wptr_accessor_chain<b,a,int>(*acc1);
        b obj = b(65,85);
        if((*acc2->access(&obj))!=65)return 1;
        obj.incb();
        if((*acc2->access(&obj))!=65)return 2;
        if(obj.k!=86)return 3;
        if(obj.i!=65)return 4;
        obj.inc();
        if((*acc2->access(&obj))!=66)return 5;
        if(obj.k!=86)return 6;
        if(obj.i!=66)return 7;
        delete acc1;
        delete acc2;
        return 0;
    }

    int wptr_accessor_chain_test_assignment(){
        wptr_simple<wptr_inheritance_accessor<b,a>> acc1_ptr = wptr_simple<wptr_inheritance_accessor<b,a>>(wptr_inheritance_accessor<b,a>());
        wptr_simple<wptr_offset_accessor<a,int>> acc2_ptr = wptr_simple<wptr_offset_accessor<a,int>>(wptr_offset_accessor<a,int>(offsetof(a,i)));
        wptr_accessor_chain<b,a,int>* acc1 = new wptr_accessor_chain<b,a,int>(
            (wptr_base_readable<wptr_inheritance_accessor<b,a>>*)&acc1_ptr,
            (wptr_base_readable<wptr_offset_accessor<a,int>>*)&acc2_ptr
        );
        wptr_accessor_chain<b,a,int>* acc2 = new wptr_accessor_chain<b,a,int>();
        *acc2 = *acc1;
        b obj = b(65,85);
        if((*acc2->access(&obj))!=65)return 1;
        obj.incb();
        if((*acc2->access(&obj))!=65)return 2;
        if(obj.k!=86)return 3;
        if(obj.i!=65)return 4;
        obj.inc();
        if((*acc2->access(&obj))!=66)return 5;
        if(obj.k!=86)return 6;
        if(obj.i!=66)return 7;
        delete acc1;
        delete acc2;
        return 0;
    }

    int wptr_accessor_chain_test_setAccessor(){
        wptr_inheritance<wptr_inheritance_accessor<b,a>,wptr_accessor<b,a>> acc1_ptr = wptr_inheritance<wptr_inheritance_accessor<b,a>,wptr_accessor<b,a>>(wptr_inheritance_accessor<b,a>());
        wptr_inheritance<wptr_offset_accessor<a,int>,wptr_accessor<a,int>> acc2_ptr = wptr_inheritance<wptr_offset_accessor<a,int>,wptr_accessor<a,int>>(wptr_offset_accessor<a,int>(offsetof(a,i)));
        wptr_accessor_chain<b,a,int>* acc2 = new wptr_accessor_chain<b,a,int>();
        acc2->SetAccessor1(&acc1_ptr);
        acc2->SetAccessor2(&acc2_ptr);
        b obj = b(65,85);
        if((*acc2->access(&obj))!=65)return 1;
        obj.incb();
        if((*acc2->access(&obj))!=65)return 2;
        if(obj.k!=86)return 3;
        if(obj.i!=65)return 4;
        obj.inc();
        if((*acc2->access(&obj))!=66)return 5;
        if(obj.k!=86)return 6;
        if(obj.i!=66)return 7;
        delete acc2;
        acc2 = new wptr_accessor_chain<b,a,int>();
        acc2->SetAccessor1((wptr_base_readable<wptr_inheritance_accessor<b,a>>*)&acc1_ptr);
        acc2->SetAccessor2((wptr_base_readable<wptr_offset_accessor<a,int>>*)&acc2_ptr);
        obj = b(65,85);
        if((*acc2->access(&obj))!=65)return 8;
        obj.incb();
        if((*acc2->access(&obj))!=65)return 9;
        if(obj.k!=86)return 10;
        if(obj.i!=65)return 11;
        obj.inc();
        if((*acc2->access(&obj))!=66)return 12;
        if(obj.k!=86)return 13;
        if(obj.i!=66)return 14;
        delete acc2;
        return 0;
    }

    int wptr_accessor_chain_test_access(){
        wptr_simple<wptr_inheritance_accessor<b,a>> acc1_ptr = wptr_simple<wptr_inheritance_accessor<b,a>>(wptr_inheritance_accessor<b,a>());
        wptr_simple<wptr_offset_accessor<a,int>> acc2_ptr = wptr_simple<wptr_offset_accessor<a,int>>(wptr_offset_accessor<a,int>(offsetof(a,i)));
        wptr_accessor_chain<b,a,int>* acc2 = new wptr_accessor_chain<b,a,int>(&acc1_ptr,&acc2_ptr);
        b obj = b(65,85);
        if((*acc2->access(&obj))!=65)return 1;
        obj.incb();
        if((*acc2->access(&obj))!=65)return 2;
        if(obj.k!=86)return 3;
        if(obj.i!=65)return 4;
        obj.inc();
        if((*acc2->access(&obj))!=66)return 5;
        if(obj.k!=86)return 6;
        if(obj.i!=66)return 7;
        delete acc2;
        return 0;
    }
}
