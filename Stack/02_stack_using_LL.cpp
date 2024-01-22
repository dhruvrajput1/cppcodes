#include<iostream>

using namespace std;

class node {
public:
    int data;
    node* next;

    // constructor
    // node(int d){
    //     data = d;
    //     next = NULL;
    // }
    node(int data){
        // data = data; // compiler will get confused b/w 2 data
        this->data = data; // compiler will get confused b/w 2 data that's why we use this->data
        next = NULL;
    }

};

class stack{

    node* head;
    int len;

public:

    stack(){
        head = NULL;
        len = 0;
    }

    // top
    int top(){
        return head->data; // head instead of tail, because we will insert data in front
    }
    

    // push
    void push(int data){

        // DMA
        // int* a = new int;

        node* n = new node(data); // DMA
        n->next = head; // we are doing insert at front
        head = n;
        len++;
    }

    // pop
    void pop(){ 
        // if LL doesnot exists
        if(head == NULL){
            return ;
        }

        // if only single node is present
        else if(head->next == NULL){
            delete head;
            head = NULL;
        }

        // if many nodes are there
        else{
            node* temp = head;
            head = head->next;
            delete temp;
            temp = NULL;
        }

        len--;

    }

    // size
    int size(){
        return len;
    }
    

    // empty
    bool empty() {
        if(head == NULL){
            return true;
        }
        return false;
    }
    
};

int main() {

    stack s;
    s.push(2);
    s.push(3);
    s.push(1);
    s.push(4);

    

    // cout<<s.top()<<endl;

    // s.pop();

    // cout<<s.top()<<endl;
    
    // printing all elements of stack
    while(!s.empty()) {
        cout<<s.top()<<" ";
        s.pop();
    }
    
   return 0;
}