#include<iostream>
using namespace std;

void pattern(char arr[100][100], int row, int col){
    int sr = 0, er = row-1, sc = 0, ec = col-1;

    char ch = 'X';

    while(sr <= er and sc <= ec){

        for(int i = sc; i <= ec; i++){
            arr[sr][i] = ch;
            
        }
        sr++;

        for(int j = sr; j <= er; j++){
            arr[j][ec] = ch;
           
        }
        ec--;

        for(int k = ec; k >= sc; k--){
            arr[er][k] = ch;
        
        }
        er--;

        for(int l = er; l >= sr; l--){
            arr[l][sc] = ch;
            
        }
        sc++;

        if(ch == 'X'){
            ch = 'O';
        }
        else{
            ch = 'X';
        }
    }
}

int main() {                                                
    char arr[100][100];
    int row, col;
    cin>>row>>col;

    pattern(arr, row, col);

    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }

}