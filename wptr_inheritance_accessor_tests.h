#ifndef WPTR_INHERITANCE_ACCESSOR_TESTS
#define WPTR_INHERITANCE_ACCESSOR_TESTS
#include "wptr_inheritance_accessor.h"

namespace wptr_inheritance_accessor_tests{
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
    int wptr_inheritance_accessor_test_constructor();
    int wptr_inheritance_accessor_test_constructor_copy();
    int wptr_inheritance_accessor_test_assignment();
    int wptr_inheritance_accessor_test_access();
}

#endif //WPTR_INHERITANCE_ACCESSOR_TESTS
