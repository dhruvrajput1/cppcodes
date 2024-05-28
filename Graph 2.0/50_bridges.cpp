#include<iostream>
#include<vector>
using namespace std;

int timer = 1;

void dfs(int node, int parent, vector<int> &vis, vector<int> adjList[], vector<int> &tin, vector<int> &low, vector<vector<int>> &bridges) {
    vis[node] = 1;

    tin[node] = low[node] = timer;
    timer++;

    for(auto it : adjList[node]) {
        if(it == parent) continue;

        if(vis[it] == 0) {
            dfs(it, node, vis, adjList, tin, low, bridges);
            low[node] = min(low[node], low[it]);
            // node ------------ it
            if(low[it] > tin[node]) {
                bridges.push_back({it, node});
            }
        }
        else {
            low[node] = min(low[node], low[it]);
        }
    }
}

int main() {

    int m, n;
    cin>>m>>n;

    vector<int> adjList[n+1];

    for(int i = 0; i < m; i++) {
        int u, v;
        cin>>u>>v;

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    vector<int> vis (n+1, 0);

    vector<int> tin(n); // time of insertion
    vector<int> low(n);

    vector<vector<int>> bridges;

    dfs(0, -1, vis, adjList, tin, low, bridges);

    for(int i = 0; i < bridges.size(); i++) {
        for(int j = 0; j < bridges[0].size(); j++) {
            cout<<bridges[i][j]<<" ";
        }
        cout<<endl;
    }


    return 0;
}