#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int LCSBottomUp(string text1, string text2, int m, int n) {

}


int main() {

    string s1 = "brute";
    string s2 = "groot";

    int m = s1.size();
    int n = s2.size();

    // code copied from LCS
    int dp[m + 1][n + 1];

    // writitng the base cases
    for (int i = 0; i <= m; i++) {
        dp[i][0] = 0;
    }
    for (int j = 0; j <= n; j++) {
        dp[0][j] = 0;
    }

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
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

    string ans = "";

    while(i > 0 and j > 0) {
        if(s1[i-1] == s2[j-1]) {
            ans += s1[i-1];
            i--;
            j--;
        }
        else if(dp[i-1][j] > dp[i][j-1]) {
            ans += s1[i-1];
            i--;
        }
        else {
            ans += s2[j-1];
            j--;
        }
    }

    while(i > 0) {
        ans += s1[i-1];
        i--;
    }

    while(j > 0) {
        ans += s2[j-1];
        j--;
    }

    reverse(ans.begin(), ans.end());

    cout<<ans<<endl;


    return 0;
}