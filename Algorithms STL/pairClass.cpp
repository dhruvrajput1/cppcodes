#include<iostream>
using namespace std;

int main() {

    pair<int, char> p;

    p.first = 10;
    p.second = 'F';
    
    pair<int, char> p2(p); // create a pair p2 which is similar to p

    cout<<p2.first<<endl;
    cout<<p2.second<<endl;

    pair<int, string> p3 = make_pair(100, "Audi");

    cout<<p3.first<<" "<<p3.second<<endl;

    pair<pair<int, int>, string> car;

    car.second = "Baleno";
    car.first.first = 10;
    car.first.second = 20;

    return 0;
}