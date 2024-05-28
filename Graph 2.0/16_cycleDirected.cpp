#include<iostream>
#include<vector>
using namespace std;

bool dfsCheck(int node, vector<int> adjList[], vector<int> &vis, vector<int> &pathVis) {
    vis[node] = 1;
    pathVis[node] = 1;

    for(auto it : adjList[node]) {
        // when the node is not visited
        if(vis[it] == 0) {
            if(dfsCheck(it, adjList, vis, pathVis) == true) return true;
        }
        // when the node has been previously visited
        // and is on the same path
        else if(pathVis[it] == 1) {
            return true;
        }
    }

    pathVis[node] = 0;
    return false;
}

int main() {

    int m, n; // m is the number of edges, n is number of nodes
    cin>>m>>n;

    vector<int> adjList[n+1]; // [n+1] because 1 based indexing

    for(int i = 1; i <= m; i++) {
        int u, v; cin>>u>>v;

        adjList[u].push_back(v); //creating directed graph adjacency list
    }

    vector<int> vis (n+1, 0);
    vector<int> pathVis(n+1, 0);

    for(int i = 1; i <= n; i++) {
        if(!vis[i]) {
            if(dfsCheck(i, adjList, vis, pathVis) == true) {
                cout<<"Cyclic"<<endl;
                return 0;
            } 
        }
        
    }

    cout<<"Not cyclic"<<endl;

    return 0;
}

// 11
// 10
// 1 2
// 2 3
// 3 4
// 3 7
// 4 5
// 5 6
// 7 5
// 8 2
// 8 9
// 9 10
// 10 8