#include<iostream>
#include<vector>
using namespace std;

int maxProfit(vector<int> &value, int i, int n, int buy, vector<vector<int>> &dp) {
    // base case
    if(i == n) return 0;

    if(dp[i][buy] != -1) return dp[i][buy];

    int profit = 0;

    // recursive case
    if(buy == 1) { // we can buy the stock
        int take = -value[i] + maxProfit(value, i+1, n, 0, dp);
        int notTake = maxProfit(value, i+1, n, 1, dp);
        profit = max(take, notTake);
    }
    else {
        int sell = value[i] + maxProfit(value, i+1, n, 1, dp);
        int notSell = maxProfit(value, i+1, n, 0, dp);
        profit = max(sell, notSell);
    }

    return dp[i][buy] = profit;
}

int maxProfitBottomUp(vector<int> value, int n) {
    vector<vector<int>> dp(n+1, vector<int> (2, 0));

    // writing base case
    dp[n][0] = 0;
    dp[n][1] = 0;

    int profit = 0;

    for(int i = n-1; i >= 0; i--) {
        for(int buy = 0; buy <= 1; buy++) {
            if(buy) {
                profit = max(-value[i] + dp[i+1][0], dp[i+1][1]);
            }
            else {
                profit = max(value[i] + dp[i+1][1], dp[i+1][0]);
            }
            dp[i][buy] = profit;
        }
    }

    return dp[0][1];

}

// space optimization
int maxProfitSpaceOpt(vector<int> &value, int n) {

    vector<int> ahead(2, 0);
    vector<int> curr(2, 0);

    // writing base case
    ahead[0] = 0;
    ahead[1] = 0;

    int profit = 0;

    for(int i = n-1; i >= 0; i--) {
        for(int buy = 0; buy <= 1; buy++) {
            if(buy) {
                profit = max(-value[i] + ahead[0], ahead[1]);
            }
            else {
                profit = max(value[i] + ahead[1], ahead[0]);
            }
            curr[buy] = profit;
        }
        ahead = curr;
    }

    return ahead[1];

}

int main() {

    vector<int> value {7, 1, 5, 3, 6, 4};

    int n = value.size();

    int buy = 1;

    vector<vector<int>> dp (n, vector<int> (2, -1));

    cout<<maxProfit(value, 0, n, buy, dp)<<endl;
    cout<<maxProfitBottomUp(value, n)<<endl;
    cout<<maxProfitSpaceOpt(value, n)<<endl;


    return 0;
}