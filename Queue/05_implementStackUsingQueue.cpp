#include<iostream>
#include<queue>
using namespace std;

template<typename T>

class Stack {

    queue<T> q1, q2;

public:

    void push(T x) {
        q1.push(x);
    }

    void pop() {

        if(q1.empty()) {
            return ;
        }

        while(q1.size() > 1) {
            q2.push(q1.front());
            q1.pop();
        }
        q1.pop();

        swap(q1, q2);
    }

    T top() {

        while(q1.size() > 1) {
            T element = q1.front();
            q2.push(element);
            q1.pop();
        }

        T top = q1.front();
        q2.push(top);
        q1.pop();
        
        swap(q1, q2);

        return top;

    }

    int size() {
        return q1.size();
    }

    bool empty() {
        return size() == 0;
    }

};

int main() {

    Stack<int> s;

    s.push(1);
    s.push(2);
    s.push(3);

   
    while(!s.empty()) {
        cout<<s.top()<<endl;
        s.pop();
    }

    return 0;
}