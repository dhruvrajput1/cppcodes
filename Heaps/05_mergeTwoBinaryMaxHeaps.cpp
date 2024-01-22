#include<iostream>
#include<vector>
using namespace std;

void heapify(vector<int> &arr, int n, int i) {
    
    int largest = i;
    int leftChild = 2*i + 1;
    int rightChild = 2*i + 2;

    if(arr[leftChild] > arr[largest] and leftChild <= n) {
        largest = leftChild;
    } 
    if(arr[rightChild] > arr[largest] and rightChild <= n) {
        largest = rightChild;
    }

    if(largest != i) {
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }

}

vector<int> mergeTwoBinaryMaxHeaps(vector<int> a, vector<int> b) {

    vector<int> c;

    for(auto i:a) {
        c.push_back(i);
    }

    for(auto i : b) {
        c.push_back(i);
    }

    int n = c.size();

    for(int i = n/2 - 1; i >= 0; i--) {
        heapify(c, n, i);
    }

    return c;

}

int main() {

    vector<int> a{10, 5, 6, 2};

    vector<int> b{12, 7, 9};

    vector<int> ans = mergeTwoBinaryMaxHeaps(a, b);

    for(auto i : ans) {
        cout<<i<<" ";
    }
    cout<<endl;

    return 0;
}