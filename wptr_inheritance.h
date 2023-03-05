#ifndef WPTR_INH_H
#define WPTR_INH_H

#include "wptr_managed_simple.h"
#include "wptr_readable.h"
#include "wptr_writable.h"
#include "wptr_inheritance_accessor.h"
#include "wptr_base_readable.h"

/**
 * A wise_pointer that uses a base object of a descendant class, and provides access to it as to an object of its public parent class
 */
template<typename Child, typename Parent>
class wptr_inheritance : virtual public wptr_writable<Child>, virtual public wptr_readable<Parent>, virtual public wptr_base_readable<Child>
{
protected:
    wptr_managed<Child>* to = nullptr;
    const wptr_inheritance_accessor<Child,Parent> acc;
public:
    /**
     * Empty constructor
     */
    wptr_inheritance(){

    }

    /**
     * A constructor that takes a constant reference to a object of the base type
     * @param obj constant reference to a object of the base type
     */
    wptr_inheritance(const Child& obj){
        to = new wptr_managed_simple<Child>(obj);
        if(to != nullptr)to->refc_inc();
    }

    /**
     * Copy constructor
     * @param other an existing object of the same class passed by const reference
     */
    wptr_inheritance(const wptr_inheritance<Child,Parent>& other){
        if(other.to!=nullptr)to = new wptr_managed_simple<Child>(**other.to);
        if(to != nullptr)to->refc_inc();
    }

    /**
     * A constructor that takes a constant reference to an implementation of wptr_base_readable from which it takes the base object
     * @param obj constant reference to an implementation of wptr_base_readable from which the constructor takes the base object
     */
    wptr_inheritance(const wptr_base_readable<Child>& other){
        if(other.getReferenced()!=nullptr)to = other.getReferenced();
        if(to != nullptr)to->refc_inc();
    }

    /**
     * Destructor
     */
    virtual ~wptr_inheritance() override{
        if(to != nullptr)to->refc_dec();
    }

    /**
     * Assignment operator
     * @param other an existing object of the same class that is passed by const reference
     */
    virtual const wptr_inheritance<Child,Parent>& operator=(const wptr_inheritance<Child,Parent>& other){
        if(to != nullptr)to->refc_dec();
        to = other.to;
        if(to != nullptr)to->refc_inc();
        return other;
    }

    /**
     * Assignment operator
     * @param other an existing implementation of wptr_base_readable of the same base type that is passed by const reference
     */
    virtual const wptr_base_readable<Child>& operator=(const wptr_base_readable<Child>& other) override{
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
    virtual bool operator==(const wptr_base_readable<Child>& other) const override{
        return to==other.getReferenced();
    }

     /**
     * The inequality operator that tests wether the base objects of this pointer, and an implementation of wptr_base_readable are the same
     * @param other an implementation of wptr_base_readable that is passed by const reference
     * @return false if the base objects of this pointer and an implementation of wptr_base_readable are the same, true otherwise
     */
    virtual bool operator!=(const wptr_base_readable<Child>& other) const override{
        return to!=other.getReferenced();
    }

    /**
     * The equality operator that tests wether the base objects of this pointer, and another pointer of the same class are the same
     * @param other another object of the same class that is passed by const reference
     * @return true if the base objects of this pointer and an implementation of wptr_base_readable are the same, false otherwise
     */
    bool operator==(const wptr_inheritance<Child,Parent>& other) const{
        return to==other.to;
    }

    /**
     * The inequality operator that tests wether the base objects of this pointer, and another pointer of the same class are the same
     * @param other another object of the same class that is passed by const reference
     * @return false if the base objects of this pointer and an implementation of wptr_base_readable are the same, true otherwise
     */
    bool operator!=(const wptr_inheritance<Child,Parent>& other) const{
        return to!=other.to;
    }

    /**
     * A function that returns a reference to the resulting object
     * @return a reference to the resulting object
     */
    virtual Parent& operator *() const override{
        return *acc.access((*to).operator->());
    }

    /**
     * A function that returns a pointer to the resulting object and provides access to its members
     * @return a pointer to the resulting object
     */
    virtual Parent* operator ->() const override{
        return acc.access((*to).operator->());
    }

    /**
     * A function that returns a copy of this pointer as an implementation of wptr_readable
     * @return a copy of this object as wptr_readable
     */
    virtual wptr_readable<Parent>* duplicate() const override{
         wptr_inheritance<Child,Parent>* retval = new wptr_inheritance<Child,Parent>();
         *retval = *this;
         return retval;
    }

    /**
     * A function that returns true if the base object is not set
     * @return true if the base object is not set, false otherwise
     */
    virtual bool empty() const override{
        return to==nullptr;
    }

    /**
     * A function that returns the amount of pointers that reference the same base object
     * @return the pointer count
     */
    unsigned int getRefCount() const{
        if(to==nullptr)return 0;
        wptr_managed_simple<Child>* mngd = dynamic_cast<wptr_managed_simple<Child>*>(to);
        if(mngd==nullptr)return 0;
        return mngd->getRefCount();
    }

    /**
     * A function that returns a pointer to the base object
     * @return a pointer to the base object
     */
    wptr_managed<Child> * getReferenced() const override{
        return to;
    }
};
#endif // WPTR_INH_H
