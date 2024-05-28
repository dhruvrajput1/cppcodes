#include<iostream>
#include<map>
#include<vector>
using namespace std;

int subarraySum(vector<int> &nums, int k) {

    map<int, int> m; // prefixSum, cnt
    int prefixSum = 0;
    int cnt = 0;

    m[0] = 1;

    int n = nums.size();

    for(int i = 0; i < n; i++) {

        prefixSum += nums[i];
        int lookFor = prefixSum - k;
        cnt = cnt + m[lookFor];
        m[prefixSum]++;
    }

    return cnt;

}

int main() { // count the number of subarrays with sum == k

    vector<int> nums {1, 2, 1, 2, 1};

    int k = 3;

    cout<<subarraySum(nums, k)<<endl;


    return 0;
}