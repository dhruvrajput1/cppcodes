#include<iostream>
#include<vector>
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

    vector<vector<int>> edges {
        {0, 1},
        {0, 3},
        {0, 2},
        {1, 2},
        {2, 3},
        {4, 5},
        {5, 6},
        {7, 8}
    };

    int n = 9;
    int m = edges.size();

    int extraEdges = 0;

    DisjointSet ds(n);

    for(auto it : edges) {
        int u = it[0];
        int v = it[1];

        if(ds.findUParent(u) == ds.findUParent(v)) {
            extraEdges++;
        }
        else {
            ds.unionBySize(u, v);
        }

    }

    int comp = 0;
    // count the number of components
    for(int i = 0; i < n; i++) {
        if(ds.findUParent(i) == i) {
            comp++;
        }
    }

    int ans = comp-1;

    if(extraEdges >= ans) {
        cout<<ans<<endl;
    }
    else {
        cout<<-1<<endl;
    }

    return 0;
}