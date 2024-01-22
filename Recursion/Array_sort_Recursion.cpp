#include<iostream>
using namespace std;

bool isArraySort(int arr[], int N){

    if(N == 1){
        return true;
    }

    if(arr[0] <= arr[1] and isArraySort(arr+1, N-1)){
        return true;
    }
    return false;
}

int main(){
    int arr[] = {1, 4, 2, 6, 8, 9};

    int N = sizeof(arr)/sizeof(int);
    
    if(isArraySort(arr, N)){
        cout<<"Array is sorted"<<endl;
    }
    else{
        cout<<"Array is not sorted"<<endl;
    }

    return 0;
}