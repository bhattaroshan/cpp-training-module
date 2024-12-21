#include<iostream>
#include"logger.h"
#include"let.h"

int main(){

    Let a = 20;
    Let b = 10;
    Let c = a+b;

    std::cout<<a<<" "<<b<<" "<<c<<std::endl;

    // ConsoleLogger logger;
    // LoggingDecorator loggingLet1(a, logger);
    // LoggingDecorator loggingLet2(b, logger);

    // LoggingDecorator result = loggingLet1 + loggingLet2;
    // std::cout<< result << std::endl; 
    return 0;
}