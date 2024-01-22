#include<iostream>
using namespace std;

void bubbleSort(int arr[], int n, int i, int j){
    // base case
    if(i == n-1){
        return ;
    }

    if(j == n-i-1){
        bubbleSort(arr, n, i+1, 0);
    }

    // recursive case
    else{
        if(arr[j] > arr[j+1]){
        swap(arr[j], arr[j+1]);
        }
        bubbleSort(arr, n, i, j+1);
    }
    
}

int main(){ 

    int arr[100];

    int n; cin>>n;

    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }

    bubbleSort(arr, n, 0, 0);

    for(int i = 0; i < n; i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}