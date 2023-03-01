#ifndef WPTR_INH_ACCESSOR_H
#define WPTR_INH_ACCESSOR_H

#include "wptr_accessor.h"

/**
 * An accessor that transforms a pointer to a base object of a descendant class and provides a pointer to it as to an object of its public parent class
 */
template<typename From, typename To>
class wptr_inheritance_accessor : public wptr_accessor<From,To>
{
public:
    /**
     * Default constructor
     */
    wptr_inheritance_accessor(){

    }

    /**
     * Copy constructor
     * @param other an existing object of the same class that is passed by const reference
     */
    wptr_inheritance_accessor(const wptr_inheritance_accessor<From,To>& other){

    }

    /**
     * Destructor
     */
    virtual ~wptr_inheritance_accessor(){

    }

    /**
     * Assignment operator
     * @param other an existing object of the same class that is passed by const reference
     */
    const wptr_inheritance_accessor& operator =(const wptr_inheritance_accessor<From,To>& other){
        return other;
    }

    /**
     * A function that performs the pointer transformation
     * @param from Is the pointer to the initial object
     * @return is the resulting pointer
     */
    virtual To* access(From* from) const override{
        To* mptr = from;
        return mptr;
    }
};
#endif // WPTR_INH_ACCESSOR_H
