#ifndef WPTR_ITR_TESTS
#define WPTR_ITR_TESTS
#include "../wptr_itr.h"

namespace wptr_itr_tests{
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
    int wptr_itr_test_constructor();
    int wptr_itr_test_constructor_copy();
    int wptr_itr_test_assignment();
    int wptr_itr_test_reference();
    int wptr_itr_test_member_access();
    int wptr_itr_test_comparison();
    int wptr_itr_test_duplicate();
}

#endif //WPTR_ITR_TESTS
