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
 * @todo write docs
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
     * Default constructor
     */
    wptr_wrapped(const T obj){
        wptr_simple<T> obj_ptr = wptr_simple<T>(obj);
        wptr_simple<wptr_no_accessor<T>> noaccptr = wptr_simple<wptr_no_accessor<T>>(wptr_no_accessor<T>());
        wptr_inheritance<wptr_no_accessor<T>,wptr_accessor<T,T>> noaccptr_inh = wptr_inheritance<wptr_no_accessor<T>,wptr_accessor<T,T>>();
        noaccptr_inh=noaccptr;
        to = new wptr_accessor_wrap<T,T>((wptr_base_readable<T>*)&obj_ptr,(wptr_readable<wptr_accessor<T,T>>*)&noaccptr_inh);
        if(to != nullptr)to->refc_inc();
    }

    /**
     * Default constructor
     */
    template<typename OtherType>
    wptr_wrapped(const OtherType& obj, wptr_readable<wptr_accessor<OtherType,T>>* acc){
        wptr_simple<T> obj_ptr = wptr_simple<T>(obj);
        to = new wptr_accessor_wrap<OtherType,T>(&obj_ptr,acc);
        if(to != nullptr)to->refc_inc();
    }

    /**
     * Default constructor
     */
    template<typename OtherType>
    wptr_wrapped(wptr_base_readable<OtherType>& obj_ptr, wptr_readable<wptr_accessor<OtherType,T>>* acc){
        to = new wptr_accessor_wrap<T,T>(&obj_ptr,acc);
        if(to != nullptr)to->refc_inc();
    }

    /**
     * Copy constructor
     *
     * @param other TODO
     */
    wptr_wrapped(const wptr_wrapped<T>& other){
        if(other.to!=nullptr){
            to = other.to->duplicate();
        }
        if(to != nullptr)to->refc_inc();
    }

    /**
     * Copy constructor
     *
     * @param other TODO
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
     *
     * @param other TODO
     * @return TODO
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
     * @todo write docs
     */
    virtual T& operator *() const override{
        return *to->access();
    }

    /**
     * @todo write docs
     */
    virtual T* operator ->() const override{
        return to->access();
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
    virtual wptr_readable<T>* duplicate() const override{
        wptr_wrapped<T>* wrapped_ptr = new wptr_wrapped<T>(*this);
        wptr_readable<T>* rdbl = wrapped_ptr;
        return rdbl;
    }
};
#endif // WPTR_COMPLEX_H
