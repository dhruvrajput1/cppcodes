#include<iostream>
#include<vector>
using namespace std;

bool isCycle(vector<int> adj[], vector<int> &vis, int node, int parent) {

    vis[node] = 1;

    for(auto neighbour : adj[node]) {
        if(!vis[neighbour]) {
            if(isCycle(adj, vis, neighbour, node) == true) {
                return true;
            }
        }
        else {
            if(neighbour != parent) {
                return true;
            }
        }
    }

    return false;
}


int main() {

    int m, n;
    cin>>m>>n;

    vector<int> adj[n+1];

    for(int i = 0; i < m; i++) {
        int u, v;
        cin>>u>>v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> vis(n+1, 0);

    int src = 1;

    for(int i = 1; i <= n; i++) { // loop for checking for components
        if(vis[i] == 0) {
            if(isCycle(adj, vis, i, -1) == true) {
                cout<<"Cycle Present"<<endl;
                return 0;
            } 
        }
    }

    cout<<"cycle not present"<<endl;

    return 0;
}

// 7
// 7
// 1 2
// 1 3
// 3 4
// 2 5
// 5 7
// 7 6
// 3 6