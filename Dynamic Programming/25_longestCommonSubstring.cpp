#include<iostream>
#include<vector>
using namespace std;

int LCSBottomUp(string s1, string s2, int m, int n)  {
    int dp[m][n];

    for(int i = 0; i <= m; i++) {
        dp[i][0] = 0;
    }
    for(int j = 0; j <= n; j++) {
        dp[0][j] = 0;
    }

    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) {
            if(s1[i-1] == s2[j-1]) {.
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else {
                dp[i][j] = 0;
            }
        }
    }

    int ans = 0;
    
    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) {
            ans = max(ans, dp[i][j]);
        }
    }

    return ans;

}

int main() {

    string s1 = "abcjklp";
    string s2 = "acjkp";

    int m = s1.size();
    int n = s2.size();

    vector<vector<int>> dp (m, vector<int> (n, -1));

    cout<<LCSBottomUp(s1, s2, m-1, n-1)<<endl;


    return 0;
}