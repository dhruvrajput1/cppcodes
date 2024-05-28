#include<iostream>
using namespace std;

int ways(int n) {
    // base case
    if(n == 1) {
        return 2;
    } 
    if(n == 0) {
        return 1;
    }

    // recursive case
    return ways(n - 1) + ways(n - 2);
}

int main() {

    int n; cin>>n;

    cout<<ways(n)<<endl;

    return 0;
}