#include<iostream>
using namespace std;


int fibo(int n) {

    // base case
    if(n == 0 or n == 1) {
        return n;
    }

    // recursive case
    return fibo(n-1) + fibo(n-2);

}

int fiboTopDown(int n, int* arr) {  // is arr ka naam dp bhi rakh sakte hai
     // base case
    if(n == 0 or n == 1) {
        arr[n] = n; // return karne se pehle arr(memo) me store karna hai
        return n;
    }

    // calculate karne se pehle check karo arr(memo) me already calculated to nahi hai
    if(arr[n] != -1) {
        return arr[n];
    }

    // recursive case
    // return karne se pehle arr(memo) me store karna hai
    arr[n] = fiboTopDown(n-1, arr) + fiboTopDown(n-2, arr);
    return fiboTopDown(n-1, arr) + fiboTopDown(n-2, arr);
}

int fiboBottomUp(int n) {

    int* dp = new int[n];
    // top down base case is initializing condition here

    dp[0] = 0;
    dp[1] = 1;

    for(int i = 2; i <= n; i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }

    return dp[n];
     
}

int main() {

    int n; cin>>n;

    cout<<"Simple Recursion "<<fibo(n)<<endl;

    int *arr = new int[n + 1];

    for(int i = 0; i <= n; i++) {
        arr[i] = -1; 
    }

    // topdown

    cout<<"Dynamic Programming "<<fiboTopDown(n, arr)<<endl;


    // bottom up

    cout<<"Dynamic Programming bottom up "<<fiboBottomUp(n)<<endl;

    return 0;
}