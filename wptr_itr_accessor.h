#ifndef WPTR_ITR_ACCESSOR_H
#define WPTR_ITR_ACCESSOR_H

#include "wptr_accessor.h"

/**
 * @todo write docs
 */
template<typename From, typename IndexType, typename To>
class wptr_itr_accessor : public wptr_accessor<From,To>
{
protected:
    IndexType index;
public:

    /**
     * Default constructor
     */
    wptr_itr_accessor(){

    }

    /**
     * Default constructor
     */
    wptr_itr_accessor(const IndexType& ind){
        index = ind;
    }

    /**
     * Copy constructor
     */
    wptr_itr_accessor(const wptr_itr_accessor<From,IndexType,To>& other){
        index = other.index;
    }

    /**
     * Destructor
     */
    virtual ~wptr_itr_accessor(){

    }

    const wptr_itr_accessor<From,IndexType,To>& operator=(const wptr_itr_accessor<From,IndexType,To>& other){
        index = other.index;
        return other;
    }

    bool operator==(const wptr_itr_accessor<From,IndexType,To>& other) const{
        return index == other.index;
    }

    bool operator!=(const wptr_itr_accessor<From,IndexType,To>& other) const{
        return index != other.index;
    }

    /**
     * @todo write docs
     */
    virtual To* access(From* from) const override{
        To* mptr = &((*from)[index]);
        return mptr;
    }
};
#endif // WPTR_ITR_ACCESSOR_H
