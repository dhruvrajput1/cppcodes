#include<iostream>
#include<vector>
using namespace std;

int main() {

    vector<int> nums {3, 4, 5, 1, 2};

    int n = nums.size();

        int s = 0;
        int e = n-1;
        int ans = 1e9;
 
        while(s <= e) {
            int mid = s + (e-s)/2;

            // check if the array is already sorted
            if(nums[s] <= nums[e]) {
                ans = min(ans, nums[s]);
                break;
            }

            if(nums[s] <= nums[mid]) { // left part is sorted
                // take the minimum from left part and go to right part
                ans = min(ans, nums[s]);
                s = mid + 1;
            }
            else { // right part is sorted
                // take the minimum(nums[mid]) and go to left part
                ans = min(ans, nums[mid]);
                e = mid - 1;
            }
        }

        cout<< ans;


    return 0;
}