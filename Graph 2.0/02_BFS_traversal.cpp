#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main() {

    int m, n; // m is the number of edges, n is number of nodes
    cin>>m>>n;

    vector<int> adjList[n]; // not [n+1] because 0 based indexing

    for(int i = 0; i < m; i++) {
        int u, v; cin>>u>>v;

        adjList[u].push_back(v);
        adjList[v].push_back(u);

    }

    // bfs traversal
    vector<int> vis (n, 0);
    vis[0] = 1; // for zero based indexing

    queue<int> q;
    q.push(0);

    vector<int> bfs; // it will store the bfs traversal

    while(!q.empty()) {
        int node = q.front();
        q.pop();

        bfs.push_back(node);

        for(auto it : adjList[node]) { // checking the neighbours of node
            if(vis[it] == 0) {
                vis[it] = 1;
                q.push(it);
            }
        }
    }

    for(int i = 0; i < n; i++) {
        cout<<i<<" -> ";
        for(auto i : adjList[i]) {
            cout<<i<<" ";
        }
        cout<<endl;
    }
    cout<<endl;

    // bfs is ready

    for(int i = 0; i < bfs.size(); i++) {
        cout<<bfs[i]<<" ";
    }
    cout<<endl;


    return 0;
}

// 9
// 9
// 1 2
// 2 3
// 2 4
// 6 7
// 6 9
// 4 5
// 7 8
// 1 6
// 5 8