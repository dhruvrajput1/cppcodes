#include<iostream>
using namespace std;

int count = 0;
bool kyaMaiQueenDaalSaktaHu(int board[100][100], int i, int j, int N){
    // row
    for(int k = 0; k < N; k++){
        if(board[i][k] == 1){
            return false;
        }
    }

    // column
    for(int k = 0; k < N; k++){
        if(board[k][j] == 1){
            return false;
        }
    }


    // left diagonal
    int m = i;
    int n = j;
    while(m >= 0 and n >= 0){
        if(board[m][n] == 1){
            return false;
        }
        m--;
        n--;
    }

    // right diagonal
    int k = i;
    int l = j;
    while(k >= 0 and l < N){
        if(board[k][l] == 1){
            return false;
        }
        k--;
        l++;
    }

    return true;


}

bool NQueen(int board[100][100], int N, int i){
    // base case
    if(i == N){
        for(int a = 0; a < N; a++){
            for(int b = 0; b < N; b++){
                if(board[a][b] == 1){
                    cout<<"Q ";
                }
                else{
                    cout<<"- ";
                }
                
            }
            cout<<endl;
            
        }
        count++;
        cout<<endl;
        return false;
    }


    // recursive case
    for(int j = 0; j < N; j++){
        if(kyaMaiQueenDaalSaktaHu(board, i, j, N) == true){
            board[i][j] = 1;
            if(NQueen(board, N, i+1) == true){ // can we place the queen in the next row ?
                return true;
            }
            
            board[i][j] = 0;
        }
    }
    return false;
}

int main(){
    int N;
    cin>>N;
    int board[100][100] = {0};

    NQueen(board, N, 0);
    cout<<count<<endl;
}