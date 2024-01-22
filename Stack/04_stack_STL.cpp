#include<iostream>
#include<stack>
using namespace std;

int main() {

    stack<int> s;

    s.push(7);
    s.push(4);
    s.push(6);
    s.push(5);

    cout<<s.size()<<endl;

    while(!s.empty()) {
        cout<<s.top()<<" ";
        s.pop();
    }
    

    return 0;
}