#ifndef WPTR_MANAGED_TESTS
#define WPTR_MANAGED_TESTS
#include "wptr_managed.h"

namespace wptr_managed_tests{
    class a{
    public:
        int i = 0;
        a();
        a(int a);
        void inc();
    };
    int wptr_managed_test_constructor();
    int wptr_managed_test_constructor_copy();
    int wptr_managed_test_reference();
    int wptr_managed_test_member_access();
}

#endif //WPTR_MANAGED_TESTS
