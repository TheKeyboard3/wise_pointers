#ifndef WMPTR_TESTS
#define WMPTR_TESTS
#include "wmptr.h"

namespace wmptr_tests{
    class c{
    public:
        int i;
        c();
        c(int a);
        c(const c& other);
        void inc();
    };
    class a{
    public:
        int i = 0;
        c b = c(0);
        int q = 0;
        a();
        a(int a);
        a(const a& other);
    };
    int wmptr_test_constructor();
    int wmptr_test_constructor_copy();
    int wmptr_test_assignment();
    int wmptr_test_setOffset();
    int wmptr_test_setObject();
    int wmptr_test_reference();
    int wmptr_test_member_access();
}

#endif //WMPTR_MANAGED_TESTS
