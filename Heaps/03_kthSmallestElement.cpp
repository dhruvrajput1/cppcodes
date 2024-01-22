#include<iostream>
#include<queue>
using namespace std;

int kthSmallestElement(int* arr, int n, int k) {
    
    priority_queue<int> pq;

    // step - 1 - push first k elements to pq
    for(int i = 0; i < k; i++) {
        pq.push(arr[i]);
    }

    // step - 2 insert new element if it is less than pq.top() for rest of the elements
    for(int i = k; i < n; i++) {
        int element = arr[i];

        if(element < pq.top()) {
            pq.pop();
            pq.push(element);
        }
    }

    // step - 3 - ans is root element of tree
    int ans = pq.top();
    return ans;


}

int main() {

    int arr[] = {7, 10, 4, 3, 20, 15};

    int n = sizeof(arr)/sizeof(int);

    int k = 3;

    cout<<kthSmallestElement(arr, n, k)<<endl;

    return 0;
}