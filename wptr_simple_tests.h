#ifndef WPTR_SIMPLE_TESTS
#define WPTR_SIMPLE_TESTS
#include "wptr_simple.h"

namespace wptr_simple_tests{
    class a{
    public:
        int i = 0;
        a();
        a(int a);
        a(const a& other);
        void inc();
    };
    int wptr_simple_test_constructor();
    int wptr_simple_test_constructor_copy();
    int wptr_simple_test_assignment();
    int wptr_simple_test_reference();
    int wptr_simple_test_member_access();
    int wptr_simple_test_comparison();
    int wptr_simple_test_duplicate();
}

#endif //WPTR_SIMPLE_TESTS
