#include<iostream>
#include<string.h>
using namespace std;

class String {
    char* p;
    int len;

public:
    String() {
        len = 0;
        p = NULL;
    }

    String(const char* s) {
        len = strlen(s);
        p = new char[len + 1]; // +1 for null at the end
        strcpy(p, s);
    }

    String(const String& s) { // copy constructor
        len = s.len;
        p = new char[len + 1]; // +1 for null at the end
        strcpy(p, s.p);
    }

    ~String() { // destructor
        delete p;
    }

    friend String operator+(const String& s, const String& t);

    friend int operator<=(const String &s, const String &t);

    friend void show(const String s);

};

// overloading + operator
String operator+(const String& s, const String& t) {
    String temp;
    temp.len = s.len + t.len;

    temp.p = new char[temp.len + 1]; // +1 for null at the end

    strcpy(temp.p, s.p);
    strcat(temp.p, t.p);

    return (temp);
}

// overloading <= operator
int operator<=(const String &s, const String &t) {
    int m = strlen(s.p);
    int n = strlen(t.p);

    if(m <= n) {
        return 1;
    }
    else {
        return 0;
    }
}

void show(const String s) {
    cout<<s.p<<endl;
}

int main() {

    String s1 = "New";
    String s2 = "York";
    String s3 = "Delhi";

    String t1, t2, t3;
    t1 = s1;
    t2 = s2;
    t3 = s1 + s3;

    cout<<"t1 = ";
    show(t1);
    cout<<endl;

    cout<<"t2 = ";
    show(t2);
    cout<<endl;

    cout<<"t3 = ";
    show(t3);
    cout<<endl;

    return 0;
}
