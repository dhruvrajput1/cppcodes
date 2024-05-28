#include<iostream>
#include<vector>
using namespace std;

int findWays(vector<int> &nums, int i, int sum, vector<vector<int>> &dp) {
    // base case
    
    if(i == 0) {
        if(sum == 0 and nums[0] == 0) {
            return 2;
        }
        if(sum == 0 or sum == nums[0]) {
            return 1;
        }

        return 0;
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

    if(nums[0] == 0) {
        dp[0][0] = 2; // means if nums[0] == 0 and sum == 0 and index is also == 0 then we have 2 ways
    }
    else {
        dp[0][0] = 1; // means if we are at index 0 and sum is == 0 and the nums[0] is not equal to 0, then we have only 1 case that is notTake
    }

    if(nums[0] != 0 and nums[0] <= sum) dp[0][nums[0]] = 1;

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

int countPartitions(int n, vector<int> &arr, int d) {
    int totalSum = 0;

    for(int i = 0; i < n; i++) totalSum += arr[i];

    if((totalSum - d) < 0 or (totalSum - d)%2) {
        return 0;
    }

    vector<vector<int>> dp(n, vector<int>((totalSum-d)/2+1, -1));

    return findWays(arr, n-1, (totalSum-d)/2, dp);

}

int main() {

    vector<int> arr {5, 2, 6, 4};

    int d = 3;

    int n = arr.size();

    cout<<countPartitions(n, arr, d)<<endl;

    return 0;
}