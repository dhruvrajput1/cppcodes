#include<iostream>
#include<vector>
using namespace std;

bool isPalindrome(string s) {
    int i = 0;
    int j = s.length() - 1;
    while (i < j) {
        if (s[i]!= s[j]) {
            return false;
        }
        i++;
        j--;
    }
    return true;
}

int minPartitions(int i, int n, string s) {
    // base case
    if(i == n) {
        return 0;
    }

    // recursive case
    string temp = "";
    int minCost = 1e9;
    for(int j = i; j < n; j++) {
        temp += s[j];
        if(isPalindrome(temp)) {
            int cost = 1 + minPartitions(j+1, n, s);
            minCost = min(cost, minCost);
        }
    }

    return minCost;
}

int minPartitionsTabulation(string s) {
    int n = s.length();

    vector<int> dp(n+1, 0);

    // base case
    dp[n] = 0;

    for(int i = n-1; i >= 0; i--) {
        string temp = "";
        int minCost = 1e9;
        for(int j = i; j < n; j++) {
            temp += s[j];
            if(isPalindrome(temp)) {
                int cost = 1 + dp[j+1];
                minCost = min(cost, minCost);
            }
            dp[i] = minCost;
        }
    }

    return dp[0];
}

int main() {

    string s = "bababcbadcede";

    int n = s.size();

    cout<< minPartitions(0, n, s) - 1<<endl; // -1 to ignore the last partition when i == n-1;

    cout<<minPartitionsTabulation(s) - 1<<endl;


    return 0;
}