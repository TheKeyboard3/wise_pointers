#ifndef WPTR_WRAPPED_TESTS
#define WPTR_WRAPPED_TESTS
#include "../wptr_wrapped.h"

namespace wptr_wrapped_tests{
    class a{
    public:
        int i = 0;
        a();
        a(int a);
        a(const a& other);
        void inc();
    };
    int wptr_wrapped_test_constructor();
    int wptr_wrapped_test_constructor_object();
    int wptr_wrapped_test_constructor_object_readable();
    int wptr_wrapped_test_constructor_base_readable_readable();
    int wptr_wrapped_test_constructor_copy();
    int wptr_wrapped_test_constructor_base_readable();
    int wptr_wrapped_test_assignment();
    int wptr_wrapped_test_member_access();
}

#endif //WPTR_WRAPPED_TESTS
