#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main() {

    int n = 4;

    vector<vector<int>> flights {
        {0, 1, 100},
        {1, 2, 100},
        {2, 0, 100},
        {1, 3, 600},
        {2, 3, 200}
    };

    int src = 0;
    int dest = 3;
    int k = 1;

    int m = flights.size();

    vector<pair<int, int>> adjList[n];

    for(int i = 0; i < m; i++) {
    
        adjList[flights[i][0]].push_back({flights[i][1], flights[i][2]});

    }

    vector<int> dist(n, 1e9);

    dist[src] = 0;

    queue<pair<int, pair<int, int>>> q; // {stops, node, cost}

    q.push({0, {src, 0}}); 

    while(!q.empty()) {
        auto it = q.front();
        q.pop();

        int stops = it.first;
        int node = it.second.first;
        int cost = it.second.second; // cost is the shortest cost taken to reach node till now

        if(stops > k) continue;

        for(auto i : adjList[node]) {
            int adjNode = i.first;
            int wt = i.second;

            if(cost + wt < dist[adjNode] and stops <= k) {
                dist[adjNode] = cost + wt;
                q.push({stops+1, {adjNode, cost+wt}});
            }
        }

    }

    if(dist[dest] == 1e9) {
        cout<<-1<<endl;
        return 0;
    }

    cout<<dist[dest]<<endl;



    return 0;
}