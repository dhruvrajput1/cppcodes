#include<iostream>
using namespace std;

void heapify(int arr[], int n, int i) {

    int largest = i;
    int leftChild = 2*i;
    int rightChild = 2*i + 1;

    if(leftChild <= n and arr[largest] < arr[leftChild]) {
        largest = leftChild;
    }

    if(rightChild <= n and arr[largest] < arr[rightChild]) {
        largest = rightChild;
    }

    if(largest != i) {
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }

}

void heapSort(int arr[], int n) {

    int size = n;

    while(size > 1) {
        swap(arr[1], arr[size]);

        size--;

        heapify(arr, size, 1);
    }

}

// for 0 based indexing
// void heapSort(int* arr, int n) {
//     for(int i = n/2 - 1; i >= 0; i--) {
//         heapify(arr, n, i);
//     }

//     for(int i = n - 1; i >= 0; i--) {
//         swap(arr[0], arr[i]);
//         heapify(arr, i, 0);
//     }
// }

int main() {

    int arr[] = {-1, 54, 53, 55, 52, 50};

    int n = 5;

    for(int i = n/2; i > 0; i--) {
        heapify(arr, n, i);
    }

    heapSort(arr, n);

    for(int i = 1; i <= n; i++) {
        cout<<arr[i]<<" ";
    }

    return 0;
}