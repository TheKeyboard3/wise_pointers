#ifndef WPTR_INH_ACCESSOR_H
#define WPTR_INH_ACCESSOR_H

#include "wptr_accessor.h"

/**
 * @todo write docs
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
     */
    wptr_inheritance_accessor(const wptr_inheritance_accessor<From,To>& other){

    }

    /**
     * Destructor
     */
    virtual ~wptr_inheritance_accessor(){

    }

    const wptr_inheritance_accessor& operator =(const wptr_inheritance_accessor<From,To>& other){
        return other;
    }

    /**
     * @todo write docs
     */
    virtual To* access(From* from) const override{
        To* mptr = from;
        return mptr;
    }
};
#endif // WPTR_INH_ACCESSOR_H
