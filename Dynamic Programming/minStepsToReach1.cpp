#include<iostream>
#include<climits>
using namespace std;

int minStepsToReach1(int n) {
    // base case
    if(n == 1) {
        return 0;
    }

    // recursive case
    int opt1, opt2, opt3;
    opt1 = opt2 = opt3 = INT_MAX;

    opt1 = minStepsToReach1(n - 1);
    if(n%3 == 0) {
        opt2 = minStepsToReach1(n/3);
    }
    if(n%2 == 0) {
        opt3 = minStepsToReach1(n/2);
    }

    return min(opt1, min(opt2, opt3)) + 1;

} 

int topDown(int n, int* dp) {
     // base case
    if(n == 1) {
        dp[n] = 0; // return karne se pehle store
        return 0;
    }

    // calculate krne se pehle check
    if(dp[n] != -1) {
        return dp[n];
    }

    // recursive case
    int opt1, opt2, opt3;
    opt1 = opt2 = opt3 = INT_MAX;

    opt1 = topDown(n - 1, dp);
    if(n%3 == 0) {
        opt2 = topDown(n/3, dp);
    }
    if(n%2 == 0) {
        opt3 = topDown(n/2, dp);
    }

    // return karne se pehle store
    dp[n] = min(opt1, min(opt2, opt3)) + 1; 

    return min(opt1, min(opt2, opt3)) + 1;
}

int bottomUp(int n) {
    int* dp = new int[n + 1];

    dp[1] = 0;

    int opt1, opt2, opt3;
    

    for(int i = 2; i <= n; i++) {
        opt1 = opt2 = opt3 = INT_MAX;

        opt1 = dp[i-1];
        if(i%2 == 0) {
            opt2 = dp[i/2];
        }
        if(i%3 == 0) {
            opt3 = dp[i/3];
        }
        dp[i] = min(opt1, min(opt2, opt3)) + 1;
    }

    for(int i = 0; i <= n; i++) {
        cout<<dp[i]<<" ";
    }
    cout<<endl;

    return dp[n];
}

int main() {

    int n; cin>>n;

    cout<<"Simple Recursion "<<minStepsToReach1(n)<<endl;

    int* dp = new int[n+1];

    for(int i = 0; i <= n; i++) {
        dp[i] = -1;
    }

    cout<<"Top Down "<<topDown(n, dp)<<endl;

    for(int i = 0; i <= n; i++) {
        cout<<dp[i]<<" ";
    }
    cout<<endl;

    cout<<"Bottom Up "<<bottomUp(n)<<endl;

    return 0;
}