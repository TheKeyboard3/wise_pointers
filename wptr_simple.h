#ifndef WPTR_SIMPLE_H
#define WPTR_SIMPLE_H

#include "wptr_managed.h"
#include "wptr_readable.h"
#include "wptr_writable.h"
#include "wptr_base_readable.h"

/**
 * A wise_pointer that performs no transformations
 */
template<typename T>
class wptr_simple : virtual public wptr_readable<T>, virtual public wptr_writable<T>, virtual public wptr_base_readable<T>
{
protected:
    awptr_managed<T>* to = nullptr;
public:
    /**
     * Empty constructor
     */
    wptr_simple(){

    }

    /**
     * A constructor that takes an object of the base type as a reference
     * @param obj an existing object of the base type
     */
    wptr_simple(const T& obj){
        to = new wptr_managed<T>(obj);
        if(to != nullptr)to->refc_inc();
    }

    /**
     * Copy constructor
     * @param other an exisitng object of the same type
     */
    wptr_simple(const wptr_simple<T>& other){
        if(other.to!=nullptr)to = new wptr_managed<T>(**other.to);
        if(to != nullptr)to->refc_inc();
    }

    /**
     * A constructor that takes an implementation of wptr_base_readable with the same base type as an argument
     * @param other an implementation of wptr_base_readable with the same base type that is passed as a const reference
     */
    wptr_simple(const wptr_base_readable<T>& other){
        if(other.getReferenced()!=nullptr)to = other.getReferenced();
        if(to != nullptr)to->refc_inc();
    }

    /**
     * Destructor
     */
    virtual ~wptr_simple() override{
        if(to != nullptr)to->refc_dec();
    }

    /**
     * Assignment operator
     * @param other an exisitng object of the same type
     */
    const wptr_simple<T>& operator=(const wptr_simple<T>& other){
        if(to != nullptr)to->refc_dec();
        to = other.to;
        if(to != nullptr)to->refc_inc();
        return other;
    }

    /**
     * Assignment operator
     * @param other an implementaion of wptr_base_readable that is passed by const reference from which the opeerator takes the base object
     */
    virtual const wptr_base_readable<T>& operator=(const wptr_base_readable<T>& other) override{
        if(to != nullptr)to->refc_dec();
        to = other.getReferenced();
        if(to != nullptr)to->refc_inc();
        return other;
    }

    /**
     * The equality operator that tests wether the base object of this pointer and another imbplementation of wptr_base_readable with the same base type is the same
     * @param other an implementation of wptr_base_readable that is passed by const reference
     * @return true if the base object of this pointer and the implementation  of wptr_base_readable is the same, false otherwise
     */
    virtual bool operator==(const wptr_base_readable<T>& other) const override{
        return to==other.getReferenced();
    }

    /**
     * The inequality operator that tests wether the base object of this pointer and another imbplementation of wptr_base_readable with the same base type is the same
     * @param other an implementation of wptr_base_readable that is passed by const reference
     * @return false if the base object of this pointer and the implementation  of wptr_base_readable is the same, true otherwise
     */
    virtual bool operator!=(const wptr_base_readable<T>& other) const override{
        return to!=other.getReferenced();
    }

    /**
     * A function that returns a reference to the resulting object
     * @return a reference to the resulting object
     */
    virtual T& operator *() const override{
        return **to;
    }

    /**
     * A function that returns a pointer to the resulting object and provides access to its members
     * @return a pointer to the resulting object
     */
    virtual T* operator ->() const override{
        return (*to).operator->();
    }

    /**
     * A function that returns a copy of this pointer as an implementation of wptr_readable
     * @return a copy of this object as wptr_readable
     */
    virtual wptr_readable<T>* duplicate() const override{
        wptr_simple<T>* retval = new wptr_simple<T>();
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
    awptr_managed<T> * getReferenced() const override{
        return to;
    }
};
#endif // WPTR_H
