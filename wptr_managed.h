#ifndef WPTR_MANAGED_H
#define WPTR_MANAGED_H
#include "awptr_managed.h"
/**
 * A template class that contains an object managed by wise_pointers
 */
template<typename T>
class wptr_managed : public awptr_managed<T>
{
protected:
    T managed_obj;
    unsigned int refcount = 0;
public:
    /**
     * A constructor that takes an object of the base class as an argument
     * @param obj an existing object of the base class that is passed by const reference
     */
    wptr_managed(const T& obj){
        managed_obj = T(obj);
    }

    /**
     * Copy constructor
     * @param other an existing object of the same type
     */
    wptr_managed(const wptr_managed& other){
        managed_obj = other.managed_obj;
    }

    /**
     * Destructor
     */
    virtual ~wptr_managed() override{

    }

    /**
     * A function that increases the amount of pointers that reference this object
     */
    virtual void refc_inc() override{
        refcount++;
    }

    /**
     * A function that decreases the amount of pointers that reference this object
     */
    virtual void refc_dec() override{
        refcount--;
        if(refcount <= 0) delete this;
    }

    /**
     * A function that returns a reference to the object contained by an object of this managed object
     * @return a reference to the object of the specified class, that is contained within this object
     */
    virtual T& operator *() override{
        return managed_obj;
    }

    /**
     * A function that returns a pointer to the object contained by an object of this managed object and provides access to its members
     * @return a pointer to the object of the specified class, that is contained within this object
     */
    virtual T* operator ->() override{
        return &managed_obj;
    }

    /**
     * A function that returns the amount of pointers that reference this object
     * @return the value of the reference counter
     */
    unsigned int getRefCount() const{
        return refcount;
    }
};
#endif // WPTR_MANAGED_H
