#include<iostream>
#include<vector>
using namespace std;

int maxAmount(int i, vector<int> &weights, vector<int> &val, int capacity, vector<vector<int>> &dp) {
    // base case
    if(i == 0) {
        if(weights[0] <= capacity) return val[0];
        else return 0;
    }

    if(dp[i][capacity] != -1) {
        return dp[i][capacity];
    }

    // recursive case
    int notTake = maxAmount(i-1, weights, val, capacity, dp);
    int take = -1e8;
    if(weights[i] <= capacity) take = val[i] + maxAmount(i-1, weights, val, capacity-weights[i], dp);

    return dp[i][capacity] = max(take, notTake);
}

int maxAmountBottomUp(vector<int> weights, vector<int> val, int capacity, int n) {
    vector<vector<int>> dp(n, vector<int>(capacity+1, 0));

    for(int wt = weights[0]; wt <= capacity; wt++) {
        dp[0][wt] = val[0];
    }

    for(int i = 1; i < n; i++) {
        for(int wt = 0; wt <= capacity; wt++) {
            int notTake = dp[i-1][wt];
            int take = -1e8;
            if(weights[i] <= wt) {
                take = val[i] + dp[i-1][wt-weights[i]];
            }

            dp[i][wt] = max(take, notTake);
        }
    }

    return dp[n-1][capacity];

}


// space optimized
int maxAmountSpaceOpt(vector<int> weights, vector<int> val, int capacity, int n) {

    vector<int> prev(capacity+1, 0);
    vector<int> curr(capacity+1, 0);

    for(int wt = weights[0]; wt <= capacity; wt++) {
        prev[wt] = val[0];
    }

    for(int i = 1; i < n; i++) {
        for(int wt = 0; wt <= capacity; wt++) {
            int notTake = prev[wt];
            int take = -1e8;
            if(weights[i] <= wt) {
                take = val[i] + prev[wt-weights[i]];
            }

            curr[wt] = max(take, notTake);
        }
        prev = curr;
    }

    return prev[capacity];
}

int main() {

    vector<int> weights {3, 2, 5};
    vector<int> val {30, 40, 60};

    int capacity = 6;

    int n = weights.size();

    vector<vector<int>> dp(n, vector<int>(capacity+1, -1));

    cout<<maxAmount(n-1, weights, val, capacity, dp)<<endl;
    cout<<maxAmountBottomUp(weights, val, capacity, n)<<endl;
    cout<<maxAmountSpaceOpt(weights, val, capacity, n)<<endl;


    return 0;
}