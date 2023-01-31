#ifndef WMPTR_H
#define WMPTR_H

#include "wptr_managed.h"
#include "awptr.h"
#include "wptr.h"

/**
 * @todo write docs
 */
template<typename T, typename M>
class wmptr : public awptr<M>
{
protected:
    wptr_managed<T>* to = nullptr;
    unsigned long offset = 0;
public:
    /**
     * Empty constructor
     */
    wmptr(){

    }

    /**
     * Default constructor
     */
    wmptr(const T obj, unsigned long ofs){
        to = new wptr_managed<T>(obj);
        if(to != nullptr)to->refc_inc();
        offset = ofs;
    }

    /**
     * Construct from an existing wptr
     */
    wmptr(const wptr<T>& obj, unsigned long ofs){
        to = obj.getTo();
        if(to != nullptr)to->refc_inc();
        offset = ofs;
    }

    /**
     * Copy constructor
     *
     * @param other TODO
     */
    wmptr(const wmptr& other){
        if(other.to!=nullptr)to = new wptr_managed<T>(*other.to);
        if(to != nullptr)to->refc_inc();
        offset = other.offset;
    }

    void setOffset(unsigned long ofs){
        offset = ofs;
    }

    void setObject(const wptr<T>& other){
        if(to!=nullptr)to->refc_dec();
        to = other.getTo();
        if(to!=nullptr)to->refc_inc();
    }

    /**
     * Destructor
     */
    virtual ~wmptr() override{
        if(to != nullptr)to->refc_dec();
    }

    /**
     * Assignment operator
     *
     * @param other TODO
     * @return TODO
     */
    const wmptr& operator=(const wmptr& other){
        if(to != nullptr)to->refc_dec();
        to = other.to;
        if(to != nullptr)to->refc_inc();
        offset = other.offset;
        return other;
    }

    /**
     * @todo write docs
     */
    virtual M& operator *() const override{
        char* tptr = (char*)(&(**to));
        M* mptr = (M*)(tptr+offset);
        return *mptr;
    }

    /**
     * @todo write docs
     */
    virtual M* operator ->() const override{
        char* tptr = (char*)(*to).operator->();
        M* mptr = (M*)(tptr+offset);
        return mptr;
    }

    /**
     * @todo write docs
     */
    virtual bool empty() const override{
        return to==nullptr;
    }

    /**
     * @todo write docs
     */
    virtual int getRefCount() const override {
        return to->getRefCount();
    }
};
#endif // WMPTR_H
