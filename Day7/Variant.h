
#ifndef VARIANT_H
#define VARIANT_H

enum class CDataType{
    UNKNOWN = -1,
    NUMBER,
    DOUBLE,
    STRING,
    BOOLEAN,
    ARRAY,
};


class Variant{
public:
    Variant(){}
    Variant(const Variant& other);
    Variant(int n);
    Variant(double d);
    Variant(const char* s);

    // friend std::ostream& operator<<(std::ostream& os, Variant& vl);
    Variant& operator=(const Variant& other);

    CDataType getType() const;
    int getNum() const;
    char* getString() const;
    double getDouble() const;
    ~Variant();

    int m_nRes;
    double m_dRes;
    char* m_sRes;
    bool m_bRes;
    CDataType m_type = CDataType::UNKNOWN;
};

struct Node{
    Variant v;
    Node *next;
    Node(const Variant v):v(v),next(nullptr){}
};


class VariantList{
public:
    ~VariantList();
    void addVariant(Variant other);
    Node* getHead() const;
    Node* getTail() const; 
    friend std::ostream& operator<<(std::ostream& os, VariantList& vl);
private:
    Node *head = nullptr;
    Node *tail = nullptr;
};

#endif