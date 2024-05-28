#include<iostream>
using namespace std;

int fibo(int n, int dp[]) {
    // base case
    if(n == 0 or n == 1) {
        return n;
    }

    // recursive case
    if(dp[n] != 0) {
        return dp[n]; // stored value of fibo of n
    }

    int ans;

    ans = fibo(n-1, dp) + fibo(n-2, dp);
    dp[n] = ans;

    return ans;

}

// bottom up approach
int fiboBottomUp(int n) {
    int dp[100] = {0};

    dp[0] = 0;
    dp[1] = 1;

    for(int i = 2; i <= n; i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }

    return dp[n];
}

int main() {

    int n = 6;

    int dp[100] = {0};

    cout<<fibo(n, dp)<<endl;
    cout<<fiboBottomUp(n)<<endl;

    return 0;
}