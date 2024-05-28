#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main() {

    int m, n;
    cin>>m>>n;

    vector<pair<int, int>> adjList[n];

    for(int i = 0; i < m; i++) {
        int u, v, wt;
        cin>>u>>v>>wt;
        adjList[u].push_back({v, wt});
        adjList[v].push_back({u, wt});
    }

    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq; // min heap

    pq.push({0, {0, -1}}); // wt, node

    vector<int> vis (n, 0);

    vector<pair<int, int>> MST;

    int sum = 0;

    while(!pq.empty()) {
        auto it = pq.top();
        int wt = it.first;
        int node = it.second.first;
        int parent = it.second.second;
        pq.pop();

        if(vis[node] == 1) continue;
        vis[node] = 1;
        sum += wt;

        if(parent != -1) {
            MST.push_back({parent, node});
        }
        
        for(auto i : adjList[node]) {
            int adjNode = i.first;
            int ewt = i.second;

            if(!vis[adjNode]) {
                pq.push({ewt, {adjNode, node}});
            }
        }
    }

    cout<<sum<<endl;

    for(auto it : MST) {
        cout<<it.first<<" "<<it.second<<endl;
    }


    return 0;
}

// 6
// 5
// 0 3 6
// 0 1 2
// 1 3 8
// 1 4 5
// 1 2 3
// 2 4 7