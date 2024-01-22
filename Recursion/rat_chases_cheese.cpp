#include<iostream>
using namespace std;

bool ratChaseCheese(char maze[1000][1000], int N, int M, int i, int j, int sol[1000][1000]){
    // base case
    
    if(i == N-1 and j == M-1){
		sol[i][j] = 1;
        for(int k = 0; k < N; k++){
            for(int l = 0; l < M; l++){
                cout<<sol[k][l]<<" ";
            }
            cout<<endl;
        }
        return true;
    }


    // recursive case
    // down
	sol[i][j] = 1;
    if(j < M and maze[i][j+1] != 'X'){
        sol[i][j+1] = 1;
        if(ratChaseCheese(maze, N, M, i, j+1, sol) == true){
            return true;
        }
        sol[i][j+1] = 0;
    }
    // right
    if(i < N and maze[i+1][j] != 'X'){
        sol[i+1][j] = 1;
        if(ratChaseCheese(maze, N, M, i+1, j, sol) == true){
            return true;
        }
        sol[i+1][j] = 0;
    }
	
    return false;
	
}

int main(){
    int N, M;
    cin>>N>>M;
    char maze[1000][1000];
    int sol[1000][1000] = {0};
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin>>maze[i][j];
        }
    }

    if(ratChaseCheese(maze, N, M, 0, 0, sol) == false){
		cout<<"NO PATH FOUND"<<endl;
	}

}