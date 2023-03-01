#ifndef WPTR_ACCESSOR_H
#define WPTR_ACCESSOR_H

/**
 * An abstract template class that transforms a poitner to an object into a pointer to another object,
 * that is presumably (althou not necessarily) contained within it
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
     * A function that performs the pointer transformation
     * @param from Is the pointer to the initial object
     * @return is the resulting pointer
     */
    virtual To* access(From* from) const = 0;
};
#endif // WPTR_ACCESSOR_H
