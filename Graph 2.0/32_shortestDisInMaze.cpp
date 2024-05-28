#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int main() {

    vector<vector<int>> grid {
        {1, 1, 1, 1},
        {1, 1, 0, 1},
        {1, 1, 1, 1},
        {1, 1, 0, 0},
        {1, 0, 0, 0}
    };

    pair<int, int> src = {0, 1};
    pair<int, int> des = {2, 2};

    if(src.first == des.first and src.second == des.second) {
        cout<<0;
        return 0;
    }

    int m = grid.size();
    int n = grid[0].size();

    vector<vector<int>> dist (m, vector<int> (n, 1e9));

    dist[0][1] = 0;

    queue<pair<int, pair<int, int>>> q;

    q.push({0, {src.first, src.second}});

    int delrow[] = {-1, 0, 1, 0};
    int delcol[] = {0, 1, 0, -1};

    while(!q.empty()) {
        auto it = q.front();
        int dis = it.first;
        int r = it.second.first;
        int c = it.second.second;
        q.pop();

        for(int i = 0; i < 4; i++) {
            int nrow = r + delrow[i];
            int ncol = c + delcol[i];

            if(nrow >= 0 and nrow < m and ncol >= 0 and ncol < n and grid[nrow][ncol] == 1 and dist[nrow][ncol] > dis + 1) {
                dist[nrow][ncol] = 1 + dis;
            }

            if(nrow == des.first and ncol == des.second) { // reached the destination 
                cout<< dis +  1;
                return 0;
            }
            q.push({dis + 1, {nrow, ncol}});
        }


    }

    cout<<-1<<endl;

    return 0;
}