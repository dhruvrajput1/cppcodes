#include<iostream>
#include<queue>
#include<vector>
using namespace std;

void bfs(vector<vector<char>> &grid, vector<vector<int>> &vis, int row, int col) {
    vis[row][col] = 1;

    int m = grid.size();
    int n = grid[0].size();

    queue<pair<int, int>> q;

    q.push({row, col});

    while(!q.empty()) {
        int row = q.front().first;
        int col = q.front().second;
        q.pop();

        for(int delrow = -1; delrow <= 1; delrow++) { // iterating over all neighbours
            for(int delcol = -1; delcol <= 1; delcol++) {
                int nrow = row + delrow;
                int ncol = col + delcol;

                if(nrow >= 0 and nrow < m and ncol >= 0 and ncol < n and grid[nrow][ncol] == '1' and vis[nrow][ncol] == 0) {
                    vis[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                }
            }
        }
    }
}

int main() {


    vector<vector<char>> grid { // return the number of islands
        {'0', '1', '1', '0'},
        {'0', '1', '1', '0'},
        {'0', '0', '1', '0'},
        {'0', '0', '0', '0'},
        {'1', '1', '0', '1'}
    };

    int m = grid.size();
    int n = grid[0].size();

    

    vector<vector<int>> vis (m, vector<int> (n, 0));

    int cnt = 0;

    

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(vis[i][j] == 0 and grid[i][j] == '1') {
                cnt++;
                bfs(grid, vis, i, j);
            }
        }
    }

    

    cout<<cnt<<endl;


    return 0;
}