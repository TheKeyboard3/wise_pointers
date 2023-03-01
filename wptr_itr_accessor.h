#ifndef WPTR_ITR_ACCESSOR_H
#define WPTR_ITR_ACCESSOR_H

#include "wptr_accessor.h"

/**
 * An accessor that transforms a pointer to a iterable base object into a pointer to it`s member by using it`s index
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
        index = IndexType();
    }

    /**
     * A constructor that takes the index as an argument
     * @param ind an existing object of the index type that is passed by reference
     */
    wptr_itr_accessor(const IndexType& ind){
        index = ind;
    }

    /**
     * Copy constructor
     * @param other an existing object of the same type
     */
    wptr_itr_accessor(const wptr_itr_accessor<From,IndexType,To>& other){
        index = other.index;
    }

    /**
     * Destructor
     */
    virtual ~wptr_itr_accessor(){

    }

    /**
     * Assignment operator
     * @param other an existing object of the same type
     */
    const wptr_itr_accessor<From,IndexType,To>& operator=(const wptr_itr_accessor<From,IndexType,To>& other){
        index = other.index;
        return other;
    }

    /**
     * The equality operator that tests wether the index of this accessor and another accessor of the same class are the same
     * @param other an existing object of the same class that is passed by const reference
     * @return true if the index of this accessor and another accessor of the same class are the same, false otherwise
     */
    bool operator==(const wptr_itr_accessor<From,IndexType,To>& other) const{
        return index == other.index;
    }
    /**
     * The inequality operator that tests wether the index of this accessor and another accessor of the same class are the same
     * @param other an existing object of the same class that is passed by const reference
     * @return false if the index of this accessor and another accessor of the same class are the same, true otherwise
     */
    bool operator!=(const wptr_itr_accessor<From,IndexType,To>& other) const{
        return index != other.index;
    }

    /**
     * A function that performs the pointer transformation
     * @param from Is the pointer to the initial object
     * @return is the resulting pointer
     */
    virtual To* access(From* from) const override{
        To* mptr = &((*from)[index]);
        return mptr;
    }
};
#endif // WPTR_ITR_ACCESSOR_H
