#ifndef WPTR_ACCESSOR_CHAIN_TESTS
#define WPTR_ACCESSOR_CHAIN_TESTS
#include "wptr_accessor_chain.h"

namespace wptr_accessor_chain_tests{
    class a{
    public:
        int i = 0;
        a();
        a(int a);
        void inc();
    };
    class b : public a{
    public:
        int k = 0;
        b();
        b(int a, int b);
        void incb();
    };
    int wptr_accessor_chain_test_constructor();
    int wptr_accessor_chain_test_constructor_readable();
    int wptr_accessor_chain_test_constructor_base_readable();
    int wptr_accessor_chain_test_constructor_copy();
    int wptr_accessor_chain_test_assignment();
    int wptr_accessor_chain_test_setAccessor();
    int wptr_accessor_chain_test_access();
}

#endif //WPTR_ACCESSOR_CHAIN_TESTS
