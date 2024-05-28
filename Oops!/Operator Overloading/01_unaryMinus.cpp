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

    void operator - () { // overloading the minus operator, this will change the sign of data members
        x = -x;
        y = -y;
        z = -z;
    }

};

int main() {

    space s;


    s.setData(10, -20, 30);

    cout<<"S : ";
    s.display();

    -s; // activates operator-() function

    // s2 = -s1 will not work because operator-() function is not returning anything

    cout<<"S : ";
    s.display();

    return 0;
}