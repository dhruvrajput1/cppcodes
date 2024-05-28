#include<iostream>
using namespace std;

bool isSafe(int board[][10], int i, int j, int n) {
    // row
    for(int k = 0; k < n; k++) {
        if(board[i][k] == 1) {
            return false;
        }
    }

    // column
    for(int k = 0; k < n; k++) {
        if(board[k][j] == 1) {
            return false;
        }
    }

    // left diagonal
    int m = i;
    int p = j;

    while(m >= 0 and p >= 0) {
        if(board[m][p] == 1) {
            return false;
        }
        m--;
        p--;
    }

    // right diagonal

    int k = i;
    int l = j;

    while(k >= 0 and j < n) {
        if(board[k][l] == 1) {
            return false;
        }
        k--;
        l++;
    }

    return true;

}

bool nQueenSolve(int board[][10], int i, int n) {
    // base case
    if(i == n) {
        for(int a = 0; a < n; a++) {
            for(int b = 0; b < n; b++) {
                if(board[a][b] == 1) {
                    cout<<"Q ";
                }
                else {
                    cout<<"_ ";
                }
            }
            cout<<endl;
        }
        cout<<endl;
        return false;
    }

    // recursive case
    for(int j = 0; j < n; j++) {
        if(isSafe(board, i, j, n)) {
            // place the queen assuming i, j is the correcet position
            board[i][j] = 1;
            if(nQueenSolve(board, i + 1, n)) {
                return true;
            }

            // if code comes here, means i, j is not the correct position, means assumption is wrong
            board[i][j] = 0; // backtrack
        }
    }

    //  if code comes here, means we have tried all the positions in the current row and coudln't place queen
    return false;
}

int main() {

    int n ;
    cin>>n;

    int board[10][10] = {0};

    nQueenSolve(board, 0, n);

    return 0;
}