#include<iostream>
using namespace std;

bool is7presentOrNot(int arr[], int N){
    // base case
    if (N == 0){ // 7 mila nahi
        return false;
    }

    if(arr[0] == 7){
        return true;
    }
    // if(is7presentOrNot(arr+1, N-1) == true){
    //     return true;
    // }
    // return false;
    return is7presentOrNot(arr+1, N-1);

}

int main(){

    int arr[] = {6, 8, 4, 7, 9};
    int N = sizeof(arr)/sizeof(int);

    if(is7presentOrNot(arr, N)){
        cout<<"7 is present";
    }
    else{
        cout<<"7 is not present";
    }
 
    return 0;
}