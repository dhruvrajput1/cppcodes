#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void dfs(int node, vector<int> adj[], vector<int> &vis, vector<int> &list) {
    vis[node] = 1;
    list.push_back(node);

    for(auto it: adj[node]) {
        if(vis[it] == 0) { // if not visited
            dfs(it, adj, vis, list);
        }
    }
}

int main() {

    int m, n; // m is the number of edges, n is number of nodes
    cin>>m>>n;

    vector<int> adjList[n]; // not [n+1] because 0 based indexing

    for(int i = 0; i < m; i++) {
        int u, v; cin>>u>>v;

        adjList[u].push_back(v);
        adjList[v].push_back(u);

    }

    int start = 0; // starting from 0 node

    vector<int> vis(n, 0);
    vector<int> list;

    dfs(start, adjList, vis, list);

    for(auto i : list) {
        cout<<i<<" ";
    }
    cout<<endl;

   
    return 0;
}

// 8
// 8
// 0 1
// 1 4
// 1 5
// 0 2
// 2 3
// 3 7
// 7 6
// 2 6