#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class DisjointSet {
private:
    vector<int> rank;
    vector<int> parent;
    vector<int> size;

public:

    DisjointSet(int n) {
        rank.resize(n+1, 0);
        parent.resize(n+1);
        size.resize(n+1, 1);
        
        for(int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int findUParent(int node) {
        // base case
        if(node == parent[node]) {
            return node;
        }

        // recursive case
        return parent[node] = findUParent(parent[node]); // path compression
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUParent(u);
        int ulp_v = findUParent(v);

        if(ulp_u == ulp_v) {
            return ;
        }

        if(rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if(rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUParent(u);
        int ulp_v = findUParent(v);

        if(ulp_u == ulp_v) {
            return ;
        }

        if(size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        } 
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
    
};

int main() {

    int m, n;
    cin>>m>>n;

    vector<pair<int, int>> adjList[n+1];

    for(int i = 0; i < m; i++) {
        int u, v, wt;
        cin>>u>>v>>wt;
        adjList[u].push_back({v, wt});
        adjList[v].push_back({u, wt});
    }

    vector<pair<int, pair<int, int>>> edges;

    for(int i = 0; i < n; i++) {
        for(auto it : adjList[i]) {
            int adjNode = it.first;
            int wt = it.second;
            int node = i;

            edges.push_back({wt, {node, adjNode}});
        }
    }

    sort(edges.begin(), edges.end());

    int sumWt = 0;

    DisjointSet ds(n);

    for(auto it : edges) {
        int wt = it.first;
        int u = it.second.first;
        int v = it.second.second;

        if(ds.findUParent(u) != ds.findUParent(v)) {
            sumWt += wt;
            ds.unionBySize(u, v);
        }
    }

    cout<<sumWt<<endl;



    return 0;
}