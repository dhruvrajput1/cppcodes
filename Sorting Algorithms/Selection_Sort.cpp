#include<iostream>
using namespace std;

int main(){
    
    // selection sort algorithm

    int arr[] = {5, 2, 1, 3, 4};

    int N = sizeof(arr)/sizeof(int);

    for(int pos = 0; pos < N-1; pos++){
        int min = pos;
        for(int j = pos + 1; j < N; j++){  // this loop will give us the smallest element
            if(arr[j] < arr[min]){
                min = j;
            }
        }
        swap(arr[pos], arr[min]);
    }

    for(int i = 0; i < N; i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}