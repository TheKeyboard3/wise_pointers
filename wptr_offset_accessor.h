#ifndef WPTR_OFFSET_ACCESSOR_H
#define WPTR_OFFSET_ACCESSOR_H

#include "wptr_accessor.h"

/**
 * @todo write docs
 */
template<typename From, typename To>
class wptr_offset_accessor : public wptr_accessor<From,To>
{
protected:
    unsigned long int offset = 0;
public:
    /**
     * Empty constructor
     */
    wptr_offset_accessor(){

    }

    /**
     * Default constructor
     */
    wptr_offset_accessor(unsigned long ofs){
        offset = ofs;
    }

    /**
     * Copy constructor
     */
    wptr_offset_accessor(const wptr_offset_accessor<From,To>& other){
        offset = other.offset;
    }

    /**
     * Destructor
     */
    virtual ~wptr_offset_accessor(){

    }

    const wptr_offset_accessor<From,To>& operator =(const wptr_offset_accessor<From,To>& other){
        offset = other.offset;
        return other;
    }

    bool operator ==(const wptr_offset_accessor<From,To>& other) const{
        return offset == other.offset;
    }

    bool operator !=(const wptr_offset_accessor<From,To>& other) const{
        return offset != other.offset;
    }

    /**
     * @todo write docs
     */
    virtual To* access(From* from) const override{
        char* tptr = (char*)from;
        To* mptr = (To*)(tptr+offset);
        return mptr;
    }
};
#endif // WPTR_OFFSET_ACCESSOR_H
