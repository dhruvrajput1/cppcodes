#include<iostream>
using namespace std;

void rotateImage(int arr[100][100], int sol[100][100], int N){
    int st_r = 0, st_c = 0, end_r = N-1, end_c = N-1;

    while(st_r <= end_r and st_c <= end_c){
        for(int i = 0; i < N; i++){
            sol[st_r][i] = arr[i][end_c];
        }
        end_c--;
        st_r++;
        
    }

}

int main(){
    int N; cin>>N;
    int arr[100][100];
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin>>arr[i][j];
        }
    }
    int sol[100][100];

    rotateImage(arr, sol, N);

    for(int p = 0; p < N; p++){
        for(int q = 0; q < N; q++){
            cout<<sol[p][q]<<" ";
        }
        cout<<endl;
    }
}