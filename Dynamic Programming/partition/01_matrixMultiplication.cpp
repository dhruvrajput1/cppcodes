#include<iostream>
#include<vector>
using namespace std;

int matrixMultiplication(vector<int>& arr, int i, int j, vector<vector<int>>& dp) {
     // base case
    if(i == j) {
        return 0;
    }
    if(dp[i][j] != -1) {
        return dp[i][j];
    }

    // recursive case
    int mini = 1e9;
    for(int k = i; k < j; k++) {
        int steps = arr[i-1]*arr[k]*arr[j] + matrixMultiplication(arr, i, k, dp) + matrixMultiplication(arr, k+1, j, dp);
        mini = min(steps, mini);
    }

    return dp[i][j] = mini;
}

int matrixMultiplicationBottomUp(vector<int>& arr, int n) {
    vector<vector<int>> dp(n, vector<int>(n, 0));

    // base case
    for(int i = 1; i < n; i++) {
        dp[i][i] = 0;
    }

    for(int i = n-1; i >= 1; i--) {
        for(int j = i+1; j < n; j++) {
            int mini = 1e9;
            for(int k = i; k < j; k++) {
                int steps = arr[i-1]*arr[k]*arr[j] + dp[i][k] + dp[k+1][j];
                mini = min(steps, mini);
            }
            dp[i][j] = mini;
        }
    }

    return dp[1][n-1];
}

int main() {

    vector<int> arr {10, 20, 30, 40, 50};

    int n = arr.size();

    vector<vector<int>> dp(n, vector<int>(n, -1));

    cout<<matrixMultiplication(arr, 1, n-1, dp)<<endl;
    cout<<matrixMultiplicationBottomUp(arr, n)<<endl;

    return 0;
}