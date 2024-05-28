#include<iostream>
#include<vector>
using namespace std;

int maxCoins(vector<int>& nums, int i, int j, vector<vector<int>>& dp) {
    // base case
    if(i > j) {
        return 0;
    }
    if(dp[i][j] != -1) {
        return dp[i][j];
    }

    // recursive case
    int maxi = -1e9;
    for(int idx = i; idx <= j; idx++) {
        int cost = nums[i-1]*nums[idx]*nums[j+1] + maxCoins(nums, i, idx-1, dp)  + maxCoins(nums, idx+1, j, dp);
        maxi = max(maxi, cost);
    }

    return dp[i][j] = maxi;
}

int maxCoinsBottomUp(vector<int>& nums, int n) {
    vector<vector<int>> dp(n+2, vector<int>(n+2, 0));

    for(int i = n; i >= 1; i--) {
        for(int j = 1; j <= n; j++) {
            if(i > j) {
                continue;
            }
            int maxi = -1e9;
            for(int idx = i; idx <= j; idx++) {
                int cost = nums[i-1]*nums[idx]*nums[j+1] + dp[i][idx-1] + dp[idx+1][j];
                maxi = max(maxi, cost);
            }
            dp[i][j] = maxi;
        }
    }

    return dp[1][n];
}

int main() {

    vector<int> nums {3, 1, 5, 8};

    int n = nums.size();

    // insert 1 at the beginning and 1 at the end
    nums.insert(nums.begin(), 1);
    nums.push_back(1);

    vector<vector<int>> dp(n+1, vector<int>(n+1, -1));

    cout<<maxCoins(nums, 1, n, dp)<<endl;
    cout<<maxCoinsBottomUp(nums, n)<<endl;


    return 0;
}