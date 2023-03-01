#ifndef WPTR_ACCESSOR_WRAP_H
#define WPTR_ACCESSOR_WRAP_H

#include "wptr_accessor_wrap_readable.h"
#include "wptr_accessor.h"
#include "wptr_simple.h"
#include "wptr_readable.h"
#include "wptr_writable.h"
#include "wptr_inheritance.h"

/**
 * A template class that combines an implementation of wptr_accessor with a pointer to an implementation ow wptr_managed
 * It provides the same interface for reading the value of the resulting object of the accessor regardless of the base type, or
 * the accessor
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
     * A constructor that takes a pointer to an implementation of wptr_base_readable, from which it takes the base object,
     * and a pointer to an implementation of wptr_readable<wptr_accessor>, from which it takes the accessor
     * @param from the pointer to an implementation of wptr_base_readable, from which the constructor takes the base object
     * @param acc the pointer to an implementation of wptr_readable<wptr_accessor>, from which the constructor takes the accessor
     */
    wptr_accessor_wrap(const wptr_base_readable<From>* from, wptr_readable<wptr_accessor<From,To>>* acc){
        to = from->getReferenced();
        if(to != nullptr)to->refc_inc();
        accessor = acc->duplicate();
    }

    /**
     * A constructor that takes a pointer to an implementation of wptr_base_readable, from which it takes the base object,
     * and a pointer to an implementation of wptr_base_readable, from which it takes the accessor
     * @param from the pointer to an implementation of wptr_base_readable, from which the constructor takes the base object
     * @param acc the pointer to an implementation of wptr_base_readable, from which the constructor takes the accessor
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
     * @param other an existing object of the same class that is passed by a constant reference
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
     * The equality operator that tests wether the base objects this wrap, and an implementation of wptr_base_readable are the same
     * @param other an implementation of wptr_base_readable, that is passed by const reference
     * @return true if the base objects of this wrap, and an implementation of wptr_base_readable are the same, false otherwise
     */
    virtual bool operator==(const wptr_base_readable<From>& other) const{
        return to==other.getReferenced();
    }

    /**
     * The equality operator that tests wether the base objects this object, and another object of this class are the same
     * @param other an object of this class, that is passed by const reference
     * @return true if the base objects this object, and another of the same class are the same, false otherwise
     */
    virtual bool operator==(const wptr_accessor_wrap<From,To>& other) const{
        return to==other.to;
    }

    /**
     * The inequality operator that tests wether the base objects this wrap, and an implementation of wptr_base_readable are the same
     * @param other an implementation of wptr_base_readable, that is passed by const reference
     * @return false if the base objects of this wrap, and an implementation of wptr_base_readable are the same, true otherwise
     */
    virtual bool operator!=(const wptr_base_readable<From>& other) const{
        return to!=other.getReferenced();
    }

    /**
     * The inequality operator that tests wether the base objects this object, and another object of this class are the same
     * @param other an object of this class, that is passed by const reference
     * @return false if the base objects this object, and another of the same class are the same, true otherwise
     */
    virtual bool operator!=(const wptr_accessor_wrap<From,To>& other) const{
        return to!=other.to;
    }

    /**
     * The assignment operator
     * @param other an existing object of this class that is passed by const reference
     */
    virtual const wptr_accessor_wrap<From,To>& operator=(const wptr_accessor_wrap<From,To>& other){
        to = other.to;
        if(to != nullptr)to->refc_inc();
        if(other.accessor!=nullptr)accessor = other.accessor->duplicate();
        return other;
    }

    /**
     * A function that increases the amount of pointers that reference this object
     */
    virtual void refc_inc() override{
        refcount++;
    }

    /**
     * A function that decreases the amount of pointers that reference this object
     */
    virtual void refc_dec() override{
        refcount--;
        if(refcount <= 0) delete this;
    }

    /**
     * A function that returns the resulting object
     */
    virtual To* access() const override{
        return (*accessor)->access(&(**to));
    }

    /**
     * A function that returns true if the base object is not set
     * @return true if the base object is not set, false otherwise
     */
    virtual bool empty() const override{
        return to==nullptr;
    }

    /**
     * A function that returns the amount of pointers that reference this object
     * @return the value of the reference counter
     */
    virtual int getRefCount() const override{
        return to->getRefCount();
    }

    /**
     * A function that returns the base object
     */
    awptr_managed<From> * getReferenced() const{
        return to;
    }

    /**
     * A function that creates a copy of this object as an implementation of the interface for reading
     */
    virtual wptr_accessor_wrap_readable<To>* duplicate() const override{
        wptr_accessor_wrap<From,To>* retval = new wptr_accessor_wrap<From,To>();
        *retval = *this;
        return retval;
    }
};
#endif // WPTR_H
