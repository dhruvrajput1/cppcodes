#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main() {

    int n = 2;
    vector<pair<int, int>> prerequisites = {{1, 0}, {0, 1}};

    vector<int> adjList[n];

    for(auto it : prerequisites) {
        adjList[it.first].push_back(it.second);
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
        cout<<"all courses can be finished"<<endl;
    }
    else {
        cout<<"courses can't be finished"<<endl;
    }

    return 0;
}