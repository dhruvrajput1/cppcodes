#include<iostream>
#include<vector>
using namespace std;

int LIS(vector<int> &arr, int i, int n, int prev, vector<vector<int>> &dp) {
    // base case
    if(i == n) return 0;

    if(dp[i][prev+1] != -1) return dp[i][prev+1]; // +1 because dp[i][-1] is invalid operation

    // recursive case
    int notTake = LIS(arr, i+1, n, prev, dp);
    int take = -1e8;
    if(prev == -1 or arr[prev] < arr[i]) {
        take = 1 + LIS(arr, i+1, n, i, dp);
    }

    return dp[i][prev+1] = max(notTake, take);
}

int lisBottomUp(vector<int> &arr, int n) {
    vector<vector<int>> dp (n+1, vector<int> (n+1, 0));

    for(int i = n-1; i >= 0; i--) {
        for(int prev = i-1; prev >= -1; prev--) {
            int notTake = dp[i+1][prev+1];
            int take = -1e8;
            if(prev == -1 or arr[i] > arr[prev]) {
                take = 1 + dp[i+1][i+1];
            }
            dp[i][prev+1] = max(take, notTake);
        }
    }

    return dp[0][-1+1];

}

// space optimization
int lisSpaceOpt(vector<int> &arr, int n) {

    vector<int> next(n+1, 0);
    vector<int> curr(n+1, 0);

    for(int i = n-1; i >= 0; i--) {
        for(int prev = i-1; prev >= -1; prev--) {
            int notTake = next[prev+1];
            int take = -1e8;
            if(prev == -1 or arr[i] > arr[prev]) {
                take = 1 + next[i+1];
            }
            curr[prev+1] = max(take, notTake);
        }
        next = curr;
    }

    return next[-1+1];

}

int lisSpecialMethod(vector<int> &arr, int n) {
    vector<int> dp(n, 1); // dp[i] signifies the length if LIS till index i

    int maxi = 0;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < i; j++) {
            if(arr[j] < arr[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
            maxi = max(maxi, dp[i]);
        }
    }

    return maxi;
}

int main() {

    vector<int> arr {10, 9, 2, 5, 3, 7, 101, 18};

    int n = arr.size();

    int prev = -1;

    vector<vector<int>> dp (n, vector<int> (n+1, -1));

    cout<<LIS(arr, 0, n, prev, dp)<<endl;
    cout<<lisBottomUp(arr, n)<<endl;
    cout<<lisSpaceOpt(arr, n)<<endl;
    cout<<lisSpecialMethod(arr, n)<<endl;

    return 0;
}