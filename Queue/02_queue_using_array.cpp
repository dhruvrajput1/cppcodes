#include<iostream>
using namespace std;

class queue {

    int* arr; // creating array dynamically
    int f;
    int e;
    int currSize;
    int n;
    
public:
    queue(int size) { // default constructor
        n = size;
        arr = new int[n];
        f = 0;
        e = n - 1;
        currSize = 0;
    }

    // push
    void push(int data) {

        if(currSize < n) {
            e = (e + 1)%n;

            arr[e] = data;
            currSize++;
        }
        else {
            cout<<"Queue is full"<<endl;
        }
       
    }

    // pop
    void pop() {

        if(currSize > 0) {
            f = (f + 1)%n;
            currSize--;
        }
        else {
            cout<<"queue is empty"<<endl;
        }
        
    }

    bool empty() {
        if(currSize == 0) {
            return true;
        }
        else {
            return false;
        }
    }

    int front() {
        return arr[f];
    }

    int size() {
        return currSize;
    }
   
};



int main() {

    queue q(5);

    q.push(4);
    q.push(1);
    q.push(6);
    q.push(5);
    q.push(9); 
    

    while(!q.empty()) {
        cout<<q.front()<<" ";
        q.pop();
    }


    return 0;
}