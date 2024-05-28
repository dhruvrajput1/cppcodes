#include<iostream>
#include<vector>
#include<stack>
using namespace std;

void dfs(int node, vector<int> &vis, vector<int> adjList[], stack<int> &s) {
    vis[node] = 1;

    for(auto it : adjList[node]) {
        if(!vis[it]) {
            dfs(it, vis, adjList, s);
        }
    }
    s.push(node);
}

void dfs3(int node, vector<int> adjT[], vector<int> &vis) {
    vis[node] = 1;

    for(auto it : adjT[node]) {
        if(!vis[it]) {
            dfs3(it, adjT, vis);
        }
    }
}

int main() {

    int m, n;
    cin>>m>>n;

    vector<int> adjList[n];

    for(int i = 0; i < m; i++) {
        int u, v;
        cin>>u>>v;

        adjList[u].push_back(v);
    }

    vector<int> vis (n, 0);

    stack<int> s;
    // step 1
    for(int i = 0; i < n; i++) {
        if(!vis[i]) {
            dfs(i, vis, adjList, s);
        }
    }

    // step 2 - reverse the edges
    vector<int> adjT[n];

    for(int i = 0; i < n; i++) {
        for(auto it : adjList[i]) {
            adjT[it].push_back(i);
        }
    }

    for(int i = 0; i < n; i++) { // mark all vis[i] = 0 for again dfs traversal
        vis[i] = 0;
    }

    // step 3 - do a dfs traversal
    int scc = 0;
    while(!s.empty()) {
        int node = s.top();
        s.pop();

        if(!vis[node]) {
            scc++;
            dfs3(node, adjT, vis);
        }
        

    }

    cout<<scc<<endl;


    return 0;
}

// 10
// 8
// 0 1
// 1 2
// 2 0
// 2 3
// 3 4
// 4 7
// 4 5
// 5 6
// 6 4
// 6 7