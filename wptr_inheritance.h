#ifndef WPTR_INH_H
#define WPTR_INH_H

#include "wptr_managed.h"
#include "wptr_readable.h"
#include "wptr_writable.h"
#include "wptr_inheritance_accessor.h"
#include "wptr_base_readable.h"

/**
 * @todo write docs
 */
template<typename Parent, typename Child>
class wptr_inheritance : virtual public wptr_writable<Parent>, virtual public wptr_readable<Child>, virtual public wptr_base_readable<Parent>
{
protected:
    awptr_managed<Parent>* to = nullptr;
    const wptr_inheritance_accessor<Parent,Child> acc;
public:
    /**
     * Empty constructor
     */
    wptr_inheritance(){

    }

    /**
     * Default constructor
     */
    wptr_inheritance(const Parent& obj){
        to = new wptr_managed<Parent>(obj);
        if(to != nullptr)to->refc_inc();
    }

    /**
     * Copy constructor
     *
     * @param other TODO
     */
    wptr_inheritance(const wptr_inheritance<Parent,Child>& other){
        if(other.to!=nullptr)to = new wptr_managed<Parent>(**other.to);
        if(to != nullptr)to->refc_inc();
    }

    /**
     * Copy constructor
     *
     * @param other TODO
     */
    wptr_inheritance(const wptr_base_readable<Parent>& other){
        if(other.getReferenced()!=nullptr)to = other.getReferenced();
        if(to != nullptr)to->refc_inc();
    }

    /**
     * Destructor
     */
    virtual ~wptr_inheritance() override{
        if(to != nullptr)to->refc_dec();
    }

    /**
     * Assignment operator
     *
     * @param other TODO
     * @return TODO
     */
    virtual const wptr_inheritance<Parent,Child>& operator=(const wptr_inheritance<Parent,Child>& other){
        if(to != nullptr)to->refc_dec();
        to = other.to;
        if(to != nullptr)to->refc_inc();
        return other;
    }

    /**
     * Assignment operator
     *
     * @param other TODO
     * @return TODO
     */
    virtual const wptr_base_readable<Parent>& operator=(const wptr_base_readable<Parent>& other) override{
        if(to != nullptr)to->refc_dec();
        to = other.getReferenced();
        if(to != nullptr)to->refc_inc();
        return other;
    }

    /**
     * @todo write docs
     *
     * @param other TODO
     * @return TODO
     */
    virtual bool operator==(const wptr_base_readable<Parent>& other) const override{
        return to==other.getReferenced();
    }

    /**
     * @todo write docs
     *
     * @param other TODO
     * @return TODO
     */
    virtual bool operator!=(const wptr_base_readable<Parent>& other) const override{
        return to!=other.getReferenced();
    }

    /**
     * @todo write docs
     *
     * @param other TODO
     * @return TODO
     */
    bool operator==(const wptr_inheritance<Parent,Child>& other) const{
        return to==other.to;
    }

    /**
     * @todo write docs
     *
     * @param other TODO
     * @return TODO
     */
    bool operator!=(const wptr_inheritance<Parent,Child>& other) const{
        return to!=other.to;
    }

    /**
     * @todo write docs
     */
    virtual Child& operator *() const override{
        return *acc.access((*to).operator->());
    }

    /**
     * @todo write docs
     */
    virtual Child* operator ->() const override{
        return acc.access((*to).operator->());
    }

    /**
     * @todo write docs
     */
    virtual wptr_readable<Child>* duplicate() const override{
         wptr_inheritance<Parent,Child>* retval = new wptr_inheritance<Parent,Child>();
         *retval = *this;
         return retval;
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
    virtual int getRefCount() const override{
        if(to==nullptr)return 0;
        return to->getRefCount();
    }

    /**
     * @todo write docs
     */
    awptr_managed<Parent> * getReferenced() const override{
        return to;
    }
};
#endif // WPTR_INH_H
