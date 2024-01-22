#include<iostream>
using namespace std;
int main(){
    int N; cin>>N;
    int arr[N];
    for(int i = 0; i <= N-1; i++){
        cin>>arr[i];
    }
    for(int i = 0; i <= N-2; i++){
        for(int j = 0; j <= N-2-i; j++){
            if(arr[j] > arr[j+1]){
            int t = arr[j];
            arr[j] = arr[j+1];
            arr[j+1] = t;
            }
        }
    }
    for(int k = 0; k <= N-1; k++){
        cout<<arr[k]<<" ";
    }
    
    return 0;
}