#ifndef WPTR_ACCESSOR_WRAP_READABLE_H
#define WPTR_ACCESSOR_WRAP_READABLE_H

/**
 * @todo write docs
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
     * @todo write docs
     */
    virtual T* access() const = 0;

    /**
     * @todo write docs
     */
    virtual bool empty() const = 0;

        /**
     * @todo write docs
     */
    virtual void refc_inc() = 0;

    /**
     * @todo write docs
     */
    virtual void refc_dec() = 0;

    /**
     * @todo write docs
     */
    virtual int getRefCount() const = 0;

    /**
     * @todo write docs
     */
    virtual wptr_accessor_wrap_readable<T>* duplicate() const = 0;
};
#endif // WPTR_ACCESSOR_WRAP_READABLE_H
