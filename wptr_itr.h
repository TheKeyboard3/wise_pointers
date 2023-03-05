#ifndef WPTR_ITR_H
#define WPTR_ITR_H

#include "wptr_managed_simple.h"
#include "wptr_readable.h"
#include "wptr_writable.h"
#include "wptr_itr_accessor.h"
#include "wptr_simple.h"
#include "wptr_base_readable.h"

/**
 * A wise_pointer that uses a base object of an iterable class, and provide access to it`s element
 */
template<typename Parent, typename IndexType, typename Child>
class wptr_itr : virtual public wptr_readable<Child>, virtual public wptr_writable<Parent>, virtual public wptr_base_readable<Parent>
{
protected:
    wptr_managed<Parent>* to = nullptr;
    wptr_simple<wptr_itr_accessor<Parent, IndexType,Child>> acc;
public:
    /**
     * Empty constructor
     */
    wptr_itr(){
        to = nullptr;
    }

    /**
     * A constructor that takes and index as an argument
     * @param ind an existing object of the index type that is passed by const reference
     */
    wptr_itr(const IndexType& ind){
        to = nullptr;
        acc = wptr_simple<wptr_itr_accessor<Parent, IndexType,Child>>(wptr_itr_accessor<Parent, IndexType,Child>(ind));
    }

    /**
     * A constructor that takes and index and an object of the base type as arguments
     * @param obj an existing object of the base type that is passed by const reference
     * @param ind an existing object of the index type that is passed by const reference
     */
    wptr_itr(const Parent& obj, const IndexType& ind){
        to = new wptr_managed_simple<Parent>(obj);
        if(to != nullptr)to->refc_inc();
        acc = wptr_simple<wptr_itr_accessor<Parent, IndexType,Child>>(wptr_itr_accessor<Parent, IndexType,Child>(ind));
    }

    /**
     * Copy constructor
     * @param other an existing object of the same class that is passed by const reference
     */
    wptr_itr(const wptr_itr<Parent,IndexType,Child>& other){
        if(other.getReferenced()!=nullptr)to = new wptr_managed_simple<Parent>(**other.getReferenced());
        if(to != nullptr)to->refc_inc();
        acc = wptr_simple<wptr_itr_accessor<Parent, IndexType,Child>>(wptr_itr_accessor<Parent, IndexType,Child>(*other.acc));
    }

    /**
     * A constructor that takes and index and an imbplementation of wptr_base_readable with the same base type as arguments
     * @param other an imbplementation of wptr_base_readable with the same base type that is passed by const reference
     * @param ind an existing object of the index type that is passed by const reference
     */
    wptr_itr(const wptr_base_readable<Parent>& other,  const IndexType& ind){
        if(other.getReferenced()!=nullptr)to = other.getReferenced();
        if(to != nullptr)to->refc_inc();
        acc = wptr_simple<wptr_itr_accessor<Parent, IndexType,Child>>(wptr_itr_accessor<Parent, IndexType,Child>(ind));
    }

    /**
     * Destructor
     */
    virtual ~wptr_itr() override{
        if(to != nullptr)to->refc_dec();
    }

    /**
     * Assignment operator
     * @param other an existing object of the same class that is passed by const reference
     */
    const wptr_itr<Parent,IndexType,Child>& operator=(const wptr_itr<Parent,IndexType,Child>& other){
        if(to != nullptr)to->refc_dec();
        to = other.getReferenced();
        if(to != nullptr)to->refc_inc();
        acc = wptr_simple<wptr_itr_accessor<Parent, IndexType,Child>>(wptr_itr_accessor<Parent, IndexType,Child>(*other.acc));
        return other;
    }

    /**
     * Assignment operator
     * @param other an imbplementation of wptr_base_readable with the same base type that is passed by const reference
     */
    virtual const wptr_base_readable<Parent>& operator=(const wptr_base_readable<Parent>& other) override{
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
    virtual bool operator==(const wptr_base_readable<Parent>& other) const override{
        return to==other.getReferenced();
    }

    /**
     * The inequality operator that tests wether the base object of this pointer and another imbplementation of wptr_base_readable with the same base type is the same
     * @param other an implementation of wptr_base_readable that is passed by const reference
     * @return false if the base object of this pointer and the implementation  of wptr_base_readable is the same, true otherwise
     */
    virtual bool operator!=(const wptr_base_readable<Parent>& other) const override{
        return to!=other.getReferenced();
    }

    /**
     * The equality operator that tests wether the base object and the index of this pointer and another pointer of the same class are the same
     * @param other an existing object of the same class that is passed by const reference
     * @return true if the base object and the index of this pointer and another pointer of the same class are the same, false otherwise
     */
    bool operator==(const wptr_itr<Parent,IndexType,Child>& other) const{
        if(*acc!=*other.acc)return false;
        return to==other.to;
    }

    /**
     * The equality operator that tests wether the base object and the index of this pointer and another pointer of the same class are the same
     * @param other an existing object of the same class that is passed by const reference
     * @return false if the base object and the index of this pointer and another pointer of the same class are the same, true otherwise
     */
    bool operator!=(const wptr_itr<Parent,IndexType,Child>& other) const{
        if(*acc!=*other.acc)return true;
        return to!=other.to;
    }

    /**
     * A function that returns a reference to the resulting object
     * @return a reference to the resulting object
     */
    virtual Child& operator *() const override{
        return *acc->access((*to).operator->());
    }

    /**
     * A function that returns a pointer to the resulting object and provides access to its members
     * @return a pointer to the resulting object
     */
    virtual Child* operator ->() const override{
        return acc->access((*to).operator->());
    }

    /**
     * A function that returns a copy of this pointer as an implementation of wptr_readable
     * @return a copy of this object as wptr_readable
     */
    virtual wptr_readable<Child>* duplicate() const override{
        wptr_itr<Parent,IndexType,Child>* retval = new wptr_itr<Parent,IndexType,Child>();
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
        wptr_managed_simple<Parent>* mngd = dynamic_cast<wptr_managed_simple<Parent>*>(to);
        if(mngd==nullptr)return 0;
        return mngd->getRefCount();
    }

    /**
     * A function that returns a pointer to the base object
     * @return a pointer to the base object
     */
    wptr_managed<Parent> * getReferenced() const override{
        return to;
    }
};
#endif // WPTR_ITR_H
