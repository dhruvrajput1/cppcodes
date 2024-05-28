#include<iostream>
#include<vector>
using namespace std;

int maxProfit(vector<int> &value, int i, int n, int buy, int capacity, vector<vector<vector<int>>> &dp) {
    // base case
    if(capacity == 0) return 0;
    if(i == n) return 0;

    if(dp[i][buy][capacity] != -1) return dp[i][buy][capacity];

    // recursive case

    int profit = 0;

    if(buy == 1) {
        int take = -value[i] + maxProfit(value, i+1, n, 0, capacity, dp);
        int notTake = maxProfit(value, i+1, n, 1, capacity, dp);
        profit = max(take, notTake);
    }
    else {
        int sell = value[i] + maxProfit(value, i+1, n, 1, capacity-1, dp);
        int NotSell = maxProfit(value, i+1, n, 0, capacity, dp);
        profit = max(sell, NotSell);
    }

    return dp[i][buy][capacity] = profit;

}

int maxProfitBottomUp(vector<int> value, int capacity, int n) {
    int dp[n+1][2][3];

    // writing base cases
    for(int i = 0; i < n; i++) {
        for(int buy = 0; buy <= 1; buy++) {
            dp[i][buy][0] = 0;
        }
    }

    for(int buy = 0; buy <= 1; buy++) {
        for(int cap = 0; cap <= capacity; cap++) {
            dp[n][buy][cap] = 0;
        }
    }

    int profit = 0;

    for(int i = n-1; i >= 0; i--) {
        for(int buy = 0; buy <= 2; buy++) {
            for(int cap = 1; cap <= capacity; cap++) {
                if(buy == 1) {
                    profit = max(-value[i] + dp[i+1][0][cap], dp[i+1][1][cap]);
                }
                else {
                    profit = max(value[i] + dp[i+1][1][cap-1], dp[i+1][0][cap]);
                }
                dp[i][buy][cap] = profit;
            }
        }
    }

    return dp[0][1][2];
}

// space optimization
int maxProfitSpaceOpt(vector<int> value, int capacity, int n) {

    vector<vector<int>> after(2, vector<int> (3, 0));
    vector<vector<int>> curr(2, vector<int> (3, 0));

    // writing base cases
    for(int i = 0; i < n; i++) {
        for(int buy = 0; buy <= 1; buy++) {
            curr[buy][0] = 0;
        }
    }

    for(int buy = 0; buy <= 1; buy++) {
        for(int cap = 0; cap <= capacity; cap++) {
            curr[buy][cap] = 0;
        }
    }

    int profit = 0;

    for(int i = n-1; i >= 0; i--) {
        for(int buy = 0; buy <= 1; buy++) {
            for(int cap = 1; cap <= capacity; cap++) {
                if(buy == 1) {
                    profit = max(-value[i] + after[0][cap], after[1][cap]);
                }
                else {
                    profit = max(value[i] + after[1][cap-1], after[0][cap]);
                }
                curr[buy][cap] = profit;
            }
            after = curr;
        }
        
    }

    return after[1][2];

}

int main() {

    vector<int> value {3, 3, 5, 0, 0, 3, 1, 4};

    int n = value.size();

    int capacity = 2;
    int buy = 1;

    vector<vector<vector<int>>> dp (n, vector<vector<int>> (2, vector<int> (3, -1)));

    cout<<maxProfit(value, 0, n, buy, capacity, dp)<<endl;
    cout<<maxProfitBottomUp(value, capacity, n)<<endl;
    cout<<maxProfitSpaceOpt(value, capacity, n)<<endl;

    return 0;
}