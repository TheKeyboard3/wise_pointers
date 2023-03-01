#ifndef WPTR_DEREFERENCE_ACCESSOR_H
#define WPTR_DEREFERENCE_ACCESSOR_H

#include "wptr_accessor.h"

/**
 * An accessor that dereferences the base type(calls the unary * operator) to perform the transformation
 */
template<typename From, typename To>
class wptr_dereference_accessor : public wptr_accessor<From,To>
{
public:
    /**
     * Default constructor
     */
    wptr_dereference_accessor(){

    }

    /**
     * Copy constructor
     * @param other an existing object of the same class that is passed by const reference
     */
    wptr_dereference_accessor(const wptr_dereference_accessor<From,To>& other){

    }

    /**
     * Destructor
     */
    virtual ~wptr_dereference_accessor(){

    }

   /**
     * Assignment operator
     * @param other an existing object of the same class that is passed by const reference
     */
    const wptr_dereference_accessor<From,To>& operator =(const wptr_dereference_accessor<From,To>& other){

    }

    /**
     * A function that performs the pointer transformation
     * @param from Is the pointer to the initial object
     * @return is the resulting pointer
     */
    virtual To* access(From* from) const override{
        To* mptr = &(**from);
        return mptr;
    }
};
#endif // WPTR_DEREFERENCE_ACCESSOR_H
