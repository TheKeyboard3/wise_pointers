#ifndef WPTR_WRITABLE_H
#define WPTR_WRITABLE_H

#include "wptr_agnostic.h"
#include "wptr_base_readable.h"
#include "awptr_managed.h"

/**
 * An abstract template class that contains the function used to set the base object of a wise_pointer
 * It had to be separated from wptr_base_readable to allow for wptr_wrapped
 */
template<typename T>
class wptr_writable : public wptr_agnostic
{
public:
    /**
     * Destructor
     */
    virtual ~wptr_writable(){

    }

    /**
     * Assignment operator
     * @param other an implementaion of wptr_base_readable that is passed by const reference from which the opeerator takes the base object
     */
    virtual const wptr_base_readable<T>& operator=(const wptr_base_readable<T>& other) = 0;
};
#endif // WPTR_WRITABLE_H
