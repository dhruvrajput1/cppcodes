#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main() {

    vector<vector<int>> grid {
        {2, 1, 1},
        {1, 1, 0},
        {0, 1, 1}
    };

    int m = grid.size();
    int n = grid[0].size();

    queue<pair<pair<int, int>, int>> q;

    vector<vector<int>> visited(m, vector<int> (n, 0));


    for(int i = 0; i < m; i++) { // push all the indexes of rotten oranges in queue
        for(int j = 0; j < n; j++) {
            if(grid[i][j] == 2) {
                q.push({{i, j}, 0});
                visited[i][j] = 2;
            }
            else {
                visited[i][j] = 0;
            }
        } 
    }

    int delrow[] = {-1, 0, 1, 0};
    int delcol[] = {0, 1, 0, -1};
    int time = 0;

    while(!q.empty()) {

        int r = q.front().first.first;
        int c = q.front().first.second;
        int t = q.front().second;

        time = max(t, time);
        q.pop();

        for(int i = 0; i <= 3; i++) {
            int nrow = r + delrow[i];
            int ncol = c + delcol[i];

            if(nrow >= 0 and nrow < m and ncol >= 0 and ncol < n and visited[nrow][ncol] == 0 and grid[nrow][ncol] == 1) {
                q.push({{nrow, ncol}, t+1});
                visited[nrow][ncol] = 1;
            }
        }

    }

    cout<<time<<endl;



    return 0;
}