#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int minEnergy(vector<int> &heights, int idx, vector<int> &dp) {
    // base case
    if(idx == 0) return 0;

    if(dp[idx] != -1) {
        return dp[idx];
    } 

    // recursive case
    int left = minEnergy(heights, idx-1, dp) + abs(heights[idx] - heights[idx-1]);
    int right = INT_MAX;

    if(idx > 1) {
        right = minEnergy(heights, idx-2, dp) + abs(heights[idx] - heights[idx-2]);
    }

    return dp[idx] =  min(left, right);
}

int minEnergyBottomUp(vector<int> &heights, int n) {
    int dp[n];

    dp[0] = 0;

    for(int i = 1; i <= n; i++) {
        int firstStep = dp[i-1] + abs(heights[i] - heights[i-1]);
        int lastStep = INT_MAX;
        if(i > 1) { 
            lastStep = dp[i-2] + abs(heights[i] - heights[i-2]);
        }

        dp[i] = min(firstStep, lastStep);
    }

    return dp[n];
}

// space optimized

int minWaysSpaceOpt(vector<int> &heights, int n) {
    int prev = 0;
    int prev2 = 0;

    for(int i = 1; i < n; i++) {
        int firstStep = prev + abs(heights[i] - heights[i-1]);
        int lastStep = INT_MAX;
        if(i > 1) { 
            lastStep = prev2 + abs(heights[i] - heights[i-2]);
        }

        int curr = min(firstStep, lastStep);
        prev2 = prev;
        prev = curr;
    }

    return prev;
}

int main() {

    vector<int> heights{30, 10, 60, 10, 60, 50};

    int n = heights.size();

    vector<int> dp(n+1, -1);

    cout<<minEnergy(heights, n-1, dp)<<endl;

    cout<<minEnergyBottomUp(heights, n-1)<<endl;

    cout<<minWaysSpaceOpt(heights, n)<<endl;

    return 0;
}