#ifndef WPTR_AGNOSTIC_H
#define WPTR_AGNOSTIC_H

/**
 * An abstract class that contains the functions of a wise_pointer that do not require the base type or the resulting type
 */
class wptr_agnostic
{
public:
    /**
     * Destructor
     */
    virtual ~wptr_agnostic(){

    }

    /**
     * A function that returns true if the base object or the accessor is not set
     * @return true if the base object otr the accessor is not set, false otherwise
     */
    virtual bool empty() const = 0;

    /**
     * A function that returns the amount of pointers that reference the same base object
     * @return the pointer count
     */
    virtual int getRefCount() const = 0;
};
#endif // WPTR_AGNOSTIC_H
