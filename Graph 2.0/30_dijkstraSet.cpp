#include<iostream>
#include<vector>
#include<set>
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

    int src = 0;

    vector<int> dist(n, 1e9);

    dist[src] = 0;

    set<pair<int, int>> s;

    s.insert({0, src});

    while(!s.empty()) {
        auto it = *(s.begin());
        int dis = it.first;
        int node = it.second;
        s.erase(it);

        for(auto i : adjList[node]) {
            int adjNode = i.first;
            int wt = i.second;

            if(dis + wt < dist[adjNode]) {

                // erase if it already existed with larger distance
                if(dist[adjNode] != 1e9) {
                    s.erase({dist[adjNode], adjNode});
                }

                dist[adjNode] = dis + wt;
                s.insert({dist[adjNode], adjNode});
            }

        }

    }

    for(auto i : dist) {
        cout<<i<<" ";
    }


    return 0;
}