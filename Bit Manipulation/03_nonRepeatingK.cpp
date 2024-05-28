#include<iostream>
#include<vector>
using namespace std;

int findUnique(vector<int> &nums, int n, int k) {

    vector<int> count(32, 0);

    // AND(bitwise) each element of the array with each set digit (one at a time) to get the count of set bits at each position
    for(int i = 0; i < 32; i++) {
        for(int j = 0; j < n; j++) {
            if((nums[j] & (1 << i)) != 0) {
                count[i] += 1;
            }
        }
    }

    // now consider all bits whose count is not multiple of k
    int ans = 0;
    int prod = 1;
    for(int i = 0; i < 32; i++) {
        ans = ans + (count[i]%k)*prod;
        prod *= 2;
    }

    return ans;

}

int main() {

    vector<int> nums {2, 2, 1, 5, 1, 1, 2};

    int n = nums.size();
    int k = 3;

    cout<<findUnique(nums, n, k)<<endl;

    return 0;
}