#ifndef WPTR_ARR_MANAGER_H
#define WPTR_ARR_MANAGER_H
/**
 * A template class that adapts arrays to work with wise_pointers
 */
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
     * A constructor that takes the array size as its argument
     * @param s the size of the array
     */
    wptr_arr_manager(unsigned int s){
        size = s;
        managed_arr = new T[size];
    }

    /**
     * Copy constructor
     *
     * @param other an existing array manager of the same type that is passed as a constant reference
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
     * A function that returns the size of the array
     * @return the size of the array
     */
    virtual unsigned int getSize(){
        return size;
    }

    /**
     * A function that returns a reference to an element of the array
     * @param i index of the element
     * @return a reference to an element of the array
     */
    virtual T& operator[] (unsigned int i){
        return managed_arr[i];
    }
};
#endif // WPTR_MANAGED_ARR_H
