#ifndef WPTR_ITR_H
#define WPTR_ITR_H

#include "wptr_managed.h"
#include "wptr_readable.h"
#include "wptr_writable.h"
#include "wptr_itr_accessor.h"
#include "wptr_simple.h"
#include "wptr_base_readable.h"

/**
 * @todo write docs
 */
template<typename Parent, typename IndexType, typename Child>
class wptr_itr : virtual public wptr_readable<Child>, virtual public wptr_writable<Parent>, virtual public wptr_base_readable<Parent>
{
protected:
    awptr_managed<Parent>* to = nullptr;
    wptr_simple<wptr_itr_accessor<Parent, IndexType,Child>> acc;
public:
    /**
     * Empty constructor
     */
    wptr_itr(){
        to = nullptr;
    }

    /**
     * Default constructor
     */
    wptr_itr(const IndexType& ind){
        to = nullptr;
        acc = wptr_simple<wptr_itr_accessor<Parent, IndexType,Child>>(wptr_itr_accessor<Parent, IndexType,Child>(ind));
    }

    /**
     * Default constructor
     */
    wptr_itr(const Parent obj, const IndexType& ind){
        to = new wptr_managed<Parent>(obj);
        if(to != nullptr)to->refc_inc();
        acc = wptr_simple<wptr_itr_accessor<Parent, IndexType,Child>>(wptr_itr_accessor<Parent, IndexType,Child>(ind));
    }

    /**
     * Copy constructor
     *
     * @param other TODO
     */
    wptr_itr(const wptr_itr<Parent,IndexType,Child>& other){
        if(other.getReferenced()!=nullptr)to = new wptr_managed<Parent>(**other.getReferenced());
        if(to != nullptr)to->refc_inc();
        acc = wptr_simple<wptr_itr_accessor<Parent, IndexType,Child>>(wptr_itr_accessor<Parent, IndexType,Child>(*other.acc));
    }

    /**
     * Copy constructor
     *
     * @param other TODO
     */
    wptr_itr(const wptr_base_readable<Parent>& other,  const IndexType& ind){
        if(other.getReferenced()!=nullptr)to = other.getReferenced();
        if(to != nullptr)to->refc_inc();
        acc = wptr_simple<wptr_itr_accessor<Parent, IndexType,Child>>(wptr_itr_accessor<Parent, IndexType,Child>(ind));
    }

    /**
     * Destructor
     */
    virtual ~wptr_itr() override{
        if(to != nullptr)to->refc_dec();
    }

    /**
     * Assignment operator
     *
     * @param other TODO
     * @return TODO
     */
    const wptr_itr<Parent,IndexType,Child>& operator=(const wptr_itr<Parent,IndexType,Child>& other){
        if(to != nullptr)to->refc_dec();
        to = other.getReferenced();
        if(to != nullptr)to->refc_inc();
        acc = wptr_simple<wptr_itr_accessor<Parent, IndexType,Child>>(wptr_itr_accessor<Parent, IndexType,Child>(*other.acc));
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
    bool operator==(const wptr_itr<Parent,IndexType,Child>& other) const{
        if(*acc!=*other.acc)return false;
        return to==other.to;
    }

    /**
     * @todo write docs
     *
     * @param other TODO
     * @return TODO
     */
    bool operator!=(const wptr_itr<Parent,IndexType,Child>& other) const{
        if(*acc!=*other.acc)return true;
        return to!=other.to;
    }

    /**
     * @todo write docs
     */
    virtual Child& operator *() const override{
        return *acc->access((*to).operator->());
    }

    /**
     * @todo write docs
     */
    virtual Child* operator ->() const override{
        return acc->access((*to).operator->());
    }

    /**
     * @todo write docs
     */
    virtual wptr_readable<Child>* duplicate() const override{
        wptr_itr<Parent,IndexType,Child>* retval = new wptr_itr<Parent,IndexType,Child>();
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
#endif // WPTR_ITR_H
