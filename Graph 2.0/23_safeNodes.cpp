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

    vector<int> adjRev[n];

    vector<int> indegree(n, 0);

    for(int i = 0; i < n; i++) {
        for(auto it : adjList[i]) {
            adjRev[it].push_back(i);
            indegree[i]++;
        }
    }

    queue<int> q;
    vector<int> safeNodes;
    
    for(int i = 0; i < n; i++) {
        if(indegree[i] == 0) {
            q.push(i);
        }
    }

    while(!q.empty()) {

        int node = q.front();
        q.pop();

        safeNodes.push_back(node);

        for(auto it : adjRev[node]) {
            indegree[it]--;
            if(indegree[it] == 0) {
                q.push(it);
            }
        }

    }

    for(int i = 0; i < safeNodes.size(); i++) {
        cout<<safeNodes[i]<<" ";
    }
    cout<<endl;


    return 0;
}

// 13
// 12
// 0 1
// 1 2
// 2 3
// 3 4
// 3 5
// 4 6
// 5 6
// 6 7
// 8 1
// 8 9
// 9 10
// 10 8
// 11 9