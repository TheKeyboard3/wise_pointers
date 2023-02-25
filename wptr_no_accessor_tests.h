#ifndef WPTR_NO_ACCESSOR_TESTS
#define WPTR_NO_ACCESSOR_TESTS
#include "wptr_no_accessor.h"

namespace wptr_no_accessor_tests{
    class a{
    public:
        a();
        a(int a);
        int i = 0;
        int& operator *();
    };
    int wptr_no_accessor_test_constructor();
    int wptr_no_accessor_test_constructor_copy();
    int wptr_no_accessor_test_assignment();
    int wptr_no_accessor_test_access();
}

#endif //WPTR_NO_ACCESSOR_TESTS
