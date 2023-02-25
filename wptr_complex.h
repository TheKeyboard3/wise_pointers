#ifndef WPTR_COMPLEX_H
#define WPTR_COMPLEX_H

#include "wptr_managed.h"
#include "wptr_readable.h"
#include "wptr_writable.h"
#include "wptr_accessor.h"
#include "wptr_base_readable.h"
#include "wptr_inheritance.h"

/**
 * @todo write docs
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
     * Default constructor
     */
    wptr_complex(const From& obj, wptr_readable<wptr_accessor<From,To>>* acc_set){
        to = new wptr_managed<From>(obj);
        if(to != nullptr)to->refc_inc();
        acc = acc_set->duplicate();
    }

    /**
     * Default constructor
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
     * Default constructor
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
     *
     * @param other TODO
     */
    wptr_complex(const wptr_complex<From,To>& other){
        if(other.to!=nullptr)to = new wptr_managed<From>(**other.to);
        if(to != nullptr)to->refc_inc();
        if(other.acc!=nullptr)acc = other.acc->duplicate();
    }

    /**
     * Copy constructor
     *
     * @param other TODO
     */
    wptr_complex(const wptr_base_readable<From>& other, wptr_readable<wptr_accessor<From,To>>* acc_set){
        if(other.getReferenced()!=nullptr)to = other.getReferenced();
        if(to != nullptr)to->refc_inc();
        acc = acc_set->duplicate();
    }

    /**
     * Copy constructor
     *
     * @param other TODO
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
     * Copy constructor
     *
     * @param other TODO
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
     *
     * @param other TODO
     * @return TODO
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
     *
     * @param other TODO
     * @return TODO
     */
    virtual const wptr_base_readable<From>& operator=(const wptr_base_readable<From>& other) override{
        if(to != nullptr)to->refc_dec();
        to = other.getReferenced();
        if(to != nullptr)to->refc_inc();
        return other;
    }

    /**
     * @todo write docs
     *
     * @param other TODO
     * @return TODO
     */
    virtual bool operator==(const wptr_base_readable<From>& other) const override{
        return to==other.getReferenced();
    }

    /**
     * @todo write docs
     *
     * @param other TODO
     * @return TODO
     */
    virtual bool operator!=(const wptr_base_readable<From>& other) const override{
        return to!=other.getReferenced();
    }

    /**
     * @todo write docs
     *
     * @param other TODO
     * @return TODO
     */
    bool operator==(const wptr_complex<From,To>& other) const{
        return to==other.getReferenced();
    }

    /**
     * @todo write docs
     *
     * @param other TODO
     * @return TODO
     */
    bool operator!=(const wptr_complex<From,To>& other) const{
        return to!=other.getReferenced();
    }

    /**
     * @todo write docs
     */
    virtual To& operator *() const override{
        return *(*acc)->access((*to).operator->());
    }

    /**
     * @todo write docs
     */
    virtual To* operator ->() const override{
        return (*acc)->access((*to).operator->());
    }

    /**
     * @todo write docs
     */
    virtual wptr_readable<To>* duplicate() const override{
         wptr_complex<From,To>* retval = new wptr_complex<From,To>();
         *retval = *this;
         return retval;
    }

    /**
     * @todo write docs
     */
    virtual bool empty() const override{
        return to==nullptr||acc==nullptr;
    }

    /**
     * @todo write docs
     */
    virtual int getRefCount() const override{
        if(to==nullptr)return 0;
        return to->getRefCount();
    }

    /**
     * @todo write docs
     */
    awptr_managed<From>* getReferenced() const override{
        return to;
    }

    /**
     * @todo write docs
     */
    wptr_readable<wptr_accessor<From,To>>* getAccessor() const{
        return acc->duplicate();
    }

    /**
     * @todo write docs
     */
    void setAccessor(wptr_readable<wptr_accessor<From,To>>* acc_set){
        if(acc != nullptr) delete acc;
        acc = acc_set->duplicate();
    }

    /**
     * @todo write docs
     */
    template<typename ActualAccessorType>
    void setAccessor(wptr_base_readable<ActualAccessorType>* acc_set){
        if(acc != nullptr) delete acc;
        wptr_inheritance<ActualAccessorType,wptr_accessor<From,To>>* acc1_ptr = new wptr_inheritance<ActualAccessorType,wptr_accessor<From,To>>();
        *acc1_ptr=*acc_set;
        acc=acc1_ptr;
    }

    /**
     * @todo write docs
     */
    template<typename ActualAccessorType>
    void setAccessor(ActualAccessorType acc_set){
        if(acc != nullptr) delete acc;
        wptr_inheritance<ActualAccessorType,wptr_accessor<From,To>>* acc1_ptr = new wptr_inheritance<ActualAccessorType,wptr_accessor<From,To>>(acc_set);
        acc=acc1_ptr;
    }
};
#endif // WPTR_COMPLEX_H
