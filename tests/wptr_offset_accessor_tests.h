#ifndef WPTR_OFFSET_ACCESSOR_TESTS
#define WPTR_OFFSET_ACCESSOR_TESTS
#include "../wptr_offset_accessor.h"

namespace wptr_offset_accessor_tests{
    class a{
    public:
        a();
        a(int a);
        int i = 0;
    };
    class b{
    public:
        b();
        b(int u, int b);
        a aaa;
        int k = 0;
    };
    int wptr_offset_accessor_test_constructor();
    int wptr_offset_accessor_test_constructor_copy();
    int wptr_offset_accessor_test_assignment();
    int wptr_offset_accessor_test_access();
    int wptr_offset_accessor_test_comparison();
}

#endif //WPTR_NO_ACCESSOR_TESTS
