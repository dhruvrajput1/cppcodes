#include<iostream>
#include<string.h>
using namespace std;

class String {
    char* p;
    int len;

public:
    String() {

    }

    String(char* a) {
        len = strlen(a);
        p = new char[len + 1];
        strcpy(p, a);
    }

    void print() {
        cout<<p<<endl;
    }

};

int main() {
    char* a = "Dhruv Rajput";

    String s1;

    s1 = String(a); // converting the basic type to class type. basic type is char array and the class type is String
    s1.print();

    String s2;
    s2 = a;
    s2.print();
}