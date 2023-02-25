#ifndef WPTR_ACCESSOR_H
#define WPTR_ACCESSOR_H

/**
 * @todo write docs
 */
template<typename From, typename To>
class wptr_accessor
{
public:
    /**
     * Destructor
     */
    virtual ~wptr_accessor(){

    }

    /**
     * @todo write docs
     */
    virtual To* access(From* from) const = 0;
};
#endif // WPTR_ACCESSOR_H
