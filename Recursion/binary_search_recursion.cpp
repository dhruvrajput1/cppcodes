#include<iostream>
using namespace std;

int binarySearch(int arr[], int start, int end, int key){   
    // base case
    if(start > end){
        return -5;
    }

    // recursive case
    int mid = (start + end)/2;
    
        if(arr[mid] == key){
            return mid;
        }
        else if(key > arr[mid]){
            binarySearch(arr, mid+1, end, key);
        }
        else{
            binarySearch(arr, start, mid, key);
        }   
    
    
}   

int main(){
    int N;
    cin>>N;
    int arr[N];
    
    for(int i = 0; i <= N-1; i++){
        cin>>arr[i];
    }

    int key;
    cin>>key;

    cout<<binarySearch(arr, 0, N-1, key)<<endl;
}