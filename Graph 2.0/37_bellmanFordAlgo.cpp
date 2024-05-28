#include<iostream>
#include<vector>
using namespace std;

int main() {

    vector<vector<int>> edges {
        {0, 1, 5},
        {1, 0, 3},
        {1, 2, -1},
        {2, 0, 1}
    };

    int n = 3;
    int m = edges.size();

    int src = 2;

    vector<int> dist(n, 1e8);

    dist[src] = 0;

    for(int i = 0; i < n-1; i++) {
        for(auto it : edges) {
            int u = it[0];
            int v = it[1];
            int wt = it[2];

            if(dist[u] + wt < dist[v]) {
                dist[v] = dist[u] + wt;
            }
        }
    }

    // nth relaxation to check for the negative cycle

    for(auto it : edges) {
        int u = it[0];
        int v = it[1];
        int wt = it[2];

        if(dist[u] + wt < dist[v]) {
            cout<<-1<<endl;
            return 0;
        }
    }

    for(int i = 0; i < n; i++) {
        cout<<dist[i]<<" ";
    }
    cout<<endl;



    return 0;
}