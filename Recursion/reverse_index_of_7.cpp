#include<iostream>
using namespace std;

int indexOf7FromEnd(int *arr, int N, int i){

    if(i < 0){
        return -1;
    }

    if(arr[i] == 7){
        return i;
    }
    indexOf7FromEnd(arr, N, i-1);
}

int main(){

    int arr[] = {1, 9, 7, 5, 9};
    int N = sizeof(arr)/sizeof(int);

    int index = indexOf7FromEnd(arr, N, N-1);
    
    if(index == -1){
        cout<<"7 is not present"<<endl;
    }
    else{
        cout<<"7 is present at index "<<index<<endl;
    }
    return 0;
}