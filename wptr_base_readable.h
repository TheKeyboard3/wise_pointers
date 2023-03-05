#ifndef WPTR_BASE_READABLE_H
#define WPTR_BASE_READABLE_H

#include "wptr_agnostic.h"
#include "wptr_managed.h"

/**
 * An abstract class that contains functions of a wise_pointer that depend on the base type
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
     * A function that returns a pointer to the base object
     * @return a pointer to the base object
     */
    virtual wptr_managed<T>* getReferenced() const = 0;

    /**
     * The equality operator that tests wether the base objects of this pointer, and an implementation of wptr_base_readable are the same
     * @param other an implementation of wptr_base_readable that is passed by const reference
     * @return true if the base objects of this pointer and an implementation of wptr_base_readable are the same, false otherwise
     */
    virtual bool operator==(const wptr_base_readable<T>& other) const = 0;

    /**
     * The inequality operator that tests wether the base objects of this pointer, and an implementation of wptr_base_readable are the same
     * @param other an implementation of wptr_base_readable that is passed by const reference
     * @return false if the base objects of this pointer and an implementation of wptr_base_readable are the same, true otherwise
     */
    virtual bool operator!=(const wptr_base_readable<T>& other) const = 0;
};
#endif // WPTR_BASE_READABLE_H
