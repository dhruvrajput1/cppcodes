#include<iostream>
using namespace std;
int main(){
    // Linear Search;
    int N; cin>>N;
    int arr[N];
    for(int i = 0; i <= N-1; i++){
        cin>>arr[i];
    }
    int ans;
    int j;
    int key = 6;
    for(j = 0; j <= N-1; j++){
        if(arr[j] == key){
            ans = j;
            cout<<"Present at "<<ans<<"th index"<<endl;
            return 0;
        }
           
    }

        cout<<"Number is not present"<<endl;
    
    return 0;
}