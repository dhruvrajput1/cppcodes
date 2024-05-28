#include<iostream>
#include<vector>
#include<queue>
using namespace std;

bool isBipartite(vector<int> adjList[], int node, vector<int> &colour, int col) {

    colour[node] = col;

    for(auto it : adjList[node]) {
        if(colour[it] == -1) {
            if(isBipartite(adjList, it, colour, !col) == false) return false;
        }
        else if(colour[it] == col) {
            return false;
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
            if(isBipartite(adjList, start, colour, 0) == false) {
                cout<<"Not Bipartite"<<endl; 
                return 0;
            }
        }
    }

    cout<<"Bipartite"<<endl;

    return 0;
}