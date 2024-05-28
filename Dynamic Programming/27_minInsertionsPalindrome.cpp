#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int LCSBottomUp(string text1, string text2, int m, int n) {

    int dp[m + 1][n + 1];

    // writitng the base cases
    for (int i = 0; i <= m; i++) {
        dp[i][0] = 0;
    }
    for (int j = 0; j <= n; j++) {
        dp[0][j] = 0;
    }

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++)
        {
            // matching
            if (text1[i - 1] == text2[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    return dp[m][n];
}


int longestPalindromicSubsequence(string s) {
    
    string t = s;

    reverse(t.begin(), t.end());

    return LCSBottomUp(s, t, s.size(), t.size());
}

int main() {

    string s = "abcaa";

    int n = s.size();

    cout<< n-longestPalindromicSubsequence(s)<<endl;


    return 0;
}