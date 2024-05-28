#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main() {

    int n = 4;
    vector<vector<int>> prerequisites = {{1, 0}, {2, 1}, {3, 2}};

    vector<int> adjList[n];

    for(auto it : prerequisites) {
        adjList[it[1]].push_back(it[0]);
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
        for(auto i : topo) {
            cout<<i<<" ";
        }
    }
    else {
        cout<<"courses can't be finished"<<endl;
    }

    return 0;
}