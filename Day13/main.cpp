#include<iostream>
#include<thread>

void helloFunc(){
    while(true){
        std::cout<<"Hello from func1\n";
    }
}

void helloFunc2(){
    while(true){
        std::cout<<"Hello from func2\n";
    }
}


int main(){
    std::thread t(helloFunc);
    std::thread t2(helloFunc2);
    t.detach();
    t2.detach();
    // t.join();
    // t2.join();
    std::cout<<"Hello there!\n";
    while(true){
        std::cout<<"Hello from main thread\n";
    }
    return 0;
}