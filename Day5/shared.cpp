#include<iostream>

template<typename T>
class SharedPointer{
public:

    SharedPointer():ptr(nullptr),refCount(nullptr){};

    SharedPointer(const SharedPointer& sp){
        ptr = sp.ptr;
        refCount = sp.refCount;
        (*refCount)++;
    }

    SharedPointer(T* p = nullptr):ptr(p){
        if(ptr){
            refCount = new int(1);
        }
    }

    ~SharedPointer(){
        release();
    }

    int use_count() const {
        return *refCount;
    }


private:
    T* ptr;
    int *refCount;

    void release(){
        if(refCount && --(*refCount) ==0){
            delete ptr;
            delete refCount;
            ptr = nullptr;
            refCount = nullptr;
        }
    }
};

int main(){

    // std::shared_ptr<int> sh(new int(45));
    // auto dh = sh;
    // std::shared_ptr<int> nn(new int(78));
    // dh = nn;
    // std::cout<<sh.use_count()<<std::endl;
    // std::cout<<nn.use_count()<<std::endl;


    
    // int a = 10;
    // auto abc = std::shared_ptr<
    SharedPointer<int> sp(new int(85));
    SharedPointer<int> tt = sp;
    
    // SharedPointer<int> dd;
    // std::cout<<tt.use_count()<<std::endl;

    return 0;
}