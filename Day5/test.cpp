#include <iostream>

template <typename _Tp>
class SharedPointer
{
public:
    SharedPointer(_Tp *ptr = nullptr) : res(ptr), counter(new int(1))
    {
        std::cout << "Called" << std::endl;
    }

    SharedPointer(const SharedPointer &sharePtr)
    {
        res = sharePtr.res;
        counter = sharePtr.counter;
        (*counter)++;
    }

    ~SharedPointer()
    {
        std::cout << "Destructor called " << std::endl;
        (*counter)--;
        if (*counter == 0)
        {
            delete res;
        }
    }

private:
    _Tp *res;
    int *counter;
};

int main()
{
    SharedPointer<int> sharePtr(new int(100));
    SharedPointer<int> dd;
    // SharedPointer<int> sharePtr_1 = sharePtr;
    // SharedPointer<int> sharePtr_2 = sharePtr;
    return 0;
}