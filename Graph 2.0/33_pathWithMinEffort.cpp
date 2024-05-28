#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main() {

    vector<vector<int>> heights {
        {1, 2, 2},
        {3, 8, 2},
        {5, 3, 5}
    };

    int m = heights.size();
    int n = heights[0].size();

    pair<int, int> src = {0, 0};
    pair<int, int> dest = {m-1, n-1};

    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

    pq.push({0, {0, 0}});

    vector<vector<int>> dist(m, vector<int> (n, 1e9));

    dist[src.first][src.second] = 0;

    int delrow[] = {-1, 0, 1, 0};
    int delcol[] = {0, 1, 0, -1};

    while(!pq.empty()) {
        auto it = pq.top();
        int diff = it.first;
        int row = it.second.first;
        int col = it.second.second;
        pq.pop();

        if(row == m-1 and col == n-1) {
            cout<<diff<<endl;
            return 0;
        }

        for(int i = 0; i < 4; i++) {
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];

            if(nrow >= 0 and nrow < m and ncol >= 0 and ncol < n) {
                int newEffort = max(abs(heights[row][col] - heights[nrow][ncol]), diff);
                if(newEffort < dist[nrow][ncol]) {
                    dist[nrow][ncol] = newEffort;
                    pq.push({newEffort, {nrow, ncol}});
                }
                
            }
        }

    }


    return 0;
}