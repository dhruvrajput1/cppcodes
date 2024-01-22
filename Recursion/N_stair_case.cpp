#include<iostream>
using namespace std;

int nStairCase(int N, int k){
    // base case
    if(N == 0){
        return 1;
    }
    else if(N <0){
        return 0;
    }

    // recursive case
    // return nStairCase(N-1) + nStairCase(N-2) + nStairCase(N-3); // ye kaam recursion karega
    int sum = 0;
    for(int i = 1; i <= k; i++){
        sum = sum + nStairCase(N-i, k);
    }

    return sum;
}

int main(){
    int N;
    cin>>N;

    int k; // k is max number of jumps
    cin>>k;

    cout<<"Number of ways: "<<nStairCase(N, k)<<endl;
}