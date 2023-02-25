#ifndef WPTR_DEREFERENCE_ACCESSOR_TESTS
#define WPTR_DEREFERENCE_ACCESSOR_TESTS
#include "wptr_dereference_accessor.h"

namespace wptr_dereference_accessor_tests{
    class a{
    public:
        a();
        a(int a);
        int i = 0;
        int& operator *();
    };
    int wptr_dereference_accessor_test_constructor();
    int wptr_dereference_accessor_test_constructor_copy();
    int wptr_dereference_accessor_test_assignment();
    int wptr_dereference_accessor_test_access();
}

#endif //WPTR_DEREFERENCE_ACCESSOR_TESTS
