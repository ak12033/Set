#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
using namespace std;

void dfs(int node, unordered_map<int,bool> &visited,  unordered_map<int,list<int>> &adj,  vector<int> &component){
    component.push_back(node);
    visited[node]=true;
    // har connected node k liye recursive call
    for(auto i: adj[node]){
        if(!visited[i]){
          dfs(i,visited,adj,component);
        }
    }
}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    // Write your code here
    // prepare adjlist
    unordered_map<int,list<int>> adj;
    for(int i=0;i<edges.size();i++){
        int u = edges[i][0];
        int v= edges[i][1];
        
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    vector<vector<int>> ans;
    unordered_map<int,bool> visited;
    //call all node DFS if not visited
    for(int i=0; i<V;i++){
        if(!visited[i]){
            vector<int> component;
            dfs(i,visited,adj,component);
            ans.push_back(component);
        }
    }
    return ans;
}

int main() {
    int V, E;
    
    // Input number of vertices and edges
    cout << "Enter the number of vertices: ";
    cin >> V;
    cout << "Enter the number of edges: ";
    cin >> E;
    
    vector<vector<int>> edges(E);
    
    // Input edges
    cout << "Enter the edges (u v) for each edge:" << endl;
    for (int i = 0; i < E; ++i) {
        int u, v;
        cin >> u >> v;
        edges[i] = {u, v};
    }

    // Find connected components
    vector<vector<int>> components = depthFirstSearch(V, E, edges);

    // Print the connected components
    cout << "Connected Components:" << endl;
    for (const auto &component : components) {
        for (int node : component) {
            cout << node << " ";
        }
        cout << endl;
    }

    return 0;
}