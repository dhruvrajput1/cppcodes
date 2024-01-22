#include<iostream>
#include<unordered_map>
using namespace std;

class Student {
public:

    string firstName;
    string lastName;
    string rollNo;

    Student(string f, string l, string no) {
        firstName = f;
        lastName = l;
        rollNo = no;
    }

    bool operator == (const Student& s) const{
        return rollNo == s.rollNo;
    }

};

class HashFunction {
public:

    size_t operator() (const Student &s) const{ // size_t is unsigned int datatype, represent size in byte
        return s.firstName.size() + s.lastName.size();
    }

};

int main() {

    unordered_map<Student, int, HashFunction> studentMap;

    Student s1("Prateek", "Narang", "010");
    Student s2("Rahul", "Kumar", "023");
    Student s3("Prateek", "Gupta", "030");
    Student s4("Rahul", "Kumar", "120");

    // add student - marks to hashmap

    studentMap[s1] = 100;
    studentMap[s2] = 120;
    studentMap[s3] = 11;
    studentMap[s4] = 45;

    // find the marks of student s3
    cout<<studentMap[s3]<<endl;

    // iterating over all students
    for(auto s : studentMap) { // s is a pair
        cout<<s.first.firstName<<" "<<s.first.rollNo<<" "<<s.second<<endl;
    }


    return 0;
}