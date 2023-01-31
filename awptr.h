#ifndef AWPTR_H
#define AWPTR_H

#include "wptr_managed.h"

/**
 * @todo write docs
 */
template<typename T>
class awptr
{
public:
    /**
     * Destructor
     */
    virtual ~awptr(){

    }

    /**
     * @todo write docs
     */
    virtual T& operator *() const = 0;

    /**
     * @todo write docs
     */
    virtual T* operator ->() const = 0;

    /**
     * @todo write docs
     */
    virtual bool empty() const = 0;

    /**
     * @todo write docs
     */
    virtual int getRefCount() const = 0;
};
#endif // AWPTR_H
