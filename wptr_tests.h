#ifndef WPTR_TESTS
#define WPTR_TESTS
#include "wptr.h"

namespace wptr_tests{
    class a{
    public:
        int i = 0;
        a();
        a(int a);
        void inc();
    };
    int wptr_test_constructor();
    int wptr_test_constructor_copy();
    int wptr_test_assignment();
    int wptr_test_reference();
    int wptr_test_member_access();
}

#endif //WPTR_MANAGED_TESTS
