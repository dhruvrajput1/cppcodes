#include<iostream>
using namespace std;

void searchKey(int arr[1000][1000], int row, int col, int key){
    int i = 0;
    int j = col -1;

    int flag = 0;

    while(i < row and j >= 0){
        if(key == arr[i][j]){
            cout<<key<<" is present at index "<<i<<", "<<j<<endl;
            flag = 1;
            break;
        }

        else if(key > arr[i][j]){
            i++;
        }

        else if(key < arr[i][j]){
            j--;
        }
    }
    
    if(flag == 0){
        cout<<"Key is not present"<<endl;
    }

}

int main(){

    int N, M;
    cin>>N>>M;

    int arr[1000][1000];

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin>>arr[i][j];
        }
    }

    int key;
    cin>>key;

    searchKey(arr, N, M, key);
 
    return 0;
}