#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int maxPathSum(vector<vector<int>> &matrix, vector<vector<int>> &dp, int i, int j) {
    
    if(j < 0 or j >= matrix[0].size()) {
        return INT_MIN;
    }
    if(i == 0) {
        return matrix[0][j];
    }

    if(dp[i][j] != -1) {
        return dp[i][j];
    }

    int up = matrix[i][j] + maxPathSum(matrix, dp, i-1, j);
    int rightDiag = matrix[i][j] + maxPathSum(matrix, dp, i-1, j+1);
    int leftDiag = matrix[i][j] + maxPathSum(matrix, dp, i-1, j-1);

    return dp[i][j] = max(up, max(leftDiag, rightDiag));
}

int maxPathSumBottomUp(vector<vector<int>> &matrix, int m, int n) {
    int dp[m][n];

    for(int j = 0; j < n; j++) {
        dp[0][j] = matrix[0][j];
    }

    for(int i = 1; i < m; i++) {
        for(int j = 0; j < n; j++) {
            int up = matrix[i][j] + dp[i-1][j];
            int rightDiag = 0;
            int leftDiag = 0;
            if(j < m-1) rightDiag = matrix[i][j] + dp[i-1][j+1];
            if(j > 0) leftDiag = matrix[i][j] + dp[i-1][j-1];

            dp[i][j] = max(up, max(leftDiag, rightDiag));
        }
    }

    int maxi = INT_MIN;

    for(int j = 0; j < n; j++) {
        maxi = max(maxi, dp[m-1][j]);
    }

    return maxi;
}

// space optimization
int maxPathSumSpaceOpt(vector<vector<int>> &matrix, int m, int n) {
    vector<int> prev(n, 0);
    

    for(int j = 0; j < n; j++) {
        prev[j] = matrix[0][j];
    }

    for(int i = 1; i < m; i++) {
        vector<int> curr(n, 0);
        for(int j = 0; j < n; j++) {
            int up = matrix[i][j] + prev[j];
            int leftDiag, rightDiag = -1e8;
            if(j > 0) leftDiag = matrix[i][j] + prev[j-1];
            if(j < m-1) rightDiag = matrix[i][j] + prev[j+1];

            curr[j] = max(up, max(leftDiag, rightDiag));
        }
        prev = curr;
    }

    int maxi = -1e8;

    for(int j = 0; j < n; j++) {
        maxi = max(maxi, prev[j]);
    }

    return maxi;

}

int main() {

    vector<vector<int>> matrix {
        {1, 2, 10, 4},
        {100, 3, 2, 1},
        {1, 1, 20, 2},
        {1, 2, 2, 1}
    };

    int m = matrix.size();
    int n = matrix[0].size();


    vector<vector<int>> dp(m, vector<int>(n, -1));

    int ans = INT_MIN;

    for(int j = 0; j < n-1; j++) {
        ans = max(ans, maxPathSum(matrix, dp, m-1, n-1-j));
    }

    cout<<ans<<endl;

    cout<<maxPathSumBottomUp(matrix, m, n)<<endl;

    cout<<maxPathSumSpaceOpt(matrix, m, n)<<endl;

    return 0;
}