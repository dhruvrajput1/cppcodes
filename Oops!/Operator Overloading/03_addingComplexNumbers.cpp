#include<iostream>
using namespace std;

class Complex {
    float real;
    float imag;

public:
    Complex() { // default constructor

    }

    Complex(float x, float y) { // constructor 2 --> if we are creating a parameterized constructor, then we must create default constructor
        real = x;
        imag = y;
    }

    Complex operator+(Complex C) { // the member function of C1 are accessed directly and C2 is passed as argument
        Complex temp;
        temp.real = real + C.real;
        temp.imag = imag + C.imag;

        return temp;
    }

    void display() {
        cout<<real<<" + "<<imag<<"i"<<endl;
    }

};

int main() {

    Complex c1, c2, c3;

    c1 = Complex(2.5, 3.5);
    c2 = Complex(1.6, 2.7);

    c3 = c1 + c2;

    c3.display();

    return 0;
}

