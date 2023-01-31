#ifndef WARRPTR_MANAGED_H
#define WARRPTR_MANAGED_H
#include "awarrptr_managed.h"
/**
 * @todo write docs
 */
//#include <iostream>
template<typename T>
class warrptr_managed : public awarrptr_managed<T>
{
protected:
    T* managed_arr = nullptr;
    int refcount = 0;
    unsigned int s = 0;
public:
    /**
     * Default constructor
     */
    warrptr_managed(unsigned int size){
        //std::cout<<"created at "<<this<<std::endl;
        if(size!=0)managed_arr = new T[size];
        s=size;
    }

    /**
     * Copy constructor
     *
     * @param other TODO
     */
    warrptr_managed(const warrptr_managed& other){
        //std::cout<<"copied at "<<this<<std::endl;
        s=other.s;
        if(s!=0){
            managed_arr = new T[s];
            for(unsigned int i = 0; i < s; i++){
                managed_arr[i] = T(other.managed_arr[i]);
            }
        }
    }

    /**
     * Destructor
     */
    virtual ~warrptr_managed(){
        //std::cout<<"deleted at "<<this<<std::endl;
        if(managed_arr!=nullptr)delete managed_arr;
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
    virtual T& operator [](unsigned int i) override{
        return managed_arr[i];
    }

    /**
     * @todo write docs
     */
    virtual T* operator *() override{
        return managed_arr;
    }

    /**
     * @todo write docs
     */
    virtual int getRefCount() const override{
        return refcount;
    }

    /**
     * @todo write docs
     */
    virtual int getSize() const override{
        return s;
    }
};
#endif // WPTR_MANAGED_H
