#include<iostream>
#include<vector>
using namespace std;

bool dfsCheck(int node, vector<int> adjList[], vector<int> &vis, vector<int> &pathVis, vector<int> &check) {
    vis[node] = 1;
    pathVis[node] = 1;

    check[node] = 0;

    for(auto it : adjList[node]) {
        // when the node is not visited
        if(vis[it] == 0) {
            if(dfsCheck(it, adjList, vis, pathVis, check) == true) {
                check[node] = 0; // part of the cycle therefore can not be a safe node
                return true;
            }
        }
        // when the node has been previously visited
        // and is on the same path
        else if(pathVis[it] == 1) {
            check[node] = 0; // part of the cycle therefore can not be a safe node
            return true;
        }
    }

    check[node] = 1; // safe node, because no cycle detected, if cycle was deteced function would have returned true in the above loop only
    pathVis[node] = 0;
    return false;
}

int main() {

    int m, n; // m is the number of edges, n is number of nodes
    cin>>m>>n;

    vector<int> adjList[n]; // [n+1] because 1 based indexing

    for(int i = 0; i < m; i++) {
        int u, v; 
        cin>>u>>v;

        adjList[u].push_back(v); //creating directed graph adjacency list
    }

    vector<int> vis (n, 0);
    vector<int> pathVis(n, 0);

    vector<int> safeNodes;

    vector<int> check (n, 0);

    for(int i = 0; i < n; i++) {
        if(!vis[i]) {
            dfsCheck(i, adjList, vis, pathVis, check);
        }
        
    }

    for(int i = 0; i < n; i++) {
        if(check[i] == 1) {
            safeNodes.push_back(i);
        }
    }

    for(int i = 0; i < safeNodes.size(); i++) {
        cout<<safeNodes[i]<<" ";
    }
    cout<<endl;

    return 0;
}

// 13
// 12
// 0 1
// 1 2
// 2 3
// 3 4
// 3 5
// 4 6
// 5 6
// 6 7
// 8 1
// 8 9
// 9 10
// 10 8
// 11 9

