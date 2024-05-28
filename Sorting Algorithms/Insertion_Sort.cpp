#include<iostream>
using namespace std;

int main(){

    int arr[] = {5, 2, 4, 6, 1, 3};

    int N = sizeof(arr)/sizeof(int);

    for(int i = 1; i < N; i++){
        int current = arr[i];
        int j = i - 1;

        while(arr[j] > current and j >= 0){ // taking current to its correct position
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = current;
    }

    for(int i = 0; i < N; i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}