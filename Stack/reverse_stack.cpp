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
    int topOfStack = s.top();
    s.pop();
    
    insertAtBottom(s, topElement);

    s.push(topOfStack);
}

void reverseStack(stack<int> &s) {
    // base case
    if(s.empty()) {
        return ;
    }

    // recursive case
    int topElement = s.top();
    s.pop();

    reverseStack(s);

    insertAtBottom(s, topElement);

    
}

void printStack(stack<int> s) {

    while(!s.empty()) {
        cout<<s.top()<<endl;
        s.pop();
    }
   
}

int main() {

    stack<int> s;

    s.push(4);
    s.push(3);
    s.push(2);
    s.push(1);

    cout<<"Before reverse"<<endl;

    printStack(s);

    reverseStack(s);

    cout<<"After reverse"<<endl;

    printStack(s);

    return 0;
}