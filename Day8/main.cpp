#include<iostream>
#include"logger.h"
#include"let.h"

int main(){

    Let a = 45.3;
    Let b = 56.7;

    ConsoleLogger logger;
    LoggingDecorator loggingLet1(a, logger);
    LoggingDecorator loggingLet2(b, logger);

    LoggingDecorator result = loggingLet1 + loggingLet2;
    std::cout<< result << std::endl; 
    return 0;
}