#include<iostream>
using namespace std;

class Human {
public:
    int height;
    int weight;
    int age;

    int getAge() {
        return age;
    }

    void setWeight(int w) {
        weight = w;
    }

};

class Male : public Human {
public:
    string color;

    void sleep() {
        cout<<"Male Sleeping"<<endl;
    }
};

int main() {

    Male m1;

    m1.age = 20;
    m1.height = 178;
    
    m1.setWeight(70);

    m1.color = "brown";

    cout<<m1.age<<endl;
    cout<<m1.height<<endl;
    cout<<m1.weight<<endl;
    cout<<m1.color<<endl;
    m1.sleep();



    return 0;
}