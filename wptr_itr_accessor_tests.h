#ifndef WPTR_ITR_ACCESSOR_TESTS
#define WPTR_ITR_ACCESSOR_TESTS
#include "wptr_itr_accessor.h"

namespace wptr_itr_accessor_tests{
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
    int wptr_itr_accessor_test_constructor();
    int wptr_itr_accessor_test_constructor_copy();
    int wptr_itr_accessor_test_assignment();
    int wptr_itr_accessor_test_access();
    int wptr_itr_accessor_test_comparison();
}

#endif //WPTR_ITR_ACCESSOR_TESTS
