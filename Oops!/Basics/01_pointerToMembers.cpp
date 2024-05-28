#include<iostream>
using namespace std;

class M {
    int x, y;

public:

    void set(int a, int b) {
        x = a;
        y = b;
    }

    friend int sum(M m);

};

int sum(M m) { // it will need a friend function as it is accessing private members of class M
    int M :: *ptr = &M :: x; // pointer pointing to x
    int M :: *ptr2 = &M :: y; // ptr2 pointing to y

    int s = m.*ptr + m.*ptr2; // derefering the pointer

    return s;
}

int main() {

    M obj;

    obj.set(1, 2);

    cout<<sum(obj)<<endl;


    return 0;
}