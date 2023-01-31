#include <iostream>
#include "wptr.h"
#include "wmptr.h"
#include "wptr_managed_tests.h"
#include "wptr_tests.h"
#include "wmptr_tests.h"

class c{
public:
    int i = 0;
    c(){
        i = 0;
    }
    c(int a){
        i=a;
    }
    void inc(){
        i++;
    }
};

class o{
public:
    int u = 0;
    c i;
    int p = 18;
    o(){
        i.i = 0;
    }
    o(int a){
        i.i=a;
    }
    void inc(){
        i.i++;
    }
};

using namespace std;

void increment_c_i(awptr<c> &a){
    a->inc();
}

int main(int argc, char **argv) {
//    {
//        wptr<c> i(c(0));
//        cout << (*i).i << endl;
//        i->inc();
//        cout << (*i).i << endl;
//        (*i).i++;
//        cout << (*i).i << endl;
//        (*i).inc();
//        cout << (*i).i << endl;
//        i->i++;
//        cout << (*i).i << endl;
//        cout << i->i << endl;
//    }

    //{
        //unsigned long offset = offsetof(o,i);
        //wptr<o> j(o(0));
        //cout<<j.getRefCount()<<endl;
        //cout << j->i.i << endl;
        //cout << j->p << endl;
        //cout << j->u << endl;
        //cout<<endl;
        //wmptr<o,c> i(j,offset);
        //cout<<j.getRefCount()<<endl;
        //cout << (*i).i << endl;
        //cout << j->i.i << endl;
        //cout << j->p << endl;
        //cout << j->u << endl;
        //cout<<endl;
        //i->inc();
        //cout << (*i).i << endl;
        //cout << i->i << endl;
        //cout << j->i.i << endl;
        //cout << j->p << endl;
        //cout << j->u << endl;
        //cout<<endl;
        //increment_c_i(i);
        //cout << (*i).i << endl;
        //cout << i->i << endl;
        //cout << j->i.i << endl;
        //cout << j->p << endl;
        //cout << j->u << endl;
        //cout<<endl;
//        i->inc();
//        cout << (*i).i << endl;
//        (*i).i++;
//        cout << (*i).i << endl;
//        (*i).inc();
//        cout << (*i).i << endl;
//        i->i++;
//        cout << (*i).i << endl;
//        cout << i->i << endl;
    //}

//    wptr<c> i(c(0));
//    cout << (*i).i << endl;
//    i->inc();
//    cout << (*i).i << endl;
//    (*i).i++;
//    cout << (*i).i << endl;
//    (*i).inc();
//    cout << (*i).i << endl;
//    i->i++;
//    cout << (*i).i << endl;
//    cout << i->i << endl;
//
//    wptr<c> j(i);
//    cout << j->i << endl;
//    cout << (j==i) << endl;
//    j->inc();
//    cout << i->i << endl;
//    cout << j->i << endl;
//    cout<<endl;
//    cout<<wptr_managed_tests::wptr_managed_test_constructor()<<endl;
//    cout<<wptr_managed_tests::wptr_managed_test_constructor_copy()<<endl;
//    cout<<wptr_managed_tests::wptr_managed_test_member_access()<<endl;
//    cout<<wptr_managed_tests::wptr_managed_test_reference()<<endl;
//    cout<<endl;
    cout<<wmptr_tests::wmptr_test_constructor()<<endl;
    cout<<wmptr_tests::wmptr_test_constructor_copy()<<endl;
    cout<<wmptr_tests::wmptr_test_assignment()<<endl;
    cout<<wmptr_tests::wmptr_test_setOffset()<<endl;
    cout<<wmptr_tests::wmptr_test_setObject()<<endl;
    cout<<wmptr_tests::wmptr_test_reference()<<endl;
    cout<<wmptr_tests::wmptr_test_member_access()<<endl;
//    cout<<endl;
//    cout<<wptr_tests::wptr_test_constructor()<<endl;
//    cout<<wptr_tests::wptr_test_constructor_copy()<<endl;
//    cout<<wptr_tests::wptr_test_assignment()<<endl;
//    cout<<wptr_tests::wptr_test_reference()<<endl;
//    cout<<wptr_tests::wptr_test_member_access()<<endl;
//    cout<<endl;
    return 0;
}
