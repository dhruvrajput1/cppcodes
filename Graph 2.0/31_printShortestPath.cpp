#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int main() {

    int m, n;
    cin>>m>>n;

    vector<pair<int, int>> adjList[n+1];

    for(int i = 0; i < m; i++) {
        int u, v, wt;
        cin>>u>>v>>wt;

        adjList[u].push_back({v, wt});
        adjList[v].push_back({u, wt});
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

    vector<int> dist(n+1, 1e9);
    vector<int> parent(n+1);

    int src = 1;
    int dest = 5;

    dist[src] = 0;

    for(int i = 0; i <= n; i++) {
        parent[i] = i;
    }

    minHeap.push({0, src});

    while(!minHeap.empty()) {
        auto it = minHeap.top();
        int dis = it.first;
        int node = it.second;
        minHeap.pop();

        for(auto i : adjList[node]) {
            int adjNode = i.first;
            int wt = i.second;

            if(dis + wt < dist[adjNode]) {
                dist[adjNode] = dis + wt;
                minHeap.push({dis+wt, adjNode});
                parent[adjNode] = node;
            }
        }
    }

    vector<int> path;
    int node = dest;

    while(parent[node] != node) {
        path.push_back(node);
        node = parent[node];
    }
    path.push_back(src);

    reverse(path.begin(), path.end());

    for(int i = 0; i < path.size(); i++) {
        cout<<path[i]<<" ";
    }

    return 0;
}