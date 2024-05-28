#include<iostream>
#include<vector>
using namespace std;

bool isPresent(vector<int> &arr, int i, int k, vector<vector<int>> &dp) {
    // base case
    if(k == 0) {
        return true;
    }
    if(i == 0) {
        if(arr[0] == k) return true;
        else return false;
    }

    if(dp[i][k] != -1) {
        return dp[i][k];
    }


    // recursive case
    bool notTake = isPresent(arr, i-1, k, dp);
    bool take = false;
    if(arr[i] >= k) {
        take = isPresent(arr, i-1, k-arr[i], dp);
    }

    return dp[i][k] =  take or notTake;
}

bool isPresentBottomUp(vector<int> &arr, int k) {

    int n = arr.size();

    bool dp[n][k+1];

    for(int i = 0; i < n; i++) {
        dp[i][0] = true;
    }

    if(arr[0] <= k) dp[0][arr[0]] = true;

    for(int i = 1; i < n; i++) {
        for(int target = 1; target <= k; target++) {
            bool notTake = dp[i-1][target];
            bool take = false;
            if(target >= arr[i]) {
                take = dp[i-1][target-arr[i]];
            }

            dp[i][target] = take or notTake;
        }
    }

    return dp[n-1][k];

}


// space optimization
bool isPossibleSpaceOpt(vector<int> &arr, int k) {
    vector<bool> prev(k+1, 0);
    vector<bool> curr(k+1, 0);

    int n = arr.size();

    prev[0] = curr[0] = true;

    prev[arr[0]] = true;

    for(int i = 1; i < n; i++) {
        for(int target = 1; target <= k; target++) {
            bool notTake = prev[target];
            bool take = false;
            if(target >= arr[i]) {
                take = prev[target-arr[i]];
            }

            curr[target] = take or notTake;
        }
        prev = curr;
    }

    return prev[k];
}

int main() {

    vector<int> arr {1, 2, 3, 4};

    int n = arr.size();

    int k = 4;

    vector<vector<int>> dp(n, vector<int> (k+1, -1));

    if(isPresent(arr, n-1, k, dp)) cout<<"Present"<<endl;
    else cout<<"Not Present"<<endl;

    if(isPresentBottomUp(arr, k)) cout<<"Present"<<endl;
    else cout<<"Not Present"<<endl;

    if(isPossibleSpaceOpt(arr, k)) cout<<"Present"<<endl;
    else cout<<"Not Present"<<endl;

    return 0;
}