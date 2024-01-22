#include<iostream>
#include<deque>
using namespace std;

int main() {

    int arr[] = {1, 2, 3, 1, 4, 5, 2, 3, 6};

    int n = sizeof(arr)/sizeof(int);

    int k = 3; // we have to find max among 3 numbers starting from 0th index

    // we have to process first k elements separately
    deque<int> Q(k);

    for(int i = 0; i < k; i++) {

        while(!Q.empty() and arr[i] > arr[Q.back()]) {
            Q.pop_back();
        }
        Q.push_back(i); 

    }

    // process the remaining elements
    for(int i; i < n; i++) {
        cout<<arr[Q.front()]<<" ";

        // 1. remove the elements which are not the part of the window
        while(!Q.empty() and Q.front() <= i - k) {
            Q.pop_front();
        }

        // 2. remove the elements which are not useful and are in window
        while(!Q.empty() and arr[i] >= arr[Q.back()]) {
            Q.pop_back();
        }

        // 3. add the new elements
        Q.push_back(i);

    }



    return 0;
}