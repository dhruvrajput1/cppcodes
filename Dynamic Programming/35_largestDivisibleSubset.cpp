#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {

    vector<int> nums {1, 16, 7, 8, 4};

    int n = nums.size();

    sort(nums.begin(), nums.end());

    vector<int> dp(n, 1);

    int maxi = 1;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < i; j++) {
            if(nums[i] % nums[j] == 0 and dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1;
            }  
            maxi = max(maxi, dp[i]);
        }
    }

    cout<<maxi<<endl;

    return 0;
}