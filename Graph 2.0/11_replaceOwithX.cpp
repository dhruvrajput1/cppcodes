#include<iostream>
#include<vector>
using namespace std;

void dfs(int row, int col, vector<vector<char>> &grid, vector<vector<int>> &vis, int delrow[], int delcol[]) {

    vis[row][col] = 1;

    int m = grid.size();
    int n = grid[0].size();

    for(int i = 0; i < 4; i++) { // checking for neighbours
        int nrow = row + delrow[i];
        int ncol = col + delcol[i];

        if(nrow >= 0 and nrow < m and ncol >= 0 and ncol < n and grid[nrow][ncol] == 'O' and vis[nrow][ncol] == 0) {
            dfs(nrow, ncol, grid, vis, delrow, delcol);
        }
    }

}

int main() {

    vector<vector<char>> grid {
        {'X', 'X', 'X', 'X','X'},
        {'X', 'O', 'O', 'X', 'O'},
        {'X','X', 'O', 'X', 'O'},
        {'X', 'O', 'X', 'O', 'X'},
        {'O', 'O', 'X', 'X', 'X'}
    };

    int m = grid.size();
    int n = grid[0].size();

    vector<vector<int>> vis (m, vector<int> (n, 0));

    int delrow[] = {-1, 0, 1, 0};
    int delcol[] = {0, 1, 0, -1};

    // we have to check only the boundaries

    for(int i = 0; i < m; i++) {
        if(grid[i][0] == 'O' and vis[i][0] == 0) {
            dfs(i, 0, grid, vis, delrow, delcol);
        }
    }

    for(int j = 0; j < n; j++) {
        if(grid[m-1][j] == 'O' and vis[m-1][j] == 0) {
            dfs(m-1, j, grid, vis, delrow, delcol);
        }
    }

    for(int i = 0; i < m; i++) {
        if(grid[i][n-1] == 'O' and vis[i][n-1] == 0) {
            dfs(i, n-1, grid, vis, delrow, delcol);
        }
    }

    for(int j = 0; j < n; j++) {
        if(grid[0][j] == 'O' and vis[0][j] == 0) {
            dfs(0, j, grid, vis, delrow, delcol);
        }
    }

    // now convert the remaining O's to X's

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++ ){
            if(vis[i][j] == 0 and grid[i][j] == 'O') {
                grid[i][j] = 'X';
            }
        }
    }

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++ ){
            cout<<grid[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}