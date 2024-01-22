#include <iostream>
#include <climits>
using namespace std;

int minCoinsNeeded(int *coins, int n, int amount) {
    // base case
    if(amount == 0) {
        return 0;
    }

    // recursive case
    int ans = INT_MAX;

    for (int i = 0; i < n; i++) {

        if (amount - coins[i] >= 0) {

            int chotaAmount = amount - coins[i];
            int chotaAns = minCoinsNeeded(coins, n, chotaAmount);

            if (chotaAns != INT_MAX and chotaAns < ans) {
                ans = chotaAns;
            }
        }
    }

    return ans + 1;
}

int topDown(int* coins, int n, int amount, int* &dp) {
    // base case
    if(amount == 0) {
        dp[amount] = 0;
        return 0;
    }

    // check before calculating
    if(dp[amount] != -1) {
        return dp[amount]; 
    }

    // recursive case
    int ans = INT_MAX;

    for (int i = 0; i < n; i++) {

        if (amount - coins[i] >= 0) {

            int chotaAmount = amount - coins[i];
            int chotaAns = minCoinsNeeded(coins, n, chotaAmount);

            if (chotaAns != INT_MAX and chotaAns < ans) {
                ans = chotaAns;
            }
        }
    }

    

    // store befire return 
    dp[amount] = ans + 1;
    return ans + 1;

}

// bottom up
int bottomUp(int *coins, int n, int amount) {

    int* dp = new int[amount + 1];

    for(int i = 0; i <= amount; i++) {
        dp[i] = INT_MAX;
    }

    dp[0] = 0;

    for(int rupee = 1; rupee <= amount; rupee++) {
        for(int i = 0; i < n; i++) {
            if(rupee - coins[i] >= 0) {
                int chotaAmount = rupee - coins[i];
                dp[rupee] = min(dp[rupee], dp[chotaAmount]+1);
            }
        }
    }

    for(int i = 0; i <= amount; i++) {
        cout<<dp[i]<<" ";
    }
    cout<<endl;

    return dp[amount];


}

int main() {

    int coins[] = {1, 7, 10};

    int amount;
    cin >> amount;

    int n = sizeof(coins) / sizeof(int);

    cout << "Simple Recursion " << minCoinsNeeded(coins, n, amount) << endl;

    int* dp = new int[amount + 1];

    for(int i = 0; i <= amount; i++) {
        dp[i] = -1;
    }

    cout<<"Top Down "<<topDown(coins, n, amount, dp)<<endl;

    cout<<"bottom up"<<bottomUp(coins, n, amount)<<endl;

    return 0;
}