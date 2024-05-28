#include<iostream>
using namespace std;

int merge(int* arr, int s, int e) {
    
    int mid = (s + e)/2;

    int i = s;
    int j = mid + 1;
    int k = s;

    int cnt = 0;

    int temp[10000];

    while(i <= mid and j <= e) {
        if(arr[i] <= arr[j]) {
            temp[k] = arr[i];
            i++;
            k++;
        }
        else {
            temp[k++] = arr[j++];
            cnt += mid - i + 1;
        }
    }

    while(i <= mid) {
        temp[k++] = arr[i++];
    }

    while(j <= e) {
        temp[k++] = arr[j++];
    }

    // copy all elements back to arr

    for(int l = s; l <= e; l++) {
        arr[l] = temp[l];
    }

    return cnt;

}

int inversionCount(int* arr, int s, int e) {
    // base case
    if(s >= e) {
        return 0;
    }

    // recursive case

    int mid = (s + e)/2;

    int x = inversionCount(arr, s, mid);
    int y = inversionCount(arr, mid + 1, e);

    int z = merge(arr, s, e);

    return x + y + z;
}

int main() {

    int arr[] = {1, 5, 2, 6, 3, 0};

    int n = sizeof(arr)/sizeof(int);

    cout<<inversionCount(arr, 0, n - 1)<<endl;

    return 0;
}