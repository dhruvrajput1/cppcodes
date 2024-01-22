#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

int main() {

    unordered_map<string, vector<string>> phonebook;

    phonebook["Dhruv"].push_back("9711163256");
    phonebook["Dhruv"].push_back("8130881257");

    phonebook["Rahul"].push_back("9711163256");
    phonebook["Rahul"].push_back("8802082613");
    phonebook["Angela"].push_back("8130881257");
    phonebook["Rahul"].push_back("9810965109");

    for(auto p : phonebook) {
        cout<<p.first<<"-> ";
        for(auto x : p.second) {
            cout<<x<<", ";
        }
        cout<<endl;
    }

    return 0;
}