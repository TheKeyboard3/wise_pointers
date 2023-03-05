#ifndef WPTR_MANAGED_H
#define WPTR_MANAGED_H

/**
 * An abstract class for a template that contains an object managed by wise_pointers
 */
template<typename T>
class wptr_managed
{
public:
    /**
     * Destructor
     */
    virtual ~wptr_managed(){

    }

    /**
     * A function that increases the amount of pointers that reference this object
     */
    virtual void refc_inc() = 0;

    /**
     * A function that decreases the amount of pointers that reference this object
     */
    virtual void refc_dec() = 0;

    /**
     * A function that returns a reference to the object contained by an object of this managed object
     * @return a reference to the object of the specified class, that is contained within this object
     */
    virtual T& operator *() = 0;

    /**
     * A function that returns a pointer to the object contained by an object of this managed object and provides access to its members
     * @return a pointer to the object of the specified class, that is contained within this object
     */
    virtual T* operator ->() = 0;
};
#endif // WPTR_MANAGED_H
