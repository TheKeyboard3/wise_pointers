#ifndef WPTR_MANAGED_H
#define WPTR_MANAGED_H
#include "awptr_managed.h"
/**
 * @todo write docs
 */
//#include <iostream>
template<typename T>
class wptr_managed : public awptr_managed<T>
{
protected:
    T managed_obj;
    int refcount = 0;
public:
    /**
     * Default constructor
     */
    wptr_managed(const T obj){
        //std::cout<<"created at "<<this<<std::endl;
        managed_obj = obj;
    }

    /**
     * Copy constructor
     *
     * @param other TODO
     */
    wptr_managed(const wptr_managed& other){
        //std::cout<<"copied at "<<this<<std::endl;
        managed_obj = other.managed_obj;
    }

    /**
     * Destructor
     */
    virtual ~wptr_managed(){
        //std::cout<<"deleted at "<<this<<std::endl;
    }

    /**
     * @todo write docs
     */
    virtual void refc_inc() override{
        refcount++;
    }

    /**
     * @todo write docs
     */
    virtual void refc_dec() override{
        refcount--;
        if(refcount <= 0) delete this;
    }

    /**
     * @todo write docs
     */
    virtual T& operator *() override{
        return managed_obj;
    }

    /**
     * @todo write docs
     */
    virtual T* operator ->() override{
        return &managed_obj;
    }

    virtual int getRefCount() const override{
        return refcount;
    }
};
#endif // WPTR_MANAGED_H
