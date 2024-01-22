#include<iostream>
using namespace std;

int count(int N, int last_digit){
    // base case
    if(N == 1){
        if(last_digit == 0){
            return 1;
        }
        else{
            return 1;
        }
    }


    // recursive case
    if(last_digit == 0){
        return count(N-1, 0) + count(N-1, 1);
    }
    else{
        return count(N-1, 0);
    }
}

int main(){

    int t; cin>>t;

    for(int i = 1; i <= t; i++){
        int N;
        cin>>N;

        cout<<"#"<<i<<" : ";

        int what = count(N, 0) + count(N, 1);
        cout<<what<<endl;
        
    }
    
}