#include<iostream>
#include<vector>
#include<unordered_map>
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

    vector<vector<string>> accounts = {
        {"John", "johnsmith@mail.com", "john_newyork@mail.com"},
        {"John", "johnsmith@mail.com", "john00@mail.com"},
        {"Mary", "mary@mail.com"},
        {"John", "johnnybravo@mail.com"}
    };

    int n = accounts.size();
    unordered_map<string, int> mapMailNode;

    DisjointSet ds(n);

    for(int i = 0; i < n; i++) {
        for(int j = 1; j < accounts[i].size(); j++) {
            string mail = accounts[i][j];
            if(mapMailNode.find(mail) == mapMailNode.end()) { // mail not present in map
                mapMailNode[mail] = i;
            }
            else { // if mail is already present
                ds.unionBySize(i, mapMailNode[mail]);
            }
        }
    }

    // now iterate over map and add mails to their parents
    vector<string> mergedMails[n]; // list of vector

    for(auto it : mapMailNode) {
        string mail = it.first;
        int node = ds.findUParent(it.second);

        mergedMails[node].push_back(mail);
    }


    // storing the ans
    vector<vector<string>> ans;

    for(int i = 0; i < n; i++) { // we have to put the names at ans[i][0]
        if(mergedMails[i].size() == 0) continue;

        sort(mergedMails[i].begin(), mergedMails[i].end());

        vector<string> temp;
        temp.push_back(accounts[i][0]);

        for(auto it : mergedMails[i]) {
            temp.push_back(it);
        }

        ans.push_back(temp);

    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < ans[i].size(); j++) {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }


    return 0;
}