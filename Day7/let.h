

#ifndef LET_H
#define LET_H

#include<iostream>
#include"Variant.h"

// union DataType{

// };

// enum class CDataType{
//     UNKNOWN = -1,
//     NUMBER,
//     DOUBLE,
//     STRING,
//     BOOLEAN,
// };

class Let:public Variant{
public:
    // Let() = default;
    // Let(const Let&);
    // Let(const bool&);
    // Let(const int &n);
    // Let(const double &d);
    // Let(const char* s);
    // Let(std::initializer_list<Variant>&&);
    Let(Variant v);
    ~Let();

    //explicit conversions
    operator int() const;
    operator double() const;
    operator char*() const;
    operator bool() const;

    //methods
    int length() const;

    //operator overloading
    Let& operator=(const Let&);
    Let& operator+=(const Let&);
    //ostream overloading
    friend std::ostream& operator<<(std::ostream&, const Let&);


private:
    // int m_nRes;
    // double m_dRes;
    // bool m_bRes = false;
    // char* m_sRes = nullptr;
    // CDataType m_type = CDataType::UNKNOWN; 

    char* createNewString(const char*,const char*);
    int getIntegerCount(int) const;
    int getDoubleCount(double) const;
    int getStringCount(const char*) const;
};

typedef Let let;
typedef Let LET;

#endif