#ifndef WPTR_ARR_MANAGER_H
#define WPTR_ARR_MANAGER_H
/**
 * @todo write docs
 */
//#include <iostream>
template<typename T>
class wptr_arr_manager
{
protected:
    T* managed_arr = nullptr;
    unsigned int size = 0;
public:
    /**
     * Empty constructor
     */
    wptr_arr_manager(){

    }

    /**
     * Default constructor
     */
    wptr_arr_manager(unsigned int s){
        size = s;
        managed_arr = new T[size];
    }

    /**
     * Copy constructor
     *
     * @param other TODO
     */
    wptr_arr_manager(const wptr_arr_manager<T>& other){
        //std::cout<<"copied at "<<this<<std::endl;
        size = other.size;
        managed_arr = new T[size];
        for(int i = 0; i < size; i++)managed_arr[i]=T(other.managed_arr[i]);
    }

    /**
     * Destructor
     */
    virtual ~wptr_arr_manager(){
        //std::cout<<"deleted at "<<this<<std::endl;
        delete managed_arr;
    }

    /**
     * @todo write docs
     */
    virtual unsigned int getSize(){
        return size;
    }

    /**
     * @todo write docs
     */
    virtual T& operator[] (unsigned int i){
        return managed_arr[i];
    }
};
#endif // WPTR_MANAGED_ARR_H
