#include<iostream>
using namespace std;

int main() {

    int arr[] = {4, 5, 1, 2, 3};
    int key = 2;

    int n = sizeof(arr)/sizeof(int);

    int s = 0;
    int e = n-1;

    while(s <= e) {
        int mid = (s+e)/2;

        if(arr[mid] == key) {
            cout<<mid<<endl;
            break;
        }

        if(arr[0] <= arr[mid]) { // checking if left part is sorted or not
            if(key >= arr[s] and key < arr[mid]) { // checking if key lies in left part of array or not
                e = mid - 1;
            }
            else {
                s = mid + 1;
            }
        }
        else { // right part is sorted
            if(key > arr[mid] and key <= arr[e]) { // checking if key lies in right part of array or not
                s = mid + 1;
            }
            else {
                e = mid - 1;
            }
        }

    }

    return 0;
}