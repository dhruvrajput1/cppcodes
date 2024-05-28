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

    int m = 4;
    int n = 5;

    vector<vector<int>> operators = {{0, 0}, {0, 0}, {1, 1}, {1, 0}, {0, 1}, {0, 3}, {1, 3}, {0, 4}, {3, 2}, {2, 2}, {1, 2}, {0, 2}};

    DisjointSet ds(m*n);

    vector<vector<int>> vis (m, vector<int> (n, 0));
    
    int cnt = 0;

    vector<int> ans;

    for(auto it : operators) {
        int row = it[0];
        int col = it[1];

        if(vis[row][col] == 1) {
            ans.push_back(cnt);
            continue;
        }

        vis[row][col] = 1;
        cnt++;

        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};

        for(int i = 0; i < 4; i++) {
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];

            if(nrow >= 0 and nrow < m and ncol >= 0 and ncol < n) {
                if(vis[nrow][ncol] == 1) {
                    int node = row*n + col;
                    int neighbourNode = nrow*n + ncol;
                    if(ds.findUParent(node) != ds.findUParent(neighbourNode)) {
                        cnt--;
                        ds.unionByRank(node, neighbourNode);
                    }
                }
            }
        }
        ans.push_back(cnt);
    }

    for(auto i : ans) {
        cout<<i<<" ";
    }


    return 0;
}