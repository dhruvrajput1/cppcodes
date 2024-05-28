#include<iostream>
#include<vector>
#include<queue>
using namespace std;

bool isBipartite(vector<int> adjList[], int start, vector<int> &colour) {

    colour[start] = 0;

    queue<int> q;
    q.push(start);

    while(!q.empty()) {
        int node = q.front();
        q.pop();

        for(auto it : adjList[node]) {
            if(colour[it] == -1) {
                colour[it] = !colour[node]; // colour the neighbours opposite the colour of node
                q.push(it);
            }
            else if(colour[it] == colour[node]) {
                return false;
            }
        }
    }

    return true;
}

int main() {

    
    int m, n; // m is the number of edges, n is number of nodes
    cin>>m>>n;

    vector<int> adjList[n+1]; // [n+1] because 1 based indexing

    for(int i = 1; i <= m; i++) {
        int u, v; cin>>u>>v;

        adjList[u].push_back(v);
        adjList[v].push_back(u);

    }

    vector<int> colour(n+1, -1);
    
    int start = 1;

    for(int i = 1; i <= n; i++) { // if theere are components of graph
        if(colour[i] == -1) {
            if(isBipartite(adjList, start, colour) == false) {
                cout<<"Not Bipartite"<<endl; 
                return 0;
            }
        }
    }

    cout<<"Bipartite"<<endl;

    return 0;
}