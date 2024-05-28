#include<iostream>
using namespace std;

class Animal {
public:

    int age;
    int weight;

    void bark() {
        cout<<"Woof"<<endl;
    }

};

class Human {
public:

    string color;

    void speak() {
        cout<<"Hemlo World"<<endl;
    }
};

// multiple inheritance
class Hybrid : public Animal, public Human {

};

int main() {

    Hybrid h;

    h.bark();
    h.speak();

    return 0;
}