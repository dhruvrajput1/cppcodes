#include<iostream>
using namespace std;

void makeInverse(int* A, int* inv, int N, int i){
    // base case
    if(i == N){
        return;
    }

    // recursive case
    // int value = A[i];

    // inv[value] = i;

    inv[A[i]] = i;

    makeInverse(A, inv, N, i+1);


}

int main(){
    int N;
    cin>>N;
    int A[N];
    int inv[N];
    for(int i = 0; i < N; i++){
        cin>>A[i];
    }

    makeInverse(A, inv, N, 0);

    for(int i = 0; i < N; i++){
        cout<<inv[i]<<" ";
    }

    return 0;
}