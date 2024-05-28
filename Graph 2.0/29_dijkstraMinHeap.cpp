#include<iostream>
#include<vector>
#include<queue>
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

    int src = 0;

    vector<int> dist (n, 1e9);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

    minHeap.push({0, src});

    dist[src] = 0;

    while(!minHeap.empty()) {
        int distance = minHeap.top().first;
        int node = minHeap.top().second;
        minHeap.pop();

        for(auto it : adjList[node]) {
            int v = it.first;
            int wt = it.second;
            if(dist[v] > distance + wt) {
                dist[v] = dist[node] + wt;
                minHeap.push({dist[v], v});
            }
        }
    }

    for(auto i : dist) {
        cout<<i<<" ";
    }




    return 0;
}


// 8
// 6
// 0 1 4
// 0 2 4
// 1 2 2
// 2 3 3
// 2 4 1
// 2 5 6
// 4 5 3
// 3 5 2