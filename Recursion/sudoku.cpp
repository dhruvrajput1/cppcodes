#include<iostream>
#include<math.h>
using namespace std;

bool kyaMaiNumDaalSaktaHu(int mat[9][9], int i, int j, int num, int n){

    // row
    for(int k = 0; k < n; k++){
        if(mat[i][k] == num){
            return false;
        }
    }

    // column
    for(int k = 0; k < n; k++){
        if(mat[k][j] == num){
            return false;
        }
    }

    // square matrix
    int si, sj;
    int chota_N = sqrt(n);
    si = (i/chota_N)*chota_N;
    sj = (j/chota_N)*chota_N;
    for(int l = si; l < si + chota_N; l++){
        for(int k = sj; k < sj + chota_N; k++){
            if(mat[l][k] == num){
                return false;
            }
        }
    }

    return true;
}

bool sudokuSolver(int mat[9][9], int i, int j, int n){
    // base case
    if(i == n){
        for(int k = 0; k < n; k++){
            for(int l = 0; l < n; l++){
                cout<<mat[k][l]<<" ";
            }
            cout<<endl;
        }
        return true;
    }


    // recursive case
    if(j == n){
        sudokuSolver(mat, i+1, 0, n);
    }

    if(mat[i][j] != 0){
        return sudokuSolver(mat, i, j+1, n);
    }

    for(int num = 1; num <= 9; num++){
        if(kyaMaiNumDaalSaktaHu(mat, i, j, num, n) == true){
            mat[i][j] = num;
            if(sudokuSolver(mat, i, j+1, n) == true){
                return true;
            }

            mat[i][j] = 0; // backtrack
        }
    }

    return false;

}

int main(){

    int mat[9][9] = {
        {5,3,0,0,7,0,0,0,0},
		{6,0,0,1,9,5,0,0,0},
		{0,9,8,0,0,0,0,6,0},
		{8,0,0,0,6,0,0,0,3},
		{4,0,0,8,0,3,0,0,1},
		{7,0,0,0,2,0,0,0,6},
		{0,6,0,0,0,0,2,8,0},
		{0,0,0,4,1,9,0,0,5},
		{0,0,0,0,8,0,0,7,9}
    };

    sudokuSolver(mat, 0, 0, 9);

    return 0;
}