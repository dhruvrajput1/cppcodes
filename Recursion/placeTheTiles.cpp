#include<iostream>
using namespace std;

int ways(int n) {
    // base case
    if(n <= 3) {
        return 1;
    }

    // recursive case

    return ways(n - 1) + ways(n - 4);
}

int main() {
    // we're given a 4 x n wall

    int n = 4;

    cout<<ways(n)<<endl;

    return 0;
}