#include<iostream>
#include<vector>
#include<stack>
using namespace std;

void toposort(int node, vector<pair<int, int>> adjList[], vector<int> &vis, stack<int> &s) {
    vis[node] = 1;

    for(auto it : adjList[node]) {
        int v = it.first; // v is the neighbouring node
        if(!vis[v]) {
            toposort(v, adjList, vis, s);
        }
    }

    s.push(node);

}

int main() {

    int m, n;
    cin>>m>>n;

    vector<pair<int, int>> adjList[n];

    for(int i = 0; i < m; i++) {
        int u, v, wt;
        cin>>u>>v>>wt;
        
        adjList[u].push_back({v, wt});
    }

    int src = 0;

    vector<int> vis (n, 0);

    vector<int> topo(n);

    stack<int> s;

    for(int i = 0; i < n; i++) {
        if(!vis[i]) {
            toposort(i, adjList, vis, s);
        }
    }

    vector<int> dist (n, 1e9);

    dist[src] = 0;

    while(!s.empty()) {
        int node = s.top();
        s.pop();

        for(auto it : adjList[node]) {
            int v = it.first;
            int wt = it.second;
            if(dist[v] > dist[node] + wt) {
                dist[v] = dist[node] + wt;
            }
        }
    }

    for(auto i : dist) {
        cout<<i<<" ";
    }
    cout<<endl;



    return 0;
}