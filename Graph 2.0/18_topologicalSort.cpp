#include<iostream>
#include<vector>
#include<stack>
using namespace std;

void dfs(int node, vector<int> &vis, stack<int> &s, vector<int> adjList[]) {
    vis[node] = 1;

    for(auto it : adjList[node]) {
        if(!vis[it]) {
            dfs(it, vis, s, adjList);
        }
    }

    s.push(node);
}

int main() {

    int m, n; // m is the number of edges, n is number of nodes
    cin>>m>>n;

    vector<int> adjList[n]; // [n+1] because 1 based indexing

    for(int i = 0; i < m; i++) {
        int u, v; cin>>u>>v;

        adjList[u].push_back(v); //creating directed graph adjacency list
    }

    vector<int> vis(n, 0);

    stack<int> s;

    for(int i = 0; i < n; i++) {
        if(!vis[i]) {
            dfs(i, vis, s, adjList);
        }
    }

    while(!s.empty()) {
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;


    return 0;
}