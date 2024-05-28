#include<iostream>
#include<vector>
using namespace std;

int main() {

    string s1 = "ababa";
    string s2 = "cbbcad";

    int m = s1.size();
    int n = s2.size();

    // copied code from LCS
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
            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    // copied code ends

    int i = m;
    int j = n;

    int length = dp[m][n];
    int index = length-1; // will be used for creating string ans
    string ans = "";

    for(int i = 0; i < length; i++) {
        ans.push_back('$');
    }

    while(i > 0 and j > 0) {

        if(s1[i-1] == s2[j-1]) {
            ans[index] = s1[i-1];
            index--;
            i--;
            j--;
        }
        else if(dp[i-1][j] > dp[i][j-1]) {
            i--;
        }
        else {
            j--;
        }

    }

    cout<<ans<<endl;
   

    return 0;
}