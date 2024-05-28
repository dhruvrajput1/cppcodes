#include<iostream>
#include<vector>
using namespace std;

int ways(vector<int> &coins, int i, int target, vector<vector<int>> &dp) {
    // base case
    if(i == 0) {
        if(target%coins[0] == 0) {
            return 1;
        }
        else {
            return 0;
        }
    }

    if(dp[i][target] != -1) return dp[i][target];

    // recursive case
    int notPick = ways(coins, i-1, target, dp);
    int pick = 0;
    if(coins[i] <= target) {
        pick = ways(coins, i, target-coins[i], dp);
    }

    return dp[i][target] = pick + notPick;
}

int waysBottomUp(vector<int> &coins, int target) {
    int n = coins.size();

    int dp[n][target+1];

    for(int T = 0; T <= target; T++) {
        dp[0][T] = T%coins[0] == 0;
    }

    for(int i = 1; i < n; i++) {
        for(int T = 0; T <= target; T++) {
            int notPick = dp[i-1][T];
            int pick = 0;
            if(coins[i] <= T) {
                pick = dp[i][T-coins[i]];
            }

            dp[i][T] = pick + notPick;
        }
    }

    return dp[n-1][target];
}

int main() {

    vector<int> coins {1, 2, 3};

    int n = coins.size();

    int target = 4;

    vector<vector<int>> dp(n, vector<int> (target+1, -1));

    cout<<ways(coins, n-1, target, dp)<<endl;
    cout<<waysBottomUp(coins, target)<<endl;

    return 0;
}