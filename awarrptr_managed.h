#ifndef AWARRPTR_MANAGED_H
#define AWARRPTR_MANAGED_H

/**
 * @todo write docs
 */
//#include <iostream>
template<typename T>
class awarrptr_managed
{
public:
    /**
     * Destructor
     */
    virtual ~awarrptr_managed(){
        //std::cout<<"deleted at "<<this<<std::endl;
    }

    /**
     * @todo write docs
     */
    virtual void refc_inc() = 0;

    /**
     * @todo write docs
     */
    virtual void refc_dec() = 0;

    /**
     * @todo write docs
     */
    virtual T& operator [](unsigned int i) = 0;

    /**
     * @todo write docs
     */
    virtual T* operator *() = 0;

    /**
     * @todo write docs
     */
    virtual int getRefCount() const = 0;

    /**
     * @todo write docs
     */
    virtual int getSize() const = 0;
};
#endif // AWARRPTR_MANAGED_H
