#include<iostream>
#include<vector>
using namespace std;

// code from prev code starts 
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

    return findWaysBottomUp(arr, (totalSum-d)/2);

}
// code from prev prob ends here

int main() {

    vector<int> arr {1, 2, 3, 1};

    int target = 3;

    int n = arr.size();

    cout<<countPartitions(n, arr, target)<<endl;


    return 0;
}