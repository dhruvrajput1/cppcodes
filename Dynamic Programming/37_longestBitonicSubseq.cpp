#include<iostream>
#include<vector>
using namespace std;

int main() {

    vector<int> nums {1, 11, 2, 10, 4, 5, 2, 1};

    int n = nums.size();

    vector<int> dp1(n, 1);
    vector<int> dp2(n, 1);

    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < i; j++) {
            if(nums[j] < nums[i]) {
                dp1[i] = max(dp1[i], dp1[j] + 1);
            }
        }
    }

    for(int i = n-1; i >= 0; i--) {
        for(int j = n-1; j > i; j--) {
            if(nums[j] < nums[i]) {
                dp2[i] = max(dp2[i], dp2[j] + 1);
            }
        }
    }

    vector<int> bitonic(n);

    int maxi = 0;

    for(int i = 0; i < n; i++) {
        bitonic[i] = dp1[i] + dp2[i] - 1;
        maxi = max(maxi, bitonic[i]);
    }

    cout<<maxi<<endl;


    return 0;
}