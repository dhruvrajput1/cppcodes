#include<iostream>
#include<vector>
using namespace std;

int minSumPath(vector<vector<int>> &triangle, vector<vector<int>> &dp, int i, int j, int n) {
    if(i == n-1) {
        return triangle[n-1][j];
    }

    if(dp[i][j] != -1) {
        return dp[i][j];
    }

    int down = triangle[i][j] + minSumPath(triangle, dp, i+1, j, n);
    int diagonal = triangle[i][j] + minSumPath(triangle, dp, i+1, j+1, n);

    return dp[i][j] = min(down, diagonal);
}

int minSumPathBottomUp(vector<vector<int>> &triangle, int n) {
    int dp[n][n];

    // base case
    for(int j = 0; j < n; j++) {
        dp[n-1][j] = triangle[n-1][j];
    }

    for(int i = n-2; i >= 0; i--) {
        for(int j = i; j >= 0; j--) {
            int down = triangle[i][j] + dp[i+1][j];
            int diagonal = triangle[i][j] + dp[i+1][j+1];

            dp[i][j] = min(down, diagonal);
        }
    }

    return dp[0][0];
}


// space optimized
int minSumPathSpaceOpt(vector<vector<int>> &triangle, int n) {
    vector<int> front(n);
    

    for(int j = 0; j < n; j++) {
        front[j] = triangle[n-1][j];
    }

    for(int i = n-2; i >= 0; i--) {
        vector<int> curr(n);
        for(int j = i; j >= 0; j--) {
            int down = triangle[i][j] + front[j];
            int diagonal = triangle[i][j] + front[j+1];

            curr[j] = min(down, diagonal);
        }
        front = curr;
    }

    return front[0];
}

int main() {

    vector<vector<int>> triangle {
        {1},
        {2, 3},
        {3, 6, 7},
        {8, 9, 6, 10}
    };

    int n = triangle.size();

    vector<vector<int>> dp(n, vector<int>(n, -1));

    cout<<minSumPath(triangle, dp, 0, 0, n)<<endl;
    cout<<minSumPathBottomUp(triangle, n)<<endl;
    cout<<minSumPathSpaceOpt(triangle, n)<<endl;


    return 0;
}