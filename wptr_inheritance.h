#ifndef WPTR_INH_H
#define WPTR_INH_H

#include "wptr_managed.h"
#include "wptr_readable.h"
#include "wptr_writable.h"
#include "wptr_inheritance_accessor.h"
#include "wptr_base_readable.h"

/**
 * @todo write docs
 */
template<typename Parent, typename Child>
class wptr_inheritance : virtual public wptr_writable<Parent>, virtual public wptr_readable<Child>, virtual public wptr_base_readable<Parent>
{
protected:
    awptr_managed<Parent>* to = nullptr;
    const wptr_inheritance_accessor<Parent,Child> acc;
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
    wptr_inheritance(const Parent& obj){
        to = new wptr_managed<Parent>(obj);
        if(to != nullptr)to->refc_inc();
    }

    /**
     * Copy constructor
     * @param other an existing object of the same class passed by const reference
     */
    wptr_inheritance(const wptr_inheritance<Parent,Child>& other){
        if(other.to!=nullptr)to = new wptr_managed<Parent>(**other.to);
        if(to != nullptr)to->refc_inc();
    }

    /**
     * A constructor that takes a constant reference to an implementation of wptr_base_readable from which it takes the base object
     * @param obj constant reference to an implementation of wptr_base_readable from which the constructor takes the base object
     */
    wptr_inheritance(const wptr_base_readable<Parent>& other){
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
    virtual const wptr_inheritance<Parent,Child>& operator=(const wptr_inheritance<Parent,Child>& other){
        if(to != nullptr)to->refc_dec();
        to = other.to;
        if(to != nullptr)to->refc_inc();
        return other;
    }

    /**
     * Assignment operator
     * @param other an existing implementation of wptr_base_readable of the same base type that is passed by const reference
     */
    virtual const wptr_base_readable<Parent>& operator=(const wptr_base_readable<Parent>& other) override{
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
    virtual bool operator==(const wptr_base_readable<Parent>& other) const override{
        return to==other.getReferenced();
    }

     /**
     * The inequality operator that tests wether the base objects of this pointer, and an implementation of wptr_base_readable are the same
     * @param other an implementation of wptr_base_readable that is passed by const reference
     * @return false if the base objects of this pointer and an implementation of wptr_base_readable are the same, true otherwise
     */
    virtual bool operator!=(const wptr_base_readable<Parent>& other) const override{
        return to!=other.getReferenced();
    }

    /**
     * The equality operator that tests wether the base objects of this pointer, and another pointer of the same class are the same
     * @param other another object of the same class that is passed by const reference
     * @return true if the base objects of this pointer and an implementation of wptr_base_readable are the same, false otherwise
     */
    bool operator==(const wptr_inheritance<Parent,Child>& other) const{
        return to==other.to;
    }

    /**
     * The inequality operator that tests wether the base objects of this pointer, and another pointer of the same class are the same
     * @param other another object of the same class that is passed by const reference
     * @return false if the base objects of this pointer and an implementation of wptr_base_readable are the same, true otherwise
     */
    bool operator!=(const wptr_inheritance<Parent,Child>& other) const{
        return to!=other.to;
    }

    /**
     * A function that returns a reference to the resulting object
     * @return a reference to the resulting object
     */
    virtual Child& operator *() const override{
        return *acc.access((*to).operator->());
    }

    /**
     * A function that returns a pointer to the resulting object and provides access to its members
     * @return a pointer to the resulting object
     */
    virtual Child* operator ->() const override{
        return acc.access((*to).operator->());
    }

     /**
     * A function that returns a copy of this pointer as an implementation of wptr_readable
     * @return a copy of this object as wptr_readable
     */
    virtual wptr_readable<Child>* duplicate() const override{
         wptr_inheritance<Parent,Child>* retval = new wptr_inheritance<Parent,Child>();
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
    virtual int getRefCount() const override{
        if(to==nullptr)return 0;
        return to->getRefCount();
    }

    /**
     * A function that returns a pointer to the base object
     * @return a pointer to the base object
     */
    awptr_managed<Parent> * getReferenced() const override{
        return to;
    }
};
#endif // WPTR_INH_H
