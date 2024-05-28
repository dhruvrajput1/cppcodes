#include<iostream>
#include<vector>
using namespace std;

int maximumChocolates(vector<vector<int>> &grid, int m, int n, int i, int j1, int j2, vector<vector<vector<int>>> &dp) {
    // base case
    if(j1 < 0 or j2 < 0 or j1 >= n or j2 >= n) {
        return -1e8;
    }

    if(i == m-1) {
        if(j1 == j2) {
            return grid[i][j1];
        }
        else {
            return grid[i][j1] + grid[i][j2];
        }
    }

    if(dp[i][j1][j2] != -1) {
        return dp[i][j1][j2];
    }

    int maxi = 0;

    for(int dj1 = -1; dj1 <= 1; dj1++) {
        for(int dj2 = -1; dj2 <= 1; dj2++) {
            if(j1 == j2) maxi = max(maxi, grid[i][j1] +  maximumChocolates(grid, m, n, i+1, j1+dj1, j2+dj2, dp));
            else maxi = max(maxi, grid[i][j1] + grid[i][j2] + maximumChocolates(grid, m, n, i+1, j1+dj1, j2+dj2, dp));
        }
    }

    return dp[i][j1][j2] =  maxi;
}

int main() { // tabulation form not asked in interview of 3D DP

    vector<vector<int>> grid {
        {2, 3, 1, 2},
        {3, 4, 2, 2},
        {5, 6, 3, 5}
    };

    int m = grid.size();
    int n = grid[0].size();

    vector<vector<vector<int>>> dp(m, vector<vector<int>> (n, vector<int> (n, -1)));

    cout<<maximumChocolates(grid, m, n, 0, 0, n-1, dp)<<endl;

    return 0;
}