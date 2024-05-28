#include<iostream>
#include<vector>
using namespace std;

int waysForTrue(string expression, int i, int j, int isTrue, vector<vector<vector<int>>>& dp) {
    // Base case
    if (i > j) {
        return 0;
    }
    if (i == j) {
        if (isTrue == 1) {
            return expression[i] == 'T';
        } else {
            return expression[i] == 'F';
        }
    }
    if(dp[i][j][isTrue] != -1) {
        return dp[i][j][isTrue];
    }


    // base case
    int ways = 0;

    for (int k = i + 1; k <= j - 1; k = k + 2) {
        int leftTrue = waysForTrue(expression, i, k - 1, 1, dp);
        int leftFalse = waysForTrue(expression, i, k - 1, 0, dp);
        int rightTrue = waysForTrue(expression, k + 1, j, 1, dp);
        int rightFalse = waysForTrue(expression, k + 1, j, 0, dp);

        if (expression[k] == '&') {
            if (isTrue) {
                ways += leftTrue * rightTrue;
            } else {
                ways += leftTrue * rightFalse + leftFalse * rightTrue + leftFalse * rightFalse;
            }
        } else if (expression[k] == '|') {
            if (isTrue) {
                ways += leftTrue * rightTrue + leftTrue * rightFalse + leftFalse * rightTrue;
            } else {
                ways += leftFalse * rightFalse;
            }
        } else {
            if (isTrue) {
                ways += leftTrue * rightFalse + leftFalse * rightTrue;
            } else {
                ways += leftTrue * rightTrue + leftFalse * rightFalse;
            }
        }
    }

    return dp[i][j][isTrue] = ways;
}

int main() {

    string expression = "T|T&F";

    int n = expression.size();

    vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(2, -1)));

    cout << waysForTrue(expression, 0, n - 1, 1, dp);

    return 0;
}
