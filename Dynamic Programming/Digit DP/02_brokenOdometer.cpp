#include<iostream>
#include<cstring>
using namespace std;

int G(string str, int pos, int tight, int flag, int dp[8][2][2]) {
    // base case
    if(pos == str.size()) {
        if(flag == 1) return 1; // contains 3
        else return 0;
    }

    if(dp[pos][tight][flag] != -1) return dp[pos][tight][flag];

    // recursive case
    if(tight == 1) {
        int res = 0;
        for(int i = 0 ; i <= str[pos] - '0'; i++) {
            int flg = flag;
            if(i == 3) {
                flg = 1; // contains 3
            }
            if(i == str[pos] - '0') { // next wala bhi restricted rahega
                res += G(str, pos + 1, 1, flg, dp);
            }
            else {
                res += G(str, pos + 1, 0, flg, dp);
            }
        }

        return dp[pos][tight][flag] = res;
    }
    else {
        int res = 0;
        for(int i = 0; i <= 9; i++) {
            int flg = flag;
            if(i == 3) {
                flg = 1;
            }
            res += G(str, pos + 1, 0, flg, dp);
        }
        return dp[pos][tight][flag] = res;
    }

}

int main() {

    int n = 14;

    string s = to_string(n);

    int dp[8][2][2]; // pos, tight, flag
    memset(dp, -1, sizeof(dp)); 

    int x = G(s, 0, 1, 0, dp); // x is the number of reading which contain any digit as 3

    cout<<n - x<<endl;


    return 0;
}