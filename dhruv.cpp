#include<bits/stdc++.h>
using namespace std;

int main() {

    int m, n;
    cin>>m>>n;

    vector<pair<int, int>> adjList[n];

    for(int i = 0; i < m; i++) {
        int u, v, wt;
        cin>>u>>v>>wt;

        adjList[u].push_back({v, wt});
        adjList[v].push_back({u, wt});
    }

    vector<int> dist(n, 1e9);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push({0, 0}); // dist, node

    dist[0] = 0;

    while(!pq.empty()) {
        int dis = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        for(auto it : adjList[node]) {
            int v = it.first;
            int wt = it.second;

            if(dist[v] > dis + wt) {
                dist[v] = dis + wt;
                pq.push({dist[v], v});
            }
        }
    }

    for(int i : dist) {
        cout<<i<<" ";
    }


    return 0;
}