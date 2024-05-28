#include<iostream>
#include<vector>
using namespace std;

int main() {

    vector<vector<int>> grid {
        {0, 1, 1, 1},
        {1, 1, 1, 1},
        {0, 1, 1, 1}
    };

    int m = grid.size();
    int n = grid[0].size();

    vector<vector<int>> dp(m, vector<int>(n, 0));

    // base case
    // copy first row and first column as it is
    for(int i = 0; i < m; i++) {
        dp[i][0] = grid[i][0];
    }

    for(int j = 0; j < n; j++) {
        dp[0][j] = grid[0][j];
    }

    for(int i = 1; i < m; i++) {
        for(int j = 1; j < n; j++) {
            if(grid[i][j] == 0) dp[i][j] = 0;
            else {
                dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1])) + 1;
            }
        }
    }

    int sum = 0;

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            sum += dp[i][j];
        }
    }

    cout<<sum<<endl;

    return 0;
}