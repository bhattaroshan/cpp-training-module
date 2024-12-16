#include<iostream>
using namespace std;

template<typename T>
struct Node{
    T data;
    Node *next;
};

template<typename T>
class LinkedList{
public:
    void insert(T data){
        Node<T> *node = new Node<T>;
        node->next = nullptr;
        node->data = data;
        if(!head){
            head = node;
            tail = head;
        }else{
            tail->next = node;
            tail = tail->next;
        }
    }

    void display(){
        Node<T> *temp = head;
        while(temp){
            std::cout<<temp->data<<std::endl;
            temp = temp->next;
        }
    }

    ~LinkedList(){
        Node<T> *temp = head;
        while(temp){
            Node<T> *t = temp->next;
            delete temp;
            temp = t;
        }
    }

    template<typename U>
    friend std::ostream& operator<<(ostream& os, const LinkedList<U>& ll);

private:
    Node<T> *head = nullptr;
    Node<T> *tail = nullptr;

};

template<typename T>
std::ostream& operator<<(ostream& os, const LinkedList<T>& ll){
    Node<T> *currNode = ll.head;
    while(currNode){
        os<<currNode->data;
        currNode = currNode->next;
        if(currNode){
            os<<", ";
        }
    }
    return os;
}


int main(){
    LinkedList<int> ll;

    ll.insert(1);
    ll.insert(3);
    ll.insert(4);
    ll.insert(5);
    ll.insert(6);
    std::cout<<ll<<std::endl;
    // ll.display();


    // ll.insert("hello");
    // ll.insert(34);
    // ll.insert(45.56);

    return 0;
}