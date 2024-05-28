#include<iostream>
#include<vector>
using namespace std;

int maxSumSpaceOpt(vector<int> nums) {

    int n = nums.size();

    int prev = nums[0];
    int prev2 = 0;

    for(int i = 1; i < n; i++) {
        int pick = nums[i] + prev2;
        int notPick = prev;

        int curr = max(pick, notPick);

        prev2 = prev;
        prev = curr;
    }

    return prev;
}

int main() {

    vector<int> nums{2, 3, 2};

    vector<int> temp1;
    vector<int> temp2;

    int n = nums.size();

    for(int i = 0; i < n; i++) {
        if(i != 0) {
            temp1.push_back(nums[i]);
        }
        if(i != n-1) {
            temp2.push_back(nums[i]);
        }
    }

    cout<<max(maxSumSpaceOpt(temp1), maxSumSpaceOpt(temp2));

    return 0;
}