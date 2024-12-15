#include<iostream>

enum class DataType{
    UNKNOWN = -1,
    NUMBER,
    DOUBLE,
    STRING,
    BOOLEAN,
};

class Variant{
public:
    Variant(){}
    Variant(int n):m_nRes(n),m_type(DataType::NUMBER){}
    Variant(double d):m_dRes(d),m_type(DataType::DOUBLE){}
    Variant(const char* s):m_type(DataType::STRING){
        m_sRes = new char[strlen(s)+1];
    }
    ~Variant(){
        if(m_type==DataType::STRING){
            delete[] m_sRes;
        }
    }
    int getNum(){return m_nRes;}
    void setNum(int n){m_nRes = n;}
private:
    int m_nRes;
    double m_dRes;
    char* m_sRes;
    DataType m_type = DataType::UNKNOWN;
};

struct Node{
    Variant v;
    Node *next;
};

class VariantList{
public:
    void insert(Variant v){
        Node *newNode = new Node;
        newNode->v.setNum(v.getNum());
        if(!head){
            head = newNode;
        }else{
            Node *temp = head;
            while(temp->next){
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
    ~VariantList(){
        Node *root = head;
        while(root){
            Node *temp = root;
            root = root->next;
            delete temp;
        }
    }
private:
    Node *head = nullptr;
};

class Let{
public:
    Let(std::initializer_list<Variant> v){

    }
};

int main(){
    // VariantList vl;
    // vl.insert("test");
    // vl.insert(45);

    Let a = {1,"hello",56.7};

    return 0;
}