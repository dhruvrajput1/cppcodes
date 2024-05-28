#include<iostream>
#include<vector>
using namespace std;

int numOfProvinces(vector<int> adjList[], int node, vector<int> &vis) {
    vis[node] = 1;

    for(auto it : adjList[node]) {
        if(vis[it] == 0) {
            vis[it] = 1;
            numOfProvinces(adjList, it, vis);
        }
    }

}

int main() {

    int m, n;
    cin>>m>>n;

    vector<int> adjList[n+1];

    for(int i = 0; i < m; i++) {
        int u, v;
        cin>>u>>v;

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    int start = 1;

    vector<int> vis(n+1, 0);

    int cnt = 0;

    for(int i = 1; i <= n; i++) {
        if(vis[i] == 0) {
            cnt++;
            numOfProvinces(adjList, i, vis);  
        }
    }

    cout<<cnt<<endl;

    return 0;
}