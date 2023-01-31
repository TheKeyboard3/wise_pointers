#ifndef WPTR_H
#define WPTR_H

#include "wptr_managed.h"
#include "awptr.h"
/**
 * @todo write docs
 */
template<typename T>
class wptr : awptr<T>
{
protected:
    wptr_managed<T>* to = nullptr;
public:
    /**
     * Empty constructor
     */
    wptr(){

    }

    /**
     * Default constructor
     */
    wptr(const T obj){
        to = new wptr_managed<T>(obj);
        if(to != nullptr)to->refc_inc();
    }

    /**
     * Copy constructor
     *
     * @param other TODO
     */
    wptr(const wptr& other){
        if(other.to!=nullptr)to = new wptr_managed<T>(*other.to);
        if(to != nullptr)to->refc_inc();
    }

    /**
     * Destructor
     */
    virtual ~wptr() override{
        if(to != nullptr)to->refc_dec();
    }

    /**
     * Assignment operator
     *
     * @param other TODO
     * @return TODO
     */
    virtual const wptr& operator=(const wptr& other){
        if(to != nullptr)to->refc_dec();
        to = other.to;
        if(to != nullptr)to->refc_inc();
        return other;
    }

    /**
     * @todo write docs
     *
     * @param other TODO
     * @return TODO
     */
    virtual bool operator==(const wptr& other) const{
        return to==other.to;
    }

    /**
     * @todo write docs
     *
     * @param other TODO
     * @return TODO
     */
    virtual bool operator==(const wptr_managed<T>* other) const{
        return to==other;
    }

    /**
     * @todo write docs
     *
     * @param other TODO
     * @return TODO
     */
    virtual bool operator!=(const wptr& other) const{
        return to!=other.to;
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
    wptr_managed<T>* getTo() const{
        return to;
    }
};
#endif // WPTR_H
