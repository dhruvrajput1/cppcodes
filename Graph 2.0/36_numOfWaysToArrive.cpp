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
    int dest = n-1;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // dist, node

    vector<int> dist(n, 1e9);
    vector<int> ways(n, 0);

    dist[src] = 0;
    ways[src] = 1;

    pq.push({0, src});

    int mod = 1e9+7;

    while(!pq.empty()) {
        int dis = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        for(auto it : adjList[node]) {
            int adjNode = it.first;
            int wt = it.second;
            // this is the first time i am coming with this short distance
            if(dis + wt < dist[adjNode]) {
                dist[adjNode] = dis + wt;
                pq.push({dis+wt, adjNode});
                ways[adjNode] = ways[node];
            }
            else if(dis + wt == dist[adjNode]) {
                ways[adjNode] = (ways[node] + ways[adjNode])%mod;
            }
        }
    }

    cout<<ways[n-1]%mod<<endl;

    return 0;
}