#include<iostream>
#include<queue>
using namespace std;

int minCost(int* arr, int n) {

    priority_queue<int, vector<int>, greater<int>> pq; // minHeap

    int ans = 0;

    for(int i = 0; i < n; i++) {
        pq.push(arr[i]);
    }

    while(pq.size() > 1) {
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();

        int sum = a + b;

        ans += sum;
        pq.push(sum);
    }

    return ans;
}

int main() {

    int arr[] = {4, 3, 2, 6};
    int n = sizeof(arr)/sizeof(int);

    cout<<minCost(arr, n)<<endl;

    return 0;
}