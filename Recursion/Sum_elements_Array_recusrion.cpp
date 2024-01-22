#include<iostream>
using namespace std;

int sumOfArray(int *arr, int N){

    if(N == 1){
        return arr[0];
    }

    return arr[0] + sumOfArray(arr+1, N-1);
}

int main(){
    int arr[] = {1, 4, 7, 9, 11, 54};
    int N = sizeof(arr)/sizeof(int);

    
    cout<<"Sum of all elements of array is: "<<sumOfArray(arr, N)<<endl;

    return 0;
}