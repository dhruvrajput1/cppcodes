#include<iostream>
using namespace std;

void spiralPrint(int arr[100][100], int row, int col){
    int start_row = 0, end_row = row - 1;
    int start_col = 0, end_col = col - 1;

    int count = 0;

    while(start_row <= end_row or start_col <= end_col){

        for(int i = start_col; i <= end_col; i++){
            cout<<arr[start_row][i]<<", ";
            count++;
            if(count == row*col){
                return;
            }
        }
        start_row++;

        for(int j = start_row; j <= end_row; j++){
            cout<<arr[j][end_col]<<", ";
            count++;
            if(count == row*col){
                return;
            }
        }
        end_col--;

        for(int k = end_col; k >= start_col; k--){
            cout<<arr[end_row][k]<<", ";
            count++;
            if(count == row*col){
                return;
            }
        }
        end_row--;

        for(int l = end_row; l >= start_row; l--){
            cout<<arr[l][start_col]<<", ";
            count++;
            if(count == row*col){
                return;
            }
        }
        start_col++;
    }

}

int main(){
    
    int arr[100][100];
    int row, col;
    cin>>row>>col;

    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            cin>>arr[i][j];
        }
    }

    spiralPrint(arr, row, col);

    return 0;
}
