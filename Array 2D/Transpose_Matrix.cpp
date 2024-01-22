#include<iostream>
using namespace std;

#define M 3
#define N 4


void transpose(int A[][N], int B[][M]){

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            B[i][j] = A[j][i];
        }
    }
}

int main(){

    int A[M][N];
    

    for(int i = 0; i < M; i++){
        for(int j = 0; j < N; j++){
            cin>>A[i][j];
        }
    }

    int B[N][M];

    transpose(A, B);

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cout<<B[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}