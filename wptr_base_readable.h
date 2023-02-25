#ifndef WPTR_BASE_READABLE_H
#define WPTR_BASE_READABLE_H

#include "wptr_agnostic.h"
#include "awptr_managed.h"

/**
 * @todo write docs
 */
template<typename T>
class wptr_base_readable : public wptr_agnostic
{
public:
    /**
     * Destructor
     */
    virtual ~wptr_base_readable(){

    }

    /**
     * @todo write docs
     *
     * @return TODO
     */
    virtual awptr_managed<T>* getReferenced() const = 0;

    /**
     * @todo write docs
     *
     * @param other TODO
     * @return TODO
     */
    virtual bool operator==(const wptr_base_readable<T>& other) const = 0;

    /**
     * @todo write docs
     *
     * @param other TODO
     * @return TODO
     */
    virtual bool operator!=(const wptr_base_readable<T>& other) const = 0;
};
#endif // WPTR_BASE_READABLE_H
