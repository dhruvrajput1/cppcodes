#include<iostream>
#include<vector>
using namespace std;

int maxSum(vector<int> nums, int idx, vector<int> dp) {
    // base case
    if(idx == 0) {
        return nums[idx];
    }
    if(idx < 0) {
        return 0;
    }

    if(dp[idx] != -1) {
        return dp[idx];
    }

    // recursive case
    int pick = nums[idx] + maxSum(nums, idx-2, dp);
    int notPick = maxSum(nums, idx-1, dp);

    return dp[idx] = max(pick, notPick);
}

int maxSumBottomUp(vector<int> nums) {
    int n = nums.size();
    int dp[n];

    dp[0] = nums[0];
    dp[-1] = 0;

    for(int i = 1; i < n; i++) {
        int pick = nums[i] + dp[i-2];
        int notPick = dp[i-1];

        dp[i] = max(pick, notPick);
    }

    return dp[n-1];
}

// space optimization
int maxSumSpaceOpt(vector<int> nums) {

    int n = nums.size();

    int prev = nums[0];
    int prev2 = 0;

    for(int i = 1; i < n; i++) {
        int pick = nums[i] + prev2;
        int notPick = prev;

        int curr = max(pick, notPick);

        prev2 = prev;
        prev = curr;
    }

    return prev;
}

int main() {

    vector<int> nums{2, 1, 4, 9};

    int n = nums.size();

    vector<int> dp(n, -1);

    cout<<maxSum(nums, n-1, dp)<<endl;
    cout<<maxSumBottomUp(nums)<<endl;
    cout<<maxSumSpaceOpt(nums)<<endl;

    return 0;
}