#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

int G(int n, vector<int>& S, int pos, int prev, int dp[8][8]) {
    // base case
    if(pos == n) {
        return 1;
    }

    if(dp[pos][prev] != -1) return dp[pos][prev];

    // recursive case
    int res = 0;
    for(int j = 0; j < S.size(); j++) {
        if(pos == 0 or abs(S[j] - prev) <= 2) {
            res += G(n, S, pos + 1, S[j], dp);
        }
    }

    return dp[pos][prev] = res;
}

int main() {

    int n = 2;
    vector<int> S {1, 3, 6};

    int dp[8][8];

    memset(dp, -1, sizeof(dp));

    cout<<G(n, S, 0, 0, dp)<<endl;


    return 0;
}