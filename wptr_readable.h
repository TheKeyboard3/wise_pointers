#ifndef WPTR_READABLE_H
#define WPTR_READABLE_H

#include "wptr_agnostic.h"

/**
 * @todo write docs
 */
template<typename T>
class wptr_readable : public wptr_agnostic
{
public:
    /**
     * Destructor
     */
    virtual ~wptr_readable(){

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
    virtual wptr_readable<T>* duplicate() const = 0;
};
#endif // WPTR_READABLE_H
