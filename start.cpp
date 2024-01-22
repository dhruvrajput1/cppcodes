#include<iostream>
using namespace std;

int binarySearch(int* arr, int s, int e, int key) {
    int mid = (s + e)/2;

    if(arr[mid] == key) {
        return mid;
    }
    else if(arr[mid] < key) {
        return binarySearch(arr, mid + 1, e, key);
    }
    else {
        return binarySearch(arr, s, mid - 1, key);
    }
}

int main() {

    int arr[] = {1, 2, 4, 5, 9};

    int n = sizeof(arr)/sizeof(int);

    int key = 9;

    cout<<binarySearch(arr, 0, n, key)<<endl;

    return 0;
}