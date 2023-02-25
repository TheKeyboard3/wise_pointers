#ifndef WPTR_COMPLEX_TESTS
#define WPTR_COMPLEX_TESTS
#include "wptr_complex.h"

namespace wptr_complex_tests{
    class a{
    public:
        int i = 0;
        a();
        a(int a);
        a(const a& other);
        void inc();
    };
    class arrwrapper{
    private:
        int size;
        a* arr = nullptr;
    public:
        arrwrapper();
        arrwrapper(const arrwrapper& other);
        arrwrapper(int s);
        ~arrwrapper();
        const arrwrapper& operator=(const arrwrapper& other);
        a& operator[](int ind);
    };

    int wptr_complex_test_constructor();
    int wptr_complex_test_constructor_obj_readable();
    int wptr_complex_test_constructor_obj_base_readable();
    int wptr_complex_test_constructor_obj_accessor();
    int wptr_complex_test_constructor_copy();
    int wptr_complex_test_constructor_base_readable_readable();
    int wptr_complex_test_constructor_base_readable_base_readable();
    int wptr_complex_test_constructor_base_readable_accessor();
    int wptr_complex_test_assignment();
    int wptr_complex_test_assignment_base_readable();
    int wptr_complex_test_getAccessor();
    int wptr_complex_test_setAccessor_readable();
    int wptr_complex_test_setAccessor_base_readable();
    int wptr_complex_test_comparison();
    int wptr_complex_test_empty();
    int wptr_complex_test_reference();
    int wptr_complex_test_member_access();
    int wptr_complex_test_duplicate();
}

#endif //WPTR_COMPLEX_TESTS
