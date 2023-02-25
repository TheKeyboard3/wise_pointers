#ifndef WPTR_AGNOSTIC_H
#define WPTR_AGNOSTIC_H

/**
 * @todo write docs
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
     * @todo write docs
     */
    virtual bool empty() const = 0;

    /**
     * @todo write docs
     */
    virtual int getRefCount() const = 0;
};
#endif // WPTR_AGNOSTIC_H
