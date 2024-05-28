#include<iostream>
#include<vector>
using namespace std;

int findWays(vector<int> &nums, int i, int sum, vector<vector<int>> &dp) {
    // base case
    if(sum == 0) {
        return 1;
    }
    if(i == 0) {
        if(nums[0] == sum) {
            return 1;
        }
        else {
            return 0;
        }
    }

    if(dp[i][sum] != -1) {
        return dp[i][sum];
    }

    // recursive case
    int notTake = findWays(nums, i-1, sum, dp);
    int take = 0;
    if(nums[i] <= sum) {
        take = findWays(nums, i-1, sum-nums[i], dp);
    }

    return dp[i][sum] = take + notTake;
}

int findWaysBottomUp(vector<int> &nums, int sum) {
    int n = nums.size();

    vector<vector<int>> dp(n, vector<int>(sum+1, 0));

    for(int i = 0; i < n; i++) {
        dp[i][0] = 1;
    }

    if(nums[0] <= sum) dp[0][nums[0]] = 1;

    for(int i = 1; i < n; i++) {
        for(int s = 0; s <= sum; s++) {
            int notTake = dp[i-1][s];
            int take = 0;
            if(nums[i] <= s) {
                take = dp[i-1][s-nums[i]];
            }   

            dp[i][s] = take + notTake;
        }
    }

    return dp[n-1][sum];

} 

// space optimization
int findWaysSpaceOpt(vector<int> &nums, int sum) {

    int n = nums.size();

    vector<int> prev(sum+1, 0);
    vector<int> curr(sum+1, 0);

    prev[0] = 1;
    curr[0] = 1;

    if(nums[0] <= sum) {
        prev[nums[0]] = 1;
    }

    for(int i = 1; i < n; i++) {
        for(int s = 0; s <= sum; s++) {
            int notTake = prev[s];
            int take = 0;
            if(nums[i] <= s) {
                take = prev[s-nums[i]];
            }   

            curr[s] = take + notTake;
        }
        prev = curr;
    }

    return prev[sum];
}

int main() {

    vector<int> nums {1, 2, 1, 2, 1};

    int sum = 3;

    int n = nums.size();

    vector<vector<int>> dp(n, vector<int>(sum+1, -1));

    cout<<findWays(nums, n-1, sum, dp)<<endl;
    cout<<findWaysBottomUp(nums, sum)<<endl;
    cout<<findWaysSpaceOpt(nums, sum)<<endl;

    return 0;
}