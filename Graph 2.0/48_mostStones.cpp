#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class DisjointSet {
private:
    

public:

    vector<int> rank;
    vector<int> parent;
    vector<int> size;

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

    vector<vector<int>> stones = {{0,0},{0,1},{1,0},{1,2},{2,1},{2,2}};

    int n = 6;

    int maxRow = 0;
    int maxCol = 0;

    for(auto it : stones) {
        maxRow = max(maxRow, it[0]);
        maxCol = max(maxCol, it[1]);
    }

    DisjointSet ds(maxRow + maxCol + 1);

    unordered_map<int, int> stonesNodes; // in this map we will store the nodes which we have

    for(auto it : stones) {
        int nodeRow = it[0];
        int nodeCol = it[1] + maxRow + 1;

        ds.unionByRank(nodeRow, nodeCol);

        stonesNodes[nodeRow] = 1;
        stonesNodes[nodeCol] = 1;

    }

    int cnt = 0;
    for(auto it : stonesNodes) {
        if(ds.findUParent(it.first) == it.first) {
            cnt++;
        }
    }

    cout<<n-cnt<<endl;


    return 0;
}