#include<iostream>

template<typename T>
class SharedPointer{
public:
    explicit SharedPointer(T* p = nullptr):ptr(p){
        if(ptr){
            refCount = new std::atomic<int>(1);
        }
    }
    ~SharedPointer(){
        release();
    }

   
private:
    T* ptr = nullptr;
    int *refCount = nullptr;

    void release(){
        if(refCount && --(*refCount)==0){
            delete ptr;
            delete refCount;
            ptr = nullptr;
            refCount = nullptr;
        }
    }
};

int main(){
    
    // std::shared_ptr<int> n(new int[10]);
    // n.get()[0] = 90;
    // n.get()[1] = 67;
    // std::cout<<*(n.get()+1)<<std::endl;
    return 0;
}