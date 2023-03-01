#ifndef WPTR_NO_ACCESSOR_H
#define WPTR_NO_ACCESSOR_H

#include "wptr_accessor.h"

/**
 * The accessor that performs no transformation
 */
template<typename T>
class wptr_no_accessor : public wptr_accessor<T,T>
{
public:
    /**
     * Default constructor
     */
    wptr_no_accessor(){

    }

    /**
     * Copy constructor
     * @param other an existing object of the same class that is passed by const reference
     */
    wptr_no_accessor(const wptr_no_accessor<T>& other){

    }

    /**
     * Destructor
     */
    virtual ~wptr_no_accessor(){

    }

    /**
     * Assignment operator
     * @param other an existing object of the same class that is passed by const reference
     */
    const wptr_no_accessor<T>& operator =(const wptr_no_accessor<T>& other){
        return other;
    }

    /**
     * A function that performs the pointer transformation
     * @param from Is the pointer to the initial object
     * @return is the resulting pointer
     */
    virtual T* access(T* from) const override{
        return from;
    }
};
#endif // WPTR_NO_ACCESSOR_H
