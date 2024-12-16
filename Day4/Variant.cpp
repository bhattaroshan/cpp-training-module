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
    Variant(const Variant& other){
        m_type = other.m_type;
        m_nRes = other.m_nRes;
        m_dRes = other.m_dRes;
        if(other.m_type==DataType::STRING && other.m_sRes ){
            m_sRes = new char[strlen(other.m_sRes)+1];
            strcpy(m_sRes,other.m_sRes);   
        }
    }

    Variant(int n):m_nRes(n),m_type(DataType::NUMBER){}
    Variant(double d):m_dRes(d),m_type(DataType::DOUBLE){}
    Variant(const char* s):m_type(DataType::STRING){
        m_sRes = new char[strlen(s)+1];
        strcpy(m_sRes,s);
    }

    Variant& operator=(const Variant& other){
        if(this==&other) return *this;
        m_nRes = other.m_nRes;
        m_dRes = other.m_dRes;
        if(m_sRes){
            delete[] m_sRes;
        }
        if(other.m_type==DataType::STRING && other.m_sRes ){
            m_sRes = new char[strlen(other.m_sRes)+1];
            strcpy(m_sRes,other.m_sRes);   
        }
        return *this;
    }

    DataType getType() const {
        return m_type;
    }

    int getNum() const {
        return m_nRes;
    }

    char* getString() const {
        return m_sRes;
    }

    double getDouble() const {
        return m_dRes;
    }

    ~Variant(){
        if(m_type==DataType::STRING){
            delete[] m_sRes;
        }
    }

private:
    int m_nRes;
    double m_dRes;
    char* m_sRes;
    DataType m_type = DataType::UNKNOWN;
};

struct Node{
    Variant v;
    Node *next;
    Node(const Variant v):v(v),next(nullptr){}
};

class VariantList{
public:
   
    void addVariant(Variant other){
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

    friend std::ostream& operator<<(std::ostream& os, VariantList& vl);
    Node* getHead() const {return head;}
    Node* getLast() const {return tail;}

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
    Node *tail = nullptr;
};

std::ostream& operator<<(std::ostream& os, VariantList& vl){
    Node *currNode = vl.getHead();
    while(currNode){
        if(currNode->v.getType()==DataType::NUMBER){
            os<<currNode->v.getNum();
        }else if(currNode->v.getType()==DataType::STRING){
            os<<currNode->v.getString();
        }else if(currNode->v.getType()==DataType::DOUBLE){
            os<<currNode->v.getDouble();
        }
        currNode = currNode->next;
        if(currNode){
            os<<", ";
        }
    }
    return os;
}

class Let{
public:
    Let(std::initializer_list<Variant> v){
    }

private:
    Variant *v;
};

int main(){
    VariantList vl;
    vl.addVariant(40);
    vl.addVariant("hello");
    vl.addVariant(67.89);
    vl.addVariant("testing");


    // int a[50]={1,2,3,4,5,6};




    std::cout<<vl<<std::endl;

    return 0;
}