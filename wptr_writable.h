#ifndef WPTR_WRITABLE_H
#define WPTR_WRITABLE_H

#include "wptr_agnostic.h"
#include "wptr_base_readable.h"
#include "awptr_managed.h"

/**
 * @todo write docs
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
     *
     * @param other TODO
     * @return TODO
     */
    virtual const wptr_base_readable<T>& operator=(const wptr_base_readable<T>& other) = 0;
};
#endif // WPTR_WRITABLE_H
