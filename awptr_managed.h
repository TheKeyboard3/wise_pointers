#ifndef AWPTR_MANAGED_H
#define AWPTR_MANAGED_H

/**
 * @todo write docs
 */
//#include <iostream>
template<typename T>
class awptr_managed
{
public:
    /**
     * Destructor
     */
    virtual ~awptr_managed(){
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
    virtual T& operator *() = 0;

    /**
     * @todo write docs
     */
    virtual T* operator ->() = 0;

    /**
     * @todo write docs
     */
    virtual int getRefCount() const = 0;
};
#endif // AWPTR_MANAGED_H
