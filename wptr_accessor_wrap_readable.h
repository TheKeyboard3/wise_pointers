#ifndef WPTR_ACCESSOR_WRAP_READABLE_H
#define WPTR_ACCESSOR_WRAP_READABLE_H

/**
 * An abstract class that serves as an interface for reading the value of the resulting object of the accessor regardless of the base type
 */
template<typename T>
class wptr_accessor_wrap_readable
{
public:
    /**
     * Empty constructor
     */
    wptr_accessor_wrap_readable(){

    }

    /**
     * Destructor
     */
    virtual ~wptr_accessor_wrap_readable(){

    }

    /**
     * A function that returns the resulting object
     */
    virtual T* access() const = 0;

    /**
     * A function that returns true if the base object is not set
     * @return true if the base object is not set, false otherwise
     */
    virtual bool empty() const = 0;

    /**
     * A function that increases the amount of pointers that reference this object
     */
    virtual void refc_inc() = 0;

    /**
     * A function that decreases the amount of pointers that reference this object
     */
    virtual void refc_dec() = 0;

    /**
     * A function that returns the amount of pointers that reference this object
     * @return the value of the reference counter
     */
    virtual int getRefCount() const = 0;

    /**
     * A function that creates a copy of this object as an implementation of the interface for reading
     */
    virtual wptr_accessor_wrap_readable<T>* duplicate() const = 0;
};
#endif // WPTR_ACCESSOR_WRAP_READABLE_H
