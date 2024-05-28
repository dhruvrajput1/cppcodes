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

};

class GermanShepherd : public Dog {

};

int main() {

    GermanShepherd g1;

    g1.speak();

    return 0;
}