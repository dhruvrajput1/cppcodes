#include<iostream>
using namespace std;

int ways(int i, int j){
    // base case
    if(i == 0 and j == 0){
        return 1;
    }
    if(i < 0){
        return 0;
    }
    if(j < 0){
        return 0;
    }


    // recursive case
    return ways(i, j-1) + ways(i-1, j);
}

int main(){
    int N, M; cin>>N>>M;

    // int arr[1000][1000];

    cout<<ways(N, M);

    return 0;
}