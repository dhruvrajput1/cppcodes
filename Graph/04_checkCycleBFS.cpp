#include<unordered_map>
#include<queue>
#include<list>
#include<set>
using namespace std;

bool isCyclicBFS(int src, unordered_map<int, bool>& visited, 
unordered_map<int, list<int>> &adj) {

    unordered_map<int, int> parent;

    queue<int> q;

    parent[src] = -1;
    visited[src] = 1;

    q.push(src);

    while(!q.empty()) {
        int front = q.front();
        q.pop();

        for(auto neighbour : adj[front]) {
            if(visited[neighbour] == true and neighbour != parent[front]) {
                return true;
            }
            else if(!visited[neighbour]) {
                q.push(neighbour);
                visited[neighbour] = true;
                parent[neighbour] = front;
            }
        }
    }

    return false;
}

string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    // create adjList

    unordered_map<int, list<int>> adj;

    for(int i = 0; i < m; i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }


    // to handle disconnected components

    unordered_map<int, bool> visited;

    for(int i = 0; i < n; i++) {

        if(!visited[i]) {
            bool ans = isCyclicBFS(i, visited, adj);

            if(ans == 1) {
                return "Yes";
            }
        }

    }

    return "No";

}

// https://www.codingninjas.com/codestudio/problems/cycle-detection-in-undirected-graph_1062670?leftPanelTab=1