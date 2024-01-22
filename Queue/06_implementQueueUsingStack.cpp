#include<iostream>
#include<stack>
using namespace std;

class Queue {

    stack<int> s1;
    stack<int> s2;

public:

    void push(int data) {

        s1.push(data);

    }

    void pop() {

        while(s1.size() > 1) {
            s2.push(s1.top());
            s1.pop();
        }

        s1.pop();

        while(s2.size() > 0) {
            s1.push(s2.top());
            s2.pop();
        }

    }

    int front() {

        while(s1.size() > 1) {
            s2.push(s1.top());
            s1.pop();
        }

        int ans = s1.top();

        while(s2.size() > 0) {
            s1.push(s2.top());
            s2.pop();
        }

        return ans;

    }

    bool empty() {

        if(s1.size() == 0) {
            return true;
        }
        return false;

    }

    int size() {

        return s1.size();

    }

};

int main() {

    Queue q;

    for(int i = 0; i < 5; i++) {
        q.push(i+1);
    }

    cout<<q.front()<<endl;

    q.pop();

    cout<<q.size()<<endl;

    cout<<q.front()<<endl;



    return 0;
}