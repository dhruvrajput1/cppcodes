#include<iostream>
#include<vector>
using namespace std;

int maxAmount(int i, vector<int> &weights, vector<int> &val, int capacity, vector<vector<int>> &dp) {
    // base case
    if(i == 0) {
        return (capacity/weights[0])*val[0];
    }

    if(dp[i][capacity] != -1) return dp[i][capacity];

    // recursive case
    int notTake = maxAmount(i-1, weights, val, capacity, dp);
    int take = -1e8;
    if(weights[i] <= capacity) {
        take = val[i] + maxAmount(i, weights, val, capacity-weights[i], dp);
    }

    return dp[i][capacity] = max(notTake, take);

}

int maxAmountBottomUp(vector<int> &weights, vector<int> &val, int capacity) {
    int n = weights.size();

    int dp[n][capacity+1];

    for(int w = 0; w <= capacity; w++) {
        dp[0][w] = ((int)(w/weights[0]))*val[0];
    }

    for(int i = 1; i < n; i++) {
        for(int w = 0; w <= capacity; w++) {
            int notTake = dp[i-1][w];
            int take = -1e8;
            if(weights[i] <= w) {
                take = val[i] + dp[i][w-weights[i]];
            }
            dp[i][w] = max(take, notTake);
        }
    }

    return dp[n-1][capacity];

}

int main() {

    vector<int> weights {2, 4, 6};
    vector<int> val {5, 11, 13};

    int capacity = 10;

    int n = weights.size();

    vector<vector<int>> dp(n, vector<int>(capacity+1, -1));

    cout<<maxAmount(n-1, weights, val, capacity, dp)<<endl;
    cout<<maxAmountBottomUp(weights, val, capacity)<<endl;

    return 0;
}