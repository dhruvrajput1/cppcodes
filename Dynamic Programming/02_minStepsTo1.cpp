#include<iostream>
#include<climits>
using namespace std;

int minWays(int n, int dp[]) {

    // base case
    if(n == 1) {
        return 0;
    }

    // recursive case

    // look up if n is already computed
    if(dp[n] != 0) {
        return dp[n];
    } 

    int ans;

    int op1, op2, op3 = INT_MAX;
    if(n%3 == 0) {
        op1 = minWays(n/3, dp);
    }
    if(n%2 == 0) {
        op2 = minWays(n/2, dp);
    }
    op3 = minWays(n-1, dp);

    ans = min(op1, min(op2, op3)) + 1;

    dp[n] = ans;

    return ans;
}


// bottom up approach
int minWaysBottomUp(int n) {
    int dp[100];

    dp[1] = 0;
    dp[2] = 1;
    dp[3] = 1;

    int op1, op2, op3 = INT_MAX;

    for(int i = 4; i <= n; i++) {
        if(i%3 == 0) {
            op1 = dp[i/3];
        }
        if(i%2 == 0) {
            op2 = dp[i/2];
        }
        op3 = dp[i-1];

        dp[i] = min(op1, min(op2, op3)) + 1;
    }

    return dp[n];
}


int main() {

    int n = 36; // return the minimum number of ways to reach 1

    int dp[100] = {0};

    cout<<minWays(n, dp)<<endl;

    cout<<minWaysBottomUp(n)<<endl;


    return 0;
}