#include<iostream>
#include<climits>
using namespace std;

int maxSum(int* arr, int n) {
    
    int currSum = 0;
    int maxSum = INT_MIN;

    for(int i = 0; i < n; i++) {
        currSum = currSum + arr[i];

        if(currSum > maxSum) {
            maxSum = currSum;
        }
        if(currSum < 0) {
            currSum = 0;
        }
    }

    return maxSum;
}

int main() {

    int arr[] = {5, -1, 4, 2, -5, -1, 3};

    int n = sizeof(arr)/sizeof(int);

    cout<<maxSum(arr, n)<<endl;


    return 0;
}