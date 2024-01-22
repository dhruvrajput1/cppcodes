#include<iostream>
#include<stack>
using namespace std;

void transfer(stack<int> &s1, stack<int> &s2, int n) {
    for(int i = 0; i < n; i++) {
        s2.push(s1.top());
        s1.pop();
    }
}

void reverse(stack<int> &s1) {
    
    stack<int> s2;

    int n = s1.size();

    for(int i = 0; i < n; i++) {
        // pick the element at the top and insert it at the bottom
        int topElement = s1.top();
        s1.pop();

        // transfer n - i - 1 (remaining) elements from stack s1 to stack s2
        transfer(s1, s2, n - i - 1);

        // insert the element topElement in s1
        s1.push(topElement);

        // transfer n - i - 1 (remaining) elements from stack s2 to stack s1
        transfer(s2, s1, n - i - 1);
    }


}

void printStack(stack<int> s) {
    while(!s.empty()) {
        cout<<s.top()<<endl;
        s.pop();
    }
    cout<<endl;
}

int main() {

    stack<int> s;
    s.push(2);
    s.push(5);
    s.push(1);
    s.push(7);

    cout<<"Before reverse"<<endl;

    printStack(s);

    reverse(s);

    cout<<"After reverse"<<endl;

    printStack(s);

    return 0;
}