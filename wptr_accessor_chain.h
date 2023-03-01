#ifndef WPTR_ACCESSOR_CHAIN_H
#define WPTR_ACCESSOR_CHAIN_H

#include "wptr_accessor.h"
#include "wptr_readable.h"
#include "wptr_inheritance.h"

/**
 * A template class that links together two implementations of wptr_accessor
 * It is also an implementation of wptr_accessor, and its objects can be links in a chain
 */
template<typename From, typename Intermediate, typename To>
class wptr_accessor_chain : public wptr_accessor<From,To>
{
protected:
    wptr_readable<wptr_accessor<From,Intermediate>>* accessor1;
    wptr_readable<wptr_accessor<Intermediate,To>>* accessor2;
public:
    /**
     * Empty constructor
     */
    wptr_accessor_chain(){
        accessor1=nullptr;
        accessor2=nullptr;
    }

    /**
     * A constructor thate takes two pointers to implementations of wptr_readable<wptr_accessor>
     * @param acc1 the pointer to an implementation of wptr_readable<wptr_accessor> that is the first link in the chain
     * @param acc2 the pointer to an implementation of wptr_readable<wptr_accessor> that is the second link in the chain
     */
    wptr_accessor_chain(wptr_readable<wptr_accessor<From,Intermediate>>* acc1, wptr_readable<wptr_accessor<Intermediate,To>>* acc2){
        accessor1=acc1->duplicate();
        accessor2=acc2->duplicate();
    }

    /**
     * Copy constructor
     * @param other an object of the same class, that is passed by a constant reference
     */
    wptr_accessor_chain(const wptr_accessor_chain<From,Intermediate,To>& other){
        accessor1=other.accessor1->duplicate();
        accessor2=other.accessor2->duplicate();
    }

    /**
     * A Constructor that takes two pointers to implementations of wptr_base_readable<U> where U is an implementation of wptr_accessor
     * @param acc1 the pointer to an implementation of wptr_base_readable<U> that is the first link in the chain
     * @param acc2 the pointer to an implementation of wptr_base_readable<U> that is the second link in the chain
     */
    template<typename ActualAccessorType1, typename ActualAccessorType2>
    wptr_accessor_chain(wptr_base_readable<ActualAccessorType1>* acc1, wptr_base_readable<ActualAccessorType2>* acc2){
        wptr_inheritance<ActualAccessorType1,wptr_accessor<From,Intermediate>>* acc1_ptr = new wptr_inheritance<ActualAccessorType1,wptr_accessor<From,Intermediate>>();
        *acc1_ptr=*acc1;
        accessor1=acc1_ptr;
        wptr_inheritance<ActualAccessorType2,wptr_accessor<Intermediate,To>>* acc2_ptr = new wptr_inheritance<ActualAccessorType2,wptr_accessor<Intermediate,To>>();
        *acc2_ptr=*acc2;
        accessor2=acc2_ptr;
    }

    /**
     * Destructor
     */
    virtual ~wptr_accessor_chain(){
        if(accessor1!=nullptr)delete accessor1;
        if(accessor2!=nullptr)delete accessor2;
    }

    /**
     * The assignment operator
     * @param other an object of the same class, that is passed by a constant reference
     */
    virtual const wptr_accessor_chain<From,Intermediate,To>& operator =(const wptr_accessor_chain<From,Intermediate,To>& other){
        if(accessor1!=nullptr)delete accessor1;
        if(accessor2!=nullptr)delete accessor2;
        accessor1=other.accessor1->duplicate();
        accessor2=other.accessor2->duplicate();
        return other;
    }

    /**
     * A function that sets the value of the pointer to the first implementation of wptr_accessor
     * @param acc1 the pointer to an implementation of wptr_readable<wptr_accessor> that is the first link in the chain
     */

    void SetAccessor1(wptr_readable<wptr_accessor<From,Intermediate>>* acc1){
        if(accessor1!=nullptr)delete accessor1;
        accessor1 = acc1->duplicate();
    }

    /**
     * A function that sets the value of the pointer to the first implementation of wptr_accessor
     * @param acc1 the pointer to an implementation of wptr_base_readable<U> that is the first link in the chain
     */
    template<typename ActualAccessorType1>
    void SetAccessor1(wptr_base_readable<ActualAccessorType1>* acc1){
        if(accessor1!=nullptr)delete accessor1;
        wptr_inheritance<ActualAccessorType1,wptr_accessor<From,Intermediate>>* acc1_ptr = new wptr_inheritance<ActualAccessorType1,wptr_accessor<From,Intermediate>>();
        *acc1_ptr=*acc1;
        accessor1=acc1_ptr;
    }

    /**
     * A function that sets the value of the pointer to the second implementation of wptr_accessor
     * @param acc2 the pointer to an implementation of wptr_readable<wptr_accessor> that is the second link in the chain
     */
    void SetAccessor2(wptr_readable<wptr_accessor<Intermediate,To>>* acc2){
        if(accessor2!=nullptr)delete accessor2;
        accessor2 = acc2->duplicate();
    }

    /**
     * A function that sets the value of the pointer to the second implementation of wptr_accessor
     * @param acc2 the pointer to an implementation of wptr_base_readable<U> that is the second link in the chain
     */
    template<typename ActualAccessorType2>
    void SetAccessor2(wptr_base_readable<ActualAccessorType2>* acc2){
        if(accessor2!=nullptr)delete accessor2;
        wptr_inheritance<ActualAccessorType2,wptr_accessor<Intermediate,To>>* acc2_ptr = new wptr_inheritance<ActualAccessorType2,wptr_accessor<Intermediate,To>>();
        *acc2_ptr=*acc2;
        accessor2=acc2_ptr;
    }

    /**
     * A function that performs the pointer transformation, and calls the corresponding functions of its links
     * @param from Is the pointer to the initial object
     * @return is the resulting pointer
     */
    virtual To* access(From* from) const override{
        To* mptr = (*accessor2)->access((*accessor1)->access(from));
        return mptr;
    }
};
#endif // WPTR_ACCESSOR_CHAIN_H
