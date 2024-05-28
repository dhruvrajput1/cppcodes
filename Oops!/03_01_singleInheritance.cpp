#include<iostream>
using namespace std;

class Animal {
public:

    int age;
    int weight;

    void speak() {
        cout<<"Woof"<<endl;
    }

};

class Dog : public Animal {
public:
    void sayHello() {
        cout<<"Hello"<<endl;
    }
};


int main() {

    Dog d;

    d.speak();
    d.sayHello();

    return 0;
}