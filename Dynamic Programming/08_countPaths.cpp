#include <iostream>
#include <vector>
using namespace std;

int countPaths(int i, int j, vector<vector<int>> &dp) {
    // base case
    if (i == 0 and j == 0)
    {
        return 1;
    }
    if (i < 0 or j < 0)
    {
        return 0;
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }

    // recursive case
    int left = countPaths(i, j - 1, dp);
    int up = countPaths(i - 1, j, dp);

    return dp[i][j] = left + up;
}

int countPathsBottomUp(int m, int n) {
    vector<vector<int>> dp(m, vector<int>(n));

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(i == 0 and j == 0) {
                dp[i][j] = 1;
            }
            else {
                int up = 0;
                int left = 0;
                if(i > 0) {
                    up += dp[i-1][j];
                }
                if(j > 0) {
                    left += dp[i][j-1];
                }

                dp[i][j] = up + left;
            }
            
        }
    }

    return dp[m-1][n-1];
}

int main() {

    int m = 3;
    int n = 3;

    vector<vector<int>> dp(m, vector<int>(n, -1));

    cout << countPaths(m - 1, n - 1, dp) << endl;
    cout << countPathsBottomUp(m, n) << endl;

    return 0;
}