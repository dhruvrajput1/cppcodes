#include<iostream>
using namespace std;

class node {
public:
    int data;
    node* next;

    node(int d) {
        data = d;
        next = NULL;
    }

};

class Queue {

    node* head;
    node* tail;
    int len;
public:

    Queue() {
        head = NULL;
        tail = NULL;
        len = 0;
    }

    void push(int data) {
        node* n = new node(data);

        if(head == NULL) {
            head = n;
            tail = n;
        }
        else {
            tail->next = n;
            tail = n; 
        }   
        len++;
    }

    void pop() {
        if(head == NULL) {
            return ;
        }
        else if(head->next == NULL) {
            delete head;
            head = NULL;
            tail = NULL;
        }
        else {
            node* temp = head;
            head = head->next;
            delete temp;
            temp = NULL;
        }
        len--;
    }

    bool empty() {
        if(len == 0) {
            return true;
        }
        return false;
    }

    int front() {
        return head->data;
    }

    int size() {
        return len;
    }

};

int main() {

    Queue q;

    for(int i = 1; i <= 5; i++) {
        q.push(i++);
    }

    while(!q.empty()) {
        cout<<q.front()<<" ";
        q.pop();
    }

    return 0;
}