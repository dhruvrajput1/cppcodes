#include<iostream>
#include<vector>
#include<queue>
using namespace std;

bool isCycle(vector<int> adj[], vector<int> &vis, int src) {

    vis[src] = 1;

    queue<pair<int, int>> q; // node, parent

    q.push({src, -1}); // parent for src is -1

    while(!q.empty()) {
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();

        for(auto it : adj[node]) {
            if(vis[it] == 0) {
                vis[it] = 1;
                q.push({it, node});
            }
            else if(parent != it) {
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
            if(isCycle(adj, vis, src) == true) {
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