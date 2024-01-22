#include<iostream>
#include<stack>
using namespace std;

void insertAtBottom(stack<int> &s, int topElement) {
    // base case
    if(s.empty()) {
        s.push(topElement);
        return ;
    }

    // recursive case
    int data = s.top();
    s.pop();

    insertAtBottom(s, topElement);

    s.push(data);

}

void reverseStack(stack<int> &s) {
    // base case
    if(s.empty()) {
        return ;
    }

    // recursive case
    // pick the top element and insert it at the bottom of 'reversed small stack'
    int topElement = s.top();
    s.pop();

    // recursively reverse the smaller stack
    reverseStack(s);
    insertAtBottom(s, topElement);
}

int main() {

    stack<int> s;

    s.push(2);
    s.push(5);
    s.push(4);
    s.push(1);
    s.push(3);

    reverseStack(s);

    while(!s.empty()) {
        cout<<s.top()<<endl;
        s.pop();
    }

    return 0;
}