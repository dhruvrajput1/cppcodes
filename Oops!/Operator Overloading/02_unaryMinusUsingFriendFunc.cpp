#include<iostream>
using namespace std;

class space {
    int x, y, z;

public:
    void setData(int a, int b, int c) {
        x = a;
        y = b;
        z = c;
    }

    void display() {
        cout<<x<<" "<<y<<" "<<z<<endl;
    }

    friend void operator-(space &s);

};

void operator-(space &s) {
    s.x = -s.x;
    s.y = -s.y;
    s.z = -s.z;
}

int main() {

    space s;

    s.setData(10, -20, 30);

    cout<<"S : ";
    s.display();

    -s; // activates operator-() function

    cout<<"S : ";
    s.display();

    return 0;
}