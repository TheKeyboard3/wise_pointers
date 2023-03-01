#ifndef WPTR_OFFSET_ACCESSOR_H
#define WPTR_OFFSET_ACCESSOR_H

#include "wptr_accessor.h"

/**
 * The accessor that uses an offset of an object of the target type in the object of the base type to perform the transformation
 * The offset can be obtained by using the offsetof function
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
     * @param ofs the offset of the desired object in the base object in bytes
     */
    wptr_offset_accessor(unsigned long ofs){
        offset = ofs;
    }

    /**
     * Copy constructor
     * @param other an existing object of the same class that is passed by const reference
     */
    wptr_offset_accessor(const wptr_offset_accessor<From,To>& other){
        offset = other.offset;
    }

    /**
     * Destructor
     */
    virtual ~wptr_offset_accessor(){

    }

    /**
     * Assignment operator
     * @param other an existing object of the same class that is passed by const reference
     */
    const wptr_offset_accessor<From,To>& operator =(const wptr_offset_accessor<From,To>& other){
        offset = other.offset;
        return other;
    }

    /**
     * The equality operator that tests wether the offset of this accessor and another accessor of the same class are the same
     * @param other an existing object of the same class that is passed by const reference
     * @return true if the offset of this accessor and another accessor of the same class are the same, false otherwise
     */
    bool operator ==(const wptr_offset_accessor<From,To>& other) const{
        return offset == other.offset;
    }

    /**
     * The inequality operator that tests wether the offset of this accessor and another accessor of the same class are the same
     * @param other an existing object of the same class that is passed by const reference
     * @return true if the offset of this accessor and another accessor of the same class are the same, false otherwise
     */
    bool operator !=(const wptr_offset_accessor<From,To>& other) const{
        return offset != other.offset;
    }

    /**
     * A function that performs the pointer transformation
     * @param from Is the pointer to the initial object
     * @return is the resulting pointer
     */
    virtual To* access(From* from) const override{
        char* tptr = (char*)from;
        To* mptr = (To*)(tptr+offset);
        return mptr;
    }
};
#endif // WPTR_OFFSET_ACCESSOR_H
