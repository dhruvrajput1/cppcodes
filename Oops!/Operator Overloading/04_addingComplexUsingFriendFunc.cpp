#include<iostream>
using namespace std;

class Complex {
    float real;
    float imag;

public:
    Complex() { // default constructor

    }

    Complex(float x, float y) { // constructor 2
        real = x;
        imag = y;
    }

    void display() {
        cout<<real<<" + "<<imag<<"i"<<endl;
    }

    friend Complex operator+(Complex c1, Complex c2);

};

Complex operator+(Complex c1, Complex c2) {
    Complex temp;
    temp.real = c1.real + c2.real;
    temp.imag = c1.imag + c2.imag;

    return temp;
}

int main() {

    Complex c1, c2, c3;

    c1 = Complex(2.5, 3.5);
    c2 = Complex(1.6, 2.7);

    c3 = c1 + c2;
    // c3 = operator+(c1, c2); // same as above

    c3.display();

    return 0;
}