
#include<iostream>

enum class DataType{
    UNKNOWN = -1,
    NUMBER,
    DOUBLE,
    STRING,
    BOOLEAN,
};

class Let{
public:
    Let();
    Let(const Let&);
    Let(const bool&);
    Let(const int &n);
    Let(const double &d);
    Let(const char* s);

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

    ~Let();
private:
    int m_nRes;
    double m_dRes;
    bool m_bRes = false;
    char* m_sRes = nullptr;
    DataType m_type = DataType::UNKNOWN; 

    char* createNewString(const char*,const char*);
    int getIntegerCount(int) const;
    int getDoubleCount(double) const;
    int getStringCount(const char*) const;
};

typedef Let let;