#ifndef WPTR_COMPLEX_H
#define WPTR_COMPLEX_H

#include "wptr_managed.h"
#include "wptr_accessor_wrap.h"
#include "wptr_accessor_wrap_readable.h"
#include "wptr_inheritance.h"
#include "wptr_simple.h"
#include "wptr_readable.h"
#include "wptr_writable.h"
#include "wptr_no_accessor.h"


/**
 * A template class that provides access to a wptr_accessor_wrap
 */
template<typename T>
class wptr_wrapped : virtual public wptr_readable<T>, virtual public wptr_writable<T>
{
protected:
    wptr_accessor_wrap_readable<T>* to = nullptr;
public:
    /**
     * Empty constructor
     */
    wptr_wrapped(){

    }

    /**
     * A constructor that takes an object of the target type as an argument
     * @param obj an existing object of the target type that is passed by const reference
     */
    wptr_wrapped(const T& obj){
        wptr_simple<T> obj_ptr = wptr_simple<T>(obj);
        wptr_simple<wptr_no_accessor<T>> noaccptr = wptr_simple<wptr_no_accessor<T>>(wptr_no_accessor<T>());
        wptr_inheritance<wptr_no_accessor<T>,wptr_accessor<T,T>> noaccptr_inh = wptr_inheritance<wptr_no_accessor<T>,wptr_accessor<T,T>>();
        noaccptr_inh=noaccptr;
        to = new wptr_accessor_wrap<T,T>((wptr_base_readable<T>*)&obj_ptr,(wptr_readable<wptr_accessor<T,T>>*)&noaccptr_inh);
        if(to != nullptr)to->refc_inc();
    }

    /**
     * A constructor that takes an object of the base type and a pointer to an implementation of wptr_readable<wptr_accessor> as arguments
     * @param obj an existing object of the base type that is passed by const reference
     * @param acc a pointer to an implementation of wptr_readable<wptr_accessor> from which the constructor takes the accessor
     */
    template<typename OtherType>
    wptr_wrapped(const OtherType& obj, wptr_readable<wptr_accessor<OtherType,T>>* acc){
        wptr_simple<T> obj_ptr = wptr_simple<T>(obj);
        to = new wptr_accessor_wrap<OtherType,T>(&obj_ptr,acc);
        if(to != nullptr)to->refc_inc();
    }

    /**
     * A constructor that takes an object of the base type and a pointer to an implementation of wptr_readable<wptr_accessor> as arguments
     * @param obj an existing object of the base type that is passed by const reference
     * @param acc a pointer to an implementation of wptr_readable<wptr_accessor> from which the constructor takes the accessor
     */
    template<typename OtherType>
    wptr_wrapped(wptr_base_readable<OtherType>& obj_ptr, wptr_readable<wptr_accessor<OtherType,T>>* acc){
        to = new wptr_accessor_wrap<T,T>(&obj_ptr,acc);
        if(to != nullptr)to->refc_inc();
    }

    /**
     * Copy constructor
     * @param other an existing object of the same class
     */
    wptr_wrapped(const wptr_wrapped<T>& other){
        if(other.to!=nullptr){
            to = other.to->duplicate();
        }
        if(to != nullptr)to->refc_inc();
    }

    /**
     * A constructor that take an implementation of wptr_base_readable with a base type that corresponds to the target type of this class
     * @param other other an implementation of wptr_base_readable with a base type that corresponds to the target type of this class from which the constructor takes the base object
     * wptr_no_accessor is used as the accessor
     */
    wptr_wrapped(const wptr_base_readable<T>& other){
        if(other.getReferenced()!=nullptr){
            wptr_simple<wptr_no_accessor<T>> noaccptr = wptr_simple<wptr_no_accessor<T>>(wptr_no_accessor<T>());
            wptr_inheritance<wptr_no_accessor<T>,wptr_accessor<T,T>> noaccptr_inh = wptr_inheritance<wptr_no_accessor<T>,wptr_accessor<T,T>>();
            noaccptr_inh=noaccptr;
            to = new wptr_accessor_wrap<T,T>(&other,&noaccptr_inh);
        }
        if(to != nullptr)to->refc_inc();
    }

    /**
     * Destructor
     */
    virtual ~wptr_wrapped() override{
        if(to != nullptr){
            to->refc_dec();
        }
    }

    /**
     * Assignment operator
     * @param other an implementation of wptr_base_readable with a base type that corresponds to the target type of this class from which the function takes the base object
     */
    virtual const wptr_base_readable<T>& operator=(const wptr_base_readable<T>& other) override{
        if(to != nullptr)to->refc_dec();
        if(other.getReferenced()!=nullptr){
            wptr_simple<wptr_no_accessor<T>> noaccptr = wptr_simple<wptr_no_accessor<T>>(wptr_no_accessor<T>());
            wptr_inheritance<wptr_no_accessor<T>,wptr_accessor<T,T>> noaccptr_inh = wptr_inheritance<wptr_no_accessor<T>,wptr_accessor<T,T>>();
            noaccptr_inh=noaccptr;
            to = new wptr_accessor_wrap<T,T>(&other,&noaccptr_inh);
        }
        if(to != nullptr)to->refc_inc();
        return other;
    }


    /**
     * A function that returns a reference to the resulting object
     * @return a reference to the resulting object
     */
    virtual T& operator *() const override{
        return *to->access();
    }

    /**
     * A function that returns a pointer to the resulting object and provides access to its members
     * @return a pointer to the resulting object
     */
    virtual T* operator ->() const override{
        return to->access();
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
    template<typename basetype>
    unsigned int getRefCount() const{
        if(to == nullptr)return 0;
        wptr_accessor_wrap<basetype, T>* mngd = dynamic_cast<wptr_accessor_wrap<basetype, T>*>(to);
        if(mngd==nullptr)return 0;
        return to->getRefCount();
    }

    /**
     * A function that returns a pointer to the base object
     * @return a pointer to the base object
     */
    virtual wptr_readable<T>* duplicate() const override{
        wptr_wrapped<T>* wrapped_ptr = new wptr_wrapped<T>(*this);
        wptr_readable<T>* rdbl = wrapped_ptr;
        return rdbl;
    }
};
#endif // WPTR_COMPLEX_H
