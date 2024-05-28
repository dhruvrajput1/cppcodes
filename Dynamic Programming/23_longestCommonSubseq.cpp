#include <iostream>
#include <vector>
using namespace std;

// before shifting of indexes code
// int LCS(string text1, string text2, int i1, int i2, vector<vector<int>> &dp)
// {
//     // base case
//     if (i1 < 0 or i2 < 0)
//     {
//         return 0;
//     }

//     if (dp[i1][i2] != -1)
//         return dp[i1][i2];

//     // if matches
//     if (text1[i1] == text2[i2])
//     {
//         return dp[i1][i2] = 1 + LCS(text1, text2, i1 - 1, i2 - 1, dp);
//     }

//     return dp[i1][i2] = 0 + max(LCS(text1, text2, i1 - 1, i2, dp), LCS(text1, text2, i1, i2 - 1, dp));
// }

// code after shifting of indexes
int longestCommonSubsequences(string text1, string text2, int i1, int i2, vector<vector<int>> &dp)
{
    // base case
    if (i1 == 0 or i2 == 0)
    {
        return 0;
    }

    if (dp[i1][i2] != -1)
        return dp[i1][i2];

    // if matches
    if (text1[i1 - 1] == text2[i2 - 1])
    {
        return dp[i1][i2] = 1 + longestCommonSubsequences(text1, text2, i1 - 1, i2 - 1, dp);
    }

    return dp[i1][i2] = 0 + max(longestCommonSubsequences(text1, text2, i1 - 1, i2, dp), longestCommonSubsequences(text1, text2, i1, i2 - 1, dp));
}

int LCSBottomUp(string text1, string text2, int m, int n)
{

    int dp[m + 1][n + 1];

    // writitng the base cases
    for (int i = 0; i <= m; i++)
    {
        dp[i][0] = 0;
    }
    for (int j = 0; j <= n; j++)
    {
        dp[0][j] = 0;
    }

    for (int i = 1; i <= m; i++)
    {
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

// space optimization
int LCSSpaceOpt(string text1, string text2, int m, int n)
{

    vector<int> prev(n + 1, 0);
    vector<int> curr(n + 1, 0);

    // writitng the base cases
    for (int j = 0; j <= n; j++)
    {
        prev[j] = 0;
    }

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            // matching
            if (text1[i - 1] == text2[j - 1])
            {
                curr[j] = 1 + prev[j - 1];
            }
            else
            {
                curr[j] = max(prev[j], curr[j - 1]);
            }
        }
        prev = curr;
    }
    return prev[n];
}

int main()
{

    string s1 = "acd";
    string s2 = "ced";

    int m = s1.size();
    int n = s2.size();

    vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));

    cout << longestCommonSubsequences(s1, s2, m, n, dp) << endl;
    cout << LCSBottomUp(s1, s2, m, n) << endl;
    cout << LCSSpaceOpt(s1, s2, m, n) << endl;

    return 0;
}