#include<iostream>
#include<vector>
using namespace std;

int minWays(string s1, string s2, int i, int j, vector<vector<int>> dp) {
    // base case
    if(i < 0) {
        return j+1;
    }
    if(j < 0) {
        return i+1;
    }
    if(dp[i][j] != -1) {
        return dp[i][j];
    }

    // recursive case
    if(s1[i] == s2[j]) {
        return dp[i][j] = minWays(s1, s2, i-1, j-1, dp);
    }

    int insert = 1 + minWays(s1, s2, i, j-1, dp);
    int deletion = 1 + minWays(s1, s2, i-1, j, dp);
    int replace = 1 + minWays(s1, s2, i-1, j-1, dp);

    return dp[i][j] = min(insert, min(deletion, replace));
}

int minWaysBottomUp(string s1, string s2, int m, int n) { // 1 based indexing // shifting index
    int dp[m+1][n+1];

    for(int j = 0; j <= n; j++) {
        dp[0][j] = j;
    }

    for(int i = 0; i <= m; i++) {
        dp[i][0] = i;
    }

    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) {
            if(s1[i-1] == s2[j-1]) {
                dp[i][j] = dp[i-1][j-1];
            }
            else {
                int insert = 1 + dp[i][j-1];
                int delettion = 1 + dp[i-1][j];
                int replace = 1 + dp[i-1][j-1];

                dp[i][j] = min(insert, min(delettion, replace));
            }
        }
    }

    return dp[m][n];
}


int main() {

    string s1 = "horse"; // find min ways to convert string s1 to s2
    string s2 = "ros";

    int m = s1.size();
    int n = s2.size();

    vector<vector<int>> dp (m, vector<int> (n, -1));

    cout<<minWays(s1, s2, m-1, n-1, dp)<<endl;
    cout<<minWaysBottomUp(s1, s2, m, n)<<endl;

    return 0;
}