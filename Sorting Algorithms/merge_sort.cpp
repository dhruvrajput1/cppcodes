#include<iostream>
using namespace std;

void mergeTwoSortedArray(int* arr, int s, int e){
    
    int mid = (s + e)/2;

    int i = s; int j = mid + 1; int k = s;

    int temp[1000];

    while(i <= mid and j <= e){
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

    while(i <= mid){
        temp[k] = arr[i];
        i++;
        k++;
    }

    while(j <= e){
        temp[k] = arr[j];
        j++;
        k++;
    }

    for(int l = s; l <= e; l++){
        arr[l] = temp[l];
    }

}

void mergeSort(int* arr, int s, int e){
    // base case
    if(s == e){
        return ;
    }

    // recursive case

    int mid = (s + e)/2;

    mergeSort(arr, s, mid);

    mergeSort(arr, mid + 1, e);

    mergeTwoSortedArray(arr, s, e);


}

int main(){

    int n; cin>>n;

    int arr[1000];

    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }

    mergeSort(arr, 0, n-1);

    for(int i = 0; i < n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    return 0;
}