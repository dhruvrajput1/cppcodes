#include<iostream>
#include<vector>
using namespace std;

int minCoins(vector<int>& coins, int i, int target, vector<vector<int>> &dp) {

    if(i == 0) {
        if(target%coins[0] == 0) {
            return target/coins[0];
        }
        else {
            return 1e9;
        }
    }

    if(dp[i][target] != -1) {
        return dp[i][target];
    }

    int notTake = minCoins(coins, i-1, target, dp);
    int take = 1e9;
    if(coins[i] <= target) {
        take = 1 + minCoins(coins, i, target-coins[i], dp);
    }

    return dp[i][target] = min(take, notTake);

}

int minCoinsBottomUp(vector<int> &coins, int target) {

    int n = coins.size();

    vector<vector<int>> dp(n, vector<int>(target+1, 0));

    for(int T = 0; T <= target; T++) {
        if(T%coins[0] == 0) {
            dp[0][T] =  T/coins[0];
        }
        else {
            dp[0][T] = 1e9;
        }
    }

    for(int i = 1; i < n; i++) {
        for(int T = 0; T <= target; T++) {
            int notTake = dp[i-1][T];
            int take = 1e9;
            if(coins[i] <= T) {
                take = 1 + dp[i][T-coins[i]];
            }

            dp[i][T] = min(take, notTake);
        }
    }

    return dp[n-1][target];

}

// space optimization
int minCoinsSpaceOpt(vector<int> &coins, int target) {

    int n = coins.size();

    vector<int> prev(target+1, 0);
    vector<int> curr(target+1, 0);

    for(int T = 0; T <= target; T++) {
        if(T%coins[0] == 0) {
            prev[T] =  T/coins[0];
        }
        else {
            prev[T] = 1e9;
        }
    }

    for(int i = 1; i < n; i++) {
        for(int T = 0; T <= target; T++) {
            int notTake = prev[T];
            int take = 1e9;
            if(coins[i] <= T) {
                take = 1 + curr[T-coins[i]];
            }

            curr[T] = min(take, notTake);
        }
        prev = curr;
    }

    return prev[target];

}

int main() {

    vector<int> coins {9, 6, 5, 1};

    int n = coins.size();
    int target = 7;

    vector<vector<int>> dp(n, vector<int>(target+1, -1));

    cout<<minCoins(coins, n-1, target, dp)<<endl;
    cout<<minCoinsBottomUp(coins, target)<<endl;
    cout<<minCoinsSpaceOpt(coins, target)<<endl;

    
    return 0;
}