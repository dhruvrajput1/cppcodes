#include <iostream>
using namespace std;

// 2nd approach

int cnt = 0;

bool ratInMaze(char maze[20][20], int sol[][20], int i, int j, int m, int n) {
    // base case
    if(i == m - 1 and j == n - 1) {
        sol[m][n] = 1;
        // printing the solution matrix
        for(int l = 0; l < m; l++) {
            for(int k = 0; k < n; k++) {
                cout<<sol[l][k]<<" ";
            }
            cout<<endl;
        }
        cnt++;
        cout<<endl;
        return true;
    }

    // rat should be inside the grid
    if(i > m or j > n) {
        return false;
    }

    if(maze[i][j] == 'X') {
        return false;
    }

    // recursive case

    // assume solution exists through current cell
    sol[i][j] = 1;

    bool rightSuccess = ratInMaze(maze, sol, i, j + 1, m, n);
    bool downSuccess = ratInMaze(maze, sol, i + 1, j, m, n);

    // backtracking
    sol[i][j] = 0;

    if(rightSuccess or downSuccess) {
        return true;
    }

    return false;

}

int main() {
    
    char maze[20][20] = {
		"OOOO",
		"OOXO",
		"OOOX",
		"OXOO"
    };

    int sol[20][20] = {0};

    int m = 4;
    int n = 4;

    bool ans = ratInMaze(maze, sol, 0, 0, m, n);

    if(ans == false) {
        cout<<"Solution doesn't exists"<<endl;
    }

    cout<<"Total number of combinations are "<<cnt<<endl;
    
    return 0;
}
