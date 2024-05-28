#include <iostream>
#include <stdexcept>
using namespace std;

const int MAX_SIZE = 100; // Maximum size of the stack

class Stack {
private:
    int top;             // Index of the top element
    int array[MAX_SIZE]; // Array to store elements

public:
    Stack() {
        top = -1; // Initialize the top index to -1 (empty stack)
    }

    // Function to check if the stack is empty
    bool isEmpty() {
        return top == -1;
    }

    // Function to push an element onto the stack
    void push(int value) {
        if (top >= MAX_SIZE - 1) {
            throw overflow_error("Stack is full");
        }
        array[++top] = value;
    }

    // Function to pop the top element from the stack
    void pop() {
        if (isEmpty()) {
            throw underflow_error("Stack is empty");
        }
        --top;
    }

    // Function to get the top element of the stack
    int topElement() {
        if (isEmpty()) {
            throw underflow_error("Stack is empty");
        }
        return array[top];
    }
};

int main() {
    Stack stack;

    // Push some elements onto the stack
    stack.pop();
    stack.push(10);
    stack.push(20);
    stack.push(30);

    // Print and pop elements from the stack
    while (!stack.isEmpty()) {
        cout << "Top element: " << stack.topElement() << endl;
        stack.pop();
    }

    return 0;
}
