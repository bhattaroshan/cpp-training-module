
#include "./let.h"

Let::Let(){

}

Let::Let(const Let& var){
    m_type = var.m_type;
    switch(var.m_type){
        case DataType::NUMBER:
            m_nRes = var.m_nRes;
            break;
        case DataType::DOUBLE:
            m_dRes = var.m_dRes;
            break;
        case DataType::BOOLEAN:
            m_bRes = var.m_bRes;
            break;
        case DataType::STRING:
            m_sRes = createNewString(m_sRes,var.m_sRes);
            break;
        default:
            m_nRes = 0;
            m_dRes = 0;
            m_bRes = false;
            m_sRes = nullptr;
            break;
    }
}

Let::Let(const bool &b):m_type(DataType::BOOLEAN){
    m_bRes = b;
}

Let::Let(const int &n):m_type(DataType::NUMBER){
    m_nRes = n;
}

Let::Let(const double &d):m_type(DataType::DOUBLE){
    m_dRes = d;
}

Let::Let(const char* s):m_type(DataType::STRING){
    m_sRes = createNewString(m_sRes,s);
}

Let::operator int() const{
    return m_nRes;
}

Let::operator double() const{
    return m_dRes;
}

Let::operator char*() const{
    return m_sRes;
}

Let::operator bool() const{
    return m_bRes;
}

int Let::length() const {
    int len = 0;
    switch(m_type){
        case DataType::NUMBER:
            len = getIntegerCount(m_nRes);
            break;
        case DataType::DOUBLE:
            len = getDoubleCount(m_dRes);
            break;
        case DataType::BOOLEAN:
            len = 1;
            break;
        case DataType::STRING:
            len = getStringCount(m_sRes);
            break;
        default:
            len = 0;
            break;
    }

    return len;
}

Let& Let::operator=(const Let& other){
    if(this==&other){
        return *this;
    }

    if(m_sRes){
        delete m_sRes;
        m_sRes = nullptr;
    }

    m_type = other.m_type;

    switch(m_type){
        case DataType::NUMBER:
            m_nRes = other.m_nRes;
            break;
        case DataType::DOUBLE:
            m_dRes = other.m_dRes;
            break;
        case DataType::BOOLEAN:
            m_bRes = other.m_bRes;
            break;
        case DataType::STRING:
            m_sRes = createNewString(m_sRes,other.m_sRes);
            break;
        default:
            m_nRes = 0;
            m_dRes = 0.0;
            m_bRes = false;
            if(m_sRes) delete[] m_sRes;
            m_sRes = nullptr;
            break;
    }

    return *this;
}

Let& Let::operator+=(const Let& other){
    switch(m_type){
        case DataType::NUMBER:
            if(other.m_type==DataType::DOUBLE){
                m_type = DataType::DOUBLE;
                m_dRes = static_cast<double>(m_nRes)+other.m_dRes;
                m_nRes = 0;
            }else if(other.m_type==DataType::BOOLEAN){
                m_nRes += 1; 
            }
            break;
        case DataType::BOOLEAN:
            if(other.m_type==DataType::NUMBER){
                m_type = DataType::NUMBER;
                m_nRes = other.m_nRes + static_cast<int>(m_bRes);
            }else if(other.m_type==DataType::DOUBLE){
                m_type = DataType::DOUBLE;
                m_dRes = other.m_dRes + static_cast<double>(m_bRes);
            }
            break;
        default:
            break;
    }
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Let& var){
    switch(var.m_type){
        case DataType::NUMBER:
            os<<var.m_nRes;
            break;
        case DataType::DOUBLE:
            os<<var.m_dRes;
            break;
        case DataType::BOOLEAN:
            if(var.m_bRes)
                os<<"true";
            else
                os<<"false";
            break;
        case DataType::STRING:
            os<<var.m_sRes;
            break;
        default:
            os<<"Unknown Datatype Error";
    }
    
    return os;
}

Let::~Let(){
    if(m_sRes){
        delete[] m_sRes;
    }
}

//private methods

char* Let::createNewString(const char *source, const char* copyString){
    int sourceLen = 0;
    int copyLen = 0;
    if(source){
        sourceLen = strlen(source);
    }

    if(copyString){
        copyLen = strlen(copyString);
    }

    char *szTemp = new char[sourceLen + copyLen +1];
    strcpy(szTemp,"");

    if(source){
        strcat(szTemp,source);
        delete[] source;
    }
    if(copyString){
        strcat(szTemp, copyString);
    }

    return szTemp;
}

int Let::getIntegerCount(int n) const {
    int len = 0;
    while(n){
        ++len;
        n  /= 10;
    }
    return len;
}

int Let::getDoubleCount(double d) const {
    int len = 0;
    int intPart = static_cast<int>(d);
    int intLen = getIntegerCount(intPart);

    return intLen; //only sending length of decimal part
}

int Let::getStringCount(const char* s) const{
    return strlen(s);
}