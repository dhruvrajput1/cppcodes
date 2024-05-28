#include<iostream>
#include<vector>
using namespace std;

int main() {

    int m, n; // m is the number of edges, n is number of nodes
    cin>>m>>n;

    // adjacency matrix
    int adj[n+1][n+1]; // (n+1) for 1 based indexing

    for(int i = 0; i < m; i++) {
        int u, v;
        cin>>u>>v;

        adj[u][v] = 1;
        adj[v][u] = 1;

    }

    // adjacency list
    vector<int> adjList[n+1]; // (n+1) for 1 based indexing

    for(int i = 0; i < m; i++) {
        int u, v; cin>>u>>v;

        adjList[u].push_back(v);
        adjList[v].push_back(u);

    }

    // printing the adjacency list

    for(int i = 0; i <= n; i++) {
        cout<<i<<" -> ";
        for(auto it : adjList[i]) {
            cout<<it<<" ";
        }
        cout<<endl;
    }



    return 0;
}