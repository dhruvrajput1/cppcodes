#include<iostream>
#include<vector>
using namespace std;

bool isMatching(string s1, string s2, int i, int j, vector<vector<int>> &dp) {
    // base case
    if(i < 0 and j < 0) return true;

    if(i < 0 and j >= 0) return false;

    if(i >= 0 and j < 0) {
        for(int k = 0; k <= i; j++) {
            if(s1[k] != '*') {
                return false;
            }
        }
        return true;
    }

    if(dp[i][j] != -1) {
        return dp[i][j];
    }

    // recursive case
    if(s1[i] == s2[j] or s1[i] == '?') {
        return dp[i][j] =  isMatching(s1, s2, i-1, j-1, dp);
    }
    if(s1[i] == '*') {
        return dp[i][j] =  isMatching(s1, s2, i-1, j, dp) or isMatching(s1, s2, i, j-1, dp);
    }
    
    return dp[i][j] =  false;

}

bool isMatchingBottomUp(string s1, string s2, int m, int n) {
    bool dp[m+1][n+1];

    // writing base cases
    dp[0][0] = true;
    
    for(int j = 1; j <= n; j++) {
        dp[0][j] = false;
    }

    for(int i = 1; i <= m; i++) {
        int flag = true;
        for(int k = 1; k <= i; k++) {
            if(s1[k-1] == '*') {
                flag = false;
                break;
            }
        }
        dp[i][0] = flag;
    }

    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) {
            if(s1[i-1] == s2[j-1] or s1[i-1] == '?') {
                dp[i][j] = dp[i-1][j-1];
            }
            else if(s1[i-1] == '*') {
                dp[i][j] = dp[i-1][j] or dp[i][j-1];
            }
            else {
                dp[i][j] = false;
            }
        }
    }

    return dp[m][n];
}

int main() {

    string s1 = "ab*cd";
    string s2 = "abdefcd";

    int m = s1.size();
    int n = s2.size();

    vector<vector<int>> dp (m, vector<int> (n, -1));

    if(isMatching(s1, s2, m-1, n-1, dp)) cout<<"Matching"<<endl;
    else cout<<"Not Matching"<<endl;

    if(isMatchingBottomUp(s1, s2, m, n)) cout<<"Matching"<<endl;
    else cout<<"Not Matching"<<endl;

    return 0;
}