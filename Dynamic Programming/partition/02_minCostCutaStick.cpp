#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int minCost(vector<int>& cuts, int i, int j, vector<vector<int> >& dp) {
    // base case
    if(i > j) {
        return 0;
    }
    if(dp[i][j] != -1) {
        return dp[i][j];
    }

    // recursive case
    int mini = 1e9;
    for(int idx = i; idx <= j; idx++) {
        int cost = cuts[j+1] - cuts[i-1] + minCost(cuts, i, idx-1, dp) + minCost(cuts, idx+1, j, dp);
        mini = min(mini, cost);
    }

    return dp[i][j] = mini;
    
}

int minCostBottomUp(vector<int>& cuts, int n, int m) {

    vector<vector<int>> dp(m+2, vector<int>(m+2, 0));


    // recursive case
    for(int i = m; i >= 1; i--) {
        for(int j = 1; j <= m; j++) {
            int mini = 1e9;
            if(i > j) {
                continue;
            }
            for(int idx = i; idx <= j; idx++) {
                int cost = cuts[j+1] - cuts[i-1] + dp[i][idx-1] + dp[idx+1][j];
                mini = min(mini, cost);
            }
            dp[i][j] = mini;
        }
    }

    return dp[1][m];
}

int main() {
    
    int n = 7;
    vector<int> cuts {1, 3, 4, 5};

    int m = cuts.size();

    cuts.push_back(n);
    cuts.insert(cuts.begin(), 0);

    sort(cuts.begin(), cuts.end());

    vector<vector<int>> dp(m+1, vector<int>(m+1, -1));

    cout<<minCost(cuts, 1, m, dp)<<endl;
    cout<<minCostBottomUp(cuts, n, m)<<endl;


    return 0;
}