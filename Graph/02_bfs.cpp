#include<iostream>
#include<list>
#include<unordered_map>
#include<vector>
#include<set>
#include<queue>
using namespace std;

class Graph {
public:

    unordered_map<int, list<int>> adj;

    void addEdge(int u, int v, bool direction) {
        // direction = 0 -> undirected graph
        // direction = 1 -> directed graph

        adj[u].push_back(v);

        if(direction == 0) {
            adj[v].push_back(u);
        }
    }


void bfs(unordered_map<int,set<int>> &adjList, unordered_map<int,bool> &visited, vector<int>&ans,int node){
    queue<int>q;
    q.push(node);
    visited[node]=1;
    
    while(!q.empty()){
        int frontnode=q.front();
        q.pop();
        //storefrontnode to ans
        ans.push_back(frontnode);
        //traverse all neighbours of frontnode
        for(auto i:adjList[frontnode]){
            if(!visited[i]){
                q.push(i);
                visited[i]=1;
            }
        }
    }
}

vector<int> BFS(int vertex)
{
    unordered_map<int,set<int>> adjList;
    vector<int> ans;
    unordered_map<int,bool> visited;
    
    // traverse all components
    for(int i =0;i<vertex;i++){
        if(!visited[i]){
            bfs(adjList,visited,ans,i); 
        }
    }
   return ans; 
}

};



int main() {

    Graph g;

    g.addEdge(0, 1, 0);
    g.addEdge(0, 2, 0);
    g.addEdge(1, 2, 0);
    g.addEdge(2, 0, 0);
    g.addEdge(2, 3, 0);
    g.addEdge(3, 3, 0);

    vector<int> ans = g.BFS(6);

    for(int i = 0; i < ans.size(); i++) {
        cout<<ans[i]<<" ";
    }
    cout<<endl;


    return 0;
}