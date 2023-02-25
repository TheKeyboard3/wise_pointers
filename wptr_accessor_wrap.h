#ifndef WPTR_ACCESSOR_WRAP_H
#define WPTR_ACCESSOR_WRAP_H

#include "wptr_accessor_wrap_readable.h"
#include "wptr_accessor.h"
#include "wptr_simple.h"
#include "wptr_readable.h"
#include "wptr_writable.h"
#include "wptr_inheritance.h"

/**
 * @todo write docs
 */
template<typename From, typename To>
class wptr_accessor_wrap : virtual public wptr_accessor_wrap_readable<To>
{
protected:
    unsigned int refcount = 0;
    awptr_managed<From>* to = nullptr;
    wptr_readable<wptr_accessor<From,To>>* accessor = nullptr;
public:
    /**
     * Empty constructor
     */
    wptr_accessor_wrap(){

    }

    /**
     * Default constructor
     */
    wptr_accessor_wrap(const wptr_base_readable<From>* from, wptr_readable<wptr_accessor<From,To>>* acc){
        to = from->getReferenced();
        if(to != nullptr)to->refc_inc();
        accessor = acc->duplicate();
    }

    /**
     * Default constructor
     */
    template<typename ActualAccessorType>
    wptr_accessor_wrap(const wptr_base_readable<From>* from, wptr_base_readable<ActualAccessorType>* acc){
        to = from->getReferenced();
        if(to != nullptr)to->refc_inc();
        wptr_inheritance<ActualAccessorType,wptr_accessor<From,To>>* acc1_ptr = new wptr_inheritance<ActualAccessorType,wptr_accessor<From,To>>();
        *acc1_ptr=*acc;
        accessor=acc1_ptr;
    }

    /**
     * Copy constructor
     */
    wptr_accessor_wrap(const wptr_accessor_wrap<From,To>& other){
        if(other.to!=nullptr)to = new wptr_managed<From>(**other.to);
        if(to != nullptr)to->refc_inc();
        if(other.accessor!=nullptr)accessor = other.accessor->duplicate();
    }


    /**
     * Destructor
     */
    virtual ~wptr_accessor_wrap() override{
        if(to != nullptr)to->refc_dec();
        if(accessor!=nullptr)delete accessor;
    }

    /**
     * @todo write docs
     *
     * @param other TODO
     * @return TODO
     */
    virtual bool operator==(const wptr_base_readable<From>& other) const{
        return to==other.getReferenced();
    }

    /**
     * @todo write docs
     *
     * @param other TODO
     * @return TODO
     */
    virtual bool operator==(const wptr_accessor_wrap<From,To>& other) const{
        return to==other.to;
    }

    /**
     * @todo write docs
     *
     * @param other TODO
     * @return TODO
     */
    virtual bool operator!=(const wptr_base_readable<From>& other) const{
        return to!=other.getReferenced();
    }

    /**
     * @todo write docs
     *
     * @param other TODO
     * @return TODO
     */
    virtual bool operator!=(const wptr_accessor_wrap<From,To>& other) const{
        return to!=other.to;
    }

    /**
     * @todo write docs
     *
     * @param other TODO
     * @return TODO
     */
    virtual const wptr_accessor_wrap<From,To>& operator=(const wptr_accessor_wrap<From,To>& other){
        to = other.to;
        if(to != nullptr)to->refc_inc();
        if(other.accessor!=nullptr)accessor = other.accessor->duplicate();
        return other;
    }

    /**
     * @todo write docs
     */
    virtual void refc_inc() override{
        refcount++;
    }

    /**
     * @todo write docs
     */
    virtual void refc_dec() override{
        refcount--;
        if(refcount <= 0) delete this;
    }

    /**
     * @todo write docs
     */
    virtual To* access() const override{
        return (*accessor)->access(&(**to));
    }

    /**
     * @todo write docs
     */
    virtual bool empty() const override{
        return to==nullptr;
    }

    /**
     * @todo write docs
     */
    virtual int getRefCount() const override{
        return to->getRefCount();
    }

    /**
     * @todo write docs
     */
    awptr_managed<From> * getReferenced() const{
        return to;
    }

    /**
     * @todo write docs
     */
    virtual wptr_accessor_wrap_readable<To>* duplicate() const override{
        wptr_accessor_wrap<From,To>* retval = new wptr_accessor_wrap<From,To>();
        *retval = *this;
        return retval;
    }
};
#endif // WPTR_H
