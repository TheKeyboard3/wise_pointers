#ifndef WPTR_ACCESSOR_WRAP_TESTS
#define WPTR_ACCESSOR_WRAP_TESTS
#include "wptr_accessor_wrap.h"

namespace wptr_accessor_wrap_tests{
    class a{
    public:
        int i = 0;
        a();
        a(int a);
        void inc();
    };
    int wptr_accessor_wrap_test_constructor();
    int wptr_accessor_wrap_test_constructor_readable();
    int wptr_accessor_wrap_test_constructor_base_readable();
    int wptr_accessor_wrap_test_constructor_copy();
    int wptr_accessor_wrap_test_assignment();
    int wptr_accessor_wrap_test_comparison();
    int wptr_accessor_wrap_test_access();
}

#endif //WPTR_ACCESSOR_WRAP_TESTS
