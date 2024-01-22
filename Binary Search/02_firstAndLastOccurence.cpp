#include <iostream>
using namespace std;

int firstOccurence(int *arr, int n, int key) {

    int s = 0;
    int e = n - 1;

    int ans = -1;

    while(s <= e) {
        int mid = (s+e)/2;

        if(arr[mid] == key) {
            ans = mid;
            e = mid-1;
        }
        else if(key < arr[mid]) {
            e = mid - 1;
        }
        else {
            s = mid + 1;
        }
    }
    
    return ans;

}

int lastOccurence(int *arr, int n, int key) {

    int s = 0;
    int e = n - 1;

    int ans = -1;

    while(s <= e) {
        int mid = (s+e)/2;

        if(arr[mid] == key) {
            ans = mid;
            s = mid + 1;
        }
        else if(key < arr[mid]) {
            e = mid - 1;
        }
        else {
            s = mid + 1;
        }
    }
    
    return ans;

}

int main() {

    int arr[] = {1, 2, 5, 8, 8, 8, 8, 8, 10, 12, 15, 20};

    int n = sizeof(arr) / sizeof(int);

    int key = 8;

    cout<<firstOccurence(arr, n, key)<<endl;
    cout<<lastOccurence(arr, n, key)<<endl;

    return 0;
}