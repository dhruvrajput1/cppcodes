#include<iostream>
#include<vector>
using namespace std;

class Stack {

    vector<int> stack;
    vector<int> minStack;
    vector<int> maxStack;

public:

    void push(int data) {
        
        int currentMin = data;
        int currentMax = data;

        if(minStack.size() != 0) { // comparision between topmost element and the new data
            currentMin = min(minStack[minStack.size() - 1], data);
            currentMax = max(maxStack[maxStack.size() - 1], data);
        }

        minStack.push_back(currentMin);
        maxStack.push_back(currentMax);

        stack.push_back(data);

    }

    int top() {
        return stack[stack.size() - 1];
    }

    int getMin() {
        return minStack[minStack.size() - 1];
    }

    int getMax() {
        return maxStack[maxStack.size() - 1];
    }

    void pop() {
        minStack.pop_back();
        maxStack.pop_back();
        stack.pop_back();
    }

    bool empty() {
        return stack.size() == 0;
    }

};

int main() {

    Stack s;

    s.push(1);
    s.push(5);
    s.push(3);
    s.push(8);

    cout<<s.getMax()<<endl;
    cout<<s.getMin()<<endl;

    s.pop(); 

    cout<<s.getMax()<<endl;
    cout<<s.getMin()<<endl;



    return 0;
}