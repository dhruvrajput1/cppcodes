#include<stdio.h>

int main(){

    int arr[] = {5, 1, 3, 2, 4};
    int N = sizeof(arr)/sizeof(int);

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N - i; j++){
            if(arr[j] > arr[j+1]){
                int t = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = t;
            }
        }
    }

    for(int i = 0; i < N; i++){
        printf("%d ", arr[i]);
    }

    return 0;
}