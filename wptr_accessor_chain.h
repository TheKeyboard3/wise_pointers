#ifndef WPTR_ACCESSOR_CHAIN_H
#define WPTR_ACCESSOR_CHAIN_H

#include "wptr_accessor.h"
#include "wptr_readable.h"
#include "wptr_inheritance.h"

/**
 * @todo write docs
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
     * Default constructor
     */
    wptr_accessor_chain(wptr_readable<wptr_accessor<From,Intermediate>>* acc1, wptr_readable<wptr_accessor<Intermediate,To>>* acc2){
        accessor1=acc1->duplicate();
        accessor2=acc2->duplicate();
    }

    /**
     * Copy constructor
     */
    wptr_accessor_chain(const wptr_accessor_chain<From,Intermediate,To>& other){
        accessor1=other.accessor1->duplicate();
        accessor2=other.accessor2->duplicate();
    }

    /**
     * Constructor from base_readables
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
     * @todo write docs
     *
     * @param other TODO
     * @return TODO
     */
    virtual const wptr_accessor_chain<From,Intermediate,To>& operator =(const wptr_accessor_chain<From,Intermediate,To>& other){
        if(accessor1!=nullptr)delete accessor1;
        if(accessor2!=nullptr)delete accessor2;
        accessor1=other.accessor1->duplicate();
        accessor2=other.accessor2->duplicate();
        return other;
    }

    /**
     * @todo write docs
     *
     * @param other TODO
     * @return TODO
     */

    void SetAccessor1(wptr_readable<wptr_accessor<From,Intermediate>>* acc1){
        if(accessor1!=nullptr)delete accessor1;
        accessor1 = acc1->duplicate();
    }

    /**
     * @todo write docs
     *
     * @param other TODO
     * @return TODO
     */
    template<typename ActualAccessorType1>
    void SetAccessor1(wptr_base_readable<ActualAccessorType1>* acc1){
        if(accessor1!=nullptr)delete accessor1;
        wptr_inheritance<ActualAccessorType1,wptr_accessor<From,Intermediate>>* acc1_ptr = new wptr_inheritance<ActualAccessorType1,wptr_accessor<From,Intermediate>>();
        *acc1_ptr=*acc1;
        accessor1=acc1_ptr;
    }

    /**
     * @todo write docs
     *
     * @param other TODO
     * @return TODO
     */
    void SetAccessor2(wptr_readable<wptr_accessor<Intermediate,To>>* acc2){
        if(accessor2!=nullptr)delete accessor2;
        accessor2 = acc2->duplicate();
    }

    /**
     * @todo write docs
     *
     * @param other TODO
     * @return TODO
     */
    template<typename ActualAccessorType2>
    void SetAccessor2(wptr_base_readable<ActualAccessorType2>* acc2){
        if(accessor2!=nullptr)delete accessor2;
        wptr_inheritance<ActualAccessorType2,wptr_accessor<Intermediate,To>>* acc2_ptr = new wptr_inheritance<ActualAccessorType2,wptr_accessor<Intermediate,To>>();
        *acc2_ptr=*acc2;
        accessor2=acc2_ptr;
    }

    /**
     * @todo write docs
     */
    virtual To* access(From* from) const override{
        To* mptr = (*accessor2)->access((*accessor1)->access(from));
        return mptr;
    }
};
#endif // WPTR_ACCESSOR_CHAIN_H
