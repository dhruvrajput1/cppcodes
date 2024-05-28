#include<iostream>
#include<vector>
#include<unordered_set>
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

    vector<vector<int>> grid {
        {1, 1, 0, 1, 1},
        {1, 1, 0, 1, 1},
        {1, 1, 0, 1, 1},
        {0, 0, 1, 0, 0},
        {0, 0, 1, 1, 1},
        {0, 0, 1, 1, 1}
    };

    int m = grid.size();
    int n = grid[0].size();

    DisjointSet ds(m*n);

    for(int row = 0; row < m; row++) {
        for(int col = 0; col < n; col++) {
            if(grid[row][col] == 0) continue;

            int delrow[] = {-1, 0, 1, 0};
            int delcol[] = {0, 1, 0, -1};

            for(int i = 0; i < 4; i++) {
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];

                if(nrow >= 0 and nrow < m and ncol >= 0 and ncol < n and grid[nrow][ncol] == 1) {
                    int node = row*n + col;
                    int neighbourNode = nrow*n + ncol;
                    ds.unionBySize(node, neighbourNode);
                }
            }
        }
    }

    int maxi = 0;

    unordered_set<int> st;

    for(int row = 0; row < m; row++) {
        for(int col = 0; col < n; col++) {
            if(grid[row][col] == 0) {
                int delrow[] = {-1, 0, 1, 0};
                int delcol[] = {0, 1, 0, -1};

                for(int i = 0; i < 4; i++) {
                    int nrow = row + delrow[i];
                    int ncol = col + delcol[i];

                    if(nrow >= 0 and nrow < m and ncol >= 0 and ncol < n and grid[nrow][ncol] == 1) {
                        int neighboutNode = nrow*n + ncol;
                        st.insert(ds.findUParent(neighboutNode));
                    }
                }
                int sizeTotal = 1; // 1 for the 0 which we are converting to 1
                for(auto it : st) {
                    sizeTotal += ds.size[it];
                }
                maxi = max(sizeTotal, maxi);
                st.clear();
            }
        }
    }

    for(int cellNo = 0; cellNo < m*n; cellNo++) { // agar 0 lagane se pehle hi koi island hai jiska size is greater than the size we will get after converting that 0 to 1
        maxi = max(maxi, ds.size[ds.findUParent(cellNo)]);
    }

    cout<<maxi<<endl;

    return 0;
}