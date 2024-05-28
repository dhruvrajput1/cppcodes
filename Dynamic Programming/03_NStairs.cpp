#include<iostream>
#include<vector>
using namespace std;

int totalWays(int idx, vector<int> &dp) {
    // base case
    if(idx == 0) {
        return 1;
    }
    if(idx == 1) {
        return 1;
    }

    if(dp[idx] != -1) {
        return dp[idx];
    }

    // recursive case
    int left = totalWays(idx-1, dp);
    int right = totalWays(idx-2, dp);

    return dp[idx] = left + right;
}

int totalWaysBottomUp(int n) {

    int dp[100] = {0};

    dp[0] = 1;
    dp[1] = 1;

    for(int i = 2; i <= n; i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }

    return dp[n];

}

// space optimized
int totalWaysSpaceOpt(int n) {
    int prev = 1;
    int prev2 = 1;

    for(int i = 2; i <= n; i++) {
        int curr = prev + prev2;
        prev2 = prev;
        prev = curr;
    }

    return prev;

}

int main() {

    int n = 5;

    vector<int> dp(n+1, -1);

    cout<<totalWays(n, dp)<<endl;
    cout<<totalWaysBottomUp(n)<<endl;
    cout<<totalWaysSpaceOpt(n)<<endl;


    return 0;
}


