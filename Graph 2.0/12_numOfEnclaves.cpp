#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main() {

    vector<vector<int>> grid {
        {0, 0, 0, 1, 1},
        {0, 0, 1, 1, 0},
        {0, 1, 0, 0, 0},
        {0, 1, 1, 0, 0},
        {0, 0, 0, 1, 1}
    };

    int m = grid.size();
    int n = grid[0].size();

    vector<vector<int>> vis (m, vector<int> (n, 0));

    queue<pair<int, int>> q;

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(i == 0 or i == m-1 or j == 0 or j == n-1) {
                if(grid[i][j] == 1) {
                    vis[i][j] = 1;
                    q.push({i, j});
                }
            }
        }
    }

    int delrow[] = {-1, 0, 1, 0};
    int delcol[] = {0, 1, 0, -1};

    while(!q.empty()) {
        int row = q.front().first;
        int col = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++) {
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];

            if(nrow >= 0 and nrow < m and ncol >= 0 and ncol < n and grid[nrow][ncol] == 1 and vis[nrow][ncol] == 0) {
                vis[nrow][ncol] = 1;
                q.push({nrow, ncol});
            }

        }

    }

    int cnt = 0;

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(grid[i][j] == 1 and vis[i][j] == 0) {
                cnt++;
            }
        }
    }

    cout<<cnt<<endl;


    return 0;
}