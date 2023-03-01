#ifndef WPTR_READABLE_H
#define WPTR_READABLE_H

#include "wptr_agnostic.h"

/**
 * An abstract class that contains functions of a wise_pointer that depend on the resulting type
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
     * A function that returns a reference to the resulting object
     * @return a reference to the resulting object
     */
    virtual T& operator *() const = 0;

    /**
     * A function that returns a pointer to the resulting object and provides access to its members
     * @return a pointer to the resulting object
     */
    virtual T* operator ->() const = 0;

    /**
     * A function that returns a copy of this pointer as an implementation of wptr_readable
     * @return a copy of this object as wptr_readable
     */
    virtual wptr_readable<T>* duplicate() const = 0;
};
#endif // WPTR_READABLE_H
