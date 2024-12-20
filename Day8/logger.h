
#include<iostream>
#include "let.h"

class Logger {
public:
    virtual ~Logger() = default;
    virtual void log(const std::string& message) = 0;
};


class ConsoleLogger : public Logger {
public:
    void log(const std::string& message) override {
        std::cout << "[LOG]: " << message << std::endl;
    }
};

class LoggingDecorator {
public:
    LoggingDecorator(Let&, Logger&);
    LoggingDecorator operator+(const LoggingDecorator& other);
    char operator[](const int); 
    friend std::ostream& operator<<(std::ostream& os, LoggingDecorator& decorator);

private:
    Let& letInstance; 
    Logger& logger;   
};
