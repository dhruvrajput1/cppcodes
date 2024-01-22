#include<iostream>
using namespace std;

int partition(int *arr, int start, int end){
    int pivot = arr[end];
    int k = start -1; // -1


    
    for(int j = start; j < end; j++){
        if(arr[j] <= pivot){
            k++; // k is representing partition
            swap(arr[k], arr[j]);
        }
        
    }

    swap(arr[k+1], pivot);

    return k+1;
}

void quickSort(int* arr, int start, int end){

    // base case
    if(start >= end){
        return ;
    }


    // recursive case

    int index = partition(arr, start, end); // pivot ka index dega

    quickSort(arr, start, index -1);
    quickSort(arr, index +1, end);

}

int main(){

    int N;
    cin>>N;

    int arr[1000];

    for(int i = 0; i < N; i++){
        cin>>arr[i];
    }

    quickSort(arr, 0, N-1);

    for(int i = 0; i < N; i++){
        cout<<arr[i]<<" ";
    }
 
    return 0;
}