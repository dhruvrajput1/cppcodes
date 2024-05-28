#include<iostream>
#include<vector>
using namespace std;

int main() {

    int n = 4;
    int m = 4;

    vector<vector<int>> edges {
        {0, 1, 3},
        {1, 2, 1},
        {1, 3, 4},
        {2, 3, 1}
    };

    int threshold = 4;

    vector<vector<int>> dist(n, vector<int> (n, 1e9)); // adjacency matrix

    for(auto it : edges) {
        dist[it[0]][it[1]] = it[2];
        dist[it[1]][it[0]] = it[2];
    }

    // creating the adjacency matrix
    for(int i = 0; i < n; i++) dist[i][i] = 0;

    for(int k = 0; k < n; k++) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(dist[i][k] == 1e9 or dist[k][j] == 1e9) continue;
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);  
            }
        }
    }

    int ans = n;
    int cityNo = -1;

    for(int city = 0; city < n; city++) {
        int cnt = 0;
        for(int adjCity = 0; adjCity < n; adjCity++) {
            if(dist[city][adjCity] <= threshold) {
                cnt++;
            }
        }
        if(cnt <= ans) {
            ans = cnt;
            cityNo = city;
        }
    }

    cout<<cityNo<<endl;


    return 0;
}