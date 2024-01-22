#include<iostream>
using namespace std;

class heap {
public:

    int arr[100];
    int size;

    heap() {
        size = 0;
    }

    void insert(int val) {
        size = size + 1;
        
        int index = size;

        arr[index] = val;

        while(index > 1) {
            int parent = index/2;

            if(arr[index] > arr[parent]) {
                swap(arr[index], arr[parent]);
                index = parent;
            }
            else {
                return ;
            }
        }

    }

    void print() {
        for(int i = 1; i <= size; i++) {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }

    void deleteFromHeap() {
        if(size == 0) {
            return ;
        }

        // step 1- put last element into first element
        arr[1] = arr[size];

        // step 2- remove last element
        size--;

        // step 3 - take first element to its correct position
        int i = 1;
        while(i < size) {
            int leftChildIndex = 2*i;
            int rightChildIndex = 2*i + 1;

            if(arr[i] < arr[leftChildIndex] and leftChildIndex < size) {
                swap(arr[i], arr[leftChildIndex]);
                i = leftChildIndex;
            }
            if(arr[i] < arr[rightChildIndex] and rightChildIndex < size) {
                swap(arr[i], arr[rightChildIndex]);
                i = rightChildIndex;
            }
            else {
                return ;
            }
        }

    }

};

void heapify(int* arr, int n, int i) {
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
        // step 1- swap
        swap(arr[1], arr[size]);
        size--;

        // step 2 - heapify
        heapify(arr, size, 1);
    }

}

int main() {

    heap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);   
    h.insert(52); 
    h.insert(54);

    // h.print(); 

    h.deleteFromHeap();

    // h.print(); 

    int arr[] = {-1, 54, 53, 55, 52, 50};

    int n = sizeof(arr)/sizeof(int) - 1;

    for(int i = n/2; i > 0; i--) {
        heapify(arr, n, i);
    }

    for(int i = 1; i <= n; i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    cout<<"Sorted Array"<<endl;
    heapSort(arr, n);

    for(int i = 1; i <= n; i++) {
        cout<<arr[i]<<" ";
    }

    return 0;
}