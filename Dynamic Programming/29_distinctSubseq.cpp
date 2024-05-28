#include<iostream>
#include<vector>
using namespace std;

int distinctSubseq(string s1, string s2, int i, int j, vector<vector<int>> &dp) {
    // base case
    if(j < 0) {
        return 1;
    }
    if(i < 0) {
        return 0;
    }
    
    if(dp[i][j] != -1) {
        return dp[i][j];
    }

    // recursive case
    if(s1[i] == s2[j]) {
        return dp[i][j] = distinctSubseq(s1, s2, i-1, j-1, dp) + distinctSubseq(s1, s2, i-1, j, dp);
    }
    else {
        return dp[i][j] = distinctSubseq(s1, s2, i-1, j, dp);
    }
}


int distinctSubseqBottomUp(string s1, string s2, int m, int n) { // shifted index by 1 towards positive side
    int dp[m+1][n+1];

    for(int i = 0; i <= m; i++) {
        dp[i][0] = 1;
    }

    for(int j = 1; j <= n; j++) {
        dp[0][j] = 0;
    }

    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) {
            if(s1[i-1] == s2[j-1]) {
                dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
            }
            else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    return dp[m][n];

} 


int main() {

    string s1 = "babgbag";
    string s2 = "bag";

    int m = s1.size();
    int n = s2.size();

    vector<vector<int>> dp (m, vector<int> (n, -1));

    cout<<distinctSubseq(s1, s2, m-1, n-1, dp)<<endl;
    cout<<distinctSubseqBottomUp(s1, s2, m, n)<<endl;

    return 0;
}