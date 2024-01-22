#include<iostream>
#include<vector>
#include<list>
#include<unordered_map>
using namespace std;

void dfs(int node, unordered_map<int, list<int>> &adj, unordered_map<int, bool> &visited, vector<int>& component) {
    component.push_back(node);

    visited[node] = true;

    for(auto i : adj[node]) { // checking for members
        if(!visited[i]) {
            dfs(i, adj, visited, component);
        }
    }

}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges) // V is the number of nodes, E is no of edges
{
    // prepairing the adjacent list

    unordered_map<int, list<int>> adj;

    for(int i = 0; i < edges.size(); i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<vector<int>> ans;

    unordered_map<int, bool> visited;

    for(int i = 0; i < V; i++) {
        vector<int> component;
        if(!visited[i]) {
            dfs(i, adj, visited, component);
            ans.push_back(component);
        }
    }

    return ans;

}

// https://www.codingninjas.com/codestudio/problems/dfs-traversal_630462?leftPanelTab=1
