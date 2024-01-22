#include<iostream>
using namespace std;

void mergetwoSortedArrays(int* arr, int st, int end){
    int mid = (st + end)/2;
    int i = st;
    int j = mid +1;
    int k = st;
    int temp[1000];

    while (i <= mid and j <= end){
        if(arr[i] < arr[j]){
            temp[k] = arr[i];
            i++;
            k++;
        }
        else{
            temp[k] = arr[j];
            j++;
            k++;
        }
    }
    while (i <= mid){
        temp[k] = arr[i];
        i++;
        k++;
    }
    while(j <= end){
        temp[k] = arr[j];
        j++;
        k++;
    }

    for(int l = st; l <= end; l++){
        arr[l] = temp[l];
    }
    
}

void mergeSort(int *arr, int st, int end){

    // base case
    if(st == end){
        return;
    }

    // divide
    int mid = (st + end)/2;


    // sort
    mergeSort(arr, st, mid); // recursion // 1 2 4
    mergeSort(arr, mid+1, end);// 3 5 

    // merge sorted arrays
    mergetwoSortedArrays(arr, st, end); // 1 2 3 4 5
}

int main(){

    int arr[] = {4, 2, 1, 5, 3};
    int N = sizeof(arr)/sizeof(int);

    mergeSort(arr, 0, N-1);

    for(int k = 0; k <= N-1; k++){
        cout<<arr[k]<<" ";
    }
 
    return 0;
}