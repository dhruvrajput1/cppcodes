#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main() {

    int m, n; // m is the number of edges, n is number of nodes
    cin>>m>>n;

    vector<int> adjList[n]; // [n+1] because 1 based indexing

    for(int i = 0; i < m; i++) {
        int u, v; cin>>u>>v;

        adjList[u].push_back(v); //creating directed graph adjacency list
    }

    vector<int> indegree(n, 0);

    for(int i = 0; i < n; i++) {
        for(auto it : adjList[i]) {
            indegree[it]++;
        }
    }

    queue<int> q;

    for(int i = 0; i < n; i++) {
        if(indegree[i] == 0) {
            q.push(i);
        }
    }

    vector<int> topo;

    while(!q.empty()) {
        int node = q.front();
        q.pop();

        topo.push_back(node);

        for(auto it : adjList[node]) {
            indegree[it]--;

            if(indegree[it] == 0) {
                q.push(it);
            }
        }

    }

    if(topo.size() == n) {
        cout<<"no cycle present"<<endl;
    }
    else {
        cout<<"cycle present"<<endl;
    }

    return 0;
}