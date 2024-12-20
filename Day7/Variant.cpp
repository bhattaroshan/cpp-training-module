#include<iostream>
#include "Variant.h"

Variant::Variant(const Variant& other){
    m_type = other.m_type;
    m_nRes = other.m_nRes;
    m_dRes = other.m_dRes;
    if(other.m_type==CDataType::STRING && other.m_sRes ){
        m_sRes = new char[strlen(other.m_sRes)+1];
        strcpy(m_sRes,other.m_sRes);   
    }
}

Variant::Variant(int n):m_nRes(n),m_type(CDataType::NUMBER){}

Variant::Variant(double d):m_dRes(d),m_type(CDataType::DOUBLE){}

Variant::Variant(const char* s):m_type(CDataType::STRING){
    m_sRes = new char[strlen(s)+1];
    strcpy(m_sRes,s);
}

Variant& Variant::operator=(const Variant& other){
    if(this==&other) return *this;
    m_nRes = other.m_nRes;
    m_dRes = other.m_dRes;
    if(m_sRes){
        delete[] m_sRes;
    }
    if(other.m_type==CDataType::STRING && other.m_sRes ){
        m_sRes = new char[strlen(other.m_sRes)+1];
        strcpy(m_sRes,other.m_sRes);   
    }
    return *this;
}

CDataType Variant::getType() const {
    return m_type;
}

int Variant:: getNum() const {
    return m_nRes;
}

char* Variant:: getString() const {
    return m_sRes;
}

double Variant:: getDouble() const {
    return m_dRes;
}

Variant::~Variant(){
    if(m_type==CDataType::STRING){
        delete[] m_sRes;
    }
}

void VariantList:: addVariant(Variant other){
    Node *newNode = new Node(other);
    newNode->v = other;

    if(!head){
        head = newNode;
        tail = head;
    }else{
        tail->next = newNode;
        tail = tail->next;
    }
}

Node* VariantList::getHead() const {
    return head;
}

Node* VariantList::getTail() const {
    return tail;
}

std::ostream& operator<<(std::ostream& os, VariantList& vl);

VariantList::~VariantList(){
    Node *root = head;
    while(root){
        Node *temp = root;
        root = root->next;
        delete temp;
    }
}

std::ostream& operator<<(std::ostream& os, VariantList& vl){
Node *currNode = vl.getHead();
while(currNode){
    if(currNode->v.getType()==CDataType::NUMBER){
        os<<currNode->v.getNum();
    }else if(currNode->v.getType()==CDataType::STRING){
        os<<currNode->v.getString();
    }else if(currNode->v.getType()==CDataType::DOUBLE){
        os<<currNode->v.getDouble();
    }
    currNode = currNode->next;
    if(currNode){
        os<<", ";
    }
}
return os;
}
