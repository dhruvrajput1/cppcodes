#include<iostream>
using namespace std;

int main() {

    // print all subarrays

    int arr[] = {1, 2, -10, 3, 4};

    int n = sizeof(arr)/sizeof(int);

    int currentSum = 0;
    int maxSum = 0;

    int left = -1;
    int right = -1;

    for(int i = 0; i < n; i++) {
        for(int j = i; j < n; j++) {
            
            currentSum = 0;

            for(int k = i; k <= j; k++) {
                currentSum += arr[k];
            }
            if(currentSum > maxSum) {
                maxSum = currentSum;
                left = i;
                right = j;
            }
        }
    }

    cout<<maxSum<<endl;

    // subarray of maxSum
    for(int i = left; i <= right; i++) {
        cout<<arr[i]<<" ";
    }

    return 0;
}