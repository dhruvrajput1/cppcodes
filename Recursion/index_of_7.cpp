#include<iostream>
using namespace std;

int firstIndexOf7(int arr[], int N, int i){
    
    if(i == N){
        return -1;
    }
    int idx;

    if(arr[i] == 7){
        idx = i;
    }
    firstIndexOf7(arr, N, i+1);

    return idx;
}

int main(){

    int arr[] = {1, 4, 6, 7, 7, 9};
    int N = sizeof(arr)/sizeof(int);

    int index = firstIndexOf7(arr, N, 0);
    
    if(index == -1){
        cout<<"7 is not present"<<endl;
    }
    else{
        cout<<"7 is present at index "<<index<<endl;
    }

    return 0;
}