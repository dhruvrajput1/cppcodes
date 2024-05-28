#include<iostream>
#include<cstring>
using namespace std;

int prime[] = {1, 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71};

bool check(int sum) {
    int n = sizeof(prime)/sizeof(int);

    for(int i = 0; i < n; i++) {
        if(prime[i] == sum) return true;
    }

    return false;
}

int G(string str, int pos, int tight, int sum, int dp[8][2][72]) {

    // base case
    if(pos == str.size()) {
        if(check(sum)) {
            return 1;
        }
        else return 0;
    }

    if(dp[pos][tight][sum] != -1) return dp[pos][tight][sum];

    if(tight == 1) {
        int res = 0;
        for(int i = 0; i <= str[pos] - '0'; i++) {
            if(i == str[pos] - '0') {
                res += G(str, pos + 1, 1, sum + i, dp);
            }
            else {
                res += G(str, pos + 1, 0, sum + i, dp);
            }
        }
        return dp[pos][tight][sum] = res;
    }
    else {
        int res = 0;
        for(int i = 0; i <= 9; i++) {
            res += G(str, pos + 1, 0, sum + i, dp);
        }
        return dp[pos][tight][sum] = res;
    }

}

int main() {

    int l = 10;
    int h = 19;

    

    l = l - 1;

    string a = to_string(l);
    string b = to_string(h);

    int dp[8][2][72];

    memset(dp, -1, sizeof(dp));

    int ans1 = G(a, 0, 1, 0, dp);

    memset(dp, -1, sizeof(dp));

    int ans2 = G(b, 0, 1, 0, dp);

    cout<<ans2 - ans1<< endl;

    return 0;
}