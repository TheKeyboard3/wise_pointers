#ifndef AWPTR_MANAGED_H
#define AWPTR_MANAGED_H

/**
 * An abstract class for a template that contains an object managed by a wise pointer
 */
template<typename T>
class awptr_managed
{
public:
    /**
     * Destructor
     */
    virtual ~awptr_managed(){
        //std::cout<<"deleted at "<<this<<std::endl;
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

    /**
     * A function that returns the amount of pointers that reference this object
     * @return the value of the reference counter
     */
    virtual int getRefCount() const = 0;
};
#endif // AWPTR_MANAGED_H
