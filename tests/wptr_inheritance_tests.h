#ifndef WPTR_INHERITANCE_TESTS
#define WPTR_INHERITANCE_TESTS
#include "../wptr_inheritance.h"

namespace wptr_inheritance_tests{
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
    int wptr_inheritance_test_constructor();
    int wptr_inheritance_test_constructor_copy();
    int wptr_inheritance_test_assignment();
    int wptr_inheritance_test_reference();
    int wptr_inheritance_test_member_access();
    int wptr_inheritance_test_comparison();
    int wptr_inheritance_test_duplicate();
}

#endif //WPTR_INHERITANCE_TESTS
