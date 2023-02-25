#ifndef WPTR_NO_ACCESSOR_H
#define WPTR_NO_ACCESSOR_H

#include "wptr_accessor.h"

/**
 * @todo write docs
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
     */
    wptr_no_accessor(const wptr_no_accessor<T>& other){

    }

    /**
     * Destructor
     */
    virtual ~wptr_no_accessor(){

    }

    const wptr_no_accessor<T>& operator =(const wptr_no_accessor<T>& other){
        return other;
    }

    /**
     * @todo write docs
     */
    virtual T* access(T* from) const override{
        return from;
    }
};
#endif // WPTR_NO_ACCESSOR_H
