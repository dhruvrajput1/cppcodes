#include <iostream>
#include <vector>
using namespace std;

int findKthPositive(vector<int> &arr, int k) {

    int n = arr.size();

    for (int i = 0; i < n; i++) {
        if (arr[i] <= k)
            k++;
        else
            break;
    }

    return k;
}

int findKthPositiveBinarySearch(vector<int>& arr, int k) {

    int n = arr.size();

    int s = 0;
    int e = n-1;

    while(s <= e) {
        int mid = s + (e - s)/2;

        int missing = arr[mid] - (mid + 1);

        if(missing < k) {
            s = mid + 1;
        }
        else {
            e = mid - 1;
        }
    }

    return s + k; // instead of return arr[e] + more;;; more = k-missing and missing = arr[e] - (e+1)
        
}

int main() {

    vector<int> nums{2, 3, 4, 7, 11};

    int k = 5;

    cout <<findKthPositive(nums, k) << endl;

    return 0;
}