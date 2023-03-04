#ifndef WPTR_COMPLEX_H
#define WPTR_COMPLEX_H

#include "wptr_managed.h"
#include "wptr_readable.h"
#include "wptr_writable.h"
#include "wptr_accessor.h"
#include "wptr_base_readable.h"
#include "wptr_inheritance.h"

/**
 * A wise_pointer template class that uses a modifiable accessor to return an object of the desired type from the base object
 */
template<typename From, typename To>
class wptr_complex : virtual public wptr_writable<From>, virtual public wptr_readable<To>, virtual public wptr_base_readable<From>
{
protected:
    awptr_managed<From>* to = nullptr;
    wptr_readable<wptr_accessor<From,To>>* acc = nullptr;
public:
    /**
     * Empty constructor
     */
    wptr_complex(){

    }

    /**
     * A constructor that takes a constant reference to a object of the base type and a pointer to an implementation of wptr_readable<wptr_accessor> from which it takes the accessor
     * @param obj constant reference to a object of the base type
     * @param acc_set a pointer to an implementation of wptr_readable<wptr_accessor> from which the constructor takes the accessor
     */
    wptr_complex(const From& obj, wptr_readable<wptr_accessor<From,To>>* acc_set){
        to = new wptr_managed<From>(obj);
        if(to != nullptr)to->refc_inc();
        acc = acc_set->duplicate();
    }

    /**
     * A constructor that takes a constant reference to a object of the base type and a pointer to an implementation of wptr_base_readable from which it takes the accessor
     * @param obj constant reference to a object of the base type
     * @param acc_set a pointer to an implementation of wptr_base_readable from which the constructor takes the accessor
     */
    template<typename ActualAccessorType>
    wptr_complex(const From& obj, wptr_base_readable<ActualAccessorType>* acc_set){
        to = new wptr_managed<From>(obj);
        if(to != nullptr)to->refc_inc();
        wptr_inheritance<ActualAccessorType,wptr_accessor<From,To>>* acc1_ptr = new wptr_inheritance<ActualAccessorType,wptr_accessor<From,To>>();
        *acc1_ptr=*acc_set;
        acc=acc1_ptr;
    }

    /**
     * A constructor that takes a constant reference to a object of the base type and an accessor
     * @param obj constant reference to a object of the base type
     * @param acc_set the accessor
     */
    template<typename ActualAccessorType>
    wptr_complex(const From& obj, ActualAccessorType acc_set){
        to = new wptr_managed<From>(obj);
        if(to != nullptr)to->refc_inc();
        wptr_inheritance<ActualAccessorType,wptr_accessor<From,To>>* acc1_ptr = new wptr_inheritance<ActualAccessorType,wptr_accessor<From,To>>(acc_set);
        acc=acc1_ptr;
    }

    /**
     * Copy constructor
     * @param other an existing object of the same class that is passed by constant reference
     */
    wptr_complex(const wptr_complex<From,To>& other){
        if(other.to!=nullptr)to = new wptr_managed<From>(**other.to);
        if(to != nullptr)to->refc_inc();
        if(other.acc!=nullptr)acc = other.acc->duplicate();
    }

    /**
     * A constructor that takes a constant reference to an implementation of wptr_base_readable from which it takes the base object and a pointer to an implementation of wptr_readable<wptr_accessor> from which it takes the accessor
     * @param obj constant reference to an implementation of wptr_base_readable from which the constructor takes the base object
     * @param acc_set a pointer to an implementation of wptr_readable<wptr_accessor> from which the constructor takes the accessor
     */
    wptr_complex(const wptr_base_readable<From>& other, wptr_readable<wptr_accessor<From,To>>* acc_set){
        if(other.getReferenced()!=nullptr)to = other.getReferenced();
        if(to != nullptr)to->refc_inc();
        acc = acc_set->duplicate();
    }

    /**
     * A constructor that takes a constant reference to an implementation of wptr_base_readable from which it takes the base object and a pointer to an implementation of wptr_base_readable from which it takes the accessor
     * @param obj constant reference to a object of the base type
     * @param acc_set a pointer to an implementation of wptr_base_readable from which the constructor takes the accessor
     */
    template<typename ActualAccessorType>
    wptr_complex(const wptr_base_readable<From>& other, wptr_base_readable<ActualAccessorType>* acc_set){
        if(other.getReferenced()!=nullptr)to = other.getReferenced();
        if(to != nullptr)to->refc_inc();
        wptr_inheritance<ActualAccessorType,wptr_accessor<From,To>>* acc1_ptr = new wptr_inheritance<ActualAccessorType,wptr_accessor<From,To>>();
        *acc1_ptr=*acc_set;
        acc=acc1_ptr;
    }

    /**
     * A constructor that takes a constant reference to an implementation of wptr_base_readable from which it takes the base object and an accessor
     * @param obj constant reference to a object of the base type
     * @param acc_set the accessor
     */
    template<typename ActualAccessorType>
    wptr_complex(const wptr_base_readable<From>& other, ActualAccessorType acc_set){
        if(other.getReferenced()!=nullptr)to = other.getReferenced();
        if(to != nullptr)to->refc_inc();
        wptr_inheritance<ActualAccessorType,wptr_accessor<From,To>>* acc1_ptr = new wptr_inheritance<ActualAccessorType,wptr_accessor<From,To>>(acc_set);
        acc=acc1_ptr;
    }

    /**
     * Destructor
     */
    virtual ~wptr_complex() override{
        if(to != nullptr)to->refc_dec();
        if(acc != nullptr) delete acc;
    }

    /**
     * Assignment operator
     * @param other an existing object of the same class that is passed by const reference
     */
    virtual const wptr_complex<From,To>& operator=(const wptr_complex<From,To>& other){
        if(to != nullptr)to->refc_dec();
        to = other.to;
        if(to != nullptr)to->refc_inc();
        if(acc != nullptr) delete acc;
        acc = other.acc->duplicate();
        return other;
    }

    /**
     * Assignment operator
     * @param other an existing implementation of wptr_base_readable of the same base type that is passed by const reference
     */
    virtual const wptr_base_readable<From>& operator=(const wptr_base_readable<From>& other) override{
        if(to != nullptr)to->refc_dec();
        to = other.getReferenced();
        if(to != nullptr)to->refc_inc();
        return other;
    }

    /**
     * The equality operator that tests wether the base objects of this pointer, and an implementation of wptr_base_readable are the same
     * @param other an implementation of wptr_base_readable that is passed by const reference
     * @return true if the base objects of this pointer and an implementation of wptr_base_readable are the same, false otherwise
     */
    virtual bool operator==(const wptr_base_readable<From>& other) const override{
        return to==other.getReferenced();
    }

    /**
     * The inequality operator that tests wether the base objects of this pointer, and an implementation of wptr_base_readable are the same
     * @param other an implementation of wptr_base_readable that is passed by const reference
     * @return false if the base objects of this pointer and an implementation of wptr_base_readable are the same, true otherwise
     */
    virtual bool operator!=(const wptr_base_readable<From>& other) const override{
        return to!=other.getReferenced();
    }

    /**
     * The equality operator that tests wether the base objects of this pointer, and another pointer of the same class are the same
     * @param other another object of the same class that is passed by const reference
     * @return true if the base objects of this pointer and an implementation of wptr_base_readable are the same, false otherwise
     */
    bool operator==(const wptr_complex<From,To>& other) const{
        return to==other.getReferenced();
    }

    /**
     * The inequality operator that tests wether the base objects of this pointer, and another pointer of the same class are the same
     * @param other another object of the same class that is passed by const reference
     * @return false if the base objects of this pointer and an implementation of wptr_base_readable are the same, true otherwise
     */
    bool operator!=(const wptr_complex<From,To>& other) const{
        return to!=other.getReferenced();
    }

    /**
     * A function that returns a reference to the resulting object
     * @return a reference to the resulting object
     */
    virtual To& operator *() const override{
        return *(*acc)->access((*to).operator->());
    }

    /**
     * A function that returns a pointer to the resulting object and provides access to its members
     * @return a pointer to the resulting object
     */
    virtual To* operator ->() const override{
        return (*acc)->access((*to).operator->());
    }

    /**
     * A function that returns a copy of this pointer as an implementation of wptr_readable
     * @return a copy of this object as wptr_readable
     */
    virtual wptr_readable<To>* duplicate() const override{
         wptr_complex<From,To>* retval = new wptr_complex<From,To>();
         *retval = *this;
         return retval;
    }

    /**
     * A function that returns true if the base object or the accessor is not set
     * @return true if the base object or the accessor is not set, false otherwise
     */
    virtual bool empty() const override{
        return to==nullptr||acc==nullptr;
    }

    /**
     * A function that returns the amount of pointers that reference the same base object
     * @return the pointer count
     */
    unsigned int getRefCount() const{
        if(to==nullptr)return 0;
        wptr_managed<From>* mngd = dynamic_cast<wptr_managed<From>*>(to);
        if(mngd==nullptr)return 0;
        return mngd->getRefCount();
    }

    /**
     * A function that returns a pointer to the base object
     * @return a pointer to the base object
     */
    awptr_managed<From>* getReferenced() const override{
        return to;
    }

    /**
     * A function that returns a pointer to the accessor as an implementation of wptr_accessor
     * @return a pointer to the accessor as an implementation of wptr_accessor
     */
    wptr_readable<wptr_accessor<From,To>>* getAccessor() const{
        return acc->duplicate();
    }

    /**
     * A function that sets the value of the pointer to the accessor
     * @param acc_set a pointer to an implementation of wptr_readable<wptr_accessor> from which the function takes the accessor
     */
    void setAccessor(wptr_readable<wptr_accessor<From,To>>* acc_set){
        if(acc != nullptr) delete acc;
        acc = acc_set->duplicate();
    }

    /**
     * A function that sets the value of the pointer to the accessor
     * @param acc_set a pointer to an implementation of wptr_base_readable from which the constructor takes the accessor
     */
    template<typename ActualAccessorType>
    void setAccessor(wptr_base_readable<ActualAccessorType>* acc_set){
        if(acc != nullptr) delete acc;
        wptr_inheritance<ActualAccessorType,wptr_accessor<From,To>>* acc1_ptr = new wptr_inheritance<ActualAccessorType,wptr_accessor<From,To>>();
        *acc1_ptr=*acc_set;
        acc=acc1_ptr;
    }

    /**
     * A function that sets the value of the pointer to the accessor
     * @param acc_set the accessor
     */
    template<typename ActualAccessorType>
    void setAccessor(ActualAccessorType acc_set){
        if(acc != nullptr) delete acc;
        wptr_inheritance<ActualAccessorType,wptr_accessor<From,To>>* acc1_ptr = new wptr_inheritance<ActualAccessorType,wptr_accessor<From,To>>(acc_set);
        acc=acc1_ptr;
    }
};
#endif // WPTR_COMPLEX_H
