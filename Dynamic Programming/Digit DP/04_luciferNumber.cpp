#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

int prime[] = {
    2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43
};

bool isPrime(int oddSum, int evenSum, int len) {
    int diff;

    if(len%2 == 0) {
        diff = evenSum - oddSum;
    }
    else {
        diff = oddSum - evenSum;
    }

    if(diff < 0) return false;
    else {
        for(auto it : prime) {
            if(it == diff) return true;
        }
    }

    return false;
}

int G(string str, int idx, int tight, int oddSum, int evenSum, int dp[9][2][45][45]) {
    // base case
    if(idx == str.size()) {
        if(isPrime(oddSum, evenSum, str.size())) return 1;
        else return 0;
    }

    if(dp[idx][tight][oddSum][evenSum] != -1) return dp[idx][tight][oddSum][evenSum];

    // recursive case
    if(tight == 1) {
        int cnt = 0;
        for(int i = 0; i <= str[idx] - '0'; i++) {
            int od = oddSum;
            int ev = evenSum;

            if(idx%2 == 0) {
                ev += i;
            }
            else {
                od += i;
            }

            if(i == str[idx] - '0') {
                cnt += G(str, idx + 1, 1, od, ev, dp);
            }
            else {
                cnt += G(str, idx + 1, 0, od, ev, dp);
            }
        }

        return dp[idx][tight][oddSum][evenSum] = cnt;
    }
    else {
        int cnt = 0;
        for(int i = 0; i <= 9; i++) {
            int od = oddSum;
            int ev = evenSum;

            if(idx%2 == 0) {
                ev += i;
            }
            else {
                od += i;
            }

            cnt += G(str, idx + 1, 0, od, ev, dp);
        }

        return dp[idx][tight][oddSum][evenSum] = cnt;
    }
}

int main() {

    int l = 200;
    int h = 250;

    l = l - 1;

    string a = to_string(l);
    string b = to_string(h);

    int dp[9][2][45][45];

    memset(dp, -1, sizeof(dp));

    int x = G(a, 0, 1, 0, 0, dp);

    memset(dp, -1, sizeof(dp));
    
    int y = G(b, 0, 1, 0, 0, dp);

    cout<<y-x<<endl;


    return 0;
}