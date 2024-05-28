#include<iostream>
#include<vector>
using namespace std;

int maxSumPartition(int i, int n, vector<int>& arr, int k, vector<int>& dp) {
    // base case
    if(i == n) {
        return 0;
    }
    if(dp[i] != -1) {
        return dp[i];
    }

    // recursive case
    int len = 0;
    int maxAns = -1e9;
    int maxi = -1e9;

    for(int j = i; j < min(n, i + k); j++) {
        len++;
        maxi = max(maxi, arr[j]); // to keep track of the maximum number in the partitioned subarray
        int sum = len*maxi + maxSumPartition(j+1, n, arr, k, dp);
        maxAns = max(maxAns, sum);
    }

    return dp[i] = maxAns;
}

int maxSumPartitionTabulation(vector<int>& arr, int k) {
    int n = arr.size();
    vector<int> dp(n+1, 0);

    // base case
    dp[n] = 0;

    for(int i = n-1; i >= 0; i--) {
        int len = 0;
        int maxAns = -1e9;
        int maxi = -1e9;
        for(int j = i; j < min(n, i + k); j++) {
            len++;
            maxi = max(maxi, arr[j]); // to keep track of the maximum number in the partitioned subarray
            int sum = len*maxi + dp[j+1];
            maxAns = max(maxAns, sum);
        }
        dp[i] = maxAns;
    }

    return dp[0];
}

int main() {

    vector<int> arr {1, 15, 7, 9, 2, 5, 10};
    int k = 3;

    int n = arr.size();

    vector<int> dp(n, -1);

    cout<<maxSumPartition(0, n, arr, k, dp)<<endl;
    cout<<maxSumPartitionTabulation(arr, k)<<endl;

    return 0;
}