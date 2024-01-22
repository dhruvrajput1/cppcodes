#include<iostream>
#include<list>
using namespace std;

int main(){

    list<int> l;
    
    l.push_back(2);
    l.push_back(4);
    l.push_back(15);
    l.push_front(14);
    l.push_back(9);
    l.push_back(11);

    l.pop_back();
    l.pop_front();

    cout<<l.front()<<endl;
    cout<<l.back()<<endl;
    cout<<*l.begin()<<endl; // gives address of first node 

    // print
    list<int> ::iterator itt;
    for(itt = l.begin(); itt != l.end(); itt++){
        cout<<*itt<<" ";
    }
    cout<<endl;

    list<int> :: iterator it;
    for(it = l.begin(); it != l.end(); it++) {
        cout<<*it<<" ";
    }
    


    return 0;
}