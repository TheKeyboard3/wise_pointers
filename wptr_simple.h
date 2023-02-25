#ifndef WPTR_SIMPLE_H
#define WPTR_SIMPLE_H

#include "wptr_managed.h"
#include "wptr_readable.h"
#include "wptr_writable.h"
#include "wptr_base_readable.h"

/**
 * @todo write docs
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
     * Default constructor
     */
    wptr_simple(const T& obj){
        to = new wptr_managed<T>(obj);
        if(to != nullptr)to->refc_inc();
    }

    /**
     * Copy constructor
     *
     * @param other TODO
     */
    wptr_simple(const wptr_simple<T>& other){
        if(other.to!=nullptr)to = new wptr_managed<T>(**other.to);
        if(to != nullptr)to->refc_inc();
    }

    /**
     * Copy constructor
     *
     * @param other TODO
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
     *
     * @param other TODO
     * @return TODO
     */
    const wptr_simple<T>& operator=(const wptr_simple<T>& other){
        if(to != nullptr)to->refc_dec();
        to = other.to;
        if(to != nullptr)to->refc_inc();
        return other;
    }

    /**
     * Assignment operator
     *
     * @param other TODO
     * @return TODO
     */
    virtual const wptr_base_readable<T>& operator=(const wptr_base_readable<T>& other) override{
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
    virtual bool operator==(const wptr_base_readable<T>& other) const override{
        return to==other.getReferenced();
    }

    /**
     * @todo write docs
     *
     * @param other TODO
     * @return TODO
     */
    virtual bool operator!=(const wptr_base_readable<T>& other) const override{
        return to!=other.getReferenced();
    }

    /**
     * @todo write docs
     */
    virtual T& operator *() const override{
        return **to;
    }

    /**
     * @todo write docs
     */
    virtual T* operator ->() const override{
        return (*to).operator->();
    }

    /**
     * @todo write docs
     */
    virtual wptr_readable<T>* duplicate() const override{
        wptr_simple<T>* retval = new wptr_simple<T>();
        *retval = *this;
        return retval;
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
        if(to==nullptr)return 0;
        return to->getRefCount();
    }

    /**
     * @todo write docs
     */
    awptr_managed<T> * getReferenced() const override{
        return to;
    }
};
#endif // WPTR_H
