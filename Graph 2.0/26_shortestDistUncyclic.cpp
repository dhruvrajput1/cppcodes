#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int main() {

    int m, n;
    cin>>m>>n;

    vector<int> adjList[n];

    for(int i = 0; i < m; i++) {
        int u, v;
        cin>>u>>v;
        
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    vector<int> dist(n, 1e9);

    queue<int> q;

    int src = 6;

    q.push(src);

    dist[src] = 0;

    while(!q.empty()) {
        int node = q.front();
        q.pop();

        for(auto it : adjList[node]) {
            if(dist[node] + 1 < dist[it]) {
                dist[it] = dist[node] + 1;
                q.push(it);
            }
        }
    }

    for(int i = 0; i < n; i++) {
        cout<<dist[i]<<" ";
    }
    cout<<endl;



    return 0;
}