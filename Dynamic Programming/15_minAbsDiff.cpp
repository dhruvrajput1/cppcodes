#include<iostream>
#include<vector>
using namespace std;

int minSubsetSumDiff(vector<int> &arr, int n) {

    int totalSum = 0;

    for(int i = 0; i < n; i++) totalSum += arr[i];

    int k = totalSum;

    // code taken from subset sum code
    vector<vector<bool>> dp(n, vector<bool>(k+1, 0));

    for(int i = 0; i < n; i++) {
        dp[i][0] = true;
    }

    if(arr[0] <= k) dp[0][arr[0]] = true;

    for(int i = 1; i < n; i++) {
        for(int target = 1; target <= k; target++) {
            bool notTake = dp[i-1][target];
            bool take = false;
            if(target >= arr[i]) {
                take = dp[i-1][target-arr[i]];
            }

            dp[i][target] = take or notTake;
        }
    }
    // till here

    int mini = 1e9;

    for(int i = 0; i < totalSum/2; i++) {
        int s1 = i;
        int s2 = totalSum - s1;

        if(dp[n-1][s1] == true) { // in the last row of dp array, we are varying the col and checking if that particular subset sum is possible or not
            mini = min(mini, abs(s1-s2));
        }
    }

    return mini;

}

int main() {

    vector<int> arr {-36, 36};

    int n = arr.size();

    cout<<minSubsetSumDiff(arr, n)<<endl;

    return 0;
}