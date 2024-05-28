#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<int> topoSort(int n, vector<int> adjList[]) {
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

    return topo;
}

int main() {

    vector<string> dict {"baa", "abcd", "abca", "cab", "cad"};

    int k = 4;
    int n = dict.size();

    vector<int> adjList[k];

    for(int i = 0; i < n-1; i++) {
        string s1 = dict[i];
        string s2 = dict[i+1];

        int len = min(s1.size(), s2.size());

        for(int ptr = 0; ptr < len; ptr++) {
            if(s1[ptr] != s2[ptr]) {
                adjList[s1[ptr] - 'a'].push_back(s2[ptr] - 'a');
                break;
            }
        }
    }

    vector<int> topo = topoSort(k, adjList);

    string ans = "";

    for(auto it : topo) {
        ans += char(it + 'a');
    }

    cout<<ans<<endl;


    return 0;
}