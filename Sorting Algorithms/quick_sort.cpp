#include<iostream>
#include<vector>
using namespace std;

int partition(vector<int>& arr, int s, int e) {

    int pivot = arr[s];

    int cnt = 0; // count the number of elements less than pivot, so that we can place the pivot at its correct position
    for(int i = s + 1; i <= e; i++) {
        if(arr[i] <= pivot) {
            cnt++;
        }
    }

    int pivotIndex = s + cnt;

    // place pivot at right position
    swap(arr[pivotIndex], arr[s]);

    // now make sure that element on left of pivotIndex are less than pivot and on right are greater than pivot
    int i = s;
    int j = e;

    while(i < pivotIndex and j > pivotIndex) {

        while(arr[i] < pivot) {
            i++;
        }
        while(arr[j] > pivot) {
            j--;
        }

        if(i < pivotIndex and j > pivotIndex) {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }

    return pivotIndex;
}

void quickSort(vector<int>& arr, int s, int e) {
    if(s >= e) {
        return ;
    }

    int index = partition(arr, s, e);

    quickSort(arr, s, index - 1);
    quickSort(arr, index + 1, e);
}

int main() {

    vector<int> arr {2, 4, 1, 5, 3};

    int n = arr.size();

    quickSort(arr, 0, n-1);

    for(int i = 0; i < n; i++) {
        cout<<arr[i]<<" ";
    }

    return 0;
}