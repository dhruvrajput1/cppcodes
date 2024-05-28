#include<iostream>
#include<vector>
#include<climits>
using namespace std;

long long minSum(vector<vector<int>> &paths, vector<vector<int>> &dp, int i, int j) {
    // base case
    if(i == 0 and j == 0) {
        return paths[i][j];
    }
    if(i < 0 or j < 0) {
        return INT_MAX;
    }

    if(dp[i][j] != -1) {
        return dp[i][j];
    }

    // recursive case
    long long left = paths[i][j] + minSum(paths, dp, i, j-1);
    long long up = paths[i][j] + minSum(paths, dp, i-1, j);

    return dp[i][j] = min(left, up);
}

int minSumBottomUp(vector<vector<int>> &paths, int m, int n) {
    int dp[m][n];

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(i == 0 and j == 0) {
                dp[i][j] = paths[i][j];
            }
            else {
                int left = INT_MAX;
                int up = INT_MAX;

                if(i > 0) {
                    up = paths[i][j] + dp[i-1][j];
                }
                if(j > 0) {
                    left = paths[i][j] + dp[i][j-1];
                }

                dp[i][j] = min(left, up);
            }
        }
    }

    return dp[m-1][n-1];

}


int main() {

    vector<vector<int>> paths {
        {5, 9, 6},
        {11, 5, 2}
    };

    int m = 2;
    int n = 3;

    vector<vector<int>> dp(m, vector<int>(n, -1));

    cout<<minSum(paths, dp, m-1, n-1)<<endl;
    cout<<minSumBottomUp(paths, m, n)<<endl;



    return 0;
}