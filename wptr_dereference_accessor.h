#ifndef WPTR_DEREFERENCE_ACCESSOR_H
#define WPTR_DEREFERENCE_ACCESSOR_H

#include "wptr_accessor.h"

/**
 * @todo write docs
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
     */
    wptr_dereference_accessor(const wptr_dereference_accessor<From,To>& other){

    }

    /**
     * Destructor
     */
    virtual ~wptr_dereference_accessor(){

    }

    const wptr_dereference_accessor<From,To>& operator =(const wptr_dereference_accessor<From,To>& other){

    }

    /**
     * @todo write docs
     */
    virtual To* access(From* from) const override{
        To* mptr = &(**from);
        return mptr;
    }
};
#endif // WPTR_DEREFERENCE_ACCESSOR_H
